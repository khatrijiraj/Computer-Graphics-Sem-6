#include <conio.h>
#include <graphics.h>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;
void DDA(int x1, int y1, int x2, int y2) {
    int dx, dy, steps, x_inc, y_inc;
    dx = float(x2 - x1);
    dy = float(y2 - y1);
    if (abs(dx) >= abs(dy)) {
        steps = abs(dx);
    } else {
        steps = abs(dy);
    }
    x_inc = dx / steps;
    y_inc = dy / steps;
    for (int i = 0; i <= steps; i++) {
        putpixel(x1, y1, WHITE);
        x1 = x1 + x_inc;
        y1 = y1 + y_inc;
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
    DDA(x1, y1, x2, y2);
    _getch();
    return 0;
}