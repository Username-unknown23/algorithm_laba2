using namespace std;
#pragma once
#include <iostream>
#include <string>
#include <vector>

struct Point
{
	int x;
	int y;
};

struct BoundingBox
{
	Point A; // A is expected to be higher and more to the left than B 
	Point B;
};

class FigureBase
{
public:
	FigureBase()
	{
		this->name = "FigureBase";
	};


	~FigureBase()
	{
	}

	virtual void UselessFunction() //Дебаг. Если вы это читаете, я забыл её вырезать.
	{
		cout << "Baaa";
	}

	void PrintInfo()
	{
		cout << "Figure type: " << this->FigureType << endl;
		cout << "Figure name: " << this->name << endl;
		printBoundingBox();
	};


	string GetName()
	{
		return this->name;
	};

	vector<Point> GetPoints()
	{
		return this->pointList;
	};



	void printBoundingBox()
	{
		Point x1 = this->Box.A;
		Point x2 = this->Box.B;
		cout << "{Point A{" << this->Box.A.x << ", " << this->Box.A.y << "}, ";
		cout << "Point B{" << this->Box.B.x << ", " << this->Box.B.y << "}}" << endl;
	};


	void pushBoundingBox(BoundingBox x)
	{
		this->Box = x;
	};
	

	void pushFigureName(string x)
	{
		this->name = x;
	};


	void pushFigureType(string x)
	{
		this->FigureType = x;
	};


	void pushPointList(vector<Point> v)
	{
		this->pointList = v;
		this->computeBoundary();
	};

	BoundingBox GetBoundingBox()
	{
		return this->Box;
	};

	double GetArea()
	{
		return this->area;
	}

	double GetPerimeter()
	{
		return this->perimeter;
	}

protected:
	string name;
	string FigureType;
	BoundingBox Box;
	vector<Point> pointList;
	double area;
	double perimeter;

	

	const int pointCount = 0;
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

	void computeArea();
	
};

