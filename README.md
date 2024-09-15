# bridge_crossing_problem
Five people arrive at a bridge, late in the night. They have only one lamp between them. They must manage with it while crossing the bridge. The bridge is fragile and ready to break. The bridge is also very narrow and hence only two people can cross at a time. When two people cross using the lamp, one of them must come back with the lamp, so that the people left on the first bank, can cross over. There is an additional complication to the situation. All the people have different walking speeds and therefore the crossing time of a batch is equal to the speed of the slower person. The problem is to find the optimal crossover sequence, that is, the one that takes minimum time.

Input specification:
The people who arrive at the bridge are named A, B, C, D, and E. The input to this program will consist of the time each one of them takes to cross the bridge one-way. These times are specified in minutes without any fractional parts. We assume that there is no delay in handing over the lamp. The input will thus consist of five lines of the form: name <space> time <newline>

Output specification:
The program outputs the minimum total time required for the complete crossover.
Sample Input and Output:

Input:
A 1
B 2
C 3
D 4
E 5
Output:
16

Input:
A 1
B 3
C 5
D 8
E 13
Output:
29
