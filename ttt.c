
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
#define WIN 1
#define NOWIN 0


char chose_stone(char question[]);
bool valid_input(int pos[2], char vals[BOARD_SIZE][BOARD_SIZE]);
int printfield(char vals[BOARD_SIZE][BOARD_SIZE]);
int place_x();
int place_y();
bool end(char vals[BOARD_SIZE][BOARD_SIZE], char);

int main()
{
	char vals[BOARD_SIZE][BOARD_SIZE] = {{' ',' ', ' '},{' ',' ',' '},{' ',' ',' '}};
	int player_place_pos[2];

	printfield(vals);
	printf("You start\n");
	printf("the field in the left corner ir (0,0)\n");
	char stone_player = chose_stone("Enter an Charactor as your stone");
	char stone_comp = 'x';
	while(!end(vals, stone_player)) {
		do {
			player_place_pos[1] = place_x();
			player_place_pos[0] = place_y();
		} while (!valid_input(player_place_pos, vals));
		vals[player_place_pos[0]][player_place_pos[1]] = stone_player;
		if(end(vals,stone_comp)){
			break;
		}
	printfield(vals);
	}
	return 0;
}

bool end(char vals[BOARD_SIZE][BOARD_SIZE], char stone)
{
	for (int i = 0; i < 3; i++) {
		if ((vals[i][0] == stone && vals[i][1] == stone && vals[i][2] == stone) ||
		    (vals[0][i] == stone && vals[1][i] == stone && vals[2][i] == stone)) {
			return WIN;
		}
	}
	if ((vals[0][0] == stone && vals[1][1] == stone && vals[2][2] == stone) ||
	    (vals[0][2] == stone && vals[1][1] == stone && vals[2][0] == stone)) {
		return WIN;
	}
	return NOWIN;
}

char chose_stone(char question[])
{
	char stone[3];
	printf("%s", question);
	fgets(stone, 3, stdin);
	return stone[0];
}

int place_x()
{
	char coordinate[BOARD_SIZE];
	int pos;
	printf("x:");
	fgets(coordinate, 3, stdin);
	pos = coordinate[0] - '0';
	return pos;
}

int place_y()
{
	char coordinate[BOARD_SIZE];
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
	char vals_line[BOARD_SIZE];
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

bool valid_input(int pos[2], char vals[BOARD_SIZE][BOARD_SIZE])
{
	bool valid = (' '==vals[pos[0]][pos[1]] && 0 <= pos[0] && pos[0] < BOARD_SIZE && 0 <= pos[1] && pos[1] < BOARD_SIZE);
	if(!valid) {
		printf("Invalid position, try again\n");
	}
	return valid;
}
