#ifndef TVECTOR_H
#define TVECTOR_H

#include <iostream>
#include "tvector_item.h"
#include "trapezoid.h"
#include "titerator.h"
#include <memory>

template <class T> class TVector {
public:
    TVector();
    TVector(size_t size);
    bool Empty();

    size_t Length();
    void Resize(size_t new_size);
    void InsertLast(std::shared_ptr<T>& element);
    void Remove(int idx);
    void Print();
    void Print_idx(int idx);

    TIterator<TVectorItem<T>,T> begin();
    TIterator<TVectorItem<T>,T> end();

    virtual ~TVector();

private:
    size_t size;
    std::shared_ptr<TVectorItem<T>>* data;
};

#endif //TVECTOR_H