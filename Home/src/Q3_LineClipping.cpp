#include <graphics.h>

#include <iostream>
using namespace std;

void plotPoints(int x, int y, int thickness, int colorValue) {
    putpixel(x, y, colorValue);
    int ht = thickness / 2;
    for (int i = 0; i < ht; i++) {
        putpixel(x + i, y, colorValue);
        if (thickness % 2 == 0 && i == ht - 1) {
            break;
        } else {
            putpixel(x - i, y, colorValue);
        }
    }
}

void midPointLine(int x0, int y0, int x1, int y1, int thickness = 1, int colorValue = 3) {
    int x2, y2;
    if (x0 > x1) {
        x2 = x0;
        y2 = y0;
        x0 = x1;
        y0 = y1;
        x1 = x2;
        y1 = y2;
    }

    cout << "\nInitial Coordinates = (" << x0 << ", " << y0 << ")\n";
    cout << "Final Coordinates = (" << x1 << ", " << y1 << ")\n";

    int dy = y1 - y0;
    int dx = x1 - x0;
    bool infinitySlope = false;
    double m;

    if (x0 != x1) {
        m = double(dy) / dx;  // Only Floating-point calculation
    } else {
        infinitySlope = true;
    }

    if (infinitySlope) {
        int x = x0;
        int y = y0 <= y1 ? y0 : y1;
        int yMax = (y0 * y1) / y;

        for (; y <= yMax; y++) {
            plotPoints(x, y, thickness, colorValue);
        }
    } else if (m <= 1 && m >= 0) {
        int d = (2 * dy) - dx;
        int incrE = 2 * dy;
        int incrNE = 2 * (dy - dx);

        int x = x0, y = y0;
        plotPoints(x, y, thickness, colorValue);

        while (x < x1) {
            if (d <= 0) {
                d += incrE;
                x++;
            } else {
                d += incrNE;
                x++;
                y++;
            }
            plotPoints(x, y, thickness, colorValue);
        }
    } else if (m > 1) {
        int d = dy - (2 * dx);
        int incrN = -(2 * dx);
        int incrNE = 2 * (dy - dx);

        int x = x0, y = y0;
        plotPoints(x, y, thickness, colorValue);

        while (y < y1) {
            if (d > 0) {
                d += incrN;
                y++;
            } else {
                d += incrNE;
                x++;
                y++;
            }
            plotPoints(x, y, thickness, colorValue);
        }
    } else if (m >= -1 && m < 0) {
        int d = (2 * dy) + dx;
        int decrE = 2 * dy;
        int decrSE = 2 * (dy + dx);

        int x = x0, y = y0;
        plotPoints(x, y, thickness, colorValue);

        while (x < x1) {
            if (d <= 0) {
                d += decrSE;
                x++;
                y--;
            } else {
                d += decrE;
                x++;
            }
            plotPoints(x, y, thickness, colorValue);
        }
    } else if (m < -1) {
        int d = dy + (2 * dx);
        int decrS = (2 * dx);
        int decrSE = 2 * (dy + dx);

        int x = x0, y = y0;
        plotPoints(x, y, thickness, colorValue);

        while (y > y1) {
            if (d > 0) {
                d -= decrS;
                y--;
            } else {
                d -= decrSE;
                x++;
                y--;
            }
            plotPoints(x, y, thickness, colorValue);
        }
    }
}

typedef unsigned int outcode;
enum { TOP = 0x8,
       BOTTOM = 0x4,
       RIGHT = 0x2,
       LEFT = 0x1 };

outcode CompOutCode(double x, double y, double xmin, double xmax, double ymin, double ymax) {
    outcode code = 0;
    if (y < ymax)
        code = code | TOP;
    else if (y > ymin)
        code = code | BOTTOM;

    if (x > xmax)
        code = code | RIGHT;
    else if (x < xmin)
        code = code | LEFT;

    return code;
}

void CohenSutherlandLineClipAndDraw(double x0, double y0, double x1, double y1, double xmin, double ymin, double xmax, double ymax, int value) {
    outcode outcode0, outcode1, outcodeOut;
    bool accept = false, done = false;
    outcode0 = CompOutCode(x0, y0, xmin, xmax, ymin, ymax);
    outcode1 = CompOutCode(x1, y1, xmin, xmax, ymin, ymax);

    do {
        if (!(outcode0 | outcode1)) {
            accept = true;
            done = true;
        } else if (outcode0 & outcode1) {
            done = true;
        } else {
            double x, y;
            outcodeOut = outcode0 ? outcode0 : outcode1;

            if (outcodeOut & TOP) {
                x = x0 + ((x1 - x0) * (ymax - y0)) / (y1 - y0);
                y = ymax;
            } else if (outcodeOut & BOTTOM) {
                x = x0 + ((x1 - x0) * (ymin - y0)) / (y1 - y0);
                y = ymin;
            } else if (outcodeOut & RIGHT) {
                y = y0 + ((y1 - y0) * (xmax - x0)) / (x1 - x0);
                x = xmax;
            } else {
                y = y0 + ((y1 - y0) * (xmin - x0)) / (x1 - x0);
                x = xmin;
            }

            if (outcodeOut == outcode0) {
                x0 = x;
                y0 = y;
                outcode0 = CompOutCode(x0, y0, xmin, xmax, ymin, ymax);
            } else {
                x1 = x;
                y1 = y;
                outcode1 = CompOutCode(x1, y1, xmin, xmax, ymin, ymax);
            }
        }
    } while (done == false);

    if (accept) {
        midPointLine(x0, y0, x1, y1, 3, value);
    }
}

int main() {
    int xmin, ymin, xmax, ymax, x0, y0, x1, y1;

    cout << "\nFOR THE FRAME:\n";
    do {
        cout << "Xmin = ";
        cin >> xmin;
    } while (xmin < 0);
    do {
        cout << "Xmax = ";
        cin >> xmax;
    } while (xmax < 0);
    do {
        cout << "Ymin = ";
        cin >> ymin;
    } while (ymin < 0);
    do {
        cout << "Ymax = ";
        cin >> ymax;
    } while (ymax < 0);

    cout << "\nENTER THE STARTING POINT COORDINATE :\n";
    do {
        cout << "X0 = ";
        cin >> x0;
    } while (x0 < 0);
    do {
        cout << "Y0 = ";
        cin >> y0;
    } while (y0 < 0);

    cout << "\nENTER THE ENDING POINT COORDINATE :\n";
    do {
        cout << "X1 = ";
        cin >> x1;
    } while (x1 < 0);
    do {
        cout << "Y1 = ";
        cin >> y1;
    } while (y1 < 0);

    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode, NULL);

    midPointLine(xmin, ymax, xmax, ymax, 1, 2);
    // delay(1000);
    midPointLine(xmin, ymax, xmin, ymin, 1, 2);
    // delay(1000);
    midPointLine(xmin, ymin, xmax, ymin, 1, 2);
    // delay(1000);
    midPointLine(xmax, ymax, xmax, ymin, 1, 2);
    // delay(1000);

    midPointLine(x0, y0, x1, y1, 1, 3);
    // delay(1000);
    CohenSutherlandLineClipAndDraw(x0, y0, x1, y1, xmin, ymin, xmax, ymax, 4);

    delay(10000);  // Delay of 10s
    closegraph();

    return 0;
}
