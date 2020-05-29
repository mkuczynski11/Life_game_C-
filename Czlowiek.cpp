#pragma warning(disable : 4996)
#include "Czlowiek.h"
#include "Swiat.h"

Czlowiek::Czlowiek(Swiat& swiat, const Polozenie& polozenie)
	:Zwierze(swiat, polozenie, SYMBOL_CZLOWIEKA, SILA_CZLOWIEKA, INICJATYWA_CZLOWIEKA)
{
	this->tury_umiejetnosci = 0;
	this->cooldown = COOLDOWN;
}

string Czlowiek::GetNazwa() const
{
	return "Czlowiek";
}

Polozenie Czlowiek::GenerujPolozenie()
{
	int c = 0;
	Polozenie nowe;
	cout << "Nacisnij kierunek korzystajac ze strzalek." << endl;
	c = getch();
	switch ((c = getch()))
	{
	case KEY_UP:
		if (this->GetPolozenie().y == 0) return Zwierze::GenerujPolozenie();
		nowe.x = this->GetPolozenie().x;
		nowe.y = this->GetPolozenie().y - 1;
		break;
	case KEY_DOWN:
		if (this->GetPolozenie().y == this->GetSwiat().GetDlugosc() - 1) return Zwierze::GenerujPolozenie();
		nowe.x = this->GetPolozenie().x;
		nowe.y = this->GetPolozenie().y + 1;
		break;
	case KEY_LEFT:
		if(this->GetPolozenie().x == 0) return Zwierze::GenerujPolozenie();
		nowe.x = this->GetPolozenie().x - 1;
		nowe.y = this->GetPolozenie().y;
		break;
	case KEY_RIGHT:
		if (this->GetPolozenie().x == this->GetSwiat().GetSzerokosc() -1) return Zwierze::GenerujPolozenie();
		nowe.x = this->GetPolozenie().x + 1;
		nowe.y = this->GetPolozenie().y;
		break;
	default:
		return Zwierze::GenerujPolozenie();
		break;
	}
	return nowe;
}

void Czlowiek::Akcja()
{
	this->GetSwiat().rysujSwiat();
	if (this->cooldown == 0 && this->tury_umiejetnosci == 0) {
		cout << "Czy uruchomic umiejetnosc specjalna?(T-tak,N-nie)" << endl;
		char c;
		cin >> c;
		if (c == 't' || c == 'T')
		{
			this->tury_umiejetnosci = 5;
		}
	}
	else
	{
		if (this->tury_umiejetnosci != 0)
		{
			Umiejetnosc_specjalna();
			this->tury_umiejetnosci = this->tury_umiejetnosci - 1;
			if (this->tury_umiejetnosci == 0) this->cooldown = COOLDOWN;
		}
		else if (this->cooldown != 0)
		{
			this->cooldown = this->cooldown - 1;
		}
	}
	Zwierze::Akcja();
}

bool Czlowiek::TenGatunek(Organizm* organizm)
{
	return dynamic_cast<Czlowiek*>(organizm);
}

Organizm* Czlowiek::Kopiuj(const Polozenie& polozenie)
{
	return new Czlowiek(this->GetSwiat(), polozenie);
}

void Czlowiek::Umiejetnosc_specjalna()
{
	vector<Polozenie> kombinacje = this->GenerujKombinacje();
	while (true)
	{
		if (kombinacje.size() == 0) return;
		Organizm* o = this->GetSwiat().GetOrganizm(kombinacje.at(0));
		if (o != nullptr && o->Zywy())
		{
			o->SetMartwy();
			o->SetGotowy(false);
			this->GetSwiat().DoZabicia(o);
			this->GetSwiat().GetKomentator()->Oglos_zabojstwo(this, o);
		}
		kombinacje.erase(kombinacje.begin());
	}
}

int Czlowiek::GetTuryUmiejetnosci() const
{
	return this->tury_umiejetnosci;
}

void Czlowiek::SetTuryUmiejetnosci(const int& tury)
{
	this->tury_umiejetnosci = tury;
}

int Czlowiek::GetCooldown() const
{
	return this->cooldown;
}

void Czlowiek::SetCooldown(const int& cooldown)
{
	this->cooldown = cooldown;
}

void Czlowiek::Zapisz(ofstream& wyjscie)
{
	wyjscie << this->GetSymbol() << " " << this->GetWiek() << " " << this->GetSila() << " " << this->GetPolozenie().x << " " << this->GetPolozenie().y << " " << this->GetTuryUmiejetnosci() << " " << this->GetCooldown() << "\n";
}

int Czlowiek::Zaladuj(const string& line)
{
	int i = Organizm::Zaladuj(line);
	int count = 0;
	int limit = 2;
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
				if (count == 0) this->SetTuryUmiejetnosci(result);
				else if (count == 1) this->SetCooldown(result);
				count++;
			}
			i++;
		}
	}
	return i;
}

Czlowiek::~Czlowiek()
{
}