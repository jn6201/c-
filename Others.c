#include "main.h"

extern double winwidth, winheight,FontSize;
extern int isgame;

// ��ʾ About 
void ShowAbout() {
	if(isgame==1) pause(); //��֤��Ϸ��ͣ
	FontSize = GetFontHeight();
	SetPenSize(FontSize*1.5);
	double h = FontSize*1.5;
	double w = FontSize*3;
	double x = winwidth/2.0-w/2.0;
	double y = winheight/8;
	SetPenColor("Black");
	drawLabel(winwidth/2.0-TextStringWidth("A Simple Tetris Game")/2, y+22*GetFontHeight(), "A Simple Tetris Game");
	drawLabel(winwidth/2.0-TextStringWidth("Developed by our team")/2, y+20*GetFontHeight(), "Developed by our team");
	drawLabel(winwidth/2.0-TextStringWidth("Thanks for playing!")/2, y+18*GetFontHeight(), "Thanks for playing!");
	if(button(GenUIID(0), x, y, w, h, "Yes!")){ //����ȷ�ϰ�ť
		carryon(); //�ָ�����״̬ 
	}
}

//��ʾ Help 
void ShowHelp() {
	if(isgame==1) pause(); //��֤��Ϸ��ͣ
	FontSize = GetFontHeight();
	SetPointSize(FontSize*2);
	double h = FontSize*1.5;
	double w = FontSize*3;
	double x = winwidth/2.0-w/2.0;
	double y = winheight/8;
	SetPenColor("Black");
	drawLabel(winwidth/2.0-TextStringWidth("Use Left & Right To Move Tetromino")/2, y+22*GetFontHeight(), "Use Left & Right To Move Tetromino");
	drawLabel(winwidth/2.0-TextStringWidth("Use Space To Rotate")/2, y+20*GetFontHeight(), "Use Space To Rotate");
	drawLabel(winwidth/2.0-TextStringWidth("Use Down Key To Set Current Tetromino")/2, y+18*GetFontHeight(), "Use Down Key To Set Current Tetromino");
	drawLabel(winwidth/2.0-TextStringWidth("Other Shortcut Keys Pls See Menu ;)")/2, y+16*GetFontHeight(), "Other Shortcut Keys Pls See Menu ;)");
	if(button(GenUIID(0), x, y, w, h, "Yes!")){ //����ȷ�ϰ�ť
		carryon();; //�ָ�����״̬ 
	}
}
