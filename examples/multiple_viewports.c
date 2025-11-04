/* multiple_viewports.c
   Demonstrates two viewports: left perspective, right orthographic
*/
#ifdef _WIN32
#include <windows.h>
#endif
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void drawScene(void)
{
    glColor3f(0.8f,0.2f,0.2f); glutSolidTeapot(0.7);
}

void display(void)
{
    int w = glutGet(GLUT_WINDOW_WIDTH);
    int h = glutGet(GLUT_WINDOW_HEIGHT);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    // left - perspective
    glViewport(0,0,w/2,h);
    glMatrixMode(GL_PROJECTION); glLoadIdentity(); gluPerspective(60.0,(double)(w/2)/h,0.1,100.0);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity(); glTranslatef(0,0,-3);
    drawScene();

    // right - ortho
    glViewport(w/2,0,w/2,h);
    glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(-2,2,-2,2,-10,10);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity(); glTranslatef(0,0,-1);
    drawScene();

    glutSwapBuffers();
}

void reshape(int w,int h){ if (h==0) h=1; glViewport(0,0,w,h); }

int main(int argc,char** argv){ glutInit(&argc,argv); glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH); glutInitWindowSize(800,400); glutCreateWindow("multiple_viewports.c"); glEnable(GL_DEPTH_TEST); glutDisplayFunc(display); glutReshapeFunc(reshape); glutMainLoop(); return 0; }
