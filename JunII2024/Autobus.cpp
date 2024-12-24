#include "Autobus.h"

Autobus::Autobus()
{
	trenutni = 0;
	kapacitet = 0;
	niz = nullptr;
}

Autobus::Autobus(int _kapacitet)
{
	trenutni = 0;
	kapacitet = _kapacitet;
	niz = new Putnik * [_kapacitet];
}

Autobus::Autobus(const Autobus& a)
{
	if (this != &a)
	{
		trenutni = a.trenutni;
		kapacitet = a.kapacitet;
		niz = new Putnik* [a.kapacitet];
		for (int i = 0; i < trenutni; i++)
		{
			niz[i] = a.niz[i]->Kopija();
		}
	}
}

Autobus::~Autobus()
{
	if (niz != nullptr)
	{
		for (int i = 0; i < kapacitet; i++)
			delete niz[i];
	}
	delete[] niz;
}

Autobus& Autobus::operator=(const Autobus& a) 
{
	if (this == &a) return *this;

	// Clean up existing data
	for (int i = 0; i < trenutni; i++) 
	{
		delete niz[i];
	}
	delete[] niz;

	// Copy new data
	kapacitet = a.kapacitet;
	trenutni = a.trenutni;
	niz = new Putnik * [kapacitet];
	for (int i = 0; i < a.trenutni; i++) 
        {
		niz[i] = a.niz[i]->Kopija();
	}
	return *this;
}

void Autobus::Dodaj(Putnik* p)
{
	if (trenutni < kapacitet)
	{
		niz[trenutni++] = p;
	}
}

Putnik* Autobus::MaxOprema()
{
	Putnik* max = niz[0];
	int indeks = 0;
	for (int i = 1; i < trenutni; i++)
	{
		if (max->Masa() < niz[i]->Masa())
		{
			max = niz[i];
			indeks = i;
		}
	}
	for (int i = indeks; i < trenutni - 1; i++)
	{
		niz[i] = niz[i + 1];
	}
	trenutni--;

	return max->Kopija();
}

void Autobus::Upisi(const char* imefajla)
{
	ofstream f(imefajla);
	if (!f.good())
		cout << "Greska" << endl;
	else
	{
		f << *this;
	}
	f.close();
}
