#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 
//定义字符
#define ROW 10    //改变这两个数值可改变棋盘大小
#define COL 10
 
//初始化棋盘数据
void InitBoard(char(*Board)[COL], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			Board[i][j] = ' ';
		}
	}
}
 
//打印棋盘及棋盘数据
void Display_Board(char Board[ROW][COL]) {
	system("cls");
	int i = 0, j = 0;
	printf("   ");
	for (i = 0; i < COL; i++) {
		if (i < COL - 1)
			printf(" %d |", i + 1);
		else
			printf(" %d ", i + 1);
	}
	printf("\n\n");
	for (i = 0; i < ROW; i++) {
		
		 if (i < ROW - 1) {
			for (j = 0; j < COL; j++) {
				if (j == 0)
					printf("%d   %c |", i + 1, Board[i][j]);
				else if (j < COL - 1) {
					printf(" %c |", Board[i][j]);
				}
				else
					printf(" %c \n", Board[i][j]);
			}
		}
		else {
			for (j = 0; j < COL; j++) {
				if (j == 0&&ROW<10)
					printf("%d   %c |", i + 1, Board[i][j]);
				else if(j==0)
					printf("%d  %c |", i + 1, Board[i][j]);
				else if (j < COL - 1) {
					printf(" %c |", Board[i][j]);
				}
				else
					printf(" %c \n", Board[i][j]);
			}
		}
		
 
		 if (i < ROW - 1)
			 printf("- ");
		 else
			 printf("  ");
		if (i < ROW - 1) {
			for (j = 0; j < COL; j++) {
				if(j==0){
					printf(" ---|");
				}else if (j < COL - 1)
					printf("---|");
				else
					printf("---\n");
			}
		}
		
	}
}
 
//玩家一落子
void Player_one(char Board[ROW][COL]) {
	printf("Please player1 to enter the numbers of rows and columns:");
	int x, y;
	while (1) {
		scanf_s("%d%d", &x, &y);
		
		//判断坐标合法性
		if (x <= ROW && y <= COL && x >= 1 && y >= 1) {
			//判断坐标是否被占用
			if (Board[x - 1][y - 1] == ' ') {
				Board[x - 1][y - 1] = 'X';
				printf("玩家一落子\n\n");
				Display_Board(Board);
				break;
			}
			else {
				printf("该位置已经有棋了哦，请重新下棋：");
			}
		}
		else {
			printf("You have entered an invalid symbol! Please re-enter:");
		}
	}
	
}
 
//玩家二落子
void Player_two(char Board[ROW][COL]) {
	printf("Please player2 to enter the numbers of rows and columns:");
	int x, y;
	while (1) {
		scanf_s("%d%d", &x, &y);
 
		//判断坐标合法性
		if (x <= ROW && y <= COL && x >= 1 && y >= 1) {
			//判断坐标是否被占用
			if (Board[x - 1][y - 1] == ' ') {
				Board[x - 1][y - 1] = 'O';
				printf("玩家二落子\n");
				Display_Board(Board);
				break;
			}
			else {
				printf("该位置已经有棋了哦，请重新下棋：");
			}
		}
		else {
			printf("You have entered an invalid symbol! Please re-enter:");
		}
	}
 
}
 
//电脑落子
void Computer(char Board[ROW][COL]) {
 
	while (1) {
		int x = rand() % ROW;
		int y = rand() % COL;
		//判断是否占用
		if (Board[x][y] == ' ') {
			Board[x][y] = 'O';
			printf("电脑落子\n\n");
			Display_Board(Board);
			break;
		}
	}
}
 
