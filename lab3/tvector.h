#ifndef TVECTOR_H
#define TVECTOR_H

#include <iostream>
#include "tvector_item.h"
#include "trapezoid.h"
#include <memory>

class TVector {
public:
    TVector();
    TVector(size_t size);
    bool Empty();
    //Trapezoid &operator[] (const size_t idx);
    size_t Length();
    void Resize(size_t new_size);
    void InsertLast(std::shared_ptr<Figure>& element);
    void Remove(int idx);
    void Print();
    void Print_idx(int idx);

    virtual ~TVector();

private:
    size_t size;
    std::shared_ptr<TVectorItem>* data;
};

#endif //TVECTOR_H