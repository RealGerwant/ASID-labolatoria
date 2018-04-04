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

#define S 11
 
int main()
{
	int* A;
	int* B;
	B = new int[S];
	A = new int[S];
	makeListWithUniqueElements(A, S);
	QuickSortMid(A, S);
	for (int i = 0; i < S; i++)
	{
		std::cout << A[i] << " ";
	}
	std::cout << std::endl;
	BinaryPartition(A, B, 0, S - 1,0);
	for (int i = 0; i < S; i++)
	{
		std::cout << B[i] << " ";
	}
	std::cout << std::endl;

/*	std::ofstream CB,SSB,SBB,CL,SL,CTR,HTR,STR;
	CB.open("czas_tworzenia_kopii_i_sprtowania.txt");
	SSB.open("czas_przeszukiwania_wycieczajacego.txt");
	SBB.open("czas_przeszukiwania_binarnego.txt");
	CL.open("czas_tworzenia_listy_L.txt");
	SL.open("czas_przeszukiwania_listy_L.txt");
	CTR.open("czas_tworzenia_drzewa_TR.txt");
	HTR.open("wysokoœæ_drzewa_TR.txt");
	STR.open("czas_przeszukiwania_drzewa_TR.txt");

	for (int i = 10000; i <= 200000; i+=10000)
	{
		int* A;
		int* B;
		A = new int[i];
		B = new int[i];
		lista L;
		tree TR;
		makeListWithUniqueElements(A, i);
		auto start = std::chrono::high_resolution_clock::now();
		CopyArray(A, B, i);
		QuickSortMid(B, i);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, milli> time = end - start;
		CB<< i << " " << time.count() << " miloseconds" << std::endl;
		std::cout << i << " CB done" << std::endl;
		//Przeszukiwanie wyciêczaj¹ce
		auto SSB_start = std::chrono::high_resolution_clock::now();
		for (int j =0; j < i; j++)
		{
			BruteForce(B, A[j], i);
		}
		auto SSB_end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, milli> SSB_time = SSB_end - SSB_start;
		SSB<< i << " " << SSB_time.count() << " miloseconds" << std::endl;
		std::cout << i << " SSB done" << std::endl;
		//przeszukiwanie binarne
		auto SBB_start = std::chrono::high_resolution_clock::now();
		for (int j = 0; j < i; j++)
		{
			BinarySearch(B, A[j], 0, i);
		}
		auto SBB_end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, milli> SBB_time = SBB_end - SBB_start;
		SBB << i << " " << SBB_time.count() <<" miloseconds"<< std::endl;
		std::cout << i << " SBB done" << std::endl;
		//tworzenie listy
		auto CLstart = std::chrono::high_resolution_clock::now();
		for (int j = 0; j < i; j++)
		{
			L.dodajEle(A[j]);
		}
		auto CLend = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, milli> CLtime = CLend - CLstart;
		CL << i << " " << CLtime.count() << " miliseconds" << std::endl;
		std::cout << i << " CL done" << std::endl;
		//przeszukiwanie listy
		auto SLstart = std::chrono::high_resolution_clock::now();
		for (int j = 0; j < i; j++)
		{
			czyJestElement(A[j], &L);
		}
		auto SLend = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, milli> SLtime = SLend - SLstart;
		SL << i << " " << SLtime.count() << " miliseconds" << std::endl;
		std::cout << i << " SL done" << std::endl;
		//budowa TR
		auto CTRstart = std::chrono::high_resolution_clock::now();
		for (int j = 0; j < i; j++)
		{
			TR.dodajElement(A[j]);
		}
		auto CTRend = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, milli> CTRtime = CTRend - CTRstart;
		CTR << i << " " << CTRtime.count() << " miliseconds" << std::endl;
		std::cout << i << " CTR done" << std::endl;
		//wysokoœæ TR
		HTR << i << " " << TR.zbadajWysokosc() << " wysokoœæ" << std::endl;
		std::cout << i << " HTR done" << std::endl;
		//przeszukiwanie TR
		auto STRstart = std::chrono::high_resolution_clock::now();
		for (int j = 0; j < i; j++)
		{
			TR.czyJest(A[j]);
		}
		auto STRend = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double, milli> STRtime = STRend - STRstart;
		STR << i << " " << STRtime.count() << " miliseconds" << std::endl;
		std::cout << i << " STR done" << endl;
		//tworzenie TB
		int* C;
		C = new int[i];




		std::cout << "##################################" << std::endl;
	}*/
	system("pause");
}