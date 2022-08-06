#include <iostream>
#include <fstream>
#include <time.h>
#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>


#include <GL/gl.h>
// #include <gl/glu.h>
#include <GL/glut.h>



#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"



using namespace std;



double width, height;


GLfloat diffX = 0.0;
GLfloat diffY = 0.0;



GLfloat rotateX = 0.0;
GLfloat rotateY = 0.0;



bool mouseClicked = false;



double vertexes[2000][3];
double vertexTexture[2000][2];
double vertexNormal[2000][3];
int face[1000000][4][3];



int num_texture = 0;
int textureImg[1024][1024][3];
unsigned char *data;




void parseFace(char face1[], char face2[], char face3[], char face4[], int j)
{
int arg[3];
int counter = 0;
char strinBuild[255];
for(int i = 0; i < strlen(face1); i++)
{
if(face1[i]=='/')
{
arg[counter] = atoi(strinBuild);
counter++;
strinBuild[0] = '\0';
continue;
}
else if(i==strlen(face1)-1)
{
strncat(strinBuild, &face1[i], 1);
arg[counter] = atoi(strinBuild);
counter++;
strinBuild[0] = '\0';
}
else
strncat(strinBuild, &face1[i], 1);
}
strinBuild[0] = '\0';
counter = 0;
face[j][0][0] = arg[0];
face[j][0][1] = arg[1];
face[j][0][2] = arg[2];
for(int i = 0; i < strlen(face2); i++)
{
if(face2[i]== '/')
{
arg[counter] = atoi(strinBuild);
counter++;
strinBuild[0] = '\0';
continue;
}
else if(i==strlen(face2)-1)
{
strncat(strinBuild, &face2[i], 1);
arg[counter] = atoi(strinBuild);
counter++;
strinBuild[0] = '\0';
}
else
strncat(strinBuild, &face2[i], 1);
}
counter = 0;
strinBuild[0] = '\0';
face[j][1][0] = arg[0];
face[j][1][1] = arg[1];
face[j][1][2] = arg[2];
for(int i = 0; i < strlen(face3); i++)
{
if(face3[i]== '/')
{
arg[counter] = atoi(strinBuild);
counter++;
strinBuild[0] = '\0';
continue;
}
else if(i==strlen(face3)-1)
{
strncat(strinBuild, &face3[i], 1);
arg[counter] = atoi(strinBuild);
counter++;
strinBuild[0] = '\0';
}
else
strncat(strinBuild, &face3[i], 1);
}
counter = 0;
strinBuild[0] = '\0';
face[j][2][0] = arg[0];
face[j][2][1] = arg[1];
face[j][2][2] = arg[2];





for(int i = 0; i < strlen(face4); i++)
{
if (face4[i]== '/')
{
arg[counter] = atoi(strinBuild);
counter++;
strinBuild[0] = '\0';
continue;
}
else if(i==strlen(face4)-1)
{
strncat(strinBuild, &face4[i], 1);
arg[counter] = atoi(strinBuild);
counter++;
strinBuild[0] = '\0';
}
else
strncat(strinBuild, &face4[i], 1);
}
counter = 0;
strinBuild[0] = '\0';
face[j][3][0] = arg[0];
face[j][3][1] = arg[1];
face[j][3][2] = arg[2];





}





