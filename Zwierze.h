#pragma once
#include "Helper.h"
#include "Organizm.h"

#define ZASIEG_RUCHU 1
#define SZANSA_WYKONANIA_RUCHU 100

class Zwierze : public Organizm {
private:
	int zasiegRuchu;
	double szansaWykonaniaRuchu;
	bool Ruch();
	bool CzyWykonaRuch();
	void RozmnozSie(Organizm* organizm);
protected:
	virtual Polozenie GenerujPolozenie();
public:
	Zwierze(Swiat& swiat, const Polozenie& polozenie, const char& symbol, const int& sila,
		const int& inicjatywa);
	virtual void Akcja() override;
	virtual bool Kolizja(Organizm* wrog) override;
	virtual bool TenGatunek(Organizm* organizm) = 0;
	vector<Polozenie> GenerujKombinacje();
	virtual void Zapisz(ofstream& wyjscie) override;

	int GetZasiegRuchu() const;
	void SetZasiegRuchu(const int& zasieg);
	double GetSzansaWykonaniaRuchu() const;
	void SetSzansaWykonaniaRuchu(const double& szansa);

	virtual ~Zwierze();
};