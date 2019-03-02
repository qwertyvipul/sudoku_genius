# Sudoku Genius

### What is this?
This is a sudoku solver. Given an input array of puzzle with the empty boxes as 0. It will solve the puzzle and provide you with the step-by-step solution.

### How does it work?
* It maintains a probability list for all the empty nodes.

* When a node is found with only one probable value entry it updates the node value to that value and updated the probability list of the corresponding rows and columns to the node.

* Iterating through the empty list again and again it converges to the solution. Though computationally not so effiecient. This naive approach guaratees a solution to all levels of sudoku games found in the newspapers.

### How to run the project?
1. Clone the game_1.0 folder in your pc.
2. Naviagate to the folder.
3. Compile main.cpp file `gcc main.cpp`
4. Execute and run `./a.out`

### Game Version 1.0
[View the working](game_1.0/README.md)