void readFileV2()
{
FILE *fp;
fp = fopen("C:/Users/User/Desktop/init/lab10texture/Character.obj", "r");
char store[255];
char *ptr;
//vertexed
double x, y, z;
//faces
char face1[255], face2[255], face3[255], face4[255];
//textures
double vt1, vt2;
//normal vectors
double vn1, vn2, vn3;
bool vertex = false, texture = false, normal = false, face = false;
int i = 0, j = 0, k = 0, l = 0;
int counter = 0;
while(!feof(fp))
{
fscanf(fp, "%s", store);
// printf("%s\n", store);
if(strcmp(store,"v")==0)
{
vertex = true;
counter = 0;
}
else if (strcmp(store,"vt")==0)
{
counter = 0;
texture = true;
}
else if (strcmp(store,"vn")==0)
{
counter = 0;
normal = true;
}
else if (strcmp(store,"f")==0)
{
counter = 0;
face = true;





}
else
{
if(vertex)
{
if(counter==1)
x = strtod(store, &ptr);
else if(counter==2)
y = strtod(store, &ptr);
else if(counter==3)
z = strtod(store, &ptr);
}
else if(texture)
{
if(counter==1)
vt1 = strtod(store, &ptr);
else if(counter==2)
vt2 = strtod(store, &ptr);
}
else if(normal)
{
if(counter==1)
vn1 = strtod(store, &ptr);
else if(counter==2)
vn2 = strtod(store, &ptr);
else if(counter==3)
vn3 = strtod(store, &ptr);
}
else if(face)
{
if(counter==1)
strcpy(face1, store);
else if(counter==2)
strcpy(face2, store);
else if(counter==3)
strcpy(face3, store);
else if(counter==4)
{
strcpy(face4, store);
}
}
}
if(counter==2 && texture)
{
vertexTexture[i][0] = vt1;
vertexTexture[i][1] = vt2;
i++;
texture = false;
}
else if(counter==3 && vertex)
{
vertexes[j][0] = x;
vertexes[j][1] = y;
vertexes[j][2] = z;
j++;
vertex = false;
}
else if(counter==3 && normal)
{
vertexNormal[k][0] = vn1;
vertexNormal[k][1] = vn2;
vertexNormal[k][2] = vn3;
k++;
normal = false;
}
else if(counter==4 && face)
{
parseFace(face1, face2, face3, face4, l);
l++;
face = false;
}
counter++;
}
fclose(fp);
}





int LoadBitMap(char *filename)
{
int i, j=0; //Index variables
FILE *l_file; //File pointer
unsigned char *l_texture; //The pointer to the memory zone in which we will load the texture



// windows.h gives us these types to work with the Bitmap files
BITMAPFILEHEADER fileheader;
BITMAPINFOHEADER infoheader;
RGBTRIPLE rgb;





num_texture++; // The counter of the current texture is increased





if( (l_file = fopen(filename, "rb"))==NULL) return (-1); // Open the file for reading



// fread(&fileheader, sizeof(fileheader), 1, l_file); // Read the fileheader



// fseek(l_file, sizeof(fileheader), SEEK_SET); // Jump the fileheader
// fread(&infoheader, sizeof(infoheader), 1, l_file); // and read the infoheader





// Now we need to allocate the memory for our image (width * height * color deep)
// l_texture = (byte *) malloc(infoheader.biWidth * infoheader.biHeight * 4);
// And fill it with zeros
// memset(l_texture, 0, infoheader.biWidth * infoheader.biHeight * 4);



// At this point we can read every pixel of the image
for (i=0; i < infoheader.biWidth*infoheader.biHeight; i++)
{
// We load an RGB value from the file
// fread(&rgb, sizeof(rgb), 1, l_file);





// And store it
l_texture[j+0] = rgb.rgbtRed; // Red component
l_texture[j+1] = rgb.rgbtGreen; // Green component
l_texture[j+2] = rgb.rgbtBlue; // Blue component
l_texture[j+3] = 255; // Alpha value
j += 4; // Go to the next position
}





fclose(l_file); // Closes the file stream



glBindTexture(GL_TEXTURE_2D, num_texture); // Bind the ID texture specified by the 2nd parameter





// The next commands sets the texture parameters
glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_LINEAR); // If the u,v coordinates overflow the range 0,1 the image is repeated
glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // The magnification function ("linear" produces better results)
glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST); //The minifying function





glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); // We don't combine the color with the original surface color, use only the texture map.





// Finally we define the 2d texture
glTexImage2D(GL_TEXTURE_2D, 0, 4, infoheader.biWidth, infoheader.biHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, l_texture);





// And create 2d mipmaps for the minifying function
gluBuild2DMipmaps(GL_TEXTURE_2D, 4, infoheader.biWidth, infoheader.biHeight, GL_RGBA, GL_UNSIGNED_BYTE, l_texture);





