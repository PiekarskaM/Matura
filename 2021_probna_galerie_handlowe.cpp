#include <bits/stdc++.h>
using namespace std;

struct galeria{
  string kod;
  string miasto;
  int pow[70][2];
  int p[70];
};
galeria galerie[50];

struct kraj{
    string kod;
    int ile;
  };
kraj kraje[50];
int ile_krajow=0;

void odczyt(){
ifstream in("galerie.txt");
for (int i=0;i<50;i++)
{
  in >> galerie[i].kod;
  in >> galerie[i].miasto;
  for(int j=0;j<70;j++)
  {
    in >> galerie[i].pow[j][0] >> galerie[i].pow[j][1];
    galerie[i].p[j]=galerie[i].pow[j][0]*galerie[i].pow[j][1];
  }
}
in.close();
}
bool znajdz_kraj(string k)
{
  for(int i=0;i<ile_krajow;i++)
    if (kraje[i].kod==k) return true;
  return false;
}
void podpunkt_1()
{
  ofstream out("wynik4_1.txt");
  out << "4.1"<<endl;
  for(int i=0;i<50;i++)
    {
      if (znajdz_kraj(galerie[i].kod)==false)
       {
         kraje[ile_krajow].kod=galerie[i].kod;
         kraje[ile_krajow].ile=0;
         for(int j=0;j<50;j++)
          if (kraje[ile_krajow].kod==galerie[j].kod)
            kraje[ile_krajow].ile++;
         ile_krajow++;
       }
    }
  for(int i=0;i<ile_krajow;i++)
      out << kraje[i].kod << " " << kraje[i].ile << endl;
  out.close();  
}
void podpunkt_2()
{
  ofstream out("wynik4_2a.txt");
  out << "4.2a" << endl;
  int maximum=0,minimum=9999999,ktory_najm,ktory_najw;
  for(int i=0;i<50;i++)
  {
    out << galerie[i].miasto;
    int j=0,pow=0;
    while (j<70 && galerie[i].pow[j][0]!=0 && galerie[i].pow[j][1]!=0)
    {
      pow+=galerie[i].pow[j][0]*galerie[i].pow[j][1];
      j++;
    }
    out << " " << j << " " << pow << endl; 
    if (pow<minimum)
     {
       minimum=pow;
       ktory_najm=i;
     }
    if (pow>maximum)
     {
       maximum=pow;
       ktory_najw=i;
     }
  } 
out.close();
out.open("wynik4_2b.txt");
out << "4.2b" << endl;
out << galerie[ktory_najm].miasto << " "<< minimum << endl;
out << galerie[ktory_najw].miasto << " "<< maximum << endl;
out.close();
}

void podpunkt_3()
{
  ofstream out("wynik4_3.txt");
  out << "4.3" << endl;
  int minimum=100,maximum=0,ktory_najm,ktory_najw;
  for(int i=0;i<50;i++)
   {
     //ile unikatowych powierzchni jest w galerii nr i?
     sort(galerie[i].p,galerie[i].p+70);
     int ile=0;
     for(int j=1;j<70;j++)
      {
        if (galerie[i].p[j]==0) continue;
        if (galerie[i].p[j]!=galerie[i].p[j-1]) 
          ile++;
      }
     //cout << galerie[i].miasto<<" " << ile << endl; 
     if (ile>maximum)
      {
        maximum=ile;
        ktory_najw=i;
      }
     if (ile<minimum)
      {
        minimum=ile;
        ktory_najm=i;
      }
   }
   out << galerie[ktory_najm].miasto << " " << minimum << endl;
   out << galerie[ktory_najw].miasto << " " << maximum << endl;
   out.close();
}
int main() {
odczyt();
podpunkt_1();
podpunkt_2();
podpunkt_3();
}
