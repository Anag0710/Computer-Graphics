/* axes_grid.c
   Draw simple XYZ axes and a grid to help visualize 3D space
*/
#ifdef _WIN32
#include <windows.h>
#endif
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void drawGrid(int size)
{
    glBegin(GL_LINES);
    for (int i=-size;i<=size;i++){
        glColor3f(0.4f,0.4f,0.4f);
        glVertex3f((float)i,0,-(float)size); glVertex3f((float)i,0,(float)size);
        glVertex3f(-(float)size,0,(float)i); glVertex3f((float)size,0,(float)i);
    }
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity(); glTranslatef(0,-0.5f,-6);
    // axes
    glBegin(GL_LINES);
    glColor3f(1,0,0); glVertex3f(0,0,0); glVertex3f(2,0,0);
    glColor3f(0,1,0); glVertex3f(0,0,0); glVertex3f(0,2,0);
    glColor3f(0,0,1); glVertex3f(0,0,0); glVertex3f(0,0,2);
    glEnd();
    drawGrid(10);
    glutSwapBuffers();
}

void reshape(int w,int h){ if (h==0) h=1; glViewport(0,0,w,h); glMatrixMode(GL_PROJECTION); glLoadIdentity(); gluPerspective(60.0,(double)w/h,0.1,100.0); glMatrixMode(GL_MODELVIEW); }

int main(int argc,char** argv){ glutInit(&argc,argv); glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH); glutInitWindowSize(800,600); glutCreateWindow("axes_grid.c"); glEnable(GL_DEPTH_TEST); glutDisplayFunc(display); glutReshapeFunc(reshape); glutMainLoop(); return 0; }
