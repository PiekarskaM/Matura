#include <bits/stdc++.h>
using namespace std;

bool palindrom(string s)
{
 string kopia_s=s;
 reverse(s.begin(),s.end());

 return s==kopia_s;
}
//tablica vectorow na wszystkie rodziny
vector <string> v[201];

int main()
{
int odp1=0;
string s;
for(int i=0;i<2000;i++)
{
    cin >> s;
    bool czy_palindrom = palindrom(s);

    if (czy_palindrom==false)
        continue;

    odp1+=1;
    int dlugosc = s.size();
    v[dlugosc].push_back(s);
}
cout << "Ilosc palindromow:"<< odp1 << endl;

int odp2=0;
for(int i=0;i<=200;i++)
{
    odp2+=(v[i].size()>0);
}
cout << "Ilosc niepustych rodzin:" << odp2 << endl;

ofstream out("rodziny.txt");
for(int i=0;i<=200;i++)
{
    if (v[i].size()>0)
    {
        sort(v[i].begin(),v[i].end());
        for(int j=0;j<v[i].size();j++)
            out << v[i][j]<<" ";
        out << endl;

    }
}
}
