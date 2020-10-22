#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
string podpunkt1(string slowa[],int r)
{
string res="";
for(int i=39;i<r;i+=40)
  res+=slowa[i][9];
return res;
}
void odczyt(string plik,string slowa[],int r)
{
  ifstream in(plik);
  for(int i=0;i<r;i++)
    in >> slowa[i];
  in.close();
}

string sortuj(string s)
{ sort(s.begin(),s.end());
  return s; 
}
void podpunkt3(string slowa[],int r)
{
  string ss;
  cout << "4.3." <<endl;
  for(int i=0;i<r;i++)
    {
      ss=sortuj(slowa[i]);
      if (ss[ss.size()-1]-ss[0]<=10)
        cout << slowa[i] <<endl;
    }
}
int IleRZ(string s)
{
  int zlicz[26],kod=(int)'A',res=0;
 /*
 'A'..'Z' -> []
  0    25
 */
 for(int i=0;i<26;i++) zlicz[i]=0;
 for(int i=0;i<s.size();i++)
  {
    if (zlicz[((int)s[i]-kod)]==0)
    {
      zlicz[((int)s[i]-kod)]=1;
      res++;
    }
  }
  return res;
}

void podpunkt2(string slowa[],int r)
{
  int a,max=0;
  string wyp;
 for(int i=0;i<r;i++)
 {
   a=IleRZ(slowa[i]);
   if (a>max)
    {
      max=a;
      wyp=slowa[i];
    }
 }
 cout << "4.2."<<wyp <<" " << max << endl;
}


int main() 
{
  string slowa[1000]; 
  odczyt("sygnaly.txt",slowa,1000);
  cout << "4.1."<<podpunkt1(slowa,1000) << endl;
  podpunkt2(slowa,1000);
  podpunkt3(slowa,1000);
  return 0;
}