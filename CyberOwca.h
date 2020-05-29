#pragma once
#include "Helper.h"
#include "Zwierze.h"

#define SILA_CYBEROWCY 11
#define INICJATYWA_CYBEROWCY 4
#define SYMBOL_CYBEROWCY 'c'

class CyberOwca : public Zwierze {
public:
	CyberOwca(Swiat& swiat, const Polozenie& polozenie);
	string GetNazwa() const override;
	Organizm* Kopiuj(const Polozenie& polozenie) override;
	bool TenGatunek(Organizm* organizm) override;
	~CyberOwca();
};