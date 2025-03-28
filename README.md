# Tetris Game in C++

## Overview

This is a simple **Tetris** game implemented in **C++**, using the **Windows Console API** for rendering and input handling. The game allows players to control falling tetrominoes, clear lines, and track their score.

## Features

- **7 Tetromino Shapes**: Includes the standard O, I, L, J, S, Z, and T shapes.
- **Smooth Movement**: Move left, right, down, and rotate pieces.
- **Instant Drop**: Press `spacebar` to drop the piece instantly.
- **Line Clearing**: Full lines are removed, and score is updated.
- **Game Over Detection**: The game ends when new pieces can't be placed.
- **High Score Tracking**: Tracks the highest score in a session.
- **Replay Option**: Allows restarting the game after game over.

## How to Play

- **Left Arrow Key (a)** → Move left
- **Right Arrow Key (d)** → Move right
- **S** → Move down
- **R** → Rotate the tetromino
- **Spacebar** → Instant drop

## Setup & Compilation

### Prerequisites

- **Windows OS** (as it uses Windows API functions)
- **C++ Compiler (MinGW/GCC or MSVC)**

### Compilation

Use **g++** (MinGW) to compile the program:

```sh
 g++ tetris.cpp -o tetris.exe
```

### Running the Game

```sh
 ./tetris.exe
```

## Code Breakdown

### 1. Game Setup

- Initializes game board (`vector<vector<int>>`)
- Defines `Tetromino` shapes
- Handles console settings (cursor hiding, coloring)

### 2. Game Logic

- **`canMove(dx, dy)`** → Checks if movement is possible
- **`mergeTetromino()`** → Locks pieces into the board
- **`clearLines()`** → Removes full lines and updates the score
- **`rotateTetromino()`** → Rotates a piece if space allows
- **`input()`** → Handles player controls
- **`gameLoop()`** → Main game loop that moves pieces, checks collisions, and updates the board

## Known Limitations

- The game **does not save** high scores between runs.
- Only works in **Windows Console** (not portable to Linux/macOS).

## Future Improvements

- Add **hold piece** feature
- Improve **collision handling for rotations**
- Implement **better graphics with external libraries (e.g., SDL, OpenGL)**
- Support **Linux/macOS compatibility**

## Pictures  

![Tetris](https://github.com/user-attachments/assets/f3f1b7a8-8ebe-439e-852a-ef83322713d5)
![Tetris 1](https://github.com/user-attachments/assets/30e3cfaf-7f25-41d8-b537-db88d52d992c)

## Author
Developed by

Parth Sorathiya - 202401215  
Prit Kasundra - 202401453  
Rudra Trivedi - 202401266  
Aaryan Dalsaniya - 202401405  

