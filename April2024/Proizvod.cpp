#include "Proizvod.h"

Proizvod::Proizvod()
{
	cena = 0.0;
	masa = 0.0;
}

Proizvod::Proizvod(double _cena, double _masa)
{
	cena = _cena;
	masa = _masa;
}

Proizvod::Proizvod(const Proizvod& p)
{
	if (this != &p)
	{
		cena = p.cena;
		masa = p.masa;
	}
}

Proizvod::~Proizvod()
{
}
