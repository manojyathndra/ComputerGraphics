#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
GLfloat x1,x2,y1,y2,x3,x4,y3,y4,x5,y5;
int d=230,flag=0,flagg=0;

void edgedetect(GLfloat x1,GLfloat y1,GLfloat x2,GLfloat y2,int *le,int *re)
{
	float mx,x,temp;
	int i;
	if((y2-y1)<0)
	{
		temp=x1; x1=x2; x2=temp;
		temp=y1; y1=y2; y2=temp;

	}
	if((y2-y1)!=0)
		mx=(x2-x1)/(y2-y1);
	else
		mx=x2-x1;
	x=x1;
	for(i=y1;i<y2;i++)
	{
		if(x<le[i])
			le[i]=x;
		if(x>re[i])
			re[i]=x;
		x+=mx;

	}
}
void dp(GLint cx,GLint cy)
{

	glBegin(GL_POINTS);
 	glVertex2i(cx,cy);
	glEnd();

}

void scanfill(float x1,float y1, float x2, float y2, float x3, float y3,float x4,float y4)
{
	int le[1000],re[1000];
	int i,y;
	for(i=0;i<1000;i++)
	{
		le[i]=1000;
		re[i]=0;

	}
	edgedetect(x1,y1,x2,y2,le,re);
	edgedetect(x2,y2,x3,y3,le,re);
	edgedetect(x3,y3,x4,y4,le,re);
	edgedetect(x4,y4,x1,y1,le,re);
		for(y=0;y<1000;y++)
	{
		if(le[y]<=re[y])
			for(i=le[y]+1;i<re[y];i++)
				dp(i,y);
	}
}



void pix(GLint h,GLint k,GLint x,GLint y)
{
	dp(x+h,y+k);
	dp(x+h,-y+k);
	dp(-x+h,-y+k);
	dp(-x+h,y+k);
	dp(y+h,x+k);
	dp(y+h,-x+k);
	dp(-y+h,-x+k);
	dp(-y+h,x+k);

}
void cd(GLint h,GLint k,GLint r)
{
	GLint d=1-r,x=0,y=r;
	while(y>x)
	{
		pix(h,k,x,y);
		if(d<0)
			d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	pix(h,k,x,y);
}
void init()
{
	//glClearColor(0.0,0.5,0.8,1.0);
        //glutClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(0.0,0.0,0.5);
	glPointSize(4.0);
	gluOrtho2D(0.0,1000.0,0.0,1000.0);

}


/*
void makedelay(int)
{
void dustbin1();
glutTimerFunc(4,makedelay,1);
}*/


void dustbin1()
{

glColor3f(1.0,0.0,0.0);
glBegin(GL_POLYGON);

glVertex2i(20,220);

glVertex2i(10,280);

glVertex2i(25,270);

glVertex2f(55,270);

glVertex2i(65,280);

glVertex2i(50,220);
glEnd();

}


void dustbin2()
{


glColor3f(0.419608,0.137255,0.556863);
glBegin(GL_POLYGON);

glVertex2i(275,220);

glVertex2i(265,280);

glVertex2i(280,270);

glVertex2f(310,270);

glVertex2i(320,280);

glVertex2i(305,220);
glEnd();


glColor3f(0.0,0.0,0.0);
glRasterPos2i(280,250);
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'U');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'S');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'E');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,' ');


glColor3f(0.0,0.0,0.0);
glRasterPos2i(280,235);
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'M');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'E');
}

void dustbin3()
{


glColor3f(0.858824,0.858824,0.0439216);
glBegin(GL_POLYGON);

glVertex2i(560,220);

glVertex2i(550,280);

glVertex2i(565,270);

glVertex2f(595,270);

glVertex2i(605,280);

glVertex2i(590,220);
glEnd();



glColor3f(0.0,0.0,0.0);
glRasterPos2i(565,250);
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'U');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'S');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'E');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,' ');


glColor3f(0.0,0.0,0.0);
glRasterPos2i(565,235);
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'M');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'E');

}

