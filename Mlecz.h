#pragma once
#include "Helper.h"
#include "Roslina.h"

#define PRAWDOPODOBIENSTWO_MLECZA 5
#define SILA_MLECZA 0
#define SYMBOL_MLECZA 'M'
#define PROBY_MLECZA 3

class Mlecz : public Roslina {
public:
	Mlecz(Swiat& swiat, const Polozenie& polozenie);
	string GetNazwa() const override;
	Organizm* Kopiuj(const Polozenie& polozenie) override;
	~Mlecz();
};