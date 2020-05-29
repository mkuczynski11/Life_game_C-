#include "Komentator.h"

void Komentator::Oglos_zabojstwo(Organizm* wygrany, Organizm* przegrany)
{
	cout << wygrany->GetNazwa() << " na pozycji " << wygrany->GetPolozenie().x << " " << wygrany->GetPolozenie().y << " zabija " << przegrany->GetNazwa() << " na pozycji " << przegrany->GetPolozenie().x << " " << przegrany->GetPolozenie().y << endl;
}

Komentator::Komentator()
{
}

void Komentator::Oglos_przesuniecie(const Polozenie& polozenie1, const Polozenie& polozenie2, Organizm* organizm)
{
	cout << organizm->GetNazwa() << " przesuwa sie z " << polozenie1.x << " " << polozenie1.y << " do " << polozenie2.x << " " << polozenie2.y << endl;
}

void Komentator::Oglos_zjedzenie(Organizm* zjedzony, Organizm* jedzony)
{
	cout << zjedzony->GetNazwa() << " na pozycji " << zjedzony->GetPolozenie().x << " " << zjedzony->GetPolozenie().y << " zostaje zjedzony  przez " << jedzony->GetNazwa() << " na pozycji " << jedzony->GetPolozenie().x << " " << jedzony->GetPolozenie().y << endl;
}

void Komentator::Oglos_rozmnozenie(Organizm* rodzic, Organizm* dziecko)
{
	cout << rodzic->GetNazwa() << " na pozycji " << rodzic->GetPolozenie().x << " " << rodzic->GetPolozenie().y << " tworzy potomka na pozycji " << dziecko->GetPolozenie().x << " " << dziecko->GetPolozenie().y << endl;
}

void Komentator::Oglos_rozmnozenie(Organizm* rodzic1, Organizm* rodzic2, Organizm* dziecko)
{
	cout << rodzic1->GetNazwa() << " na pozycji " << rodzic1->GetPolozenie().x << " " << rodzic1->GetPolozenie().y << " wraz z " << rodzic2->GetNazwa() << " na pozycji" << rodzic2->GetPolozenie().x << " " << rodzic2->GetPolozenie().y << " tworza potomka na pozycji " << dziecko->GetPolozenie().x << " " << dziecko->GetPolozenie().y << endl;
}

void Komentator::Oglos_odbicie_zolwia(Organizm* wygrany, Organizm* przegrany)
{
	cout << wygrany->GetNazwa() << " na pozycji " << wygrany->GetPolozenie().x << " " << wygrany->GetPolozenie().y << " odpycha " << przegrany->GetNazwa() << " na pozycji " << przegrany->GetPolozenie().x << " " << przegrany->GetPolozenie().y << endl;
}

void Komentator::Oglos_ucieczke(Organizm* wygrany, Organizm* przegrany)
{
	cout << wygrany->GetNazwa() << " na pozycji " << wygrany->GetPolozenie().x << " " << wygrany->GetPolozenie().y << " ucieka przed " << przegrany->GetNazwa() << " na pozycji " << przegrany->GetPolozenie().x << " " << przegrany->GetPolozenie().y << endl;
}

void Komentator::Oglos_zwiekszenie_sily(Organizm* organizm, const int& ile)
{
	cout << organizm->GetNazwa() << " na pozycji " << organizm->GetPolozenie().x << " " << organizm->GetPolozenie().y << " zwieksza swoja sile o " << ile << ", dzieki czemu teraz ma " << organizm->GetSila() << " sily." << endl;
}
