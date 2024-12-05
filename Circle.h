#pragma once
#include "FigureBase.h"
class Circle :
    public FigureBase
{
public:
	Circle() { radius = 0; };
    ~Circle() { };

	void pushRadius(int r)
	{
		this->radius = r;
		this->computeArea();
		this->computePerimeter();

	}

	void pushPointList(vector<Point> v)
	{
		this->pointList = v;
		this->computeBoundary();
		this->computeArea();
		this->computePerimeter();
	};




protected:
    int radius;

    const int pointCount = 1;
    
	bool checkForPointValidity()
	{
		return ((this->pointList).size() == pointCount);
	}

	void computeBoundary()
	{
		vector<Point> v = this->pointList;
		if ((v.size() > 0) && checkForPointValidity())
		{
			auto it = v.begin();
			int min_x = (*it).x - radius;
			int min_y = (*it).y - radius;
			int max_x = (*it).x + radius;
			int max_y = (*it).y + radius;
			this->Box = BoundingBox{ Point{min_x, max_y}, Point{max_x, min_y} };
		};
	};

	

    void computeArea()
    {
        double r = this->radius;
        this->area =  (3.141529 * r * r);
    };

	void computePerimeter()
	{
		double r = this->radius;
		this->perimeter = (2 * 3.141529 * r);
	}
};

