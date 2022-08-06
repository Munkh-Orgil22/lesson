 
#include <GL/glut.h>  
#include <math.h>


static void circle(void)
{

    glClear(GL_COLOR_BUFFER_BIT);
    int number = 40;
    
    float radius = 0.4f;
    float twopi = 2.0 * 3.14;
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.0f, 0.0f); 

    for(int i=0; i <= number; i++ ){
        glVertex2f(radius * cosf(i * twopi / number), radius * sinf(i * twopi / number));
    }
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

