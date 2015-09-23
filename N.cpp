
#include <iostream>
#include <stdlib.h>
using namespace std;

void next_perm(long long int tab[], int n){
	int i=n-2, j;
	while(i>=0 and tab[i]>=tab[i+1]){ i--;} // while 4321
	if(n==n-2 or i==-1) i++;
	//cout<<i<<"i ";
	if(i>0 or tab[0]<tab[1]){
		j=i+1;
		while(j<=n-1 and tab[i]<tab[j]){j++;}
		j--;
		//cout<<j<<"j ";
		swap(tab[i], tab[j]);
		i++;

	}
	j=n-1;
	while(i<j){
		swap(tab[i], tab[j]);
		j--;
		i++;
	}
}
// 10
// 3 4 3 2 1 2 4 3 2 1 stdin
// 3 4 3 2 1 3 1 2 2 4 stdout

int main(){
	int n;
	cin>>n;
	long long int * tab = new long long int[n]; //int tab[n]; <=> sterta a stos
	for(int i=0; i<n; i++){

		cin>>tab[i];
	}
	next_perm(tab, n);
	for(int i=0; i<n; i++){

		cout<<tab[i]<<" ";
	}cout<<"\n";
	
	delete [] tab; //free stos
	system ("PAUSE");
	return 0;
}
