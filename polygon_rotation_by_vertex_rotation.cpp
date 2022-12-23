#include <GL/glut.h>
#include <cmath>
#include<iostream>

using namespace std;
typedef double matrix3x3 [3][3];
typedef double matrix3x1 [3][1];
matrix3x1 p1,p2,p3,p4,p5,p6;
matrix3x3 R;
double Redian;

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
void rotation(matrix3x1 p)
{
makeunit();
R[0][0]=cos(Redian);R[0][1]=-(sin(Redian));

R[1][0]=sin(Redian);R[1][1]=cos(Redian);

multiply(R,p);
}

void displayMe()
{
       
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,1600.0,0.0,1200.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(4);
    glBegin(GL_POLYGON);
    glColor3f(0.0,1.0,0.0);
    glVertex2i(p1[0][0],p1[1][0]);
    glVertex2i(p2[0][0],p2[1][0]);
    glVertex2i(p3[0][0],p3[1][0]);
    glVertex2i(p4[0][0],p4[1][0]);
    glVertex2i(p5[0][0],p5[1][0]);
    glVertex2i(p6[0][0],p6[1][0]);
    glEnd();
    
    rotation(p1);
    rotation(p2);
    rotation(p3);
    rotation(p4);
    rotation(p5);
    rotation(p6);
    
    
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.0,0.0);
    glVertex2i(p1[0][0],p1[1][0]);
    glVertex2i(p2[0][0],p2[1][0]);
    glVertex2i(p3[0][0],p3[1][0]);
    glVertex2i(p4[0][0],p4[1][0]);
    glVertex2i(p5[0][0],p5[1][0]);
    glVertex2i(p6[0][0],p6[1][0]);
    glEnd();
    
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);  
    p1[2][0]=1;p2[2][0]=1;p3[2][0]=1;p4[2][0]=1;p5[2][0]=1;p6[2][0]=1;
    
    cout<<"Enter 1 no point cordinate x and y\n";cin>>p1[0][0]>>p1[1][0];
    cout<<"Enter 2 no point cordinate x and y\n";cin>>p2[0][0]>>p2[1][0];
    cout<<"Enter 3 no point cordinate x and y\n";cin>>p3[0][0]>>p3[1][0];
    cout<<"Enter 4 no point cordinate x and y\n";cin>>p4[0][0]>>p4[1][0];
    cout<<"Enter 5 no point cordinate x and y\n";cin>>p5[0][0]>>p5[1][0];
    cout<<"Enter 6 no point cordinate x and y\n";cin>>p6[0][0]>>p6[1][0];
    
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
