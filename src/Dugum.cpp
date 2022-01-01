/**
* @file Dugum_cpp
* @description kuyrukda kullanmak uzere dugum sinifi tanimlamalari yapildi.
* @course 2. Ogretim B Grubu
* @assignment Ikinci Odev
* @date 25.12.2021
* @author Zekeriya Altunkaynak zekeriya.altunkaynak@ogr.sakarya.edu.tr
*/
#include "Dugum.hpp"
#include <iostream>
#include <cmath>
using namespace std;




Dugum::Dugum(int& veri)
{
	this->data = veri;
	this->sonraki = 0;

}

Dugum::~Dugum()
{

}