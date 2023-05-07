//#pragma once

#ifndef MEGJELENITO_H_INCLUDED
#define MEGJELENITO_H_INCLUDED

#include <iostream>
#include "adattar.h"

class Megjelenito {
public:
	Megjelenito() {}	//ctor

    void kilistazo(Adattar &t, std::ostream& os) const;		//minden adatot kilistaz

	void havi_kilistazo(Adattar& t, std::ostream& os, int ev, int ho);	 //honap alapjan kilistazza az adatokat
	void napi_kilistazo(Adattar &t, std::ostream& os, int ev, int ho, int nap); 	//nap alapjan kilistazza az adatokat

	~Megjelenito() {}	//dtor
};


#endif // MEGJELENITO_H_INCLUDED
