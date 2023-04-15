#include <graphics.h>

#include <cmath>
#include <iostream>

using namespace std;

void Circle_Points(int x1, int y1, int x, int y, int value);
void Circle(int x1, int y1, int r, int value) {
    double d;
    int x = 0;
    int y = r;
    d = 1 - r;

    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, NULL);

    Circle_Points(x1, y1, x, y, value);
    cout << "Values after iteration us :";
    while (y > x) {
        if (d < 0) {
            d += 2 * x + 3;
            cout << "Value of d is:" << d << "\n";
        } else {
            d += 2 * (x - y) + 5;
            cout << "Value of d is: " << d << "\n";
            y--;
        }
        x++;
        Circle_Points(x1, y1, x, y, value);
        cout << x << " " << y << "\n";
    }
    delay(10000);
    closegraph();
}
void Circle_Points(int x1, int y1, int x, int y, int value) {
    putpixel((x1 + x + 320), (y1 + y + 240), 5);
    putpixel((x1 - x + 320), (y1 + y + 240), 5);
    putpixel((x1 + x + 320), (y1 - y + 240), 5);
    putpixel((x1 - x + 320), (y1 - y + 240), 5);
    putpixel((x1 + y + 320), (y1 + x + 240), 5);
    putpixel((x1 - y + 320), (y1 + x + 240), 5);
    putpixel((x1 + y + 320), (y1 - x + 240), 5);
    putpixel((x1 - y + 320), (y1 - x + 240), 5);
}

int main() {
    int r, x, y;
    cout << "\n Enter the radius of the circle";
    cin >> r;
    cout << "\n\n Enter x = ";
    cin >> x;
    cout << "\nEnter y = ";
    cin >> y;
    cout << "Initial Values of x is:" << x << "& y is:" << y << '\n';
    Circle(x, y, r, 1111);

    return 0;
}