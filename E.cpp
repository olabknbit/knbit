#include<iostream>

using namespace std;

int index(int* t, int kon, int k)
{
    char x;
    int pocz = 0;
    int polowa = (pocz+kon)/2;
    while(pocz != kon - 1)
    {
        if(t[polowa] >= k)
            kon = polowa;
        else
            pocz = polowa;
        polowa = (pocz+kon)/2;
    }
    if(t[pocz] == k)
        return kon;
    if(t[kon] == k)
        return kon+1;
    return -1;
}

int main(){
    int n,k,szukana;
    cin>>n>>k;
    int t[n];
    for(int i=0; i<n; i++){//wczytuje po kolei posortowane elementy tablicy
        cin>>t[i];
    }
    for(int i=0; i< k; i++){//wczytujemy po kolei wszystkie liczby ktorych inddeksy mamy wskazac
        cin>>szukana;
        cout<<index(t,n,szukana)<<" ";
    }
}
