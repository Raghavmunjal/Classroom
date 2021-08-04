/**
 * program to Implement the tower of hanoi function
 *
 * Compilation : gcc -o tower_of_hanoi tower_of_hanoi.c
 * Execution : ./tower_of_hanoi
 *
 * @Raghav and 1910990074  4/08/21
 * Assignment -> 5 Recursion
 */

#include <stdio.h>

// total moves required to moves n disk from source to destination
int moves;

// from - source , to - destination , aux - helper
void tower_of_hanoi(int n, char from, char to, char aux){
    
    // base case
    if (n == 0)
        return;
    
    // move n-1 disks from source to aux
    tower_of_hanoi(n-1, from, aux, to);

    // move nth disk from source to destination
    printf("\n Move disk %d from rod %c to rod %c", n, from, to);

    // incrementing moves
    moves++;

    // move n-1 disk from aux to destination
    tower_of_hanoi(n-1, aux, to, from);

}
int main() {

    // calling function to move disk from source A to destination C
    tower_of_hanoi(3,'A','C','B');

    printf("\nMoves Required -> %d",moves);

    return 0;
}

