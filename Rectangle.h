#pragma once
#include "FigureBase.h"
#include <math.h>

using namespace std;
class Rectangle : public FigureBase
{
public:
	Rectangle()
	{

	}


	~Rectangle()
	{

	}

	virtual void UselessFunction() //Дебаг. Если вы это читаете, я забыл её вырезать.
	{
		cout << "Knock-Knock";
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

	void pushPointList(vector<Point> v)
	{
		this->pointList = v;
		this->computeBoundary();
		this->computeArea();
		this->computePerimeter();
	};

protected:
	const int pointCount = 4;
	bool checkForPointValidity()
	{
		return ((this->pointList).size() == pointCount);
	}

	void computeBoundary()
	{
		vector<Point> v = this->pointList;
		if ((v.size() > 0) && checkForPointValidity())
		{
			int cnt = 0;
			int min_x = 0;
			int min_y = 0;
			int max_x = 0;
			int max_y = 0;
			for (auto it = v.begin(); it != v.end(); it++)
			{
				if (cnt == 0)
				{
					int min_x = (*it).x;
					int min_y = (*it).y;
					int max_x = (*it).x;
					int max_y = (*it).y;
				};
				if (min_x > (*it).x) min_x = (*it).x;
				if (min_y > (*it).y) min_y = (*it).y;
				if (max_x < (*it).x) max_x = (*it).x;
				if (max_y < (*it).y) max_y = (*it).y;


				cnt++;
			};
			this->Box = BoundingBox{ Point{min_x, max_y}, Point{max_x, min_y} };
		};
	};

	void computeArea()
	{
		int dx = this->Getdx();
		int dy = this->Getdy();
		this->area = dx * dy;

	};

	void computePerimeter()
	{
		int dx = this->Getdx();
		int dy = this->Getdy();
		this->perimeter = 2*(dx + dy);

	};

};

