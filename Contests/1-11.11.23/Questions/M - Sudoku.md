# M - Sodoku
##### [UVA - 13115](https://vjudge.net/problem/UVA-13115/origin)

My friend Gerson loves to resolve sudokus. A sudoku is a numeric puzzle formed by a grid of n × n,
divided in n grids of √
n ×
√
n. Every row, column and grid must contain all the numbers from 1 to
n, without repeat. Gerson can resolve 20 sudokus per day, the problem is that 19 of them are wrong.
Can you make a program that given the solutions found by Gerson tell him if they are wrong or right?
## Input
The first line of input contains a integer t, the number of test cases. Each case begins with an integer
n (1 ≤ n ≤ 25), it is guaranteed that n have an square root. This line is followed by n lines, each one
with n numbers mi,j separated by a blank space (1 ≤ mi,j ≤ n, with 1 ≤ i, j ≤ n).
## Output
For each test case prints a single line with the word ‘yes’ if the sudoku has been resolved correctly or
‘no’ otherwise.