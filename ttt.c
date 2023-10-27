
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
void place_comp(char vals[BOARD_SIZE][BOARD_SIZE], int pos[2], char, int round);
bool end(char vals[BOARD_SIZE][BOARD_SIZE], char);

/* some global vars*/

int main()
{
	char vals[BOARD_SIZE][BOARD_SIZE] = {{' ',' ', ' '},{' ',' ',' '},{' ',' ',' '}};
	int place_pos[2];

	printfield(vals);
	printf("You start\n");
	printf("the field in the left corner ir (0,0)\n");
	char stone_player = chose_stone("Enter an Charactor as your stone");
	char stone_comp = 'x';
	int round = 0;
	while(!end(vals, stone_comp)) {
		place_pos[0] = -1;
		place_pos[1] = -1;
		do {
			place_pos[1] = place_x();
			place_pos[0] = place_y();
			if(!valid_input(place_pos, vals)) {
				printf("Invalid position, try again\n");
			}
		} while (!valid_input(place_pos, vals));
		vals[place_pos[0]][place_pos[1]] = stone_player;
		if(end(vals,stone_player)){
			break;
		}
		place_comp(vals, place_pos, stone_comp, round);
		vals[place_pos[0]][place_pos[1]] = stone_comp;
	printfield(vals);
	round++;
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

void place_comp(char vals[BOARD_SIZE][BOARD_SIZE], int pos[2], char stone, int round)
{
	bool mid_own = 0;
	int last_mov_emem[2] = {pos[0], pos[1]};
	goto claim_mid;
	decide:
	if(last_mov_emem == (int[2]){0, 0} || last_mov_emem == (int[2]){0, 2} || last_mov_emem == (int[2]){2, 0} || last_mov_emem == (int[2]){2, 2}) {
		goto react_corner;
	}
	

	claim_mid:
	if(valid_input((int[2]){1, 1}, vals)){ //try claiming center first
		pos[0] = 1;
		pos[1] = 1;
		return;
	} else if (vals[1][1] == stone) {
		mid_own = 1; //set center as claimed
		goto decide;
	}
	
	claim_corner:
	pos[0] = 0;
	pos[1] = 0;
	for (int n = 1; n < 4 && !valid_input((int[2]){pos[0], pos[1]}, vals);	n++) {
		pos[0] = (n / 2) * 2;
		pos[1] = (n % 2) * 2;
	}

	react_corner:
	if(!mid_own) {
		pos[0] = 2 - last_mov_emem[0];
		pos[1] = 2 - last_mov_emem[1];
		if (valid_input(pos, vals)) {
			return;
		} else {
			goto corner_op_owned;
		}
	} else {
		pos[0] = last_mov_emem[0];
		pos[1] = 2 - last_mov_emem[1];
		if (!valid_input(pos, vals)) {
			pos[0] = 2 - last_mov_emem[0];
			pos[1] = last_mov_emem[1];
		} else {
			return;
		}
	}
	
	corner_op_owned:
	pos[0] = last_mov_emem[0];
	pos[1] = 2 - last_mov_emem[1];
	if (!valid_input(pos, vals)) {
		pos[0] = 2- last_mov_emem[0];
		pos[1] = last_mov_emem[1];
	}
	if (valid_input(pos, vals)) {
		return;
	}
	random:
	return;
}

int  printfield(char vals[BOARD_SIZE][BOARD_SIZE])
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
	bool valid = (' '== vals[pos[0]][pos[1]] && 0 <= pos[0] && pos[0] < BOARD_SIZE && 0 <= pos[1] && pos[1] < BOARD_SIZE);
	/* if(!valid) { */
	/* printf("%d, %d",pos[0],pos[1]); */
	/* 	printf("Invalid position, try again\n"); */
	/* } */
	return valid;
}
