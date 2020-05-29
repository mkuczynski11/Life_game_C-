#include "Guarana.h"
#include "Swiat.h"

Guarana::Guarana(Swiat& swiat, const Polozenie& polozenie)
	:Roslina(swiat, polozenie, SYMBOL_GUARANY, SILA_GUARANY, PRAWDOPODOBIENSTWO_GUARANY, PROBY_GUARANY)
{
}

string Guarana::GetNazwa() const
{
	return "Guarana";
}

Organizm* Guarana::Kopiuj(const Polozenie& polozenie)
{
	return new Guarana(this->GetSwiat(), polozenie);
}

bool Guarana::Kolizja(Organizm* wrog)
{
	int nowa_sila = wrog->GetSila() + ILE_SILY;
	wrog->SetSila(nowa_sila);
	this->GetSwiat().GetKomentator()->Oglos_zwiekszenie_sily(wrog, ILE_SILY);
	return Roslina::Kolizja(wrog);
}

Guarana::~Guarana()
{
}