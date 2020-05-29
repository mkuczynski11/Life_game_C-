#pragma once
#include "Helper.h"
#include "Zwierze.h"

#define SILA_OWCY 4
#define INICJATYWA_OWCY 4
#define SYMBOL_OWCY 'O'

class Owca : public Zwierze {
public:
	Owca(Swiat& swiat, const Polozenie& polozenie);
	string GetNazwa() const override;
	Organizm* Kopiuj(const Polozenie& polozenie) override;
	bool TenGatunek(Organizm* organizm) override;
	~Owca();
};