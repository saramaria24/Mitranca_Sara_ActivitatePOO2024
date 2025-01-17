#include <iostream>
#include <fstream>
#include <map>
#include <list>
using namespace std;

class Cofetarie {
protected:
	string denumire;
public:
	Cofetarie() {
		this->denumire = "Cofetarie";
	}
	Cofetarie(string nume) {
		this->denumire = nume;
	}
	virtual string getDenumire() {
		return denumire;
	}
};

class CofetarieOnline :public Cofetarie {
	string sufix;
public:
	CofetarieOnline(string nume, string sufix) :Cofetarie(nume) {
		this->sufix = sufix;
	}
	string getDenumire() {
		return denumire + " " + sufix;
	}
};

int main() {
	/ Cofetarie cof = new CofetarieOnline();

	cout << cof->getDenumire();

	int a;
	cin >> a;
	cout << "patratul este" << a * a << endl;
	fstream f("fisier.dat", ios::out | ios::binary); */

		map<int, float> valori;
	valori.insert(pair<int, float>(7, 75.8));
	valori.insert(pair<int, float>(23, 102.6));
	valori.insert(pair<int, float>(3, 32.3));
	valori.insert(pair<int, float>(23, 23));

	valori[12] = 45.5;

	cout << valori[12] << endl;

	map<int, float>::iterator it;
	it = valori.begin();

	while (it != valori.end())
	{
		cout << it->first << "=>" << it->second << endl;
		it++;
	}

	list<Cofetarie*> Cofetarii;
	Cofetarii.push_back(new Cofetarie("Ana Pan"));
	Cofetarii.push_back(new CofetarieOnline("Delicii", "Dorobanti"));
	Cofetarii.push_front(new Cofetarie("Dulcinella"));

	for (list<Cofetarie*>::iterator i = Cofetarii.begin(); i != Cofetarii.end(); i++) {
		cout << (*i)->getDenumire() << endl;
	}

	return 322;
}
