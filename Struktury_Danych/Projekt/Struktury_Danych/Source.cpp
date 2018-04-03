#include <iostream>
#include <ctime>
#include <random>
#include "QuickSort.h"
#include <chrono>
#include <fstream>
#include "ArrayCreating.h"
#include "Lista.h"
#include "BST.h"
#include "Searching.h"
#include <Windows.h>



int main()
{
/*	tree drzewo;
	int tab[] = { 8,4,2,1,3,6,5,7,12,10,9,11,14,13,15 };
	int tab2[] = { 6,11,4,7,5,8,10,12,2,3,9,1,13,14,15 };
	for (int i = 0; i<15; i++)
		drzewo.dodajElement(tab[i]);
	std::cout << drzewo.zbadajWysokosc() << std::endl;
	std::cout << drzewo.czyJest(12) << std::endl;
*/



/*
	lista tab;
	int a = 10;
	for (int i = 0; i<a; i++) {
		tab.dodajEle(i);
	}
	//tab.piszEle();
	std::cout << czyJestElement(2, &tab) << std::endl;
*/

	std::ofstream CB,SSB,SBB,CL,SL;
	CB.open("czas_tworzenia_kopii_i_sprtowania.txt");
	SSB.open("czas_przeszukiwania_wycieczajacego.txt");
	SBB.open("czas_przeszukiwania_binarnego.txt");
	CL.open("czas_tworzenia_listy_L.txt");
	SL.open("czas_przeszukiwania_listy_L.txt");

	for (int i = 10000; i <= 200000; i+=10000)
	{
		int* A;
		int* B;
		A = new int[i];
		B = new int[i];
		lista L;
		makeListWithUniqueElements(A, i);
		auto start = std::chrono::high_resolution_clock::now();
		CopyArray(A, B, i);
		QuickSortMid(B, i);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, milli> time = end - start;
		CB<< i << " " << time.count() << " miloseconds" << std::endl;
		std::cout << i << " CBdone" << std::endl;
		//Przeszukiwanie wyciêczaj¹ce
		auto SSB_start = std::chrono::high_resolution_clock::now();
		for (int j =0; j < i; j++)
		{
			BruteForce(B, A[j], i);
		}
		auto SSB_end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, milli> SSB_time = SSB_end - SSB_start;
		SSB<< i << " " << SSB_time.count() << " miloseconds" << std::endl;
		std::cout << i << " SSBdone" << std::endl;
		//przeszukiwanie binarne
		auto SBB_start = std::chrono::high_resolution_clock::now();
		for (int j = 0; j < i; j++)
		{
			BinarySearch(B, A[j], 0, i);
		}
		auto SBB_end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, milli> SBB_time = SBB_end - SBB_start;
		SBB << i << " " << SBB_time.count() <<" miloseconds"<< std::endl;
		std::cout << i << " SBBdone" << std::endl;
		//tworzenie listy
		auto CLstart = std::chrono::high_resolution_clock::now();
		for (int j = 0; j < i; j++)
		{
			L.dodajEle(A[j]);
		}
		auto CLend = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, milli> CLtime = CLend - CLstart;
		CL << i << " " << CLtime.count() << " miliseconds" << std::endl;
		std::cout << i << " CLdone" << std::endl;
		//przeszukiwanie listy
		auto SLstart = std::chrono::high_resolution_clock::now();
		for (int j = 0; j < i; j++)
		{
			czyJestElement(A[j], &L);
		}
		auto SLend = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, milli> SLtime = SLend - SLstart;
		SL << i << " " << SLtime.count() << " miliseconds" << std::endl;
		std::cout << i << " SLdone" << std::endl;
		//budowa TR





	}
	system("pause");
}