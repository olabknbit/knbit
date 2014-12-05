#include <iostream>

using namespace std;

int main(){
	int ile,a;
	cin>>ile;
	int tab[ile];
	
	for(int i=0; i<ile; i++){
		cin>>a;
		tab[i]=a;
	}
	for(int i=0; i<ile-1; i++){
		for(int j=0; j<ile-i-1; j++){
			if(tab[j]>tab[j+1]) swap(tab[j],tab[j+1]);
		}
	}cout<<"\n";
	for(int i=0; i<ile; i++){
		cout<<tab[i]<<" ";
	}
	
	
	return 0;
}
