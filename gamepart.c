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

#define TIMER_BLINK500  1     /*500ms��ʱ���¼���־��*/
#define TIMER_BLINK1000 2     /*1000ms��ʱ��ʱ���־��*/


void KeyboardEventProcess(int key, int event);
void TimerEventProcess(int timerID);/*��ʱ����Ϣ�ص�����*/

void MAINGAME(){
	registerKeyboardEvent(KeyboardEventProcess);/*ע�������Ϣ�ص�����*/
	registerTimerEvent(TimerEventProcess);/*ע�ᶨʱ����Ϣ�ص�����*/
	startTimer(TIMER_BLINK500, mseconds500);/*500ms��ʱ������*/
    startTimer(TIMER_BLINK1000, mseconds1000);/*1000ms��ʱ������*/
} 

void KeyboardEventProcess(int key, int event)
{
	uiGetKeyboard(key,event); // GUI��ȡ����
		switch (event) {
	 	case KEY_DOWN:
			 switch (key) {
			     case VK_SPACE:/*��ת*/

                     break;
			     case VK_DOWN:

                     break;
			     case VK_LEFT:
			         SetEraseMode(TRUE);
                     DrawCenteredCircle(ccx, ccy, radius);
					 ccx -= deltax;
					 SetEraseMode(FALSE);
                     DrawCenteredCircle(ccx, ccy, radius);
                     break;
			     case VK_RIGHT:
			         SetEraseMode(TRUE);
                     DrawCenteredCircle(ccx, ccy, radius);
					 ccx += deltax;
					 SetEraseMode(FALSE);
                     DrawCenteredCircle(ccx, ccy, radius);
                     break;
			     case VK_P://��ͣ// 
  					 SetEraseMode(TRUE);
                     DrawCenteredCircle(ccx, ccy, radius);
		 	         SetPenSize(GetPenSize()+1);
					 SetEraseMode(FALSE);
                     DrawCenteredCircle(ccx, ccy, radius);
					 break;

                     break;
			 }
			 break;
		case KEY_UP:
			 break;
	 }	 
	display(); // ˢ����ʾ
}

void TimerEventProcess(int timerID)
{
      bool erasemode;

	  switch (timerID) {
	    case TIMER_BLINK500: /*500ms�����˸��ʱ��*/
	      erasemode = GetEraseMode();
		  SetEraseMode(isDisplayCircle);
          DrawCenteredCircle(ccx, ccy, radius);
	      SetEraseMode(erasemode);
		  isDisplayCircle = !isDisplayCircle;
		  break;
	    case TIMER_BLINK1000: /*1000ms�����˸��ʱ��*/
	      erasemode = GetEraseMode();
		  SetEraseMode(isDisplayCircle2);
          DrawCenteredCircle(ccx, ccy, radius*2);
	      SetEraseMode(erasemode);
		  isDisplayCircle2 = !isDisplayCircle2;
		  break;
	    default:
		  break;
	  }
}

void display()
{
	// ����
	DisplayClear();

#if defined(DEMO_MENU)
	// ���ƺʹ���˵�
	drawMenu();
#endif

#if defined(DEMO_ROTATE)
	// ��ת��������
	drawRotateTriangle();
#endif
			
#if defined(DEMO_BUTTON)
	// ��ť
	drawButtons();
#endif

#if defined(DEMO_EDITBOX)
	// �༭�ı��ַ���
	drawEditText();
#endif
}
