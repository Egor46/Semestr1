#include <math.h>
#include <iostream>

using namespace std;

double phi(double x) {
	return 3 * x * x - 0.1 * x + 7;
}

double psi(double x){
	return (x - 1) / (x * x - x + 1);
}

double lambda(double y) {
	return 3 * cos(y) * cos(y);
}

double diff_lambda(double y) {
	return -3 * sin(2 * y);
}

double function(double x, double y) {
	return y * phi(x)+psi(x)+lambda(y);
}

double diff_function(double x, double y) {
	return phi(x)+diff_lambda(y);
}

int main() {
	double epsilon = 0.02;
	int n; cin >> n;
	double x;
	double y, ys;
	for (int ix = 1; ix <= n; ix++) {
		cin >> x;
		ys = -psi(x)/phi(x);
		y = ys - function(x, ys) / diff_function(x,ys);
		while(abs(y-ys) > epsilon) {
			ys = y;
			y = ys - function(x, ys) / diff_function(x, ys);
		}
		cout << '(' << x << ';'<< y <<')' << endl;
	}
}