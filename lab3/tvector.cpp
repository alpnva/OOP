#include "tvector.h"
#include <iostream>

TVector::TVector() {

}
TVector::TVector(size_t size) 
{
	this->size = 0;
	this->data = (std::shared_ptr<TVectorItem>*)malloc(sizeof
		(std::shared_ptr<TVectorItem>) * size);
}

bool TVector::Empty() {
	return this->size == 0;
}

//Trapezoid& TVector::operator[] (const size_t idx) {
//	return data[idx].GetTrapezoid();
//}

size_t TVector::Length() 
{
	return this->size;
}

void TVector::Resize(size_t new_size) {
	this->data = (std::shared_ptr<TVectorItem>*)realloc(this->data, 
		sizeof(Trapezoid) * new_size);
}

void TVector::InsertLast(std::shared_ptr<Figure>& element) {
	std::shared_ptr<TVectorItem> t = std::make_shared<TVectorItem>(element);
	this->data[size] = t;
	(this->size)++;
}

void TVector::Remove(int idx) {
	for (int j = idx; j != this->size - 1; j++) {
		this->data[j] = this->data[j + 1];
	}
	this->Resize(--(this->size));
}

void TVector::Print() {
	for(int i = 0; i < size; i++) {
		std::cout << data[i];
	}
}

void TVector::Print_idx(int idx) {
	std::cout << this->data[idx];
}

TVector::~TVector()
{
	std::cout << "TVector was deleted" << std::endl;
}