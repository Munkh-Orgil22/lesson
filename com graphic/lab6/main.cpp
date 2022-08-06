#include <GL/glut.h>

bool mouseDown;
float xRot = 0.0f;
float yRot = 0.0f;

void resize(GLsizei w, GLsizei h){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);

    glViewport(0, 0, w, h);
    glMatrixMode(GL_MODELVIEW);
}


void display () {

    GLUquadricObj *pObj;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    pObj = gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);

    glPushMatrix();
        glColor3f(0.9f, 0.5f, 0.9f);
        glRotatef(xRot, 1.0f, 0.0f, 0.0f);
        glRotatef(yRot, 0.0f, 0.0f, 1.0f);
		gluCylinder(pObj, 0.0f,0.1f, 0.4f, 4, 4);  
		gluSphere(pObj, 0.1f, 4, 4);
		glTranslatef(-0.5f, 0.0f, 0.0f);
		gluCylinder(pObj, 0.0f,0.1f, 0.4f, 4, 4);  
		gluSphere(pObj, 0.1f, 4, 4);
		glTranslatef(0.0f, -0.4f, 0.0f);
		gluCylinder(pObj, 0.0f,0.1f, 0.4f, 4, 4); 
		gluSphere(pObj, 0.1f, 4, 4);
		glTranslatef(0.5f, 0.0f, 0.0f);
		gluCylinder(pObj, 0.0f,0.1f, 0.4f, 4, 4); 
		gluSphere(pObj, 0.1f, 4, 4);
		glTranslatef(-0.25f, 0.2f, 0.4f);
		gluDisk(pObj, 0.0f, 0.5f, 26, 13);
		gluCylinder(pObj, 0.5f,0.5f, 0.1f, 26, 13); 
		gluCylinder(pObj, 0.0f,0.5f, 0.005f, 26, 13); 
		glTranslatef(0.0f, 0.0f, 0.1f);
		gluDisk(pObj, 0.0f, 0.5f, 26, 13);
		glTranslatef(0.0f, 0.0f, 0.3f);
        
    glPopMatrix();

    

    glutSwapBuffers();

}


void SpecialKeys(int key, int x, int y)
	{
	if(key == GLUT_KEY_UP)
		xRot-= 5.0f;

	if(key == GLUT_KEY_DOWN)
		xRot += 5.0f;

	if(key == GLUT_KEY_LEFT)
		yRot -= 5.0f;

	if(key == GLUT_KEY_RIGHT)
		yRot += 5.0f;

	if(key > 356.0f)
		xRot = 0.0f;

	if(key < -1.0f)
		xRot = 355.0f;

	if(key > 356.0f)
		yRot = 0.0f;

	if(key < -1.0f)
		yRot = 355.0f;

	// Refresh the Window
	glutPostRedisplay();
	}

int main ( int argc, char * argv[] ) {

    glutInit(&argc,argv);

    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutCreateWindow("lab6");
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutSpecialUpFunc(SpecialKeys);

    glutMainLoop();
}