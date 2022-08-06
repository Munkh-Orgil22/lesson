 
#include <GL/glut.h>

float x_position = -20.0;
int state = 1;
void resize(GLsizei w, GLsizei h){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-20.0, 20.0, -20.0, 20.0);

    glViewport(0, 0, w, h);
    glMatrixMode(GL_MODELVIEW);
}


void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/60, timer, 0);
    switch(state)
    {
        case 1:
            if(x_position<18)
                x_position+=0.15;
            else
                state=-1;
            break;
        case -1:
            if(x_position>-20)
                x_position-=0.15;
            else
                state=1;
            break;
    }
}


static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glBegin(GL_POLYGON);
        glVertex2f(x_position, 1.0);
        glVertex2f(x_position, -1.0);
        glVertex2f(x_position+2.0, -1.0);
        glVertex2f(x_position+2.0, 1.0);
    glEnd();

    glutSwapBuffers();

}

 

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(50,50);

    glutCreateWindow("Animation"); 

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutTimerFunc(0, timer, 0);
 
    glutMainLoop();
 
    return EXIT_SUCCESS;
}

