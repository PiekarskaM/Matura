#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int t[200];

bool dobra3(int a,int b,int c)
{
  return (a != b && b != c && b % a == 0 && c % b == 0);
}
bool dobra5(int a,int b,int c,int d,int e)
{
  int p[5];
  p[0] = a;
  p[1] = b;
  p[2] = c;
  p[3] = d;
  p[4] = e;
  for (int i = 1; i < 5;i++)
  {
    if (p[i]==p[i-1])
      return false;
    if (p[i]%p[i-1]>0)
      return false;
  }
  return true;
}

int main() 
{
  ifstream in("liczby.txt");
  for(int i=0;i<200;i++)
    {
      in >> t[i];
    }
  in.close();
  //zad 4.1
  int ile1 = 0,result=-1;
  for (int i = 0; i < 200;i++)
  {
    int a = t[i];
    int pierwsza, ostatnia = a % 10;
    while(a>0)
    {
      pierwsza = a % 10;
      a = a / 10;
    }
    if (pierwsza == ostatnia)
    {
      if (result==-1)
        result = t[i];
      ile1++;
    }
  }
  cout << "4.1. " << ile1 << " " << result << endl;

  //4.2
  int max_roznych = -1, max_czynnikow = -1;
  int liczba1, liczba2;
  for (int i = 0; i < 200;i++)
  {
    int a = t[i];
    int c = 2;
    int ile_czynnikow = 0,ile_roznych = 0;
    int poprzedni = 0;
    while (a>1)
    {
      if (a%c==0)
      {
        a = a / c;
        ile_czynnikow++;
        if (c!=poprzedni)
         {
           ile_roznych++;
         }
         poprzedni = c;
      }
      else
        c++;
    }
    if (ile_czynnikow>max_czynnikow)
      { max_czynnikow = ile_czynnikow;
        liczba1 = t[i];
      }
    if (ile_roznych>max_roznych)
      {max_roznych = ile_roznych;
        liczba2 = t[i];
      }
  }
  cout << "4.2. " << max_czynnikow << " " << liczba1 << endl;
  cout << max_roznych << " " << liczba2 << endl;
  //4.3
  int result3 = 0, result5 = 0;
  sort(t, t + 200);
  ofstream out3("trojki.txt");
  for (int i = 0; i < 200;i++)
    for (int j = i + 1; j < 200;j++)
      for (int k = j + 1; k < 200;k++)
      {
        int r = dobra3(t[i], t[j], t[k]);
        result3 += r;
        if (r==1)
          out3 << t[i] << " " << t[j] << " " << t[k] << endl;
      }
  out3.close();
  ofstream out5("piatki.txt");
  for (int i = 0; i < 200;i++)
    for (int j = i + 1; j < 200;j++)
      for (int k = j + 1; k < 200;k++)
        for (int l = k + 1; l < 200;l++)
          for (int m = l + 1; m < 200;m++)
          {
            int r = dobra5(t[i], t[j], t[k],t[l],t[m]);
            result5 += r;
            if (r == 1)
              out5 << t[i] << " " << t[j] << " " << t[k] << " " << t[l] << " " << t[m] <<endl;
          }
  out5.close();
  cout << "4.3. " << result3 << " " << result5 << endl;
}