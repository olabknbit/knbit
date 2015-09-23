#include <iostream>
using namespace std;

void merge(int t[], int s, int m, int e){
	int nt[(e-s)], i, j,licznik;
	i=s;
	j=m;
	licznik=0;
	
	while(i<m and j<e){
		if(t[i]<=t[j]){
			nt[licznik]=t[i];
			licznik++;
			i++;
			
		}else{
			nt[licznik]=t[j];
			licznik++;
			j++;
		}
	}
	while(i<m){
		nt[licznik]=t[i];
		licznik++;
		i++;
	}
	while(j<e){
		nt[licznik]=t[j];
		licznik++;
		j++;
	}
	for(int k=s; k<e; k++){
		t[k]=nt[k-s];
	}
	return;
	
}

void mergesort(int t[], int s, int e){
	if(e-s==1) return;
	int m=s+(e-s)/2;
	mergesort(t,s,m);
	mergesort(t,m,e);
	merge(t,s,m,e);
	
}

int main(){
	int n,k,f,razem;
	cin>>n>>f;
	razem=n+f;
	int *tab=new int [razem];
	
	if(razem==0) {
		cout<<"0"; return 0;
	}
	
	for(int i=0; i<razem; i++){
		cin>>tab[i];
	}
	mergesort(tab,0,razem);
	
	k=1;
	cout<<tab[0]<<" ";
	for(int i=1; i<razem; i++){
		if(tab[i]!=tab[i-1]){
			tab[k]=tab[i];
			cout<<tab[k]<<" " ;
			k++;
			
		}
	}
	//SYSTEM("PAUSE");
	return 0;
}
