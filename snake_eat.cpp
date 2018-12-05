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
int gameover();
void put_money();

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
int food_x;
int food_y;


int main() 
{
    put_money();     // 生成钱币 
    char choice;
    output();	     // 先输出场景 
    while (1)        // 不断获取指令 
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
        
        
        if (snakeX[0] == food_x && snakeY[0] == food_y)   // 吃到食物之后长度增加一格 
		{
            put_money();
            snake_length++;
            snakeX[snake_length - 1] = snakeX[snake_length - 2];
            snakeY[snake_length - 1] = snakeY[snake_length - 2];
            map[snakeY[snake_length - 1]][snakeX[snake_length - 1]] = 'X';
        }
        if (!gameover()) 
		{
            printf("gameover!!!\n");
            return 0;
        } else 
		{
            output();
        }
    }
    return 0;
}

void snake_move()   // 每一格身体都挪动 
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

int gameover() 
{
    if (snakeX[0] == SNAKE_MAX_LENGTH || snakeX[0] == 0) // 头部X坐标碰墙 
	{
        return 0;
    }
    if (snakeY[0] == SNAKE_MAX_LENGTH || snakeY[0] == 0) // 头部Y坐标碰墙 
	{
        return 0;
    }
    for (int i = 1; i < snake_length; i++) 
	{
        if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i]) // 碰到自己也判定死亡 
		{
            return 0;
        }
    }
    return 1;
}
void output()            //输出场景 
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
void put_money()        // 随机生成钱币坐标 
{
    srand((unsigned)(time(NULL)));
    food_x = rand() % 9 + 1;
    food_y = rand() % 9 + 1;
    while (map[food_y][food_x] != ' ') 
	{
        food_x = rand() % 9 + 1;
        food_y = rand() % 9 + 1;
    }
    map[food_y][food_x] = '$';
}
