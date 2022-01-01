/**
* @file AvlDugum.hpp
* @description AVL Agacinda kullanilacak dugumun ozelliklerini ve fonksiyonlar tanimlandi.
* @course 2. Ogretim B Grubu
* @assignment Ikinci Odev
* @date 26.12.2021
* @author Zekeriya Altunkaynak zekeriya.altunkaynak@ogr.sakarya.edu.tr
*/
#ifndef AvlDugum_HPP
#define AvlDugum_HPP
#include "OKuyruk.hpp"


class AvlDugum
{
public:
	AvlDugum(OKuyruk* data);
	~AvlDugum();
	AvlDugum* sol;
	AvlDugum* sag;
	OKuyruk* data;
	
};


#endif