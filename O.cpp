#include <iostream>
using namespace std;

void next_perm(int tab[], int n){						//we create the reversed binary mask - the exact mask that reflects the elemnts of the combination
	int i=n-2, j;
	while(i>=0 and tab[i]>=tab[i+1]){ i--;} 			// while there are elements and they are decreasing 'looking' from the end 
	if(n==n-2 or i==-1) i++;							//if we did not move at all or we move till the beginning we have to amend i a little bit...
	if(i>0 or tab[0]<tab[1]){							//we have to take care of the fact that the first element may be and may be not smaller than the following el
		j=i+1;
		while(j<=n-1 and tab[i]<tab[j]){j++;}
		j--;
		swap(tab[i], tab[j]);
		i++;
	}
	j=n-1;
	while(i<j){											//we reverse the longest decreasing sequence 'looking ' from the end to complete the permutation
		swap(tab[i], tab[j]);
		j--;
		i++;
	}
}

int main(){
	int t,n,k,i, pom;
	
	cin>>t;
	for(int j=0; j<t; j++){
		cin>>n>>k>>i;
		i--;
		int * bin = new int[n]; 						// vs int tab[n]; <=> heap vs stack
		
		for(pom=0; pom<k; pom++) bin[pom]=0;			//creating "reversed" bin tab which has as many 0 as the number of elements in the combination (0 are 1)
		for(; pom<n; pom++) bin[pom]=1;
		
		for(pom=0; pom<i; pom++) next_perm(bin, n); 	// getting the binary mask of the k permut (which will be "reversed")
		
		//for(pom=0; pom<n; pom++) bin[pom]=(bin[pom]+1)%2;
		
		for(pom=1; pom<=n; pom++){
			if(bin[pom-1]==0) cout<<pom<<" ";
		}
			
		delete [] bin; 										//free heap
	}
//	system ("PAUSE");
	return 0;
}