void Timer(int iUnused)
{
glutPostRedisplay();
glutTimerFunc(1,Timer,0);
}
 
void tree()
{ 
int l; 
glColor3f(0.9,0.2,0.0); 
glBegin(GL_POLYGON); 
glVertex2f(570,480); 
glEnd();
for(l=0;l<=30;l++)
{ 
glColor3f(0.0,0.5,0.0);
cd(570,480,l);
}
for(l=0;l<=25;l++)
{
glColor3f(0.0,0.5,0.0);
cd(570,450,l);

}
for(l=0;l<=20;l++) 
{ 
glColor3f(0.0,0.5,0.0);
cd(570,420,l);
}
		glColor3f(0.5,0.2,0.0);
	        glBegin(GL_POLYGON);
			glVertex2i(560,320);
			glVertex2i(560,400);
			glVertex2i(580,400);
			glVertex2i(580,320);
			glEnd();

}



void display2()
{
glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(1.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,500.0,0.0,500.0);
	glMatrixMode(GL_MODELVIEW);




}


void display()
{
glClearColor(0.0,0.5,0.8,1.0);
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

float i,j;
for(i=0;i<1000;i+=0.5)
{
/*if(i>=230 && i<=260 )
{
continue;
}
if(flag==1)
{
glutTimerFunc(5);
}
else if(flag==0||i>230)
{ */	

	glClear(GL_COLOR_BUFFER_BIT);
	//sun
	glColor3f(1.0,0.0,0.0);
	cd(600,500,35);
	cd(600,500,30);
	cd(600,500,25);
	cd(600,500,20);
	cd(600,500,15);
	cd(600,500,10);
	cd(600,500,50);
	cd(600,500,45);
	cd(600,500,40);
	cd(600,500,5);
	cd(600,500,55);
	cd(600,500,60);


	glColor3f(0.0,0.8,0.3);
	glBegin(GL_QUADS);
	glVertex2i(0,500);
	glVertex2i(1000,500);
	glVertex2i(1000,0);
	glVertex2i(0,0);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_QUADS);
	glVertex2i(0,250);
	glVertex2i(1000,250);
	glVertex2i(1000,200);
	glVertex2i(0,200);
	glEnd();
	glColor3f(0.192,0.192,0.192);
//road
	glBegin(GL_QUADS);
		glVertex2i(0,100);
		glVertex2i(0,130);
		glVertex2i(1000,130);
		glVertex2i(1000,100);
		glEnd();
	


	//glColor3f(1.0,1.0,0.5);
//WHEEL
glColor3f(0.0,0.0,0.0);
cd(30+i,110,10);
cd(80+i,110,10);
cd(130+i,110,10);
cd(170+i,110,10);

cd(225+i,110,10);
cd(265+i,110,10);

cd(320+i,110,10);
cd(360+i,110,10);
//

glBegin(GL_TRIANGLES);
glVertex2i(200+i,800);
glVertex2i(200+i,815);
glVertex2i(215+i,808);
glEnd();
glBegin(GL_TRIANGLES);
glVertex2i(200+i+i,800);
glVertex2i(200+i+i,815);
glVertex2i(215+i+i,808);

glVertex2i(200+i+i+i,800);
glVertex2i(200+i+i+i,815);
glVertex2i(215+i+i+i,808);
glEnd();
/*
glBegin(GL_LINES);
glVertex2i(130+i+i,790);
glVertex2i(130+i+i,800);
glVertex2i(170+i+i,790);
glVertex2i(170+i+i,800);
glVertex2i(142+i+i,870);
glVertex2i(142+i+i,880);

glVertex2i(0,100);
glVertex2i(1000,100);
glVertex2i(0,130);
glVertex2i(1000,130);*/

//Road Stripes
for(j=0;j<=1000;j+=30)
{

	glColor3f(0.0,0.8,1.2);
	glBegin(GL_POLYGON);
	glVertex2i(0+j,115);
	glVertex2i(0+j,120);
	glVertex2i(15+j,120);
	glVertex2i(15+j,115);
	glEnd();

}
glEnd();

glColor3f(0.0,0.8,1.2);
	glBegin(GL_POLYGON);
	glVertex2i(730,150);
	glVertex2i(730,260);
	glVertex2i(740,260);
	glVertex2i(740,150);
	glEnd();
	glColor3f(1.0,0.0,1.5);
		glBegin(GL_POLYGON);
		glVertex2i(920,150);
		glVertex2i(920,260);
		glVertex2i(930,260);
		glVertex2i(930,150);
		glEnd();
	glColor3f(1.0,1.0,0.0);
		glBegin(GL_POLYGON);
		glVertex2i(650,260);
		glVertex2i(980,260);
		glVertex2i(980,300);
		glVertex2i(650,300);
		glEnd();

glColor3f(0.0,0.0,0.0);
glRasterPos2i(710,270);
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'S');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'W');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'A');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'C');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'C');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'H');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,' ');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'B');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'H');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'A');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'R');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'A');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,'T');




