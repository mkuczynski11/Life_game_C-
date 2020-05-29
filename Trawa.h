#pragma once
#include "Helper.h"
#include "Roslina.h"

#define PRAWDOPODOBIENSTWO_TRAWY 10
#define SILA_TRAWY 0
#define SYMBOL_TRAWY 'T'
#define PROBY_TRAWY 1

class Trawa : public Roslina {
public:
	Trawa(Swiat& swiat, const Polozenie& polozenie);
	string GetNazwa() const override;
	Organizm* Kopiuj(const Polozenie& polozenie) override;
	~Trawa();
};