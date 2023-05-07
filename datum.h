//#pragma once

#ifndef DATUM_H
#define DATUM_H

#include <iostream>

 // korábbi laborfeladatokból inspirálódva

class Datum {
    int ev;
	int ho;
	int nap;
public:

    /// Paraméter nélkül hívható konstruktor, a mai napot állítja be
    Datum();

	//ctor
    Datum(int ev, int ho, int nap) : ev(ev), ho(ho), nap(nap) {}

    int getEv() const { return ev; }	//ev lekerdezese
    int getHo() const { return ho; }	//honap lekerdezese
    int getNap() const { return nap; }	//nap lekerdezese


    // Két dátum egyezõségét vizsgálja, igaz, ha egyezik a két dátum
	bool operator==(const Datum& d) const {
        return ev == d.ev && ho == d.ho && nap == d.nap;
    }

    std::ostream& kiir(std::ostream& os) const {
        return os << ev << " " << nap << " " << ho << " ";
    }

	void kiiro(std::ostream& os) const {
		os << ev <<" " << ho << " " << nap;
	}

	~Datum() {}
};


#endif // DATUM_H