glColor3f(0.0,0.0,1.0);
scanfill(15+i,120,15+i,160,95+i,160,95+i,120);
glColor3f(0.0,0.0,0.0);
scanfill(15+i,160,25+i,170,105+i,170,95+i,160);
glColor3f(1.0,1.0,0.0);
scanfill(95+i,160,105+i,170,105+i,130,95+i,120);

glColor3f(0.0,0.0,1.0);
scanfill(110+i,120,110+i,160,190+i,160,190+i,120);
glColor3f(0.0,0.0,0.0);
scanfill(110+i,160,120+i,170,200+i,170,190+i,160);
glColor3f(1.0,1.0,0.0);
scanfill(190+i,160,200+i,170,200+i,130,190+i,120);

glColor3f(0.0,0.0,1.0);
scanfill(205+i,120,205+i,160,285+i,160,285+i,120);
glColor3f(0.0,0.0,0.0);
scanfill(205+i,160,215+i,170,295+i,170,285+i,160);
glColor3f(1.0,1.0,0.0);
scanfill(285+i,160,295+i,170,295+i,130,288+i,120);

glColor3f(0.0,0.0,1.0);
scanfill(300+i,120,300+i,160,380+i,160,380+i,120);
glColor3f(0.0,0.0,0.0);
scanfill(300+i,160,310+i,170,390+i,170,380+i,160);
glColor3f(1.0,1.0,0.0);
scanfill(380+i,160,390+i,170,390+i,130,380+i,120);

glColor3f(1.0,0.0,0.0);
cd(388+i,150,3);

glBegin(GL_LINES);
glVertex2i(375+i,165);
glVertex2i(375+i,185);
glVertex2i(372+i,165);
glVertex2i(372+i,185);
glEnd();

glColor3f(0.0,1.0,0.5);
glBegin(GL_QUADS);
glVertex2i(0,500);
glVertex2i(0,550);
glVertex2i(100,600);
glVertex2i(200,500);
glEnd();

glColor3f(0.0,1.0,0.0);
glBegin(GL_TRIANGLES);
glVertex2i(400,500);
glVertex2i(500,600);
glVertex2i(600,500);

glEnd();

glColor3f(0.0,0.5,0.0);
glBegin(GL_TRIANGLES);
glVertex2i(100,500);
glVertex2i(300,600);
glVertex2i(500,500);

glEnd();

//second hill set


glColor3f(0.0,1.0,0.5);
glBegin(GL_TRIANGLES);
glVertex2i(600,500);
//glVertex2i(600,550);
glVertex2i(700,600);
glVertex2i(800,500);
glEnd();

glColor3f(0.0,1.0,0.0);
glBegin(GL_TRIANGLES);
glVertex2i(800,500);
glVertex2i(1000,600);
glVertex2i(1000,500);

glEnd();

