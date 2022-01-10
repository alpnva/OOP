#include "tvector.h"
#include <iostream>

template <class T> TVector<T>::TVector() {

}
template <class T> TVector<T>::TVector(size_t size) 
{
	this->size = 0;
	this->data = (std::shared_ptr<TVectorItem<T>>*)malloc(sizeof
		(std::shared_ptr<TVectorItem<T>>) * size);
}

template <class T> bool TVector<T>::Empty() {
	return this->size == 0;
}

template <class T> size_t TVector<T>::Length() 
{
	return this->size;
}

template <class T> void TVector<T>::Resize(size_t new_size) {
	this->data = (std::shared_ptr<TVectorItem<T>>*)realloc(this->data, 
		sizeof(Trapezoid) * new_size);
}

template <class T> void TVector<T>::InsertLast(std::shared_ptr<T>& element) {
	this->data[size] = std::make_shared<TVectorItem<T>>(element);
	(this->size)++;
}

template <class T> void TVector<T>::Remove(int idx) {
	for (int j = idx; j != this->size - 1; j++) {
		this->data[j] = this->data[j + 1];
	}
	this->Resize(--(this->size));
}

template <class T> void TVector<T>::Print() {
	for(int i = 0; i < size; i++) {
		std::cout << data[i];
	}
}

template <class T> void TVector<T>::Print_idx(int idx) {
	std::cout << this->data[idx];
}

template <class T> TIterator<TVectorItem<T>,T> TVector<T>::begin() {
	return this->data[0];
}

template <class T> TIterator<TVectorItem<T>,T> TVector<T>::end() {
	return this->data[this->size];
}
template <class T> TVector<T>::~TVector()
{
	std::cout << "TVector was deleted" << std::endl;
}

template class TVector<Figure>;