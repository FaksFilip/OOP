#include "ProizvodKolekcija.h"

ProizvodKolekcija::ProizvodKolekcija()
{
	defektan = 0;
	vrednost = 0;
}

ProizvodKolekcija::ProizvodKolekcija(bool _def, int _vred)
{
	defektan = _def;
	vrednost = _vred;
}

ProizvodKolekcija::ProizvodKolekcija(const ProizvodKolekcija& p)
{
	if (this != &p)
	{
		defektan = p.defektan;
		vrednost = p.vrednost;
	}
}

ProizvodKolekcija::~ProizvodKolekcija()
{
}
