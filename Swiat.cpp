#include "Swiat.h"
#include "Antylopa.h"
#include "CyberOwca.h"
#include "Czlowiek.h"
#include "Lis.h"
#include "Owca.h"
#include "Wilk.h"
#include "Zolw.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"

void Swiat::WypelnijSwiat()
{
	HelperWypelniania(1, SYMBOL_CZLOWIEKA);
	HelperWypelniania(ILOSC_WILKOW, SYMBOL_WILKA);
	HelperWypelniania(ILOSC_ZOLWI, SYMBOL_ZOLWIA);
	HelperWypelniania(ILOSC_OWIEC, SYMBOL_OWCY);
	HelperWypelniania(ILOSC_LISOW, SYMBOL_LISA);
	//HelperWypelniania(ILOSC_CYBEROWIEC, SYMBOL_CYBEROWCY);
	HelperWypelniania(ILOSC_ANTYLOP, SYMBOL_ANTYLOPY);
	HelperWypelniania(ILOSC_TRAWY, SYMBOL_TRAWY);
	HelperWypelniania(ILOSC_MLECZY, SYMBOL_MLECZA);
	HelperWypelniania(ILOSC_GUARANY, SYMBOL_GUARANY);
	HelperWypelniania(ILOSC_WILCZYCHJAGOD, SYMBOL_WILCZYCHJAGOD);
	HelperWypelniania(ILOSC_BARSZCZUSOSNOWSKIEGO, SYMBOL_BARSZCZUSOSNOWSKIEGO);
	sort(this->lista.begin(), this->lista.end(), Swiat::FunkcjaSortujaca);
	this->rysujSwiat();
}

void Swiat::HelperWypelniania(int limit, char symbol)
{
	size_t i = 0;
	while (i < limit)
	{
		Organizm* tmp;
		int x;
		int y;
		while (true)
		{
			x = rand() % this->szerokosc;
			y = rand() % this->dlugosc;
			tmp = this->organizmy[y][x];
			if (tmp == nullptr) break;
		}
		Polozenie p;
		p.x = x;
		p.y = y;
		if (symbol == SYMBOL_CZLOWIEKA) this->organizmy[y][x] = new Czlowiek(*this, p);
		else if (symbol == SYMBOL_WILKA) this->organizmy[y][x] = new Wilk(*this, p);
		else if (symbol == SYMBOL_ZOLWIA) this->organizmy[y][x] = new Zolw(*this, p);
		else if (symbol == SYMBOL_OWCY) this->organizmy[y][x] = new Owca(*this, p);
		else if (symbol == SYMBOL_LISA) this->organizmy[y][x] = new Lis(*this, p);
		//else if (symbol == SYMBOL_CYBEROWCY) this->organizmy[y][x] = new CyberOwca(*this, p);
		else if (symbol == SYMBOL_ANTYLOPY) this->organizmy[y][x] = new Antylopa(*this, p);
		else if (symbol == SYMBOL_TRAWY) this->organizmy[y][x] = new Trawa(*this, p);
		else if (symbol == SYMBOL_MLECZA) this->organizmy[y][x] = new Mlecz(*this, p);
		else if (symbol == SYMBOL_GUARANY) this->organizmy[y][x] = new Guarana(*this, p);
		else if (symbol == SYMBOL_WILCZYCHJAGOD) this->organizmy[y][x] = new WilczeJagody(*this, p);
		else if (symbol == SYMBOL_BARSZCZUSOSNOWSKIEGO) this->organizmy[y][x] = new BarszczSosnowskiego(*this, p);
		i++;
		this->lista.push_back(this->organizmy[y][x]);
	}
}

void Swiat::ZapiszGre()
{
	ofstream plik;
	plik.open("zapis.txt");
	plik << "S " << this->dlugosc << " " << this->szerokosc << " " << this->tura << "\n";
	for (Organizm* o : lista)
	{
		o->Zapisz(plik);
	}
	plik.close();
}

bool Swiat::FunkcjaSortujaca(const Organizm* l, const Organizm* p)
{
	if (l->GetInicjatywa() != p->GetInicjatywa())
	{
		return (l->GetInicjatywa() > p->GetInicjatywa());
	}
	return (l->GetWiek() > p->GetWiek());
}

