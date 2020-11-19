#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int t[200][320];

int podpunkt2()
{
  int ile=0;
  for(int i=0;i<200;i++)
  {
    int l=0,p=319;//od lewej i od prawej
    while(l<p)
    {
      if (t[i][l]!=t[i][p])
      {
        ile++;//popsuta symetria w tej linii
        break;
      }
      l++;p--;
    }
  }
  return ile;
}

int kontrast(int w,int k)//sprawdza czy piksel na przecieciu wiersza w i kolumny k jest kontrastujący z otoczeniem
{
 //ten ktory ma kontrastowac na boki to t[w][k]
 if (w>0 && abs(t[w-1][k]-t[w][k])>128) // jesli da sie to sprawdze do gory
  return 1;
 if (w<199 && abs(t[w+1][k]-t[w][k])>128) //jesli da sie to sprawdze na dol
  return 1;
 if (k>0 && abs(t[w][k-1]-t[w][k])>128) //jesli da sie to sprawdze w lewo
  return 1;
 if (k<319 && abs(t[w][k+1]-t[w][k])>128) // jesli da sie to sprawdze w prawo od mojego
  return 1;
return 0; 
}

int podpunkt3()
{
  int res=0;
  for(int i=0;i<200;i++)
    for(int j=0;j<320;j++)
      res=res+kontrast(i,j);//zwracana jedynka lub zero dodana jest do ogolnej ilosci kontrastujacych
  return res;
}
int main()
{
    ifstream odczyt("dane.txt");
    for(int i=0; i<200; i++)
        for(int j=0; j<320; j++)
            odczyt >> t[i][j];

    int najw=t[0][0], najm=t[0][0];

    for(int i=0; i<200; i++)
        for(int j=0; j<320; j++)
        {
            if(t[i][j]>najw)
                najw=t[i][j];
            if(t[i][j]<najm)
                najm=t[i][j];
        }
    cout << "4.1. " << najw << " " << najm << endl;
    cout << "4.2. " << "Ilosc:" << podpunkt2() << endl;
    cout << "4.3. " << "Ilosc kontrastów:" << podpunkt3() << endl;
 return 0;
}

