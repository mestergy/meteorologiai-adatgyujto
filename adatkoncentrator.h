//#pragma once

#ifndef ADATKONCENTRATOR_H_INCLUDED
#define ADATKONCENTRATOR_H_INCLUDED

#include "erzekelok.h"
#include "datum.h"

class Adatkoncentrator {
	Erzekelo erzekelo;
	Datum datum;

 public:
	Adatkoncentrator(); //ctor
	Adatkoncentrator(Datum da, Erzekelo er) : erzekelo(er), datum(da) {}

	Adatkoncentrator(const Adatkoncentrator& eredeti) : erzekelo(eredeti.erzekelo), datum(eredeti.datum) {};	//copy ctor

	Datum getDatum() { return datum; }			//lekerdezi/visszaadja az adatkoncentratorhoz tartozo datumot/ a meres datumat
	Erzekelo getErzekelo() { return erzekelo; } 		//lekerdezi/visszaadja az adatkoncentrator erzekelojet

	std::ostream& kiir(std::ostream& os);

	int getEv() { return datum.getEv(); }		//az adathoz tartozo evet adja vissza
	int getHo() { return datum.getHo(); }		//az adathoz tartozo honapot adja vissza
	int getNap() { return datum.getNap(); }		//az adathoz tartozo napot adja vissza

	void kiiro(std::ostream& os) const;

	virtual ~Adatkoncentrator() {}	//dtor
};

#endif // ADATKONCENTRATOR_H_INCLUDED


