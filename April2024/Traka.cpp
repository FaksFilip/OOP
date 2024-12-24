#include "Traka.h"

Traka::Traka()
{
	trenutni = 0;
	kapacitet = 0;
	niz = nullptr;
}

Traka::Traka(int kap)
{
	trenutni = 0;
	kapacitet = kap;
	niz = new Proizvod* [kap];
}

Traka::Traka(const Traka& t)
{
	if (this != &t)
	{
		trenutni = 0;
		kapacitet = t.kapacitet;
		niz = new Proizvod * [t.kapacitet];
		for (int i = 0; i < t.kapacitet; i++)
		{
			Add(t.niz[i]->Kopija());
		}
	}
}

Traka::~Traka()
{
	if (niz != nullptr)
	{
		for (int i = 0; i < kapacitet; i++)
		{
			delete niz[i];
		}
		delete[] niz;
	}
}

void Traka::Add(Proizvod* p)
{
	if (trenutni < kapacitet)
	{
		niz[trenutni++] = p;
	}
}

void Traka::Save(const char* imefajla)
{
	ofstream f(imefajla);

	if (!f.good())
	{
		cout << "Greska" << endl;
	}
	else
	{
		f << *this;
	}
	f.close();
}

Proizvod* Traka::Max()
{
	Proizvod* max = niz[0];
	for (int i = 1; i < trenutni; i++)
	{
		if (max->Vrednost() < niz[i]->Vrednost())
		{
			max = niz[i];
		}
	}
	return max;
}
Proizvod* Traka::RemoveMinimum()
{
	Proizvod* min = niz[0];
	int indeks = 0;
	for (int i = 1; i < trenutni; i++)
	{
		if (min->Vrednost() > niz[i]->Vrednost())
		{
			min = niz[i];
			indeks = i;
		}
	}
	for (int j = indeks; j < trenutni - 1; j++)
	{
		niz[j] = niz[j++];
	}
	trenutni--;
    
	return min;
}
