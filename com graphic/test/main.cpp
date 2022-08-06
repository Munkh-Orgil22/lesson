 
#include <GL/glut.h>  
#include <math.h>


static void circle(void)
{

    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glTranslatef(1, 0, 0);
    glRotatef(90, 1, 0, 0);
    glRotatef(90, 0, 1, 0);
    glBegin(GL_POINTS);
        glVertex3f(1, 0, 0);
    glEnd();
    
    glFlush();
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(50,50);

    glutCreateWindow("drawing circle"); 

    glutDisplayFunc(circle);
 

    glClearColor(0.0f,0.0f,0.0f, 1.0f);
    glutMainLoop();
 
    return EXIT_SUCCESS;
}

