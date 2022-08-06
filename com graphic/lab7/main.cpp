#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>

// Define a constant for the value of PI
#define GL_PI 3.1415f

// Rotation amounts
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;
static GLfloat xdiff = 0.0f;
static GLfloat ydiff = 0.0f;
static bool mouseDown = false;

struct color {
    int r, g, b;
};

typedef struct color color;


void MouseFunc(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;

        xdiff = x - yRot;
        ydiff = -y + xRot;
    }
    else
        mouseDown = false;
}


void MotionFunc(int x, int y)
{
    if (mouseDown)
    {
        yRot = x - xdiff;
        xRot = y + ydiff;

        glutPostRedisplay();
    }
}
// Reduces a normal vector specified as a set of three coordinates,
// to a unit normal vector of length one.
void ReduceToUnit(float vector[3])
{
    float length;

    // Calculate the length of the vector
    length = (float)sqrt((vector[0] * vector[0]) +
                         (vector[1] * vector[1]) +
                         (vector[2] * vector[2]));

    // Keep the program from blowing up by providing an exceptable
    // value for vectors that may calculated too close to zero.
    if (length == 0.0f)
        length = 1.0f;

    // Dividing each element by the length will result in a
    // unit normal vector.
    vector[0] /= length;
    vector[1] /= length;
    vector[2] /= length;
}

// Points p1, p2, & p3 specified in counter clock-wise order
void calcNormal(float v[3][3], float out[3])
{
    float v1[3], v2[3];
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
    out[x] = v1[y] * v2[z] - v1[z] * v2[y];
    out[y] = v1[z] * v2[x] - v1[x] * v2[z];
    out[z] = v1[x] * v2[y] - v1[y] * v2[x];

    // Normalize the vector (shorten length to one)
    ReduceToUnit(out);
}

// Creates the shaft of the bolt as a cylinder with one end
// closed.
void RenderShaft(void)
{
    float x, z, angle;              // Used to calculate cylinder wall
    float height = 200.0f;           // Height of the cylinder
    float diameter = 4.0f;         // Diameter of the cylinder
    float normal[3], corners[2][3]; // Storeage for vertex calculations
    float step = (3.1415f / 50.0f); // Approximate the cylinder wall with
                                    // 100 flat segments.

    // Set material color for head of screw
    glColor3f(1.5f, 0.5f, 0.5f);

    // First assemble the wall as 100 quadrilaterals formed by
    // placing adjoining Quads together
    glFrontFace(GL_CCW);
    glBegin(GL_QUAD_STRIP);

        // Go around and draw the sides
        for (angle = (2.0f * 3.1415f); angle > 0.0f; angle -= step)
        {
            // Calculate x and y position of the first vertex
            x = diameter * (float)sin(angle);
            z = diameter * (float)cos(angle);

            // Get the coordinate for this point and extrude the
            // length of the cylinder.
            corners[0][0] = x;
            corners[0][1] = -height / 2.0f - 55;
            corners[0][2] = z;

            corners[1][0] = x;
            corners[1][1] = height / 2.0f - 55;
            corners[1][2] = z;

            // Instead of using real normal to actual flat section
            // Use what the normal would be if the surface was really
            // curved. Since the cylinder goes up the Y axis, the normal
            // points from the Y axis out directly through each vertex.
            // Therefore we can use the vertex as the normal, as long as
            // we reduce it to unit length first and assume the y component
            // to be zero
            normal[0] = corners[1][0];
            normal[1] = 0.0f;
            normal[2] = corners[1][2];

            // Reduce to length of one and specify for this point
            ReduceToUnit(normal);
            glNormal3fv(normal);
            glVertex3fv(corners[0]);
            glVertex3fv(corners[1]);
        }

        // Make sure there are no gaps by extending last quad to
        // the original location
        glVertex3f(diameter * (float)sin(2.0f * 3.1415f),
                -height / 2.0f,
                diameter * (float)cos(2.0f * 3.1415f));

        glVertex3f(diameter * (float)sin(2.0f * 3.1415f),
                height / 2.0f,
                diameter * (float)cos(2.0f * 3.1415f));

    glEnd(); // Done with cylinder sides

    // Begin a new triangle fan to cover the bottom
    glBegin(GL_TRIANGLE_FAN);
    // Normal points down the Y axis
        glNormal3f(0.0f, -1.0f, 0.0f);

        // Center of fan is at the origin
        glVertex3f(0.0f, -height / 2.0f, 0.0f);

        // Spin around matching step size of cylinder wall
        for (angle = (2.0f * 3.1415f); angle > 0.0f; angle -= step)
        {
            // Calculate x and y position of the next vertex
            x = diameter * (float)sin(angle);
            z = diameter * (float)cos(angle);

            // Specify the next vertex for the triangle fan
            glVertex3f(x, -height / 2.0f, z);
        }

        // Be sure loop is closed by specifiying initial vertex
        // on arc as the last too
        glVertex3f(diameter * (float)sin(2.0f * 3.1415f),
                -height / 2.0f,
                diameter * (float)cos(2.0f * 3.1415f));
    glEnd();
}