//判断游戏状态
char check_win(char Board[ROW][COL]) {
	
 
	//判断行
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL - 4; j++) {
			if (Board[i][j] == Board[i][j + 1] && Board[i][j] == Board[i][j + 2] 
				&& Board[i][j] == Board[i][j + 3]
				&& Board[i][j] == Board[i][j + 4]
				&& Board[i][j] != ' ') {
				return Board[i][j];
			}
		}
	}
	//判断列
	for (int i = 0; i < ROW - 4; i++) {
		for (int j = 0; j < COL; j++) {
			if (Board[i][j] == Board[i+1][j] && Board[i][j] == Board[i+2][j]
				&& Board[i][j] == Board[i + 3][j] 
				&& Board[i][j] == Board[i + 4][j] 
				&& Board[i][j] != ' ') {
 
				return Board[i][j];
			}
		}
	}
	//判断左对角线
	for (int i = 0; i < ROW - 4; i++) {
		for (int j = 0; j < COL - 4; j++) {
			if (Board[i][j] == Board[i+1][j+1] && Board[i][j] == Board[i+2][j+2]
				&& Board[i][j] == Board[i + 3][j + 3] 
				&& Board[i][j] == Board[i + 4][j + 4]
				&& Board[i][j] != ' ') {
				return Board[i][j];
			}
		}
	}
	//判断右对角线
	for (int i = 0; i < ROW-4 ; i++) {
		for (int j = 4; j < COL; j++) {
			if (Board[i][j] == Board[i - 1][j - 1] && Board[i][j] == Board[i - 2][j - 2]
				&& Board[i][j] == Board[i - 3][j - 3] 
				&& Board[i][j] == Board[i - 4][j - 4] && Board[i][j] != ' ') {
				return Board[i][j];
			}
		}
	}
	//判断棋盘是否满了
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			if (Board[i][j] == ' ')
				return 'g';
		}
	}
 
	return 'p';
}
 
void menu() {
	system("cls");
	printf("********************\n");
	printf("***** 1.play one ***\n");
	printf("***** 2.play two ***\n");
	printf("***** 3.exit *******\n");
	printf("********************\n");
}
 
 
void game() {
 
	//存储棋盘数据-二维数组   
	char Board[ROW][COL];  //这里只创建了数据，但背景棋盘没有必要单独写出来，就和数据一起了
 
	//初始化棋盘数据
	InitBoard(Board, ROW, COL);
 
	//打印棋盘和棋盘数据
	Display_Board(Board);
	
	
	char sign;
	while (1) {
		
		//玩家一 下棋 并判断游戏是否继续
		Player_one(Board);
		sign = check_win(Board);
		if (sign != 'g')
			break;
	    
		//电脑下棋 并判断游戏是否继续
		Computer(Board);
		sign = check_win(Board);
		if (sign != 'g')
			break;
 
	}
	
	
		//判断胜利者
	if (sign == 'X')
		printf("Player_one is a winer!\n");
	else if (sign == 'O')
		printf("Computer is a winer!\n");
	else
		printf("There are no losers here!\n");
	printf("按任意键回到主菜单");
	getch();
}
 
void game_two() {
 
	//存储棋盘数据-二维数组   
	char Board[ROW][COL];  //这里只创建了数据，但背景棋盘没有必要单独写出来，就和数据一起了
 
	//初始化棋盘数据
	InitBoard(Board, ROW, COL);
 
	//打印棋盘和棋盘数据
	Display_Board(Board);
 
 
	char sign;
	while (1) {
 
		//玩家一 下棋 并判断游戏是否继续
		Player_one(Board);
		sign = check_win(Board);
		if (sign != 'g')
			break;
 
		//玩家二下棋 并判断游戏是否继续
		Player_two(Board);
		sign = check_win(Board);
		if (sign != 'g')
			break;
 
	}
 
 
	//判断胜利者
	if (sign == 'X')
		printf("Player_one is a winer!\n");
	else if (sign == 'O')
		printf("Computer is a winer!\n");
	else
		printf("There are no losers here!\n");
	printf("按任意键回到主菜单");
	getch();
}
 
int main(void) {
	srand((unsigned int)time(NULL));
 
	
	int chose_menu;
	do {
		//打印目录
		menu();
		printf("请输入你的要求：");
 
 
		//根据用户选择进入界面
		
		scanf_s("%d", &chose_menu);
		switch (chose_menu) {
		case 1:
			printf("The game is loading,please wait patiently\n");
			game();
			break;
		case 2:
			game_two();
			break;
		case 3:
			printf("The game is exiting!\n");
			break;
		default:
			printf("You have entered an invalid symbol! Please re-enter:\n");
			break;
		}
	} while (chose_menu != 3);
	
	return 0;
 
	
	
}
