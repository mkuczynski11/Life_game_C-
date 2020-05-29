#include "Wilk.h"

Wilk::Wilk(Swiat& swiat, const Polozenie& polozenie)
	:Zwierze(swiat, polozenie, SYMBOL_WILKA, SILA_WILKA, INICJATYWA_WILKA)
{
}

string Wilk::GetNazwa() const
{
	return "Wilk";
}

Organizm* Wilk::Kopiuj(const Polozenie& polozenie)
{
	return new Wilk(this->GetSwiat(), polozenie);
}

bool Wilk::TenGatunek(Organizm* organizm)
{
	return dynamic_cast<Wilk*>(organizm);
}

Wilk::~Wilk()
{
}