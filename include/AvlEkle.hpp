/**
* @file AvlEkle.hpp
* @description AVL  ozelliklerini ve kullanilacak fonksiyonlar tanimlandi.
* @course 2. Ogretim B Grubu
* @assignment Ikinci Odev
* @date 25.12.2021
* @author Zekeriya Altunkaynak zekeriya.altunkaynak@ogr.sakarya.edu.tr
*/
#ifndef AVLEkle_HPP
#define AVLEkle_HPP
#include "AVLDugum.hpp"
#include <iostream>

using namespace std;


class AvlEkle
{
public:
	AvlEkle();
	~AvlEkle();
	void ekle(OKuyruk* veri);
	void postOrderDolas();	
	friend ostream& operator<<(ostream& os, AvlEkle& AvlEkle);
	int yukseklik();
private:
	AvlDugum* solaDon(AvlDugum* AVLDugum);
	AvlDugum* sagaDon(AvlDugum* AVLDugum);
	void Sil(AvlDugum* aktifDugum);
	AvlDugum* ekle(OKuyruk* veri, AvlDugum* aktifAVLDugum);
	AvlDugum* kok;
	void postOrderDolas(AvlDugum* indeks);
	int yukseklik(AvlDugum* aktifAVLDugum);
};

#endif