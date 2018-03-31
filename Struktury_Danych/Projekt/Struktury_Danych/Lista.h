#pragma once
#ifndef Lista_h
#define Lista_h

#include	<iostream>

using namespace std;

class lista {
public:
	int wartosc;
	lista *nastepna;
public:
	lista() {
		this->nastepna = 0;
		this->wartosc = -1;
	}

void dodajEle(int a) {
		if (this->nastepna == 0) {
			lista *ele = new lista;
			ele->wartosc = a;
			this->nastepna = ele;
			return;
		}
		lista *ele = new lista;
		lista *ostatni = this;
		while (ostatni->nastepna) {
			ostatni = ostatni->nastepna;
		}
		ostatni->nastepna = ele;
		ele->wartosc = a;
		return;
	}

void piszEle() {
		lista *ele = this->nastepna;
		while (ele->nastepna) {
			cout << ele->wartosc << endl;
			ele = ele->nastepna;
		}
		cout << ele->wartosc << endl;
		return;
	}
};

int czyJestElement(int a, lista *wsk, int licznik = -1) {
	if (wsk->nastepna == 0)
		if (wsk->wartosc == a)
			return licznik;
		else
			return -1;
	if (wsk->wartosc == a)
		return licznik;
	else
		return czyJestElement(a, wsk->nastepna, ++licznik);
}

#endif // !Lista_h
