#pragma once
#include "Helper.h"
#include "Zwierze.h"

#define SILA_WILKA 9
#define INICJATYWA_WILKA 5
#define SYMBOL_WILKA 'W'

class Wilk : public Zwierze {
public:
	Wilk(Swiat& swiat, const Polozenie& polozenie);
	string GetNazwa() const override;
	Organizm* Kopiuj(const Polozenie& polozenie) override;
	bool TenGatunek(Organizm* organizm) override;
	~Wilk();
};