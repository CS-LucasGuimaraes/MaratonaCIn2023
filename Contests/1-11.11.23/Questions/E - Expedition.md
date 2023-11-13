# E - Expedition
##### [Gym - 103797E](https://vjudge.net/problem/Gym-103797E/origin)

Everyone is excited for their first bus expedition outside of town, especially because it'll be the first task of everyone's favorite dynamic duo (story for another time). You are the command assistant and thus are responsible for letting the lieutenants aware of how much time is needed to occupy the bus.

The bus has four seats per row, two on each side, and only one entrance, in the front of the bus. It's instructed that, when entering the bus, the student should find the farthest row from the entrance which still has an empty seat. Then, the student should prioritize the window seats, to let the next student seat on the aisle seat. Each student should take 2
 seconds to cross a row, 5
 seconds to sit in an aisle seat and 10
 seconds to sit in a window seat.

It should be an easy task, but there are some introverted students who don't follow the instructions. They instead search for the farthest row from the entrance which still has an empty window seat, in the hopes that they will travel alone. They will still sit on the window seat, leaving the aisle seat available. If there are no window seats left, they will follow the instructions normally. The other students don't know which students are introverted, so they will not avoid sitting next to them. Fortunately, you know which students are introverted, so you should be able to give the correct information to the lieutenants.

## Input
The first line contains a single integer N
 (1≤N≤30
) — the number of rows in the bus.

The next line contains a string S
 (1≤|S|≤4×N
) — the aspect of each student in the order they enter the bus. S0
 is the first to enter. If student i
 is an introvert, Si=I
. Otherwise, Si=E
.

## Output
Print a single line, the amount of time needed for everyone to sit down, in seconds.