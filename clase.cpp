#include <iostream>
#include<string>
using namespace std;
class Marker {
public:
	string culoare;
public:
	float greutate;
public:
	int lungime;
	void afisare()
	{
		cout << "culoare:" << this->culoare << endl;
		cout << "lungime:" << this->lungime << endl;
		cout << "greutate:" << this->greutate << endl;

	}
};
void main() {
	Marker marker1;
	marker1.greutate = 45;
	marker1.lungime = 12;
	marker1.culoare = "Albastru";
	marker1.afisare();

}