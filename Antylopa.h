#pragma once
#include "Helper.h"
#include "Zwierze.h"

#define SILA_ANTYLOPY 4
#define INICJATYWA_ANTYLOPY 4
#define SYMBOL_ANTYLOPY 'A'
#define ZASIEG_ANTYLOPY 2

class Antylopa : public Zwierze {
public:
	Antylopa(Swiat& swiat, const Polozenie& polozenie);
	string GetNazwa() const override;
	Organizm* Kopiuj(const Polozenie& polozenie) override;
	bool TenGatunek(Organizm* organizm) override;
	bool Kolizja(Organizm* wrog) override;
	~Antylopa();
};