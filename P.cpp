#include <iostream>
using namespace std;

int n_of_perm(int n, int k){
	if(k<n/2) k=n-k;
	int temp=k+1, out, ktemp;
	ktemp=1;
	out=1;
	while(temp<=n){
		out*=temp;
		out/=ktemp;
		temp++;
		ktemp++;
	}
	return out;
}

void next_permut(int tab[], int n){
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

int NWW_two(int a,int b){
	if(a==b) return a;
    else{
        if(a<b) swap(a,b);//A b
        if(a%b==0) return a;
        int t=a;
        int q=2;
        while(q<=a){
            if(a%q==0){
                a=a/q;
                if(b%q==0){
                    b=b/q;
                }

                else q++;
            }
        }
        t=t*b;
        return t;
    }
}

int NWW_multiple(int numbers[], int n){
	int i=0;
	int nww=0;
	while(i<n and numbers[i]==false) i++;
	nww=numbers[i];
	for(int j=1; j<n; j++){
		i++;
		while(i<n and numbers[i]==false) i++;
		nww=(nww, numbers[i]);
	}
	return nww;

	
	
}

int main(){
	int n, a, b, n_of_per, nww, sign;
	long long score;
	cin>>n>>a>>b;
	
	int * dividers = new int [n];
	int * binary_mask= new int [n];
	binary_mask={0};
	
	for(int i=0; i<n; i++){
		cin>>dividers[i];
	}

	binary_mask[n-1]=1;								//reversed binary mask
	for(int i=0; i<n; i++){
		score+=((b-a+1)/dividers[i]); // adding the difference between the number of divisible numbers
	}
	sign=-1;
	/*for(int i=1; i<=n;i++){
		binary_mask[n-1-i]=1;
		n_of_per=n_of_perm(n,i+1);
		for(int j=0; j<n_of_per; j++){ // combinations (n above k)
			next_permut(dividers, i+1);
			nww=NWW_multiple(dividers, j);
			score+=(sign*((b-a+1)/nww));
		}
		sign*=-1;
		
	}*/
	
	cout<<score;
	return 0;
}
