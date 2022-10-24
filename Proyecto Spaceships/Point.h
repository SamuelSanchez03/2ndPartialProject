class Point
{
    private:
        int x, y;
    public:
        Point (){}
        
        Point(int x, int y)
        {
            this->x = x;
            this->y = y;
        }

        int getX()
        {
            return x;
        }

        int getY()
        {
            return y;
        }

        void moveX(int dX)
        {
            x += dX;
        }

        void moveY(int dY)
        {
            y += dY;
        }
};
