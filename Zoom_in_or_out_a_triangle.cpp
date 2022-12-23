#include <GL/glut.h>
#include<iostream>

using namespace std;
typedef float matrix3x3 [3][3];
typedef float matrix3x1 [3][1];
matrix3x1 p1,p2,p3;
matrix3x3 S;
float Sx,Sy;

void makeunit()
{
 //for (int i=0;i<3;i++)
 //for (int j=0;i<3;j++)
 //m[i][j] = (i==j);
 S[0][0]=1;S[0][1]=0;S[0][2]=0;
 S[1][0]=0;S[1][1]=1;S[1][2]=0;
 S[2][0]=0;S[2][1]=0;S[2][2]=1;
}

void multiply(matrix3x3 a,matrix3x1 b)
{

matrix3x1 t;
for(int i=0;i<3;i++)
for(int j=0;j<1;j++)
t[i][j]=(a[i][0]*b[0][j])+(a[i][1]*b[1][j])+(a[i][2]*b[2][j]);
b[0][0]=t[0][0];
b[1][0]=t[1][0];
b[2][0]=t[2][0];
   
}
void scale(matrix3x1 p)
{

makeunit();
S[0][0]=Sx;
S[1][1]=Sy;
multiply(S,p);
}

void displayMe()
{
       
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,1600.0,0.0,1200.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(4);
    glBegin(GL_TRIANGLES);
    glColor3f(0.0,1.0,0.0);
    glVertex2i(p1[0][0],p1[1][0]);
    glVertex2i(p2[0][0],p2[1][0]);
    glVertex2i(p3[0][0],p3[1][0]);
    glEnd();
    
    scale(p1);
    scale(p2);
    scale(p3);
    
    
    glBegin(GL_TRIANGLES);
    glColor3f(0.2,1.0,0.5);
    glVertex2i(p1[0][0],p1[1][0]);
    glVertex2i(p2[0][0],p2[1][0]);
    glVertex2i(p3[0][0],p3[1][0]);
    glEnd();
    
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);    
    p1[0][0]=90;p1[1][0]=90,p1[2][0]=1;
    p2[0][0]=200;p2[1][0]=400,p2[2][0]=1;
    p3[0][0]=400;p3[1][0]=90,p3[2][0]=1;
    cout<<"Any positive values can be assigned to the scaling factors sx and sy. Values less than 1 reduce the size of objects; values greater than 1 produce enlargements.Specifying a value of 1 for both sx and sy leaves the size of objects unchanged.When sx and sy are assigned the same value, a uniform scaling is produced,which maintains relative object proportions. Unequal values for sx and sy resultin a differential scaling\nEnter scaling factor Sx and Sy for translating square--\n";cin>>Sx>>Sy;
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(900, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("transformation");
    glClearColor(0.5,0.5,0.5,0.0);
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}
