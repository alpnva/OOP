#include <iostream>
#include <cstdlib>
#include <memory>
#include "trapezoid.h"
#include "tvector.h"
#include "tvector_item.h"

typedef unsigned long long Type;


int main()
{   
    TVector<Figure>* v = new TVector<Figure>(1);
    std::shared_ptr<Figure> tmp;

    short int code = 0, number = 0;
    int index = 0;

    std::cout << "Code 1 means add element.\n" << std::endl; 
    std::cout << "Code 2 means print element.\n" << std::endl; 
    std::cout << "Code 3 means delete element.\n" << std::endl; 
    std::cout << "Code 4 means break.\n" << std::endl; 

    while (code != 4) {
        std::cout << "Code:" << std::endl;
        std::cin >> code;

        if (code == 1) {
            std::cout << "Write coordinates of Trapezoid" << std::endl;
            tmp = std::make_shared<Trapezoid>(std::cin);
            v->InsertLast(tmp);
            v->Resize((v->Length()) + 1);
        }

        if (code == 2) {
            std::cout << "You can print elements. Write it's index." << std::endl;
            std::cin >> index;
            if (index >= 0 && index < v->Length()) {
                v->Print_idx(index);
            } else {std::cout << "Incorrect index." << std::endl;}
        }

        if (code == 3) {
            std::cout << "You can delete elements. Write index." << std::endl;
            std::cin >> index;
            if (index >= 0 && index < v->Length()) {
                std::cout << "Size now: " << std::endl;
                std::cout << v->Length() << std::endl;
                v->Remove(index);
                std::cout << "Element was deleted, size of array was reduced." 
                << std::endl;
                std::cout << "Size after: " << std::endl;
                std::cout << v->Length() << std::endl;
            }
            else {std::cout << "Incorrect index." << std::endl;}
        }
    }

    return 0;
}