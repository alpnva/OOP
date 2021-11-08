#ifndef TVECTORITEM_H
#define TVECTORITEM_H
#include <iostream>
#include "trapezoid.h"

class TVectorItem
{
public:
	TVectorItem();
	//TVectorItem(Trapezoid& trapezoid);
	TVectorItem(const Trapezoid &other);


	friend std::ostream& operator<<(std::ostream& os, TVectorItem &t);
	virtual ~TVectorItem();

	Trapezoid &GetT();


private:
	Trapezoid t;
};

#endif