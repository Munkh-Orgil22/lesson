#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;
bool mouseDown = false;
float xdiff = 0.0f;
float ydiff = 0.0f;
struct point{
GLfloat x, y, z;
};
struct face{
int a, b, c;
};
struct face f[100001];
struct point p[50001];
void loadPoint()
{
    FILE *fp;
    int read, i=1;
    GLfloat x, y, z;
    char ch, path[100] = "dragon.obj";
    fp = fopen(path, "r");
    if (!fp)
  {
        printf("can't open file dragon.obj\n");
        exit(1);
    }
    {
    while (!(feof(fp)))
    {
        read = fscanf(fp, "%c %f %f %f", &ch, &x, &y, &z);
        if (ch == 'v')
        {
            p[i].x = x;
            p[i].y = y;
            p[i].z = z;
            i++;
        }
    }
  }
    glEndList();
}
void loadFace()
{
    FILE *fp;
    int read, i=1, a, b, c;
    char ch, path[100] = "dragon.obj";
    fp = fopen(path, "r");
    if (!fp)
    {
    printf("can't open file dragon.obj\n");
    exit(1);
    }
    {
    while (!(feof(fp)))
    {
    read = fscanf(fp, "%c %d %d %d", &ch, &a, &b, &c);
    if (ch == 'f')
    {
    f[i].a = a;
    f[i].b = b;
    f[i].c = c;
    i++;
    }
    }
    }
    glEndList();
    }
void init (){
    glClearColor(0.0, 0.0, 0.0, 1);
    GLfloat ambient[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat diffuse[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};

    //copper
    //GLfloat matamb[] = {0.19125, 0.0735, 0.0225, 1.0};
    //GLfloat matdif[] = {0.7038, 0.27048, 0.0828, 1.0};
    //GLfloat matspe[] = {0.256777, 0.137622, 0.086014, 1.0};
    //GLfloat shin = 12.8;

    //brass
    GLfloat matamb[] = {0.329412, 0.223529, 0.027451, 1.0};
    GLfloat matdif[] = {0.780392, 0.568527, 0.113725, 1.0};
    GLfloat matspe[] = {0.992157, 0.941176, 0.807843, 1.0};
    GLfloat shin = 27.89743616;
    // gold
    // GLfloat matamb[] = {0.24725, 0.1995, 0.0745, 1.0};
    // GLfloat matdif[] = {0.75164, 0.60648, 0.22648, 1.0};
    // GLfloat matspe[] = {0.628281, 0.555802, 0.366065, 1.0};
    // GLfloat shin = 51.2;
    //pearl
    // GLfloat matamb[] = {0.25, 0.20725, 0.20725, 1.0};
    // GLfloat matdif[] = {0.18275, 0.17, 0.22525, 1.0};
    // GLfloat matspe[] = {0.332741, 0.328634, 0.346435, 1.0};
    // GLfloat shin = 38.4;
    // Ruby
    // GLfloat matamb[] = {0.1745, 0.01175, 0.01175, 1.0};
    // GLfloat matdif[] = {0.61424, 0.04136, 0.04136, 1.0};
    // GLfloat matspe[] = {0.727811, 0.626959, 0.626959, 1.0};
    // GLfloat shin = 76.8;
    GLfloat position[] = {20.0, 20.0, 20.0, 0.0};
    GLfloat lmodel_ambient[] = {0.5, 0.5, 0.5, 1.0};
    GLfloat local_view[] = {0.0};
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

    glFrontFace(GL_CW);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE);
    glEnable(GL_DEPTH_TEST);
    glMaterialfv(GL_FRONT, GL_AMBIENT, matamb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, matdif);
    glMaterialfv(GL_FRONT, GL_SPECULAR, matspe);
    glMaterialf(GL_FRONT, GL_SHININESS, shin);

    loadPoint();
    loadFace();
}
void display(void){
 glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 GLfloat xnorm, ynorm, znorm;

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 0.0f, 1.0f);
//dragon
 for(int i=1; i<100001; i++){

 //bunny
 //for(int i=1; i<277903; i++){
 glBegin(GL_TRIANGLES);
 //normal oloh
    xnorm = (p[f[i].b].y - p[f[i].a].y) * (p[f[i].c].z - p[f[i].a].z) - (p[f[i].c].y - p[f[i].a].y) * (p[f[i].b].z -
    p[f[i].a].z);
    ynorm = (p[f[i].b].z - p[f[i].a].z) * (p[f[i].c].x - p[f[i].a].x) - (p[f[i].b].x - p[f[i].a].x) * (p[f[i].c].z -
    p[f[i].a].z);
    znorm = (p[f[i].b].x - p[f[i].a].x) * (p[f[i].c].y - p[f[i].a].y) - (p[f[i].c].x - p[f[i].a].x) * (p[f[i].b].y -
    p[f[i].a].y);
    glNormal3f(xnorm, ynorm, znorm);
    glVertex3f( p [f[i].a].x, p [f[i].a].y, p [f[i].a].z );
    glVertex3f( p [f[i].b].x, p [f[i].b].y, p [f[i].b].z );
    glVertex3f( p [f[i].c].x, p [f[i].c].y, p [f[i].c].z );

 glEnd();
 }

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

    xRot = (GLfloat)((const int)xRot % 360);
    yRot = (GLfloat)((const int)yRot % 360);
// Refresh the Window
glutPostRedisplay();
}
void reshape(int w, int h){
    GLfloat fAspect;
    if (h==0) h=1;
    // dragon
    // glOrtho(0, 0, 0, 0, 0, 0);
    //bunny
    // glOrtho(-25, 25, -25, 25, -25, 25);
    glViewport(0, 0, w, h);
    fAspect = (GLfloat)w/(GLfloat)h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

 //dragon
gluPerspective(10.0, fAspect, 1.0, 30.0);
 gluLookAt( 10.0, -3.0, 10.0,
0.0, 0.0, 0.0,
0.0, -1.0, 0.0);

 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
}
void mouse(int button, int state, int x, int y){
if(state == GLUT_DOWN && button == GLUT_LEFT_BUTTON){
mouseDown = true;
xdiff = x - yRot;
ydiff = -y + xRot;
}
else
mouseDown = false;
}
void mouseMotion(int x, int y)
{
if (mouseDown)
{
yRot = x - xdiff;
xRot = y + ydiff;
glutPostRedisplay();
}
}
int main (int argc, char** argv){
 glutInit(&argc, argv);
 glutInitWindowSize(500, 500);
 glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
 glutCreateWindow("dragon");
 loadPoint();
 loadFace();
 init();
 glutDisplayFunc(display);
 glutReshapeFunc(reshape);
 glutSpecialFunc(SpecialKeys);
 glutMouseFunc(mouse);
 glutMotionFunc(mouseMotion);
 glutMainLoop();
 return 0;
}