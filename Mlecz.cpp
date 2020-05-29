#include "Mlecz.h"

Mlecz::Mlecz(Swiat& swiat, const Polozenie& polozenie)
	:Roslina(swiat, polozenie, SYMBOL_MLECZA, SILA_MLECZA, PRAWDOPODOBIENSTWO_MLECZA, PROBY_MLECZA)
{
}

string Mlecz::GetNazwa() const
{
	return "Mlecz";
}

Organizm* Mlecz::Kopiuj(const Polozenie& polozenie)
{
	return new Mlecz(this->GetSwiat(), polozenie);
}

Mlecz::~Mlecz()
{
}