Swiat::Swiat(const int& szerokosc, const int& dlugosc)
{
	this->komentator = new Komentator();
	this->szerokosc = szerokosc;
	this->dlugosc = dlugosc;
	this->tura = 0;
	this->organizmy = new Organizm * *[dlugosc];
	size_t i = 0;
	while (i < dlugosc)
	{
		this->organizmy[i] = new Organizm * [szerokosc];
		size_t j = 0;
		while (j < szerokosc)
		{
			organizmy[i][j] = nullptr;
			j++;
		}
		i++;
	}
	this->WypelnijSwiat();
}

Swiat::Swiat(ifstream& wejscie)
{
	this->komentator = new Komentator();
	string line;
	getline(wejscie, line);
	int count = 0;
	int limit = 3;
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
				if (count == 0) this->dlugosc = result;
				else if (count == 1) this->szerokosc = result;
				else if (count == 2) this->tura = result;
				count++;
			}
			i++;
		}
	}
	this->organizmy = new Organizm * *[this->dlugosc];
	i = 0;
	while (i < this->dlugosc)
	{
		this->organizmy[i] = new Organizm * [this->szerokosc];
		size_t j = 0;
		while (j < this->szerokosc)
		{
			organizmy[i][j] = nullptr;
			j++;
		}
		i++;
	}
	while (getline(wejscie, line))
	{
		char symbol = line[0];
		Organizm* nowy = nullptr;
		Polozenie p;
		p.x = 0;
		p.y = 0;
		if (symbol == SYMBOL_CZLOWIEKA)
		{
			nowy = new Czlowiek(*this, p);
		}
		else
		{
			if (symbol == SYMBOL_WILKA) nowy = new Wilk(*this, p);
			else if (symbol == SYMBOL_ZOLWIA) nowy = new Zolw(*this, p);
			else if (symbol == SYMBOL_OWCY) nowy = new Owca(*this, p);
			else if (symbol == SYMBOL_LISA) nowy = new Lis(*this, p);
			//else if (symbol == SYMBOL_CYBEROWCY) nowy = new CyberOwca(*this, p);
			else if (symbol == SYMBOL_ANTYLOPY) nowy = new Antylopa(*this, p);
			else if (symbol == SYMBOL_TRAWY) nowy = new Trawa(*this, p);
			else if (symbol == SYMBOL_MLECZA) nowy = new Mlecz(*this, p);
			else if (symbol == SYMBOL_GUARANY) nowy = new Guarana(*this, p);
			else if (symbol == SYMBOL_WILCZYCHJAGOD) nowy = new WilczeJagody(*this, p);
			else if (symbol == SYMBOL_BARSZCZUSOSNOWSKIEGO) nowy = new BarszczSosnowskiego(*this, p);
		}
		nowy->Zaladuj(line);
		this->organizmy[nowy->GetPolozenie().y][nowy->GetPolozenie().x] = nowy;
		this->lista.push_back(nowy);
	}
	this->rysujSwiat();
}

void Swiat::wykonajTure()
{
	system("CLS");
	cout << IMIE << " " << NAZWISKO << " " << INDEKS << endl;
	int i = 0;
	for (Organizm* o : lista)
	{
		o->Akcja();
		o->DodajWiek();
		i++;
	}
	this->Dodaj();
	this->Zabij();
	this->Napraw();
	sort(this->lista.begin(), this->lista.end(), Swiat::FunkcjaSortujaca);
	this->tura = this->tura + 1;
}

void Swiat::rysujSwiat()
{
	size_t i = 0;
	while (i < szerokosc+2)
	{
		cout << "-";
		i++;
	}
	cout << endl;
	i = 0;
	while (i < this->dlugosc)
	{
		size_t j = 0;
		cout << "-";
		while (j < this->szerokosc)
		{
			if (this->organizmy[i][j] == nullptr || !this->organizmy[i][j]->Zywy()) cout << '*';
			else this->organizmy[i][j]->Rysowanie();
			j++;
		}
		cout << "-";
		cout << endl;
		i++;
	}
	i = 0;
	while (i < szerokosc + 2)
	{
		cout << "-";
		i++;
	}
	cout << endl;
}

