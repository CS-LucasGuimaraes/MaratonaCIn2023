# G - Number Spiral 
##### [CSES - 1071](https://vjudge.net/problem/CSES-1071/origin)

A number spiral is an infinite grid whose upper-left square has number 1. Here are the first five layers of the spiral:
||||||
| -- | -- | -- | -- | -- |
| 01 | 02 | 09 | 10 | 25 |
| 04 | 03 | 08 | 11 | 24 |
| 05 | 06 | 07 | 12 | 23 |
| 16 | 15 | 14 | 13 | 22 |
| 17 | 18 | 19 | 20 | 21 |


Your task is to find out the number in row y and column x.

## Input
The first input line contains an integer 
t: the number of tests.

After this, there are t lines, each containing integers 
y and x.

## Output
For each test, print the number in row y and column x.

## Constraints
* 1≤t≤10^5
* 1≤y,x≤10^9