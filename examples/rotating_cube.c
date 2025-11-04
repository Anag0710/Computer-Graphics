/* rotating_cube.c
   Simple rotating colored cube using GLUT/freeglut
*/
#ifdef _WIN32
#include <windows.h>
#endif
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

static float angleX = 25.0f, angleY = 40.0f, angleZ = 0.0f;

void drawCube(void)
{
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex3f(-0.5f,-0.5f,0.5f);
    glVertex3f(0.5f,-0.5f,0.5f);
    glVertex3f(0.5f,0.5f,0.5f);
    glVertex3f(-0.5f,0.5f,0.5f);
    glColor3f(0,1,0);
    glVertex3f(-0.5f,-0.5f,-0.5f);
    glVertex3f(-0.5f,0.5f,-0.5f);
    glVertex3f(0.5f,0.5f,-0.5f);
    glVertex3f(0.5f,-0.5f,-0.5f);
    glColor3f(0,0,1);
    glVertex3f(-0.5f,-0.5f,-0.5f);
    glVertex3f(-0.5f,-0.5f,0.5f);
    glVertex3f(-0.5f,0.5f,0.5f);
    glVertex3f(-0.5f,0.5f,-0.5f);
    glColor3f(1,1,0);
    glVertex3f(0.5f,-0.5f,-0.5f);
    glVertex3f(0.5f,0.5f,-0.5f);
    glVertex3f(0.5f,0.5f,0.5f);
    glVertex3f(0.5f,-0.5f,0.5f);
    glColor3f(1,0,1);
    glVertex3f(-0.5f,0.5f,-0.5f);
    glVertex3f(-0.5f,0.5f,0.5f);
    glVertex3f(0.5f,0.5f,0.5f);
    glVertex3f(0.5f,0.5f,-0.5f);
    glColor3f(0,1,1);
    glVertex3f(-0.5f,-0.5f,-0.5f);
    glVertex3f(0.5f,-0.5f,-0.5f);
    glVertex3f(0.5f,-0.5f,0.5f);
    glVertex3f(-0.5f,-0.5f,0.5f);
    glEnd();
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0,0,-3);
    glRotatef(angleX,1,0,0);
    glRotatef(angleY,0,1,0);
    glRotatef(angleZ,0,0,1);
    drawCube();
    glutSwapBuffers();
}

void idleFunc(void)
{
    angleX += 0.15f; angleY += 0.25f; angleZ += 0.10f;
    if (angleX>360) angleX-=360;
    if (angleY>360) angleY-=360;
    if (angleZ>360) angleZ-=360;
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
{
    (void)x; (void)y;
    if (key==27 || key=='q' || key=='Q') exit(0);
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(800,600);
    glutCreateWindow("rotating_cube.c");
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idleFunc);
    glutMainLoop();
    return 0;
}
