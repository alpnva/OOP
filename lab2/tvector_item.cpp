#include "tvector_item.h"
#include <iostream>

TVectorItem::TVectorItem() {

}

/*TVectorItem::TVectorItem(Trapezoid& trapezoid) {
	this->trapezoid = trapezoid;
	std::cout << "TVector Item: created" << std::endl;
}
*/
TVectorItem::TVectorItem(const Trapezoid &other) {
	this->t = other;
	std::cout << "TVector Item: copied" << std::endl;
}

std::ostream& operator<<(std::ostream& os, TVectorItem& trap) {
	os << trap.t;
	return os;
}

TVectorItem::~TVectorItem() {
	std::cout << "TVector Item: deleted" << std::endl;
}

Trapezoid& TVectorItem::GetT() {
	return this->t;
	std::cout << "Get Trapezoid" << std::endl;
}
