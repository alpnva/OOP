#ifndef TVECTORITEM_H
#define TVECTORITEM_H
#include <iostream>
#include "trapezoid.h"
#include <memory>

template <class T> class TVectorItem {
public: 
	TVectorItem(std::shared_ptr<T>& figure);
	template <class A> friend std::ostream& operator<<(std::ostream& os, 
	const std::shared_ptr<TVectorItem<A>>& obj);
	
	std::shared_ptr<T> GetFigure() const;

	virtual ~TVectorItem();

private: 
	std::shared_ptr<T> figure; 
};

#endif