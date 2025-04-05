#include <iostream>
#include <cstdlib>   // For rand() and srand()
#include <ctime>   
#include "rock_paper.cpp"  
#include "casino_guess.cpp"  
#include "tick_tac_toe.cpp"  

using namespace std;



// Main function

int main() {
    int choice;
    char exit_choice;
    
    do {
        try {
            cout << "**************************************************" << endl;
cout << "*                                                *" << endl;
cout << "*         ██   ██  ██████  ██       █████        *" << endl;
cout << "*         ██   ██ ██    ██ ██      ██   ██       *" << endl;
cout << "*         ███████ ██    ██ ██      ███████       *" << endl;
cout << "*         ██   ██ ██    ██ ██      ██   ██       *" << endl;
cout << "*         ██   ██  ██████  ███████ ██   ██       *" << endl;
cout << "*                                                *" << endl;
cout << "*                WELCOME TO PS-69!               *" << endl;
cout << "*                                                *" << endl;
cout << "**************************************************" << endl;
cout << "\n\n";
cout << "=====================================================" << endl;
cout << "|           CHOOSE YOUR GAME BELOW                |" << endl;
cout << "|     (1) Tic_Tac_Toe    (2) Casino    (3) Rock-Paper-Cissor        |" << endl;
cout << "=====================================================" << endl;

            
            cout << "Enter your choice: ";
            if (!(cin >> choice)) {
                throw invalid_argument("Invalid input! Please enter a number.");
            }
            
            if (choice < 1 || choice > 3) {
                throw out_of_range("Invalid choice! Please select a valid option.");
            }
            
            if (choice == 3) {
                srand(static_cast<unsigned int>(time(0))); 
                char playAgain;
                RockPaperScissorsGame game;
                do {
                    game.play();
                    cout << "\nDo you want to play again? (y/n): ";
                    cin >> playAgain;
                } while (playAgain == 'y' || playAgain == 'Y');
            }
            
            else if (choice == 2) {
                srand(static_cast<unsigned int>(time(0))); 
                char playAgain;
                do {
                    CasinoGame game;
                    game.setDifficulty();
                    game.playGame();
                    cout << "\nDo you want to play again? (y/n): ";
                    cin >> playAgain;
                } while (playAgain == 'y' || playAgain == 'Y');
                cout << "Thanks for playing the Casino Number Guessing Game! \n" << endl;
            }
            
            else if (choice == 1) {
                char playAgain;
                do {
                    Game game;
                    game.play();
                    cout << "\nDo you want to play again? (y/n): ";
                    cin >> playAgain;
                } while (playAgain == 'y' || playAgain == 'Y');
            }
        }
        catch (const invalid_argument &e) {
            cout << "Error: " << e.what() << "\nPlease try again!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        catch (const out_of_range &e) {
            cout << "Error: " << e.what() << "\nPlease try again!" << endl;
            continue;
        }
        catch (...) {
            cout << "An unexpected error occurred!" << endl;
            continue;
        }
        
        cout << "Want to exit from GAMESTATION? (y/n): ";
        cin >> exit_choice;
    } while (exit_choice != 'y' && exit_choice != 'Y');

    cout << "Thanks for playing!" << endl;
    return 0;
}
