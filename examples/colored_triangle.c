/* colored_triangle.c
   Simple 2D colored triangle using GLUT
*/
#ifdef _WIN32
#include <windows.h>
#endif
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glColor3f(1,0,0); glVertex2f(-0.8f,-0.8f);
    glColor3f(0,1,0); glVertex2f(0.8f,-0.8f);
    glColor3f(0,0,1); glVertex2f(0.0f,0.8f);
    glEnd();
    glutSwapBuffers();
}

void reshape(int w,int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION); glLoadIdentity();
    if (h==0) h=1; glOrtho(-1,1,-1,1,-1,1);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("colored_triangle.c");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
