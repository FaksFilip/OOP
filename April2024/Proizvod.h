#pragma once
#include <iostream>

using namespace std;

class Proizvod
{
protected:
	double cena;
	double masa;
public:
	Proizvod();
	Proizvod(double _cena, double _masa);
	Proizvod(const Proizvod& p);
	virtual ~Proizvod();

	friend ostream& operator<<(ostream& izlaz, const Proizvod& p)
	{
		p.Print(izlaz);
		return izlaz;
	}
	friend ostream& operator<<(ostream& izlaz, const Proizvod* p)
	{
		p->Print(izlaz);
		return izlaz;
	}

	virtual void Print(ostream& izlaz)const = 0;
	virtual Proizvod* Kopija()const = 0;

	virtual double Vrednost() = 0;

};

