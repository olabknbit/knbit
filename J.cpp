#include <iostream>
using namespace std;

void merge(int t[], int nt[], int s, int m, int e){
	int  i, j,licznik;//nt[(e-s)],
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

void mergesort(int t[], int nt[],int s, int e){
	if(e-s==1) return;
	int m=s+(e-s)/2;
	mergesort(t,nt,s,m);
	mergesort(t,nt,m,e);
	merge(t, nt,s,m,e);
	
}

int main(){
	int n;
	cin>>n;
	int tab[n], nt[n];
	
	for(int i=0; i<n; i++){
		cin>>tab[i];
	}
	mergesort(tab,nt,0,n);
	for(int i=0; i<n; i++){
		cout<<tab[i]<<" ";
	}
	cout<<"\n";
	
}
