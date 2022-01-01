/**
* @file AVLAgaci_cpp
* @description avl agacina ekleme islemleri goruldu.
* @course 2. Ogretim B Grubu
* @assignment Ikinci Odev
* @date 25.12.2021
* @author Zekeriya Altunkaynak zekeriya.altunkaynak@ogr.sakarya.edu.tr
*/
#include "AvlEkle.hpp"
#include <math.h>
#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;

AvlEkle::AvlEkle()
{
	kok = 0;
}

AvlEkle::~AvlEkle()
{
	Sil(kok);
}
void AvlEkle::Sil(AvlDugum* aktifDugum)
{
	if (aktifDugum)
	{
		Sil(aktifDugum->sol);
		Sil(aktifDugum->sag);
		delete aktifDugum;
	}
}
int AvlEkle::yukseklik()
{
	return yukseklik(kok);
}

AvlDugum* AvlEkle::solaDon(AvlDugum* ebeveyn)
{
	AvlDugum* sagcocuk = ebeveyn->sag;
	ebeveyn->sag = sagcocuk->sol;
	sagcocuk->sol = ebeveyn;
	return sagcocuk;
}

void AvlEkle::postOrderDolas()
{
	postOrderDolas(kok);
}

void AvlEkle::ekle(OKuyruk* veri) {
	kok = ekle(veri, kok);
}

AvlDugum* AvlEkle::sagaDon(AvlDugum* ebeveyn)
{
	AvlDugum* solcocuk = ebeveyn->sol;
	ebeveyn->sol = solcocuk->sag;
	solcocuk->sag = ebeveyn;
	return solcocuk;
}

void AvlEkle::postOrderDolas(AvlDugum* aktif)
{
	if (aktif)
	{
		postOrderDolas(aktif->sol);
		postOrderDolas(aktif->sag);
		aktif->data->orjineUzakligi();
	}
}

ostream& operator<<(ostream& os, AvlEkle& AvlEkle)
{
	AvlEkle.postOrderDolas();
	return os;
}

int AvlEkle::yukseklik(AvlDugum* aktifAVLDugum)
{
	if (aktifAVLDugum)
	{
		return 1 + max(yukseklik(aktifAVLDugum->sol), yukseklik(aktifAVLDugum->sag));
	}
	return -1;
}


AvlDugum* AvlEkle::ekle(OKuyruk* veri, AvlDugum* aktifAVLDugum)
{
	if (aktifAVLDugum == 0)
	{
		return new AvlDugum(veri);
	}

	else if (aktifAVLDugum->data->toplamUzunluk > veri->toplamUzunluk)
	{
		aktifAVLDugum->sol = ekle(veri, aktifAVLDugum->sol);

		if (yukseklik(aktifAVLDugum->sol) - yukseklik(aktifAVLDugum->sag) > 1)
		{
			if (veri->toplamUzunluk > aktifAVLDugum->sol->data->toplamUzunluk)
			{
				aktifAVLDugum->sol = solaDon(aktifAVLDugum->sol);
				aktifAVLDugum = sagaDon(aktifAVLDugum);
			}
			else
			{
				aktifAVLDugum = sagaDon(aktifAVLDugum);
			}
		}
	}
	else if (aktifAVLDugum->data->toplamUzunluk < veri->toplamUzunluk)
	{
		aktifAVLDugum->sag = ekle(veri, aktifAVLDugum->sag);
		if (yukseklik(aktifAVLDugum->sag) - yukseklik(aktifAVLDugum->sol) > 1)
		{
			if (veri->toplamUzunluk < aktifAVLDugum->sag->data->toplamUzunluk)
			{
				aktifAVLDugum->sag = sagaDon(aktifAVLDugum->sag);
				aktifAVLDugum = solaDon(aktifAVLDugum);
			}
			else
			{
				aktifAVLDugum = solaDon(aktifAVLDugum);
			}
		}
	}
	return aktifAVLDugum;
}

