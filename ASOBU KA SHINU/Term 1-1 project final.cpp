#include "iGraphics.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <windowsx.h>
#include <math.h>
#define linenum 30
#define obsnum 20
#define dangernum 16
#define cannonnum 1
#define rectangle 18
#define numrightobstacles 7
#define numdownobstacles 4
#define screenlength 1000
#define screenwidth 650
#define pointnum -1
#define minenumber 4
double lvlend[3]={1690,2460};
int leaderlevel, linestart[5]={0,12},lineend[5]={11,27},obsstart[5]={0,8},obsend[5]={8,16},danstart[5]={0,7},danend[5]={7,16};
double pox=0, poy=0, ballx=30, bally=360, ballr=10, falling, chartimer, speedtimer, speedtimer2, speed=0,recx[30],recy[30];
double reclen[30],recwidth[30],type[30],firex,firey,v,ballx1=0,bally1=150,ballr1=40,pox1=0,area,x,y,u,ux=0,px;
double dant[dangernum], danx[dangernum], dany[dangernum], danl[dangernum], danb[dangernum],danorigin[dangernum],dantravel[dangernum],dangerdx[dangernum],dangerdy[dangernum];
double _line_x[linenum], _line_y[linenum], _line_l[linenum], _line_b[linenum],_line_origin[linenum],_line_travel[linenum];
int _line_t[linenum], time_elapsed=0, score, lifebonus, levelscore, timebonus, scoredekhabo=1, leaderboardnum;
char leaderboardscores[10][10];
double obsx[obsnum], obsy[obsnum], obsl[obsnum], obsb[obsnum];
int obst[obsnum], dancon[dangernum], deathtimer=-1;
int posrank = 1, highscore = 0, prevlevel, menu=1, sound=1, ft=1, life=3, uacon=0, ballposition, charcon=0, level=-4, playerlevel;
int intronum=1, introtimer=0, jump=0, namelen=0,ldx=2,ldy=2,completed=0;
int deadcondition = 0, i,cp,p,ballfly,frontindex=0,knockout=0,index=0,backindex=7,hangindex=0,standcounter=0,run=0,extralife=1,flag=0,leveldekhao=0,expnum;
int firecounter=0,downflag=0,downfall=0,downintersect=0,checkpoint=1,checkpointshow=0,checkpointshow1=0,checkindex=0;
char bmpnum = '1', charpos[2]="r", bmpname[10][30]= {"Games//final1.bmp", "Games//final2.bmp", "Games//final3.bmp", "Games//final4.bmp", "Games//l21.bmp","Games//l22.bmp","Games//l23.bmp","Games//l24.bmp","Games//l25.bmp","Games//l26.bmp",}, filename[30]="Games//final1.bmp";
char charbmpname[200], playername[20], leaderboardname[10][30];
char intro[100] = "Games//intro//1//intro (1).bmp";
bool fire=false;
bool mainmenu=false;
bool main_menu=true;
bool level_12=false;
bool level_3=false;
bool pause=false;
char brick[25][50]={"project image\\b 0.bmp","project image\\b 1.bmp","project image\\b 2(1).bmp","project image\\b 3.bmp",
                "project image\\b 4.bmp","project image\\b 5.bmp","project image\\b 6(1).bmp","project image\\b 7.bmp",
                "project image\\b 8.bmp","project image\\b 9(1).bmp","project image\\b 10.bmp","project image\\b 11.bmp",
                "project image\\b 12.bmp","project image\\b 13.bmp","project image\\b 12.bmp","project image\\b 4.bmp",
                "project image\\b 12.bmp","project image\\b 14.bmp","project image\\b 2(2).bmp","project image\\b 6(2).bmp",};
char stand[1][40]={"project image\\stand.bmp"};
char frontrun[8][40]={"project image\\running 1.bmp","project image\\running 2.bmp","project image\\running 3.bmp","project image\\running 4.bmp",
                      "project image\\running 5.bmp","project image\\running 6.bmp","project image\\running 7.bmp","project image\\running 8.bmp"};
char backrun[8][40]={"project image\\running 9.bmp","project image\\running 10.bmp","project image\\running 11.bmp","project image\\running 12.bmp",
                     "project image\\running 13.bmp","project image\\running 14.bmp","project image\\running 15.bmp","project image\\running 16.bmp"};
char jump1[8][40]={"project image\\jump 1.bmp","project image\\jump 2.bmp","project image\\jump 3.bmp","project image\\jump 4.bmp",
                  "project image\\jump 5.bmp","project image\\jump 6.bmp","project image\\jump 7.bmp","project image\\jump 8.bmp"};

char background [1][40]={"project image\\background.bmp"};
char rightobstacles[7][40]={"project image\\obstacle 1.bmp","project image\\obstacle 3.bmp","project image\\obstacle 5.bmp","project image\\obstacle 6.bmp",
                            "project image\\obstacle 7.bmp","project image\\obstacle 8.bmp","project image\\obstacle 9.bmp"};
char downobstacles[4][40]={"project image\\obstacle 4.bmp","project image\\obstacle 11.bmp","project image\\obstacle 12.bmp",
                           "project image\\obstacle 13.bmp"};
char minepic[4][40]={"project image\\minecraft 2.bmp","project image\\minecraft 1.bmp","project image\\bullet.bmp","project image\\bullet.bmp"};
char knock[35][60]={"project image\\ko1.bmp","project image\\ko1.bmp","project image\\ko1.bmp",
                    "project image\\ko1.bmp","project image\\ko1.bmp","project image\\ko1.bmp",
                    "project image\\ko1.bmp","project image\\ko3.bmp","project image\\ko3.bmp","project image\\ko3.bmp",
                    "project image\\ko3.bmp","project image\\ko3.bmp","project image\\ko3.bmp","project image\\ko3.bmp",
                    "project image\\ko4.bmp","project image\\ko4.bmp","project image\\ko4.bmp","project image\\ko4.bmp",
                    "project image\\ko4.bmp","project image\\ko4.bmp","project image\\ko4.bmp","project image\\ko4.bmp",
                    "project image\\ko4.bmp","project image\\ko4.bmp","project image\\ko4.bmp","project image\\ko4.bmp",
                    "project image\\ko4.bmp","project image\\ko4.bmp","project image\\ko4.bmp","project image\\ko4.bmp"};
int explosion,expframenum;
char expframe[34][100]={
    "Games\\exp\\exp01.bmp","Games\\exp\\exp02.bmp","Games\\exp\\exp03.bmp","Games\\exp\\exp04.bmp","Games\\exp\\exp05.bmp","Games\\exp\\exp06.bmp","Games\\exp\\exp07.bmp","Games\\exp\\exp08.bmp","Games\\exp\\exp09.bmp","Games\\exp\\exp10.bmp",
    "Games\\exp\\exp11.bmp","Games\\exp\\exp12.bmp","Games\\exp\\exp13.bmp","Games\\exp\\exp14.bmp","Games\\exp\\exp15.bmp","Games\\exp\\exp16.bmp","Games\\exp\\exp17.bmp","Games\\exp\\exp18.bmp","Games\\exp\\exp19.bmp","Games\\exp\\exp20.bmp",
    "Games\\exp\\exp21.bmp","Games\\exp\\exp22.bmp","Games\\exp\\exp23.bmp","Games\\exp\\exp24.bmp","Games\\exp\\exp25.bmp","Games\\exp\\exp26.bmp","Games\\exp\\exp27.bmp","Games\\exp\\exp28.bmp","Games\\exp\\exp29.bmp","Games\\exp\\exp30.bmp",
    "Games\\exp\\exp31.bmp","Games\\exp\\exp32.bmp","Games\\exp\\exp33.bmp","Games\\exp\\exp34.bmp"
};
void soundplay(){
    if(sound<0){
        PlaySound(0,0,0);
        return;
    }
    if(main_menu){
        PlaySound("Musix\\main menu.wav",NULL,SND_LOOP | SND_ASYNC);
    }
    else if(pause){
        PlaySound("Musix\\pause.wav",NULL,SND_LOOP | SND_ASYNC);
    }
    else if(level_12){
        PlaySound("Musix\\level12.wav",NULL,SND_LOOP | SND_ASYNC);
    }
//    else if(level_12 && explosion){
//        PlaySound("Musix\\explosion.wav",NULL, SND_ASYNC);
//    }
    else if(level_3&& fire==false){
        PlaySound("Musix\\level3.wav",NULL,SND_LOOP | SND_ASYNC);
    }
    else if(level_3&& fire==true){
        PlaySound("Musix\\explosion.wav",NULL, SND_ASYNC);
    }
}
void introbmpname(){
    if(intronum > 58){iPauseTimer(0); level = -3; return;}
    strcpy(intro, "Games//intro//");
    char c=intronum/10+1 + '0';
    intro[14] = c;
    strcat(intro, "//intro (");
    c=intronum%10 + '0';
    intro[24] = c;
    strcat(intro, ").bmp");
    intro[30]='\0';
    intronum++;
    if(intronum%10==0)
        intronum++;
    introtimer++;
}
struct obstacless{
    double birdx,birdy,speed;
    int birdindex;
    bool birdshow;
};
  obstacless enemy[numrightobstacles];
  obstacless enemy1[numdownobstacles];
