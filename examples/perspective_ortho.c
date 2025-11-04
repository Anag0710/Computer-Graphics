/* perspective_ortho.c
   Toggle between perspective and orthographic projection with spacebar
*/
#ifdef _WIN32
#include <windows.h>
#endif
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

int usePerspective = 1;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity(); glTranslatef(0,0,-4);
    glColor3f(0.4f,0.8f,0.4f); glutSolidCube(1.2);
    glutSwapBuffers();
}

void reshape(int w,int h){ if (h==0) h=1; glViewport(0,0,w,h); glMatrixMode(GL_PROJECTION); glLoadIdentity(); if (usePerspective) gluPerspective(60.0,(double)w/h,0.1,100.0); else glOrtho(-2,2,-2,2,-10,10); glMatrixMode(GL_MODELVIEW); }

void keyboard(unsigned char k,int x,int y){ (void)x;(void)y; if (k==27) exit(0); if (k==' ') { usePerspective = !usePerspective; reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT)); glutPostRedisplay(); } }

int main(int argc,char** argv){ glutInit(&argc,argv); glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH); glutInitWindowSize(600,600); glutCreateWindow("perspective_ortho.c - press space to toggle"); glEnable(GL_DEPTH_TEST); glutDisplayFunc(display); glutReshapeFunc(reshape); glutKeyboardFunc(keyboard); glutMainLoop(); return 0; }
