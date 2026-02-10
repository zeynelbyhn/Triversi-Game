# Triversi – C Programming Game

Triversi is a board game where **3 players (Red, Yellow, Blue)** strategically place stones on a **variable-sized board** using C programming.

## Game Rules

- **Board Size:** Maximum board size is **23x23**.
- **Starting Move:** The first stone is placed at the **center of the board**.
- **Moves:** Each new stone must be placed **adjacent to an existing stone**.
- **Conversion Rule:** Opponent stones that are **between two stones of the same color** are converted to the current player's color.  
  Conversion is checked in **8 directions**.
- **Winning Condition:** When the board is full, the player with the **highest number of stones** wins.

## Installation and Execution

Compile and run the program using the following commands:

```bash
gcc main.c -o triversi
./triversi
