#include <iostream>

using namespace std;

int main(){
	
	int n, liczba, maxLiczba;
	cin>>n;
	maxLiczba=0;
	for(int i=0; i<n; i++){
		cin>>liczba;
		if(liczba>maxLiczba) maxLiczba=liczba;
	}
	cout<<maxLiczba;
	
	return 0;
}
