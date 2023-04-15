#include <graphics.h>

#include <iostream>
using namespace std;
void circle_draw(int a, int b, int r) {
    int x = 0, y = r;
    int p = (5 / 4) - r;
    putpixel(a, b + r, WHITE);
    putpixel(a, b - r, WHITE);
    putpixel(a - r, b, WHITE);
    putpixel(a + r, b, WHITE);

    while (x <= y) {
        if (p < 0)
            p += (4 * x) + 6;
        else {
            p = p + 2 * (x - y) + 5;
            y--;
        }
        x++;
        putpixel(a + x, b + y, WHITE);
        putpixel(a - x, b + y, WHITE);
        putpixel(a + x, b - y, WHITE);
        putpixel(a + x, b - y, WHITE);
        putpixel(a + x, b + y, WHITE);
        putpixel(a + x, b - y, WHITE);
        putpixel(a - x, b + y, WHITE);
        putpixel(a - x, b - y, WHITE);
    }
}

int main() {
    int r, a, b, x, y;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    cout << "Enter the radius of the circle: ";
    cin >> r;
    cout << "Enter the x coordinate of centre of the circle: ";
    cin >> a;
    cout << "Enter the y coordinate of centre of the circle: ";
    cin >> b;
    circle_draw(r, a, b);
    getch();
    closegraph();
    return 0;
}