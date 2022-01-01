/**
* @file OncelikliKuyruk_hpp
* @description okuyruk.hpp verileriyle olusturuldu.
* @course 2. Ogretim B Grubu
* @assignment Ikinci Odev
* @date 26.12.2021
* @author Zekeriya Altunkaynak zekeriya.altunkaynak@ogr.sakarya.edu.tr
*/
#ifndef OKuyruk_HPP
#define OKuyruk_HPP
#include "Dugum.hpp"
#include <iostream>
using namespace std;

class OKuyruk
{
public:
	OKuyruk();
	OKuyruk(int toplamUzunluk);
	~OKuyruk();
	void ekle(int& veri);
	int toplamUzunluk;
	int boyut;
	void orjineUzakligi();
	bool bosMu();
	friend ostream& operator << (ostream& os, OKuyruk& oKuyruk);
private:
	Dugum* ilk;
	Dugum* son;

};

#endif