#pragma once
#include "Helper.h"
#include "Roslina.h"

#define PRAWDOPODOBIENSTWO_GUARANY 10
#define SILA_GUARANY 0
#define SYMBOL_GUARANY 'G'
#define PROBY_GUARANY 1
#define ILE_SILY 3

class Guarana : public Roslina {
public:
	Guarana(Swiat& swiat, const Polozenie& polozenie);
	string GetNazwa() const override;
	Organizm* Kopiuj(const Polozenie& polozenie) override;
	bool Kolizja(Organizm* wrog) override;
	~Guarana();
};