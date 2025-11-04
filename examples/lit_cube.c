/* lit_cube.c
   A cube lit by a single directional light (demonstrates normals and lighting)
*/
#ifdef _WIN32
#include <windows.h>
#endif
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void drawLitCube(void)
{
    glBegin(GL_QUADS);
    // front
    glNormal3f(0,0,1);
    glVertex3f(-0.5f,-0.5f,0.5f); glVertex3f(0.5f,-0.5f,0.5f);
    glVertex3f(0.5f,0.5f,0.5f); glVertex3f(-0.5f,0.5f,0.5f);
    // back
    glNormal3f(0,0,-1);
    glVertex3f(-0.5f,-0.5f,-0.5f); glVertex3f(-0.5f,0.5f,-0.5f);
    glVertex3f(0.5f,0.5f,-0.5f); glVertex3f(0.5f,-0.5f,-0.5f);
    // left
    glNormal3f(-1,0,0);
    glVertex3f(-0.5f,-0.5f,-0.5f); glVertex3f(-0.5f,-0.5f,0.5f);
    glVertex3f(-0.5f,0.5f,0.5f); glVertex3f(-0.5f,0.5f,-0.5f);
    // right
    glNormal3f(1,0,0);
    glVertex3f(0.5f,-0.5f,-0.5f); glVertex3f(0.5f,0.5f,-0.5f);
    glVertex3f(0.5f,0.5f,0.5f); glVertex3f(0.5f,-0.5f,0.5f);
    // top
    glNormal3f(0,1,0);
    glVertex3f(-0.5f,0.5f,-0.5f); glVertex3f(-0.5f,0.5f,0.5f);
    glVertex3f(0.5f,0.5f,0.5f); glVertex3f(0.5f,0.5f,-0.5f);
    // bottom
    glNormal3f(0,-1,0);
    glVertex3f(-0.5f,-0.5f,-0.5f); glVertex3f(0.5f,-0.5f,-0.5f);
    glVertex3f(0.5f,-0.5f,0.5f); glVertex3f(-0.5f,-0.5f,0.5f);
    glEnd();
}

float angle=0;
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity(); glTranslatef(0,0,-4);
    glRotatef(angle,1,1,0);
    drawLitCube(); glutSwapBuffers();
}

void idleFunc(void){ angle+=0.3f; if (angle>360) angle-=360; glutPostRedisplay(); }

void reshape(int w,int h){ if(h==0) h=1; glViewport(0,0,w,h); glMatrixMode(GL_PROJECTION); glLoadIdentity(); gluPerspective(60.0,(double)w/h,0.1,100.0); glMatrixMode(GL_MODELVIEW); }

int main(int argc,char** argv)
{
    glutInit(&argc,argv); glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(700,500); glutCreateWindow("lit_cube.c");
    glEnable(GL_DEPTH_TEST); glEnable(GL_LIGHTING); glEnable(GL_LIGHT0);
    GLfloat lightpos[] = { 1.0f, 1.0f, 1.0f, 0.0f }; // directional
    GLfloat diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    GLfloat mat_diffuse[] = {0.6f,0.2f,0.2f,1.0f}; glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
    glutDisplayFunc(display); glutReshapeFunc(reshape); glutIdleFunc(idleFunc); glutMainLoop(); return 0;
}
