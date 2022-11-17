#include <math.h>
#include <iostream>

using namespace std;

double phi(double x) {
	return 3 * x * x - 0.1 * x + 7; // функция φ(x) вставить нужную из условия
}

double psi(double x){
	return (x - 1) / (x * x - x + 1); // функция ψ(x) всавить нужную из условия
}

double lambda(double y) {
	return 3 * cos(y) * cos(y); // функция лямбда, вставить нужную из условия
}

double diff_lambda(double y) {
	return -3 * sin(2 * y); // производная от лямбды, вставить из условия
}

double function(double x, double y) {
	return y * phi(x)+psi(x)+lambda(y); // остальное менять не нужно
}

double diff_function(double x, double y) {
	return phi(x)+diff_lambda(y);
}

int main() {
	double epsilon = 0.02; // кроме этого очевидно
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
