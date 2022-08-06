#include <GL/glut.h>

bool mouseDown;
float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;

void resize(GLsizei w, GLsizei h){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-20.0, 20.0, -20.0, 20.0, -20.0, 20.0);

    glViewport(0, 0, w, h);
    glMatrixMode(GL_MODELVIEW);
}

void display () {

    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(1.5, 0.0, 0.5);


     glRotatef(xrot, 1.0f, 0.0f, 0.0f);
     glRotatef(yrot, 0.0f, 1.0f, 0.0f);

    glutWireTeapot(10.0);

    glFlush();


}

void mouse(int button, int state, int x, int y)
{
if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
{
mouseDown = true;

xdiff = x - yrot;
ydiff = -y + xrot;
}
else
mouseDown = false;
}

void mouseMotion(int x, int y)
{
if (mouseDown)
{
yrot = x - xdiff;
xrot = y + ydiff;

glutPostRedisplay();
}
}


int main ( int argc, char * argv[] ) {

    glutInit(&argc,argv);

    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutCreateWindow("lab5");
    glutDisplayFunc(display);
    glutReshapeFunc(resize);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);

    glutMainLoop();
}