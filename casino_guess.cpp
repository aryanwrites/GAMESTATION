#include <iostream>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time() to seed random number generator
using namespace std;

// CasinoGame class to manage the number guessing game
class CasinoGame {
private:
    int randomNumber;  // Random number to be guessed
    int minRange;
    int maxRange;
    int difficultyLevel;  // Difficulty level chosen by the player
    int fixattempts;  // Difficulty level chosen by the player

    // Function to generate a random number
    void generateRandomNumber() {
        randomNumber = rand() % (maxRange - minRange + 1) + minRange;
    }

public:
    CasinoGame() : minRange(1), maxRange(10), difficultyLevel(1), randomNumber(0) {}

    // Function to display the difficulty menu and set the difficulty level
    void setDifficulty() {
        cout << "\n==== Welcome to the Casino Number Guessing Game ====" << endl;
        cout << "Select Difficulty Level:" << endl;
        cout << "1. Easy (Range: 1-10, Prize: $100) Attempts : 5" << endl;
        cout << "2. Medium (Range: 1-50, Prize: $500)  Attempts : 7" << endl;
        cout << "3. Hard (Range: 1-100, Prize: $1000)  Attempts : 9" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> difficultyLevel;

        switch (difficultyLevel) {
            case 1:
                minRange = 1;
                maxRange = 10;
                fixattempts = 5 ;
                break;
            case 2:
                minRange = 1;
                maxRange = 50;
                fixattempts = 7 ;
                break;
            case 3:
                minRange = 1;
                maxRange = 100;
                fixattempts = 9 ;
                break;
            default:
                cout << "Invalid choice! Defaulting to Easy level." << endl;
                minRange = 1;
                maxRange = 10;
        }
        generateRandomNumber();
    }

    // Function to play the game
    void playGame() {
        int playerGuess;
        int attempts = 0;

        cout << "\nGuess the number between " << minRange << " and " << maxRange << ": ";
        while (true) {
            cin >> playerGuess;
            attempts++;

            if (attempts == fixattempts) {
                cout << "Out of Attempts!" << endl;
                cout<< randomNumber <<" was the number" << endl ;
                break;
            } 
            if (playerGuess == randomNumber) {
                cout << "Congratulations! You guessed the number in " << attempts << " attempts." << endl;
                awardPrize();
                break;
            } else if (playerGuess < randomNumber) {
                cout << "Low! Try again: ";
            } else {
                cout << "High! Try again: ";
            }
        }
    }

    // Function to calculate and display the prize
    void awardPrize() const {
        int prize = 0;
        switch (difficultyLevel) {
            case 1:
                prize = 100;
                break;
            case 2:
                prize = 500;
                break;
            case 3:
                prize = 1000;
                break;
        }
        cout << "You won $" << prize << "!" << endl;
    }
};

// Main function to manage the game loop
int main() {
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator

    char playAgain;
    do {
        CasinoGame game;
        game.setDifficulty();
        game.playGame();

        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing the Casino Number Guessing Game!" << endl;
    return 0;
}
