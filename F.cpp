#include <iostream>
//TODO
using namespace std;

int przesuniecie(int tab[], int pocz, int kon){
//TODO
}

int szukaj(int liczba, int tab[], int pocz, int kon){//TODO :AMEND
	if(kon-pocz==1){
		if(liczba==tab[pocz]) return pocz+1;
		return -1;
	}
	int srodek=(pocz+kon)/2;
	
	if(kon-pocz>0) {
		if(liczba<=tab[srodek]) szukaj(liczba, tab, pocz, srodek);
		else szukaj(liczba, tab, srodek, kon);
	}
	
}

int main(){
	int n,k, max, gdzie, liczba, wynik;
	
	cin>>n>>k;
	
	int tab[n];
	
	max=0;
	gdzie=n-1;
	for(int i=0; i<n; i++){
		cin>>tab[i];
		if(tab[i]<max) gdzie=i;
		max=tab[i];
		
	}
	for(int i=0; i<k; i++){
		cin>>liczba;
		if(liczba<tab[0]) wynik=szukaj(liczba, tab, gdzie, n);
		else if(liczba>tab[0]) wynik=szukaj(liczba, tab, 0, gdzie);
		else {
			wynik=szukaj(liczba, tab, gdzie, n);
			if(wynik==-1) wynik=1;
		}
		cout<<wynik<<" ";
	}
	
}

