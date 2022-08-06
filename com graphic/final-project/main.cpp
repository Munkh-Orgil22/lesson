#include<stdio.h>
#include<GL/glut.h>
void bus();
void road();
void signal();
void car();
void car2();
void mydisplay();
void display();
void frontsreen();
void drawstring();
void setFont();
void myMouse();
void update();
void control();
GLint a=300,b=-300, traffic_regulator=1, control_keyl, control_keyr;
GLfloat red=0,blue=1,green=.3;

GLfloat r=0,yell=0,g=0; // gerlen dohionii gerelnii ungiig todorhoiloh

void control()
{
	if(control_keyl!='l'||control_keyr!='r')
	{
		if(control_keyl=='l')
			a=a+6;
		if(control_keyr=='r')
			b=b-6;
	}
	
}

void myKeyboard( unsigned char key, int x, int y )
{
	switch(key)
	{
		case 'l':control_keyl=key;
			r=0;yell=0;g=1;
		break;
		case 'r':control_keyr=key;
			r=0;yell=0;g=1;
		break;
		default:break;
	}
}

void myMouse(int button,int state,int x,int y)
{
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
	    traffic_regulator=0;
        r=1;
        yell=0;
        g=0;
	}
	
	if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
	{
        traffic_regulator=0;
        r=0;
        yell=1;
        g=0;
	}
	if(button==GLUT_RIGHT_BUTTON && state==GLUT_UP)
	{	
        traffic_regulator=1;
        r=0;
        yell=0;
        g=1;
	}
	glutPostRedisplay();
	
}

void mydisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	display();
	glutSwapBuffers();
}

void update(int value)
{
	a=a-6;
	b=b+6;
	control();
	glutPostRedisplay();
}

