#define _CRT_SECURE_NO_WARNINGS
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

#define TETRIS_MENU
/*#define DEMO_MENU
#define DEMO_BUTTON
#define DEMO_ROTATE
#define DEMO_EDITBOX*/

static double winwidth, winheight;

void Main(){
SetWindowTitle("tetris wula!");
InitGraphics();
winwidth = GetWindowWidth();
winheight = GetWindowHeight();
registerCharEvent(CharEventProcess); // �ַ�
registerKeyboardEvent(KeyboardEventProcess);// ����
registerMouseEvent(MouseEventProcess);      // ���
registerTimerEvent(TimerEventProcess);      // ��ʱ��
}
#if defined(TETRIS_MENU)
// �˵���ʾ����
void drawMenu()
{ 
	static char * menuListFile[] = {"File",  
		"Open  | Ctrl-O", // ��ݼ��������[Ctrl-X]��ʽ�������ַ����Ľ�β
		"Close",
		"Exit   | Ctrl-E"};
	static char * menuListTool[] = {"Tool",
		"Triangle",
		"Circle",
		"Stop Rotation | Ctrl-T"};
	static char * menuListHelp[] = {"Help",
		"Show More  | Ctrl-M",
		"About"};
	static char * selectedLabel = NULL;

	double fH = GetFontHeight();
	double x = 0; //fH/8;
	double y = winheight;
	double h = fH*1.5; // �ؼ��߶�
	double w = TextStringWidth(menuListHelp[0])*2; // �ؼ����
	double wlist = TextStringWidth(menuListTool[3])*1.2;
	double xindent = winheight/20; // ����
	int    selection;
	
	// menu bar
	drawMenuBar(0,y-h,winwidth,h);
	// File �˵�
	selection = menuList(GenUIID(0), x, y-h, w, wlist, h, menuListFile, sizeof(menuListFile)/sizeof(menuListFile[0]));
	if( selection>0 ) selectedLabel = menuListFile[selection];
	if( selection==3 )
		exit(-1); // choose to exit
	
	// Tool �˵�
	menuListTool[3] = enable_rotation ? "Stop Rotation | Ctrl-T" : "Start Rotation | Ctrl-T";
	selection = menuList(GenUIID(0),x+w,  y-h, w, wlist,h, menuListTool,sizeof(menuListTool)/sizeof(menuListTool[0]));
	if( selection>0 ) selectedLabel = menuListTool[selection];
	if( selection==3 )
		enable_rotation = ! enable_rotation;
	
	// Help �˵�
	menuListHelp[1] = show_more_buttons ? "Show Less | Ctrl-M" : "Show More | Ctrl-M";
	selection = menuList(GenUIID(0),x+2*w,y-h, w, wlist, h, menuListHelp,sizeof(menuListHelp)/sizeof(menuListHelp[0]));
	if( selection>0 ) selectedLabel = menuListHelp[selection];
	if( selection==1 )
		show_more_buttons = ! show_more_buttons;

	// ��ʾ�˵����н��
	x = winwidth/15;
	y = winheight/8*7;
	SetPenColor("Blue");
	drawLabel(x,    y-=h, "Most recently selected menu is:");
	SetPenColor("Red");
	drawLabel(x+xindent, y-=h, selectedLabel);
	SetPenColor("Blue");
	drawLabel(x,    y-=h, "Control Variable Status");
	SetPenColor("Red");
	drawLabel(x+xindent, y-=h, enable_rotation ? "Rotation Enabled" : "Rotation Disabled");
	drawLabel(x+xindent, y-=h, show_more_buttons ? "More Buttons" : "Less Button");
}
#endif // #if defined(DEMO_MENU)
