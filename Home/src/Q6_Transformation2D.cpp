#include <graphics.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

int ch, x, y, az, i, w, ch1, ch2, xa, ya, ra, a[10], b[10], da, db;
float x1, yy1, az1, w1, dx, dy, theta, x1s, yy1s, sx, sy, a1[10], b1[10];
int main() {
    int gm, gr;

    cout << "Enter the upper left corner of the rectangle:\n";
    cin >> x >> y;
    cout << "Enter the lower right corner of the rectangle:\n";
    cin >> az >> w;

    detectgraph(&gm, &gr);
    initgraph(&gm, &gr, NULL);
    rectangle(x, y, az, w);

    da = az - x;
    db = w - y;
    a[0] = x;
    b[0] = y;
    a[1] = x + da;
    b[1] = y;
    a[2] = x + da;
    b[2] = y + db;
    a[3] = x;
    b[3] = y + db;
    while (1) {
        cout << "******2D Transformations*******\n";
        cout << "1.Translation\n2.Rotation\n3.Scaling\n4.Reflection\n5.Shearing\n6.Exit\nEnter your choice:\n";
        cin >> ch;
        switch (ch) {
            case 1:
                detectgraph(&gm, &gr);
                initgraph(&gm, &gr, NULL);
                rectangle(x, y, az, w);
                cout << "*******Translation*******\n\n";
                cout << "Enter the value of shift vector:\n";
                cin >> dx >> dy;
                x1 = x + dx;
                yy1 = y + dy;
                az1 = az + dx;
                w1 = w + dy;
                rectangle(x1, yy1, az1, w1);
                break;
            case 2:
                detectgraph(&gm, &gr);
                initgraph(&gm, &gr, NULL);
                rectangle(x, y, az, w);
                cout << "*******Rotation*******\n\n";
                cout << "Enter the value of fixed point and angle of rotation:Enter the value of fixed point and angle of rotation:\n";
                cin >> xa >> ya >> ra;
                theta = (float)(ra * (3.14 / 180));
                for (i = 0; i < 4; i++) {
                    a1[i] = (xa + ((a[i] - xa) * cos(theta) - (b[i] - ya) * sin(theta)));
                    b1[i] = (ya + ((a[i] - xa) * sin(theta) + (b[i] - ya) * cos(theta)));
                }
                for (i = 0; i < 4; i++) {
                    if (i != 3)
                        line(a1[i], b1[i], a1[i + 1], b1[i + 1]);
                    else
                        line(a1[i], b1[i], a1[0], b1[0]);
                }
                break;
            case 3:
                detectgraph(&gm, &gr);
                initgraph(&gm, &gr, NULL);
                rectangle(x, y, az, w);
                cout << "********Scaling*******\n\n";
                cout << "Enter the value of scaling factor:\n";
                cin >> sx >> sy;
                x1 = x * sx;
                yy1 = y * sy;
                az1 = az * sx;
                w1 = w * sy;
                rectangle(x1, yy1, az1, w1);
                break;
            case 4:
                detectgraph(&gm, &gr);
                initgraph(&gm, &gr, NULL);
                rectangle(x, y, az, w);
                cout << "*******Reflection*********\n";
                cout << "1.About x-axis\n2.About y-axis\n3.About both axis\nEnter your choice:\n";
                cin >> ch1;
                switch (ch1) {
                    case 1:
                        printf("Enter the fixed point\n");
                        scanf("%d%d", &xa, &ya);
                        theta = (float)(90 * (3.14 / 180));
                        for (i = 0; i < 4; i++) {
                            a1[i] = (xa + ((a[i] - xa) * cos(theta) - (-b[i] - ya) * sin(theta)));
                            b1[i] = (ya + ((a[i] - xa) * sin(theta) + (-b[i] - ya) * cos(theta)));
                        }
                        for (i = 0; i < 4; i++) {
                            if (i != 3)
                                line(a1[i], b1[i], a1[i + 1], b1[i + 1]);
                            else
                                line(a1[i], b1[i], a1[0], b1[0]);
                        }
                        break;
                    case 2:
                        cout << "Enter the fixed point\n";
                        cin >> xa >> ya;
                        theta = (float)(270 * (3.14 / 180));
                        for (i = 0; i < 4; i++) {
                            a1[i] = (xa + ((-a[i] - xa) * cos(theta) - (b[i] - ya) * sin(theta)));
                            b1[i] = (ya + ((-a[i] - xa) * sin(theta) + (b[i] - ya) * cos(theta)));
                        }
                        for (i = 0; i < 4; i++) {
                            if (i != 3)
                                line(a1[i], b1[i], a1[i + 1], b1[i + 1]);
                            else
                                line(a1[i], b1[i], a1[0], b1[0]);
                        }
                        break;
                    case 3:
                        cout << "Enter the fixed point\n";
                        cin >> xa >> ya;
                        theta = (float)(180 * (3.14 / 180));
                        for (i = 0; i < 4; i++) {
                            a1[i] = (xa + ((-a[i] - xa) * cos(theta) - (-b[i] - ya) * sin(theta)));
                            b1[i] = (ya + ((-a[i] - xa) * sin(theta) + (-b[i] - ya) * cos(theta)));
                        }
                        for (i = 0; i < 4; i++) {
                            if (i != 3)
                                line(a1[i], b1[i], a1[i + 1], b1[i + 1]);
                            else
                                line(a1[i], b1[i], a1[0], b1[0]);
                        }
                        break;
                }
                break;
            case 5:
                detectgraph(&gm, &gr);
                initgraph(&gm, &gr, NULL);
                rectangle(x, y, az, w);
                cout << "*******Shearing******\n\n";
                cout << "1.x-direction shear\n2.y-direction shear\nEnter your choice:\n";
                cin >> ch2;
                switch (ch2) {
                    case 1:
                        printf("Enter the value of shear:\n");
                        cin >> x1s;
                        x1 = x + (y * x1s);
                        yy1 = y;
                        az1 = az + (w * x1s);
                        w1 = w;
                        rectangle(x1, yy1, az1, w1);
                        break;
                    case 2:
                        printf("Enter the value of shear:\n");
                        cin >> yy1s;
                        x1 = x;
                        yy1 = y + (x * yy1s);
                        az1 = az;
                        w1 = w + (az * yy1s);
                        rectangle(x1, yy1, az1, w1);
                        break;
                }
                break;
            case 6:
                exit(0);
        }
    }
}