/* 

Jack Morrison
jackmorr@iastate.edu
CPRE 185 Section #3

Class #={DAYNUM} [={TITLE}]

	[Reflection 1]	<What were you trying to learn or achieve?>
        We are learning the basic input and output operations for c.

	[Reflection 2]	<Were you successful? Why or Why not?>
        Yes because I already knew the material.

	[Reflection 3]	<Would you do anything differently if starting this program over? If so, explain.>
        No because I already did it the way I would want to.

	[Reflection 4]	<Think about the most important thing you learned when writing this piece of code.> 
					<What was it and explain why it was significant.>
        If I had to say one thing it would be that this is meant to teach some basic stuff about printf and scanf and variables.

	[Other questions/comments for Instructors]
*/

#include <stdio.h>

int main(void) {
    const int NUM_SCORES = 5;
    double sum = 0;
    for (int i = 0; i < NUM_SCORES; i++) {
        double score;
        printf("Test score %d: ", i + 1);
        scanf("%lf", &score);
        sum += score;
    }
    double avg = sum / (double) NUM_SCORES;
    printf("Average: %f\n", avg);
    return 0;
}
