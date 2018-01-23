#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

#define PI 3.1415926535;

/*
	Ampere's Law:
	DEL x B = mu0 * J

	Faraday's Law:
	emf = -N * d(flux) / dt

*/


/*class Field {
	string name;
	int size;
	vector<double> v;
public:
	Field(const string & _name, int _size) : name(_name), size(_size) {
		v.reserve(size);
	}

	update
};*/


int main() {

	const int STEPS = 200;

	const double IMP_FREE = 120 * PI;

	const int MAX_TIME = 250;

	// ex, hy, propagate in z, example uses ez

	double ex[STEPS] = {0};
	double hy[STEPS] = {0};

	for(int t = 0; t < MAX_TIME; ++t) {
		for(int i = 0; i < STEPS - 1; ++i)
			hy[i] += (ex[i + 1] - ex[i]) / IMP_FREE;

		for(int i = 0; i < STEPS; ++i)
			ex[i] += (hy[i] - hy[i - 1]) * IMP_FREE;

		ex[0] = exp(-(t - 30) * (t - 30) / 100); // why is this a normal dist?

		cout << ex[50] << endl;
	}

}
