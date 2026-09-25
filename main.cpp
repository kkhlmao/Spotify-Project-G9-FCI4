/*
 * ================================================================
 *  SPOTIFY PLAYLIST GENERATOR & SUBSCRIPTION ADVISOR (SKELETON)
 * ----------------------------------------------------------------
 *  This is the starting skeleton for the group. It compiles as-is
 *  (with empty/placeholder behaviour) so everyone can pull it,
 *  find their TODO section, and commit their own part without
 *  breaking the build for anyone else.
 *
 *  DO NOT rename the functions or change their parameters -
 *  main() already calls them exactly as declared below.
 * ================================================================
 */

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <cstdlib>

using namespace std;

// ================================================================
// FUNCTION PROTOTYPES - do not remove or rename
// ================================================================
void displayWelcomeBanner();                                   // Member 1: Wan
void getUserInputs(string &moodInput, string &genreInput);     // Member 1: Wan

string validateMood(string moodInput);                         // Member 2: Aishah

string getPlaylistName(string mood, string genre);             // Member 3: Visshaa
string getPlaylistDescription(string mood);                    // Member 3: Visshaa

string getSubscriptionPlan(double weeklyHours, double monthlyBudget, double &monthlyCost); // Member 4: Dania

void displayFinalResult(string mood, string genre, string playlistName,
                         string playlistDesc, string plan, double monthlyCost); // Member 5: Sabrina

string toLowerCase(string text);                                // Member 6: Fakhira
double getPositiveNumber(string prompt);                        // Member 6: Fakhira
string validateGenre(string genreInput);                        // Member 6: Fakhira


// ================================================================
// MAIN FUNCTION - already wired up, do not change
// ================================================================
int main() {
    displayWelcomeBanner();

    string rawMood, rawGenre;
    getUserInputs(rawMood, rawGenre);

    string mood = validateMood(rawMood);
    string genre = validateGenre(rawGenre);

    double weeklyHours   = getPositiveNumber("Enter your average weekly listening hours: ");
    double monthlyBudget = getPositiveNumber("Enter your monthly budget for streaming (RM): ");

    string playlistName = getPlaylistName(mood, genre);
    string playlistDesc = getPlaylistDescription(mood);

    double monthlyCost = 0.0;
    string plan = getSubscriptionPlan(weeklyHours, monthlyBudget, monthlyCost);

    displayFinalResult(mood, genre, playlistName, playlistDesc, plan, monthlyCost);

    cout << "\nThank you for using Spotify Playlist Generator & Subscription Advisor!\n";
    return 0;
}


// ================================================================
// MEMBER 1: Wan
// Main menu + user input prompts
// TODO:
//   1. In displayWelcomeBanner(): print a welcome banner using
//      "====" dividers and a short intro message.
//   2. In getUserInputs(): prompt for mood, then genre, using
//      getline(cin, ...) and store them in the reference
//      parameters moodInput / genreInput.
// ================================================================
void displayWelcomeBanner() {
    cout << "Welcome to SPOTIFY!" << endl;
    cout << "=========================================" << endl;
    cout << "Playlist Generator & Subscription Advisor" << endl;
    cout << "=========================================" << endl;
    cout << "Answer a few quick questions and get\nreccomended a playlist and subscription\nplan, personalised just for you!" << endl;
    cout << "=========================================" << endl;
}

void getUserInputs(string &moodInput, string &genreInput) {
    cout << "How are you feeling today?" << endl;
    cout << "Choose your MOOD: Happy / Sad / Chill / Focus" << endl;
    cout << "Mood: ";
    getline(cin, moodInput);
    cout << endl;

    cout << "What kind of music are you into?" << endl;
    cout << "Choose a GENRE: Pop, Hip-Hop, Rock, EDM, Lo-fi, etc." << endl;
    cout << "Genre: ";
    getline(cin, genreInput);
    cout << endl;
}

