// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <string>
#include <iostream>

#include "adattar.h"
#include "datum.h"
#include "adatkoncentrator.h"
#include "erzekelok.h"
#include "megjelenito.h"
#include "menu.h"

#include "memtrace.h"
#include "gtest_lite.h"

int main() {

	Megjelenito m;		//megjelenito letrehozasa
	Adattar tarolo;		//az adattar letrehozasa
	tarolo.beolvas_f("kezdo.txt");		//a kezdo adatok beolvasasa a taroloba

///	int *p = new int;	//memtrace mukodesenek ellenorzesehez

#define KESZ 99

	std::cout<<"\nTesztek:"<<std::endl;
	std::cout<<std::endl<<"------------------ TESZTEK ------------------"<<std::endl<<std::endl;

#if KESZ == 1 || KESZ == 99

TEST(Erzekelo, konstruktor){
        Erzekelo e("Szel", 21, "km/h");
        EXPECT_EQ("Szel", e.getNev());
} END
TEST(Homerseklet, konstruktor){
        Homerseklet h12(14);
        EXPECT_EQ("homerseklet", h12.getNev());
} END
TEST(Csapadek, konstruktor){
        Csapadek cs(10);
        EXPECT_EQ("mm", cs.getMertekegyseg());
} END
TEST(Paratartalom, konstruktor){
        Paratartalom p(31);
        EXPECT_EQ(31, p.getErtek());
} END
TEST(Datum, konstruktor){
		Datum d(2020, 10, 23);
		EXPECT_EQ(2020, d.getEv());
} END
TEST(Datum, konstruktor){
		Datum d(2021, 3, 21);
		EXPECT_EQ(3, d.getHo());
} END
TEST(Datum, konstruktor){
		Datum d(2019, 5, 10);
		EXPECT_EQ(10, d.getNap());
} END
TEST(Datum, konstruktor){
		Datum d(2019, 5, 4);
		EXPECT_EQ(4, d.getNap());
} END

#endif

#if KESZ == 2 || KESZ == 99
		Datum d(2021, 05, 3);
		Homerseklet h(17);
		Adatkoncentrator a(d, h);
TEST(Adatkoncentrator, konstruktor) {
		Erzekelo e = a.getErzekelo();
		EXPECT_EQ("homerseklet", e.getNev());
} END

TEST(Adatkoncentrator, kiiratas) {
		std::stringstream ss;
		a.kiir(ss);
		EXPECT_EQ("2021 5 3 homerseklet 17 Celsius fok", ss.str());
} END

TEST(Adattar, konstruktor) {
	size_t elvart = 14;
	EXPECT_EQ(elvart, tarolo.getDb());
} END

#endif

#if KESZ == 4 || KESZ == 99
TEST(Adattar, havi_lista) {
	Adattar *temp = new Adattar();
	int n = tarolo.havi_listat_csinal(temp, 2021, 3);
	int elvart = 2;
	EXPECT_EQ(elvart, n);
	delete temp;
} END

TEST(Adattar, napi_lista) {
	Adattar *temp = new Adattar();
	int n = tarolo.napi_listat_csinal(temp, 2020, 3, 2);
	int elvart = 3;
	EXPECT_EQ(elvart, n);
	delete temp;
} END
#endif


#if KESZ == 5 || KESZ == 99
TEST(Menu, visszaadas) {
	char c = menu(tarolo, 'x', m);
	EXPECT_EQ('x', c);
} END

#endif


	std::cout<<std::endl<<"---------------- TESZTEK VEGE ----------------"<<std::endl<<std::endl;

	char opcio = '0';
	std::cout << std::endl << "---------- Meteorologiai adatgyujto ----------" << std::endl << std::endl;
	std::cout << "a - adatbevitel kezzel" << std::endl
				<< "o - osszes meglevo adat kiirasa" << std::endl
				<< "h - havi lekerdezes" << std::endl
				<< "n - napi lekerdezes" << std::endl
				<< "k - osszes adat fajlba kiirasa" << std::endl
				<< "b - adatok beolvasasa fajlbol" << std::endl
				<< "x - kilepes" << std::endl << std::endl;

	while ((opcio != 'x') && (opcio != 'X')) {
		std::cin >> opcio;
		opcio = tolower(opcio);

		if(opcio == 'a') {
			int ev, ho, nap;
			std::string nev, erz_nev;
			double ertek;
			std::cout<< "Az uj adatot eeee hh nn nev ertek formaban add meg: ";
			std::cin>> ev >> ho >> nap >> erz_nev >> ertek;

			if ((ev < 2022) && (nap < 31) && (nap > 0) && (ho > 0) && (ho <= 12)) {
				Datum d(ev, ho, nap);
				if (erz_nev == "homerseklet") {
					Homerseklet he(ertek);
					tarolo.hozzaad(new Adatkoncentrator(d, he));
				}
				else if (erz_nev == "paratartalom") {
					Paratartalom pe(ertek);
					tarolo.hozzaad(new Adatkoncentrator(d, pe));
				}
				else if (erz_nev == "szel") {
					Szel sze(ertek);
					tarolo.hozzaad(new Adatkoncentrator(d, sze));
				}
				else if (erz_nev == "csapadek") {
					Csapadek cse(ertek);
					tarolo.hozzaad(new Adatkoncentrator(d, cse));
				}
				else {
					std::cout << "nem lehet felismerni az adatot :(" << std::endl;
				}
			} else {
				std::cout << "nem ervenyes a megadott datum" << std::endl;
			}
		} else {
			opcio = menu(tarolo, opcio, m);
		}
	}
}
