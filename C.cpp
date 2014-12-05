#include <iostream>
#include <math.h>

using namespace std;
//sitem  erastostenesa zrobic
bool pierwsza(int n){
	int pierwiastek;
	
	if(n<2) return 0;
	if(n<4) return 1;
	if(n%2==0 or n%3==0) return 0;
	 pierwiastek=sqrt(n);
	 
	for(int i=5; i<=pierwiastek; i+=2) {
		if(n%i==0) return 0;
	}
	return 1;
}

int main(){
	
	int ile, n;
	cin>>ile;
	bool tab[ile];
	for(int i=0; i<ile; i++){
		cin>>n;
		if(pierwsza(n)) tab[i]=true;
		else tab[i]=false;
	}
	for(int i=0; i<ile; i++){
		if(tab[i]) cout<<"TAK\n";
		else cout<<"NIE\n";
	}
	return 0;	
}
