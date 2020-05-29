#pragma once
#include "Organizm.h"
#include "Helper.h"
#include "Komentator.h"

class Swiat {
private:
	Komentator* komentator;
	Organizm*** organizmy;
	vector<Organizm*> lista;
	vector<Organizm*> doZabicia;
	vector<Organizm*> doDodania;
	vector<Organizm*> poRozmnozeniu;
	int dlugosc;
	int szerokosc;
	int tura;
	void WypelnijSwiat();
	void HelperWypelniania(int limit, char symbol);
	static bool FunkcjaSortujaca(const Organizm* l, const Organizm* p);
	void Zabij();
	void Zabij_helper(Organizm* organizm);
	void Dodaj();
	void Dodaj_helper(Organizm* organizm);
	void Napraw();
	void Napraw_helper(Organizm* organizm);
public:
	Swiat(const int& szerokosc, const int& dlugosc);
	Swiat(ifstream& wejscie);
	void wykonajTure();
	void rysujSwiat();
	Organizm* GetOrganizm(const Polozenie& polozenie);
	Organizm* GetOrganizm(const int& x, const int& y);
	void PrzeniesOrganizm(const Polozenie& polozenie1, const Polozenie& polozenie2);
	void DoZabicia(Organizm* organizm);
	Komentator* GetKomentator() const;
	void DoDodania(Organizm* organizm);
	void DoNaprawy(Organizm* organizm);
	void ZapiszGre();

	size_t GetDlugosc() const;
	size_t GetSzerokosc() const;

	~Swiat();
};