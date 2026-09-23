# Git Commit Plan

7 commits total: 1 skeleton commit + 1 commit per group member. This gives a
clear, logical development progression in the Git log (for rubric criteria
5 & 6: Commit Quality and Log Presentation).

> Tip: each member should `git pull` before starting, edit only their own
> TODO section in the shared file, then commit + push right after finishing
> their part — don't batch everything into one commit at the end.

## Commit 1 — Skeleton (whoever sets up the repo, e.g. Wan)
```
git add skeleton_main.cpp README.md
git commit -m "chore: add project skeleton with TODO markers for all 6 sections"
```
Renamed to `main.cpp` once work begins, or kept as the reference skeleton —
team's choice. Recommended: copy `skeleton_main.cpp` to `main.cpp` at this
step and commit that instead, so everyone edits the real file from the start.
```
git add main.cpp
git commit -m "chore: initialize main.cpp from skeleton"
```

## Commit 2 — Member 1: Wan
```
git add main.cpp
git commit -m "feat: add welcome banner and user input prompts (mood, genre)"
```

## Commit 3 — Member 2: Aishah
```
git add main.cpp
git commit -m "feat: add mood validation with re-prompt on invalid input"
```

## Commit 4 — Member 3: Visshaa
```
git add main.cpp
git commit -m "feat: add playlist name and description recommendation logic"
```

## Commit 5 — Member 4: Dania
```
git add main.cpp
git commit -m "feat: add subscription tier logic (Free/Premium/Family) with cost calculation"
```

## Commit 6 — Member 5: Sabrina
```
git add main.cpp
git commit -m "feat: format final output with dividers and spacing"
```

## Commit 7 — Member 6: Fakhira
```
git add main.cpp test_cases.md
git commit -m "fix: handle negative numbers, empty strings, and non-numeric input"
git commit -m "docs: add test cases and finalize comments"
```
(This can be split into two commits — one `fix:` for the edge-case code,
one `docs:` for cleanup/comments/test documentation — to show more granular
progression in the log.)

## Optional extra commits (if time allows, to strengthen rubric criteria 5 & 6)
```
git commit -m "docs: add README with compile instructions and sample output"
git commit -m "test: verify program with multiple mood/genre/budget combinations"
```

## Suggested branch strategy
- `main` branch protected; each member works on a short-lived branch named
  after their part, e.g. `feature/mood-validation`, then opens a Pull
  Request merged into `main`. This produces a clean, readable commit graph
  for the "Git Log Presentation" criterion.
