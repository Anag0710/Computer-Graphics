/* keyboard_cube.c
   Move the cube with arrow keys (simple interaction)
*/
#ifdef _WIN32
#include <windows.h>
#endif
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

static float tx=0, ty=0, angle=0;

void drawCube(void){ glutSolidCube(1.0); }

void display(void){ glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); glLoadIdentity(); glTranslatef(tx,ty,-5); glRotatef(angle,0,1,0); glColor3f(0.4f,0.7f,0.9f); drawCube(); glutSwapBuffers(); }

void special(int key,int x,int y){ (void)x;(void)y; if (key==GLUT_KEY_LEFT) tx -= 0.1f; if (key==GLUT_KEY_RIGHT) tx += 0.1f; if (key==GLUT_KEY_UP) ty += 0.1f; if (key==GLUT_KEY_DOWN) ty -= 0.1f; glutPostRedisplay(); }

void keyboard(unsigned char k,int x,int y){ (void)x;(void)y; if (k==27) exit(0); if (k=='r') angle+=10; if (angle>360) angle-=360; glutPostRedisplay(); }

void reshape(int w,int h){ if (h==0) h=1; glViewport(0,0,w,h); glMatrixMode(GL_PROJECTION); glLoadIdentity(); gluPerspective(60.0,(double)w/h,0.1,100.0); glMatrixMode(GL_MODELVIEW); }

int main(int argc,char** argv){ glutInit(&argc,argv); glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH); glutInitWindowSize(640,480); glutCreateWindow("keyboard_cube.c"); glEnable(GL_DEPTH_TEST); glutDisplayFunc(display); glutReshapeFunc(reshape); glutKeyboardFunc(keyboard); glutSpecialFunc(special); glutMainLoop(); return 0; }