// ================================================================
// MEMBER 2: Aishah
// Mood validation
// TODO:
//   1. Convert moodInput to lowercase (use toLowerCase() from
//      Member 6's section).
//   2. Loop while it is NOT one of: happy / sad / chill / focus.
//      Inside the loop: print an error message and re-prompt
//      with getline(cin, moodInput) to get a new value.
//   3. Return the validated mood with the first letter capitalized.
// ================================================================
string validateMood(string moodInput) {
    // TODO (Aishah): validate + re-prompt loop goes here
    return "Happy"; // placeholder so the program still runs
}


// ================================================================
// ================================================================
// ================================================================
// MEMBER 3: Visshaa
// Playlist recommendation
// ----------------------------------------------------------------
// 1. In getPlaylistName(): combine mood + genre into a playlist
//    title, e.g. mood + " " + genre + " Mix".
// 2. In getPlaylistDescription(): use if/else if on mood to
//    return a one-line description for Happy / Sad / Chill / Focus.
// ================================================================
string getPlaylistName(string mood, string genre) {
    // Build playlist name from mood + genre
    // Example: mood = "Happy", genre = "Pop" -> "Happy Pop Mix"
    return mood + " " + genre + " Mix";
}

string getPlaylistDescription(string mood) {
    // Return description text based on mood
    if (mood == "Happy") {
        return "Upbeat, feel-good tracks to lift your mood and keep you smiling.";
    }
    else if (mood == "Sad") {
        return "Emotional, slower songs for reflection and comfort.";
    }
    else if (mood == "Chill") {
        return "Relaxed, laid-back beats to help you unwind and de-stress.";
    }
    else if (mood == "Focus") {
        return "Instrumental and low-distraction tracks for deep concentration.";
    }
    else {
        return "A custom playlist made for your current vibe.";
    }
}

// ================================================================
// MEMBER 4: Dania
// Subscription tier logic
// TODO:
//   1. Define price constants for Premium and Family plans.
//   2. Using if/else on weeklyHours (and monthlyBudget), decide
//      between "Free" / "Premium" / "Family".
//   3. Set monthlyCost (passed by reference) to match the chosen
//      plan, and return the plan name.
// ================================================================
string getSubscriptionPlan(double weeklyHours, double monthlyBudget, double &monthlyCost) {
    // TODO (Dania): tier logic based on weeklyHours + monthlyBudget
    monthlyCost = 0.0;
    return "[TODO: plan]";
}


// ================================================================
// MEMBER 5: Sabrina
// Output formatting
// TODO:
//   Print all the results (mood, genre, playlist name + description,
//   plan, monthly cost) using "====" and "----" dividers, spacing,
//   and setprecision(2) for the monthly cost.
// ================================================================
void displayFinalResult(string mood, string genre, string playlistName,
                         string playlistDesc, string plan, double monthlyCost) {
    // TODO (Sabrina): formatted final output goes here
    cout << "[TODO: final result display not implemented yet]\n";
}


// ================================================================
// MEMBER 6: Fakhira
// Edge cases + finalize
// TODO:
//   1. toLowerCase(): loop through the string converting each
//      character with tolower().
//   2. getPositiveNumber(): loop reading a double with cin >>,
//      reject cin.fail() or negative values (clear + ignore +
//      re-prompt), and handle cin.eof() so it can't loop forever.
//   3. validateGenre(): if genreInput is empty, return "Various";
//      otherwise capitalize the first letter and return it.
//   4. Do a final pass over the whole file: remove leftover TODOs,
//      double check comments, and test the whole program end to end.
// ================================================================
string toLowerCase(string text) {
    // TODO (Fakhira): lowercase conversion loop
    return text;
}

double getPositiveNumber(string prompt) {
    // TODO (Fakhira): safe numeric input loop (handles negative,
    // non-numeric, and end-of-input cases)
    cout << prompt;
    double value = 0.0;
    cin >> value;
    cin.ignore(10000, '\n');
    return value;
}

string validateGenre(string genreInput) {
    // TODO (Fakhira): handle empty genre + capitalize first letter
    return genreInput;
}
