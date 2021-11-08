#ifndef TVECTOR_H
#define TVECTOR_H

#include <iostream>
#include "tvector_item.h"
#include "trapezoid.h"

class TVector {
public:
    TVector();
    TVector(size_t size);
    bool Empty();
    size_t Length();
    void Resize(size_t new_size);
    void InsertLast(Trapezoid element);
    void RemoveLast();
    void Remove(int idx);
    void Print();
    void Print_idx(int idx);

    void Destroy();
    virtual ~TVector();

private:
    size_t size;
    TVectorItem *data;
};

#endif //TVECTOR_H