#ifndef TVECTORITEM_H
#define TVECTORITEM_H
#include <iostream>
#include "trapezoid.h"
#include "tallocation_block.h"
#include <memory>

template <class T> class TVectorItem {
public: 
	TVectorItem(std::shared_ptr<T>& figure);
	template <class A> friend std::ostream& operator<<(std::ostream& os, 
	const std::shared_ptr<TVectorItem<A>>& obj);
	
	std::shared_ptr<T> GetFigure() const;
	std::shared_ptr<TVectorItem<T>> GetNext();
	void SetNext(std::shared_ptr<TVectorItem<T>> next);
	void* operator new (size_t size);
	void operator delete(void* p);

	virtual ~TVectorItem();

private: 
	std::shared_ptr<T> figure; 
	std::shared_ptr<TVectorItem<T>> next;
	static TAllocationBlock vectoritem_allocator;
};

#endif