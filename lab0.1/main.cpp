#include <stdio.h>
#include <stdlib.h>
#include "FazzyNumber.hpp"
#include <iostream>

void print_menu(int keyboard) {
	if (keyboard == 1){
    		system("cls");  // î÷èùàåì êîíñîëü
    		printf("What do you want to do?\n");
    		printf("1. Add two numbers\n");
    		printf("2. Difference of two numbers\n");
    		printf("3. Multiply two numbers\n");
    		printf("4. Divide two numbers\n");
    		printf("5. Reverse number\n");
    		printf("6. Exit\n");
    		printf(">");
	}
}

int main() {
	std::cout << "Input 0 if FILE input. Else KEYBOARD input\n";
    int keyboard;
    std::cin >> keyboard;
    if (keyboard == 0){
        freopen("test_01.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    }

    int variant;
    double X, e;
    do {
    	print_menu(keyboard);

    	std::cin >> variant;

    	switch(variant) {
    		case 1: {
    			if (keyboard != 0) {
    				std::cout<<"Input A in formax: X e\n";
                    std::cin>> X >> e;
                    FazzyNumber A(X,e);
                    std::cout<<"Input B in formax: X e\n";
                    std::cin>> X >> e;
                    FazzyNumber B(X,e);
                    FazzyNumber C = A + B;
                    std::cout<< "result of A + B = ", C.print();
                    std::cout<< "\n";
                    break;
    			}
    			std::cin >> X >> e;
                FazzyNumber A(X,e);
                std::cin >> X >> e;
                FazzyNumber B(X,e);
                FazzyNumber C = A + B;
                std::cout<< "result of A + B = ", C.print();
                std::cout<< "\n";
                break;
    		}

    		case 2: {
    			if (keyboard != 0 ) {
    				std::cout<<"Input A in formax: X e\n";
                    std::cin >> X >> e;
                    FazzyNumber A(X,e);
                    std::cout << "Input B in formax: X e\n";
                    std::cin >> X >> e;
                    FazzyNumber B(X,e);
                    FazzyNumber C = A - B;
                    std::cout << "result of A - B = ", C.print();
                    std::cout << "\n";
                    break;
    			}
    			else {
    				std::cin >> X >> e;
                    FazzyNumber A(X,e);
                    std::cin >> X >> e;
                    FazzyNumber B(X,e);
                    FazzyNumber C = A - B;
                    std::cout << "result of A - B = ", C.print();
                    std::cout << "\n";
                    break;
    			}
    		}

    		case 3: {
    			if (keyboard != 0) {
    				std::cout << "Input A in formax: X e\n";
                    std::cin >> X >> e;
                    FazzyNumber A(X,e);
                    std::cout <<"Input B in formax: X e\n";
                    std::cin >> X >> e;
                    FazzyNumber B(X,e);
                    FazzyNumber C = A * B;
                    std::cout << "result of A * B = ", C.print();
                    std::cout << "\n";
                    break;
    			}
    			else {
    				std::cin >> X >> e;
                    FazzyNumber A(X,e);
                    std::cin>> X >> e;
                    FazzyNumber B(X,e);
                    FazzyNumber C = A * B;
                    std::cout << "result of A * B = ", C.print();
                    std::cout << "\n";
                    break;
    			}
    		}

    		case 4: {
    			if (keyboard != 0) {
    				std::cout <<"Input A in formax: X e\n";
                    std::cin >> X >> e;
                    FazzyNumber A(X,e);
                    std::cout <<"Input B in formax: X e\n";
                    std::cin >> X >> e;
                    FazzyNumber B(X,e);
                    FazzyNumber C = A / B;
                    std::cout << "result of A / B = ", C.print();
                    std::cout << "\n";
                    break;
    			}
    			else {
    				std::cin >> X >> e;
                    FazzyNumber A(X,e);
                    std::cin >> X >> e;
                    FazzyNumber B(X,e);
                    FazzyNumber C = A / B;
                    std::cout << "result of A / B = ", C.print();
                    std::cout << "\n";
                    break;
    			}
    		}

    		case 5: {
    			if (keyboard != 0) {
    				std::cout<<"Input A in formax: X e\n";
    			}
    			std::cin >> X >> e;
                FazzyNumber A(X,e);
                FazzyNumber C = A.reverse();
                std::cout << "result of A^(-1) = ", C.print();
                std::cout << "\n";
                break;
    		}

    	}
    	if (variant != 6 && keyboard != 0) {
    		system("pause");
    	}
    } while (variant != 6);
}
