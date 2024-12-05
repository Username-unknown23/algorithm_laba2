#include <iostream>
#include "FigureBase.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"

using namespace std;

int main()
{
    Point *p1 = new Point{0, 0};
    Point *p2 = new Point{0, 2};
    Point *p3 = new Point{2, 0};
    Point *p4 = new Point{2, 2};
    vector<Point> v = { *p1, *p2, *p3, *p4};
    vector<Point> v2 = {*p1, *p2, *p3};


    Triangle* f = new Triangle;
    f->pushFigureName("01");
    f->pushPointList(v2);

    cout << f->GetArea();
    cout << endl;
    cout << f->GetPerimeter();

    delete f;
    return 0;
}
