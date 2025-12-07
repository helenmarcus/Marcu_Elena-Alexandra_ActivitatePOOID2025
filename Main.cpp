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

// -----Clasa 2: Artist-----
class Artist {
public:
	// atribute normale
	string nume;
	string genArtistic;
	int varsta;

	const int idArtist;       // atribut constant
	static int nrArtisti;     // atribut static

	float* tarif;             // pointer (HEAP) - tarif pe eveniment in EUR

	// constructor fara parametri
	Artist() : idArtist(++nrArtisti) {
		nume = "TBD";
		genArtistic = "TBD";
		varsta = 0;
		tarif = new float(0.0f);   // alocare dinamica
	}

	// constructor cu 2 parametri
	Artist(string nume, string genArtistic) : idArtist(++nrArtisti) {
		this->nume = nume;
		this->genArtistic = genArtistic;
		varsta = 0;
		tarif = new float(0.0f);   // alocare dinamica
	}

	// constructor cu 4 parametri
	Artist(string nume, string genArtistic, int varsta, float tarifEuro)
		: idArtist(++nrArtisti) {
		this->nume = nume;
		this->genArtistic = genArtistic;
		this->varsta = varsta;
		tarif = new float(tarifEuro); // alocare dinamica
	}

	// functie statica - calculeaza tariful mediu
	static float tarifMediu(float total, int nrA) {
		if (nrA == 0) return 0;
		return total / nrA;
	}

	void afiseaza() {
		cout << "Artist ID:" << idArtist
			<< ", nume:" << nume
			<< ", gen artistic:" << genArtistic
			<< ", varsta:" << varsta
			<< ", tarif:" << *tarif << " EUR"
			<< endl;
	}
};

// initializare atribut static pentru Artist
int Artist::nrArtisti = 0;

// -----Clasa 3: Manager-----
class Manager {
public:
	// atribute normale
	string nume;
	string telefon;

	const int idManager;      // atribut constant
	static int nrManageri;    // atribut static

	int* aniExperienta;       // pointer (HEAP) - ani de experienta

	// constructor fara parametri
	Manager() : idManager(++nrManageri) {
		nume = "TBD";
		telefon = "TBD";
		aniExperienta = new int(0);   // alocare dinamica
	}

	// constructor cu 2 parametri
	Manager(string nume, string telefon) : idManager(++nrManageri) {
		this->nume = nume;
		this->telefon = telefon;
		aniExperienta = new int(0);   // alocare dinamica
	}

	// constructor cu 3 parametri
	Manager(string nume, string telefon, int aniExp)
		: idManager(++nrManageri) {
		this->nume = nume;
		this->telefon = telefon;
		aniExperienta = new int(aniExp); // alocare dinamica
	}

	// functie statica - experienta medie
	static float experientaMedie(int totalAni, int nrM) {
		if (nrM == 0) return 0;
		return (float)totalAni / nrM;
	}

	void afiseaza() {
		cout << "Manager ID:" << idManager
			<< ", nume:" << nume
			<< ", telefon:" << telefon
			<< ", ani experienta:" << *aniExperienta
			<< endl;
	}
};

// initializare atribut static pentru Manager
int Manager::nrManageri = 0;


int main() {
	Eveniment e1;
	e1.afiseaza();

	Eveniment e2("Concert rock", "Bucuresti");
	e2.afiseaza();

	Eveniment e3("Expozitie pictura", "Cluj", 120, 200);
	e3.afiseaza();

	return 0;
}
