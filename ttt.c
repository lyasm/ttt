//compile wth: gcc ttt,c ttt
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/********/
/* #user input  ½ */
/* #input validation */
/* #win checking   */
/* #AI   */
/* #Win screen    */
/********/

bool valid_input(int pos[2]);
int printfield(char vals[3][3]);
int place_x();
int place_y();

int main()
{
	char vals[3][3] = {{' ',' ', ' '},{' ',' ',' '},{' ',' ',' '}};
	int player_place_pos[2];
	bool end = 0;

	printfield(vals);
	printf("You start\n");
	printf("e\n");

	while(!end) {
		do {
			player_place_pos[0] = place_x();
			player_place_pos[1] = place_y();
		} while (!valid_input(player_place_pos));
	printfield(vals);
	printf("%d",player_place_pos[1]);
	}
}

int place_x()
{
	char coordinate[3];
	int pos;
	printf("x:");
	fgets(coordinate, 3, stdin);
	pos = coordinate[0] - '0';
	return pos;
}

int place_y()
{
	char coordinate[3];
 	int pos;
	printf("y:");
	fgets(coordinate, 3, stdin);
	pos = coordinate[0] - '0';
	return pos;
}
int printfield(char vals[3][3])
{
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

bool valid_input(int pos[2])
{
	bool valid = 1;
	return valid ;
}
