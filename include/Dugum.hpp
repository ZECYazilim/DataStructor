/**
* @file Dugum_hpp
* @description Kuyruk icin kullanacaK classin head dosyasi ve modeli olusturuldu.
* @course 2. Ogretim B Grubu
* @assignment Ikinci Odev
* @date 23.12.2021
* @author Zekeriya Altunkaynak zekeriya.altunkaynak@ogr.sakarya.edu.tr
*/
#ifndef Dugum_hpp
#define Dugum_hpp

using namespace std;



class Dugum
{
public:
	Dugum(int& data);
	~Dugum();
	int data;
	Dugum* sonraki;
};

#endif
