#include <iostream>
using namespace std;

char tablica[3][3] = {
		{'-', '-', '-'},
		{'-', '-', '-'},
		{'-', '-', '-'}
	};
	
string imie_aktualnego_gracza = "";
char znak_aktualnego_gracza = 'X';

void rysuj();
int pobierz_wybrana_pozycje();
char pobierz_znak_na_pozycji(int wybrana_pozycja);
void przypisz_znak_na_wybrana_pozycje(int wybrana_pozycja);
bool sprawdz_czy_koniec_gry(int licznik_remisu);
bool sprawdz_zwyciestwo();
bool sprawdz_zwyciestwo_kolko();
bool sprawdz_zwyciestwo_krzyzyk();
void przelacz_gracza(string imie_pierwszego_gracza, string imie_drugiego_gracza);

int main()
{
	int licznik_remisu = 0, wybrana_pozycja = 0;
	bool czy_koniec_gry = false;
	string imie_pierwszego_gracza, imie_drugiego_gracza;

	cout << "Kolko i krzyzyk\n\n";
	
	cout << "Podaj imie 1 gracza" << endl;
	cin >> imie_pierwszego_gracza;
	cout << "Podaj imie 2 gracza" << endl;
	cin >> imie_drugiego_gracza;

	rysuj();
	
	cout << "\n Wpisz imie gracza, ktory zaczyna: " << endl;
	cin >> imie_aktualnego_gracza;
	
	do
	{
		wybrana_pozycja = pobierz_wybrana_pozycje();
		
		przypisz_znak_na_wybrana_pozycje(wybrana_pozycja);
		licznik_remisu++;
		
		rysuj();
		
		czy_koniec_gry = sprawdz_czy_koniec_gry(licznik_remisu);
		
		przelacz_gracza(imie_pierwszego_gracza, imie_drugiego_gracza);
	}
	while (!czy_koniec_gry);
	
	cin.ignore();
    return 0;
}

void rysuj()
{
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << "|" << tablica[i][j];
		}
		cout << "|" << endl;
	}
	cout << endl;
}

int pobierz_wybrana_pozycje()
{	
	int wybrana_pozycja = 0;
	bool czy_pozycja_jest_pusta = true;
	do 
	{
		cout << endl << imie_aktualnego_gracza << ", podaj pole do zaznaczenia: \n";
		cin >> wybrana_pozycja;
		
		if (pobierz_znak_na_pozycji(wybrana_pozycja) != '-') {
			czy_pozycja_jest_pusta = false;
		}
	} while(!czy_pozycja_jest_pusta);
	
	return wybrana_pozycja;
}

char pobierz_znak_na_pozycji(int wybrana_pozycja)
{
	int licznik = 0;
	for (int i = 0; i <= 2; i++) 
	{
		for (int j = 0; j <= 2; j++) 
		{
			licznik++;
			if (licznik == wybrana_pozycja)
			{
				return tablica[i][j];
			}
		}
	}
}

void przypisz_znak_na_wybrana_pozycje(int wybrana_pozycja) 
{
	int licznik = 0;
	for (int i = 0; i <= 2; i++) 
	{
		for (int j = 0; j <= 2; j++) 
		{
			licznik++;
			if (licznik == wybrana_pozycja)
			{
				tablica[i][j] = znak_aktualnego_gracza;
			}
		}
	}
}

bool sprawdz_czy_koniec_gry(int licznik_remisu)
{
	if (sprawdz_zwyciestwo())
	{
		cout << "Gratulacje, " << imie_aktualnego_gracza << " zwyciezyl!" << endl;
		return true;
	}
	else if(licznik_remisu == 9)
	{
		cout << "\nMamy remis!" << endl;
		return true;
	}
	else
	{
		return false;
	}
}

bool sprawdz_zwyciestwo()
{
	if (znak_aktualnego_gracza == 'X') 
	{
		return sprawdz_zwyciestwo_krzyzyk();
	}
	else
	{
		return sprawdz_zwyciestwo_kolko();
	}
}

bool sprawdz_zwyciestwo_kolko()
{
	if ((tablica[0][0] == 'O' && tablica[0][1] == 'O' && tablica[0][2] == 'O') ||
		(tablica[1][0] == 'O' && tablica[1][1] == 'O' && tablica[1][2] == 'O') ||
		(tablica[2][0] == 'O' && tablica[2][1] == 'O' && tablica[2][2] == 'O') ||
		(tablica[0][0] == 'O' && tablica[1][0] == 'O' && tablica[2][0] == 'O') ||
		(tablica[0][1] == 'O' && tablica[1][1] == 'O' && tablica[2][1] == 'O') ||
		(tablica[0][2] == 'O' && tablica[1][2] == 'O' && tablica[2][2] == 'O') ||
		(tablica[0][0] == 'O' && tablica[1][1] == 'O' && tablica[2][2] == 'O') ||
		(tablica[2][0] == 'O' && tablica[1][1] == 'O' && tablica[0][2] == 'O'))
		{
			return true;
		}
		else
		{
			return false;
		}
}

bool sprawdz_zwyciestwo_krzyzyk()
{
	if ((tablica[0][0] == 'X' && tablica[0][1] == 'X' && tablica[0][2] == 'X') ||
		(tablica[1][0] == 'X' && tablica[1][1] == 'X' && tablica[1][2] == 'X') ||
		(tablica[2][0] == 'X' && tablica[2][1] == 'X' && tablica[2][2] == 'X') ||
		(tablica[0][0] == 'X' && tablica[1][0] == 'X' && tablica[2][0] == 'X') ||
		(tablica[0][1] == 'X' && tablica[1][1] == 'X' && tablica[2][1] == 'X') ||
		(tablica[0][2] == 'X' && tablica[1][2] == 'X' && tablica[2][2] == 'X') ||
		(tablica[0][0] == 'X' && tablica[1][1] == 'X' && tablica[2][2] == 'X') ||
		(tablica[2][0] == 'X' && tablica[1][1] == 'X' && tablica[0][2] == 'X'))
		{
			return true;
		}
		else
		{
			return false;
		}
}


void przelacz_gracza(string imie_pierwszego_gracza, string imie_drugiego_gracza)
{
	if (znak_aktualnego_gracza == 'X')
	{
		znak_aktualnego_gracza = 'O';
	}
	else
	{
		znak_aktualnego_gracza = 'X';
	}
	
	if (imie_aktualnego_gracza == imie_pierwszego_gracza)
	{
		imie_aktualnego_gracza = imie_drugiego_gracza;
	}
	else
	{
		imie_aktualnego_gracza = imie_pierwszego_gracza;
	}
}
