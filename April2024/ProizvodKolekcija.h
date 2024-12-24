#pragma once
#include <iostream>
#include <fstream>

using namespace std;


class ProizvodKolekcija
{
private:
	bool defektan;
	int vrednost;
public:
	ProizvodKolekcija();
	ProizvodKolekcija(bool _def, int _vred);
	ProizvodKolekcija(const ProizvodKolekcija& p);
	~ProizvodKolekcija();

	template<class T>
	T operator+(T a)
	{
		return (this->vrednost + a);
	}

	bool operator<(int a)
	{
		return (this->vrednost < a);
	}
	bool operator<(ProizvodKolekcija a)
	{
		return (this->vrednost < a.vrednost);
	}

	friend ostream& operator<<(ostream& izlaz, const ProizvodKolekcija& k)
	{
		izlaz << "Defektan: " << k.defektan << endl;
		izlaz << "Vrednost: " << k.vrednost << endl;
		return izlaz;
	}
	friend ostream& operator<<(ostream& izlaz, const ProizvodKolekcija* k)
	{
		izlaz << "Defektan: " << k->defektan << endl;
		izlaz << "Vrednost: " << k->vrednost << endl;
		return izlaz;
	}
	friend istream& operator>>(istream& ulaz, ProizvodKolekcija& k)
	{
		ulaz >> k.defektan;
		ulaz >> k.vrednost;
		return ulaz;
	}
	friend istream& operator>>(istream& ulaz, ProizvodKolekcija* k)
	{
		ulaz >> k->defektan;
		ulaz >> k->vrednost;
		return ulaz;
	}
};
