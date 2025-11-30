#include "Point.hpp"

// constructors
Point::Point() {
    x_coord = 0;
    y_coord = 0;
}

Point::Point(int new_x, int new_y) {
    x_coord = new_x;
    y_coord = new_y;
}

// accessor functions
int Point::getX(void) {
    return x_coord;
}

int Point::getY(void) {
    return y_coord;
}

// mutator functions
void Point::setX(int new_x) {
    x_coord = new_x;
}

void Point::setY(int new_y) {
    y_coord = new_y;
}

void Point::move(int x1, int y1) {
    x_coord += x1;
    y_coord += y1;
}

// 4 quadrants, q1->q4, q4->q3, q3->q2, q2->q1
// following xy coordinate plain, ASTC
void Point::rotateCW(void) {
    int temp = x_coord;
    x_coord = y_coord;
    y_coord = -temp;
}

// 4 quadrants, q1->q2, q2->q3, q3->q4, q4->q1
// following xy coordinate plain, ASTC
void Point::rotateCCW(void) {
    int temp = x_coord;
    x_coord = -y_coord;
    y_coord = temp;
}
