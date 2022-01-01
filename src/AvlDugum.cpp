/**
* @file AVLDugum_cpp
* @description avl dugumu icin ilk atamalar yapildi.
* @course 2. Ogretim B Grubu
* @assignment Ikinci Odev
* @date 25.12.2021
* @author Zekeriya Altunkaynak zekeriya.altunkaynak@ogr.sakarya.edu.tr
*/
#include "AVLDugum.hpp"
#include "OKuyruk.hpp"

AvlDugum::AvlDugum(OKuyruk* data)
{
	this->data = data;
	sol = 0;
	sag = 0;
}
AvlDugum::~AvlDugum()
{
	delete this->data;
}
