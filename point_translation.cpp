#include <GL/glut.h>
#include<iostream>

using namespace std;
typedef float matrix3x3 [3][3];
typedef float matrix3x1 [3][1];
matrix3x1 p;
matrix3x3 T;
float tx,ty;
void makeunit()
{
 //for (int i=0;i<3;i++) //this will also  work 
 //for (int j=0;i<3;j++)
 //m[i][j] = (i==j);
 T[0][0]=1;T[0][1]=0;T[0][2]=0;
 T[1][0]=0;T[1][1]=1;T[1][2]=0;
 T[2][0]=0;T[2][1]=0;T[2][2]=1;
}

void multiply(matrix3x3 a,matrix3x1 b)
{

matrix3x1 t;
for(int i=0;i<3;i++)
for(int j=0;j<1;j++)
t[i][j]=(a[i][0]*b[0][j])+(a[i][1]*b[1][j])+(a[i][2]*b[2][j]);
p[0][0]=t[0][0];
p[1][0]=t[1][0];
p[2][0]=t[2][0];
   
}
void translate()
{

makeunit();
T[0][2]=tx;
T[1][2]=ty;
multiply(T,p);
}

void displayMe()
{
       
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,400.0,0.0,300.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(4);
    glBegin(GL_POINTS);
    glColor3f(0.0,1.0,0.0);
    glVertex2i(p[0][0],p[1][0]);
    glEnd();
    translate();
    
    glBegin(GL_POINTS);
    glColor3f(1.0,0.0,0.0);
    glVertex2i(p[0][0],p[1][0]);
    glEnd();
    
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    int x,y;
    cout<<"Enter point coordinate a x and y --"<<endl;cin>>x>>y;
    cout<<"Enter translation factor tx and ty --"<<endl;cin>>tx>>ty;
    
    p[0][0]=x;p[1][0]=y,p[2][0]=1; 
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("transformation");
    glClearColor(0.5,0.5,0.5,0.0);
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}
