#include "Zolw.h"
#include "Swiat.h"

Zolw::Zolw(Swiat& swiat, const Polozenie& polozenie)
	:Zwierze(swiat, polozenie, SYMBOL_ZOLWIA, SILA_ZOLWIA, INICJATYWA_ZOLWIA)
{
	this->SetSzansaWykonaniaRuchu(SZANSA_WYKONANIA_RUCHU_ZOLWIA);
}

string Zolw::GetNazwa() const
{
	return "Zolw";
}

Organizm* Zolw::Kopiuj(const Polozenie& polozenie)
{
	return new Zolw(this->GetSwiat(), polozenie);
}

bool Zolw::TenGatunek(Organizm* organizm)
{
	return dynamic_cast<Zolw*>(organizm);
}	

bool Zolw::Kolizja(Organizm* wrog)
{
	if (wrog->GetSila() < 5)
	{
		this->GetSwiat().GetKomentator()->Oglos_odbicie_zolwia(this, wrog);
		return false;
	}
	else
	{
		return Zwierze::Kolizja(wrog);
	}
}

Zolw::~Zolw()
{
}