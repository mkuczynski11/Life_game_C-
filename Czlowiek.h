#pragma once
#include "Helper.h"
#include "Zwierze.h"
#include <conio.h>

#define SILA_CZLOWIEKA 5
#define INICJATYWA_CZLOWIEKA 4
#define SYMBOL_CZLOWIEKA 'C'
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define COOLDOWN 5

class Czlowiek : public Zwierze {
private:
	Polozenie GenerujPolozenie() override;
	int tury_umiejetnosci;
	int cooldown;
	void Umiejetnosc_specjalna();
public:
	Czlowiek(Swiat& swiat, const Polozenie& polozenie);
	string GetNazwa() const override;
	void Akcja() override;
	bool TenGatunek(Organizm* organizm);
	Organizm* Kopiuj(const Polozenie& polozenie);
	void Zapisz(ofstream& wyjscie) override;

	int GetTuryUmiejetnosci() const;
	void SetTuryUmiejetnosci(const int& tury);
	int GetCooldown() const;
	void SetCooldown(const int& cooldown);
	int Zaladuj(const string& line) override;

	~Czlowiek();
};