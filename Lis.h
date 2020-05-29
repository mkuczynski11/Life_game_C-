#pragma once
#include "Helper.h"
#include "Zwierze.h"

#define SILA_LISA 3
#define INICJATYWA_LISA 7
#define SYMBOL_LISA 'L'

class Lis : public Zwierze {
public:
	Lis(Swiat& swiat, const Polozenie& polozenie);
	string GetNazwa() const override;
	Organizm* Kopiuj(const Polozenie& polozenie) override;
	bool TenGatunek(Organizm* organizm) override;
	Polozenie GenerujPolozenie() override;
	~Lis();
};