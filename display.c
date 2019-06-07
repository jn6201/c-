#include "main.h"

extern double winwidth, winheight,FontSize;
extern int isgame,score,ms;
extern char FooterStr[30];
extern char DiffcultyStr[10];
extern enum gstates mainstate;

#if defined(DEMO_MENU)
// �˵���ʾ����
void drawMenu()
{
	SetPointSize(FontSize);
	static char * menuListFile[] = {"File",  
		"Start | Ctrl-O", 
		"Show ranking | Ctrl-R",
		"Save | Ctrl-S",
		"Exit | Ctrl-E"};
	static char * menuListTool[] = {"Tool",
		"Pause | Ctrl-P",
		"Speed-up | Ctrl-F",
		"Speed-down | Ctrl-D"};
	static char * menuListOthers[] = {"Others",
		"Help | Ctrl-H",
		"About | Ctrl-A"};
	static char * selectedLabel = NULL;

	double fH = GetFontHeight();
	double x = 0;
	double y = winheight;
	double h = fH*1.5; // �ؼ��߶�
	double w = TextStringWidth(menuListOthers[0])*2; // �ؼ����
	double wlist = TextStringWidth(menuListTool[3])*1.2;
	double xindent = winheight/20; // ����
	int    selection;
	
	// menu bar
	drawMenuBar(0,y-h,winwidth,h);
	// File �˵�
	selection = menuList(GenUIID(0), x, y-h, w, wlist, h, menuListFile, sizeof(menuListFile)/sizeof(menuListFile[0]));
	if( selection>0 ) selectedLabel = menuListFile[selection];
	if( selection==1 ) MAINGAME();  //��ʼ��Ϸ 
//	if( selection==2 ) ShowRanking(); //��ʾ���а� 
//	if( selection==3 ) Save_game();     //������Ϸ 
	if( selection==4 ) exit(-1); // choose to exit
	
	// Tool �˵�
	menuListTool[1] =(isgame!=1)? "Start | Ctrl-P":"Pause | Ctrl-P";
	selection = menuList(GenUIID(0),x+w,  y-h, w, wlist,h, menuListTool,sizeof(menuListTool)/sizeof(menuListTool[0]));
	if( selection>0 ) selectedLabel = menuListTool[selection];
	if( selection==1 ){ if(isgame==1)  pause();  //��ͣ��Ϸ 
						else if(isgame==2)   carryon();//�ָ���Ϸ 
						else if(isgame==0)   MAINGAME();//��ʼ��Ϸ 
						} 
	if( selection==2 ){ //���� 
		if(mainstate==Playing) faster();
		sprintf(FooterStr,"Diffculty changed to %s!",DiffcultyStr); //�޸���ʾ�� 
	}
	if( selection==3 ){ //���� 
		if(mainstate==Playing) 	slower();
		sprintf(FooterStr,"Diffculty changed to %s!",DiffcultyStr); //�޸���ʾ�� 
	}
	
	// Others �˵�
	selection = menuList(GenUIID(0),x+2*w,y-h, w, wlist, h, menuListOthers,sizeof(menuListOthers)/sizeof(menuListOthers[0]));
	if( selection>0 ) selectedLabel = menuListOthers[selection];
	if( selection==1 ) mainstate=showHelp;    //��ʾ������������ 
	if( selection==2 ) mainstate=showAbout;   //���� 
	}
#endif // #if defined(DEMO_MENU)

#if defined(DEMO_BUTTON)
// ��ť��ʾ����
void drawButtons()
{
	double fH = GetFontHeight();
	double h = fH*2;  // �ؼ��߶�
	double x = winwidth/3.5;  
	double y = winheight/2+3*h; 
	double w = winwidth/5; // �ؼ����
	
	if( button(GenUIID(0), x, y, w*2, h*2, "����Ϸ") )   //����Ϸ��ť 
		{	
			MAINGAME();
		}
		
	if( button(GenUIID(0), x, y-3*h, w*2, h*2, "��ȡ�浵") )  //��ȡ�浵��ť 
		{	
//			ReadArchiving(); 
		}
		
	if( button(GenUIID(0), x, y-6*h, w*2, h*2, "���а�") )  //���а�ť 
		{	
//			ranking_list();
		}
		
	if( button(GenUIID(0), x, y-9*h, w*2, h*2, "�˳�") )  //�˳���Ϸ 
		{	
			exit(-1);
		}
}
#endif

