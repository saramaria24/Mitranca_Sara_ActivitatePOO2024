#include <iostream>
using namespace std;
class Masina {
private:
	int nrroti;
	string marca;
	string* producatori; // lungimea vect de productori TINE CONT de nrroti
	float pret;
	static int tva;
	//static apartine clasei, nu obiectelor, se initializeaza global
	const int anFabricatie; // NU ARE VOIE SA APARA IN STANGA EGALULUI CONSTANTA
	//constructor fara parametri, implicit
public: Masina() :anFabricatie(2024)
{
	this->nrroti = 4;
	this->marca = "Dacia";
	this->pret = 5000;
	this->producatori = nullptr;
}
	  Masina(int _nrRoti, string marca, float pret, int an) :anFabricatie(an)// cand e in paranteza merge sa-l numesc exact ca constanta
	  {
		  this->nrroti = _nrRoti;
		  this->marca = marca;
		  this->pret = pret;
		  this->producatori = new string[this->nrroti];
		  for (int i = 0; i < this->nrroti; i++)
			  this->producatori[i] = "Michelin";
	  }
	  Masina(const Masina& m) :anFabricatie(m.anFabricatie) {
		  this->nrroti = m.nrroti;
		  this->marca = m.marca;
		  this->pret = m.pret;
		  this->producatori = new string[m.nrroti];
		  for (int i = 0; i < m.nrroti; i++) {
			  this->producatori[i] = m.producatori[i];
		  }

	  }
	  ~Masina() {
		  if (this->producatori != NULL)
		  {
			  delete[]this->producatori;

		  }
	  }
	  string getmarca()
	  {
		  return this->marca;
	  }
	  void setmarca(string marca)
	  {
		  if (marca.length() > 2)
			  this->marca = marca;
	  }
	  float getpret()
	  {
		  return this->pret;
	  }
	  string* getproducatori()
	  {
		  return this->producatori;
	  }

	  string getproducator(int index)
	  {
		  if (index >= 0 && index < this->nrroti)
			  return this->producatori[index];
		  else return "NU a fost gasit";
	  }
	  void setnrroti(int nrroti, string* producatori)
	  {
		  if (nrroti > 0)
		  {
			  this->nrroti = nrroti;
			  if (this->producatori != nullptr)
				  delete[] this->producatori;
		  }
		  this->producatori = new string[this->nrroti];
		  for (int i = 0; i < nrroti; i++)
			  this->producatori[i] = producatori[i];
	  }
	  //constructor cu parametri
	  void afisare()
	  {
		  cout << "Marca: " << this->marca << endl;
		  cout << "Nr roti: " << this->nrroti << " : ";
		  if (this->producatori)
			  for (int i = 0; i < this->nrroti; i++)
				  cout << this->producatori[i] << " , ";
		  cout << "Pret: " << this->pret << endl;
		  cout << "TVA: " << this->tva << endl;
		  cout << "An Fabricatie: " << this->anFabricatie << endl;
	  }
	  float Calculeaza_Pret_Total()
	  {
		  return this->pret + (this->pret * ((float)Masina::tva / 100));//sau daca vreau mai simplu impart fara (float) la /100.0f
	  }
	  static void modificaTva(int tvanou)//NU va folosi this, ca nu e metoda
	  {
		  if (tvanou > 0)
			  Masina::tva = tvanou;
	  }
	  static float Calculeaza_Pret_Total_Vector(Masina* v, int nrmasini)
	  {
		  float prettotal = 0;
		  for (int i = 0; i < nrmasini; i++)
		  {
			  prettotal += v[i].Calculeaza_Pret_Total();
		  }
		  return prettotal;
	  }
};

int Masina::tva = 19;
int main() {
	//Masina m1;
	//Masina m2(4, "Audi", 7000, 2020);
	///m1.afisare();/
	//Masina* ptr = new Masina(6, "Volvo", 20000, 2022);
	//ptr->afisare();//asa faci pentru pointeri
	//m2.afisare();
	//Masina::modificaTva(20);
	//cout << "Pret Total: " << ptr->Calculeaza_Pret_Total();
	//Masina* vector;
	//int nrMasini = 3;
	//vector = new Masina[nrMasini];
	//for (int i = 0; i < nrMasini; i++)
	//vector[i].afisare();
	//cout << "Pret total flota:" << Masina::Calculeaza_Pret_Total_Vector(vector, nrMasini);
	//delete[] vector;// nu am facut stergerea din heap lol
	////[] - deplasare+deferentiere
	////-> - deferentiere+deplasare
	Masina m;
	cout << m.getmarca() << endl;
	m.setmarca("Toyota");
	cout << m.getmarca() << endl;
	m.afisare();
	Masina m2(4, "BMW", 45000, 2021);
	m2.afisare();
	cout << m2.getproducatori()[1] << endl;
	cout << m2.getproducator(1) << endl;
	m2.setnrroti(6, new string[6]{ "Michelin", "Bridgestone", "Pirelli", "Continental", "Hankoover", "POO" });
	cout << m2.getproducator(5);
}





//    Masina m1;
//    m1.afisare();
//    
//    Masina m2(4,"Audi",7000,2020);
//    m2.afisare();
//    
//    Masina::modificaTVA(21);
//    Masina* pointer=new Masina(6,"Volvo",20000,2022);
//    pointer->afisare();
//    
//    cout<<"Pret total: "<<pointer->calculeazaPretTotal()<<endl;
//    
//    int nrMasini=3;
//    Masina* vector;
//    vector=new Masina[nrMasini];
//    
//    for(int i=0; i<nrMasini; i++){
//        //(*(vector+i)).afisare();
//        //(vector+i)->afisare();
//        vector[i].afisare();
//    }
//    
//    cout<<"Pret total flot?: "<<Masina::calculeazaPretTotalVector(nrMasini, vector)<<endl;
//    //-> - dereferentiere + accesare
//    //[] - deplasare + dereferentiere
//    
//    return 1000;