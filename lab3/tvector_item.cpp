#include "tvector_item.h"
#include <iostream>

TVectorItem::TVectorItem(std::shared_ptr<Figure>& figure) {
	this->figure = figure;
	std::cout << "TVector Item: created" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const std::shared_ptr<TVectorItem>& obj) {
	obj->figure->Print();
	return os;
}

std::shared_ptr<Figure> TVectorItem::GetFigure() const {
	return this->figure;
}

TVectorItem::~TVectorItem() {
	std::cout << "TVector Item: deleted" << std::endl;
}