glColor3f(0.0,0.5,0.0);
glBegin(GL_TRIANGLES);
glVertex2i(700,500);
glVertex2i(900,600);
glVertex2i(1000,500);
glEnd();
for(j=0;j<=90;j+=5)
{
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
	glVertex2i(290,500+j);
	glVertex2i(310,500+j);
	glEnd();
}
glColor3f(1.5,0.8,1.2);
	glBegin(GL_POLYGON);
	glVertex2i(280,590);
	glVertex2i(280,615);
	glVertex2i(320,615);
	glVertex2i(320,590);
	glEnd();

	glColor3f(1.0,1.0,1.0);
		glBegin(GL_POLYGON);
		glVertex2i(280,615);
		glVertex2i(320,615);
		glVertex2i(310,650);
		glVertex2i(290,650);
		glEnd();
		glColor3f(1.0,1.0,1.0);
			glBegin(GL_LINES);
			glVertex2i(295,650);
			glVertex2i(295,655);
			glVertex2i(300,650);
			glVertex2i(300,655);
			glVertex2i(305,650);
			glVertex2i(305,655);
			glEnd();
			//tree
			int k;
			for(k=200;k<900;k+=150)
				{
				if(k>=480 && k<=780)
				{
					continue;		
				}
				glColor3f(0.5,0.3,0.5);

	        glBegin(GL_POLYGON);
			glVertex2i(50+k,310);
			glVertex2i(50+k,350);
			glVertex2i(60+k,350);
			glVertex2i(60+k,310);
			glEnd();
			glColor3f(0.0,1.0,0.0);
			glBegin(GL_TRIANGLES);
			glVertex2i(40+k,350);
			glVertex2i(55+k,410);
			glVertex2i(70+k,350);
			glEnd();
			//house
			glColor3f(1.0,1.2,0.0);
				        glBegin(GL_POLYGON);
						glVertex2i(85+k,310);
						glVertex2i(85+k,350);
						glVertex2i(130+k,350);
						glVertex2i(130+k,310);
						glEnd();
						 glBegin(GL_POLYGON);
						 glColor3f(0.0,0.0,0.0);
						glVertex2i(100+k,310);
						glVertex2i(100+k,330);
						glVertex2i(115+k,330);
						glVertex2i(115+k,310);
						glEnd();
						glColor3f(0.0,1.0,1.0);
						glBegin(GL_TRIANGLES);
						glVertex2i(80+k,350);
						glVertex2i(105+k,380);
						glVertex2i(135+k,350);
						glEnd();

						}
				
		
//TOILET
glColor3f(1.0,1.0,1.0);
glBegin(GL_LINE_LOOP);
glVertex2i(650,320);
glVertex2i(650,520);
glVertex2i(660,495);
glVertex2i(720,495);
glVertex2i(730,520);
glVertex2i(730,320);
glEnd();


glColor3f(1.0,0.8947,0.710);
glBegin(GL_POLYGON);
glVertex2i(650,320);
glVertex2i(650,520);
glVertex2i(660,495);
glVertex2i(720,495);
glVertex2i(730,520);
glVertex2i(730,320);
glEnd();



glColor3f(0.0,0.0,0.0);
glRasterPos2i(670,470);
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'U');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'S');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'E');

glColor3f(0.0,0.0,0.0);
glRasterPos2i(662,450);
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'P');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'U');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'B');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'L');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'I');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'C');

glColor3f(0.0,0.0,0.0);
glRasterPos2i(662,430);
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'T');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'O');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'I');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'L');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'E');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'T');


glColor3f(1.0,1.0,1.0);
glBegin(GL_LINE_LOOP);

glVertex2i(650,520);
glVertex2i(660,495);
glVertex2i(720,495);
glVertex2i(730,520);
glEnd();

glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);

glVertex2i(650,520);
glVertex2i(660,495);
glVertex2i(720,495);
glVertex2i(730,520);
glEnd();

glColor3f(0.0,0.0,0.0);
glRasterPos2i(662,503);
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'T');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'O');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'I');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'L');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'E');
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'T');

