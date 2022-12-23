#include <GL/glut.h>
#include <cmath>
#include<iostream>

using namespace std;
typedef double matrix3x3 [3][3];
typedef double matrix3x1 [3][1];
matrix3x1 p1,p2,p3;
matrix3x3 R;
double Redian;
int xr,yr;//pivot point or centroid of triangle

void makeunit()
{
 R[0][0]=1;R[0][1]=0;R[0][2]=0;
 R[1][0]=0;R[1][1]=1;R[1][2]=0;
 R[2][0]=0;R[2][1]=0;R[2][2]=1;
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
void pivot_rotation(matrix3x1 p)
{
makeunit();
R[0][0]=cos(Redian);R[0][1]=-(sin(Redian));R[0][2]=(xr*(1-cos(Redian))) + (yr*sin(Redian));

R[1][0]=sin(Redian);R[1][1]=cos(Redian);R[1][2]=(yr*(1-cos(Redian)))-(xr*sin(Redian));

multiply(R,p);
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
    
    pivot_rotation(p1);
    pivot_rotation(p2);
    pivot_rotation(p3);
    
    
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
    p1[0][0]=400;p1[1][0]=400,p1[2][0]=1;
    p2[0][0]=500;p2[1][0]=700,p2[2][0]=1;
    p3[0][0]=700;p3[1][0]=400,p3[2][0]=1;
    xr=(p1[0][0]+p2[0][0]+p3[0][0])/3;//centriod calculation
    yr=(p1[1][0]+p2[1][0]+p3[1][0])/3;
    
    int Degree;
    cout<<"Enter the Degree of rotetion in Degree format --";cin>>Degree;
    Redian= Degree*(3.14159/180);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(900, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("transformation");
    glClearColor(0.5,0.5,0.5,0.0);
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}
