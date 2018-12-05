#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define SNAKE_MAX_LENGTH 20 
#define SNAKE_HEAD 'H'
#define SNAKE_BODY 'X'
#define BLANK_CELL ' '
#define WALL_CELL '*'
#define SANKE_FOOD '$'

void snake_move(); 
void output();

char map[12][12] = {
    "***********",
    "*XXXXH    *",
    "*         *",
    "*         *",
    "*         *",
    "*         *",
    "*         *",
    "*         *",
    "*         *",
    "*         *",
    "***********",
};

int snake_length = 5;
int snakeX[SNAKE_MAX_LENGTH] = {5, 4, 3, 2, 1};
int snakeY[SNAKE_MAX_LENGTH] = {1, 1, 1, 1, 1};


int main() 
{
    char choice;
    output();	     // ��������� 
    while (1)        // ���ϻ�ȡָ�� 
	{
        scanf("%s", &choice);
        snake_move();

		if(choice=='w')
		{
            snakeY[0] -= 1;
            map[snakeY[0]][snakeX[0]] = 'H';
        }
        if(choice=='s')
		{
            snakeY[0] += 1;
            map[snakeY[0]][snakeX[0]] = 'H';
        }
        if(choice=='a')
		{
            snakeX[0] -= 1;
            map[snakeY[0]][snakeX[0]] = 'H';
        }
        if(choice=='d')
		{
            snakeX[0] += 1;
            map[snakeY[0]][snakeX[0]] = 'H';
        }
   
            output();
    }
    return 0;
}

void snake_move()   // ÿһ�����嶼Ų�� 
{
    int i;
    map[snakeY[snake_length - 1]][snakeX[snake_length - 1]] = ' ';
    for (i = snake_length - 1; i > 0; i--) 
	{
        snakeX[i] = snakeX[i - 1];
        snakeY[i] = snakeY[i - 1];
        map[snakeY[i]][snakeX[i]] = 'X';
    }
}


void output()            //������� 
{
    for (int i = 0; i <= 11; i++) 
	{
        for (int j = 0; j <= 11; j++) 
		{
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

