#include "Lis.h"
#include "Swiat.h"

Lis::Lis(Swiat& swiat, const Polozenie& polozenie)
	:Zwierze(swiat, polozenie, SYMBOL_LISA, SILA_LISA, INICJATYWA_LISA)
{
}

string Lis::GetNazwa() const
{
	return "Lis";
}

Organizm* Lis::Kopiuj(const Polozenie& polozenie)
{
	return new Lis(this->GetSwiat(), polozenie);
}

bool Lis::TenGatunek(Organizm* organizm)
{
	return dynamic_cast<Lis*>(organizm);
}

Polozenie Lis::GenerujPolozenie()
{
	int x = this->GetPolozenie().x;
	int y = this->GetPolozenie().y;
	bool koniec = false;
	Polozenie tmp;
	vector<Polozenie> kombinacje;
	tmp.y = y;
	if (x != 0)
	{
		tmp.x = x - 1;
		kombinacje.push_back(tmp);
	}
	if (x != this->GetSwiat().GetSzerokosc() - 1)
	{
		tmp.x = x + 1;
		kombinacje.push_back(tmp);
	}
	tmp.x = x;
	if (y != 0)
	{
		tmp.y = y - 1;
		kombinacje.push_back(tmp);
	}
	if (y != this->GetSwiat().GetDlugosc() - 1)
	{
		tmp.y = y + 1;
		kombinacje.push_back(tmp);
	}

	while (true)
	{
		if (kombinacje.size() == 0) break;
		int choice = rand() % kombinacje.size();
		tmp = kombinacje.at(choice);
		Organizm* o = this->GetSwiat().GetOrganizm(tmp);
		if (o == nullptr || (!o->Zywy())) return tmp;
		else if (this->TenGatunek(o)) return tmp;
		kombinacje.erase(kombinacje.begin() + choice);
	}
	tmp.x = this->GetPolozenie().x;
	tmp.y = this->GetPolozenie().y;
	return tmp;
}

Lis::~Lis()
{
}