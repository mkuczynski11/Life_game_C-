#pragma once
#include "Helper.h"

class Swiat;

struct Polozenie {
	int x;
	int y;
};

class Organizm {
private:
	int wiek;
	int sila;
	int inicjatywa;
	Polozenie polozenie;
	Swiat& swiat;
	char symbol;
	bool zyje;
	bool gotowy;
	bool rozmnozylSie;
public:
	Organizm(Swiat& swiat, const Polozenie& polozenie, const char& symbol,
		const int& sila, const int& inicjatywa);
	virtual void Akcja() = 0;
	virtual bool Kolizja(Organizm* wrog) = 0;
	virtual string GetNazwa() const = 0;
	virtual Organizm* Kopiuj(const Polozenie& polozenie) = 0;
	virtual void Rysowanie();
	virtual void Zapisz(ofstream& wyjscie) = 0;

	Polozenie GetPolozenie() const;
	void SetPolozenie(const int& x, const int& y);
	void SetPolozenie(const Polozenie& polozenie);
	int GetInicjatywa() const;
	void SetInicjatywa(const int& inicjatywa);
	int GetSila() const;
	void SetSila(const int& sila);
	char GetSymbol() const;
	void SetSymbol(const char& symbol);
	bool Zywy();
	void SetMartwy();
	void Uzdrow();
	int GetWiek() const;
	void DodajWiek();
	void SetWiek(const int& wiek);
	bool GetGotowy() const;
	void SetGotowy(const bool& gotowy);
	Swiat& GetSwiat() const;
	bool GetRozmnozenie() const;
	void SetRozmnozenie(const bool& rozmnozenie);
	virtual int Zaladuj(const string& line);

	virtual ~Organizm();
};