#include <iostream>
#include <fstream>

using namespace std;
char t[100][200];

int main()
{
    ifstream in("wykreslanka.txt");
    for (int w = 0; w < 100;w++)
        for (int k = 0; k < 200;k++)
            in >> t[w][k];
    in.close();

    //4.1
    for (int w = 0; w < 100;w++)
        for (int k = 0; k < 200-5;k++)
            {
                if (t[w][k]=='m' && t[w][k+1]=='a' && t[w][k+2]=='t' && t[w][k+3]=='u' && t[w][k+4]=='r' && t[w][k+5]=='a')
                    cout << "Znaleziono w wierszu: " << w << "\n";
            }
    for (int k = 0; k < 200;k++)
        for (int w = 0; w < 100-5;w++)
            {
                if (t[w][k]=='m' && t[w+1][k]=='a' && t[w+2][k]=='t' && t[w+3][k]=='u' && t[w+4][k]=='r' && t[w+5][k]=='a')
                    cout << "Znaleziono w kolumnie: " << k << "\n";
            }
    //4.2
    int global_max = -1;
    int dlugosci[100];
    for (int w = 0; w < 100;w++)
        {
            int local_max = -1;
            int dl = 1;
            for (int k = 1; k < 200;k++)
            {
                if (t[w][k]==t[w][k-1])
                    dl++;
                else
                    dl = 1;
                if (dl>local_max)
                    local_max = dl;
            }
            if (local_max>global_max)
                global_max = local_max;
            dlugosci[w] = local_max;
        }
        cout << "Global max:" << global_max << "\n";
        for (int w = 0; w < 100;w++)
          if(dlugosci[w]==global_max)
              cout << "Wys. w wierszu:" << w << "\n";
    //4.3
        int lit[26]; //[0]-'a', [1]-'b' indeks: int(znak)-int('a')
        for (int wp = 0; wp < 100; wp++)
            for (int kp = 0; kp < 200;kp++)
                {
                    //26 w poziomie
                    if (kp<200-26)
                    {
                        for (int i = 0; i < 26;i++)
                            lit[i] = 0;
                        for (int i = kp; i < kp + 26;i++)
                            lit[int(t[wp][i]) - int('a')]++;
                        bool tak = 1;
                        for (int i = 0; i < 26;i++)
                            if (lit[i]!=1)
                                tak = false;
                        if (tak)
                            cout << "26x1: " << wp<< " " << kp<<endl;
                    }
                    //26 w pionie
                    if (wp<100-26)
                    {
                         for (int i = 0; i < 26;i++)
                            lit[i] = 0;
                        for (int i = wp; i < wp + 26;i++)
                            lit[int(t[i][kp]) - int('a')]++;
                        bool tak = 1;
                        for (int i = 0; i < 26;i++)
                            if (lit[i]!=1)
                                tak = false;
                        if (tak)
                            cout << "1x26: " << wp<< " " << kp<<endl;
                    }
                    //13x2
                    if (kp<200-13 && wp<100-2)
                    {
                        for (int i = 0; i < 26;i++)
                            lit[i] = 0;
                        for (int i = kp; i < kp + 13;i++)
                            for (int j = wp; j < wp + 2;j++)
                                lit[int(t[j][i]) - int('a')]++;
                        bool tak = 1;
                        for (int i = 0; i < 26;i++)
                            if (lit[i]!=1)
                                tak = false;
                        if (tak)
                            cout << "13x2: " << wp<< " " << kp<<endl;
                    }
                    //2x13
                    if (kp<200-2 && wp<100-13)
                    {
                        for (int i = 0; i < 26;i++)
                            lit[i] = 0;
                        for (int i = kp; i < kp + 2;i++)
                            for (int j = wp; j < wp + 13;j++)
                                lit[int(t[j][i]) - int('a')]++;
                        bool tak = 1;
                        for (int i = 0; i < 26;i++)
                            if (lit[i]!=1)
                                tak = false;
                        if (tak)
                            cout << "2x13: " << wp<< " " << kp<<endl;
                    }
                }
}