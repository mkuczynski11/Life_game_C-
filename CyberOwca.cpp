#include "CyberOwca.h"

CyberOwca::CyberOwca(Swiat& swiat, const Polozenie& polozenie)
	:Zwierze(swiat, polozenie, SYMBOL_CYBEROWCY, SILA_CYBEROWCY, INICJATYWA_CYBEROWCY)
{
}

string CyberOwca::GetNazwa() const
{
	return "CyberOwca";
}

Organizm* CyberOwca::Kopiuj(const Polozenie& polozenie)
{
	return new CyberOwca(this->GetSwiat(), polozenie);
}

bool CyberOwca::TenGatunek(Organizm* organizm)
{
	return dynamic_cast<CyberOwca*>(organizm);
}

CyberOwca::~CyberOwca()
{
}