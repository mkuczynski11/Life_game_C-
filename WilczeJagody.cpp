#include "WilczeJagody.h"
#include "Swiat.h"

WilczeJagody::WilczeJagody(Swiat& swiat, const Polozenie& polozenie)
	:Roslina(swiat, polozenie, SYMBOL_WILCZYCHJAGOD, SILA_WILCZYCHJAGOD, PRAWDOPODOBIENSTWO_WILCZYCHJAGOD, PROBY_WILCZYCHJAGOD)
{
}

string WilczeJagody::GetNazwa() const
{
	return "WilczeJagody";
}

Organizm* WilczeJagody::Kopiuj(const Polozenie& polozenie)
{
	return new WilczeJagody(this->GetSwiat(), polozenie);
}

bool WilczeJagody::Kolizja(Organizm* wrog)
{
	this->SetMartwy();
	this->SetGotowy(false);
	this->GetSwiat().DoZabicia(this);
	this->GetSwiat().GetKomentator()->Oglos_zjedzenie(this, wrog);
	wrog->SetMartwy();
	wrog->SetGotowy(false);
	this->GetSwiat().DoZabicia(wrog);
	this->GetSwiat().GetKomentator()->Oglos_zabojstwo(this, wrog);
	return false;
}

WilczeJagody::~WilczeJagody()
{
}