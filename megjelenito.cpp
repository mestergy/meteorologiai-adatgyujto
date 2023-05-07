#include "megjelenito.h"

#include <stdio.h>
#include <iostream>
#include "adattar.h"
#include "adatkoncentrator.h"

//parameterkent kap egy adattarat, aminek az  osszes elemere meghívja a kiiro fuggvenyet, vagyis ezek az adatok kiirodnak
void Megjelenito::kilistazo(Adattar &t, std::ostream& os) const {
	size_t n = t.getDb();
	for(size_t i = 0; i < n; i++) {
		t[i]->kiiro(os);
	}
}

//parameterkent kap egy adattarat, egy evet es egy honapot
//az adattar azon elemeit irja ki, melyeknek eve es honapja egyezik a parameterkent kapottakeval
void Megjelenito::havi_kilistazo(Adattar &t, std::ostream& os, int ev, int ho) {
	Adattar *temp = new Adattar();			//uj adattar letrehozasa, az egyezo adatok ebbe kerulnek majd bele
	size_t n = 0;
	n = t.havi_listat_csinal(temp, ev, ho);
	temp->setDb(n);
	if(n == 0) {
		delete temp;
		std::cout<<"errol a honaprol nincsen adat"<<std::endl;		//ha 0 db egyezo van, akkor ezt kozli a felhasznaloval
		return;
	} else {
		kilistazo(*temp, std::cout);		//az ujjonnan letrehozott adattar osszes elemenek kiirasa
	}
	delete temp;
}

//parameterkent kap egy adattarat, egy evet, egy honapot es egy napot
//az adattar azon elemeit irja ki, melyeknek datuma egyezik a parameterkent kapottakeval
void Megjelenito::napi_kilistazo(Adattar &t, std::ostream& os, int ev, int ho, int nap) {
	Adattar *temp = new Adattar();		//uj adattar letrehozasa, az egyezo adatok ebbe kerulnek majd bele
	size_t n = 0;
	n = t.napi_listat_csinal(temp, ev, ho, nap);
	temp->setDb(n);
	if(n == 0) {
		delete temp;
		std::cout<<"errol a naprol nincsen adat"<<std::endl;	//ha 0 db egyezo van, akkor ezt kozli a felhasznaloval
		return;
	} else {
		kilistazo(*temp, std::cout);		//az ujjonnan letrehozott adattar osszes elemenek kiirasa
	}
	delete temp;
}
