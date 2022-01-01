/**
* @file main.hpp
* @description main.cpp tanimlandi ve islemler baslatildi.
* @course 2. Ogretim B Grubu
* @assignment Ikinci Odev
* @date 26.12.2021
* @author Zekeriya Altunkaynak - g191210035@ogr.sakarya.edu.tr
*/
#include<iostream>
#include <fstream>
#include <sstream>
#include<math.h>
#include "OKuyruk.hpp"
#include "Dugum.hpp"
#include "AvlEkle.hpp"
#include "AVLDugum.hpp"
using namespace std;

void Calistir()
{
    AvlEkle* avlEkle = new AvlEkle();
    int i = 0;
    string satir = "";
    int satirBoyut = 0;
    int toplamUzunluk = 0;
    ifstream dosyaOku("Noktalar.txt");
    if (dosyaOku.is_open()) {

        while (getline(dosyaOku, satir))
        {
            satirBoyut = 0;
            stringstream StreamX(satir);
            stringstream StreamY(satir);
            string gelenVeri;
            while (getline(StreamX, gelenVeri, ' ')) {
                satirBoyut++;
            }
            string* satirlar = new string[satirBoyut];
            int* z = new int[satirBoyut / 3];
            int* y = new int[satirBoyut / 3];
            int* x = new int[satirBoyut / 3];
            int* orjineUzaklik = new int[satirBoyut / 3];
            int* dogruUzakligi = new int[(satirBoyut / 3) - 1];
            while (getline(StreamY, gelenVeri, ' '))
            {
                satirlar[i] = gelenVeri;
                for (int j = 0; j < (satirBoyut / 3); j++)
                {
                    if ((3*(1+j)) - 2 == i + 1)
                    {
                        x[j] = stoi(satirlar[i]);
                    }
                    else if ((3*(1+j)) - 1 == i + 1)
                    {
                        y[j] = stoi(satirlar[i]);
                    }
                    else if ((3*(1+j)) == i + 1)
                    {
                        z[j] = stoi(satirlar[i]);
                    }

                }
                i++;
            }
            for (int h = 0; h < (satirBoyut / 3); h++)
            {
                orjineUzaklik[h] = sqrt(pow(x[h], 2) + pow(y[h], 2) + pow(z[h], 2));
            }

            for (int m = 0; m < (satirBoyut / 3) - 1; m++)
            {
                toplamUzunluk += sqrt(pow(abs(x[m] - x[1+m]), 2) + (pow(abs(y[m] - y[1+m]), 2)) + (pow(abs(z[m] - z[1 + m]), 2)));
                dogruUzakligi[m] = sqrt(pow(abs(x[m] - x[1 + m]), 2) + (pow(abs(y[m] - y[1 + m]), 2)) + (pow(abs(z[m] - z[1 + m]), 2)));
            }
            int geciciZ;
            int geciciX;
            int geciciY;
            int tempData;
            for (int i = 0; i < (satirBoyut / 3) - 1; i++)
            {
                for (int j = 0; j < (satirBoyut / 3) - 1; j++)
                {
                    if (orjineUzaklik[j] > orjineUzaklik[1+j])
                    {
                        tempData = orjineUzaklik[j];
                        orjineUzaklik[j] = orjineUzaklik[1 + j];
                        orjineUzaklik[1 + j] = tempData;

                        geciciZ = z[j];
                        z[j] = z[1 + j];
                        z[1 + j] = geciciZ;

                        geciciY = y[j];
                        y[j] = y[1 + j];
                        y[1 + j] = geciciY;

                        geciciX = x[j];
                        x[j] = x[1+j];
                        x[1+j] = geciciX;


                    }
                }
            }
            OKuyruk* oKuyruk = new OKuyruk(toplamUzunluk);
            for (int i = 0; i < satirBoyut / 3; i++)
            {
                oKuyruk->ekle(z[i]);
                oKuyruk->ekle(y[i]);
                oKuyruk->ekle(x[i]);
            }
            avlEkle->ekle(oKuyruk);
            i = 0;
            toplamUzunluk = 0;
        }
        dosyaOku.close();
    }
    avlEkle->postOrderDolas();
	delete avlEkle;
}
int main()
{
    Calistir();
    return 0;
}

