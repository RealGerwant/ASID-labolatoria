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
	bool czyJestElement(int a) {
		lista *l = this->nastepna;
		int licznik = 0;
		while (l->nastepna) {
			if (l->wartosc == a)
				return true;
			l = l->nastepna;
		}
		if (l->wartosc == a)
			return true;
		return false;
	}
};

#endif // !Lista_h
