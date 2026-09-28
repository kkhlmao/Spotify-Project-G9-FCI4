/*
 * ================================================================
 *  SPOTIFY PLAYLIST GENERATOR & SUBSCRIPTION ADVISOR
 * ----------------------------------------------------------------
 *  Course   : LDCW6123 - Fundamentals of Digital Competence
 *             for Programmers
 *  Part     : Part 2 - C++ Program (inspired by Spotify)
 *  Group 9  : Wan, Aishah, Visshaa, Dania, Sabrina, Fakhira
 * ================================================================
 */

#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <cstdlib>

using namespace std;

// ================================================================
// FUNCTION PROTOTYPES 
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
// MAIN FUNCTION - ties all 6 sections together
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
// ================================================================
string validateMood(string moodInput) {

    moodInput = toLowerCase(moodInput);

    while (moodInput != "happy" &&
           moodInput != "sad" &&
           moodInput != "chill" &&
           moodInput != "focus") {

        cout << "Invalid mood. Please enter Happy, Sad, Chill, or Focus: ";
        getline(cin, moodInput);

        moodInput = toLowerCase(moodInput);
    
    }

    moodInput[0] = toupper(moodInput[0]);

    return moodInput;
}

// ================================================================
// MEMBER 3: Visshaa
// Playlist recommendation
// ================================================================
string getPlaylistName(string mood, string genre) {
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
// ================================================================
string getSubscriptionPlan(double weeklyHours, double monthlyBudget, double &monthlyCost) {
    const double PREMIUM_PRICE = 14.90; // RM per month
    const double FAMILY_PRICE  = 29.90; // RM per month

    string plan;

    if (weeklyHours < 5) {
        // Light listener - Free plan is enough
        plan = "Free";
        monthlyCost = 0.0;
    } else if (weeklyHours <= 15) {
        // Moderate listener - suggest Premium if budget allows
        if (monthlyBudget >= PREMIUM_PRICE) {
            plan = "Premium";
            monthlyCost = PREMIUM_PRICE;
        } else {
            plan = "Free";
            monthlyCost = 0.0;
        }
    } else {
        // Heavy listener (>15 hrs/week) - suggest Family if affordable,
        // otherwise fall back to Premium, otherwise Free
        if (monthlyBudget >= FAMILY_PRICE) {
            plan = "Family";
            monthlyCost = FAMILY_PRICE;
        } else if (monthlyBudget >= PREMIUM_PRICE) {
            plan = "Premium";
            monthlyCost = PREMIUM_PRICE;
        } else {
            plan = "Free";
            monthlyCost = 0.0;
        }
    }

    return plan;
}

// ================================================================
// MEMBER 5: Sabrina
// Output formatting
// ================================================================
void displayFinalResult(string mood, string genre, string playlistName,
                        string playlistDesc, string plan, double monthlyCost) {
    
  
    cout << "\n========================================\n";
    cout << "           RECOMMENDED PLAYLIST           \n";
    cout << "========================================\n";
    
    // Playlist information and colon alignment
    cout << "   Mood          : " << mood << "\n";
    cout << "   Genre         : " << genre << "\n";
    cout << "   Playlist Name : " << playlistName << "\n";
    cout << "   Description   : " << playlistDesc << "\n";

  
    cout << "----------------------------------------\n";
    
    // Subscription details and formatted price
    cout << "   Subscription  : " << plan << "\n";
    cout << "   Monthly Cost  : RM " << fixed << setprecision(2) << monthlyCost << "\n";
    

    cout << "========================================\n";
}


// ================================================================
// MEMBER 6: Fakhira
// Edge cases + finalize
// - toLowerCase(): shared helper used for case-insensitive checks
// - getPositiveNumber(): rejects negative numbers and non-numeric
//   input instead of letting the program crash or misbehave
// - validateGenre(): handles empty genre input gracefully
// ================================================================
string toLowerCase(string text) {
    for (size_t i = 0; i < text.length(); i++) {
        text[i] = tolower(text[i]);
    }
    return text;
}

double getPositiveNumber(string prompt) {
    double value;

    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.eof()) {
            cout << "\nNo more input detected. Exiting program.\n";
            exit(0);
        }

        if (cin.fail() || value < 0) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a positive number.\n";
            continue;
        }

        cin.ignore(10000, '\n');
        break;
    }

    return value;
}

string validateGenre(string genreInput) {
    if (genreInput.empty()) {
        return "Various";
    }

    genreInput[0] = toupper(genreInput[0]);
    return genreInput;
}
