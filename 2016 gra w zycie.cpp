#include<bits/stdc++.h>
using namespace std;
int komorki[15][25][105];
int check(int i, int j, int z){
    int a=0;
    int x=i-1;
    int y=j-1;
    int l=i+1;
    int m=j+1;
    if(x==0) x=12;
    if(y==0) y=20;
    if(l==13) l=1;
    if(m==21) m=1;
    a+=komorki[x][y][z-1];
    a+=komorki[x][m][z-1];
    a+=komorki[l][y][z-1];
    a+=komorki[l][m][z-1];
    a+=komorki[i][y][z-1];
    a+=komorki[i][m][z-1];
    a+=komorki[x][j][z-1];
    a+=komorki[l][j][z-1];
    return a;

}
int wynik=0;
int sumka=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fstream plik;
    plik.open("gra.txt");
    for(int i=1; i<=12; i++){
        for(int j=1; j<=20; j++){
            char a;
            plik>>a;
            if(a=='X') komorki[i][j][1]=1;
//            cout<<komorki[i][j][1];
        }
//        cout<<endl;
    }
    plik.close();
    int suma=0;
    int klik=0;
    for(int z=2; z<=100; z++){
        sumka=0;
        suma=0;
        for(int i=1; i<=12; i++){
            for(int j=1; j<=20; j++){
                int a=check(i,j,z);
                if(komorki[i][j][z-1]==0 && a==3) komorki[i][j][z]=1;
                else if(komorki[i][j][z-1]==1 && (a==2 || a==3) ) komorki[i][j][z]=1;
                if(komorki[i][j][z]==komorki[i][j][z-1]) sumka++;
                suma+=komorki[i][j][z];
            }
        }
        if(sumka==12*20 && klik==0){
            klik=1;
            cout<<"wynik trzecie\n";
            cout<<z<<" "<<suma<<"\n";

        }

    }
    cout<<"pierwszy "<<check(2,19,38)<<"\n";
    suma=0;
    for(int i=1; i<=12; i++){
        for(int j=1; j<=20; j++){
            suma+=komorki[i][j][2];
        }
    }
    cout<<"drugi "<<suma;



}