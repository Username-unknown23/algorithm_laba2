#pragma once
#include "Rectangle.h"
class Square : public Rectangle
{
public:
	Square()
	{

	}

	~Square()
	{

	}
	
protected:

	bool checkForPointValidity()
	{
		bool c1 = (this->pointList).size() == pointCount;
		bool c2 = (this->Getdx() == this->Getdy());
		cout << c1 << ",  " << c1 << endl;
		return (c1 && c2);
	}

	


};

