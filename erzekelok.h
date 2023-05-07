//#pragma once

#ifndef ERZEKELOK_H_INCLUDED
#define ERZEKELOK_H_INCLUDED

#include <string>
#include <iostream>

class Erzekelo {
 protected:
	std::string nev;
	double ertek;
	std::string mertekegyseg;

 public:
	Erzekelo();		//ctor
	Erzekelo(std::string nev, double ertek, std::string mertekegyseg) : nev(nev), ertek(ertek), mertekegyseg(mertekegyseg) {}

	std::string getNev() const { return nev; } 	//nev lekerdezese
	double getErtek() const { return ertek; } 	//ertek lekerdezese
	std::string getMertekegyseg() const { return mertekegyseg; } 	//mertekegyseg lekerdezese

	void kiiro(std::ostream& os) const {
		std::cout << nev << " " << ertek << " " << mertekegyseg << std::endl;
	}

	virtual ~Erzekelo() {}     // Virtuális dtor
};

//Erzekelo osztaly leszarmazottjai:

class Homerseklet : public Erzekelo {
 public:
	Homerseklet(double ertek) : Erzekelo("homerseklet", ertek, "Celsius fok") {}
};

class Szel : public Erzekelo {
 public:
	Szel(double ertek) : Erzekelo("szel", ertek, "km/h") {}
};

class Csapadek : public Erzekelo {
 public:
	Csapadek(double ertek) : Erzekelo("csapadek", ertek, "mm") {}
};

class Paratartalom : public Erzekelo {
 public:
	Paratartalom(double ertek) : Erzekelo("paratartalom", ertek, "%") {}
};

#endif // ERZEKELOK_H_INCLUDED