glColor3f(1.0,1.0,1.0);
glBegin(GL_LINE_LOOP);
glVertex2i(670,320);
glVertex2i(670,400);
glVertex2i(710,400);
glVertex2i(710,320);
glEnd();

glColor3f(1.0,0.627,0.478);
glBegin(GL_QUADS);
glVertex2i(670,320);
glVertex2i(670,400);
glVertex2i(710,400);
glVertex2i(710,320);
glEnd();




glColor3f(1.0,1.0,1.0);
glBegin(GL_LINE_LOOP);
glVertex2i(730,520);
glVertex2i(740,530);
glVertex2i(740,330);
glVertex2i(730,320);
glEnd();


glColor3f(1.0,1.0,1.0);
glBegin(GL_QUADS);
glVertex2i(730,520);
glVertex2i(740,530);
glVertex2i(740,330);
glVertex2i(730,320);
glEnd();


glColor3f(1.0,1.0,1.0);
glBegin(GL_LINE_LOOP);
glVertex2i(650,520);
glVertex2i(660,530);
glVertex2i(740,530);
glVertex2i(730,520);
glEnd();


glColor3f(1.0,1.0,1.0);
glBegin(GL_QUADS);
glVertex2i(650,520);
glVertex2i(660,530);
glVertex2i(740,530);
glVertex2i(730,520);
glEnd();
/*glVertex2i(50,700);
glVertex2i(190,700);

glVertex2i(190,320);*/
//building

glColor3f(1.0,1.0,1.0);
glBegin(GL_LINE_LOOP);
glVertex2i(50,320);
glVertex2i(50,700);
glVertex2i(190,700);

glVertex2i(190,320);
glEnd();

	
glColor3f(0.255,0.255,0.224);
glBegin(GL_QUADS);
glVertex2i(50,320);
glVertex2i(50,700);
glVertex2i(190,700);

glVertex2i(190,320);
glEnd();			

glColor3f(1.0,1.0,1.0);
glBegin(GL_LINE_LOOP);

glVertex2i(50,700);
glVertex2i(80,710);
glVertex2i(210,710);

glVertex2i(190,700);
glEnd();

glColor3f(1.0,1.0,1.0);
glBegin(GL_QUADS);

glVertex2i(50,700);
glVertex2i(80,710);
glVertex2i(210,710);

glVertex2i(190,700);
glEnd();

glColor3f(1.0,1.0,1.0);
glBegin(GL_LINE_LOOP);

glVertex2i(190,700);
glVertex2i(210,710);
glVertex2i(210,330);


glVertex2i(190,320);
glEnd();

glColor3f(1.0,1.0,1.0);
glBegin(GL_QUADS);

glVertex2i(190,700);
glVertex2i(210,710);
glVertex2i(210,330);


