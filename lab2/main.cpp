#include <iostream>
#include <cstdlib>
#include "trapezoid.h"
#include "tvector.h"
#include "tvector_item.h"

using namespace std;
typedef unsigned long long Type;


int main()
{   
    TVector* v = new TVector(1);
    Trapezoid tmp;

    short int code = 0;
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
            cin >> tmp;

            v->InsertLast(tmp);
            v->Resize((v->Length()) + 1);
        }

        if (code == 2) {
            std::cout << "You can print elements. Write it's index." << std::endl;
            std::cin >> index;
            if (index >= 0 && index < v->Length()) {
                v->Print_idx(index);
            } else {cout << "Incorrect index." << endl;}
        }

        if (code == 3) {
            cout << "You can delete elements. Write index." << std::endl;
            cin >> index;
            if (index >= 0 && index < v->Length()) {
                std::cout << "Size now: " << std::endl;
                std::cout << v->Length() << std::endl;
                v->Remove(index);
                cout << "Element was deleted, size of array was reduced." << endl;
                std::cout << "Size after: " << std::endl;
                std::cout << v->Length() << std::endl;
            }
            else {cout << "Incorrect index." << endl;}
        }
    }

    v->Destroy();

    return 0;
}