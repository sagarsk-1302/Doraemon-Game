#include<iostream>
#include<glut.h>
#include <math.h>
#include <stdlib.h>
#include<windows.h>
#include <cstring>
#include <sstream>  // for string streams
#include <string>  // for string
using namespace std;
 
float xr=0,yr=0,xb[5],yb[5];
int score = 0;
bool notOut=true;
void drawCricle(float x, float y, float size_h,float size_v,float red,float green,float blue){
    float angle_theta;
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0,
               0.0, 600.0);
    glColor3f(red,green,blue);
    glBegin(GL_POLYGON);
     for (int i = 0; i < 360; i++) {
            // Find the angle
            angle_theta = float(i * 3.142 / 180);
            glVertex2f(x + size_h * cos(angle_theta),
                       y + size_v * sin(angle_theta));
        }
     glEnd();

}
void semiCricle(float x, float y, float size_h,float size_v,float red,float green,float blue){
    float angle_theta;
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0,
               0.0, 600.0);
    glColor3f(red,green,blue);
    glBegin(GL_POLYGON);
     for (int i = 180; i < 360; i++) {
            // Find the angle
            angle_theta = float(i * 3.142 / 180);
            glVertex2f(x + size_h * cos(angle_theta),
                       y + size_v * sin(angle_theta));
        }
     glEnd();

}
void pointedSemiCricle(float x, float y, float size_h,float size_v,float red,float green,float blue){
    float angle_theta;
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0,
               0.0, 600.0);
    glColor3f(red,green,blue);
    glBegin(GL_POINTS);
     for (int i = 180; i < 360; i++) {
            // Find the angle
            angle_theta = float(i * 3.142 / 180);
            glVertex2f(x + size_h * cos(angle_theta),
                       y + size_v * sin(angle_theta));
        }
     glEnd();

}
void drawLine(float x_start, float y_start,float x_end, float y_end,float red,float green,float blue){
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0,
               0.0, 600.0);
    glColor3f(red,green,blue);
    glBegin(GL_LINES);
    glVertex2d(x_start, y_start);
	glVertex2d(x_end, y_end);
    glEnd();
}
void timer(int value){
	for(int i=0;i<5;i++){
		//check for collision
		if((xb[i]> (165+xr)) && (xb[i]<(245+xr)) && ((600-yb[i])<(195+yr)) && notOut){
			cout<<"OUT!!"<<endl;
			notOut = false;
			MessageBox(NULL, L"You are Out!!", L"Info",MB_OK | MB_ICONEXCLAMATION);
			exit(0);
		}
	yb[i]+=3;

	}
	glutPostRedisplay();
	glutTimerFunc(20,timer,0);
}
void createbrick(){
	for(int i=0;i<5;i++){
		if(yb[i]>600){
		yb[i]=0;
		score +=1;
		xb[i] = rand()%800;
	}
	drawCricle(xb[0]+10,600-yb[0],15,15,0.8,0,0.2);
	drawCricle(xb[1]+10,600-yb[1],15,15,0.9,0,0.5);
	drawCricle(xb[2]+10,600-yb[2],15,15,0.5,0.8,0.3);
	drawCricle(xb[3]+10,600-yb[3],15,15,0.5,0,0.1);
	drawCricle(xb[4]+10,600-yb[4],15,15,0.4,0.7,1);
	}

}

void displayText() {
ostringstream str1;
str1 << "Score :"<<score;
string geek = str1.str();
int j = geek.size();
glColor3f( 1, 1, 1 );
glRasterPos2f( 10, 580 );
for( int i = 0; i < j; i++ ) {
glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, geek[i] );
}
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	//brick
	displayText();
	createbrick();
	//body
	drawCricle(200+xr,90+yr,50,50,0,0,1); 
	drawCricle(200+xr,90+yr,40,40,1,1,1);
	//legs
	drawCricle(178+xr,35+yr,18,10,1,1,1);
	drawCricle(222+xr,35+yr,18,10,1,1,1);
	//hands
	drawCricle(265+xr,90+yr,18,10,1,1,1);
	drawCricle(135+xr,90+yr,18,10,1,1,1);
	//face outline
    	drawCricle(200+xr,150+yr,45,45,0,0,1);
    	drawCricle(200+xr,150+yr,35,35,1,1,1);
	//bamboocopter
	drawLine(200+xr,195+yr,200+xr,205+yr,0.9,1,0.1);
	drawLine(201+xr,195+yr,201+xr,205+yr,0.9,1,0.1);
	drawCricle(200+xr,206+yr,10,4,0.9,1,0.1);
	//eyes
    	drawCricle(190+xr,165+yr,8,8,0,0,0);
    	drawCricle(190+xr,165+yr,3,3,1,1,1);
	drawCricle(212+xr,165+yr,8,8,0,0,0); 
	drawCricle(212+xr,165+yr,3,3,1,1,1);
	//nose
	drawCricle(200+xr,150+yr,6,6,1,0,0);
	//facehair
	drawLine(210+xr,148+yr,225+xr,145+yr,0,0,0);
	drawLine(210+xr,151+yr,225+xr,152+yr,0,0,0);
	drawLine(190+xr,148+yr,175+xr,145+yr,0,0,0);
	drawLine(190+xr,151+yr,175+xr,152+yr,0,0,0);
	//mouth
	semiCricle(200+xr,140+yr,18,18,1,0,0);
	//magicpocket
    	pointedSemiCricle(200+xr,90+yr,30,30,0,0,0); 
    	drawLine(170+xr,90+yr,230+xr,90+yr,0,0,0);
	glFlush();
	glutPostRedisplay();
	glutSwapBuffers();
}
void specialkey(int key,int x,int y){
	switch(key){
		case GLUT_KEY_UP: yr+=5;
			//glutPostRedisplay();
			break;
		case GLUT_KEY_DOWN: yr-=5;
			//glutPostRedisplay();
			break;
		case GLUT_KEY_LEFT: xr-=5;
			//glutPostRedisplay();
			break;
		case GLUT_KEY_RIGHT: xr+=5;
			//glutPostRedisplay();
			break;
	}

}
int main(int argc, char** argv)
{
 
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 
    // Creates the window as
    // specified by the user
    glutCreateWindow("Doraemon");
 
    // Sets the background color
    glClearColor(0, 0, 0, 0);
 
    // Clears the frame buffer
    glClear(GL_COLOR_BUFFER_BIT);
 
    // Links display event with the
    // display event handler(display)
    glutDisplayFunc(display);
	glutSpecialFunc(specialkey);
	glutTimerFunc(0,timer,0);
    // Loops the current event
    glutMainLoop();
}

 
 
