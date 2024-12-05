#pragma once
#include "FigureBase.h"
#include <math.h>

using namespace std;

class Triangle : public FigureBase
{
public:
	Triangle() {};
	~Triangle() {};


	virtual void UselessFunction() //Дебаг. Если вы это читаете, я забыл её вырезать.
	{
		cout << "Knock-Knock-Knock";
	}

	int Getdx()
	{
		Point p1 = this->Box.A;
		Point p2 = this->Box.B;
		int dx = abs(p1.x - p2.x);
		return dx;
	}


	int Getdy()
	{
		Point p1 = this->Box.A;
		Point p2 = this->Box.B;
		int dy = abs(p1.y - p2.y);
		return dy;
	}

	double Getdz(Point a1, Point a2)
	{
		Point p1 = a1;
		Point p2 = a2;
		int dx = abs(p1.x - p2.x);
		int dy = abs(p1.y - p2.y);
		double dz = sqrt(dx * dx + dy * dy);
		return dz;
	}

	void pushPointList(vector<Point> v)
	{
		this->pointList = v;
		this->computeBoundary();
		this->computeArea();
		this->computePerimeter();
	};



protected:

	const int pointCount = 3;
	bool checkForPointValidity()
	{
		return ((this->pointList).size() == pointCount);
	}

	

	void computeArea()
	{
		double l1 = Getdz(pointList[0], pointList[1]);
		double l2 = Getdz(pointList[1], pointList[2]);
		double l3 = Getdz(pointList[2], pointList[0]);
		double p = (l1 + l2 + l3) / 2.0;
		this->area = sqrt((p)*(p-l1)*(p-l2)*(p-l3));

	};

	void computePerimeter()
	{
		double l1 = Getdz(pointList[0], pointList[1]);
		double l2 = Getdz(pointList[1], pointList[2]);
		double l3 = Getdz(pointList[2], pointList[0]);
		this->perimeter = l1 + l2 + l3;

	};

};
