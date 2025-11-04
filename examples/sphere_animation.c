/* sphere_animation.c
   Animated sphere bouncing along Y axis
*/
#ifdef _WIN32
#include <windows.h>
#endif
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

float y_pos = 0.0f; float vel = 0.02f;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity(); glTranslatef(0,y_pos,-6);
    glColor3f(0.9f,0.6f,0.2f); glutSolidSphere(1.0,32,32);
    glutSwapBuffers();
}

void idleFunc(void){ y_pos += vel; if (y_pos>1.5f || y_pos<-1.5f) vel = -vel; glutPostRedisplay(); }

void reshape(int w,int h){ if (h==0) h=1; glViewport(0,0,w,h); glMatrixMode(GL_PROJECTION); glLoadIdentity(); gluPerspective(60.0,(double)w/h,0.1,100.0); glMatrixMode(GL_MODELVIEW); }

int main(int argc,char** argv){ glutInit(&argc,argv); glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH); glutInitWindowSize(640,480); glutCreateWindow("sphere_animation.c"); glEnable(GL_DEPTH_TEST); glutDisplayFunc(display); glutReshapeFunc(reshape); glutIdleFunc(idleFunc); glutMainLoop(); return 0; }