size_t Swiat::GetDlugosc() const
{
	return this->dlugosc;
}

size_t Swiat::GetSzerokosc() const
{
	return this->szerokosc;
}

Organizm* Swiat::GetOrganizm(const Polozenie& polozenie)
{
	return GetOrganizm(polozenie.x, polozenie.y);
}

Organizm* Swiat::GetOrganizm(const int& x, const int &y)
{
	return this->organizmy[y][x];
}

Komentator* Swiat::GetKomentator() const
{
	return this->komentator;
}

void Swiat::PrzeniesOrganizm(const Polozenie& polozenie1, const Polozenie& polozenie2)
{
	Organizm* tmp = this->organizmy[polozenie1.y][polozenie1.x];
	this->organizmy[polozenie1.y][polozenie1.x] = this->organizmy[polozenie2.y][polozenie2.x];
	if (this->organizmy[polozenie1.y][polozenie1.x] != nullptr)
	{
		this->organizmy[polozenie1.y][polozenie1.x]->SetPolozenie(polozenie1.x, polozenie1.y);
	}
	this->organizmy[polozenie2.y][polozenie2.x] = tmp;
	if(tmp != nullptr)
		this->organizmy[polozenie2.y][polozenie2.x]->SetPolozenie(polozenie2.x, polozenie2.y);
}

void Swiat::Napraw()
{
	while (true)
	{
		if (poRozmnozeniu.size() == 0) return;
		Napraw_helper(poRozmnozeniu[0]);
		poRozmnozeniu.erase(poRozmnozeniu.begin());
	}
}

void Swiat::Napraw_helper(Organizm* organizm)
{
	int i = 0;
	while (i < this->lista.size())
	{
		if ((this->lista[i]->GetPolozenie().x == organizm->GetPolozenie().x) && (this->lista[i]->GetPolozenie().y == organizm->GetPolozenie().y))
		{
			this->lista[i]->SetRozmnozenie(false);
			break;
		}
		i++;
	}
}

void Swiat::DoNaprawy(Organizm* organizm)
{
	if (organizm == nullptr) return;
	poRozmnozeniu.push_back(organizm);
}

void Swiat::Zabij()
{
	int j = 0;
	while (true)
	{
		if (doZabicia.size() == 0) return;
		Zabij_helper(doZabicia[0]);
		doZabicia.erase(doZabicia.begin());
	}
}

void Swiat::Zabij_helper(Organizm * organizm)
{
	int i = 0;
	while (i < this->lista.size())
	{
		if ((this->lista[i]->GetPolozenie().x == organizm->GetPolozenie().x) && (this->lista[i]->GetPolozenie().y == organizm->GetPolozenie().y))
		{
			this->lista.erase(this->lista.begin() + i);
			Polozenie p = organizm->GetPolozenie();
			if (!this->organizmy[p.y][p.x]->Zywy())
				this->organizmy[p.y][p.x] = nullptr;
			delete organizm;
			break;
		}
		i++;
	}
}

void Swiat::DoZabicia(Organizm* organizm)
{
	if (organizm == nullptr) return;
	doZabicia.push_back(organizm);
}

void Swiat::Dodaj()
{
	while (true)
	{
		if (doDodania.size() == 0) return;
		Dodaj_helper(doDodania[0]);
		doDodania.erase(doDodania.begin());
	}
}

void Swiat::Dodaj_helper(Organizm* organizm)
{
	lista.push_back(organizm);
	organizm->SetGotowy(true);
}

void Swiat::DoDodania(Organizm* organizm)
{
	Polozenie p;
	p.x = organizm->GetPolozenie().x;
	p.y = organizm->GetPolozenie().y;
	this->organizmy[p.y][p.x] = organizm;
	doDodania.push_back(organizm);
}

Swiat::~Swiat()
{
	size_t i = 0;
	while (i < this->dlugosc)
	{
		size_t j = 0;
		while (j < this->szerokosc)
		{
			if (this->organizmy[i][j] != nullptr) delete organizmy[i][j];
			j++;
		}
		delete[] this->organizmy[i];
		i++;
	}
	delete[] this->organizmy;
}