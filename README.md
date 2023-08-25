# WFC Sudoku Solver

This is a web-based Sudoku solver that utilizes the Wave Function Collapse algorithm to solve Sudoku. 
The solver is implemented in JavaScript and HTML.

## Try It

You can try it [`here`](http://damngoodfreehost.infinityfreeapp.com/Sudoku/sudoku.html)

## The idea behind

The Wave Function Collapse algorithm is a technique borrowed from quantum physics and is applied to the domain of procedural generation. 

In the context of Sudoku, it is used to iteratively collapse possibilities for each cell based on constraints until a solution is found or deemed impossible. 

At the beginning each cell has 9 possible states (here's the inspiration from quantum states)

![StartBoard](https://github.com/iamnotmat/Sudoku_WFC/assets/75623519/dc4bbb0c-6f99-496e-af09-7506eb52f66c)

Everytime the user chooses a number the algorithm automatically collapses all the cells in the collapsed row, column and 3x3 square, updating the possible states for each cell based on the entered numbers.

![AfterCollapse](https://github.com/iamnotmat/Sudoku_WFC/assets/75623519/c8e2390b-31e5-4bcc-a5c5-93b29d73e5fe)

(Here you can see how the number 5 was removed from all the collapsed tiles)

## C++ files

The first sample implementation I've made from scratch was in C++, so I thought it would be interesting to also share the code I started from to implement it in the webpage.

---

Feel free to explore, use, and modify this Sudoku solver to enhance your understanding of the Wave Function Collapse algorithm and Sudoku solving strategies. If you have any questions or improvements, please feel free to contribute or reach out to me.
