#include <bits/stdc++.h>

using namespace std;
int gatunki[501];

string magia(string s)
{
    string res = "";
    size_t p = 0, q;
    while (1)
    {
        string pom = "";
        p = s.find("AA", p, 2);
        if (p != string::npos)
        {
            q = s.find("BB", p + 1, 2);
            if (q != string::npos)
                for (int i = p; i <= q + 1; i++)
                    pom += s[i];
            else
                break;
        }
        else
            break;
        res += pom;
        p = q + 1;
    }
    return res;
}
int IloscGenow(string s)
{
    int res = 0;
    size_t p = 0, q;
    do
    {
        p = s.find("AA", p, 2);
        if (p != string::npos)
        {
            q = s.find("BB", p + 1, 2);
            res++;
            p = q + 1;
        }
    } while (p != string::npos);
    return res;
}
int DlugoscGenow(string s)
{
    int dl, maxdl = -1;
    size_t p = 0, q;
    do
    {
        p = s.find("AA", p, 2);
        if (p != string::npos)
        {
            q = s.find("BB", p + 1, 2);
            dl = q - p + 2;
            maxdl = max(dl, maxdl);
            p = q + 1;
        }
    } while (p != string::npos);
    return maxdl;
}
string w[1000];
int licznik[501];
int main()
{
    ifstream dane("dane_geny.txt");
    int odp1 = 0, odp2 = 0, ig, maxig = -1, dg, maxdg = -1, maxile = -1, odp4o = 0, odp4so = 0;
    for (int i = 0; i < 1000; i++)
    {
        string s;
        dane >> s;
        //69.1
        licznik[s.size()]++;
        //69.2
        w[i] = magia(s);
        size_t poz = w[i].find("BCDDC");
        if (poz != string::npos)
            odp2++;
        //69.3
        ig = IloscGenow(w[i]);
        maxig = max(maxig, ig);
        dg = DlugoscGenow(w[i]);
        maxdg = max(maxdg, dg);
        //69.4
        string s1 = s, s2 = s;
        reverse(s2.begin(), s2.end());
        if (s1 == s2)
            odp4so++; //silnie odporny = palindrom
        if (magia(s1) == magia(s2))
            odp4o++;
    }
    //ad.69.1
    for (int i = 1; i < 500; i++)
    {
        if (licznik[i] > 0)
            odp1++;
        maxile = max(licznik[i], maxile);
    }
    cout << "Liczba gatunkow: " << odp1 << ", max osobnikow: " << maxile << endl;
    cout << "Genow z mutacja BCCD: " << odp2 << endl;
    cout << "Najwieksza liczba genow u jednego osobnika:" << maxig << endl;
    cout << "Najdluzszy gen:" << maxdg << endl;
    cout << "Silnie odpornych:" << odp4so << endl;
    cout << "Odpornych:" << odp4o << endl;
    return 0;
}
