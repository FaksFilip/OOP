#include <fstream>
#include <iostream>
#include "Proizvod.h"
#include "Cokolada.h"
#include "Igracka.h"
#include "Traka.h"
#include "Kolekcija.h"
#include "ProizvodKolekcija.h"

 using namespace std;

 void main()
 {
	 //ZADATAK POD A

  // 2 poena
	 Proizvod* p1 = new Cokolada(156.99, 0.2, 0.75);
	 //p1.print();
	 cout << p1 << endl;

	 // 2 poena
	 Proizvod* p2 = new Igracka(749.99, 1.2, 0.38);
	 //p2.print();
	 cout << p2 << endl;

	 Traka t(4);
	 Traka* tp = new Traka(4);

	 // 2 poena
	 for (int i = 0; i < t.BrojProizvoda() / 2; i++)
	 {
		 t.Add(new Cokolada(100 + i * 5, i * 3, 20 + i * 13 / 10));
		 t.Add(new Igracka(1000 + i * 20.37, (i + 1) * i, 20 + i * 13 + 24 / 10));
	 }
	 for (int i = 0; i < tp->BrojProizvoda() / 2; i++)
	 {
		 tp->Add(new Cokolada(100 + i * 5, i * 3, 20 + i * 13 / 10));
		 tp->Add(new Igracka(1000 + i * 20.37, (i + 1) * i, 20 + i * 13 + 24 / 10));
	 }

	 // 2 poena
	 //t.print();
	 cout << t << endl;

	 // 2 poena
	 Traka ttt = t + *tp;
	 // ttt.print();
	 cout << ttt << endl;

	 // 2 poena
	 delete tp;

	 // 2 poena
	 t.Save("traka.txt");

	 // 2 poena 
     // proizvod koji ima najvecu cenu
	 Proizvod* pmax = t.Max();
	 cout << *pmax << endl;

	 // 2 poena
	 Traka cTraka = t;
	 // cTraka.print();
	 cout << cTraka << endl;

	 // 2 poena
	 // izbacuje se proizvod koji ima najmanju vrednost
	 Proizvod* minProizvod = t.RemoveMinimum();
	 cout << minProizvod << endl;
 
	 //ZADATAK POD B

	 int maxPodataka = 8, brojPodataka = 5;
	 int test[] = { 23, 37, 28, 31, 34 };

	 bool defektan[] = { false, false, true, false, true };
	 int vrednost[] = { 30, 50, 60, 50, 55 };

	 // 3 boda
	 // postavljanje i prihvatanje izuzetaka
	 try
	 {
		 // 1 bod
		 Kolekcija<int> kolekcijaInt(maxPodataka);

		 // 1 bod
		 for (int i = 0; i < brojPodataka; i++)
			 kolekcijaInt.DodajPodatak(test[i]);

		 // 1 bod
		 cout << kolekcijaInt << endl; // kolekcijaInt.Ispisi(cout);

			  // 1 bod
		 kolekcijaInt.Obrisi(4);
		 cout << kolekcijaInt << endl; // kolekcijaInt.Ispisi(cout);

		 // 1 bod
		 float prosek = kolekcijaInt.OdrediProsek();
		 cout << prosek << endl;

		 // 1 bod
		 int najvecaVrednost = kolekcijaInt.NajvecaVrednost();
		 cout << najvecaVrednost << endl;

		 // 1 bod
		 kolekcijaInt.Sacuvaj("KolekcijaInt.txt");

		 // 2 boda
		 Kolekcija<int> kolekcijaIntTest(maxPodataka);
		 kolekcijaIntTest.Ucitaj("KolekcijaInt.txt ");
		 cout << kolekcijaIntTest << endl; // kolekcijaIntTest.Ispisi(cout);
	 }
	 catch (const char* poruka)
	 {
		 cout << poruka;
	 }
	 try
	 {
		 // 1 bod
		 Kolekcija<ProizvodKolekcija> kolekcijaProizvod(maxPodataka);

		 // 1 bod
		 for (int i = 0; i < brojPodataka; i++) {
			 ProizvodKolekcija tmp(defektan[i], vrednost[i]);
			 kolekcijaProizvod.DodajPodatak(tmp);
		 }

		 // 1 bod
		 cout << kolekcijaProizvod << endl; // kolekcijaProizvod.Ispisi(cout);

		 
			  // 0 bodova
		 kolekcijaProizvod.Obrisi(4);
		 cout << kolekcijaProizvod << endl; // kolekcijaProizvod.Ispisi(cout);

		 // 2 boda
		 float prosek2 = kolekcijaProizvod.OdrediProsek();
		 cout << prosek2 << endl;
		 
		 // 2 boda
		 ProizvodKolekcija najvecaVrednostProizvoda = kolekcijaProizvod.NajvecaVrednost();
		 cout << najvecaVrednostProizvoda << endl;

		 /*

		 // 0 bod
		 kolekcijaProizvod.Sacuvaj("KolekcijaProizvod.txt");

		 // 1 bod
		 Kolekcija<int> kolekcijaProizvodTest(maxPodataka);
		 kolekcijaProizvodTest.Ucitaj("KolekcijaProizvod.txt");
		 cout << kolekcijaProizvodTest << endl; // kolekcijaProizvodTest.Ispisi(cout);

		 */

	 }
	 catch (const char* poruka)
	 {
		 cout << poruka;
	 }
}