void display(void)
{
	if(traffic_regulator)
		glutTimerFunc(50,update,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(red,green,blue,0); // background color
	road();
	bus();
	signal();
	car();
	car2();
	glFlush();
}

void road()
{
	glPushMatrix();
	glScaled(40.0,40.0,0.0);
	glColor3f(0.1,0.1,0.1);
	glBegin(GL_POLYGON);
	//shuluun zam
	glVertex2f(0,5);
	glVertex2f(40,5);
	glVertex2f(40,10);
	glVertex2f(0,10);
	glEnd();
	//zamiin hvree (nogoon)
	glBegin(GL_POLYGON);
	glColor3f(0.1,0.2,0.1);
	glVertex2f(0,5);
	glVertex2f(40,5);
	glVertex2f(40,4);
	glVertex2f(0,4);
	glEnd();
	//hundlun zam
	glColor3f(0.1,0.1,0.1);
	glBegin(GL_POLYGON);
	glVertex2f(10,10);
	glVertex2f(15,10);
	glVertex2f(0,40);
	glVertex2f(4,40);
	glEnd();
	glPopMatrix();
}

void signal()
{
	glPushMatrix();
	glScaled(40.0,40.0,0.0);
	//suuri
	glColor3f(0.1,0.2,0.1);
	glBegin(GL_POLYGON);
	glVertex2f(15,7);
	glVertex2f(15,8);
	glVertex2f(18,8);
	glVertex2f(18,7);
	glEnd();
	//shon
	glBegin(GL_POLYGON);
	glVertex2f(16,7);
	glVertex2f(17,8);
	glVertex2f(17,15);
	glVertex2f(16,15);
	glEnd();
	//sambar
	glBegin(GL_POLYGON);
	glVertex2f(15.5,15);
	glVertex2f(17.5,15);
	glVertex2f(17.5,10);
	glVertex2f(15.5,10);
	glEnd();
	//red
	glColor3f(r,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(16,14.5);
	glVertex2f(17,14.5);
	glVertex2f(17,14);
	glVertex2f(16,14);
	glEnd();
	//yellow
	glColor3f(yell,yell,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(16,13.5);
	glVertex2f(17,13.5);
	glVertex2f(17,13);
	glVertex2f(16,13);
	glEnd();
	//green
	glColor3f(0.0,g,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(16,12.5);
	glVertex2f(17,12.5);
	glVertex2f(17,12);
	glVertex2f(16,12);
	glEnd();
	glPopMatrix();
}

void bus()
{
	glPushMatrix();
	glTranslated(a,50.0,0.0);
	glScaled(40.0,40.0,0.0);
	glColor3f(0.5,0.0,0.0);
	//awtobusnii hvree
	glBegin(GL_POLYGON);
	glVertex2f(25,8);
	glVertex2f(25,9.5);
	glVertex2f(26,11);
	glVertex2f(32,11);
	glVertex2f(32,8);
	glEnd();
	//tsonhnii hvree
	glColor3f(0,0.1,1);
	glBegin(GL_POLYGON);
	glVertex2f(26.1,9.5);
	glVertex2f(26.1,10.5);
	glVertex2f(31.8,10.5);
	glVertex2f(31.8,9.5);
	glEnd();
	//haalga
	glColor3f(0,0.8,1);
	glBegin(GL_POLYGON);
	glVertex2f(26.2,9);
	glVertex2f(26.2,10.4);
	glVertex2f(27.7,10.4);
	glVertex2f(27.7,9);
	glEnd();
	//haalga
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	glVertex2f(27,8.4);
	glVertex2f(27,10.4);
	glVertex2f(27.7,10.4);
	glVertex2f(27.7,8.4);
	glEnd();
	//jijig tsonhnuud
	glColor3f(0,1,1);
	glBegin(GL_POLYGON);
	glVertex2f(27.8,9.6);
	glVertex2f(27.8,10.4);
	glVertex2f(29,10.4);
	glVertex2f(29,9.6);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(29.1,9.6);
	glVertex2f(29.1,10.4);
	glVertex2f(30.2,10.4);
	glVertex2f(30.2,9.6);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(30.3,9.6);
	glVertex2f(30.3,10.4);
	glVertex2f(31.7,10.4);
	glVertex2f(31.7,9.6);
	glEnd();


	//joloodoh hesgiin tsonh
	glColor3f(0,0.8,1);
	glBegin(GL_POLYGON);
	glVertex2f(25,9.5);
	glVertex2f(26,11);
	glVertex2f(26,9.5);
	glEnd();
	glPopMatrix();
	//dugui
	glPushMatrix();//urd dugui
	glTranslated(a+970,320,0.0);
	glScaled(20.0,20.0,0.0);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(3.0,2.5);
	glVertex2f(3.0,2.6);
	glVertex2f(3.15,3.1);
	glVertex2f(3.2,3.2);
	glVertex2f(3.3,3.35);
	glVertex2f(3.4,3.4);
	glVertex2f(3.5,3.45);
	glVertex2f(3.6,3.55);
	glVertex2f(3.7,3.6);
	glVertex2f(3.8,3.63);
	glVertex2f(4.0,3.65);
	glVertex2f(4.2,3.7);
	glVertex2f(4.4,3.7);
	glVertex2f(4.6,3.65);
	glVertex2f(4.8,3.55);
	glVertex2f(5.0,3.45);
	glVertex2f(5.1,3.4);
	glVertex2f(5.2,3.25);
	glVertex2f(5.3,3.2);
	glVertex2f(5.4,3.0);
	glVertex2f(5.5,2.5);

	glVertex2f(5.45,2.15);
	glVertex2f(5.4,1.9);
	glVertex2f(5.35,1.8);
	glVertex2f(5.2,1.6);
	glVertex2f(5.0,1.5);
	glVertex2f(4.9,1.4);
	glVertex2f(4.7,1.3);
	glVertex2f(4.6,1.27);
	glVertex2f(4.4,1.25);
	glVertex2f(4.0,1.25);
	glVertex2f(3.9,1.3);
	glVertex2f(3.75,1.35);
	glVertex2f(3.6,1.4);
	glVertex2f(3.45,1.55);
	glVertex2f(3.3,1.7);
	glVertex2f(3.2,1.8);
	glVertex2f(3.1,2.2);
	glEnd();
	glPopMatrix();

	glPushMatrix();//hoid dugui
	glTranslated(a+1140,320,0.0);
	glScaled(20.0,20.0,0.0);
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(3.0,2.5);
	glVertex2f(3.0,2.6);
	glVertex2f(3.15,3.1);
	glVertex2f(3.2,3.2);
	glVertex2f(3.3,3.35);
	glVertex2f(3.4,3.4);
	glVertex2f(3.5,3.45);
	glVertex2f(3.6,3.55);
	glVertex2f(3.7,3.6);
	glVertex2f(3.8,3.63);
	glVertex2f(4.0,3.65);
	glVertex2f(4.2,3.7);
	glVertex2f(4.4,3.7);
	glVertex2f(4.6,3.65);
	glVertex2f(4.8,3.55);
	glVertex2f(5.0,3.45);
	glVertex2f(5.1,3.4);
	glVertex2f(5.2,3.25);
	glVertex2f(5.3,3.2);
	glVertex2f(5.4,3.0);
	glVertex2f(5.5,2.5);

	glVertex2f(5.45,2.15);
	glVertex2f(5.4,1.9);
	glVertex2f(5.35,1.8);
	glVertex2f(5.2,1.6);
	glVertex2f(5.0,1.5);
	glVertex2f(4.9,1.4);
	glVertex2f(4.7,1.3);
	glVertex2f(4.6,1.27);
	glVertex2f(4.4,1.25);
	glVertex2f(4.0,1.25);
	glVertex2f(3.9,1.3);
	glVertex2f(3.75,1.35);
	glVertex2f(3.6,1.4);
	glVertex2f(3.45,1.55);
	glVertex2f(3.3,1.7);
	glVertex2f(3.2,1.8);
	glVertex2f(3.1,2.2);
	glEnd();
	glPopMatrix();
}

void car()
{
	glPushMatrix();
	glTranslated(b,190.0,0.0);
	glScaled(20.0,20.0,0.0);
	glColor3f(1.0,0.0,0.0);
	// mashinii hvree
	glBegin(GL_POLYGON);
	glVertex2f(2.5,2.5);
	glVertex2f(3.0,3.5);
	glVertex2f(3.5,3.75);
	glVertex2f(4.0,4.0);
	glVertex2f(4.5,4.0);
	glVertex2f(5.0,3.75);
	glVertex2f(5.5,3.5);
	glVertex2f(5.75,3.0);
	glVertex2f(6.0,2.5);
	glVertex2f(16.5,2.5);
	glVertex2f(16.75,3.0);
	glVertex2f(17.0,3.5);
	glVertex2f(17.5,3.75);
	glVertex2f(18.0,4.0);
	glVertex2f(18.5,4.0);
	glVertex2f(19.0,3.75);
	glVertex2f(19.5,3.5);
	glVertex2f(19.75,3.0);
	glVertex2f(20.0,2.5);
	glVertex2f(21.0,2.5);
	glVertex2f(21.0,4.0);
	glVertex2f(21.5,4.0);
	glVertex2f(21.0,4.5);
	glVertex2f(20.0,5.0);
	glVertex2f(15.0,5.0);
	glVertex2f(14.0,5.5);
	glVertex2f(13.0,6.0);
	glVertex2f(12.0,6.5);
	glVertex2f(11.0,7.0);
	glVertex2f(6.0,7.0);
	glVertex2f(5.0,6.5);
	glVertex2f(4.5,6.25);
	glVertex2f(4.25,6.0);
	glVertex2f(4.0,5.75);
	glVertex2f(3.5,5.5);
	glVertex2f(3.0,5.5);
	glVertex2f(1.9,5.45);
	glVertex2f(1.8,5.4);
	glVertex2f(1.7,5.35);
	glVertex2f(1.6,5.3);
	glVertex2f(1.5,5.25);
	glVertex2f(1.4,5.15);
	glVertex2f(1.3,5.0);
	glVertex2f(1.2,4.85);
	glVertex2f(1.1,4.7);
	glVertex2f(1.0,4.3);
	glVertex2f(1.0,3.2);
	glVertex2f(1.1,3.05);
	glVertex2f(1.2,2.9);
	glVertex2f(1.3,2.9);
	glVertex2f(1.4,2.75);
	glVertex2f(1.5,2.65);
	glVertex2f(1.6,2.6);
	glVertex2f(1.7,2.55);
	glVertex2f(1.8,2.5);
	glVertex2f(1.9,2.45);
	glVertex2f(2.0,2.5);
	glEnd();
	//tsonh
	glColor3f(1.0,1.0,1.0); 
	glBegin(GL_POLYGON);
	glVertex2f(5.0,5.0);
	glVertex2f(14.0,5.0);
	glVertex2f(11.5,6.5);
	glVertex2f(10.5,6.75);
	glVertex2f(7.0,6.75);
	glEnd();
	// 2 duguinii deegvvrh goyliin zuraas
	glColor3f(0.0,0.0,0.0); 
	glBegin(GL_LINE_LOOP);
	glVertex2f(2.5,2.5);
	glVertex2f(3.0,3.5);
	glVertex2f(3.5,3.75);
	glVertex2f(4.0,4.0);
	glVertex2f(4.5,4.0);
	glVertex2f(5.0,3.75);
	glVertex2f(5.5,3.5);
	glVertex2f(5.75,3.0);
	glVertex2f(6.0,2.5);
	glVertex2f(16.5,2.5);
	glVertex2f(16.75,3.0);
	glVertex2f(17.0,3.5);
	glVertex2f(17.5,3.75);
	glVertex2f(18.0,4.0);
	glVertex2f(18.5,4.0);
	glVertex2f(19.0,3.75);
	glVertex2f(19.5,3.5);
	glVertex2f(19.75,3.0);
	glVertex2f(20.0,2.5);
	glVertex2f(21.0,2.5);
	glVertex2f(21.0,4.0);
	glVertex2f(21.5,4.0);
	glVertex2f(21.0,4.5);
	glVertex2f(20.0,5.0);
	glVertex2f(15.0,5.0);
	glVertex2f(14.0,5.5);
	glVertex2f(13.0,6.0);
	glVertex2f(12.0,6.5);
	glVertex2f(11.0,7.0);
	glVertex2f(6.0,7.0);
	glVertex2f(5.0,6.5);
	glVertex2f(4.5,6.25);
	glVertex2f(4.25,6.0);
	glVertex2f(4.0,5.75);
	glVertex2f(3.5,5.5);
	glVertex2f(3.0,5.5);
	glVertex2f(1.9,5.45);
	glVertex2f(1.8,5.4);
	glVertex2f(1.7,5.35);
	glVertex2f(1.6,5.3);
	glVertex2f(1.5,5.25);
	glVertex2f(1.4,5.15);
	glVertex2f(1.3,5.0);
	glVertex2f(1.2,4.85);
	glVertex2f(1.1,4.7);
	glVertex2f(1.0,4.3);
	glVertex2f(1.0,3.2);
	glVertex2f(1.1,3.05);
	glVertex2f(1.2,2.9);
	glVertex2f(1.3,2.9);
	glVertex2f(1.4,2.75);
	glVertex2f(1.5,2.65);
	glVertex2f(1.6,2.6);
	glVertex2f(1.7,2.55);
	glVertex2f(1.8,2.5);
	glVertex2f(1.9,2.45);
	glVertex2f(2.0,2.5);
	glEnd();
	//haalgan deegvvrh goylin zuraas
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINE_LOOP); 
	glVertex2f(8.0,3.0);
	glVertex2f(16.0,3.0);
	glVertex2f(16.5,3.5);
	glVertex2f(17.0,4.0);
	glVertex2f(16.5,4.25);
	glVertex2f(16.0,4.5);
	glVertex2f(15.0,4.5);
	glVertex2f(15.0,5.0);
	glVertex2f(14.0,5.0);
	glVertex2f(11.5,6.5);
	glVertex2f(10.5,6.75);
	glVertex2f(7.0,6.75);
	glVertex2f(5.0,5.0);
	glVertex2f(7.0,5.0);
	glVertex2f(6.5,4.5);
	glEnd();


	glBegin(GL_LINES); 
	glVertex2d(7.0,5.0);
	glVertex2d(15.0,5.0);
	glEnd();

	glColor3f(0.0,0.0,0.0);  
	glBegin(GL_LINES);
	glVertex2d(15.0,4.0);
	glVertex2d(17.0,4.0);
	glEnd();

	glColor3f(0.0,0.0,0.0); 
	glBegin(GL_LINES);
	glVertex2d(15.0,3.5);
	glVertex2d(16.5,3.5);
	glEnd();

	glColor3f(0.0,0.0,0.0); 
	glBegin(GL_LINES);
	glVertex2d(15.0,5.0);
	glVertex2d(14.0,3.0);
	glEnd();

	glColor3f(0.0,0.0,0.0); 
	glBegin(GL_LINES);
	glVertex2d(12.0,5.0);
	glVertex2d(12.0,6.2);
	glEnd();

	glColor3f(0.0,0.0,0.0); 
	glBegin(GL_LINES);
	glVertex2d(7.0,5.0);
	glVertex2d(7.0,6.7);
	glEnd();

	// hoid dugui
	glBegin(GL_POLYGON); 
	glVertex2f(3.0,2.5);
	glVertex2f(3.0,2.6);
	glVertex2f(3.15,3.1);
	glVertex2f(3.2,3.2);
	glVertex2f(3.3,3.35);
	glVertex2f(3.4,3.4);
	glVertex2f(3.5,3.45);
	glVertex2f(3.6,3.55);
	glVertex2f(3.7,3.6);
	glVertex2f(3.8,3.63);
	glVertex2f(4.0,3.65);
	glVertex2f(4.2,3.7);
	glVertex2f(4.4,3.7);
	glVertex2f(4.6,3.65);
	glVertex2f(4.8,3.55);
	glVertex2f(5.0,3.45);
	glVertex2f(5.1,3.4);
	glVertex2f(5.2,3.25);
	glVertex2f(5.3,3.2);
	glVertex2f(5.4,3.0);
	glVertex2f(5.5,2.5);

	glVertex2f(5.45,2.15);
	glVertex2f(5.4,1.9);
	glVertex2f(5.35,1.8);
	glVertex2f(5.2,1.6);
	glVertex2f(5.0,1.5);
	glVertex2f(4.9,1.4);
	glVertex2f(4.7,1.3);
	glVertex2f(4.6,1.27);
	glVertex2f(4.4,1.25);
	glVertex2f(4.0,1.25);
	glVertex2f(3.9,1.3);
	glVertex2f(3.75,1.35);
	glVertex2f(3.6,1.4);
	glVertex2f(3.45,1.55);
	glVertex2f(3.3,1.7);
	glVertex2f(3.2,1.8);
	glVertex2f(3.1,2.2);
	glEnd();

	// urd dugui
	glBegin(GL_POLYGON);
	glVertex2f(17.0,2.5);
	glVertex2f(17.0,2.6);
	glVertex2f(17.15,3.1);
	glVertex2f(17.2,3.2);
	glVertex2f(17.3,3.35);
	glVertex2f(17.4,3.4);
	glVertex2f(17.5,3.45);
	glVertex2f(17.6,3.55);
	glVertex2f(17.7,3.6);
	glVertex2f(17.8,3.63);
	glVertex2f(18.0,3.65);
	glVertex2f(18.2,3.7);
	glVertex2f(18.4,3.7);
	glVertex2f(18.6,3.65);
	glVertex2f(18.8,3.55);
	glVertex2f(19.0,3.45);
	glVertex2f(19.1,3.4);
	glVertex2f(19.2,3.25);
	glVertex2f(19.3,3.2);
	glVertex2f(19.4,3.0);

	glVertex2f(19.5,2.5);
	glVertex2f(19.45,2.15);
	glVertex2f(19.4,1.9);
	glVertex2f(19.35,1.8);
	glVertex2f(19.2,1.6);
	glVertex2f(19.0,1.5);
	glVertex2f(18.9,1.4);
	glVertex2f(18.7,1.3);
	glVertex2f(18.6,1.27);
	glVertex2f(18.4,1.25);
	glVertex2f(18.0,1.25);
	glVertex2f(17.9,1.3);
	glVertex2f(17.75,1.35);
	glVertex2f(17.6,1.4);
	glVertex2f(17.45,1.55);
	glVertex2f(17.3,1.7);
	glVertex2f(17.2,1.8);
	glVertex2f(17.1,2.2);
	glEnd();
	glPopMatrix();
}
void car2()
{
	glPushMatrix(); 
	glTranslated(b-2000,190.0,0.0);
	glScaled(20.0,20.0,0.0);
	glColor3f(1.0,1.0,0.4);
	//mashinii hvree
	glBegin(GL_POLYGON);
	glVertex2f(2.5,2.5);
	glVertex2f(3.0,3.5);
	glVertex2f(3.5,3.75);
	glVertex2f(4.0,4.0);
	glVertex2f(4.5,4.0);
	glVertex2f(5.0,3.75);
	glVertex2f(5.5,3.5);
	glVertex2f(5.75,3.0);
	glVertex2f(6.0,2.5);
	glVertex2f(16.5,2.5);
	glVertex2f(16.75,3.0);
	glVertex2f(17.0,3.5);
	glVertex2f(17.5,3.75);
	glVertex2f(18.0,4.0);
	glVertex2f(18.5,4.0);
	glVertex2f(19.0,3.75);
	glVertex2f(19.5,3.5);
	glVertex2f(19.75,3.0);
	glVertex2f(20.0,2.5);
	glVertex2f(21.0,2.5);
	glVertex2f(21.0,4.0);
	glVertex2f(21.5,4.0);
	glVertex2f(21.0,4.5);
	glVertex2f(20.0,5.0);
	glVertex2f(15.0,5.0);
	glVertex2f(14.0,5.5);
	glVertex2f(13.0,6.0);
	glVertex2f(12.0,6.5);
	glVertex2f(11.0,7.0);
	glVertex2f(6.0,7.0);
	glVertex2f(5.0,6.5);
	glVertex2f(4.5,6.25);
	glVertex2f(4.25,6.0);
	glVertex2f(4.0,5.75);
	glVertex2f(3.5,5.5);
	glVertex2f(3.0,5.5);
	glVertex2f(1.9,5.45);
	glVertex2f(1.8,5.4);
	glVertex2f(1.7,5.35);
	glVertex2f(1.6,5.3);
	glVertex2f(1.5,5.25);
	glVertex2f(1.4,5.15);
	glVertex2f(1.3,5.0);
	glVertex2f(1.2,4.85);
	glVertex2f(1.1,4.7);
	glVertex2f(1.0,4.3);
	glVertex2f(1.0,3.2);
	glVertex2f(1.1,3.05);
	glVertex2f(1.2,2.9);
	glVertex2f(1.3,2.9);
	glVertex2f(1.4,2.75);
	glVertex2f(1.5,2.65);
	glVertex2f(1.6,2.6);
	glVertex2f(1.7,2.55);
	glVertex2f(1.8,2.5);
	glVertex2f(1.9,2.45);
	glVertex2f(2.0,2.5);
	glEnd();

	// tsonhnii heseg
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(5.0,5.0);
	glVertex2f(14.0,5.0);
	glVertex2f(11.5,6.5);
	glVertex2f(10.5,6.75);
	glVertex2f(7.0,6.75);
	glEnd();
	// 2 duguinii deegvvrh goyliin zuraas
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(2.5,2.5);
	glVertex2f(3.0,3.5);
	glVertex2f(3.5,3.75);
	glVertex2f(4.0,4.0);
	glVertex2f(4.5,4.0);
	glVertex2f(5.0,3.75);
	glVertex2f(5.5,3.5);
	glVertex2f(5.75,3.0);
	glVertex2f(6.0,2.5);
	glVertex2f(16.5,2.5);
	glVertex2f(16.75,3.0);
	glVertex2f(17.0,3.5);
	glVertex2f(17.5,3.75);
	glVertex2f(18.0,4.0);
	glVertex2f(18.5,4.0);
	glVertex2f(19.0,3.75);
	glVertex2f(19.5,3.5);
	glVertex2f(19.75,3.0);
	glVertex2f(20.0,2.5);
	glVertex2f(21.0,2.5);
	glVertex2f(21.0,4.0);
	glVertex2f(21.5,4.0);
	glVertex2f(21.0,4.5);
	glVertex2f(20.0,5.0);
	glVertex2f(15.0,5.0);
	glVertex2f(14.0,5.5);
	glVertex2f(13.0,6.0);
	glVertex2f(12.0,6.5);
	glVertex2f(11.0,7.0);
	glVertex2f(6.0,7.0);
	glVertex2f(5.0,6.5);
	glVertex2f(4.5,6.25);
	glVertex2f(4.25,6.0);
	glVertex2f(4.0,5.75);
	glVertex2f(3.5,5.5);
	glVertex2f(3.0,5.5);
	glVertex2f(1.9,5.45);
	glVertex2f(1.8,5.4);
	glVertex2f(1.7,5.35);
	glVertex2f(1.6,5.3);
	glVertex2f(1.5,5.25);
	glVertex2f(1.4,5.15);
	glVertex2f(1.3,5.0);
	glVertex2f(1.2,4.85);
	glVertex2f(1.1,4.7);
	glVertex2f(1.0,4.3);
	glVertex2f(1.0,3.2);
	glVertex2f(1.1,3.05);
	glVertex2f(1.2,2.9);
	glVertex2f(1.3,2.9);
	glVertex2f(1.4,2.75);
	glVertex2f(1.5,2.65);
	glVertex2f(1.6,2.6);
	glVertex2f(1.7,2.55);
	glVertex2f(1.8,2.5);
	glVertex2f(1.9,2.45);
	glVertex2f(2.0,2.5);
	glEnd();

	// haalgan deerh goyliin zuraasnuud
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(8.0,3.0);
	glVertex2f(16.0,3.0);
	glVertex2f(16.5,3.5);
	glVertex2f(17.0,4.0);
	glVertex2f(16.5,4.25);
	glVertex2f(16.0,4.5);
	glVertex2f(15.0,4.5);
	glVertex2f(15.0,5.0);
	glVertex2f(14.0,5.0);
	glVertex2f(11.5,6.5);
	glVertex2f(10.5,6.75);
	glVertex2f(7.0,6.75);
	glVertex2f(5.0,5.0);
	glVertex2f(7.0,5.0);
	glVertex2f(6.5,4.5);
	glEnd();


	glBegin(GL_LINES); 
	glVertex2d(7.0,5.0);
	glVertex2d(15.0,5.0);
	glEnd();

	glColor3f(0.0,0.0,0.0);  
	glBegin(GL_LINES);
	glVertex2d(15.0,4.0);
	glVertex2d(17.0,4.0);
	glEnd();

	glColor3f(0.0,0.0,0.0); 
	glBegin(GL_LINES);
	glVertex2d(15.0,3.5);
	glVertex2d(16.5,3.5);
	glEnd();

	glColor3f(0.0,0.0,0.0); 
	glBegin(GL_LINES);
	glVertex2d(15.0,5.0);
	glVertex2d(14.0,3.0);
	glEnd();

	glColor3f(0.0,0.0,0.0); 
	glBegin(GL_LINES);
	glVertex2d(12.0,5.0);
	glVertex2d(12.0,6.2);
	glEnd();

	glColor3f(0.0,0.0,0.0); 
	glBegin(GL_LINES);
	glVertex2d(7.0,5.0);
	glVertex2d(7.0,6.7);
	glEnd();
	
	glBegin(GL_POLYGON); // hoid dugui
	glVertex2f(3.0,2.5);
	glVertex2f(3.0,2.6);
	glVertex2f(3.15,3.1);
	glVertex2f(3.2,3.2);
	glVertex2f(3.3,3.35);
	glVertex2f(3.4,3.4);
	glVertex2f(3.5,3.45);
	glVertex2f(3.6,3.55);
	glVertex2f(3.7,3.6);
	glVertex2f(3.8,3.63);
	glVertex2f(4.0,3.65);
	glVertex2f(4.2,3.7);
	glVertex2f(4.4,3.7);
	glVertex2f(4.6,3.65);
	glVertex2f(4.8,3.55);
	glVertex2f(5.0,3.45);
	glVertex2f(5.1,3.4);
	glVertex2f(5.2,3.25);
	glVertex2f(5.3,3.2);
	glVertex2f(5.4,3.0);
	glVertex2f(5.5,2.5);

	glVertex2f(5.45,2.15);
	glVertex2f(5.4,1.9);
	glVertex2f(5.35,1.8);
	glVertex2f(5.2,1.6);
	glVertex2f(5.0,1.5);
	glVertex2f(4.9,1.4);
	glVertex2f(4.7,1.3);
	glVertex2f(4.6,1.27);
	glVertex2f(4.4,1.25);
	glVertex2f(4.0,1.25);
	glVertex2f(3.9,1.3);
	glVertex2f(3.75,1.35);
	glVertex2f(3.6,1.4);
	glVertex2f(3.45,1.55);
	glVertex2f(3.3,1.7);
	glVertex2f(3.2,1.8);
	glVertex2f(3.1,2.2);
	glEnd();


	glBegin(GL_POLYGON); //urd dugui
	glVertex2f(17.0,2.5);
	glVertex2f(17.0,2.6);
	glVertex2f(17.15,3.1);
	glVertex2f(17.2,3.2);
	glVertex2f(17.3,3.35);
	glVertex2f(17.4,3.4);
	glVertex2f(17.5,3.45);
	glVertex2f(17.6,3.55);
	glVertex2f(17.7,3.6);
	glVertex2f(17.8,3.63);
	glVertex2f(18.0,3.65);
	glVertex2f(18.2,3.7);
	glVertex2f(18.4,3.7);
	glVertex2f(18.6,3.65);
	glVertex2f(18.8,3.55);
	glVertex2f(19.0,3.45);
	glVertex2f(19.1,3.4);
	glVertex2f(19.2,3.25);
	glVertex2f(19.3,3.2);
	glVertex2f(19.4,3.0);

	glVertex2f(19.5,2.5);
	glVertex2f(19.45,2.15);
	glVertex2f(19.4,1.9);
	glVertex2f(19.35,1.8);
	glVertex2f(19.2,1.6);
	glVertex2f(19.0,1.5);
	glVertex2f(18.9,1.4);
	glVertex2f(18.7,1.3);
	glVertex2f(18.6,1.27);
	glVertex2f(18.4,1.25);
	glVertex2f(18.0,1.25);
	glVertex2f(17.9,1.3);
	glVertex2f(17.75,1.35);
	glVertex2f(17.6,1.4);
	glVertex2f(17.45,1.55);
	glVertex2f(17.3,1.7);
	glVertex2f(17.2,1.8);
	glVertex2f(17.1,2.2);
	glEnd();
	glPopMatrix();
}

void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,1346.0,0.0,728.0);
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1346,728);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Traffic signal");

	glutDisplayFunc(mydisplay);
	glutKeyboardFunc(myKeyboard); 
	glutMouseFunc(myMouse);

	myinit();
	glutMainLoop();
}