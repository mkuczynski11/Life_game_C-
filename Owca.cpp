#pragma once
#include "Owca.h"

Owca::Owca(Swiat& swiat, const Polozenie& polozenie)
	:Zwierze(swiat, polozenie, SYMBOL_OWCY, SILA_OWCY, INICJATYWA_OWCY)
{
}

string Owca::GetNazwa() const
{
	return "Owca";
}

Organizm* Owca::Kopiuj(const Polozenie& polozenie)
{
	return new Owca(this->GetSwiat(), polozenie);
}

bool Owca::TenGatunek(Organizm* organizm)
{
	return dynamic_cast<Owca*>(organizm);
}

Owca::~Owca()
{
}