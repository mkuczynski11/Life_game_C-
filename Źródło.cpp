#include "Helper.h"
#include "Swiat.h"

int main()
{
	srand(time(NULL));
	int n, m;
	cout << "Podaj wysokosc planszy:";
	cin >> n;
	cout << "Podaj szerokosc planszy:";
	cin >> m;
	Swiat* swiat = new Swiat(n, m);
	char c;
	ifstream plik;
	string opcje = "Nacisnij dowolny klawisz aby przejsc dalej, Q aby wyjsc, Z aby zapisac gre, L aby zaladowac gre.";
	cout << opcje << endl;
	while (cin >> c)
	{
		switch (c)
		{
		case 'q': return 0;
		case 'Q': return 0;
		case 'Z':
			swiat->ZapiszGre();
			break;
		case 'z':
			swiat->ZapiszGre();
			break;
		case 'L':
			delete swiat;
			plik.open("zapis.txt");
			swiat = new Swiat(plik);
			plik.close();
			break;
		case 'l':
			delete swiat;
			plik.open("zapis.txt");
			swiat = new Swiat(plik);
			plik.close();
			break;
		default:
			swiat->wykonajTure();
			swiat->rysujSwiat();
		}
		cout << opcje << endl;
	}
}