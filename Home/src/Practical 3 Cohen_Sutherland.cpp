#include <iostream>
#include <conio.h>
#include <graphics.h>

using namespace std;
int x_min, x_max, y_min, y_max, x1, y1, x2, y2, slope;
int region[4], region_beg[4] = {0, 0, 0, 0}, region_end[4] = {0, 0, 0, 0};
int f;
void generate_window()
{
    cout << "Enter the x min of the window: ";
    cin >> x_min;
    cout << "Enter the x max of the window: ";
    cin >> x_max;
    cout << "Enter the y min of the window: ";
    cin >> y_min;
    cout << "Enter the y max of the window: ";
    cin >> y_max;
    rectangle(x_min, y_min, x_max, y_max);
}

void input_line()
{
    cout << "Enter x coordinate of initial point of line: ";
    cin >> x1;
    cout << "Enter y coordinate of initial point of line: ";
    cin >> y1;
    cout << "Enter x coordinate of end point of line: ";
    cin >> x2;
    cout << "Enter y coordinate of end point of line: ";
    cin >> y2;
    line(x1, y1, x2, y2);
}

void set_region_code()
{
    // For initial point
    if (x1 < x_min)
    {
        region_beg[3] = 1;
        f = 1;
    }
    if (y1 < y_min)
    {
        region_beg[1] = 1;
        f = 1;
    }
    if (x1 > x_max)
    {
        region_beg[2] = 1;
        f = 1;
    }
    if (y1 > y_max)
    {
        region_beg[0] = 1;
        f = 1;
    }

    // For end point
    if (x2 < x_min)
    {
        region_end[3] = 1;
        f = 1;
    }
    if (y2 < y_min)
    {
        region_end[1] = 1;
        f = 1;
    }
    if (x2 > x_max)
    {
        region_end[2] = 1;
        f = 1;
    }
    if (y2 > y_max)
    {
        region_end[0] = 1;
        f = 1;
    }

    // checking the position of line
    if (f == 0)
    {
        cout << "The line is within the window. Clipping is not needed";
    }
    f = 1;
    for (int i = 0; i < 4; i++)
    {
        region[i] = region_beg[i] && region_end[i];
        if (region[i] == 1)
            f = 0;
    }
    if (f == 0)
    {
        cout << "Line is outside the window";
    }
    else
    {
        slope = (y2 - y1) / (x2 - x1);

        // initial point
        if (region_beg[0] == 1 && region_beg[1] == 0)
        {
            x1 = x1 + (y_max - y1) / slope;
            y1 = y_max;
        }

        if (region_beg[0] == 0 && region_beg[1] == 1)
        {
            x1 = x1 + (y_min - y1) / slope;
            y1 = y_min;
        }

        if (region_beg[2] == 0 && region_beg[3] == 1)
        {
            y1 = y1 + (x_min - x1) * slope;
            x1 = x_min;
        }

        if (region_beg[2] == 1 && region_beg[3] == 0)
        {
            y1 = y1 + (x_max - x1) * slope;
            x1 = x_max;
        }

        // end point
        if (region_end[0] == 1 && region_end[1] == 0)
        {
            x2 = x2 + (y_max - y2) / slope;
            y2 = y_max;
        }

        if (region_end[0] == 0 && region_end[1] == 1)
        {
            x2 = x2 + (y_min - y2) / slope;
            y2 = y_min;
        }

        if (region_end[2] == 0 && region_end[3] == 1)
        {
            y2 = y2 + (x_min - x2) * slope;
            x2 = x_min;
        }

        if (region_end[2] == 1 && region_end[3] == 0)
        {
            y2 = y2 + (x_max - x2) * slope;
            x2 = x_max;
        }
    }
}

int main()
{
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    int gd = DETECT, gm, i;    /* request autodetection */
    initgraph(&gd, &gm, data); /* initialize graphics mode */

    generate_window();
    input_line();
    set_region_code();
    delay(5000);
    clearviewport();
    rectangle(x_min, y_min, x_max, y_max);
    line(x1, y1, x2, y2);
    cout<<"Coordinates after clipping: "<< x1 << " " << y1 << " " << x2 << " " << y2;
    _getch();
    return 0;
}
