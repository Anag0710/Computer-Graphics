/*
 File: 3D Animation.c
 Simple animated rotating cube using OpenGL + GLUT.
 Compile (Windows, with freeglut):
    gcc "3D Animation.c" -o cube -lfreeglut -lopengl32 -lglu32
 Compile (Linux):
    gcc "3D Animation.c" -o cube -lGL -lGLU -lglut
*/
#ifdef _WIN32
#include <windows.h>
#endif
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

static float angleX = 25.0f;
static float angleY = 40.0f;
static float angleZ = 0.0f;

void drawCube(void)
{
     glBegin(GL_QUADS);
     // Front face (z = +0.5)
     glColor3f(1.0f, 0.0f, 0.0f); // red
     glVertex3f(-0.5f, -0.5f,  0.5f);
     glVertex3f( 0.5f, -0.5f,  0.5f);
     glVertex3f( 0.5f,  0.5f,  0.5f);
     glVertex3f(-0.5f,  0.5f,  0.5f);

     // Back face (z = -0.5)
     glColor3f(0.0f, 1.0f, 0.0f); // green
     glVertex3f(-0.5f, -0.5f, -0.5f);
     glVertex3f(-0.5f,  0.5f, -0.5f);
     glVertex3f( 0.5f,  0.5f, -0.5f);
     glVertex3f( 0.5f, -0.5f, -0.5f);

     // Left face (x = -0.5)
     glColor3f(0.0f, 0.0f, 1.0f); // blue
     glVertex3f(-0.5f, -0.5f, -0.5f);
     glVertex3f(-0.5f, -0.5f,  0.5f);
     glVertex3f(-0.5f,  0.5f,  0.5f);
     glVertex3f(-0.5f,  0.5f, -0.5f);

     // Right face (x = +0.5)
     glColor3f(1.0f, 1.0f, 0.0f); // yellow
     glVertex3f( 0.5f, -0.5f, -0.5f);
     glVertex3f( 0.5f,  0.5f, -0.5f);
     glVertex3f( 0.5f,  0.5f,  0.5f);
     glVertex3f( 0.5f, -0.5f,  0.5f);

     // Top face (y = +0.5)
     glColor3f(1.0f, 0.0f, 1.0f); // magenta
     glVertex3f(-0.5f,  0.5f, -0.5f);
     glVertex3f(-0.5f,  0.5f,  0.5f);
     glVertex3f( 0.5f,  0.5f,  0.5f);
     glVertex3f( 0.5f,  0.5f, -0.5f);

     // Bottom face (y = -0.5)
     glColor3f(0.0f, 1.0f, 1.0f); // cyan
     glVertex3f(-0.5f, -0.5f, -0.5f);
     glVertex3f( 0.5f, -0.5f, -0.5f);
     glVertex3f( 0.5f, -0.5f,  0.5f);
     glVertex3f(-0.5f, -0.5f,  0.5f);
     glEnd();
}

void display(void)
{
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

     glLoadIdentity();
     // move back to view the cube
     glTranslatef(0.0f, 0.0f, -3.0f);

     // apply rotations
     glRotatef(angleX, 1.0f, 0.0f, 0.0f);
     glRotatef(angleY, 0.0f, 1.0f, 0.0f);
     glRotatef(angleZ, 0.0f, 0.0f, 1.0f);

     drawCube();

     glutSwapBuffers();
}

void idleFunc(void)
{
     // animate angles
     angleX += 0.15f;
     angleY += 0.25f;
     angleZ += 0.10f;
     if (angleX > 360.0f) angleX -= 360.0f;
     if (angleY > 360.0f) angleY -= 360.0f;
     if (angleZ > 360.0f) angleZ -= 360.0f;

     glutPostRedisplay();
}

void reshape(int w, int h)
{
     if (h == 0) h = 1;
     glViewport(0, 0, w, h);

     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluPerspective(60.0, (GLdouble)w / (GLdouble)h, 0.1, 100.0);

     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
     (void)x; (void)y;
     if (key == 27 || key == 'q' || key == 'Q') {
          /* Some freeglut headers/versions don't declare glutLeaveMainLoop,
             and it may not be available in all builds. Use exit() to quit. */
          exit(0);
     }
}

int main(int argc, char** argv)
{
     /* Initialize GLUT and create window */
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
     glutInitWindowSize(800, 600);
     glutInitWindowPosition(100, 100);
     glutCreateWindow("Rotating Cube");

     /* Enable depth testing for correct Z-ordering */
     glEnable(GL_DEPTH_TEST);

     /* Register callbacks */
     glutDisplayFunc(display);
     glutReshapeFunc(reshape);
     glutKeyboardFunc(keyboard);
     glutIdleFunc(idleFunc);

     /* Enter the GLUT main loop */
     glutMainLoop();

          return 0;
     }