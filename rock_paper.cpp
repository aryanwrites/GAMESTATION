#include <iostream>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For seeding random number generation
#include <string>
using namespace std;

// Enum to represent the choices
enum Choice { ROCK, PAPER, SCISSORS };

// Class representing the game logic
class RockPaperScissorsGame {
private:
    Choice userChoice;
    Choice computerChoice;

public:
    // Function to display the menu and get user's choice
    void getUserChoice() {
        int choice;
        cout << "\n==== Rock-Paper-Scissors ====" << endl;
        cout << "1. Rock" << endl;
        cout << "2. Paper" << endl;
        cout << "3. Scissors" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        // Validate input and convert to enum
        switch (choice) {
            case 1:
                userChoice = ROCK;
                break;
            case 2:
                userChoice = PAPER;
                break;
            case 3:
                userChoice = SCISSORS;
                break;
            default:
                cout << "Invalid choice! Defaulting to Rock." << endl;
                userChoice = ROCK;
        }
    }

    // Function to generate a random choice for the computer
    void generateComputerChoice() {
        int randomNum = rand() % 3;  // Generate a random number between 0 and 2
        computerChoice = static_cast<Choice>(randomNum);
    }

    // Function to convert choice enum to string
    string choiceToString(Choice choice) const {
        switch (choice) {
            case ROCK:
                return "Rock";
            case PAPER:
                return "Paper";
            case SCISSORS:
                return "Scissors";
            default:
                return "Unknown";
        }
    }

    // Function to determine and display the result
    void determineWinner() const {
        cout << "\nYour choice: " << choiceToString(userChoice) << endl;
        cout << "Computer's choice: " << choiceToString(computerChoice) << endl;

        if (userChoice == computerChoice) {
            cout << "It's a tie!" << endl;
        } else if ((userChoice == ROCK && computerChoice == SCISSORS) ||
                   (userChoice == PAPER && computerChoice == ROCK) ||
                   (userChoice == SCISSORS && computerChoice == PAPER)) {
            cout << "You win!" << endl;
        } else {
            cout << "Computer wins!" << endl;
        }
    }

    // Function to play the game
    void play() {
        getUserChoice();
        generateComputerChoice();
        determineWinner();
    }
};

// Main function
int main() {
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator

    char playAgain;
    RockPaperScissorsGame game;

    do {
        game.play();
        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing Rock-Paper-Scissors!" << endl;
    return 0;
}
