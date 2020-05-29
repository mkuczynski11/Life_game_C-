#pragma once
#include "Helper.h"
#include "Roslina.h"

#define PRAWDOPODOBIENSTWO_WILCZYCHJAGOD 5
#define SILA_WILCZYCHJAGOD 99
#define SYMBOL_WILCZYCHJAGOD 'J'
#define PROBY_WILCZYCHJAGOD 1

class WilczeJagody : public Roslina {
public:
	WilczeJagody(Swiat& swiat, const Polozenie& polozenie);
	string GetNazwa() const override;
	Organizm* Kopiuj(const Polozenie& polozenie) override;
	bool Kolizja(Organizm* organizm) override;
	~WilczeJagody();
};