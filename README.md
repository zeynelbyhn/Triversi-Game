Triversi - C Programming Game
Triversi is a strategic board game designed for 3 players (Red, Yellow, and Blue) played on a dynamic grid. The objective is to have the most pieces of your color on the board when all cells are filled.
+4

Game Rules

Board Size: The user can define the board size, with a maximum limit of 23x23 to ensure stability.
+1

Initial Move: The game starts by placing the first piece in the exact center of the board. The logic automatically calculates the center for both odd and even-sized grids.
+1


Placement Strategy: Every new piece must be placed adjacent to at least one existing piece on the board.
+1


Piece Transformation: When a piece is placed, the program scans in 8 different directions (horizontal, vertical, and diagonal). Any opponent pieces trapped between the newly placed piece and another piece of the same color are converted to the current player's color.
+3


Winning: Once the board is full, the program counts the Red (K), Yellow (S), and Blue (M) pieces to determine and announce the winner.
+2

Technical Features
Written in C using 2D arrays for board management.
+1

Implemented custom directional scan algorithms using while loops and flags for piece conversion.
+2

Includes robust input validation for coordinates and board boundaries.

Installation and Usage
To compile and run the game on your local machine, use a C compiler (like GCC):

Bash
# Compile the source code
gcc 23011104.c -o triversi

# Run the game
./triversi
