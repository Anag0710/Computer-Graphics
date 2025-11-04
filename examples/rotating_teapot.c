/* rotating_teapot.c
   Simple rotating GLUT teapot example
*/
#ifdef _WIN32
#include <windows.h>
#endif
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

static float angle = 0.0f;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, -0.5f, -4.0f);
    glRotatef(angle, 0.0f, 1.0f, 0.0f);
    glColor3f(0.8f, 0.3f, 0.2f);
    glutSolidTeapot(1.0);
    glutSwapBuffers();
}

void idleFunc(void)
{
    angle += 0.4f;
    if (angle>360) angle-=360;
    glutPostRedisplay();
}

void reshape(int w,int h)
{
    if (h==0) h=1;
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0,(double)w/h,0.1,100.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key,int x,int y)
{ (void)x; (void)y; if (key==27) exit(0); }

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(640,480);
    glutCreateWindow("rotating_teapot.c");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idleFunc);
    glutMainLoop();
    return 0;
}
