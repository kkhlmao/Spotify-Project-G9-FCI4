# Test Cases

All tests below were run against the compiled `main.cpp` to confirm expected
behaviour.

## Test Case 1 — Happy path, Family plan
**Input:**
```
Mood: Focus
Genre: Lo-fi
Weekly hours: 20
Monthly budget: 30
```
**Expected output (key lines):**
```
Mood                : Focus
Genre                : Lo-fi
Recommended Playlist : Focus Lo-fi Mix
  Steady, low-distraction tracks to help you concentrate.
Recommended Plan     : Family
Monthly Cost         : RM 29.90
```

## Test Case 2 — Light listener, Free plan
**Input:**
```
Mood: Happy
Genre: Pop
Weekly hours: 2
Monthly budget: 50
```
**Expected output (key lines):**
```
Mood                : Happy
Genre                : Pop
Recommended Playlist : Happy Pop Mix
  Upbeat, feel-good tracks to keep your energy high.
Recommended Plan     : Free
Monthly Cost         : RM 0.00
```
(Free plan is chosen for light listeners regardless of budget, since higher
tiers aren't needed yet.)

## Test Case 3 — Moderate listener, limited budget falls back to Free
**Input:**
```
Mood: Sad
Genre: R&B
Weekly hours: 10
Monthly budget: 5
```
**Expected output (key lines):**
```
Mood                : Sad
Genre                : R&B
Recommended Playlist : Sad R&B Mix
  Soft, emotional songs to help you feel and heal.
Recommended Plan     : Free
Monthly Cost         : RM 0.00
```
(Budget of RM 5 is below the RM 14.90 Premium price, so the program falls
back to Free instead of recommending a plan the user can't afford.)

## Test Case 4 — Heavy listener, mid budget falls back to Premium
**Input:**
```
Mood: Chill
Genre: EDM
Weekly hours: 18
Monthly budget: 20
```
**Expected output (key lines):**
```
Recommended Plan     : Premium
Monthly Cost         : RM 14.90
```
(RM 20 is enough for Premium at RM 14.90 but not Family at RM 29.90, so the
program correctly steps down one tier instead of Free.)

---

## Edge Cases Handled

| # | Scenario                                      | Behaviour                                                                 |
|---|------------------------------------------------|-----------------------------------------------------------------------------|
| 1 | Invalid mood (e.g. "Angry", "excited")          | Error message shown; user is re-prompted until a valid mood is entered     |
| 2 | Mood typed in different case (e.g. "HAPPY")     | Accepted — comparison is case-insensitive via `toLowerCase()`               |
| 3 | Empty genre input (just pressing Enter)         | Defaults to `"Various"` instead of crashing or leaving it blank            |
| 4 | Unrecognised genre (e.g. "Reggae", "K-pop")      | Still accepted and used to build the playlist name — no hard-coded list restriction, just capitalized for display |
| 5 | Negative weekly hours or budget (e.g. "-5")      | Rejected with an error message; user is re-prompted                        |
| 6 | Non-numeric input for hours/budget (e.g. "abc")  | `cin.fail()` detected, input stream cleared, user is re-prompted           |
| 7 | Input stream runs out unexpectedly (EOF)         | Program exits cleanly with a message instead of looping forever            |
| 8 | Budget of exactly RM 0                           | Handled correctly — always resolves to the Free plan                       |
| 9 | Very high hours (e.g. 40) with very high budget  | Correctly recommends Family plan at RM 29.90                               |

These were each manually tested by compiling and running the program with
the listed inputs and confirming the output matched expectations.
