#include "graphics.h"
#include "extgraph.h"
#include "genlib.h"
#include "simpio.h"
#include "conio.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include <windows.h>
#include <olectl.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>

#include "imgui.h"

#define DEMO_MENU
#define DEMO_BUTTON
#define DEMO_ROTATE
#define DEMO_EDITBOX

static double winwidth, winheight;   // ���ڳߴ�
static int    show_more_buttons = 0; // ��ʾ���ఴť

// ����������provided in libgraphics
void DisplayClear(void); 
// ��ʱ������������provided in libgraphics
void startTimer(int id,int timeinterval);

// �û�����ʾ����
void display(void); 

// �û����ַ��¼���Ӧ����
void CharEventProcess(char ch)
{
	uiGetChar(ch); // GUI�ַ�����
	display(); //ˢ����ʾ
}

// �û��ļ����¼���Ӧ����
void KeyboardEventProcess(int key, int event)
{
	uiGetKeyboard(key,event); // GUI��ȡ����
	display(); // ˢ����ʾ
}

// �û�������¼���Ӧ����
void MouseEventProcess(int x, int y, int button, int event)
{
	uiGetMouse(x,y,button,event); //GUI��ȡ���
	display(); // ˢ����ʾ
}

//��Ϸ�������� 
void Start_game();   //��ʼ��Ϸ 
void ranking_list();//��ʾ���а� 
void ReadArchiving();//��ȡ�浵 
void Save_game();//������Ϸ 
void Pause_game();//��ͣ��Ϸ 
void Resume_game();//�ָ���Ϸ 
void ShowHelp();//��ʾ���� 
void ShowHAbout();//��ʾ���� 


void TimerEventProcess(int timerID);
void prefunction();//Ԥ����ÿ��ˢ��ʱ��һ��ע���ɫ�߿�
void BlockMove(int direction);//�ѵ�ǰ������ƶ�һ��
int isblock(int a,int b,int x,int y);//�ж�xy����λ���ܷ���� һ��ab�ͷ���
void clean();//�����ǰ�����
void drawblock(int a,int b,int x,int y);//��xy����λ�û���һ��ab�ͷ���
void BlockInit();//���������һ�������a��
void blockicy();//���ᵱǰ�����
void blcokdecline();//����������
void finaldraw();//��������ʽ���ձ��ͼ��
int block[12][22];//��ʼ��Ϊ0����հף���1��2��3��4��5��6��7������ͬ��ɫ
int newblock;//���ڴ洢��һ�������a����
int indexx,indexy;//���浱ǰָʾ��
int indexa,indexb;//���浱ǰָʾ����
int ms;//����ʱ����
int score;//

