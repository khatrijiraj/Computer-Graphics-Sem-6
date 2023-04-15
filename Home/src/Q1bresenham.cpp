#include <graphics.h>

#include <cmath>
#include <iostream>
using namespace std;

void mid_line(int x0, int y0, int x1, int y1, int value) {
    int x = x0;
    int dy = y1 - y0;
    int dx = x1 - x0;
    int d = 2 * dy - dx;
    int NE = 2 * (dy - dx);
    int E = 2 * dy;
    int y = y0;
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, NULL);
    putpixel(x, y, value);
    cout << "Initial values of x & y is:" << x0 << " " << y0 << "\n";
    cout << "Values after iteration is::" << '\n';
    while (x < x1) {
        if (d <= 0) {
            d += E;
            x++;
        } else {
            d += NE;
            x++;
            y++;
        }
        putpixel(x, y, value);
        cout << x << " " << y << "\n"
             << "\n";
    }
    delay(10000);
    closegraph();
}

int main() {
    int x0;
    int x1;
    int y0;
    int y1;
    int value;

    cout << "Enter thr starting coordinate"
         << "\n";
    cin >> x0 >> y0;
    cout << "Enter the ending corodinate"
         << "\n";
    cin >> x1 >> y1;
    cout << "Enter the color of the line"
         << "\n";
    cin >> value;
    mid_line(x0, y0, x1, y1, value);
    return 0;
}
