#include "menu.h"

#include <iostream>

#include "adattar.h"
#include "datum.h"
#include "adatkoncentrator.h"
#include "erzekelok.h"
#include "megjelenito.h"

#include "memtrace.h"
#include "gtest_lite.h"

//parameterkent kap egy adattarat, egy opciot es egy megjelenitot
//visszater a valasztott opcioval
//az opcio fuggvenyeben vegzi el a megfelelo muveleteket
char menu(Adattar &tarolo, char opcio, Megjelenito m) {
		int ev, ho, nap;
		std::string nev, erz_nev;

		switch(opcio) {
			case 'h' :
				std::cout << "A keresett honap eeee hh formatumban: ";
				std::cin >> ev >> ho;
				m.havi_kilistazo(tarolo, std::cout, ev, ho);
				return 'h';

			case 'n' :
				std::cout << "A keresett nap eeee hh nn formatumban: ";
				std::cin >> ev >> ho >> nap;
				m.napi_kilistazo(tarolo, std::cout, ev, ho, nap);
				return 'n';

			case 'k' :
				std::cout << "Melyik letezo fajlba irjam ki? pl: pelda.txt"<<std::endl;
				std::cin >> nev;
				tarolo.kiir_f(nev);
				return 'k';

			case 'b' :
				std::cout << "Melyik fajlbol olvassam be? pl: adatok.txt"<<std::endl;
				std::cin >> nev;
				tarolo.beolvas_f(nev);
				return 'b';

			case 'o' :
				std::cout << "Az osszes eddigi adat listaja: "<<std::endl;
				m.kilistazo(tarolo, std::cout);
				return 'm';

			case 'x' :
				std::cout<<"kilepes"<<std::endl;
				return 'x';

			default :
				std::cout<<"nincs ilyen opcio"<<std::endl;
				return '0';
		}
		return '0';
}
