#include <graphics.h>
#include <math.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

void bezier_curve(int x[4], int y[4]) {
    /* request auto detection */
    int gdriver = DETECT, gmode, errorcode;
    /* initialize graphics and local variables */
    initgraph(&gdriver, &gmode, NULL);

    double t;
    for (t = 0.0; t < 1.0; t += 0.0005) {
        double xt = pow(1 - t, 3) * x[0] + 3 * t * pow(1 - t, 2) * x[1] + 3 * pow(t, 2) * (1 - t) * x[2] + pow(t, 3) * x[3];
        double yt = pow(1 - t, 3) * y[0] + 3 * t * pow(1 - t, 2) * y[1] + 3 * pow(t, 2) * (1 - t) * y[2] + pow(t, 3) * y[3];
        putpixel(xt, yt, WHITE);
    }
    for (int i = 0; i < 4; i++)
        putpixel(x[i], y[i], YELLOW);

    delay(5000);
    closegraph();
}

void hermite_curve(int x1, int y1, int x2, int y2, double t1, double t4) {
    /* request auto detection */
    int gdriver = DETECT, gmode, errorcode;
    /* initialize graphics and local variables */
    initgraph(&gdriver, &gmode, NULL);

    float x, y, t;
    for (t = 0.0; t <= 1.0; t += 0.001) {
        x = (2 * t * t * t - 3 * t * t + 1) * x1 + (-2 * t * t * t + 3 * t * t) * x2 + (t * t * t - 2 * t * t + t) * t1 + (t * t * t - t * t) * t4;
        y = (2 * t * t * t - 3 * t * t + 1) * y1 + (-2 * t * t * t + 3 * t * t) * y2 + (t * t * t - 2 * t * t + 1) * t1 + (t * t * t - t * t) * t4;
        putpixel(x, y, YELLOW);
    }
    putpixel(x1, y1, GREEN);
    putpixel(x2, y2, GREEN);
    line(x1, y1, x2, y2);

    delay(5000);
    closegraph();
}

int main() {
    int x1, y1, x2, y2, n;
    double t1, t4;

    int x[4], y[4];
    int i;
    cout << "1.Bezier Curve \n2.Hermite Curve\n";
    cout << "Enter your choice:";
    cin >> n;
    if (n == 1) {
        cout << "Enter x and y coordinates\n";
        for (i = 0; i < 4; i++) {
            cout << "x" << i + 1 << ":";
            cin >> x[i];
            cout << "y" << i + 1 << ":";
            cin >> y[i];
            cout << endl;
        }
        bezier_curve(x, y);
    } else if (n == 2) {
        cout << "Enter the x coordinate of 1st hermite point:";
        cin >> x1;
        cout << "Enter the y coordinate of 1st hermite point:";
        cin >> y1;
        cout << "Enter the x coordinate of 4th hermite point:";
        cin >> x2;
        cout << "Enter the y coordinate of 4th hermite point:";
        cin >> y2;
        cout << "Enter tangent at p1:";
        cin >> t1;
        cout << "Enter tangent at p4:";
        cin >> t4;
        hermite_curve(x1, y1, x2, y2, t1, t4);
    } else {
        cout << "\nInvalid Choice";
    }
    return 0;
}