free(l_texture); // Free the memory we used to load the texture





return (num_texture); // Returns the current texture OpenGL ID
}





void ReduceToUnit(float vector[3])
{
float length;





// Calculate the length of the vector
length = (float)sqrt((vector[0]*vector[0]) +
(vector[1]*vector[1]) +
(vector[2]*vector[2]));





// Keep the program from blowing up by providing an exceptable
// value for vectors that may calculated too close to zero.
if(length == 0.0f)
length = 1.0f;





// Dividing each element by the length will result in a
// unit normal vector.
vector[0] /= length;
vector[1] /= length;
vector[2] /= length;
}





void calcNormal(float v[3][3], float out[3])
{
float v1[3],v2[3];
static const int x = 0;
static const int y = 1;
static const int z = 2;





// Calculate two vectors from the three points
v1[x] = v[0][x] - v[1][x];
v1[y] = v[0][y] - v[1][y];
v1[z] = v[0][z] - v[1][z];





v2[x] = v[1][x] - v[2][x];
v2[y] = v[1][y] - v[2][y];
v2[z] = v[1][z] - v[2][z];





// Take the cross product of the two vectors to get
// the normal vector which will be stored in out
out[x] = v1[y]*v2[z] - v1[z]*v2[y];
out[y] = v1[z]*v2[x] - v1[x]*v2[z];
out[z] = v1[x]*v2[y] - v1[y]*v2[x];





// Normalize the vector (shorten length to one)
ReduceToUnit(out);
}





void rotateCamera()
{
glRotatef(rotateX, 1.0f, 0.0f, 0.0f);
glRotatef(rotateY, 0.0f, 1.0f, 0.0f);
}





void drawCharacter()
{



glBindTexture(GL_TEXTURE_2D, 1);
for(int i = 0; i <2000; i++)
{
glBegin(GL_POLYGON);
glNormal3f(vertexNormal[face[i][0][2]-1][0], vertexNormal[face[i][0][2]-1][1], vertexNormal[face[i][0][2]-1][2]);
glTexCoord2f(vertexTexture[face[i][0][1]-1][0], 1 - vertexTexture[face[i][0][1]-1][1]);
glVertex3f(vertexes[face[i][0][0]-1][0], vertexes[face[i][0][0]-1][1], vertexes[face[i][0][0]-1][2]);





glNormal3f(vertexNormal[face[i][1][2]-1][0], vertexNormal[face[i][1][2]-1][1], vertexNormal[face[i][1][2]-1][2]);
glTexCoord2f(vertexTexture[face[i][1][1]-1][0], 1 - vertexTexture[face[i][1][1]-1][1]);
glVertex3f(vertexes[face[i][1][0]-1][0], vertexes[face[i][1][0]-1][1], vertexes[face[i][1][0]-1][2]);





glNormal3f(vertexNormal[face[i][2][2]-1][0], vertexNormal[face[i][2][2]-1][1], vertexNormal[face[i][2][2]-1][2]);
glTexCoord2f(vertexTexture[face[i][2][1]-1][0], 1 - vertexTexture[face[i][2][1]-1][1]);
glVertex3f(vertexes[face[i][2][0]-1][0], vertexes[face[i][2][0]-1][1], vertexes[face[i][2][0]-1][2]);





glNormal3f(vertexNormal[face[i][3][2]-1][0], vertexNormal[face[i][3][2]-1][1], vertexNormal[face[i][3][2]-1][2]);
glTexCoord2f(vertexTexture[face[i][3][1]-1][0], 1 - vertexTexture[face[i][3][1]-1][1]);
glVertex3f(vertexes[face[i][3][0]-1][0], vertexes[face[i][3][0]-1][1], vertexes[face[i][3][0]-1][2]);
glEnd();
}
}






void display()
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
rotateCamera();
drawCharacter();
// glutSolidSphere(0.6, 32, 32);
glutSwapBuffers();
}






