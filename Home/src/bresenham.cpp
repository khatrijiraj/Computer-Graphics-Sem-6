#include <conio.h>
#include <graphics.h>

#include <iostream>
using namespace std;
void Bresenham(int x1, int y1, int x2, int y2) {
    int x, y, dx, dy, steps, p;
    x = x1;
    y = y1;
    dx = (x2 - x1);
    dy = (y2 - y1);
    p = 2 * dy - dx;
    while (x <= x2) {
        putpixel(x, y, YELLOW);
        x++;
        if (p < 0) {
            p = p + 2 * dy;
        } else {
            p = p + 2 * dy - dx;
            y++;
        }
    }
}

int main() {
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    int gd = DETECT, gm, i;
    initgraph(&gd, &gm, data);
    int x1, y1, x2, y2;
    cout << "Enter x1: ";
    cin >> x1;
    cout << "Enter y1: ";
    cin >> y1;
    cout << "Enter x2: ";
    cin >> x2;
    cout << "Enter y2: ";
    cin >> y2;
    Bresenham(x1, y1, x2, y2);
    _getch();
    return 0;
}