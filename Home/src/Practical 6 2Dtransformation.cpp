#include <iostream>
#include <conio.h>
#include <graphics.h>
#include <math.h>

using namespace std;

int n, x_cor[20], y_cor[20], points[20], tx, ty, c, s, angle, x, y, sfx, sfy;

void input_coordinate()
{
    cout << "Enter the number of sides of the polygon: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the cordinate " << i << " of the polygon";
        cin >> x_cor[i] >> y_cor[i];
    }
}

void generate_polygon()
{
    for (int i = 0; i < n; i++)
    {
        points[2 * i] = x_cor[i];
        points[2 * i + 1] = y_cor[i];
    }
    drawpoly(n, points);
}

void translate()
{
    cout << "Enter the distance for translation in x cordinate";
    cin >> tx;
    cout << "Enter the distance for translation in y cordinate";
    cin >> ty;
    for (int i = 0; i < n; i++)
    {
        x_cor[i] += tx;
        y_cor[i] += ty;
    }
    setcolor(YELLOW);
    points[0] = '\0';
    generate_polygon();
}

void rotate()
{
    int t, v;
    cout << "Enter the angle for rotation: ";
    cin >> angle;
    cout << "Enter the point from where it needs to be rotated: ";
    cin >> x >> y;
    c = cos(angle * M_PI / 180);
    s = sin(angle * M_PI / 180);
    for (int i = 0; i < n; i++)
    {
        for (i = 0; i < n; i++)
        {
            t = x_cor[i] - x;
            v = y_cor[i] - y;
            x_cor[i] = x + floor(t * c - v * s);
            y_cor[i] = y + floor(v * c + t * s);
        }
    }
    setcolor(YELLOW);
    points[0] = '\0';
    generate_polygon();
}

void shearing()
{
    cout<<"Enter the shearing factor: ";
    cin>>sfx>>sfy;
    for (int i = 0; i < n; i++)
    {
        x_cor[i] = x_cor[0] + (x_cor[i] - x_cor[0]) * sfx;
        y_cor[i] = y_cor[0] + (y_cor[i] - y_cor[0]) * sfy;
    }
    setcolor(YELLOW);
    points[0] = '\0';
    generate_polygon();
}

void scale()
{
    cout<<"Enter the shearing factor: ";
    cin>>sfx>>sfy;
    for (int i = 0; i < n; i++) {
        x_cor[i] = x_cor[0] + (int)((float)(x_cor[i] - x_cor[0]) * sfx);
        y_cor[i] = y_cor[0] + (int)((float)(y_cor[i] - y_cor[0]) * sfx);
    }
    setcolor(YELLOW);
    points[0] = '\0';
    generate_polygon();
}

int main()
{
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    int gd = DETECT, gm, i; /* request autodetection */
    int ch, p;
    do
    {
        cout << "--------------MENU-------------" << endl;
        cout << "1. Translation" << endl;
        cout << "2. Rotation" << endl;
        cout << "3. Shearing" << endl;
        cout << "4. Scaling" << endl;
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            input_coordinate();
            initgraph(&gd, &gm, data); /* initialize graphics mode */
            setcolor(CYAN);
            generate_polygon();
            translate();
            _getch();
            break;

        case 2:
            input_coordinate();
            initgraph(&gd, &gm, data); /* initialize graphics mode */
            setcolor(CYAN);
            generate_polygon();
            rotate();
            _getch();
            break;

        case 3:
            input_coordinate();
            initgraph(&gd, &gm, data); /* initialize graphics mode */
            setcolor(CYAN);
            generate_polygon();
            shearing();
            _getch();
            break;

        case 4:
            input_coordinate();
            initgraph(&gd, &gm, data); /* initialize graphics mode */
            setcolor(CYAN);
            generate_polygon();
            scale();
            _getch();
            break;
        }
        cout<<"Do you want to continue?? If yes enter 1 else 0:: ";
        cin>>p;
    } while (p==1);

    return 0;
}