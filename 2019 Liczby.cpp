#include <iostream>
#include <fstream>
using namespace std;

bool potega3(int n)
  {
    while(n%3==0)
    {
      n/=3;
    }
    if(n==1)
      return 1;
    else return 0;
  }

int ilePoteg3(int t[], int r)
  {
  int ile=0;
  for(int i=0; i<r; i++)
  {
    ile+=potega3(t[i]);
  }
  return ile;
  }

void odczyt(string plik, int t[], int r)
  {
  ifstream in(plik);
  for(int i=0;i<r;i++)
  in >> t[i];
  in.close();
  }
int SumaSilniLiczby(int a)
  {
    int silnia[10]={1,1,2,6,24,120,720,5040,40320,362880};
    int sum=0;
    while (a>0)
    {
      sum+=silnia[a%10];
      a=a/10;
    }
    return sum;
  }
void podpunkt2(int t[], int r)
  {
    for(int i=0; i<r; i++)
      {
        if (SumaSilniLiczby(t[i])==t[i])
          cout << t[i] << " ";
      }
      cout << endl;
  }

int nwd(int a, int b)
  {
    while(a!=b)
      {
        if(a>b)
          a-=b;
          else b-=a;
      }
    return a;
  }

void podpunkt3(int t[], int r)
  {
    int a, dl, maxdl=0, p, nwdw;
    for(int i=0; i<r-1; i++)
      {
        a=t[i];
        dl=1;
        for(int j=i+1;j<r;j++)
          {
            a=nwd(a,t[j]);
            if (a==1) break;
            else 
               dl++;
            if (dl>maxdl)
            {
              maxdl=dl;
              p=t[i];
              nwdw=a;
            }
          }
      }
      cout << maxdl << " " << p << " " << nwdw;
  }

int main() 
{
  int t[500];
  odczyt("liczby.txt", t,500);
  cout << ilePoteg3(t, 500)<<endl;
  podpunkt2(t, 500);
  podpunkt3(t, 500);
}
