//#pragma once

#ifndef ADATTAR_H_INCLUDED
#define ADATTAR_H_INCLUDED

#include "adatkoncentrator.h"

class Adattar {
	size_t db;	 //adatok szama / tároló mérete
	Adatkoncentrator** adatok;	//tarolt adat(koncentrator)ok, pointer az ősosztálya
public:

	Adattar() { db = 0; adatok = NULL; }	//konstruktor, üres tároló
	Adattar(const Adattar& eredeti);	// copy ctor

	size_t getDb() { return db; } 	//Éppen aktuálisan eltárolt adatok száma
	void setDb(size_t n) { db = n; }

	void hozzaad(Adatkoncentrator* adat); //egy adat hozzaadasa az adattarhoz
	void beolvas_f(const std::string& nev);		//adatok beolvasása fájlból
	void kiir_f(const std::string& nev);		//osszes adat kiirasa fájlba

	Adatkoncentrator*& operator[](size_t index) const { return adatok[index]; }		//indexelő operátor

	size_t havi_listat_csinal(Adattar *ide, int ev, int ho);
	size_t napi_listat_csinal(Adattar *ide, int ev, int ho, int nap);


	//dtor
	~Adattar() {
		for(size_t i = 0; i < db; i++) {
			delete adatok[i];
		}
		db = 0;
		delete[] adatok;
	}
};

#endif // ADATTAR_H_INCLUDED




