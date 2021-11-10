#ifndef TVECTORITEM_H
#define TVECTORITEM_H
#include <iostream>
#include "trapezoid.h"
#include <memory>

class TVectorItem
{
public:
	TVectorItem(std::shared_ptr<Figure>& figure);

	friend std::ostream& operator<<(std::ostream& os, 
		const std::shared_ptr<TVectorItem>& obj);

	std::shared_ptr<Figure> GetFigure() const;

	virtual ~TVectorItem();

private:
	std::shared_ptr<Figure> figure;
};

#endif
