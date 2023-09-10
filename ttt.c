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


/********/

#define BOARD_SIZE 3
#define LINES_NUMBER_MAX 11
#define LINES_ROW 4

bool valid_input(int pos[2], char vals[3][3]);
int printfield(char vals[BOARD_SIZE][BOARD_SIZE]);
int place_x();
int place_y();

int main()
{
	char vals[3][3] = {{' ','0', ' '},{' ',' ',' '},{' ',' ',' '}};
	int player_place_pos[2];
	bool end = 0;

	printfield(vals);
	printf("You start\n");
	printf("the field in the left corner ir (0,0)\n");

	while(!end) {
		do {
			player_place_pos[1] = place_x();
			player_place_pos[0] = place_y();
		} while (!valid_input(player_place_pos, vals));
		vals[player_place_pos[0]][player_place_pos[1]] = 'o';
	printfield(vals);
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
int printfield(char vals[BOARD_SIZE][BOARD_SIZE])
{
	printf("\033[2J");  // Clear the entire screen
	printf("\033[H");   // Move cursor to (0, 0)
	int line_num = 1;
	char vals_line[3];
	int row = 0;

	while(line_num <= LINES_NUMBER_MAX) {
		int line_type = line_num % LINES_ROW;

		switch (line_type) {
		case 1:
			printf("       |       |        \n");
			break;
		case 2:
			vals_line[0] = vals[row][0];
			vals_line[1] = vals[row][1];
			vals_line[2] = vals[row][2];
			printf("   %c   |   %c   |   %c    \n", vals_line[0], vals_line[1], vals_line[2]);
			row++;
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

bool valid_input(int pos[2], char vals[3][3])
{
	bool valid = (' '==vals[pos[0]][pos[1]] && 0 <= pos[0] && pos[0] < 3 && 0 <= pos[1] && pos[1] < 3);
	if(!valid) {
		printf("Invalid position, try again\n");
	}
	return valid;
}
