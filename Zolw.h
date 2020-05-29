#pragma once
#include "Helper.h"
#include "Zwierze.h"

#define SILA_ZOLWIA 2
#define INICJATYWA_ZOLWIA 1
#define SYMBOL_ZOLWIA 'Z'
#define SZANSA_WYKONANIA_RUCHU_ZOLWIA 75

class Zolw : public Zwierze {
public:
	Zolw(Swiat& swiat, const Polozenie& polozenie);
	string GetNazwa() const override;
	Organizm* Kopiuj(const Polozenie& polozenie) override;
	bool TenGatunek(Organizm* organizm) override;
	bool Kolizja(Organizm* wrog) override;
	~Zolw();
};