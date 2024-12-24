#pragma once
#include "Proizvod.h"
#include "Cokolada.h"
#include "Igracka.h"
#include <iostream>
#include <fstream>

using namespace std;

class Traka
{
private:
	Proizvod** niz;
	int trenutni;
	int kapacitet;
public:
	Traka();
	Traka(int kap);
	Traka(const Traka& t);
	~Traka();

	friend ostream& operator<<(ostream& izlaz, const Traka& t)
	{
		izlaz << "Trenutni: " << t.trenutni << endl;
		izlaz << "Kapacitet: " << t.kapacitet << endl;
		for (int i = 0; i < t.trenutni; i++)
		{
			izlaz << "Niz: " << t.niz[i] << endl;
		}
		return izlaz;
	}
	friend ostream& operator<<(ostream& izlaz, const Traka* t)
	{
		izlaz << "Trenutni: " << t->trenutni << endl;
		izlaz << "Kapacitet: " << t->kapacitet << endl;
		for (int i = 0; i < t->trenutni; i++)
		{
			izlaz << "Niz: " << t->niz[i] << endl;
		}
		return izlaz;
	}

	friend Traka operator+(const Traka& t1, const Traka& t2)
	{
		Traka t(t1.kapacitet + t2.kapacitet);
		for (int i = 0; i < t1.trenutni; i++)
		{
			t.Add(t1.niz[i]->Kopija());
		}
		for (int i = 0; i < t2.trenutni; i++)
		{
			t.Add(t2.niz[i]->Kopija());
		}
		return t;
	}

	void Add(Proizvod* p);
	void Save(const char* imefajla);

	Proizvod* Max();
	Proizvod* RemoveMinimum();

	int BrojProizvoda()
	{
		return kapacitet;
	}
};

