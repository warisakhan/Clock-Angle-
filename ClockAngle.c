/* Warisa Khan G01257446
CS 262, Lab Section 208  Lab 4
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
	/*initializing variables
	 */
	char input[20];
	int A;
	int h;
	int hour;
	int min;
	int m; 
	int mirrorH;
	int mirrorM;
	
	A =0;
	h = 0;
	hour = 0;
	min = 0;
	m = 0;
	mirrorH = 0;
	mirrorM = 0;
/*do while loop
 */
	do{
		/*asking user for input and passing it in.
		 */
		printf("Please enter an angle from 0-180:\n");
		fgets(input, 20, stdin);
		sscanf(input, "%d", &A);

		/*checking to see if the angle meets with the restraints
		 */
	
		if(0 <= A || A <= 180){
			break;
		}
	}while(A < 0 || A > 180);
/*if the angle is 0, the time is set
 */
	if(A == 0){
                printf("There are 2 hours where the hands are 0 degrees apart\n");
                printf("00:00\n");
                printf("12:00\n");
                exit(0);
        }
/*if the angle is 180 the time is set
 */
        if(A == 180){
                printf("There are 2 hours where the hands are 0 degrees apart\n");
                printf("6:00\n");
                printf("18:00\n");
                exit(0);
        }

/* if the angle is not divisble by 6 then there is not angle availble 
 */
        if(A % 6 != 0){
                printf("There is no hour where the hands are A degrees apart\n");
		exit(0);
        }

	/* using a double for loop to check for the hour and the minute 
	 */
	for(h = 0; h < 13; h++){
		for(m = 0; m < 60; m ++){
			/*seeing if the angle is equivalent to A
			 */
			if(((0.5*(60* h + m)) -(m * 6)) == A){
				if(hour == 0 && min == 0){
					hour = h;
					min = m;
					break;
				}
				

		}
			
			else if((m*6) - (0.5*(60*h + m))== A) {
				if(hour == 0 && min == 0){
					hour = h;
					min = m;
					break;
				}
		
			}
	}

	}

	/*calculating mirror time 
	 */
	mirrorH = 23 - hour;
        mirrorM = 60 - min;

       	if(mirrorM == 60){
                mirrorM = 0;
                mirrorH ++;
        }
	/*print staements if the mirrortime meets the requirements
	 */
	if(mirrorH - 12 < 0 || hour + 12 == 24){
               	printf("%02d:%02d\n",hour - 12, min);
                printf("%02d:%02d\n",mirrorH, mirrorM);
                printf("%02d:%02d\n",hour, min);
                printf("%02d:%02d\n",mirrorH+12, mirrorM);
                exit(0);
	
	}

	/*print statements for outisde of this condition
	 */
	
	printf("%02d:%02d\n", hour, min);
	printf("%02d:%02d\n", mirrorH-12, mirrorM);
	printf("%02d:%02d\n", hour+12, min);
	printf("%02d:%02d\n", mirrorH, mirrorM);

	return 0;

}

