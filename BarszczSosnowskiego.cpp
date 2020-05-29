#include "BarszczSosnowskiego.h"
#include "Swiat.h"

BarszczSosnowskiego::BarszczSosnowskiego(Swiat& swiat, const Polozenie& polozenie)
	:Roslina(swiat, polozenie, SYMBOL_BARSZCZUSOSNOWSKIEGO, SILA_BARSZCZUSOSNOWSKIEGO, PRAWDOPODOBIENSTWO_BARSZCZUSOSNOWSKIEGO, PROBY_BARSZCZUSOSNOWSKIEGO)
{
}

string BarszczSosnowskiego::GetNazwa() const
{
	return "BarszczSosnowskiego";
}

Organizm* BarszczSosnowskiego::Kopiuj(const Polozenie& polozenie)
{
	return new BarszczSosnowskiego(this->GetSwiat(), polozenie);
}

void BarszczSosnowskiego::Akcja()
{
	vector<Polozenie> kombinacje = this->GenerujKombinacje();
	while (true)
	{
		if (kombinacje.size() == 0) return;
		Organizm* o = this->GetSwiat().GetOrganizm(kombinacje.at(0));
		if (o != nullptr && o->Zywy())
		{
			bool if_zwierze = !dynamic_cast<Roslina*>(o);
			if (if_zwierze) {
				o->SetMartwy();
				o->SetGotowy(false);
				this->GetSwiat().DoZabicia(o);
				this->GetSwiat().GetKomentator()->Oglos_zabojstwo(this, o);
			}
		}
		kombinacje.erase(kombinacje.begin());
	}
	Roslina::Akcja();
}

bool BarszczSosnowskiego::Kolizja(Organizm* wrog)
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

BarszczSosnowskiego::~BarszczSosnowskiego()
{
}