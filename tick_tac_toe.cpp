#include <iostream>
using namespace std;

const int SIZE = 3;

// Class to represent the game board
class Board {
private:
    char grid[SIZE][SIZE];  // 3x3 board

public:
    Board() {
        // Initialize the board with empty cells
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                grid[i][j] = ' ';
            }
        }
    }

    // Function to display the board
    void display() {
        system("cls");  // Clear the console (use "clear" for Linux/Mac)
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

    // Function to place a move on the board
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

// Class to represent a player
class Player {
private:
    char symbol;  // 'X' or 'O'

public:
    Player(char sym) : symbol(sym) {}

    char getSymbol() const {
        return symbol;
    }
};

// Class to manage the game
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

// Main function
int main() {
    Game game;
    game.play();
    return 0;
}
