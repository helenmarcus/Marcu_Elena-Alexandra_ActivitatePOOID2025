#include <iostream>
#include<string>
using namespace std;

// -----Clasa 1: Eveniment-----
class Eveniment{
public:
	//atribute normale
	string nume;
	string locatie;
	int durataMinute;

	const int idEveniment; //atribut constant

	static int nrEvenimente; //atribut static

	int* bileteDisponibile; //pointer (HEAP) - bilete disponibile

	//constructor fara parametri
	Eveniment() : idEveniment(++nrEvenimente) {
		nume = "TBD";
		locatie = "TBD";
		durataMinute = 0;
		bileteDisponibile = new int(0); //alocare dinamica
	}
	//constructor cu 2 parametri
	Eveniment(string nume, string locatie) : idEveniment(++nrEvenimente) {
		this->nume = nume;
		this->locatie = locatie;
		durataMinute = 0;
		bileteDisponibile = new int(0); //alocare dinamica
	}
	//constructor cu 4 parametri
	Eveniment(string nume, string locatie, int durata, int bilete) : idEveniment(++nrEvenimente) {
		this->nume = nume;
		this->locatie = locatie;
		this->durataMinute = durata;
		bileteDisponibile = new int(bilete); //alocare dinamica
	}
	// functie statica - calculeaza durata medie
	static float durataMedie(int durataTotala, int nrEv) {
		if (nrEv == 0) return 0;
		return (float)durataTotala / nrEv;
	}
	void afiseaza() {
		cout << "Eveniment ID:" << idEveniment
		<< ", nume:" << nume
		<< ", locatie:" << locatie
		<< ", durata:" << durataMinute << " minute"
		<< ", bilete disponibile:" << *bileteDisponibile << endl;
	}
};
int Eveniment::nrEvenimente = 0; //initializare atribut static