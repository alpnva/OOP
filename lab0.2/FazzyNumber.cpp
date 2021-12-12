#include "FazzyNumber.h"

FazzyNumber::FazzyNumber(double X_in, double e_in) {
	L = X_in - e_in;
	X = X_in;
	R = X_in + e_in;
}

double FazzyNumber::get_l() {
    return L;
}
double FazzyNumber::get_x() { 
    return X;
}
double FazzyNumber::get_r() {
    return R;
}
double FazzyNumber::get_er() {
    return R-X;
}
double FazzyNumber::get_el() {
    return X-L;
}


void FazzyNumber::print() {
    std::cout << std::fixed;
    std::cout.precision(3);
    std::cout << "(" << "L = " << L << ", X = " << X << ", R = " << R << ")" << std::endl;
}
    
FazzyNumber FazzyNumber::operator+ (const FazzyNumber& a) {
    FazzyNumber res(L + a.L, X + a.X, R + a.R);
    return res;
}
FazzyNumber FazzyNumber::operator- (const FazzyNumber& a) {
    FazzyNumber res(L - a.L, X - a.X, R - a.R);
    return res;
}
FazzyNumber FazzyNumber::operator* (const FazzyNumber& a) {
    FazzyNumber res(L * a.L, X * a.X, R * a.R);
    return res;
}
FazzyNumber FazzyNumber::operator/ (const FazzyNumber& a) {
    if (a.X > 0) {
    	FazzyNumber res(L / a.L, X / a.X, R / a.R);
    	return res;
    } else {
    	std::cout << "Error\n" << std::endl;
    	FazzyNumber err(0,0);
    	return err;
    }
}

FazzyNumber FazzyNumber::inverse() {
    if (X > 0) {
    	FazzyNumber res(1 / R, 1 / X, 1 / L);
    	return res;
    } else {
    	std::cout << "Error\n" << std::endl;;
    	return err;
    }
}

bool FazzyNumber::operator> (const FazzyNumber& a) {
    return (X > a.X);
}
bool FazzyNumber::operator>= (const FazzyNumber& a) {
    return (X >= a.X);
}
bool FazzyNumber::operator< (const FazzyNumber& a) {
    return (X < a.X);
}
bool FazzyNumber::operator<= (const FazzyNumber& a) {
    return (X <= a.X);
}
bool FazzyNumber::operator== (const FazzyNumber& a) {
    return (X == a.X);
}
bool FazzyNumber::operator!= (const FazzyNumber& a) {
    return (X != a.X);
}

std::ostream& operator<<(std::ostream& os, FazzyNumber other)
{
    os << "(" << other.L << ", " << other.X << ", " << other.R << ")";
    return os;
}
    
std::istream& operator>>(std::istream& is, FazzyNumber other)
{
    is >> other.L >> other.X >> other.R;
    return is;
}

FazzyNumber operator""_fn(const char* string, size_t size)
{
    std::string a = "";
    int ind = 0;
    float nums[3];
    for (int i = 0; i < 3; i++) {
        while(string[ind] != '|') {
            a += string[ind];
            ++ind;
        }
        nums[i] = atof(a.c_str());
        a = "";
        ++ind;
    }
    return FazzyNumber(nums[0], nums[1], nums[2]);
}