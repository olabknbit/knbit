#include <iostream>
#include <math.h>

using namespace std;

const double A=0.00000000001;

long double f(long double liczba, long double acc, long double pierw){
	
	if(fabs(pierw*pierw-liczba)<A){
		//cout<<pierw*pierw<<" "<<pierw*pierw-liczba<<" "<<fabs(pierw*pierw-liczba)<<"\n";
		return pierw;}
	acc/=2;
	if(pierw*pierw>liczba) pierw-=acc;
	else pierw+=acc;
	return f(liczba, acc, pierw);
	
}

int main(){
	
	int z;
	long double liczba,wynik;
	cin>>z;
	
	cout.precision(8);
	for(int i=0; i<z; i++){
		cin>>liczba;
		wynik=f(liczba, liczba/2, liczba/2);
		cout<<wynik<<"\n";
	}
	
	
	return 0;
}
