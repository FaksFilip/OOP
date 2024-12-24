#pragma once
#include <iostream>
#include "Proizvod.h"

using namespace std;

class Cokolada:public Proizvod
{
private:
	double kakao;
public:
	Cokolada() :Proizvod()
	{
		kakao = 0.0;
	}
	Cokolada(double cena, double masa, double _kakao) :Proizvod(cena, masa)
	{
		kakao = _kakao;
	}
	Cokolada(const Cokolada& c) :Proizvod(c)
	{
		if (this != &c)
		{
			kakao = c.kakao;
		}
	}
	~Cokolada()
	{

	}

	void Print(ostream& izlaz)const
	{
		izlaz << "Cena: " << cena << endl;
		izlaz << "Masa: " << masa << endl;
		izlaz << "Kakao: " << kakao << endl;
	}
	Proizvod* Kopija()const
	{
		return new Cokolada(cena, masa, kakao);
	}

	double Vrednost()
	{
		return (cena + 0.01 * kakao * masa);
	}
};

