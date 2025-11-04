/* spinning_pyramid.c
   Simple pyramid made of triangles that spins
*/
#ifdef _WIN32
#include <windows.h>
#endif
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

static float angle = 0.0f;

void drawPyramid(void)
{
    glBegin(GL_TRIANGLES);
    // front
    glColor3f(1,0,0); glVertex3f(0,0.8f,0);
    glColor3f(0,1,0); glVertex3f(-0.8f,-0.8f,0.8f);
    glColor3f(0,0,1); glVertex3f(0.8f,-0.8f,0.8f);
    // right
    glColor3f(1,0,1); glVertex3f(0,0.8f,0);
    glColor3f(0,1,1); glVertex3f(0.8f,-0.8f,0.8f);
    glColor3f(1,1,0); glVertex3f(0.8f,-0.8f,-0.8f);
    // back
    glColor3f(0.4f,0.6f,0.8f); glVertex3f(0,0.8f,0);
    glColor3f(0.2f,0.7f,0.3f); glVertex3f(0.8f,-0.8f,-0.8f);
    glColor3f(0.6f,0.2f,0.5f); glVertex3f(-0.8f,-0.8f,-0.8f);
    // left
    glColor3f(0.5f,0.5f,0.2f); glVertex3f(0,0.8f,0);
    glColor3f(0.3f,0.7f,0.9f); glVertex3f(-0.8f,-0.8f,-0.8f);
    glColor3f(0.9f,0.3f,0.6f); glVertex3f(-0.8f,-0.8f,0.8f);
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity(); glTranslatef(0,0,-4);
    glRotatef(angle,0,1,0);
    drawPyramid();
    glutSwapBuffers();
}

void idleFunc(void)
{
    angle += 0.5f; if (angle>360) angle-=360; glutPostRedisplay();
}

void reshape(int w,int h)
{
    if (h==0) h=1; glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION); glLoadIdentity(); gluPerspective(60.0,(double)w/h,0.1,100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv); glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(600,600); glutCreateWindow("spinning_pyramid.c");
    glEnable(GL_DEPTH_TEST); glutDisplayFunc(display); glutReshapeFunc(reshape);
    glutIdleFunc(idleFunc); glutMainLoop(); return 0; }
