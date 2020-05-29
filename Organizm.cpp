#include "Organizm.h"

Organizm::Organizm(Swiat& swiat, const Polozenie& polozenie, const char& symbol,
	const int& sila, const int& inicjatywa)
	:swiat(swiat)
{
	this->wiek = 0;
	this->polozenie = polozenie;
	this->symbol = symbol;
	this->sila = sila;
	this->inicjatywa = inicjatywa;
	this->zyje = true;
	this->gotowy = true;
	this->rozmnozylSie = false;
}

void Organizm::Rysowanie()
{
	if (this == nullptr) cout << '.';
	else cout << this->symbol;
}

Polozenie Organizm::GetPolozenie() const
{
	return this->polozenie;
}

void Organizm::SetPolozenie(const int& x, const int& y)
{
	this->polozenie.x = x;
	this->polozenie.y = y;
}

void Organizm::SetPolozenie(const Polozenie& polozenie)
{
	SetPolozenie(polozenie.x, polozenie.y);
}

int Organizm::GetInicjatywa() const
{
	return this->inicjatywa;
}

void Organizm::SetInicjatywa(const int& inicjatywa)
{
	this->inicjatywa = inicjatywa;
}

int Organizm::GetSila() const
{
	return this->sila;
}

void Organizm::SetSila(const int& sila)
{
	this->sila = sila;
}

char Organizm::GetSymbol() const
{
	return this->symbol;
}

void Organizm::SetSymbol(const char& symbol)
{
	this->symbol = symbol;
}

bool Organizm::Zywy()
{
	return this->zyje;
}

int Organizm::GetWiek() const
{
	return this->wiek;
}

void Organizm::SetMartwy()
{
	this->zyje = false;
}

void Organizm::Uzdrow()
{
	this->zyje = true;
}

void Organizm::DodajWiek()
{
	this->wiek = this->wiek + 1;
}

bool Organizm::GetGotowy() const
{
	return this->gotowy;
}

void Organizm::SetGotowy(const bool& gotowy)
{
	this->gotowy = gotowy;
}

Swiat& Organizm::GetSwiat() const
{
	return this->swiat;
}

bool Organizm::GetRozmnozenie() const
{
	return this->rozmnozylSie;
}

void Organizm::SetRozmnozenie(const bool& rozmnozenie)
{
	this->rozmnozylSie = rozmnozenie;
}

void Organizm::SetWiek(const int& wiek)
{
	this->wiek = wiek;
}

int Organizm::Zaladuj(const string& line)
{
	int count = 0;
	int limit = 4;
	int i = 2;
	while (count < limit)
	{
		char c = line[i];
		if (c == ' ') i++;
		else
		{
			string number = "";
			while (c >= '0' && c <= '9' && i < line.length())
			{
				number += c;
				i++;
				c = line[i];
			}
			if (number != "")
			{
				int result;
				result = stoi(number);
				if (count == 0) this->SetWiek(result);
				else if (count == 1) this->SetSila(result);
				else if (count == 2) this->SetPolozenie(result, this->GetPolozenie().y);
				else if (count == 3) this->SetPolozenie(this->GetPolozenie().x, result);
				count++;
			}
			i++;
		}
	}
	return i;
}

Organizm::~Organizm()
{
}