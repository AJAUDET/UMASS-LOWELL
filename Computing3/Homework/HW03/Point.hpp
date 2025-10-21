#ifndef POINT_HPP
#define POINT_HPP
class Point
{
 private:
    //  point coordinates
    int x_coord;
    int y_coord;
 public:
    // constructors
    Point();
    Point(int new_x, int new_y);
    // accessor functions
    int getX(void);
    int getY(void);
    // mutator functions
    void setX(int new_x);
    void setY(int new_y);
    void move(int x1, int y1);
    void rotateCW(void);
    void rotateCCW(void);
};
#endif
