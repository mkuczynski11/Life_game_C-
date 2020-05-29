#include "Antylopa.h"
#include "Swiat.h"

Antylopa::Antylopa(Swiat& swiat, const Polozenie& polozenie)
	:Zwierze(swiat, polozenie, SYMBOL_ANTYLOPY, SILA_ANTYLOPY, INICJATYWA_ANTYLOPY)
{
	this->SetZasiegRuchu(ZASIEG_ANTYLOPY);
}

string Antylopa::GetNazwa() const
{
	return "Antylopa";
}

Organizm* Antylopa::Kopiuj(const Polozenie& polozenie)
{
	return new Antylopa(this->GetSwiat(), polozenie);
}

bool Antylopa::TenGatunek(Organizm* organizm)
{
	return dynamic_cast<Antylopa*>(organizm);
}

bool Antylopa::Kolizja(Organizm* wrog)
{
	double d = (double)(rand() % 101);
	if (d <= (double)50)
	{
		vector<Polozenie> kombinacje = this->GenerujKombinacje();
		while (true)
		{
			if (kombinacje.size() == 0) return Zwierze::Kolizja(wrog);
			int choice = rand() % kombinacje.size();
			Organizm* o = this->GetSwiat().GetOrganizm(kombinacje.at(choice));
			if (o == nullptr || (!o->Zywy()))
			{
				this->GetSwiat().GetKomentator()->Oglos_ucieczke(this, wrog);
				this->GetSwiat().PrzeniesOrganizm(this->GetPolozenie(), kombinacje.at(choice));
				return true;
			}
			kombinacje.erase(kombinacje.begin() + choice);
		}
	}
	else
	{
		return Zwierze::Kolizja(wrog);
	}
}

Antylopa::~Antylopa()
{
}