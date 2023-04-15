#include <graphics.h>

#include <cmath>
#include <iostream>
using namespace std;

void line(int x0, int y0, int x1, int y1, int value) {
    int x;
    double dy = y1 - y0;
    double dx = x1 - x0;
    double m = dy / dx;
    double y = y0;
    cout << "Value of m is :\n"
         << m << "\n";
    int gdrive = DETECT, gmode, errorcode;
    initgraph(&gdrive, &gmode, NULL);

    if (m <= 1) {
        y = y0;
        for (x = x0; x <= x1; x++) {
            y = y + m;
            cout << "When k<1 "
                 << "Value of y =" << y << "Value of x = " << x << "\n";
            putpixel(x, round(y), value);
        }
    } else {
        x = x0;
        for (y = y0; y <= y1; y++) {
            x = x + 1 / m;
            cout << "When k>1 "
                 << "Value of y =" << y << "Value of x = " << x << "\n";
            putpixel(round(x), y, value);
        }
    }
    delay(10000);
}
int main() {
    int x0;
    int x1;
    int y0;
    int y1;
    int value;

    cout << "Enter starting corrdinate\n";
    cin >> x0 >> y0;
    cout << "Enter ending corodinates\n";
    cin >> x1 >> y1;
    cout << "Enter color of line\n";
    cin >> value;
    line(x0, y0, x1, y1, value);
    return 0;
}
