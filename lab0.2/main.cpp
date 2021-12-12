#include <stdio.h>
#include <stdlib.h>
#include "FazzyNumber.h"
#include <iostream>
#include <fstream>


int main () {
    std::string test_name;
    std::cout << "Type test file name (e.g. test_01.txt) ";
    std::cout << "or type 'console' to enter them by yourself: ";
    std::cin >> test_name;
    double x_a, e_a, x_b, e_b;
    if (test_name != "console") {
        std::ifstream input;
        input.open(test_name);
        if (!input.is_open()) {
            std::cout << "File is not exists\n"; // если не открылся
            return -1;
        }
        input >> x_a >> e_a >> x_b >> e_b;
    }else {
        std::cout<<"Input A in formax: X e\n";
        std::cin>> x_a >> e_a;
        
        std::cout<<"Input B in formax: X e\n";
        std::cin>> x_b >> e_b;
        FazzyNumber B(x_b,e_b);
    }
    std::cout << std::endl;

    FazzyNumber A(x_a, e_a);
    FazzyNumber B(x_b, e_b);

    FazzyNumber sum = A + B;
    FazzyNumber dif = A - B;
    FazzyNumber mul = A * B;
    FazzyNumber div = A / B ;
    std::cout<< "result of A + B = ", sum.print();
    std::cout<< "\n";

    std::cout<< "result of A - B = ", dif.print();
    std::cout<< "\n";

    std::cout<< "result of A * B = ", mul.print();
    std::cout<< "\n";

    std::cout<< "result of A / B = ", div.print();
    std::cout<< "\n";
    std::cout << std::endl;

    std::cout << "Let's find inversed Fazzy Numbers." << std::endl;
    std::cout << "Inversed FazzyNumber 1: " <<  A.inverse() << std::endl;
    std::cout << "Inversed FazzyNumber 2: " << B.inverse() << std::endl;

    std::cout << "Comparing 2 Fazzy Numbers by x..." << std::endl;
    if (A != B) {
        std::cout << "FazzyNumber1 is not equal to FazzyNumber2" << std::endl;
        if (A > B) {
            std::cout << "FazzyNumber1 is greater than FazzyNumber2" << std::endl;
        }
        else {
            std::cout << "FazzyNumber1 is lower than FazzyNumber2" << std::endl;
        }
    }
    else {
        std::cout << "FazzyNumber1 is equal to FazzyNumber2" << std::endl;
    }
    std::cout << std::endl;

    FazzyNumber N = "3.98|4.13|4.28"_fn;
    std::cout << "Fazzy Number literals" << N << "\n";
}