// Creates the head of the bolt
void RenderHead(void)
{
    float x, y, angle;              // Calculated positions
    float height = -1.0f;           // Thickness of the head
    float diameter = 60.0f;         // Diameter of the head
    float normal[3], corners[4][3]; // Storeage of vertices and normals
    float step = (3.1415f / 10.0f);  // step = 1/6th of a circle = hexagon
    float col = 180;
    // Set material color for head of bolt

    glColor3f(1.5f, 0.5f, 0.5f);
    // Begin a new triangle fan to cover the top
    glFrontFace(GL_CCW);
    glBegin(GL_TRIANGLE_FAN);

    // All the normals for the top of the bolt point straight up
    // the z axis.
    glNormal3f(0.0f, 0.0f, 1.0f);

    // Center of fan is at the origin
    glVertex3f(0.0f, 0.0f, height / 2.0f);

    // Divide the circle up into 6 sections and start dropping
    // points to specify the fan. We appear to be winding this
    // fan backwards. This has the effect of reversing the winding
    // of what would have been a CW wound primative. Avoiding a state
    // change with glFrontFace().

    // First and Last vertex closes the fan
    glVertex3f(0.0f, diameter, height / 2.0f);

    for (angle = (2.34f * 3.1415f) - step; angle >= 0; angle -= step)
    {
        // Calculate x and y position of the next vertex
        x = diameter * (float)sin(angle);
        y = diameter * (float)cos(angle);
        col-=60.0f;
        // Specify the next vertex for the triangle fan
        glVertex3f(x, y, height / 2.0f);
    }


    for (angle = 0.0f; angle < (2.34f * 3.1415f); angle += step)
    {
        // Calculate x and y position of the next vertex
        x = diameter * (float)sin(angle);
        y = diameter * (float)cos(angle);
        col+=60.0f;
        // Specify the next vertex for the triangle fan
        glVertex3f(x, y, height / 2.0f);
        
    }

    // Last vertex closes the fan
    // Done drawing the fan that covers the bottom
    glEnd();
    glFrontFace(GL_CW);

    // Begin a new triangle fan to cover the bottom
    glBegin(GL_QUAD_STRIP);

    // Normal for bottom points straight down the negative z axis

    // points to specify the fan
    for (angle = 0.0f; angle < (2.34f * 3.1415f); angle += step)
    {
        // Calculate x and y position of the next vertex
        x = diameter * (float)sin(angle);
        y = diameter * (float)cos(angle);
        col-=60.0f;

        // Specify the next vertex for the triangle fan
        glVertex3f(x, y, 0);
        glVertex3f(2 * x, 2 * y, -30.0f);

    }
    for (angle = (2.34f * 3.1415f) - step; angle >= 0; angle -= step)
    {
        // Calculate x and y position of the next vertex
        x = diameter * (float)sin(angle);
        y = diameter * (float)cos(angle);
        col+=60.0f;
        // Specify the next vertex for the triangle fan
        glVertex3f(x, y, 0);
        glVertex3f(2 * x, 2 * y, -30.0f);

    }

    // Last vertex, used to close the fan

    // Done drawing the fan that covers the bottom
    glEnd();

    // Build the sides out of triangles (two each). Each face
    // will consist of two triangles arranged to form a
   
}

