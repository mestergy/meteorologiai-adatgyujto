#include "adatkoncentrator.h"

#include <stdio.h>
#include <iostream>

//visszater egy adatkoncentrator osszes adatanak kiirasaval
std::ostream& Adatkoncentrator::kiir(std::ostream& os) {
	return os << datum.getEv() << " " << datum.getHo() << " " << datum.getNap() << " " <<
		erzekelo.getNev() << " " << erzekelo.getErtek()  << " " << erzekelo.getMertekegyseg();
}

//egy Adatkoncentrator osszes hozzatartozo ertekenek kiirasa
void Adatkoncentrator::kiiro(std::ostream& os) const {
	datum.kiiro(os);
	os << " ";
	erzekelo.kiiro(os);
}

