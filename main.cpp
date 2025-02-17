#include <iostream>
#include <cstdlib>   // For rand() and srand()
#include <ctime>   
using namespace std;

const int SIZE = 3;

// Class of Tic_Tac_Toe
class Board {
private:
    char grid[SIZE][SIZE]; 

public:
    Board() {
        // Initialize the board with empty cells
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                grid[i][j] = ' ';
            }
        }
    }

    void display() {
        system("clear");
        cout << "Tic-Tac-Toe Game" << endl;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                cout << " " << grid[i][j];
                if (j < SIZE - 1) cout << " |";
            }
            cout << endl;
            if (i < SIZE - 1) cout << "---|---|---" << endl;
        }
    }

    bool placeMove(int row, int col, char symbol) {
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && grid[row][col] == ' ') {
            grid[row][col] = symbol;
            return true;
        }
        return false;
    }

    // Function to check if a player has won
    bool checkWin(char symbol) {
        // Check rows and columns
        for (int i = 0; i < SIZE; i++) {
            if ((grid[i][0] == symbol && grid[i][1] == symbol && grid[i][2] == symbol) ||  // Row
                (grid[0][i] == symbol && grid[1][i] == symbol && grid[2][i] == symbol)) {  // Column
                return true;
            }
        }

        // Check diagonals
        if ((grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol) ||  // Main diagonal
            (grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol)) {  // Anti-diagonal
            return true;
        }

        return false;
    }

    // Function to check if the board is full (for a draw)
    bool isFull() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (grid[i][j] == ' ') return false;
            }
        }
        return true;
    }
};

class Player {
private:
    char symbol;  // 'X' or 'O'

public:
    Player(char sym) : symbol(sym) {}

    char getSymbol() const {
        return symbol;
    }
};


class Game {
private:
    Board board;
    Player player1;
    Player player2;
    Player* currentPlayer;

public:
    Game() : player1('X'), player2('O'), currentPlayer(&player1) {}

    // Function to switch turns between players
    void switchTurn() {
        if (currentPlayer == &player1) {
            currentPlayer = &player2;
        } else {
            currentPlayer = &player1;
        }
    }

    // Main function to play the game
    void play() {
        bool gameOver = false;
        int row, col;

        while (!gameOver) {
            board.display();
            cout << "Player " << currentPlayer->getSymbol() << "'s turn." << endl;
            cout << "Enter row (0-2): ";
            cin >> row;
            cout << "Enter column (0-2): ";
            cin >> col;

            // Validate the move
            if (board.placeMove(row, col, currentPlayer->getSymbol())) {
                // Check for win or draw
                if (board.checkWin(currentPlayer->getSymbol())) {
                    board.display();
                    cout << "Player " << currentPlayer->getSymbol() << " wins!" << endl;
                    gameOver = true;
                } else if (board.isFull()) {
                    board.display();
                    cout << "It's a draw!" << endl;
                    gameOver = true;
                } else {
                    switchTurn();  // Switch to the next player
                }
            } else {
                cout << "Invalid move. Try again." << endl;
            }
        }
    }
};





// CASINO
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

// Main function
int main() {


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



    int while_loop_choice = 1 ;
    while(while_loop_choice != 0){
        // cout<< " "
        
    }

    //ttt game
    Game game;
    game.play();


    //casino-game
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
}
