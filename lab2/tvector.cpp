#include "tvector.h"
#include <iostream>

TVector::TVector() {

}
TVector::TVector(size_t size) 
{
	this->size = 0;
	this->data = (TVectorItem*)malloc((sizeof(TVectorItem)) * (size));
}

bool TVector::Empty() {
	return this->size == 0;
}

size_t TVector::Length() 
{
	return this->size;
}

void TVector::Resize(size_t new_size) {
	this->data = (TVectorItem*)realloc(this->data, sizeof(TVectorItem) * new_size);
}

void TVector::InsertLast(Trapezoid element) {
	TVectorItem* tmp = new TVectorItem(element);
	this->data[this->size] = *tmp;
	(this->size)++;
	//size += 1;
	//data = (TVectorItem*) realloc(data, size * sizeof(TVectorItem));
	//data[size -1] = obj;
}

void TVector::RemoveLast() {
	if (size > 0) {
		size -= 1;
		this->data = (TVectorItem*)realloc(this->data, size * 
			sizeof(TVectorItem));
	}
}

void TVector::Remove(int idx) {
	for (int j = idx; j != this->size - 1; j++) {
		this->data[j] = this->data[j + 1];
	}
	this->Resize(--(this->size));
}

void TVector::Print() {
	for(int i = 0; i < size; i++) {
		std::cout << this->data[i] << "\n";
	}
}

void TVector::Print_idx(int idx) {
	std::cout << this->data[idx] << "\n";
}

void TVector::Destroy() {
	if (size != 0) {
		this->size = 0;
		free(this->data);
	}
}

TVector::~TVector()
{
	std::cout << "TVector was deleted" << std::endl;
}