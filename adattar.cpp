#include "adattar.h"

#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>

#include "adatkoncentrator.h"

#include "memtrace.h"


//egy db Adatkoncentrator hozzaadasa az adattarhoz
//mivel az Adattar mindig csak akkora, ahany adat van benne, igy itt memoriafoglalas es felszabadítas is tortenik
//a legutobb hozzaadott adat az adattar legnagyobb indexu helyere kerul
void Adattar::hozzaad(Adatkoncentrator* ad) {
	Adatkoncentrator **temp = new Adatkoncentrator *[db+1];
	for(size_t i = 0; i < db; i++)
		temp[i] = adatok[i];
	temp[db] = ad;
	delete[] adatok;
	adatok = temp;
	db++;
}

//adatok beolvasasa parameterkent kapott nevu fajlbol
void Adattar::beolvas_f(const std::string& nev) {
	std::fstream file;
	file.open(nev);
	std::string erz_nev;
	double ertek;
	int ev, ho, nap;

	try { if(file.fail())
			throw "Hiba a fajl megnyitasakor: ";
	} catch(const char* e) {
		std::cout << e << nev << std::endl;
		return;
	}

	if (file.is_open()) {
		int i = 0;
		while (file >> ev) {
			if(ev) {
				char nemkell[60];		//azert kell, mert a fajlban az adatok mertekegysege is ott lehet, de arra nincs szukseg
				file >> ho >> nap >> erz_nev >> ertek;
				file.getline(nemkell, 60);
				Datum d(ev, ho, nap);

				if (erz_nev == "homerseklet") {
					Homerseklet he(ertek);
					hozzaad(new Adatkoncentrator(d, he));
				} else if (erz_nev == "paratartalom") {
					Paratartalom pe(ertek);
					hozzaad(new Adatkoncentrator(d, pe));
				} else if (erz_nev == "szel") {
					Szel sze(ertek);
					hozzaad(new Adatkoncentrator(d, sze));
				} else if (erz_nev == "csapadek") {
					Csapadek cse(ertek);
					hozzaad(new Adatkoncentrator(d, cse));
				}
			} 
			i++;
		}
		file.close();
	}
}

//adatok kiirasa parameterkent kapott nevu fajlba
void Adattar::kiir_f(const std::string& nev) {
	std::fstream file;
	file.open(nev);

	try { if(file.fail())
			throw "Hiba a fajl megnyitasakor: ";
	} catch(const char* e) {
		std::cout << e << nev << std::endl;
		return;
	}

	if (file.is_open()) {
		for(size_t i = 0; i < db; i++) {
			adatok[i]->kiir(file)<<std::endl;
		}
		file.close();
	}
}

//atvesz parameterkent egy Adattarat, amit modositani fog
//atveszi meg a keresett evet es honapot
//visszater a talalatok szamaval, vagyis a parameterkent kapott Adattar uj darabszamaval
//vegigmegy annak az adattarnak az osszes elemen, amiben a megfelelo adatokat keressuk
//ha van egyezoseg, akkor a parameterkent atvett adattarra meghivja a hozzaado fuggvenyt az egyezo adatkoncentratorral
size_t Adattar::havi_listat_csinal(Adattar *ide, int ev, int ho) {
	size_t talalatok = 0;
	for(size_t i = 0; i < db; i++) {
		int tmp_ev = adatok[i]->getEv();
		int tmp_ho = adatok[i]->getHo();

		if (tmp_ev == ev) {
			if (tmp_ho == ho) {
				ide->hozzaad(new Adatkoncentrator(*adatok[i]));
				talalatok += 1;
			}
		}
	}
	return talalatok;
}


//atvesz parameterkent egy Adattarat, amit modositani fog
//atveszi meg a keresett evet, honapot, napot
//visszater a talalatok szamaval, vagyis a parameterkent kapott Adattar uj darabszamaval
//vegigmegy annak az adattarnak az osszes elemen, amiben a megfelelo adatokat keressuk
//ha van egyezoseg, akkor a parameterkent atvett adattarra meghivja a hozzaado fuggvenyt az egyezo adatkoncentratorral
size_t Adattar::napi_listat_csinal(Adattar *ide, int ev, int ho, int nap) {
	Datum keresett (ev, ho, nap);
	size_t talalatok = 0;

	for(size_t i = 0; i < db; i++) {
		if(adatok[i]->getDatum() == keresett) {
			ide->hozzaad(new Adatkoncentrator(*adatok[i]));
			talalatok += 1;
		}
	}
	return talalatok;
}
