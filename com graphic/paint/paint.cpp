#include <GL/glut.h>  
#include <stdlib.h>
float x, y, r, g, b;
void resize(GLsizei w, GLsizei h){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1000.0, 0.0, 1000.0);

    glViewport(0, 0, w, h);
}

void mouse(int button, int state, int mousex, int mousey){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        x = mousex;
        y = 1000-mousey;

        r = (rand()%9)/8;
        g = (rand()%9)/8;
        b = (rand()%9)/8;
    }
    glutPostRedisplay();
}

static void display(void)
{
    glColor3f(r, g, b); 
    glPointSize(15);

        glBegin(GL_POINTS);
            glVertex2f(x, y);
        glEnd();

    glFlush();

}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(50,50);

    glutCreateWindow("Paint"); 
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glutDisplayFunc(display);
    glutReshapeFunc(resize); 
    glutMouseFunc(mouse);

    
    glutMainLoop();
 
    return EXIT_SUCCESS;
}