// Called to draw scene
void RenderScene(void)
{
    // Clear the window with current clearing color
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Save the matrix state
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    // Rotate about x and y axes
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
    glRotatef(yRot, 0.0f, 0.0f, 1.0f);

    // Render just the Thread of the nut
    RenderShaft();

    glPushMatrix();
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    // RenderThread();

    glTranslatef(0.0f, 0.0f, 45.0f);
    RenderHead();
    glPopMatrix();

    glPopMatrix();

    // Swap buffers
    glutSwapBuffers();
}

// This function does any needed initialization on the rendering
// context.
void SetupRC()
{
    // Light values and coordinates
    GLfloat ambientLight[] = {0.4f, 0.4f, 0.4f, 1.0f};
    GLfloat diffuseLight[] = {0.7f, 0.7f, 0.7f, 1.0f};
    GLfloat specular[] = {0.9f, 0.9f, 0.9f, 1.0f};
    GLfloat lightPos[] = {-50.0f, 200.0f, 200.0f, 1.0f};
    GLfloat specref[] = {0.6f, 0.6f, 0.6f, 1.0f};

    glEnable(GL_DEPTH_TEST); // Hidden surface removal
    glEnable(GL_CULL_FACE);  // Do not calculate inside of solid object
    glFrontFace(GL_CCW);

    // Enable lighting
    glEnable(GL_LIGHTING);

    // Setup light 0
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

    // Position and turn on the light
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glEnable(GL_LIGHT0);

    // Enable color tracking
    glEnable(GL_COLOR_MATERIAL);

    // Set Material properties to follow glColor values
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    // All materials hereafter have full specular reflectivity
    // with a moderate shine
    glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
    glMateriali(GL_FRONT, GL_SHININESS, 64);

    // Black background
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

///////////////////////////////////////////////////////////////////////////////
// Process arrow keys
void SpecialKeys(int key, int x, int y)
{
    if (key == GLUT_KEY_UP)
        xRot -= 5.0f;

    if (key == GLUT_KEY_DOWN)
        xRot += 5.0f;

    if (key == GLUT_KEY_LEFT)
        yRot -= 5.0f;

    if (key == GLUT_KEY_RIGHT)
        yRot += 5.0f;

    if (key > 356.0f)
        xRot = 0.0f;

    if (key < -1.0f)
        xRot = 355.0f;

    if (key > 356.0f)
        yRot = 0.0f;

    if (key < -1.0f)
        yRot = 355.0f;

    // Refresh the Window
    glutPostRedisplay();
}

void ChangeSize(int w, int h)
{
    GLfloat nRange = 200.0f;

    // Prevent a divide by zero
    if (h == 0)
        h = 1;

    // Set Viewport to window dimensions
    glViewport(0, 0, w, h);

    // Reset coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Establish clipping volume (left, right, bottom, top, near, far)
    if (w <= h)
        glOrtho(-nRange, nRange, -nRange * h / w, nRange * h / w, -nRange * 2.0f, nRange * 2.0f);
    else
        glOrtho(-nRange * w / h, nRange * w / h, -nRange, nRange, -nRange * 2.0f, nRange * 2.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Completed Bolt");
    glutReshapeFunc(ChangeSize);
    glutSpecialFunc(SpecialKeys);
    glutDisplayFunc(RenderScene);
    glutMotionFunc(MotionFunc);
    glutMouseFunc(MouseFunc);
    SetupRC();
    glutMainLoop();

    return 0;
}
