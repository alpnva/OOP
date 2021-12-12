#ifndef FAZZYNUMBER_H
#define FAZZYNUMBER_H

#include <iostream>

class FazzyNumber {
public:
	FazzyNumber(double X_in, double e_in);
	double get_l();
    double get_x();
    double get_r();
    double get_er();
    double get_el();
    void print();
    FazzyNumber operator+ (const FazzyNumber& a);
    FazzyNumber operator- (const FazzyNumber& a);
    FazzyNumber operator* (const FazzyNumber& a);
    FazzyNumber operator/ (const FazzyNumber& a);
    FazzyNumber inverse();
    bool operator> (const FazzyNumber& a);
    bool operator>= (const FazzyNumber& a);
    bool operator< (const FazzyNumber& a);
    bool operator<= (const FazzyNumber& a);
    bool operator== (const FazzyNumber& a);
    bool operator!= (const FazzyNumber& a);

    FazzyNumber(double L_in, double X_in, double R_in) {
        L = L_in;
        X = X_in;
        R = R_in;
    }

    friend std::ostream& operator<<(std::ostream& os, FazzyNumber other);
    friend std::istream& operator>>(std::istream& is, FazzyNumber other);
private:
	double L, X, R;

};

FazzyNumber operator""_fn(const char* string, size_t size);


#endif 