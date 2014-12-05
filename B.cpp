#include <iostream>
using namespace std;

int nwd(long long int a, long long int b){
	if(b==0) return a;
	nwd(b,a%b);
}

int main(){
	long long int ile, a, b, licznik, pom_ile;

	licznik=0;
	cin>>ile;
	long long int tab[ile][2];
	pom_ile=ile;

	while(pom_ile>0){

		cin>>a>>b;

		//NWD
		if(a==b) tab[licznik][0]=a;
		else tab[licznik][0]=nwd(a,b);

		//NWW
		if(a==b) tab[licznik][1]=a;
		else tab[licznik][1]=a*b/tab[licznik][0];

		licznik++;
		pom_ile--;
	}
	for(int i=0; i<ile; i++){
		cout<<tab[i][0]<<" "<<tab[i][1]<<"\n";
	}

	return 0;
}
