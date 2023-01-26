/* 

Jack Morrison
jackmorr@iastate.edu
CPRE 185 Section #3

Class #={DAYNUM} [={TITLE}]

	[Reflection 1]	<What were you trying to learn or achieve?>
        ={ANSWER_1}

	[Reflection 2]	<Were you successful? Why or Why not?>
        ={ANSWER_2}

	[Reflection 3]	<Would you do anything differently if starting this program over? If so, explain.>
        ={ANSWER_3}

	[Reflection 4]	<Think about the most important thing you learned when writing this piece of code.> 
					<What was it and explain why it was significant.>
        ={ANSWER_4}

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
