#include"main.h"
int ifgame=0;
// �û����������
// ����ʼ��ִ��һ��
void Main() 
{
	// ��ʼ�����ں�ͼ��ϵͳ
	SetWindowTitle("Tetris");
	//SetWindowSize(10, 10); // ��λ - Ӣ��
	//SetWindowSize(15, 10);
	//SetWindowSize(10, 20);  // �����Ļ�ߴ粻�����򰴱�����С
    InitGraphics();

	// ��ô��ڳߴ�
    winwidth = GetWindowWidth();
    winheight = GetWindowHeight();

	// ע��ʱ����Ӧ����
	registerCharEvent(CharEventProcess); // �ַ�
	registerKeyboardEvent(KeyboardEventProcess);// ����
	registerMouseEvent(MouseEventProcess);      // ���
            

	// �򿪿���̨���������������Ϣ�����ڵ���
	// InitConsole(); 

}

#if defined(DEMO_MENU)
// �˵���ʾ����
void drawMenu()
{ 
	static char * menuListFile[] = {"File",  
		"Start | Ctrl-O", 
		"Show ranking | Ctrl-R",
		"Save | Ctrl-S",
		"Exit | Ctrl-E"};
	static char * menuListTool[] = {"Tool",
		"Pause | Ctrl-P",
		"Speed-up | Ctrl->",
		"Speed-down | Ctrl-<"};
	static char * menuListHelp[] = {"Help",
		"Help | Ctrl-H",
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
//	if( selection==1 ) Start_game();  //��ʼ��Ϸ 
//	if( selection==2 ) ShowRanking(); //��ʾ���а� 
//	if( selection==3 ) Save_game();     //������Ϸ 
	if( selection==4 ) exit(-1); // choose to exit
	
	// Tool �˵�
//	menuListTool[1] =(g_gamestate!=Playing)? "Start  | Ctrl-P":"Pause  | Ctrl-P";
	selection = menuList(GenUIID(0),x+w,  y-h, w, wlist,h, menuListTool,sizeof(menuListTool)/sizeof(menuListTool[0]));
	if( selection>0 ) selectedLabel = menuListTool[selection];
	if( selection==1 ){ if(ifgame==1)  Pause_game();  //��ͣ��Ϸ 
						else if(ifgame==2)   Resume_game();//�ָ���Ϸ 
						else if(ifgame==0)   Start_game();//��ʼ��Ϸ 
						} 
	if( selection==2 )  
	if( selection==3 )  
	
	// Help �˵�
	selection = menuList(GenUIID(0),x+2*w,y-h, w, wlist, h, menuListHelp,sizeof(menuListHelp)/sizeof(menuListHelp[0]));
	if( selection>0 ) selectedLabel = menuListHelp[selection];
//	if( selection==1 ) ShowHelp();    //��ʾ������������ 
//	if( selection==2 ) ShowAbout();   //���� 
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
			ranking_list();
		}
		
	if( button(GenUIID(0), x, y-9*h, w*2, h*2, "�˳�") )  //�˳���Ϸ 
		{	
			exit(-1);
		}
}
#endif

void display()
{
	// ����
	DisplayClear();
	// ���ƺʹ���˵�
	drawMenu();
	// ��ť
	drawButtons();
	// �����ƵĽ��put����Ļ��
	//UpdateDisplay();
} 
