#include "Point.h"

using namespace std;

class HitBox
{
    private:
        Point points[4];
    public:
        HitBox(Point a, Point b, Point c, Point d)
        {
            points[0] = a;
            points[1] = b;
            points[2] = c;
            points[3] = d;
        }
};