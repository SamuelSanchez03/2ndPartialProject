#include "Point.h"

using namespace std;

class HitBox
{
    private:
        int x1, x2, y1, y2;
    public:

        HitBox(){}
        HitBox(int x1, int x2, int y1, int y2)
        {
            this->x1 = x1;
            this->x2 = x2;
            this->y1 = y1;
            this->y2 = y2;
        }
        
        bool pointInside(Point p)
        {
            int x = p.getX(), y = p.getY();
            return (x>=x1 && x<=x2 && y>=y1 && y<=y2);
        }

        void moveHB(int speed)
        {
            y1 += speed;
            y2 += speed;
        }
};