#include"main.h"

#define TIMER  1     

#define xiangsu 0.2


void prefunction(){
	int i,j;
	for(i=0;i<12;i++){
		for(j=0;j<22;j++){
			if(i==0||i==11||j==0||j==21)block[i][j]=-10;
		}
	}
}

void BlockMove(int direction){
	switch(direction){
		case -1:if(isblock(indexa,indexb,indexx-1,indexy)==1){
			indexx--;
			clean();
			drawblock(indexa,indexb,indexx,indexy);
		}break;
		case 1:if(isblock(indexa,indexb,indexx+1,indexy)==1){
			indexx++;
			clean();
			drawblock(indexa,indexb,indexx,indexy);
		}break; 
		case 0: if(isblock(indexa,indexb,indexx,indexy-1)==1){
			indexy--;
			clean();
			drawblock(indexa,indexb,indexx,indexy);
		}break;
	}
}
int isblock(int a,int b,int x,int y){
	if(block[x][y]<=0)return 0;
	switch(a){
		case 1: if(block[x][y-1]<=0||block[x-1][y]<=0||block[x-1][y-1]<=0)return 0;
				break;
		case 2: switch(b){
			case 0:case 2: if(block[x][y+1]<=0||block[x+1][y]<=0||block[x+1][y-1]<=0)return 0;
				break;
			case 1:case 3: if(block[x][y-1]<=0||block[x-1][y-1]<=0||block[x+1][y]<=0)return 0;
				break;
		}break;
		case 3: switch(b){
			case 0:case 2: if(block[x-1][y]<=0||block[x][y+1]<=0||block[x-1][y-1]<=0)return 0;
				break;
			case 1:case 3: if(block[x-1][y]<=0||block[x][y-1]<=0||block[x+1][y-1]<=0)return 0;
				break;
		}break;
		case 4: switch(b){
			case 0:case 2: if(block[x][y+1]<=0||block[x][y-1]<=0||block[x][y-2]<=0)return 0;
				break;
			case 1:case 3: if(block[x+1][y]<=0||block[x-1][y]<=0||block[x-2][y]<=0)return 0;
				break;
		}break;
		case 5: switch(b){
			case 0: if(block[x-1][y]<=0||block[x+1][y]<=0||block[x+2][y]<=0)return 0;
				break;
			case 1: if(block[x][y-1]<=0||block[x-1][y]<=0||block[x][y-2]<=0)return 0;
				break;
			case 2: if(block[x][y-1]<=0||block[x-1][y-1]<=0||block[x-2][y-1]<=0)return 0;
				break;
			case 3: if(block[x][y+1]<=0||block[x][y-1]<=0||block[x+1][y-1]<=0)return 0;
				break;
		}
		case 6: switch(b){
			case 0: if(block[x+1][y]<=0||block[x-1][y]<=0||block[x-1][y+1]<=0)return 0;
				break;
			case 1: if(block[x][y-1]<=0||block[x][y+1]<=0||block[x+1][y+1]<=0)return 0;
				break;
			case 2: if(block[x-1][y]<=0||block[x+1][y]<=0||block[x+1][y+1]<=0)return 0;
				break;
			case 3: if(block[x][y+1]<=0||block[x][y-1]<=0||block[x-1][y-1]<=0)return 0;
				break;
		}break;
		case 7: switch(b){
			case 0: if(block[x-1][y]<=0||block[x+1][y]<=0||block[x][y+1]<=0)return 0;
				break;
			case 1: if(block[x+1][y]<=0||block[x][y+1]<=0||block[x][y-1]<=0)return 0;
				break;
			case 2: if(block[x][y-1]<=0||block[x+1][y]<=0||block[x-1][y]<=0)return 0;
				break;
			case 3: if(block[x-1][y]<=0||block[x][y+1]<=0||block[x][y-1]<=0)return 0;
				break;
		}break;
	}
	return 1;
}
void clean(){
	int i,j;
	for(i=0;i<12;i++){
		for(j=0;j<22;j++){
			if(block[i][j]>0)block[i][j]=0;
		}
	}
}
void drawblock(int a,int b,int x,int y){//前提是isblock=1
	switch(a){
		case 1: block[x][y-1]=block[x-1][y]=block[x-1][y-1]=block[x][y]=1;
				break;
		case 2: switch(b){
			case 0: block[x][y+1]=block[x+1][y]=block[x+1][y-1]=block[x][y]=2;
				break;
			case 1: block[x][y-1]=block[x-1][y-1]=block[x+1][y]=block[x][y]=2;
				break;
		}break;
		case 3: switch(b){
			case 0: block[x-1][y]=block[x][y+1]=block[x-1][y-1]=block[x][y]=3;
				break;
			case 1: block[x-1][y]=block[x][y-1]=block[x+1][y-1]=block[x][y]=3;
				break;
		}break;
		case 4: switch(b){
			case 0: block[x][y+1]=block[x][y-1]=block[x][y-2]=block[x][y]=4;
				break;
			case 1: block[x+1][y]=block[x-1][y]=block[x-2][y]=block[x][y]=4;
				break;
		}break;
		case 5: switch(b){
			case 0: block[x-1][y]=block[x+1][y]=block[x+2][y]=block[x][y]=5;
				break;
			case 1: block[x][y-1]=block[x-1][y]=block[x][y-2]=block[x][y]=5;
				break;
			case 2: block[x][y-1]=block[x-1][y-1]=block[x-2][y-1]=block[x][y]=5;
				break;
			case 3: block[x][y+1]=block[x][y-1]=block[x+1][y-1]=block[x][y]=5;
				break;
		}break;
		case 6: switch(b){
			case 0: block[x+1][y]=block[x-1][y]=block[x-1][y+1]=block[x][y]=6;
				break;
			case 1: block[x][y-1]=block[x][y+1]=block[x+1][y+1]=block[x][y]=6;
				break;
			case 2: block[x-1][y]=block[x+1][y]=block[x+1][y+1]=block[x][y]=6;
				break;
			case 3: block[x][y+1]=block[x][y-1]=block[x-1][y-1]=block[x][y]=6;
				break;
		}break;
		case 7: switch(b){
			case 0: block[x-1][y]=block[x+1][y]=block[x][y+1]=block[x][y]=7;
				break;
			case 1: block[x+1][y]=block[x][y+1]=block[x][y-1]=block[x][y]=7;
				break;
			case 2: block[x][y-1]=block[x+1][y]=block[x-1][y]=block[x][y]=7;
				break;
			case 3: block[x-1][y]=block[x][y+1]=block[x][y-1]=block[x][y]=7;
				break;
		}break;
	}

}


