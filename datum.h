//#pragma once

#ifndef DATUM_H
#define DATUM_H

#include <iostream>

 // kor�bbi laborfeladatokb�l inspir�l�dva

class Datum {
    int ev;
	int ho;
	int nap;
public:

    /// Param�ter n�lk�l h�vhat� konstruktor, a mai napot �ll�tja be
    Datum();

	//ctor
    Datum(int ev, int ho, int nap) : ev(ev), ho(ho), nap(nap) {}

    int getEv() const { return ev; }	//ev lekerdezese
    int getHo() const { return ho; }	//honap lekerdezese
    int getNap() const { return nap; }	//nap lekerdezese


    // K�t d�tum egyez�s�g�t vizsg�lja, igaz, ha egyezik a k�t d�tum
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

