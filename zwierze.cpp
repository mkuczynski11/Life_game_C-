#include "Zwierze.h"
#include "Swiat.h"

Zwierze::Zwierze(Swiat& swiat, const Polozenie& polozenie, const char& symbol, const int& sila,
	const int& inicjatywa)
	:Organizm(swiat, polozenie, symbol, sila, inicjatywa)
{
	this->zasiegRuchu = ZASIEG_RUCHU;
	this->szansaWykonaniaRuchu = SZANSA_WYKONANIA_RUCHU;
}

void Zwierze::Akcja()
{
	if (this->CzyWykonaRuch() && (this->GetGotowy()))
	{
		int i = 0;
		while (i < this->zasiegRuchu)
		{
			if (!Ruch()) break;
			i++;
		}
	}
}

bool Zwierze::Ruch()
{
	Polozenie gdzie = this->GenerujPolozenie();
	if (gdzie.x == this->GetPolozenie().x && gdzie.y == this->GetPolozenie().y)
	{
		//this->swiat.GetKomentator()->Oglos_przesuniecie(this->polozenie, gdzie, this);
		return true;
	}
	Organizm* o = this->GetSwiat().GetOrganizm(gdzie);
	if (o == nullptr || (!o->Zywy()))
	{
		//this->swiat.GetKomentator()->Oglos_przesuniecie(this->polozenie, gdzie, this);
		this->GetSwiat().PrzeniesOrganizm(this->GetPolozenie(), gdzie);
		return true;
	}
	else if (this->TenGatunek(o) && o->Zywy())
	{
		if ((!this->GetRozmnozenie()) && (!o->GetRozmnozenie())) {
			this->RozmnozSie(o);
			return false;
		}
		return true;
	}
	else if (o->Zywy())
	{
		if (o->Kolizja(this)) {
		//this->swiat.GetKomentator()->Oglos_przesuniecie(this->polozenie, gdzie, this);
		this->GetSwiat().PrzeniesOrganizm(this->GetPolozenie(), gdzie);
		}
		return false;
	}
}

void Zwierze::RozmnozSie(Organizm* organizm)
{
	int x = organizm->GetPolozenie().x;
	int y = organizm->GetPolozenie().y;
	int add_x = 0;
	int limit_x = 0;
	int add_y = 0;
	int limit_y = 0;
	if (x == 0)
	{
		add_x = 0;
		limit_x = 2;
	}
	else if (x == this->GetSwiat().GetSzerokosc() - 1)
	{
		add_x = -1;
		limit_x = 1;
	}
	else
	{
		add_x = -1;
		limit_x = 2;
	}

	if (y == 0)
	{
		add_y = 0;
		limit_y = 2;
	}
	else if (y == this->GetSwiat().GetDlugosc() - 1)
	{
		add_y = -1;
		limit_y = 1;
	}
	else
	{
		add_y = -1;
		limit_y = 2;
	}
	vector<Polozenie> kombinacje;
	while (add_x < limit_x)
	{
		int another_y = add_y;
		while (another_y < limit_y)
		{
			Polozenie tmp;
			tmp.x = x + add_x;
			tmp.y = y + another_y;
			kombinacje.push_back(tmp);
			another_y++;
		}
		add_x++;
	}
	while (true)
	{
		if (kombinacje.size() == 0) break;
		int choice = rand() % kombinacje.size();
		Organizm* o = this->GetSwiat().GetOrganizm(kombinacje.at(choice));
		if (o == nullptr || (!o->Zywy()))
		{
			Organizm* tmp = this->Kopiuj(kombinacje.at(choice));
			tmp->SetGotowy(false);
			this->GetSwiat().DoDodania(tmp);
			this->GetSwiat().GetKomentator()->Oglos_rozmnozenie(this, organizm, tmp);
			this->SetRozmnozenie(true);
			this->GetSwiat().DoNaprawy(this);
			organizm->SetRozmnozenie(true);
			organizm->GetSwiat().DoNaprawy(organizm);
			return;
		}
		kombinacje.erase(kombinacje.begin() + choice);
	}
}

bool Zwierze::CzyWykonaRuch()
{
	double d = (double)(rand() % 101);
	if (d <= this->szansaWykonaniaRuchu)
		return true;
	//cout << "Organizm nie wykonuje ruchu" << endl;
	return false;
}

Polozenie Zwierze::GenerujPolozenie()
{
	int x = this->GetPolozenie().x;
	int y = this->GetPolozenie().y;
	int choice = rand() % 2;
	Polozenie tmp;
	tmp.x = 0;
	tmp.y = 0;
	if (choice == 0)
	{
		tmp.y = y;
		int new_x;
		if (x == 0) new_x = (rand() % 2);
		else if (x == this->GetSwiat().GetSzerokosc() - 1) new_x = (rand() % 2) - 1;
		else new_x = (rand() % 3) - 1;
		tmp.x = x + new_x;
	}
	else if (choice == 1)
	{
		tmp.x = x;
		int new_y;
		if (y == 0) new_y = (rand() % 2);
		else if (y == this->GetSwiat().GetDlugosc() - 1) new_y = (rand() % 2) - 1;
		else new_y = (rand() % 3) - 1;
		tmp.y = y + new_y;
	}
	return tmp;
}

vector<Polozenie> Zwierze::GenerujKombinacje()
{
	int x = this->GetPolozenie().x;
	int y = this->GetPolozenie().y;
	vector<Polozenie> result;
	Polozenie tmp;
	if (x != 0)
	{
		tmp.x = x - 1;
		tmp.y = y;
		result.push_back(tmp);
	}
	if (x != this->GetSwiat().GetSzerokosc() - 1)
	{
		tmp.x = x + 1;
		tmp.y = y;
		result.push_back(tmp);
	}
	if (y != 0)
	{
		tmp.x = x;
		tmp.y = y - 1;
		result.push_back(tmp);
	}
	if (y != this->GetSwiat().GetDlugosc() - 1)
	{
		tmp.x = x;
		tmp.y = y + 1;
		result.push_back(tmp);
	}
	return result;
}

bool Zwierze::Kolizja(Organizm* wrog)
{
	if (this->GetSila() > wrog->GetSila()) //obronca sie obronil
	{
		wrog->SetMartwy();
		wrog->SetGotowy(false);
		this->GetSwiat().DoZabicia(wrog);
		this->GetSwiat().GetKomentator()->Oglos_zabojstwo(this, wrog);
		return false;
	}
	else //atakujacy wygral
	{
		this->SetMartwy();
		this->SetGotowy(false);
		this->GetSwiat().DoZabicia(this);
		this->GetSwiat().GetKomentator()->Oglos_zabojstwo(wrog, this);
		return true;
	}
}

int Zwierze::GetZasiegRuchu() const
{
	return this->zasiegRuchu;
}

void Zwierze::SetZasiegRuchu(const int& zasieg)
{
	this->zasiegRuchu = zasieg;
}

double Zwierze::GetSzansaWykonaniaRuchu() const
{
	return this->szansaWykonaniaRuchu;
}

void Zwierze::SetSzansaWykonaniaRuchu(const double& szansa)
{
	this->szansaWykonaniaRuchu = szansa;
}

void Zwierze::Zapisz(ofstream& wyjscie)
{
	wyjscie << this->GetSymbol() << " " << this->GetWiek() << " " << this->GetSila() << " " << this->GetPolozenie().x << " " << this->GetPolozenie().y << "\n";
}

Zwierze::~Zwierze()
{
}