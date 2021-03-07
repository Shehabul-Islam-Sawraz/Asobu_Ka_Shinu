# include "iGraphics.h"

double recx[1001];
double recy[1001];
double reclen[1001];
double recwidth[1001];
int type[1001];
double polyx[6]={900,910,975,985,1050,1060};
double polyy[6]={250,240,725,715,1200,1190};
double ballx=130,bally=110,ballr=40,v;
int i,cp=1,ballfly=0,flagfly;
char stand[1][30]={"project image\\stand.bmp"};

void ballfall()
{
    v=v+0.015;
}

void ballposition()
{
    for(int i=0; i<8; i++){
        if(ballx>=recx[i] && ballx<recx[i]+reclen[i]-ballr){
            ballfly=0;
            if(flagfly==0){
                cp=i;
            }
            v=0.05;
            printf("%d\n",cp);
            break;
        }
    }
    if(bally>recy[cp]+recwidth[cp]+2){
        ballfly=1;
        if(ballx+ballr<100){
            bally=bally-v;
        }
        else{
            bally=bally-v;
            for(i=0;i<8;i++){
                recy[i]=recy[i]+v;
            }
        }
    }
}

void iDraw()
{
    ballposition();
    iClear();
    iSetColor(255,0,0);
    for(int i=0;i<8;i++){
        iFilledRectangle(recx[i],recy[i],reclen[i],recwidth[i]);
    }
    iSetColor(0,0,255);
    //iFilledCircle(ballx,bally,ballr,100);
    iShowBMP2(ballx,bally,stand[0],255);
    //iPolygon(polyx,polyy,4);
}

void iMouseMove(int mx, int my)
{
    //place your codes here
}

void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {

    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {

    }
}

void iKeyboard(unsigned char key)
{
    if(key == 'q')
    {
        exit(0);
    }
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
    if(key == GLUT_KEY_RIGHT)
    {
        if(ballfly==1){
            ballfly=2;
        }
        if(ballfly==2 && ballx>=recx[cp-1] && ballx<recx[cp+1]){
            cp=cp+1;
            flagfly=1;
            ballx=ballx+2;
        }
        else if(ballfly==2){
            if(recwidth[cp+1]<0){
                if(ballx+ballr+5>recx[cp+1] && bally<=recy[cp+1]){
                    return;
                }
            }
            else{
                if(ballx+ballr+5>recx[cp+1] && bally<=recy[cp+1]+recwidth[cp+1]){
                    return;
                }
            }
            flagfly=0;
        }
        else if(ballx+5>recx[cp+1]-ballr && ballfly==0 && recwidth[cp+1]>0){
            flagfly=0;
            return;
        }
        if(ballfly==2){
            for(int i=0;i<8;i++){
                recx[i]=recx[i]-2;
            }
            ballx=ballx+2;
        flagfly=0;
        }
        else{
            for(int i=0;i<8;i++){
                recx[i]=recx[i]-5;
            }
            ballx=ballx+5;
            flagfly=0;
        }
    }
    if(key == GLUT_KEY_LEFT)
    {
        if(ballfly==1){
            ballfly=2;
        }
        //if(ballfly==2 && )
        if(ballfly==2){
            if(recwidth[cp-1]<0){
                if(ballx-5<recx[cp-1]+reclen[cp-1] && bally<=recy[cp-1]){
                    return;
                }
            }
            else{
                if(ballx-5<recx[cp-1]+reclen[cp-1] && bally<=recy[cp-1]+recwidth[cp-1]){
                    return;
                }
            }
        }
        if(ballx-5<recx[cp-1]+reclen[cp-1] && ballfly==0){
           return;
        }
        if(ballfly==2){
            for(i=0;i<8;i++){
                recx[i]=recx[i]+2;
            }
            ballx=ballx-2;
        }
        else{
            for(i=0;i<8;i++){
                recx[i]=recx[i]+5;
            }
            ballx=ballx-5;
        }
    }
    if(key == GLUT_KEY_UP)
    {
        for(i=0;i<8;i++){
            recy[i]=recy[i]-5;
        }
       // for(i=0;i<4;i++){
         //   polyy[i]=polyy[i]-5;
        //}
        bally=bally+5;
    }
    if(key == GLUT_KEY_DOWN)
    {
        if(bally-5<recy[cp]+recwidth[cp]+1){
            return;
        }
        for(i=0;i<8;i++){
            recy[i]=recy[i]+5;
        }
        //for(i=0;i<4;i++){
          //  polyy[i]=polyy[i]+5;
        //}
        bally=bally-5;
    }
    if(key == GLUT_KEY_END)
    {
        exit(0);
    }
}


int main()
{
    recx[0]=100;
    recy[0]=100;
    reclen[0]=10;
    recwidth[0]=300;
    type[0]=1;
    recx[1]=110;
    recy[1]=100;
    reclen[1]=390;
    recwidth[1]=10;
    type[1]=0;
    recx[2]=490;
    recy[2]=110;
    reclen[2]=10;
    recwidth[2]=490;
    type[2]=1;
    /*recx[3]=380;
    recy[3]=250;
    reclen[3]=10;
    recwidth[3]=900;
    type[3]=1;*/
    recx[3]=500;
    recy[3]=585;
    reclen[3]=310;
    recwidth[3]=15;
    type[3]=0;
    recx[4]=800;
    recy[4]=585;
    reclen[4]=10;
    recwidth[4]=-500;
    type[4]=1;
    recx[5]=810;
    recy[5]=85;
    reclen[5]=450;
    recwidth[5]=10;
    type[5]=0;
    recx[6]=1245;
    recy[6]=95;
    reclen[6]=15;
    recwidth[6]=150;
    type[6]=1;
    /*recx[8]=1150;
    recy[8]=200;
    reclen[8]=10;
    recwidth[8]=500;
    type[8]=1;*/
    recx[7]=1260;
    recy[7]=235;;
    reclen[7]=250;
    recwidth[7]=10;
    type[7]=0;
    iSetTimer(100,ballfall);
    iInitialize(1366,620,"GAMES!");
    return 0;
}
