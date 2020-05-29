#pragma once
#include "Helper.h"
#include "Organizm.h"

class Komentator {
public:
	Komentator();
	void Oglos_zabojstwo(Organizm* wygrany, Organizm* przegrany);
	void Oglos_przesuniecie(const Polozenie& polozenie1, const Polozenie& polozenie2, Organizm* organizm);
	void Oglos_zjedzenie(Organizm* zjedzony, Organizm* jedzony);
	void Oglos_rozmnozenie(Organizm* rodzic, Organizm* dziecko);
	void Oglos_rozmnozenie(Organizm* rodzic1, Organizm* rodzic2, Organizm* dziecko);
	void Oglos_odbicie_zolwia(Organizm* wygrany, Organizm* przegrany);
	void Oglos_ucieczke(Organizm* wygrany, Organizm* przegrany);
	void Oglos_zwiekszenie_sily(Organizm* organizm, const int& ile);
};