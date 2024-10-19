#include <iostream>
using namespace std;

class Masina {
public:
	int nrRoti;
	string Marca;
	float Pret;
	static int TVA;
	const int anFabricatie;

	Masina() :anFabricatie(2024) {
		this->nrRoti = 4;
		this->Marca = "Dacia";
		this->Pret = 5000;
	}
	Masina(int _nrRoti, string Marca, float Pret, int an) :anFabricatie(an) {
		this->nrRoti = _nrRoti;
		this->Marca = Marca;
		this->Pret = Pret;
	}
	void afisare() {
		cout << "Marca" << this->Marca << endl;
		cout << "Nr Roti" << this->nrRoti << endl;
		cout << "Pret" << this->Pret << endl;
		cout << "An fabricatie" << this->anFabricatie << endl;
	}
	float calculeazaPretTotal() {
		return this->Pret + (this->Pret * (Masina::TVA / 100.0f));
	}
	static void modificaTVA(int noulTVA) {
		if (noulTVA > 0)
			Masina::TVA = noulTVA;
	}
	static float calculeazaPretTotalVector(int nrMasini, Masina* vector) {
		float pretTotal = 0;
		for (int i = 0; i < nrMasini; i++) {
			pretTotal += vector[i].calculeazaPretTotal();
			return pretTotal;
		}

	}
};

int Masina::TVA = 19;


int main()
{
	Masina m;
	m.afisare();
	Masina m2(4, "Audi", 7000, 2020);
	m2.afisare();
	Masina::modificaTVA(21);
	Masina* pointer = new Masina(6, "Volvo", 20000, 2022);
	pointer->afisare();
	cout << "pret total" << pointer->calculeazaPretTotal();
	int nrMasini = 3;
	Masina* vector;
	vector = new Masina[nrMasini];
	for (int i = 0; i < nrMasini; i++) {
		vector[i].afisare();
	}
	cout << "pret total flota" << Masina::calculeazaPretTotalVector(nrMasini, vector) << endl;
	return 1000;

}