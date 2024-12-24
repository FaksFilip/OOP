#pragma once
#include <iostream>
#include <fstream>
#include "Putnik.h"

using namespace std;

class Autobus
{
private:
	Putnik** niz;
	int trenutni;
	int kapacitet;
public:
	Autobus();
	Autobus(int _kapacitet);
	Autobus(const Autobus& a);
	~Autobus();

	Autobus& operator=(const Autobus& a);

	void Dodaj(Putnik* p);
	Putnik* MaxOprema();

	void Upisi(const char* imefajla);

	int BrojPutnika()
	{
		return kapacitet;
	}
	double UkupnaOprema()
	{
		double suma = 0.0;
		for (int i = 0; i < trenutni; i++)
		{
			suma += niz[i]->Masa();
		}
		return suma;
	}

	friend Autobus operator+(const Autobus& a1, const Autobus& a2)
	{
		Autobus a(a1.kapacitet + a2.kapacitet);
		for (int i = 0; i < a1.trenutni; i++)
		{
			a.Dodaj(a1.niz[i]->Kopija());
		}
		for (int i = 0; i < a2.trenutni; i++)
		{
			a.Dodaj(a2.niz[i]->Kopija());
		}
		return a;
	}

	friend ostream& operator<<(ostream& izlaz, const Autobus& p)
	{
		izlaz << "Trenutni: " << p.trenutni << endl;
		izlaz << "Kapacitet: " << p.kapacitet << endl;
		for (int i = 0; i < p.trenutni; i++)
		{
			izlaz << "Niz: " << p.niz[i] << endl;
		}
		return izlaz;
	}
	friend ostream& operator<<(ostream& izlaz, const Autobus* p)
	{
		izlaz << "Trenutni: " << p->trenutni << endl;
		izlaz << "Kapacitet: " << p->kapacitet << endl;
		for (int i = 0; i < p->trenutni; i++)
		{
			izlaz << "Niz: " << p->niz[i] << endl;
		}
		return izlaz;
	}
};