void setup()
{



GLfloat ambientLight[] = {0.4f, 0.4f, 0.4f, 1.0f };
GLfloat diffuseLight[] = {0.7f, 0.7f, 0.7f, 1.0f };
GLfloat specular[] = { 0.9f, 0.9f, 0.9f, 1.0f};
GLfloat lightPos[] = { 15.0f, 10.0f, 1.0f, 1.0f };
GLfloat specref[] = { 0.6f, 0.6f, 0.6f, 1.0f };



// readFile();
readFileV2();
// qobj = gluNewQuadric();





glEnable(GL_DEPTH_TEST); // Hidden surface removal
glEnable(GL_CULL_FACE); // Do not calculate inside of solid object
glFrontFace(GL_CCW);
glShadeModel(GL_SMOOTH);




// Enable lighting
glEnable(GL_LIGHTING);
glShadeModel(GL_FLAT);
glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);





// Setup light 0
glLightModelfv(GL_LIGHT_MODEL_AMBIENT,ambientLight);
glLightfv(GL_LIGHT0,GL_AMBIENT,ambientLight);
glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuseLight);
glLightfv(GL_LIGHT0,GL_SPECULAR,specular);





// Position and turn on the light
glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
glEnable(GL_LIGHT0);





// Enable color tracking
glEnable(GL_COLOR_MATERIAL);



// Set Material properties to follow glColor values
glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
int width, height, n;
//"C:/Users/User/Desktop/init/lab10texture/Texture.jpg"
data = stbi_load("C:/Users/User/Desktop/init/lab10texture/Texture.jpg", &width, &height, &n, 3);



glEnable(GL_TEXTURE_2D);
glBindTexture(GL_TEXTURE_2D, 1);



glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);





glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);





glTexImage2D(GL_TEXTURE_2D, 0, 4, 1024, 1024, 0, GL_RGB, GL_UNSIGNED_BYTE, data);





gluBuild2DMipmaps(GL_TEXTURE_2D, 4, 1024, 1024, GL_RGB, GL_UNSIGNED_BYTE, data);



stbi_image_free(data);



glClearColor(0.0f, 0.0f, 0.0f, 1.0f);



}





void resize(GLsizei w, GLsizei h)
{
GLfloat nRange = 15.0f;
width = w;
height = h;



glViewport(0, 0, (GLsizei) width, (GLsizei) height);



glMatrixMode(GL_PROJECTION);
glLoadIdentity();



if (w <= h)
glOrtho (-nRange, nRange, -nRange*h/w, nRange*h/w, -nRange*2.0f, nRange*2.0f);
else
glOrtho (-nRange*w/h, nRange*w/h, -nRange, nRange, -nRange*2.0f, nRange*2.0f);



glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}





void mouse(int button, int state, int x, int y)
{
if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
{
mouseClicked = true;
diffX = x - rotateY;
diffY = -y + rotateX;
}
else
{
mouseClicked = false;
}
}





void motion(int x, int y)
{



if(mouseClicked == true)
{
rotateY = x - diffX;
rotateX = y + diffY;
glutPostRedisplay();
}
}





void specialKeys(int key, int x, int y)
{
if(key == GLUT_KEY_UP)
rotateX-= 5.0f;





if(key == GLUT_KEY_DOWN)
rotateX += 5.0f;





if(key == GLUT_KEY_LEFT)
rotateY -= 5.0f;





if(key == GLUT_KEY_RIGHT)
rotateY += 5.0f;





if(key > 359.0f)
rotateX = 0.0f;





if(key < -1.0f)
rotateX = 355.0f;





if(key > 359.0f)
rotateY = 0.0f;





if(key < -1.0f)
rotateY = 355.0f;



glutPostRedisplay();
}



int main(int argc, char** argv)
{



glutInit(&argc, argv);
glutInitWindowSize(600, 600);
glutInitWindowPosition(100, 100);
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
glutCreateWindow("Lab 10 - Texture");



setup();



glutDisplayFunc(display);
glutReshapeFunc(resize);



glutMouseFunc(mouse);
glutMotionFunc(motion);
glutSpecialFunc(specialKeys);



glutMainLoop();
return 0;
}