int BlockInit(){
	srand((int)time(0)); 
	int t;
	t=((int)rand())%7+1;
	return t;
}
void blockicy(){
	int i,j;
	for(i=0;i<11;i++){
		for(j=0;j<21;j++){
			if(block[i][j]>0)block[i][j]=-block[i][j];
		}
	}
}
void blcokdecline(){
int flag=1,i,j,m,n;
for(j=1;j<21;j++){
	flag=1;
	for(i=1;i<11;i++)if(block[i][j]==0)flag=0;
	if(flag==1){
		score++;
		for(m=j;m<21;m++){
			for(n=1;n<11;n++){
				block[n][m]=block[n][m+1];
			}
			}
		}
	}
}
void finaldraw(){
	int i,j;
	for(i=0;i<12;i++){
		for(j=0;j<22;j++){
			switch (block[i][j]){
				case -10:SetPenColor("Black");break;
				case -1:SetPenColor("Blue");break;
				case 1:SetPenColor("Blue");break;
				case -2:SetPenColor("Green");break;
				case 2:SetPenColor("Green");break;
				case -3:SetPenColor("Red");break;
				case 3:SetPenColor("Red");break;
				case -4:SetPenColor("Orange");break;
				case 4:SetPenColor("Orange");break;
				case -5:SetPenColor("Yellow");break;
				case 5:SetPenColor("Yellow");break;
				case -6:SetPenColor("Brown");break;
				case 6:SetPenColor("Brown");break;
				case -7:SetPenColor("Cyan");break;
				case 7:SetPenColor("Cyan");break;
				case 0:SetPenColor("White");break;
				
			}
			drawRectangle(i*xiangsu+1,j*xiangsu+1,xiangsu,xiangsu,1);
		}
	}
	int x=15,y=25;//画旁边的待命方块
	switch(newblock){
	case 1: SetPenColor("Blue");
			drawRectangle(x*xiangsu,y*xiangsu,xiangsu,xiangsu,1);
			drawRectangle(x*xiangsu,(y-1)*xiangsu,xiangsu,xiangsu,1);
			drawRectangle((x-1)*xiangsu,y*xiangsu,xiangsu,xiangsu,1);
			drawRectangle((x-1)*xiangsu,(y-1)*xiangsu,xiangsu,xiangsu,1);
			break;
	case 2: SetPenColor("Yellow");
			drawRectangle(x*xiangsu,(y-1)*xiangsu,xiangsu,xiangsu,1);
			drawRectangle(x*xiangsu,(y-2)*xiangsu,xiangsu,xiangsu,1);
			drawRectangle((x-1)*xiangsu,y*xiangsu,xiangsu,xiangsu,1);
			drawRectangle((x-1)*xiangsu,(y-1)*xiangsu,xiangsu,xiangsu,1);
			break;
				
	case 3: SetPenColor("Red");
			drawRectangle(x*xiangsu,y*xiangsu,xiangsu,xiangsu,1);
						drawRectangle(x*xiangsu,(y-1)*xiangsu,xiangsu,xiangsu,1);
						drawRectangle((x-1)*xiangsu,(y-2)*xiangsu,xiangsu,xiangsu,1);
						drawRectangle((x-1)*xiangsu,(y-1)*xiangsu,xiangsu,xiangsu,1);
						break;
				
	case 4: SetPenColor("Green");
			drawRectangle(x*xiangsu,y*xiangsu,xiangsu,xiangsu,1);
						drawRectangle(x*xiangsu,(y-1)*xiangsu,xiangsu,xiangsu,1);
						drawRectangle(x*xiangsu,(y-2)*xiangsu,xiangsu,xiangsu,1);
						drawRectangle(x*xiangsu,(y+1)*xiangsu,xiangsu,xiangsu,1);
						break;
				
	case 5: SetPenColor("Brown");
			drawRectangle(x*xiangsu,y*xiangsu,xiangsu,xiangsu,1);
						drawRectangle((x-1)*xiangsu,(y-1)*xiangsu,xiangsu,xiangsu,1);
						drawRectangle((x-1)*xiangsu,y*xiangsu,xiangsu,xiangsu,1);
						drawRectangle((x+1)*xiangsu,y*xiangsu,xiangsu,xiangsu,1);
						break;
				
		case 6: SetPenColor("Orange");
			drawRectangle(x*xiangsu,(y-1)*xiangsu,xiangsu,xiangsu,1);
						drawRectangle((x-1)*xiangsu,(y-1)*xiangsu,xiangsu,xiangsu,1);
						drawRectangle((x-1)*xiangsu,y*xiangsu,xiangsu,xiangsu,1);
						drawRectangle((x+1)*xiangsu,(y-1)*xiangsu,xiangsu,xiangsu,1);
						break;
				
		case 7: SetPenColor("Cyan");
				drawRectangle(x*xiangsu,y*xiangsu,xiangsu,xiangsu,1);
						drawRectangle((x-1)*xiangsu,(y-1)*xiangsu,xiangsu,xiangsu,1);
						drawRectangle((x)*xiangsu,(y-1)*xiangsu,xiangsu,xiangsu,1);
						drawRectangle((x+1)*xiangsu,(y-1)*xiangsu,xiangsu,xiangsu,1);
						break;
							
		}
}