glVertex2i(190,320);
glEnd();
//WINDOW
glColor3f(1.0,1.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2i(70,340);
glVertex2i(70,400);
glVertex2i(105,400);

glVertex2i(105,340);
glEnd();

glColor3f(1.0,1.0,0.0);
glBegin(GL_QUADS);
glVertex2i(70,340);
glVertex2i(70,400);
glVertex2i(105,400);

glVertex2i(105,340);
glEnd();

glColor3f(1.0,1.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2i(140,340);
glVertex2i(140,400);
glVertex2i(175,400);

glVertex2i(175,340);
glEnd();


glColor3f(1.0,0.0,0.0);
glBegin(GL_QUADS);
glVertex2i(140,340);
glVertex2i(140,400);
glVertex2i(175,400);

glVertex2i(175,340);
glEnd();


glColor3f(1.0,1.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2i(70,620);
glVertex2i(70,680);
glVertex2i(110,680);

glVertex2i(110,620);
glEnd();

glColor3f(1.0,0.0,0.0);
glBegin(GL_QUADS);
glVertex2i(70,620);
glVertex2i(70,680);
glVertex2i(110,680);

glVertex2i(110,620);
glEnd();

glColor3f(1.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2i(140,620);
glVertex2i(140,680);
glVertex2i(175,680);

glVertex2i(175,620);
glEnd();



glColor3f(1.0,0.0,0.0);
glBegin(GL_QUADS);
glVertex2i(140,620);
glVertex2i(140,680);
glVertex2i(175,680);

glVertex2i(175,620);
glEnd();

glColor3f(1.0,1.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2i(70,470);
glVertex2i(70,540);
glVertex2i(110,540);

glVertex2i(110,470);
glEnd();

glColor3f(1.0,0.0,0.0);
glBegin(GL_QUADS);
glVertex2i(70,470);
glVertex2i(70,540);
glVertex2i(110,540);

glVertex2i(110,470);
glEnd();


glColor3f(1.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2i(140,470);
glVertex2i(140,540);
glVertex2i(175,540);

glVertex2i(175,470);
glEnd();



glColor3f(1.0,0.0,0.0);
glBegin(GL_QUADS);
glVertex2i(140,470);
glVertex2i(140,540);
glVertex2i(175,540);

glVertex2i(175,470);
glEnd();

tree();

if(i<80)
{
dustbin1();
}


if(i<200)
{
dustbin2();
}


if(i<350)
{
dustbin3();
}

if(i>80)
{

glColor3f(1.0,0.0,0.0);
scanfill(25+i,165,25+i,230,65+i,230,65+i,165);
scanfill(25+i,230,65+i,230,75+i,240,35+i,240);
scanfill(65+i,230,75+i,240,75+i,175,65+i,165);
}


if(i>=200)
{
glColor3f(0.419608,0.137255,0.556863);
scanfill(130+i,165,130+i,230,170+i,230,170+i,165);
scanfill(130+i,230,170+i,230,180+i,240,140+i,240);
scanfill(170+i,230,180+i,240,180+i,175,170+i,165);
}



if(i>=350)
{
glColor3f(0.858824,0.858824,0.0439216);
scanfill(235+i,165,235+i,230,275+i,230,275+i,165);
scanfill(235+i,230,275+i,230,285+i,240,245+i,240);
scanfill(275+i,230,285+i,240,285+i,175,275+i,165);
}


glutPostRedisplay();
glFlush();
}
}


void keys(unsigned char key, int x, int y)
	{
	switch(key)
{

case 13:display();
break;
case 27:exit(0);
break;



}
}


char displaystring(int x,int y,char *string,int font)
{


int len,i,z;
glColor3f(0.0,0.0,0.0);
glRasterPos2f(x,y);
len= (int) strlen(string);
for(i=0;i<len;i++)
{
if(font==1)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
if(font==2)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
if(font==3)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
if(font==4)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
if(font==5)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
if(font==6)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
if(font==7)
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,string[i]);
}
}
void displaymypage()
{
glClearColor(0.076,0.76,0.0,1.0);
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
displaystring(370,900," W E L C O M E   T O   M Y  P R O J E C T",7);
displaystring(370,890," __________________________________",7);
displaystring(400,800," Title:SWACHH BHARAT",7);
displaystring(200,650,"***********************************",7);
displaystring(150,600,"1.Press 'Enter' To View The Project.",7);
displaystring(150,480,"2.Press 'ESC' to come out",7);
displaystring(450,200,"BY:-",7);
displaystring(450,150,"CHANDAN KUMAR KAFLE(4SU15CS020)",7);
displaystring(450,120,"MANOJ YATHINDRA(4SU15CS114)",7);
glutSwapBuffers();
}







int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(700,700);
	glutCreateWindow("SWACHH BHARAT");
	glutInitWindowPosition(0,0);
	//glutDisplayFunc(display);

      glutKeyboardFunc(keys);
glutDisplayFunc(displaymypage);
		init();
	
//	glutMouseFunc(mouse);
	
       //Timer(0);
	glutMainLoop();
	return 0;
}

