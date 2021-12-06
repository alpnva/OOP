#include <cstdio>
#include <iostream>
class FazzyNumber {
public:
	FazzyNumber(double X_in, double e_in) {
		L = X_in - e_in;
		X = X_in;
		R = X_in + e_in;
	};
	double get_l() {
		return L;
	}
    double get_x() { 
    	return X;
    }
    double get_r() {
    	return R;
    }
    double get_er() {
    	return R-X;
    }
    double get_el() {
    	return X-L;
    }
    void print() {
    	std::cout << std::fixed;
    	std::cout.precision(3);
    	std::cout << L << X << R << std::endl;
    	}
    FazzyNumber operator+ (FazzyNumber a) {
    	FazzyNumber res(L + a.L, X + a.X, R + a.R);
    	return res;
    }
    FazzyNumber operator- (FazzyNumber a) {
    	FazzyNumber res(L - a.L, X - a.X, R - a.R);
    	return res;
    }
    FazzyNumber operator* (FazzyNumber a) {
    	FazzyNumber res(L * a.L, X * a.X, R * a.R);
    	return res;
    }
    FazzyNumber operator/ (FazzyNumber a) {
    	if (a.X > 0) {
    		FazzyNumber res(L / a.L, X / a.X, R / a.R);
    		return res;
    	} else {
    		std::cout << "Error\n" << std::endl;
    		FazzyNumber err(0,0);
    		return err;
    	}
    }
    FazzyNumber reverse() {
    	if (X > 0) {
    		FazzyNumber res(1 / R, 1 / X, 1 / L);
    		return res;
    	} else {
    		std::cout << "Error\n" << std::endl;;
    		FazzyNumber err(0,0);
    		return err;
    	}
    }

    bool operator> (FazzyNumber a) {
    	return (X > a.X);
    }
    bool operator>= (FazzyNumber a) {
    	return (X >= a.X);
    }
    bool operator< (FazzyNumber a) {
    	return (X < a.X);
    }
    bool operator<= (FazzyNumber a) {
    	return (X <= a.X);
    }
    bool operator== (FazzyNumber a) {
    	return (X == a.X);
    }
    bool operator!= (FazzyNumber a) {
    	return (X != a.X);
    }

private:
	double L, X, R;
	FazzyNumber(double L_in, double X_in, double R_in) {
		L = L_in;
		X = X_in;
		R = R_in;
	}
};