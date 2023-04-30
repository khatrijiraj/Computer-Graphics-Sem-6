#include <iostream>
#include <graphics.h>
using namespace std;
void circle_draw(float a, float b, float r)
{
   float x = 0, y = r;
   float p = (5 / 4) - r;
   putpixel(a, b + r, WHITE);
   putpixel(a, b - r, WHITE);
   putpixel(a - r, b, WHITE);
   putpixel(a + r, b, WHITE);
   p = (5 / 4) - r;
   while (x <= y)
   {
      if (p < 0)
         p += (2 * x) + 3;
      else
      {
         p += (2 * (x - y)) + 5;
         y--;
      }
      x++;
      putpixel(a + x, b + y, WHITE);
      putpixel(a - x, b + y, WHITE);
      putpixel(a - x, b - y, WHITE);
      putpixel(a + x, b - y, WHITE);
      putpixel(a + x, b + y, WHITE);
      putpixel(y - b, x + a, WHITE);
      putpixel(y + b, x - a, WHITE);
      putpixel(y - b, x - a, WHITE);
   }
}
int main()
{
   float r, a, b, x, y;

   int gd = DETECT, gm;
   initgraph(&gd, &gm, NULL);
   cout<<"Enter the radius of the circle: ";
   cin>>r;
   cout<<"Enter the x coordinate of centre of the circle: ";
   cin>>a;
   cout<<"Enter the y coordinate of centre of the circle: ";
   cin>>b;
   circle_draw(a,b,r);
   getch();
   closegraph();
   return 0;
}
