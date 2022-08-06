 
#include <GL/glut.h>  
#include <math.h>

int n = 6, alpha = 0;
// float r = 0.1;
void idle(void){
    glutPostRedisplay();
}

// void specialKey(int key, int x, int y){
//     if(key == GLUT_KEY_UP){
//         r++;
//     }
//     else if(key == GLUT_KEY_DOWN){
//         r--;
//     }

// }

void keyboard( unsigned char key, int x, int y){
    switch(key){
        case 'r': case 'R':
            glColor3f(1.0f, 0.0f, 0.0f);
            break;
        case 'g': case 'G':
            glColor3f(0.0f, 1.0f, 0.0f);
            break;
        case 'b': case 'B':
            glColor3f(0.0f, 0.0f, 1.0f);
            break;
    }
}
static void shapes(void)
{
    //glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    for(float r = 0.1; r <= 0.5; r+=0.1){
        for(int i = 1; i <= n; i++){
            float x = r*cos(2*3.14*i/n);
            float y = r*sin(2*3.14*i/n);
            //alpha+=10;

            glVertex2f(x, y);
        }      
        
    }
    glEnd();   

    // glutSpecialFunc(specialKey);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idle);

    glFlush();
}

 

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(50,50);

    glutCreateWindow("drawing shapes"); 

    glutDisplayFunc(shapes);
 
    glutMainLoop();
 
    return EXIT_SUCCESS;
}

