#include "Roslina.h"
#include "Swiat.h"

Roslina::Roslina(Swiat& swiat, const Polozenie& polozenie, const char& symbol, const int& sila, const double& prawdopodobienstwo, const int& ilosc)
	:Organizm(swiat, polozenie, symbol, sila, 0)
{
	this->prawdopodobienstwo = prawdopodobienstwo;
	this->ilosc_prob = ilosc;
}

void Roslina::Akcja()
{
	int i = 0;
	while (i < this->ilosc_prob && (!this->Rozmnozenie()) && (this->GetGotowy()))
		i++;
}

bool Roslina::Rozmnozenie()
{
	double d = double(rand() % 101);
	if (d > this->prawdopodobienstwo)
	{
		return false;
	}
	vector<Polozenie> kombinacje = this->GenerujKombinacje();
	while (true)
	{
		if (kombinacje.size() == 0) return false;
		int choice = rand() % kombinacje.size();
		Organizm* o = this->GetSwiat().GetOrganizm(kombinacje.at(choice));
		if (o == nullptr || (!o->Zywy()))
		{
			Organizm* tmp = this->Kopiuj(kombinacje.at(choice));
			tmp->SetGotowy(false);
			this->GetSwiat().DoDodania(tmp);
			this->GetSwiat().GetKomentator()->Oglos_rozmnozenie(this, tmp);
			return true;
		}
		kombinacje.erase(kombinacje.begin() + choice);
	}
}

vector<Polozenie> Roslina::GenerujKombinacje()
{
	int x = this->GetPolozenie().x;
	int y = this->GetPolozenie().y;
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
	return kombinacje;
}

bool Roslina::Kolizja(Organizm* wrog)
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
		this->GetSwiat().GetKomentator()->Oglos_zjedzenie(this, wrog);
		return true;
	}
}

double Roslina::GetPrawdopodobienstwo() const
{
	return this->prawdopodobienstwo;
}

void Roslina::SetPrawdopodobienstwo(const double& prawdopodobienstwo)
{
	this->prawdopodobienstwo = prawdopodobienstwo;
}

int Roslina::GetIloscProb() const
{
	return this->ilosc_prob;
}

void Roslina::SetIloscProb(const int& ilosc)
{
	this->ilosc_prob = ilosc;
}

void Roslina::Zapisz(ofstream& wyjscie)
{
	wyjscie << this->GetSymbol() << " " << this->GetWiek() << " " << this->GetSila() << " " << this->GetPolozenie().x << " " << this->GetPolozenie().y << "\n";
}

Roslina::~Roslina()
{
}