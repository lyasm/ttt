//compile wth: gcc ttt,c ttt
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/********/
/* #user input   */
/* #fix terminal visual bug  ❌ (only happens on first terminal)*/
/* #win checking   */
/* #AI   */
/* #Win screen    */
/********/


int printfield(char vals[3][3]);
int  place();
int main() {
	char vals[3][3] = {{' ',' ', ' '},{' ',' ',' '},{' ',' ',' '}};
	int player_place_pos;
	bool end = 0;
	
	printfield(vals);
	printf("You start\n");
	printf("To place your piece:\nEnter the x coordinate followed by the y coordinate, seperate them using an space\n");
	while(!end) {
	player_place_pos = place();
	printfield(vals);
	printf("%d",player_place_pos);
	}
}

int  place(){
	char coordinate[5];
	int pos;
	fgets(coordinate, 5, stdin);
	pos = coordinate[2] - '0';
	pos += (coordinate[0] - '0') * 10;
	return pos;
}

int printfield(char vals[3][3]) {
	printf("\033[2J");  // Clear the entire screen
	printf("\033[H");   // Move cursor to home position (0, 0)
	int line_num = 1;
	char vals_line[3];
	while(line_num <= 11) {
		switch (line_num % 4) {
		case 1:
			printf("       |       |        \n");
			break;
		case 2 :
			vals_line[0] = vals[line_num/4 - 1/2][0];
			vals_line[1] = vals[line_num/4 - 1/2][1];
			vals_line[2] = vals[line_num/4 - 1/2][2];
			printf("   %c   |   %c   |   %c    \n", vals_line[0], vals_line[1], vals_line[2]);
			break;
		case 3 :
			printf("       |       |        \n");
			break;
		case 0 :
			printf("-------+-------+-------\n");
			break;
		default :
			printf("Error: incorrect line-number\n");
			return 1;
		}
		line_num++;
	}
		return 0;
}

