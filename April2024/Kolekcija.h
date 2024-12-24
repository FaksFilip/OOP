#pragma once
#include <iostream>
#include <fstream>

using namespace std;

template <class T>
class Kolekcija
{
private:
	T* niz;
	int trenutni;
	int kapacitet;
public:
	Kolekcija();
	Kolekcija(int _kapacitet);
	Kolekcija(const Kolekcija<T>& k);
	~Kolekcija();

	void DodajPodatak(T& t);
	void Obrisi(int rbr);

	double OdrediProsek();
	T NajvecaVrednost();

	void Sacuvaj(const char* imefajla);
	void Ucitaj(const char* imefajla);

	friend ostream& operator<<(ostream& izlaz, const Kolekcija<T>& k)
	{
		izlaz << "Trenutni: " << k.trenutni << endl;
		izlaz << "Kapacitet: " << k.kapacitet << endl;
		for (int i = 0; i < k.trenutni; i++)
		{
			izlaz << "Niz: " << k.niz[i] << endl;
		}
		return izlaz;
	}
	friend ostream& operator<<(ostream& izlaz, const Kolekcija<T>* k)
	{
		izlaz << "Trenutni: " << k->trenutni << endl;
		izlaz << "Kapacitet: " << k->kapacitet << endl;
		for (int i = 0; i < k->trenutni; i++)
		{
			izlaz << "Niz: " << k->niz[i] << endl;
		}
		return izlaz;
	}
	friend istream& operator>>(istream& ulaz, Kolekcija<T>& k)
	{
		ulaz >> k.trenutni;
		ulaz >> k.kapacitet;
		for (int i = 0; i < k.trenutni; i++)
		{
			ulaz >> k.niz[i];
		}
		return ulaz;
	}
	friend istream& operator>>(istream& ulaz, Kolekcija<T>* k)
	{
		ulaz >> k->trenutni;
		ulaz >> k->kapacitet;
		for (int i = 0; i < k->trenutni; i++)
		{
			ulaz >> k->niz[i];
		}
		return ulaz;
	}
};

template<class T>
inline Kolekcija<T>::Kolekcija()
{
	trenutni = 0;
	kapacitet = 0;
	niz = nullptr;
}

template<class T>
inline Kolekcija<T>::Kolekcija(int _kapacitet)
{
	trenutni = 0;
	kapacitet = _kapacitet;
	niz = new T[kapacitet];
}

template<class T>
inline Kolekcija<T>::Kolekcija(const Kolekcija<T>& k)
{
	if (this != &k)
	{
		trenutni = 0;
		kapacitet = k.kapacitet;
		niz = new T[kapacitet];
		for (int i = 0; i < k.kapacitet; i++)
		{
			DodajPodatak(k.niz[i]);
		}
	}
}

template<class T>
inline Kolekcija<T>::~Kolekcija()
{
	if (niz != nullptr)
		delete[] niz;
}

template<class T>
inline void Kolekcija<T>::DodajPodatak(T& t)
{
	try
	{
		if (trenutni >= kapacitet)
		{
			throw(trenutni);
		}
		else
		{
			niz[trenutni++] = t;
		}
	}
	catch (int t)
	{
		cout << "Greska" << endl;
	}
}

template<class T>
inline void Kolekcija<T>::Obrisi(int rbr)
{
	try
	{
		if (rbr < 0 && rbr > trenutni)
		{
			throw(rbr);
		}
		else
		{
			for (int i = rbr - 1; i < trenutni - 1; i++)
			{
				niz[i] = niz[i + 1];
			}
			trenutni--;
		}
	}
	catch (int r)
	{
		cout << "Greska." << endl;
	}
}

template<class T>
inline double Kolekcija<T>::OdrediProsek()
{
	double suma = 0.0;
	for (int i = 0; i < trenutni; i++)
	{
		suma = niz[i] + suma;
	}
	return (suma / trenutni);
}

template<class T>
inline T Kolekcija<T>::NajvecaVrednost()
{
	T max = niz[0];
	for (int i = 1; i < trenutni; i++)
	{
		if (max < niz[i])
			max = niz[i];
	}
	return max;
}

template<class T>
inline void Kolekcija<T>::Sacuvaj(const char* imefajla)
{
	ofstream f(imefajla);
	if (!f.good())
		throw new exception("greksa");
	f << *this;

	f.close();
}

template<class T>
inline void Kolekcija<T>::Ucitaj(const char* imefajla)
{
	ifstream f(imefajla);
	if (!f.good())
		throw new exception("greska");

	f >> *this;

	f.close();
}
