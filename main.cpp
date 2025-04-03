#include <iostream>
#include <cstdlib>   // For rand() and srand()
#include <ctime>   
#include "rock_paper.cpp"  
#include "casino_guess.cpp"  
#include "tick_tac_toe.cpp"  

using namespace std;



// Main function
int main() {

    

int choice ; 
char exit_choice;
    do{

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

        cout << "Enter the choice: " ;
        cin >> choice ;
        if (choice == 3 ){
            srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator
            char playAgain;
            RockPaperScissorsGame game;
    
            do {
                game.play();
                cout << "\nDo you want to play again? (y/n): ";
                cin >> playAgain;
                } 
            while (playAgain == 'y' || playAgain == 'Y');
            }

        if (choice == 2 ){
            srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator

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

        if (choice == 1){
            char playAgainn;
            do{
                Game game;
                game.play();
                cout << "\nDo you want to play again? (y/n): ";
                cin >> playAgainn;
            }
            while (playAgainn == 'y' || playAgainn == 'Y');
        }
        cout << "Want to exit fom GAMESTATION? (y/n): " ; 
        cin >>exit_choice;
    }
    while (exit_choice != 'y' ) ;



}
