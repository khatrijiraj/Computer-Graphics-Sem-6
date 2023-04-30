#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<math.h>

using namespace std;

int main()
{
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    int gd = DETECT, gm; /* request autodetection */
    initgraph(&gd, &gm, data); 
    int x[10], y[10], i;
    float put_x, put_y, t;
    cout<<"Enter x and y coordinates";
    for(i=0;i<4;i++)
    {
        cin>>x[i]>>y[i];
        putpixel(x[i],y[i],WHITE);
    }

    for(float j=0;j<=1;j=j+0.001)
    {
        put_x = pow(1-j,3)*x[0] + 3*j*pow(1-j,2)*x[1] + 3*j*j*(1-j)*x[2] + pow(j,3)*x[3];
        put_y = pow(1-j,3)*y[0] + 3*j*pow(1-j,2)*y[1] + 3*j*j*(1-j)*y[2] + pow(j,3)*y[3];
        putpixel(put_x,put_y,WHITE);
    }
    _getch();
    return 0;
}

//300 300
//400 450
//500 100
//600 300