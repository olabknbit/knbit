#include <iostream>
using namespace std;

long long unsigned int sum=0;                              // the sum of all the inversions, counted globally 

void merge(int t[], int s, int m, int e){ // it sorts all the elements AND counts the sum of inversions
	int nt[(e-s)], i, j,licznik;
	i=s;
	j=m;
	licznik=0;

	while(i<m and j<e){                 // as long as the 'left' and 'right' part of what we are merging (and sorting in the same time) is not finished
		if(t[i]<=t[j]){                   //sorts the elements
			nt[licznik]=t[i];
			licznik++;
			i++;

		}else{
			nt[licznik]=t[j];
			licznik++;
			sum+=(m-i);
			//cout<<s<<" "<<i<<" "<<m<<" "<<j<<" "<<nt[licznik-1]<<"\n";
			j++;

		}
	}
	while(i<m){                         //when the 'left' part of the merge waas not empty
		nt[licznik]=t[i];
		licznik++;
		i++;
	}
	while(j<e){                         //when the 'right' part of the merge waas not empty
		nt[licznik]=t[j];
		licznik++;
		j++;
	}
	for(int k=s; k<e; k++){             //exporting data from table 'nt' to our initial table 't'
		t[k]=nt[k-s];
	}

}
// 3  3 2 1				3
// 5  2 8 9 6 5			0221=5
// 8  1 2 3 8 5 6 9 4    6
void mergesort(int t[], int s, int e){  //quite obvious I think
	if(e-s==1) return;
	int m=s+(e-s)/2;
	mergesort(t,s,m);
	mergesort(t,m,e);
	merge(t,s,m,e);

}

int main(){
	int n;
	cin>>n;
	if(n==0){                     //if there are to be no elements
        	cout<<0<<"\n";
		return 0;
	}
	else{
		int * tab= new int[n];

		for(int i=0; i<n; i++){
			cin>>tab[i];
		}
		mergesort(tab,0,n);

		cout<<sum<<"\n";
		delete [] tab;
	}

	return 0;
}