#if defined(DEMO_TOOLS)
// ���߰�ť��ʾ����
void drawTools()
{
	double fH = GetPointSize();
	double h = winwidth/15;
	double x = winwidth/1.8;
	double y = winheight/4;
	double w = winwidth/15;
	double dx= winwidth/15;

	//��ʼ������Ч��ͬ�˵���ʼ 
	if(button(GenUIID(0), x, y, w, h, "")) {
		if(isgame!=1) {
			if(isgame==2)  carryon();
//			else if(g_gamestate!=Cleaning)Start_game();
		}
	}

	//���ƿ�ʼͼ�� 
	SetPenColor("Black");
	SetPenSize(3);
	MovePen(x+w/6,y+w/6);
	DrawLine(0,w*2.0/3);
	DrawLine(w*2.0/3,-w/3);
	DrawLine(-w*2.0/3,-w/3);
	SetPenSize(0);
	
	//��ͣ������Ч��ͬ�˵���ͣ
	if(button(GenUIID(0), x+dx, y, w, h, "")) {
		if(isgame==1) pause();
	}
	//������ͣͼ�� 
	SetPenColor("Black");
	SetPenSize(10);
	MovePen(x+dx+w/3,y+w/6);
	DrawLine(0,w*2.0/3);
	MovePen(x+dx+w-w/3,y+w/6);
	DrawLine(0,w*2.0/3);
	SetPenSize(0);
	
	//ֹͣ������Ч��ֹͬͣ��ͣ
	if(button(GenUIID(0), x+2*dx, y, w, h, "")) {
//		if(g_gamestate==Playing||g_gamestate==Paused||g_gamestate==GameEnd) Stop_game();
	}
	//����ֹͣͼ�� 
	SetPenColor("Black");
	SetPenSize(22);
	MovePen(x+2*dx+w/3,y+w/3);
	DrawLine(0,w/3);
	DrawLine(w/3,0);
	DrawLine(0,-w/3);
	DrawLine(-w/3,0);
	SetPenSize(0);
	
	//���ٰ���
	if(button(GenUIID(0), x, y-dx, w, h, "")) {
		if(mainstate==Playing) {
			slower();
		}
		sprintf(FooterStr,"Diffculty changed to %s!",DiffcultyStr); //�޸���ʾ�� 
	}
	
	//���Ƽ���ͼ�� 
	SetPenColor("Black");
	SetPenSize(3);
	MovePen(x+w-w/3,y-dx+w/6);
	DrawLine(0,w*2.0/3);
	DrawLine(-w/2,-w/3);
	DrawLine(w/2,-w/3);
	MovePen(x+w-w/6,y-dx+w/6);
	DrawLine(0,w*2.0/3);
	DrawLine(-w/2,-w/3);
	DrawLine(w/2,-w/3);
	SetPenSize(0);
	
	//���ٰ���
	if(button(GenUIID(0), x+2*dx, y-dx, w, h, "")) {
		if(mainstate==Playing) {
			faster();
		}
		sprintf(FooterStr,"Diffculty changed to %s!",DiffcultyStr); //�޸���ʾ�� 
	}
	//���Ƽ���ͼ�� 
	SetPenColor("Black");
	SetPenSize(3);
	MovePen(x+2*dx+w/3,y-dx+w/6);
	DrawLine(0,w*2.0/3);
	DrawLine(+w/2,-w/3);
	DrawLine(-w/2,-w/3);
	MovePen(x+2*dx+w/6,y-dx+w/6);
	DrawLine(0,w*2.0/3);
	DrawLine(+w/2,-w/3);
	DrawLine(-w/2,-w/3);
	SetPenSize(0);
	
	//������һ��ͼ�� 
	SetPenColor("White");
	drawRectangle(x/1.25,y*2.58,w*1.5, w*1.5, TRUE);
	SetPenColor("Black");
	SetPenSize(3);
	drawLabel(x/1.24, y*3, "Next :"); //���� "Next"
	MovePen(x/1.25,y*2.58);
	DrawLine(w*1.5,0);
	DrawLine(0,w*1.5);
	DrawLine(-w*1.5,0);
	DrawLine(0,-w*1.5); 
	
	
	//���Ʒ����� 
	SetPointSize(fH*3);
	char scoretext[10];
	itoa(score*100,scoretext,10);
	drawLabel( x*1.2, y*3, "Score :");
	drawLabel( x*1.2, y*2.7, scoretext);
	
	switch(ms) { //�����ٶ��޸��Ѷ����� 
			case 250:
				strcpy(DiffcultyStr,"INSANE");
				break;
			case 300:
				strcpy(DiffcultyStr,"HARD");
				break;
			case 350:
				strcpy(DiffcultyStr,"NORMAL");
				break;
			case 400:
				strcpy(DiffcultyStr,"EASY");
				break;
		}
	
	//�����Ѷ�
	SetPointSize(fH*3);
	drawLabel( x*1.2, y*2.3,"Diffculty:");
	if(ms==400) SetPenColor("Green");
	if(ms==350) SetPenColor("Cyan");
	if(ms==300) SetPenColor("Orange");
	if(ms==250) SetPenColor("Red");
	drawLabel( x*1.2, y*2.0, DiffcultyStr);
	
	//�����˳���ť
	SetPointSize(fH);
	if( button(GenUIID(0), winwidth/1.2, winheight/10,GetFontHeight()*3,GetFontHeight()*1.5, "�˳�") )   //�˳���ť 
		{
			exit(0);
		}
}
#endif

//���Ƶ���
void DrawFooter() {
	double Font_Height = GetFontHeight();
	double Start_x = Font_Height/3.0; //��������
	double Footer_Height = Font_Height*1.5; //�����߶�
	SetPenSize(1);
	SetPenColor("LightGray");
	drawRectangle(0, 0, winwidth, Footer_Height, TRUE);
	SetPenColor("Black");
	drawLabel(Start_x, Font_Height*0.45, FooterStr);	 
}

	
void display()
{
	// ����
	DisplayClear();
	SetPenColor("Cream");
	drawRectangle(0, 0, winwidth, winheight, TRUE);
	// ���ƺʹ���˵�
	drawMenu();
	//���Ƶ��� 
	DrawFooter();
	// ��ť
    if(mainstate==Welcome) drawButtons();
	// �����ƵĽ��put����Ļ��
	//UpdateDisplay();
	if(mainstate==Playing){
		drawTools();
		finaldraw(); 	
	}
	if(mainstate==showAbout) ShowAbout();
	if(mainstate==showHelp) ShowHelp();
} 
