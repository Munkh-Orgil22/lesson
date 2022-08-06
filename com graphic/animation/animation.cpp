#include <GL/glut.h>
#include <math.h>

float boatPos = 0.0, cloudPos = 0.0;

void moveBoat(int){
    glutPostRedisplay();
    glutTimerFunc(1700/1000, moveBoat, 0);
    if(boatPos<1700)
	{
        boatPos+=0.5;
	}
    else
	{
        boatPos = -600;
	}
}

void moveCloud(int){
    glutPostRedisplay();
    glutTimerFunc(1700/1000, moveCloud, 0);
    if(cloudPos<1700)
	{
        cloudPos+=0.15;
	}
    else
	{
        cloudPos = -600;
	}
}

void DrawCircle(float cx, float cy, float r, int num_segments){

		glBegin(GL_TRIANGLE_FAN);
		for (int i = 0; i < num_segments; i++)
		{
		float theta = 2.0f * 3.1415926f * float(i) / float(num_segments); 

		float x = r * cosf(theta);
		float y = r * sinf(theta); 

		glVertex2f(x + cx, y + cy); 

		}
		glEnd();
	}

void hills(){

		glColor3f(0.4, 0.4, 0.2);
		DrawCircle(200, 200, 500, 2000); 
		glColor3f(0.4, 0.4, 0.2);
		DrawCircle(800,200,500, 2000);
		glColor3f(0.4, 0.4, 0.2);
		DrawCircle(1400, 200, 500, 2000);
		glColor3f(0.4, 0.4, 0.2);
		DrawCircle(2000, 200, 500, 2000);

	}
void cloud(){

	glColor3f(1.0, 1.0, 1.0);

	DrawCircle(500 + cloudPos, 800, 60, 2000);
	DrawCircle(600 + cloudPos,800, 80, 2000);
	DrawCircle(700 + cloudPos, 800, 55, 2000);

	DrawCircle(1100 + cloudPos, 800, 60, 2000);
	DrawCircle(1200 + cloudPos,800, 80, 2000);
	DrawCircle(1300 + cloudPos, 800, 55, 2000);

}
	void sky(){

	glBegin(GL_POLYGON); //Sky  
	glColor3f(0.4, 0.5, 1.0);
	glVertex2i(0, 1500);
	glVertex2i(2000, 1500);
	glColor3f(0.7, 0.7, 1.0);
	glVertex2i(2000, 0);
	glVertex2i(0, 0);
	glEnd();
	  


	}
	void river(){

	glBegin(GL_POLYGON); // River
	glColor3f(0.2, 0.3, 1.1);
	glVertex2i(0, 0);
	glVertex2i(1700, 0);
	glVertex2i(1700, 500);
	glVertex2i(0, 500);
	glEnd();


	}
	
void boat()
	{
    glBegin(GL_QUADS); //ih bie 
	glColor3f(1.9, 0.0, 0.0);
	glVertex2i(100 + boatPos,200);
	glVertex2i(400 + boatPos, 200);
	glVertex2i(480 + boatPos,300);
	glVertex2i(50 + boatPos,300);
    glEnd();

	glBegin(GL_POLYGON); //dalbaa  
	glColor3f(0.0, 1.8, 0.5);
	glVertex2i(120 + boatPos,300);
	glVertex2i(240 + boatPos, 300);
	glVertex2i(190 + boatPos,360);
	glEnd();

	glBegin(GL_QUADS); //dalbaa
	glColor3f(1.0, 1.7, 0.0);
	glVertex2i(240 + boatPos,300);
	glVertex2i(420 + boatPos, 300);
	glVertex2i(350 + boatPos,360);
	glVertex2i(190 + boatPos,360);
    glEnd();
	
	}

void myDisplay(void)
	{     
		sky();
		hills();
		river();
		boat();
		cloud();
		glutSwapBuffers();
}

void myInit(void)
{
	glClearColor(0.0, 0.0, 1.0, 0.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glPointSize(0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1700.0, 0.0, 1000.0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1700, 1000);
	glutInitWindowPosition(0, 0);

	glutCreateWindow("Animation");
	glutDisplayFunc(myDisplay);
	glutTimerFunc(0, moveBoat, 0);
	glutTimerFunc(0, moveCloud, 0);
	myInit();
	glutMainLoop();
}