struct minecrafts{
    double minex,mnx,miney,minelen,minespeed;
    int mineindex;
};
  minecrafts mine[minenumber];
void danger(int i, double x, double y, double l, double b, int type=1, int condition=0,double travel=0){
    if(condition==-1&&type==4)
        danx[i]=x+travel-5;
    else
        danx[i]=x;
    if(condition==-1&&type==3)
        dany[i]=y+395;
    else
        dany[i]=y;
    danl[i]=l;
    danb[i]=b;
    dant[i]=type;
    dancon[i]=condition;
    if(type==3) danorigin[i]=y;
    else if(type==4) danorigin[i]=x;
    dantravel[i]=travel;
}
void dangercheck(double cx, double cy){
    if(deadcondition == 1) return;
    if(level==1 || level==2){//added
        for(int i=danstart[level-1]; i<danend[level-1]; i++){
        if(cx+ballr+20 > danx[i] && cx < (danx[i] + danl[i]) && cy + 70 > dany[i] && cy < (dany[i] + danb[i])){
            if(dant[i] !=101){
                if(dant[i]==1){
                    explosion=1;
                    expnum=i;
                    level_12=true;
                    //soundplay();
                    if(sound>0) PlaySound("Musix\\explosion.wav",NULL, SND_ASYNC);
                }
                if(deathtimer>0) return;
                life--;
                if(deadcondition == 0){
                    deathtimer = 100;
                    deadcondition = 1;
                }
                else{
                    iClear();
                    iSetColor(255, 0, 0);
                    iRectangle(350, 350, 300, 50);
                    iText(400, 360, "GAME OVER!");
                }
            }
            else {
                if(life<3 && dancon[i]==1){
                    life++;
                    dancon[i]=0;
                    return;
                }
            }
        }
    }
    }//added
}
void line(int i, double x, double y, double len, int type=1, int travel=0, double thickness=5, int drawline=0){
    _line_t[i]=type;
    if(type==3)
        _line_x[i] = x+10;
    else
        _line_x[i] = x;
    _line_y[i] = y;
    if(type==1||type==3){
        _line_l[i] = len;
        _line_b[i] = thickness;

    }
    if(type==2||type==4){
        _line_l[i] = thickness;
        _line_b[i] = len;
    }
    if(type==3){
        _line_origin[i]=_line_x[i];
        _line_travel[i]=travel;
    }
    if(type==4){
        _line_origin[i]=_line_y[i];
        _line_travel[i]=travel;
    }
    if(drawline>-1){
        iSetColor(255, 0, 0);
        //iFilledRectangle(_line_x[i]+pox, _line_y[i]+poy, _line_l[i], _line_b[i]);
    }
}
void restart(){
    recx[0]=0; recy[0]=140; reclen[0]=400; recwidth[0]=10; type[0]=0;
    recx[1]=400; recy[1]=140; reclen[1]=10; recwidth[1]=120; type[1]=1;
    recx[2]=410; recy[2]=250; reclen[2]=300; recwidth[2]=10; type[2]=0;
    recx[3]=710; recy[3]=100; reclen[3]=10; recwidth[3]=160; type[3]=2;
    recx[4]=720; recy[4]=100; reclen[4]=250; recwidth[4]=10; type[4]=0;
    recx[5]=970; recy[5]=100; reclen[5]=10; recwidth[5]=110; type[5]=1;
    recx[6]=980; recy[6]=200; reclen[6]=150; recwidth[6]=10; type[6]=0;
    recx[7]=1230; recy[7]=200; reclen[7]=150; recwidth[7]=10; type[7]=0;
    recx[8]=1380; recy[8]=120; reclen[8]=10; recwidth[8]=90; type[8]=2;
    recx[9]=1390; recy[9]=120; reclen[9]=150; recwidth[9]=10; type[9]=0;
    recx[10]=1650; recy[10]=120; reclen[10]=150; recwidth[10]=10; type[10]=0;
    recx[11]=1800; recy[11]=120; reclen[11]=10; recwidth[11]=120; type[11]=1;
    recx[12]=1810; recy[12]=230; reclen[12]=200; recwidth[12]=10; type[12]=0;
    recx[13]=2010; recy[13]=0; reclen[13]=10; recwidth[13]=240; type[13]=2;
    recx[14]=2170; recy[14]=230; reclen[14]=200; recwidth[14]=10; type[14]=0;
    recx[15]=2480; recy[15]=230; reclen[15]=250; recwidth[15]=10; type[15]=0;
    recx[16]=2840; recy[16]=230; reclen[16]=200; recwidth[16]=10; type[16]=0;
    recx[17]=3040; recy[17]=0; reclen[17]=10; recwidth[17]=240; type[17]=2;
    //the next 3 rectangle are related to pox
    recx[18]=450; recy[18]=250; reclen[18]=260; recwidth[18]=10;
    recx[19]=1000; recy[19]=200; reclen[19]=130; recwidth[19]=10;
    recx[20]=1400; recy[20]=120; reclen[20]=140; recwidth[20]=10;
    recx[21]=1130;recy[21]=0;reclen[21]=100;recwidth[21]=1;
    recx[22]=1540;recy[22]=0;reclen[22]=110;recwidth[22]=1;
    ux=0;
    if(checkpoint==1){
        ballx1=0; bally1=160; pox1=0;
    }
    else if(checkpoint==2){
        ballx1=1085; bally1=220; pox1=-1000;
    }
    iShowBMP2(ballx1+pox1,bally1,stand[0],255);
    leveldekhao=0;
}
int areaintersect(double l1x,double r1x,double l1y,double r1y,double l2x,double l2y,double r2x,double r2y){
    if(level==3){
        double a,b;
        a=min(r1x,r2x)-max(l1x,l2x);
        b=min(r1y,r2y)-max(l1y,l2y);
        if(a<=0 || b<=0){
            return 0;
        }
        else{
            return 1;
        }
    }
}
void enemymovement(){
    if(level==3){
        for(int i=0;i<numrightobstacles;i++){
            if(enemy[i].birdshow){
                iShowBMP2(enemy[i].birdx+pox1,enemy[i].birdy,rightobstacles[enemy[i].birdindex],255);
            }
        }
    }
}
void enemymovement1(){
    if(level==3){
        for(int i=0;i<numdownobstacles;i++){
            if(enemy1[i].birdshow){
                iShowBMP2(enemy1[i].birdx+pox1,enemy1[i].birdy,downobstacles[enemy1[i].birdindex],255);
            }
        }
    }
}
void minemovement(){
    if(level==3){
        for(i=0;i<minenumber;i++){
            iShowBMP2(mine[i].mnx+pox1,mine[i].miney,minepic[mine[i].mineindex],255);
        }
        iShowBMP2(mine[4].minex+pox1,mine[4].miney,minepic[mine[4].mineindex],0xffffff);
    }
}
void ko(){
    if(level==3){
        if(knockout==1){
        index++;
        if(index>=1 && index <=9)  {  ballx1-=6;  bally1+=5;  }
        if(index>=10 && index<=13) {  ballx1-=5;  bally1-=3;  }
        if(index>=14 && index<=23) {  ballx1-=4;  bally1-=3;  }
        if(index>=24 && index<=29) { ballx1-=2; }
        if(index>29)  {  index=0;  knockout=0;  restart(); soundplay(); }
        p=0;
    }
    else if(knockout==2){
        index++;
        if(index>=1 && index <=9)  {  ballx1+=6;  bally1+=5;  }
        if(index>=10 && index<=13) {  ballx1+=5;  bally1-=3;  }
        if(index>=14 && index<=23) {  ballx1+=4;  bally1-=3;  }
        if(index>=24 && index<=29) { ballx1+=2; }
        if(index>29)  {  index=0;  knockout=0;  restart(); soundplay(); }
        p=0;
    }
  }
}
void checkshow(){
    if(level==3){
        if(checkpointshow==1 && checkpointshow1==1 && level==3){
            iShowBMP2(50,250,"project image\\CHECKPOINT3.bmp",255);
        }
    }
}
void leaderboard2(char newname[20], int newscore, int playerlevel){
    leaderboardnum=0;
	char filename[40] = "FILES//leaderboard1.txt";
	filename[18] = '0' + playerlevel;
    char ara[12][20];
    int score[12];
    FILE* fp=fopen(filename, "r");
    int i;
    printf("Level %d Prev File:\n", playerlevel);
    for(i=0; i<10; i++){
        fscanf(fp, "%s %d", ara[i], &score[i]);
        if(feof(fp)) break;
        printf("%s %d\n", ara[i], score[i]);
        //if(feof(fp)) break;
    }
    fclose(fp);
    int flag=0;
    for(int j=0; j<i; j++){
        if(!strcmp(ara[j], newname)){
            score[j] = newscore;
            flag=1;
            break;
        }
    }
    if(!flag){
        strcpy(ara[i], newname);
        score[i]=newscore;
        i++;
    }
    for(int j=0; j<i; j++){
        for(int k=j; k<i; k++){
            if(score[j] < score[k]){
                int tmp=score[j];
                score[j] = score[k];
                score[k] = tmp;
                char temp[20];
                strcpy(temp, ara[j]);
                strcpy(ara[j], ara[k]);
                strcpy(ara[k], temp);
            }
        }
    }
    fp=fopen(filename, "w");
    for(int j=0; j<i; j++) fprintf(fp, "%s %d\n", ara[j], score[j]);
    fclose(fp);
    printf("\n\n");
    printf("*****LEADERBOARD*****\n");
	for (int j = 0; j < i; j++) {
        leaderboardnum++;
        if(j<10){
            strcpy(leaderboardname[j], ara[j]);
            sprintf(leaderboardscores[j], "%07d", score[j]);
        }
		printf("%d.%20s\t%d", j + 1, ara[j], score[j]);
        if (!strcmp(newname, ara[j])) {
            posrank = j+1;
			printf(" <--%s", playername);
		}
		printf("\n");
	}
	if(posrank == 1) highscore = 1;
	else highscore = 0;
	printf("\n\tYou ranked: %d\n", posrank);
    printf("\n\n");
}
void highscore_leaderboard(){
    freopen("FILES//Gamehistory.txt", "a", stdout);
    printf("\n\n------------------------------\n");
    printf("Player name: %s Level: %d\n", playername, playerlevel);
    score=0;
    timebonus=(max(0, (500-time_elapsed))) * 30;
    if(playerlevel == 1) timebonus=(max(0, (650-time_elapsed))) * 100;
    if(playerlevel == 2) timebonus=(max(0, (1050-time_elapsed))) * 100;
    if(playerlevel == 3) timebonus=(max(0, (7000-time_elapsed))) * 100;
    lifebonus=life * 500;
    levelscore = playerlevel * 10000;
    score = levelscore + lifebonus + timebonus;
    {   printf("Time Elapsed: %d\n", time_elapsed);
        printf("\nTimebonus: %d\nLifebonus: %d\nLevelscore: %d\n\tScore: %d\n", timebonus, lifebonus, levelscore, score);
    }
    leaderboard2(playername, score, playerlevel);
}
void iLevelCompleted(){
        if(leveldekhao==1){
            iShowBMP(0, 0, "project image\\Levelcompleted2.bmp");
            for(i=0;i<numrightobstacles;i++){
                enemy[i].birdshow=false;
            }
            for(i=0;i<numdownobstacles;i++){
                enemy1[i].birdshow=false;
            }
        }
        else{
            iShowBMP(0, 0, "Games//Menu//Levelcompleted.bmp");
        }
    if(life == 1)
        iShowBMP2(273, 336, "Games//Menu//star1.bmp", 0xffffff);
    if(life == 2)
        iShowBMP2(273, 336, "Games//Menu//star2.bmp", 0xffffff);
    if(life == 3)
        iShowBMP2(273, 336, "Games//Menu//star3.bmp", 0xffffff);
    if(highscore)
        iShowBMP2(612, 212, "Games//Menu//highscore.bmp", 0xffffff);
    {
        char printscore[15];
        sprintf(printscore, "Score: %06d", score);
        iSetColor(255, 255, 255);
        iText(435, 242, printscore, GLUT_BITMAP_TIMES_ROMAN_24);
        iShowBMP2(260, 190, "Games//leaderboard-icon-9.bmp", 0xffffff);
    }
}
void ball_position(){
    ballposition=20;
    if(level==1 || level==2){
        for(int i=linestart[level-1]; i<lineend[level-1]; i++){
        if(ballx>=_line_x[i] && ballx<=_line_x[i]+_line_l[i]  && bally>_line_y[i])
            ballposition=i;
        }
        if(bally> _line_y[ballposition]+ 5 && uacon    == 0)
            falling+=.025;
        else
            falling =0;
    }
}
void b_allposition(){
    if(ballx1>1080 && ballx1<1120){
        checkpoint=2;
        checkpointshow=1;
        checkpointshow1=1;
        checkindex++;
        if(checkindex>100){
            checkpointshow1=2;
        }
    }
    else{
        checkpointshow=0;
    }
    if(p==1 && knockout==0){
        if(ballx1-5<0){
            if(run==4){
                run=1;
            }
            else if(run==5){
                run=2;
            }
            p=0; ux=0; px=0;
        }
        if((ballx1>1130 && ballx1+ballr1<1230)||(ballx1>1540 && ballx1+ballr1<1650)||(ballx1>2010 && ballx1+ballr1<2170)||(ballx1>2370 && ballx1+ballr1<2480)||(ballx1>2730 && ballx1+ballr1 <2840)){
            cp=21; v=4; downfall=0;
            if((ballx1>1130 && ballx1+ballr1<1230 && bally1<=212)||(ballx1>1540 && ballx1+ballr1<1650 && bally1<=132)||(ballx1>2010 && ballx1+ballr1<2170 && bally1<=250)||(ballx1>2370 && ballx1+ballr1<2480 && bally1<=250)||(ballx1>2730 && ballx1+ballr1 <2840 && bally1 <=250)){
                cp=21; downfall=1; p=0; ux=0; px=0;
            }
        }
        if(ballx1+ballr1+5>=recx[cp+1] && bally1 <=recy[cp+1]+recwidth[cp+1] && p==1){
            if(run==4)  {  run=1;  }
            else if(run==5)  {  run=2;  }
            p=0; ux=0; px=0;
        }
        else{
            ballx1+=ux;
        }
            px-=1;
            if(p==1){
                bally1=bally1+px;
            }
            if(bally1<=recy[cp]+recwidth[cp]+5 && p==1){
                p=0; px=0; ux=0;
            }
    }
    if(areaintersect(ballx1,ballx1+40,bally1,bally1+60,1240,220,1240+25,220+24) && extralife==1){
        if(life<3){
            life++;
        }
        extralife=0;
    }
    if(areaintersect(ballx1,ballx1+40,bally1,bally1+60,3000,250,3000+50,250+31)){
        level=11; leveldekhao=1; completed=1; highscore_leaderboard();
    }
    if(ballx1+ballr1>3000){
        level=11; leveldekhao=1; completed=1; highscore_leaderboard();
    }
    if((ballx1>1130 && ballx1+ballr1<1230)||(ballx1>1540 && ballx1+ballr1<1650)||(ballx1>2010 && ballx1+ballr1<2170)||(ballx1>2370 && ballx1+ballr1<2480)||(ballx1>2730 && ballx1+ballr1 <2840)){
        cp=21; v=4; ballfly=0; downfall=0;
        if((ballx1>1130 && ballx1+ballr1<1230 && bally1<=212)||(ballx1>1540 && ballx1+ballr1<1650 && bally1<=132)||(ballx1>2010 && ballx1+ballr1<2170 && bally1<=250)||(ballx1>2370 && ballx1+ballr1<2480 && bally1<=250)||(ballx1>2730 && ballx1+ballr1 <2840 && bally1 <=250)){
            cp=21; downfall=1;
        }
    }
    else if(ballx1+ballr1>=1650 && ballx1+ballr1<1800){
        cp=10; v=4; ballfly=0; downfall=0;
    }
    else{
        for(i=0;i<=rectangle;i++){
            if(ballx1>=recx[i] && ballx1+ballr1<=recx[i]+reclen[i]){
                cp=i; v=4; ballfly=0; downfall=0;
                break;
            }
            else if((ballx1<=recx[i] && ballx1+ballr1 <=recx[i]+reclen[i])||(ballx1>=recx[i] && ballx1<=recx[i]+reclen[i] && ballx1+ballr1>recx[i]+reclen[i])||(ballx1<=recx[i] && ballx1+ballr1>=recx[i]+reclen[i])){
                cp=i+1;  v=4; ballfly=0; downfall=0;
                break;
            }
        }
    }
    if(downfall){
        if(bally1<=0){
            life--;
            if(life==0){
                checkpoint=1; extralife=1; level=-1;
            }
            restart();
        }
    }
    if(((GetAsyncKeyState(VK_UP) & 0x8000)==0)|| downfall==1){
        if(bally1>recy[cp]+recwidth[cp]+2 && p==0){
            ballfly=1;
            bally1=bally1-v;
        }
    }
}
void obstacle(int i, double x, double y, double l, double b, int type=1){
    obsx[i]=x;
    obsy[i]=y;
    obsl[i]=l;
    obsb[i]=b;
    obst[i]=type;
    iSetColor(255, 255, 0);
    if(type==1){}
}
int obstacle_check(double cx, double cy){
    if(level==1 || level==2){
        for(int i=obsstart[level-1]; i<obsend[level-1]; i++){
            if(cx+ballr+20 > obsx[i] && cx < (obsx[i] + obsl[i]) && cy + 70 > obsy[i] && cy < (obsy[i] + obsb[i])){
                return 0;
            }
        }
        return 1;
    }
}
void f1(){
    ///line(line_num, line_x, line_y, line_len, line_type, line_thickness);
    ///(by default) type = 1 horizontal line
    ///type = 2 vertical line
    ///by default lines thickness is set to 5
    _line_y[20]=-345;
    line(0, 0, 0+350, 400);
    line(1, 395, 0+350, -100, 2);
    line(2, 395, -100+350, 300);
    line(3, 690, -100+350, 60, 2);
    line(4, 685, -40+350, 150);
    line(5, 925, -40+350, 250);
    line(6, 1175, -40+350, -150, 2);
    line(7, 1175, -190+350, 300);
    line(8, 1470, -190+350, 150, 2);
    line(9, 1470, -40+350, 200);
    line(10, 1665, 20+350, 1000, 2);
    line(11, 200, 200+350, 50);
    line(12,0,100,150);
    line(13,150,100,100,2);
    line(14,150,200,300);
    line(15,450,205,-110,2);
    line(16,450,100,250);
    line(17,700,100,150,2);
    line(18,700,250,300);
    line(19,1000,260,-250,2);
    line(20,1000,10,500);
    line(21,1500,10,400,2);
    line(22,1500,410,300);
    line(23,1800,420,-200,2);
    line(24,1800,220,350);
    line(25,2150,220,100,2);
    line(25,2150,320,300);
    line(26,1020,220,100,3,400);
    ///obstacles
    obstacle(0, 0, 0, 400, 352, 2);
    obstacle(1, 400, 0, 325, 250, 2);
    obstacle(2, 690, 0, 140, 310, 2);
    obstacle(3, 930, 0, 250, 310, 2);
    obstacle(4, 1175, 0, 310, 162, 2);
    obstacle(5, 1470, 0, 205, 315, 2);
    obstacle(6, 0, 0, 30, 2000, 2);
    obstacle(7, 0, 1000, 1600, 1000);
    obstacle(8, -1000, 0, 1025, 1000, 2);
    obstacle(9,0,0,1000,100,2);
    obstacle(10,150,100,300,100,2);
    obstacle(11,700,0,300,250,2);
    obstacle(12,1500,0,1650,220,2);
    obstacle(13,1500,220,300,190,2);
    obstacle(14,2131,224,200,100, 2);
    obstacle(15, 0, 0, 30, 2000, 2);
    ///dangers
    danger(0, 350, 350, 40, 50);
    danger(1, 1050, 325, 40, 50);
    danger(2, 1620, 320, 30, 30, 3, 0); ///moving danger vertical
    danger(3, 871, 425, 25, 25, 101, 1); ///life++
    danger(4,395, 252, 30, 30, 4, 0, 275); ///moving danger
    danger(5, 1175, 162, 30, 30, 4, 0, 300); ///moving danger
    danger(6, 0, 0, 2000, 40, 0); ///hole
    danger(7, 450, 105, 30, 30, 4, 0, 230);///moving danger
    danger(8 ,1000, 15, 30, 30, 4, 0,480);///moving danger
    danger(9, 1800, 225, 30, 30, 4, 0, 300);///moving danger
    danger(10,1000, 15, 30, 30, 4, -1,480);///moving danger
    danger(11, 1200, 320, 25, 25, 101, 1);///life++
    danger(12, 826, 254, 30, 30);///stationary danger
    danger(13, 1734, 412, 30, 30, 3, 0);///moving danger vertical
    danger(14 ,2228, 324, 30, 30, 3, 0);///moving danger vertical
    danger(15, 2437, 324, 30, 30, 3, -1);///moving danger vertical
    for(int i=0;i<dangernum;i++){
        dangerdx[i]=2;
        dangerdy[i]=3;
    }
}
void timer(){
    if(deathtimer >= 0){
        deathtimer--;
        bally++;
        if(charbmpname[16] == 'r')ballx-=1.2;
        if(charbmpname[16] == 'l')ballx+=1.2;
    }
    else if(deadcondition == 1){
        ballx=35; bally=360; deadcondition = 0;
    }
    if((level == 1 || level == 2 || level == 3) && (!completed)) time_elapsed++;
    if(level==1 || level==2){
        for(int i=danstart[level-1];i<danend[level-1];i++){
        if(dant[i]==3){
            dany[i]+=dangerdy[i];
            if(dany[i]-danorigin[i]>=400||dany[i]<danorigin[i]) dangerdy[i]*=-1;
        }
        else if(dancon[i] == -1 || dant[i] == 4){
            danx[i]+=dangerdx[i];
            if(danx[i]-danorigin[i]>=dantravel[i]||danx[i]<danorigin[i]) dangerdx[i]*=-1;
        }
    }
    for(int i=linestart[level-1];i<lineend[level-1];i++){
        if(_line_t[i]==3){
            _line_x[i]+=ldx;
            if(_line_x[i]-_line_origin[i]>=_line_travel[i]||_line_x[i]<=_line_origin[i]) ldx*=-1;
            if(_line_t[ballposition]==3&&!jump) ballx+=ldx;
        }
        else if(obst[i]==4){
            _line_y[i]+=ldy;
            if(_line_t[ballposition]==4) bally+=ldy;
            if(_line_y[i]-_line_origin[i]>=_line_travel[i]||_line_y[i]<=_line_origin[i]) ldy*=-1;
        }
    }
    if(obstacle_check(ballx, bally-falling))
    bally-=falling;
    speedtimer-=100;
    speedtimer2-=100;
    speed=3+max(max(0, 7*speedtimer/1000), max(0, 7*speedtimer2/1000));
    }
    ///gravity
    if(uacon==1 && speedtimer>0)
        uacon=2;
    if(uacon==2)
        if(obstacle_check(ballx+ux, bally))
            ballx+=ux;
    u-=1.25;
    double hobe=bally+u;
    if(hobe > _line_y[ballposition] && obstacle_check(ballx, hobe)){
        bally=hobe;
    }
    else{
        jump=0;
        uacon=0;
        ux=3;
    }
}
void charcondition(){
    if(deadcondition == 1) {
        charcon = -1;
        if(deathtimer > 80){ bmpnum = '1'; return ;}
        if(deathtimer > 60){ bmpnum = '2'; return ;}
        if(deathtimer > 40){ bmpnum = '3'; return ;}
        if(deathtimer > 20){ bmpnum = '4'; return ;}
        if(deathtimer > 0){ bmpnum = '5'; return ;}
    }
    if(uacon == 0 && speedtimer2<0 && speedtimer<0){
        if(charcon==0){
            bmpnum++;
            if(bmpnum=='5')
                bmpnum='1';
            return;
        }
        charcon=0;
        bmpnum='1';
        chartimer=1500;
    }
    else if(uacon == 0 && (speedtimer2>0 || speedtimer>0)){
        if(charcon==1){
            if(speed > 7){
                bmpnum++;
                if(bmpnum=='7')
                    bmpnum='1';
            }
            return;
        }
        charcon=1;
        bmpnum='1';
        chartimer=1500;
    }
    else if(uacon==0 && speedtimer>0){
        if(charcon==2){
            if(speed > 7){
                bmpnum++;
                if(bmpnum=='7')
                    bmpnum='1';
            }
            return;
        }
        charcon=2;
        bmpnum='1';
        chartimer=1500;
    }
    else if(uacon !=0 && u>0){
        if(charcon==3){
            return;
        }
        charcon=3;
        bmpnum='3';
        chartimer=1500;
    }
    else if(uacon != 0 && u<0){
        if(charcon==4){
            return;
        }
        charcon=4;
        bmpnum='4';
        chartimer=1500;
    }
}
void charname(){
    strcpy(charbmpname, "Games//char//1//");
    strcat(charbmpname, charpos);
    if(charcon == -1){strcat(charbmpname, "d//");}
    if(charcon==0) strcat(charbmpname, "s//");
    if(charcon==1 || charcon==2) strcat(charbmpname, "r//");
    if(charcon==3 || charcon==4) strcat(charbmpname, "j//");
    else strcat(charbmpname, "s//");
    charbmpname[20]=bmpnum;
    charbmpname[21]='.';
    charbmpname[22]='b';
    charbmpname[23]='m';
    charbmpname[24]='p';
    charbmpname[25]='\0';
}
void upanimation(){
    if(deadcondition == 1) return;
    uacon=1;
    double x = max(0, u) + 15;
    if(x<33)
        u=x;
}
void poxpoy(){
    if(ballx>=0 && ballx<500){
        pox=0;
        if(level==1)strcpy(filename, bmpname[0]);
        if(level==2)strcpy(filename, bmpname[4]);
    }
    if(ballx>=500 && ballx<750){
        pox=-350;
        if(level==1)strcpy(filename, bmpname[1]);
        if(level==2)strcpy(filename, bmpname[5]);
    }
    if(ballx>=750 && ballx<1250){
        pox=-500;
        if(level==1)strcpy(filename, bmpname[2]);
        if(level==2)strcpy(filename, bmpname[6]);
    }
    if(ballx>=1250&&ballx<=1500){
        pox=-1000;
        if(level==1)strcpy(filename, bmpname[3]);
        if(level==2)strcpy(filename, bmpname[7]);
    }
    if(ballx>=1500&&ballx<=2200&&level==2){
        pox=-1500;
        if(level==2)strcpy(filename, bmpname[8]);
    }
    if(ballx>=2200){
        pox=-2000;
        if(level==2)strcpy(filename, bmpname[9]);
    }
}
void newgame(){
    if(deadcondition == 1){ deadcondition = 0; deathtimer = -1;}
    time_elapsed = 0;
    f1();
    iSpecialKeyboard(GLUT_KEY_UP);
    ballx=35;
    bally=360;
}
void leaderboard(){
    if(!strcmp(playername, "level1")) return;
    if(!strcmp(playername, "level2")) return;
    if(!strcmp(playername, "level3")) return;
    FILE* fp1 = fopen("FILES//profile.txt", "r");
	FILE* fp2 = fopen("FILES//temp.txt", "w");
	int found=0;
	while (1) {
		char tmpname[40];
		int tmplevel;
		fscanf(fp1, "%s %d", tmpname, &tmplevel);
		if (feof(fp1)) break;
		if (!strcmp(tmpname, playername)) {
			found = 1;
			fprintf(fp2, "%s %d\n", playername, playerlevel);
		}
		else fprintf(fp2, "%s %d\n", tmpname, tmplevel);
	}
	if (!found) fprintf(fp2, "%s %d\n", playername, playerlevel);
	fclose(fp1);
	fclose(fp2);
	fp1 = fopen("FILES//profile.txt", "w");
	fp2 = fopen("FILES//temp.txt", "r");
	while (1) {
		int c;
		c=fgetc(fp2);
		if (feof(fp2)) break;
		fputc(c, fp1);
	}
	fclose(fp1);
	fclose(fp2);
}
void iLife(){
    if(life>0){
        iSetColor(0, 255, 0);
        iRectangle(850, 650, 99, 20);
        if(life==3)
            iSetColor(0, 255, 0);
        if(life==2)
            iSetColor(255, 255, 0);
        if(life==1)
            iSetColor(255, 0, 0);
        iFilledRectangle(850, 652, 33*life, 16);
    }
    if(life<1){
        prevlevel=level;
        newgame();
        level = -1;
        return;
    }
    if(ballx>lvlend[level-1]){
        completed=1;
        highscore_leaderboard();
    }
}
void iLevel(){
    if(level==1 || level==2){
        ball_position();
        poxpoy();
        charname();
        iLife();
        dangercheck(ballx, bally);
        iShowBMP(0, 0, "Games//BG1.bmp");
        if(level==2)
        for(int i=linestart[level-1];i<lineend[level-1];i++){
            if(_line_t[i]==3){
                    iShowBMP2(pox+_line_x[i]-12,poy+_line_y[i]-30, "Games//carpet2.bmp", 0xffffff);
            }
        }
        iSetColor(0, 255, 0);
        iRectangle(850, 650, 99, 20);
        if(life==3)iSetColor(0, 255, 0);
        if(life==2)iSetColor(255, 255, 0);
        if(life==1)iSetColor(255, 0, 0);
        iFilledRectangle(850, 652, 33*life, 16);
        for(int i=danstart[level-1]; i<danend[level-1]; i++){
            if(dant[i]==1&&!explosion&&deathtimer)iShowBMP2(pox+danx[i], poy+dany[i], "Games//grenade.bmp", 0xffffff);
            if(dant[i]==3||dant[i]==4)iShowBMP2(pox+danx[i], poy+dany[i], "Games//bullet.bmp", 0xffffff);
            if(dant[i]==101 && dancon[i])iShowBMP2(pox+danx[i], poy+dany[i], "Games//life.bmp", 0xffffff);}
        for(int i=obsstart[level-1]; i<obsend[level-1]; i++){
            if(obst[i] == 1)iShowBMP(pox+obsx[i], obsy[i], "Games//box.bmp");
            else if(obst[i]==3) iFilledRectangle(pox+obsx[i],poy+obsy[i],100,5);
        }
            iShowBMP2(0, 0, filename, 0xffffff);
        iShowBMP2(ballx+pox-28, bally+poy-ballr/2, charbmpname, 0xffffff);
        if(explosion==1){
            if(expframenum==34){
                explosion=0;
                expframenum=0;
                soundplay();
            }
            iShowBMP2(danx[expnum]+pox,dany[expnum]+poy-13,expframe[expframenum],0x00000);
            expframenum++;
        }
    }
    //iSetColor(0,255,0);
    if(level==4){
     iSetColor(45,54,87);

     iFilledRectangle(0, 0, 1000, 700);
     iSetColor(255, 0, 0);
     iText(300,350,"Congratulations! You have completed all levels! Thank you!");
     }
    iShowBMP2(0, 650, "Games//Menu//Menubar.bmp", 0xffffff);
    if(deathtimer > 0) {
        iShowBMP2(400, 300, "Games//dead.bmp", 0x000000);
    }
}
void iMenu(){
    iShowBMP(0, 0, "Games//Menu//Menu.bmp");
    iShowBMP2(412, 170, "Games//Menu//play1.bmp", 0xffffff);
    if(!ft)iShowBMP2(455, 170, "Games//Menu//newgame.bmp", 0xffffff);
    else iShowBMP2(455, 170, "Games//Menu//howto.bmp", 0xffffff);
    iShowBMP2(495, 170, "Games//Menu//info.bmp", 0xffffff);
    if(sound>0)iShowBMP2(533, 170, "Games//Menu//sound1.bmp", 0xffffff);
    else iShowBMP2(533, 170, "Games//Menu//sound0.bmp", 0xffffff);
    iShowBMP2(571, 170, "Games//Menu//quit.bmp", 0xffffff);
    if(mainmenu){
        iSetColor(0,255,0);
        iText(450,140,"MAIN MENU",GLUT_BITMAP_HELVETICA_18);
    }
}
void iFailed(){
    iShowBMP(0, 0, "Games//BG1.bmp");
    iShowBMP2(300, 0, "Games//Menu//failed.bmp", 0xffffff);
}
void profile_check(){
    FILE *fp = fopen("FILES//profile.txt", "r+");
    int found=0, file_level;
    char name[20];
    while(1){
        fscanf(fp, "%s %d", name, &file_level);
        if(!strcmp(name, playername)){
            playerlevel=file_level;
            found=1;
        }
        if(feof(fp)) break;
    }
    if(!found){
        fprintf(fp, "%s %d\n", playername, 1);
        playerlevel=1;
        fclose(fp);
    }
}
void createplayername(unsigned char key){
    if(key==8){
        if(!namelen) return;
        namelen--;
        playername[namelen]='\0';
        return;
    }
    playername[namelen] = key;
    namelen++;
    playername[namelen] = '\0';
}
void iProfile(){
    if(!namelen)iShowBMP(0, 0, "Games//profile//back2.bmp");
    else{
        iShowBMP(0, 0, "Games//profile//back.bmp");
        iText(400, 183, playername, GLUT_BITMAP_TIMES_ROMAN_24);
    }
}
void smooth(){
    if(level == 3 ) return;
    if(deadcondition == 1) return;
    if(GetAsyncKeyState(VK_UP) & 0x8000){
        iSpecialKeyboard(GLUT_KEY_UP);
    }
    if(GetAsyncKeyState(VK_DOWN) & 0x8000){
        iSpecialKeyboard(GLUT_KEY_DOWN);
    }
    if(GetAsyncKeyState(VK_RIGHT) & 0x8000){
        iSpecialKeyboard(GLUT_KEY_RIGHT);
    }
    if(GetAsyncKeyState(VK_LEFT) & 0x8000){
        iSpecialKeyboard(GLUT_KEY_LEFT);
    }
    if(GetAsyncKeyState(87) & 0x8000){
        iSpecialKeyboard(GLUT_KEY_UP);
    }
    if(GetAsyncKeyState(83) & 0x8000){
        iSpecialKeyboard(GLUT_KEY_DOWN);
    }
    if(GetAsyncKeyState(68) & 0x8000){
        iSpecialKeyboard(GLUT_KEY_RIGHT);
    }
    if(GetAsyncKeyState(65) & 0x8000){
        iSpecialKeyboard(GLUT_KEY_LEFT);
    }
}
void smooth1(){
    if(level != 3) return;
    if(deadcondition == 1) return;
    if(GetAsyncKeyState(VK_UP) & 0x8000){
        iSpecialKeyboard(GLUT_KEY_UP);
    }
    if(GetAsyncKeyState(VK_DOWN) & 0x8000){
        iSpecialKeyboard(GLUT_KEY_DOWN);
    }
    if(GetAsyncKeyState(VK_RIGHT) & 0x8000){
        iSpecialKeyboard(GLUT_KEY_RIGHT);
    }
    if(GetAsyncKeyState(VK_LEFT) & 0x8000){
        iSpecialKeyboard(GLUT_KEY_LEFT);
    }
    if(GetAsyncKeyState(87) & 0x8000){
        iSpecialKeyboard(GLUT_KEY_UP);
    }
    if(GetAsyncKeyState(83) & 0x8000){
        iSpecialKeyboard(GLUT_KEY_DOWN);
    }
    if(GetAsyncKeyState(68) & 0x8000){
        iSpecialKeyboard(GLUT_KEY_RIGHT);
    }
    if(GetAsyncKeyState(65) & 0x8000){
        iSpecialKeyboard(GLUT_KEY_LEFT);
    }
}
void iLeaderBoard(){
    iClear();
    iShowBMP(0, 0, "Games//score.bmp");
    char scorenum[10];
    sprintf(scorenum, "%07d", levelscore);
    iText(162, 480, scorenum, GLUT_BITMAP_TIMES_ROMAN_24);
    sprintf(scorenum, "%07d", timebonus);
    iText(162, 400, scorenum, GLUT_BITMAP_TIMES_ROMAN_24);
    sprintf(scorenum, "%07d", lifebonus);
    iText(162, 323, scorenum, GLUT_BITMAP_TIMES_ROMAN_24);
    sprintf(scorenum, "%07d", score);
    iText(162, 203, scorenum, GLUT_BITMAP_TIMES_ROMAN_24);
    iText(548, 440, leaderboardname[0], GLUT_BITMAP_TIMES_ROMAN_24);
    iText(775, 383+67, leaderboardscores[0], GLUT_BITMAP_TIMES_ROMAN_24);
    if(leaderboardnum > 5) leaderboardnum = 5;
    for(int i=2; i<=leaderboardnum; i++){
        char bmpfile[] = "Games//2.bmp";
        bmpfile[7] = '0'+i;
        iShowBMP2(453, 415-(i-1)*67, bmpfile, 0xffffff);
        if(!strcmp(playername, leaderboardname[i-1])) iSetColor(255, 0, 0);
        else iSetColor(255, 255, 0);
        iText(548, 383-(i-2)*67, leaderboardname[i-1], GLUT_BITMAP_TIMES_ROMAN_24);
        iText(775, 383-(i-2)*67, leaderboardscores[i-1], GLUT_BITMAP_TIMES_ROMAN_24);
    }
}
void iDraw(){
    if(level == -101701){
        iLeaderBoard();
        return;
    }
    if(level==3){
        b_allposition();
    }
    iClear();
    if(!completed){
    if(level==-5){
        iShowBMP(0, 0, "Games//howto.bmp");
        iShowBMP2(0, 650, "Games//Menu//Menubar.bmp", 0xffffff);
    }
    if(level==-6){
        iShowBMP(0, 0, "Games//credits.bmp");
        iShowBMP2(0, 650, "Games//Menu//Menubar.bmp", 0xffffff);
    }
    if(level==-4) iShowBMP(0, 0, intro);
    if(level==-3 || level==-2) iProfile();
    if(level==-1) iFailed();
    if(level==0) iMenu();
    if(level==1 || level==2 || level==4) iLevel();
    }
    else{
        iLevelCompleted();
    }
    if(level==3){
        iShowBMP(0,0,"project image\\7.bmp");
        iShowBMP2(0, 650, "Games//Menu//Menubar.bmp", 0xffffff);
    for(i=0;i<rectangle;i++){
        iShowBMP(recx[i]+pox1,recy[i],brick[i]);
        //iRectangle(recx[i],recy[i],reclen[i],recwidth[i]);
    }
    iRectangle(recx[21]+pox1,recy[21],reclen[21],recwidth[21]);
    iRectangle(recx[22]+pox1,recy[22],reclen[22],recwidth[22]);
    iShowBMP(recx[18]+pox1,recy[18],brick[18]);
    iShowBMP(recx[19]+pox1,recy[19],brick[19]);
    iShowBMP(recx[20]+pox1,recy[20],"project image\\b 91.bmp");
    iShowBMP(0+pox1,0,"project image\\brickbg1.bmp");
    iShowBMP(410+pox1,0,"project image\\brickbg2.bmp");
    iShowBMP(460+pox1,0,"project image\\brickbg3.bmp");
    iShowBMP(410+pox1,140,"project image\\brickbg4.bmp");
    iShowBMP(460+pox1,140,"project image\\brickbg5.bmp");
    iShowBMP(710+pox1,0,"project image\\brickbg6.bmp");
    iShowBMP(980+pox1,0,"project image\\brickbg7.bmp");
    iShowBMP(1000+pox1,0,"project image\\brickbg8.bmp");
    iShowBMP(980+pox1,100,"project image\\brickbg9.bmp");
    iShowBMP(1000+pox1,100,"project image\\brickbg10.bmp");
    iShowBMP(1230+pox1,0,"project image\\brickbg11.bmp");
    iShowBMP(1230+pox1,140,"project image\\brickbg12.bmp");
    iShowBMP(1380+pox1,0,"project image\\brickbg13.bmp");
    iShowBMP(1400+pox1,0,"project image\\brickbg14.bmp");
    iShowBMP(1650+pox1,0,"project image\\brickbg15.bmp");
    iShowBMP(1810+pox1,0,"project image\\brickbg16.bmp");
    iShowBMP(1810+pox1,140,"project image\\brickbg17.bmp");
    iShowBMP(1850+pox1,0,"project image\\brickbg18.bmp");
    iShowBMP(1850+pox1,140,"project image\\brickbg19.bmp");
    iShowBMP(2170+pox1,0,"project image\\brickbg16.bmp");
    iShowBMP(2170+pox1,140,"project image\\brickbg17.bmp");
    iShowBMP(2840+pox1,0,"project image\\brickbg16.bmp");
    iShowBMP(2840+pox1,140,"project image\\brickbg17.bmp");
    iShowBMP(2480+pox1,0,"project image\\brickbg20.bmp");
    iShowBMP(2480+pox1,140,"project image\\brickbg21.bmp");
    iShowBMP(3000+pox1,250,"project image\\endpicture.bmp");
    if(knockout){
        iShowBMP2(ballx1+pox1,bally1,knock[index],255);
    }
    if(extralife){
        iShowBMP2(1240+pox1,220,"project image\\extralife.bmp",255);
    }
    enemymovement();   enemymovement1();  minemovement();
    iSetColor(0,0,255);
    iText(810,662,"Life: ",GLUT_BITMAP_HELVETICA_18);
    if(life==3){
        iShowBMP2(850,650,"project image\\charlife 1.bmp",0);
        iShowBMP2(900,650,"project image\\charlife 1.bmp",0);
        iShowBMP2(950,650,"project image\\charlife 1.bmp",0);
    }
    else if(life==2){
        iShowBMP2(850,650,"project image\\charlife 1.bmp",0);
        iShowBMP2(900,650,"project image\\charlife 1.bmp",0);
    }
    else if(life==1){
        iShowBMP2(850,650,"project image\\charlife 1.bmp",0);
    }
    if(downfall){
        bally1=bally1-4;
    }
    if(fire){
        if(expframenum==34){
            fire=false; level_3=true; expframenum=0;
        }
        iShowBMP2(x+pox1,y,expframe[expframenum],0);
        expframenum++;
        iShowBMP2(x+60+pox1,y+60,"project image\\dead.bmp",255);
    }
    if(run==0 && knockout==0){
        iShowBMP2(ballx1+pox1,bally1,stand[0],255);
    }
    else if(run==1 && knockout==0){
        iShowBMP2(ballx1+pox1,bally1,frontrun[frontindex],255);
        standcounter++;
        if(standcounter>=20){
            standcounter=0; run=0; frontindex=0;
        }
        downflag=0;
    }
    else if(run==2 && knockout==0){
        iShowBMP2(ballx1+pox1,bally1,backrun[backindex],255);
        standcounter++;
        if(standcounter>=20){
            standcounter=0; run=0;
            backindex=7;
        }
        downflag=0;
    }
    else if(run==3 && knockout==0){
        iShowBMP2(ballx1+pox1,bally1,jump1[1],255);
    }
    else if(run==4 && knockout==0){
        iShowBMP2(ballx1+pox1,bally1,jump1[3],255);
    }
    else if(run==5 && knockout==0){
        iShowBMP2(ballx1+pox1,bally1,"project image\\bjump.bmp",255);
    }
    else if(run==6 && knockout==0){
        iShowBMP2(ballx1+pox1,bally1,"project image\\down.bmp",255);
    }
    if(run!=0 && run>2 && knockout==0){
        standcounter++;
        if(standcounter>=20){
            standcounter=0; run=0;
        }
        downflag=0;
    }
    checkshow();
    }
}
void iMouseMove(int mx, int my) {}
void iMouse(int button, int state, int mx, int my){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        if(mainmenu){
            level=0;
            ft=0;
            if(mx>=440 && mx<=560 && my>=140 && my<=175){
                checkpoint=1;
                restart();  newgame();
                completed=0; level=-2; life=3; ft=1;
                mainmenu=false;
                main_menu=true; pause=false; level_12=false; level_3=false;
                soundplay();
            }
        }
        if(!completed){
        if(level==0){
            if(mx>=412 && mx<=452){
                level=playerlevel;
                //if(playerlevel != 3) iPauseTimer()
                scoredekhabo=1;
                if(level==1 || level==2){
                main_menu=false; pause=false; level_12=true; level_3=false;
                soundplay();
                }
                if(level==3){
                main_menu=false; pause=false; level_12=false; level_3=true;
                soundplay();
                }
                iSpecialKeyboard(GLUT_KEY_UP);
                ft=0;
                mainmenu=false;
            }
            if(mx>=455 && mx<= 495){
                if(!ft){
                    level=playerlevel;
                    scoredekhabo=1;
                    life=3;
                    if(level==1 || level==2){
                        main_menu=false; pause=false; level_12=true; level_3=false;
                        soundplay();
                        newgame();
                    }
                    else if(level==3){
                        checkpoint=1;
                        main_menu=false; pause=false; level_12=false; level_3=true;
                        soundplay();
                        restart();
                    }
                }
                else{
                    level=-5;
                }
                mainmenu=false;
            }
            if(mx>495 && mx<= 535){
                level=-6;
            }
            if(mx>=571 && mx<=611){
                printf("Thank You %s\n", playername);
                exit(0);
            }
            if(mx>=533 && mx<=573){
                sound*=-1;
                if(sound==-1){
                    PlaySound(0,0,0);
                }
                else if(sound==1){
                    if(ft==0){
                        main_menu=false; pause=true; level_12=false; level_3=false;
                        soundplay();
                    }
                    else{
                        main_menu=true; pause=false; level_12=false; level_3=false;
                        soundplay();
                    }
                }
            }

        }
    }
    else{
            if(level == -101701){
                level=leaderlevel;
                return;
            }
            if(my >=190 && my <= 270 && mx>= 260 && mx<=340){
                leaderlevel = level;
                level = -101701;
                return;
            }
            if(mx>=273 && mx<=273+127){
                checkpoint=1;
                completed=0;
                level=0;
                life=3;
                ft=1;
                main_menu=true; pause=false; level_12=false; level_3=false;
                soundplay();
            }
            if(mx>=440 && mx<=440+127){
                completed=0;
                level=playerlevel;
                scoredekhabo=1; life=3;
                if(level==1 || level==2){
                    main_menu=false; pause=false; level_12=true; level_3=false;
                    soundplay();
                    newgame();
                }
                else if(level==3){
                    checkpoint=1;
                    main_menu=false; pause=false; level_12=false; level_3=true;
                    soundplay();
                    restart();
                }
            }
            if(mx>=600 && mx<=727){
                completed=0;
                level=++playerlevel;
                scoredekhabo=1;
                time_elapsed=0;
                //level=1;
                leaderboard();
                life=3;
                if(level==1 || level==2){
                    main_menu=false; pause=false; level_12=true; level_3=false;
                    soundplay();
                    newgame();
                }
                else if(level==3){
                    checkpoint=1;
                    main_menu=false; pause=false; level_12=false; level_3=true;
                    soundplay();
                    restart();
                }
            }
            mainmenu=false;
        }
        if(level>0 || level==-5 || level==-6){
            if(level>0){
                if(level==1 || level==2){
                    main_menu=false; pause=false; level_12=true; level_3=false;
                    soundplay();
                }
                if(level==3){
                    main_menu=false; pause=false; level_12=false; level_3=true;
                    soundplay();
                }
            }
            if(mx>=0 && mx<= 50&& my>=650 &&my<=700){
                mainmenu=true;
                if(level>0){
                    main_menu=false; pause=true; level_12=false; level_3=false;
                    soundplay();
                }
                level=0;
            }
        }
        else if(level == -1){
            if(mx>=360 && mx <= 360 + 110){
                checkpoint=1;
                restart();
                newgame();
                level=0; life=3; ft=1;
                main_menu=true; pause=false; level_12=false; level_3=false;
                soundplay();
            }
            else if(mx>=543 && mx <= 543 + 110){
                level=playerlevel;
                scoredekhabo=1; life=3;
                if(level==1 || level==2){
                    main_menu=false; pause=false; level_12=true; level_3=false;
                    soundplay();
                    newgame();
                }
                else if(level==3){
                    checkpoint=1;
                    main_menu=false; pause=false; level_12=false; level_3=true; fire=false;
                    soundplay();
                    restart();
                }
            }
            mainmenu=false;
        }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {}
    //printf("%d %d\n",mx,my);
}
}
void iKeyboard(unsigned char key){
    if(deadcondition == 1) return;
    if(level == -101701){
        level = leaderlevel;
        return;
    }
    ///notun ashche///
    if(key=='A') iSpecialKeyboard(GLUT_KEY_LEFT);
    if(key=='S') iSpecialKeyboard(GLUT_KEY_DOWN);
    if(key=='D') iSpecialKeyboard(GLUT_KEY_RIGHT);
    if(key == 'W') iSpecialKeyboard(GLUT_KEY_UP);
    if(level==0 && key==13){
            level=playerlevel;
            scoredekhabo=1;
            if(level==1 || level==2){
                main_menu=false; pause=false; level_12=true; level_3=false;
                soundplay();
            }
            if(level==3){
                main_menu=false; pause=false; level_12=false; level_3=true;
                soundplay();
            }
            iSpecialKeyboard(GLUT_KEY_UP);
    }
    if(level == 0 && key == 27){
        printf("Thank You %s\n", playername);
        exit(0);
    }
    if(level!=0){
        if(key == 27){
            level=0;
            mainmenu=true;
            main_menu=false; pause=true; level_12=false; level_3=false;
            soundplay();
        }
    }
    if(level == -3 || level == -2){
        //printf("%d\n", key);
        if(level == -3 && key == 13) return;
        if(level==-2 && key==13){
            level = 0;
            profile_check();
            return;
        }
        createplayername(key);
        level=-2;
    }
    if(level==3){
         if(key=='b'){
            if(p==0){
                p=1; ux=-25; px=20; run=5;
            }
            else if(p==1){
                return;
            }
        }
        if(key=='f' || key=='F'){
            if(p==0){
                p=1; ux=25; px=20; run=4;
            }
            else if(p==1){
                return;
            }
        }
    }
}
void iSpecialKeyboard(unsigned char key){
    if(deadcondition == 1) return;
    if(level == -101701){
        level = leaderlevel;
        return;
    }
    if(key==GLUT_KEY_RIGHT){
        if(level==1 || level==2){
            strcpy(charpos, "r");
            if(uacon==2)
                return;
            if(uacon==1){
                uacon=2;
                ux+=2;
                return;
            }
            if(obstacle_check(ballx+speed, bally)==1){
                ballx+=speed;
            }
            speedtimer=1500;
        }
        if(level==3){  //level=3
            if(knockout==0 && p==0){
                downintersect=0;
        if(ballfly==0 && ballx1+ballr1+5>=recx[cp+1] && type[cp+1]==1 && downfall==0){
            run=1;
            frontindex++;
            if(frontindex>=8){
                frontindex=0;
            }
            return;
        }
        else if(ballfly==1 && ballx1+ballr1+5>=recx[cp+1] && bally1 <=recy[cp+1]+recwidth[cp+1] && downfall==0){
            run=1;
            frontindex++;
            if(frontindex>=8){
                frontindex=0;
            }
            return;
        }
        else if(ballfly==1 && bally1>recy[cp+1]+recwidth[cp+1] && downfall==0){
            ballx1=ballx1+4;
            if(ballx1>2510)  { pox1=-2460; }
            else if(ballx1>1950)  { pox1=-1850; }
            else if(ballx1>1465)  { pox1=-1400; }
            else if(ballx1>1080) { pox1=-1000; }
            else if(ballx1>560) { pox1=-450; }
            run=4;
            frontindex++;
            if(frontindex>=8){
                frontindex=0;
            }
        }
        else{
            if(ballfly==1 && downfall==0){
                run=4;
                ballx1=ballx1+4;
                if(ballx1>2510)  { pox1=-2460; }
                else if(ballx1>1950)  { pox1=-1850; }
                else if(ballx1>1465) { pox1=-1400; }
                else if(ballx1>1080) { pox1=-1000; }
                else if(ballx1>560) { pox1=-450; }
            }
            else if(downfall==0){
                ballx1=ballx1+7;
                if(ballx1>2510)  { pox1=-2460; }
                else if(ballx1>1950)  { pox1=-1850; }
                else if(ballx1>1465) { pox1=-1400; }
                else if(ballx1>1080) { pox1=-1000; }
                else if(ballx1>560) { pox1=-450; }
                run=1;
                frontindex++;
                if(frontindex>=8){
                    frontindex=0;
                }
            }
        }
            }
        }
    }
    if(key==GLUT_KEY_LEFT){
        if(level==1 || level==2){
            //printf("obspos: %lf %lf, %lf -- %lf, %lf %lf\n", ballx, bally, obsx[6], obsx[6]+obsl[6], obsy[6], obsb[6]+obsy[6]);
            strcpy(charpos, "l");
            if(uacon==2)
                return;
            if(uacon==1){
                uacon=2;
                ux=-3;
                return;
            }
            if(obstacle_check(ballx-speed-10, bally)==1){
                ballx-=speed;
                strcpy(charpos, "l");
            }
            speedtimer2=1500;
        }
        if(level==3){
            if(knockout==0 && p==0){
                downintersect=0;
        if(ballfly==1 && ballx1-5<recx[cp] && bally1<=recy[cp-1]+recwidth[cp-1] && downfall==0){
            run=2;
            backindex--;
            if(backindex<0){
                backindex=7;
            }
            return;
        }
        else if((ballfly==0 && (ballx1-5<recx[cp] || ballx1-5<recx[cp-1]) && bally1<recy[cp-1]+recwidth[cp-1])||(ballx1-5<0)){
            if(downfall==0){
                run=2;
                backindex--;
                if(backindex<0){
                    backindex=7;
                }
                return;
            }
        }
        else{
            if(ballfly==1 && downfall==0){
                run=5;
                ballx1=ballx1-4;
                if(ballx1<560) { pox1=0; }
                else if(ballx1<1080) { pox1=-450; }
                else if(ballx1<1465) { pox1=-1000; }
                else if(ballx1<1950) { pox1=-1400; }
                else if(ballx1<2510) { pox1=-1850; }
            }
            else if(downfall==0){
                ballx1=ballx1-7;
                if(ballx1<560) { pox1=0; }
                else if(ballx1<1080) { pox1=-450; }
                else if(ballx1<1465) { pox1=-1000; }
                else if(ballx1<1950) { pox1=-1400; }
                else if(ballx1<2510) { pox1=-1850; }
                run=2;
                backindex--;
                if(backindex<0){
                    backindex=7;
                }
            }
        }
            }
        }
    }
    if(key==GLUT_KEY_UP){
        if((level==1 || level==2) && jump<4){
            jump++;
            if(jump%2==1){
                upanimation();
            }
        }
        if(level==3 && knockout==0 && p==0){
            downintersect=0;
            if(bally1+60>screenwidth+50){
                return;
            }
            else if(downfall==0){
                bally1=bally1+8;
                run=3;
            }
        }
    }
    if(key==GLUT_KEY_DOWN && level==3 && knockout==0){
        if(ballfly==0 && downfall==0){
            run=6;  downflag=1;  downintersect=1;
            return;
        }
        if(bally1-5<recy[cp]+recwidth[cp] && downfall==0){
            run=0;  downintersect=0;
            return;
        }
        if(downfall==0){
            bally1=bally1-5;
            run=0;  downintersect=0;
        }
    }
}
void change(){
  if(level==3){
    if(life==0 && fire==false){
        checkpoint=1;
        extralife=1;
        knockout=0;
        level=-1;
    }
    else if(life==0 && fire==true){
        return;
    }
    else{
        for(int i=0;i<numrightobstacles;i++){
        enemy[i].birdx-=enemy[i].speed;
        if(downintersect==1){
            if(areaintersect(ballx1,ballx1+35,bally1,bally1+39,enemy[i].birdx,enemy[i].birdy,enemy[i].birdx+35,enemy[i].birdy+37) && knockout==0){
                fire=true;
                soundplay();
                x=enemy[i].birdx;
                y=enemy[i].birdy;
                enemy[i].birdshow=false;
                life--;
                knockout=1;
            }
        }
        else if(areaintersect(ballx1,ballx1+40,bally1,bally1+60,enemy[i].birdx,enemy[i].birdy,enemy[i].birdx+35,enemy[i].birdy+37) && knockout==0){
            fire=true;
            soundplay();
            x=enemy[i].birdx;
            y=enemy[i].birdy;
            enemy[i].birdshow=false;
            life--;
            knockout=1;
        }
        if(!enemy[i].birdshow){
            enemy[i].birdx=screenlength+rand()%8000;
            enemy[i].birdy=120+rand()%520;
            enemy[i].speed=6+rand()%5;
            enemy[i].birdshow=true;
        }
        if(enemy[i].birdx<=0){
            enemy[i].birdx=screenlength+rand()%8000;
            enemy[i].birdy=120+rand()%520;
            enemy[i].speed=6+rand()%5;
            enemy[i].birdshow=true;
        }
    }
    ///change1
    for(int i=0;i<numdownobstacles;i++){
        enemy1[i].birdy-=enemy1[i].speed;
        if(downintersect==1){
            if(areaintersect(ballx1,ballx1+35,bally1,bally1+39,enemy1[i].birdx,enemy1[i].birdy,enemy1[i].birdx+35,enemy1[i].birdy+37) && knockout==0){
                fire=true;
                soundplay();
                x=enemy1[i].birdx;
                y=enemy1[i].birdy;
                enemy1[i].birdshow=false;
                life--;
                knockout=1;
            }
        }
        else if(areaintersect(ballx1,ballx1+40,bally1,bally1+60,enemy1[i].birdx,enemy1[i].birdy,enemy1[i].birdx+35,enemy1[i].birdy+37) && knockout==0){
            fire=true;
            soundplay();
            x=enemy1[i].birdx;
            y=enemy1[i].birdy;
            enemy1[i].birdshow=false;
            life--;
            knockout=1;
        }
        if(!enemy1[i].birdshow){
            enemy1[i].birdx=100+rand()%1260;
            enemy1[i].birdy=screenwidth+rand()%6000;
            enemy1[i].speed=5+rand()%5;
            enemy1[i].birdshow=true;
        }
        if(enemy1[i].birdy<=0){
            enemy1[i].birdy=screenwidth+rand()%6000;
            enemy1[i].birdx=100+rand()%1260;
            enemy1[i].speed=5+rand()%5;
            enemy1[i].birdshow=true;
        }
    }
    ///minechange
    for(i=0;i<minenumber;i++){
        if(mine[i].mineindex==0){
            mine[i].mnx+=mine[i].minespeed;
            if(mine[i].mnx+25>mine[i].minex+mine[i].minelen){
                mine[i].mineindex=1;
            }
        }
        else if(mine[i].mineindex==1){
            mine[i].mnx-=mine[i].minespeed;
            if(mine[i].mnx<mine[i].minex){
                mine[i].mineindex=0;
            }
        }
        if(areaintersect(ballx1,ballx1+40,bally1,bally1+60,mine[i].mnx,mine[i].miney,mine[i].mnx+25,mine[i].miney+37) && knockout==0){
            life--;
            if(mine[i].mineindex==0){
                knockout=2;
            }
            else if(mine[i].mineindex==1){
                knockout=1;
            }
        }
    }
    if(mine[4].mineindex==2){
        mine[4].miney+=mine[4].minespeed;
        if(mine[4].miney+5>mine[4].mnx+mine[4].minelen){
            mine[i].mineindex=3;
        }
    }
    else if(mine[4].mineindex==3){
        mine[4].miney-=mine[i].minespeed;
        if(mine[4].miney<mine[4].mnx){
            mine[4].mineindex=2;
        }
    }
    if(areaintersect(ballx1,ballx1+40,bally1,bally1+60,mine[4].minex,mine[i].miney,mine[i].minex+30,mine[i].miney+30) && knockout==0){
            life--;
            knockout=2;
    }
    }
  }
}
void setenemyvariables(){
    for(int i=0;i<numrightobstacles;i++){
        enemy[i].birdx=screenlength+rand()%10000;
        enemy[i].birdy=120+rand()%520;
        enemy[i].birdindex=rand()%7;
        enemy[i].speed=6+rand()%5;
        enemy[i].birdshow=true;
    }
}
void setenemyvariables1(){
    for(int i=0;i<numdownobstacles;i++){
        enemy1[i].birdy=screenwidth+rand()%10000;
        enemy1[i].birdx=100+rand()%1260;
        enemy1[i].birdindex=rand()%4;
        enemy1[i].speed=6+rand()%5;
        enemy1[i].birdshow=true;
    }
}
void minevariables(){
    mine[0].minex=720; mine[0].mnx=720; mine[0].miney=110; mine[0].minelen=250; mine[0].mineindex=0; mine[0].minespeed=2;
    mine[1].minex=1230; mine[1].mnx=1230; mine[1].miney=210; mine[1].minelen=150; mine[1].mineindex=0; mine[1].minespeed=1;
    mine[2].minex=1810; mine[2].mnx=1810; mine[2].miney=240; mine[2].minelen=200; mine[2].mineindex=0; mine[2].minespeed=1.5;
    mine[3].minex=2480; mine[3].mnx=2480; mine[3].miney=250; mine[3].minelen=250; mine[3].mineindex=0; mine[3].minespeed=2;
    mine[4].minex=2900; mine[4].mnx=250; mine[4].miney=250; mine[4].minelen=200; mine[4].mineindex=2; mine[4].minespeed=4;
}
int main(){
    newgame();
    restart(); minevariables(); setenemyvariables(); setenemyvariables1();
    iSetTimer(50, introbmpname);
    iSetTimer(80, smooth);
    iSetTimer(40, smooth1);
    iSetTimer(10, timer);

    iSetTimer(100, charcondition);
    iSetTimer(20,change); iSetTimer(80,ko); iSetTimer(50,checkshow);
    if(main_menu && sound>0){
        PlaySound("Musix\\main menu.wav",NULL,SND_LOOP | SND_ASYNC);
    }
    iInitialize(screenlength,screenwidth+50, "Asobu Ka Shino");
    return 0;
}
