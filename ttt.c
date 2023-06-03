#include <stdio.h>
#include <string.h>

void printfield();

int main() {
        printf("Hello World\n");
	printfield();
	return 0;
}

void printfield() {
	int line_num = 1;
	while(line_num <= 11) {
		switch (line_num % 4) {
		case 1:
			printf("       |       |        \n");
			break;
		case 2 :
			printf("   a   |   a   |   a    \n");
			break;
		case 3 :
			printf("       |       |        \n");
			break;
		case 0 :
			printf("-------+-------+-------\n");
			break;
		default :
			printf("Error: incorrect line-number\n");
			break;
		}
		line_num++;
	}
}
