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
	int n, j,sum,zl;
	cin>>n>>zl;
	int *tab=new int[n];
	
	if(n<2 or zl==0){
		cout<<"NIE"; return 0;
	}
	
	for(int i=0; i<n; i++){
		cin>>tab[i];
	}
	mergesort(tab,0,n);

	
	j=n-1;
	sum=zl+1;
	if(tab[0]<zl){
		for(int i=0; i<n; i++){
	
			while(j>i and tab[i]+tab[j]>zl){
				j--;
			}
			if(j==i) break;
			if(tab[i]+tab[j]==zl) {
				cout<<"TAK"; 
				sum=tab[i]+tab[j];
				break; 
			}
		}
	}
	if(sum!=zl) cout<<"NIE";
	
	return 0;
}
