/**
* @file OncelikliKuyruk_cpp
* @description onceliklu kuyruk sinifi olusturulup islemleri yapildi.
* @course 2. Ogretim B Grubu
* @assignment Ikinci Odev
* @date 25.12.2021
* @author Zekeriya Altunkaynak zekeriya.altunkaynak@ogr.sakarya.edu.tr
*/
#include "Dugum.hpp"
#include "OKuyruk.hpp"
#include <iomanip>
#include<iostream>
#include<math.h>

using namespace std;




OKuyruk::OKuyruk(int toplam)
{
	ilk = son = 0;
	this->toplamUzunluk = toplam;
}

OKuyruk::OKuyruk() {}
OKuyruk::~OKuyruk()
{
	while (ilk != 0)
	{
		Dugum* gecici = ilk;
		ilk = ilk->sonraki;
		delete gecici;
	}
}

bool OKuyruk::bosMu()
{
	if (ilk == 0)
		return true;
	return false;
}

void OKuyruk::ekle(int& data)
{
	if (ilk == 0)
	{
		ilk = new Dugum(data);
		son = ilk;
	}
	else
	{
		Dugum* yeni = new Dugum(data);
		son->sonraki = yeni;
		son = yeni;
	}
	boyut++;
}

ostream& operator<<(ostream& os, OKuyruk& oKuyruk)
{
	os << endl;
	return os;
}


void OKuyruk::orjineUzakligi()
{
	int sayac = 0;
	int* veriler = new int[boyut];
	
	for (Dugum* gecici = ilk;gecici != 0; gecici = gecici->sonraki)
	{
		veriler[sayac] = gecici->data;
		sayac++;
	}

	for (int i = 0;i < boyut / 3;i++)
	{
		int xKoordinati = veriler[i * 3];
		int yKoordinati = veriler[i * 3 + 1];
		int zKoordinati = veriler[i * 3 + 2];
		int orijinUzakligi = sqrt(pow(xKoordinati, 2)+ pow(yKoordinati, 2) + pow(zKoordinati, 2));

		if (orijinUzakligi != 0)
		{
			cout << orijinUzakligi << " ";
		}
	}
	cout << endl;
}