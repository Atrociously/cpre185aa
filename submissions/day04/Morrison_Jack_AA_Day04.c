/* 

Jack Morrison
jackmorr@iastate.edu
CPRE 185 Section #3

Class #04 [mathRand]

	[Reflection 1]	<What were you trying to learn or achieve?>
        We are learning about math functions.

	[Reflection 2]	<Were you successful? Why or Why not?>
        Yes because I used the pow function and the M_PI constant

	[Reflection 3]	<Would you do anything differently if starting this program over? If so, explain.>
        No it is a pretty simple program there is not much to change.

	[Reflection 4]	<Think about the most important thing you learned when writing this piece of code.> 
					<What was it and explain why it was significant.>
        That there was an M_PI constant for pi.

	[Other questions/comments for Instructors]
*/

#include <stdio.h>
#include <math.h>

int  main() {
    double radius;

    printf("Radius = ");
    scanf("%lf", &radius);

    double volume = (4.0 / 3.0) * M_PI * pow(radius, 3.0);
    printf("Volume = %lf\n", volume);
	return 0;
}