void MAINGAME(){
	score=0;
	isgame=1;
	prefunction();
	indexx=6;
	indexy=19;
	newblock=BlockInit();
	drawblock(BlockInit(),0,indexx,indexy);
	display();
	registerKeyboardEvent(KeyboardEventProcess1);/*×￠2á?ü?ì???￠??μ÷oˉêy*/
	registerTimerEvent(TimerEventProcess);/*×￠2á?¨ê±?÷???￠??μ÷oˉêy*/
	ms=500;//最初速度
	startTimer(TIMER, ms);/*500ms?¨ê±?÷′￥·￠*/
    
} 

void KeyboardEventProcess1(int key, int event)
{
	int tmp;
	tmp=ms;
	uiGetKeyboard(key,event); // GUI??è??ü?ì
		switch (event) {
	 	case KEY_DOWN:
			 switch (key) {
			     case VK_SPACE:
			 		if(isblock(indexa,(indexb+1)%4,indexx,indexy)==1){
			 			clean();
			 			indexb=(indexb+1)%4;
			 			drawblock(indexa,indexb,indexx,indexy);
			 			display();
			 		}
                     break;
			     case VK_DOWN:
					 ms=200;
                     break;
			     case VK_LEFT:
			         if(isblock(indexa,indexb,indexx-1,indexy)==1){
			         	clean();
			         	indexx--;
			         	drawblock(indexa,indexb,indexx,indexy);
			         	display();
			         }
                     break;
			     case VK_RIGHT:
			         if(isblock(indexa,indexb,indexx+1,indexy)==1){
			         	clean();
			         	indexx++;
			         	drawblock(indexa,indexb,indexx,indexy);
			         	display();
			         }
                     break;
                 default:break;
			 }
			 break;
		case KEY_UP:
			 ms=tmp;
			 break;
	 }	 
}

void TimerEventProcess(int timerID)
{
    if(isgame==1){
    if(score%10==0&&ms>=300)ms=ms-50;
	switch(timerID){
    	case TIMER:
    	if(isblock(indexa,indexb,indexx,indexy-1)==1){
    		indexy=indexy-1;
    		clean();
    		drawblock(indexa,indexb,indexx,indexy);
    		display();
    	}
    	else{
    		blockicy();
    		blockdecline();
    		indexa=newblock;
    		indexb=0;
    		newblock=BlockInit();
    		score++;
    		indexx=6;
    		indexy=19;
    		if(isblock(indexa,indexb,indexx,indexy)==1){
    			drawblock(indexa,indexb,indexx,indexy);
    			display();
    		}
    		else{//开启游戏结束流程
    			cancelTimer(TIMER);
				isgame=0;
    		}
    	}

    } 
}
	  
}
void pause(){
	if(isgame==1)isgame=2;
}
void carryon(){
	if(isgame==2)isgame=1;
}





