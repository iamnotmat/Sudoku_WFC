# WFC Sudoku Solver

This is a web-based Sudoku solver that utilizes the Wave Function Collapse algorithm to solve Sudoku. 
The solver is implemented in JavaScript and HTML.

## Try It

You can try it [`here`](https://teotexe.github.io/Projects/Sudoku_WFC/sudoku.html)

## The idea behind

The Wave Function Collapse algorithm is a technique borrowed from quantum physics and is applied to the domain of procedural generation. 

In the context of Sudoku, it is used to iteratively collapse possibilities for each cell based on constraints until a solution is found or deemed impossible. 

At the beginning each cell has 9 possible states (here's the inspiration from quantum states)

![StartBoard](https://github.com/user-attachments/assets/aaa09e1c-8e57-408d-9af6-70dfbf726e8d)


Everytime the user chooses a number the algorithm automatically collapses all the cells in the collapsed row, column and 3x3 square, updating the possible states for each cell based on the entered numbers.

![AfterCollapse](https://github.com/user-attachments/assets/38266ec1-9c22-4877-b343-aaf70a601127)

(Here you can see how the number 5 was removed from all the collapsed tiles)

## C++ files

The first sample implementation I've made from scratch was in C++, so I thought it would be interesting to also share the code I started from to implement it in the webpage.
