#pragma once
#include "Helper.h"
#include "Organizm.h"

#define PRWADOPODOBIENSTO_ROZMNOZENIA 10

class Roslina : public Organizm{
private:
	double prawdopodobienstwo;
	int ilosc_prob;
	bool Rozmnozenie();
public:
	Roslina(Swiat& swiat, const Polozenie& polozenie, const char& symbol, const int& sila, const double& prawdopodobienstwo, const int& ilosc);
	virtual void Akcja() override;
	virtual bool Kolizja(Organizm * wrog) override;
	vector<Polozenie> GenerujKombinacje();
	void Zapisz(ofstream& wyjscie) override;

	double GetPrawdopodobienstwo() const;
	void SetPrawdopodobienstwo(const double& prawdopodobienstwo);
	int GetIloscProb() const;
	void SetIloscProb(const int& ilosc);

	virtual ~Roslina();
};