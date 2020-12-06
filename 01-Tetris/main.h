#include <stdio.h>              // 标准头文件
#include <windows.h>            // 控制windows窗口界面头文件，DOS界面
#include <conio.h>              // 接收键盘输入输出
#include <time.h>               // 用于获取随机数

/*******宏  定  义*******/
#define FrameX 13   		    // 游戏窗口左上角的X轴坐标
#define FrameY 3   			    // 游戏窗口左上角的Y轴坐标
#define Frame_height  20 	    // 游戏窗口的高度
#define Frame_width   18 	    // 游戏窗口的宽度

/*******定  义  全  局  变  量 *******/
int i,j,Temp,Temp1,Temp2; 	//temp,temp1,temp2用于记住和转换方块变量的值
int a[80][80]={0};   		//标记游戏屏幕的图案：2,1,0分别表示该位置为游戏边框、方块、无图案;初始化为无图案
int b[4];     				//标记4个"口"方块：1表示有方块，0表示无方块
struct Tetris		//声明俄罗斯方块的结构体
{
 	int x;     		//中心方块的x轴坐标
 	int y;     		//中心方块的y轴坐标
 	int flag;    	//标记方块类型的序号
 	int next;    	//下一个俄罗斯方块类型的序号
 	int speed;    	//俄罗斯方块移动的速度
 	int number;    	//产生俄罗斯方块的个数
 	int score;    	//游戏的分数
 	int level;    	//游戏的等级
};
HANDLE hOut;		//控制台句柄

/*******函  数  声  明 *******/
void gotoxy(int x, int y);			//光标移到指定位置
void DrwaGameframe();				//绘制游戏边框
void Flag(struct Tetris *);			//随机产生方块类型的序号
void MakeTetris(struct Tetris *);	//制作俄罗斯方块
void PrintTetris(struct Tetris *);	//打印俄罗斯方块
void CleanTetris(struct Tetris *);	//清除俄罗斯方块的痕迹
int  ifMove(struct Tetris *);		//判断是否能移动，返回值为1，能移动，否则，不能移动
void Del_Fullline(struct Tetris *);	//判断是否满行，并删除满行的俄罗斯方块
void Gameplay();					//开始游戏
void regulation();                  //游戏规则
void explation();                   //按键说明
void welcom();                      //欢迎界面
void Replay(struct Tetris *);  		//重新开始游戏
void title();                       //欢迎界面上方的标题
void flower();                      //欢迎界面上的字符装饰花
void close();                       //关闭游戏
