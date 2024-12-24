#pragma once
#include <iostream>
#include "Proizvod.h"

using namespace std;

class Igracka :public Proizvod
{
private:
	double osmeh;
public:
	Igracka() :Proizvod()
	{
		osmeh = 0.0;
	}
	Igracka(double cena, double masa, double _osmeh) :Proizvod(cena, masa)
	{
		osmeh = _osmeh;
	}
	Igracka(const Igracka& i) :Proizvod(i)
	{
		if (this != &i)
		{
			osmeh = i.osmeh;
		}
	}
	~Igracka()
	{

	}

	void Print(ostream& izlaz)const
	{
		izlaz << "Cena: " << cena << endl;
		izlaz << "Masa: " << masa << endl;
		izlaz << "Osmeh: " << osmeh << endl;
	}
	Proizvod* Kopija()const
	{
		return new Igracka(cena, masa, osmeh);
	}

	double Vrednost()
	{
		return (cena * masa + cena * osmeh);
	}
};

