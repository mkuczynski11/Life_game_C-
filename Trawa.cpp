#include "Trawa.h"

Trawa::Trawa(Swiat& swiat, const Polozenie& polozenie)
	:Roslina(swiat, polozenie, SYMBOL_TRAWY, SILA_TRAWY, PRAWDOPODOBIENSTWO_TRAWY, PROBY_TRAWY)
{
}

string Trawa::GetNazwa() const
{
	return "Trawa";
}

Organizm* Trawa::Kopiuj(const Polozenie& polozenie)
{
	return new Trawa(this->GetSwiat(), polozenie);
}

Trawa::~Trawa()
{
}