#pragma once
#include "Helper.h"
#include "Roslina.h"

#define PRAWDOPODOBIENSTWO_BARSZCZUSOSNOWSKIEGO 15
#define SILA_BARSZCZUSOSNOWSKIEGO 10
#define SYMBOL_BARSZCZUSOSNOWSKIEGO 'B'
#define PROBY_BARSZCZUSOSNOWSKIEGO 1

class BarszczSosnowskiego : public Roslina {
public:
	BarszczSosnowskiego(Swiat& swiat, const Polozenie& polozenie);
	string GetNazwa() const override;
	Organizm* Kopiuj(const Polozenie& polozenie) override;
	void Akcja() override;
	bool Kolizja(Organizm* wrog) override;
	~BarszczSosnowskiego();
};