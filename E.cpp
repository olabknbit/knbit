#include <iostream>
using namespace std;

int find(int *t,int liczba,int pocz,int kon){

	if(pocz==kon-1){
		if(t[pocz]==liczba) return pocz+1;
		return -1;	
	} 
    int polowa=(pocz+kon)/2;
   
    if(liczba<=t[polowa]) {
    	if(polowa-pocz==1){
    		if(t[pocz]==liczba) return pocz+1;
    		if(t[polowa]==liczba) return polowa+1;
    		return -1;
    	}
    	return find(t, liczba, pocz, polowa+1);
    }//tu powinno byæ polowa+1 ale wtedy nie dziala
    else return find(t, liczba, polowa, kon);
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
        cout<<find(t,szukana, 0, n)<<" ";
    }
}

