#include <iostream>
using namespace std;

int sudoku[9][9];
int puste[81][3];
int rows[9];
int cols[9];
int squares[3][3];
void seekbestpoint(int puste[][3], int npuste);
void amendpuste(int x, int y,int puste[][3], int npuste);

bool checkvertical(int x, int y, int l){
	for(int i=0; i<9; i++){
		if(sudoku[x][i]==l) return false;
	}
	return true;
}

bool checkhorizontal(int x, int y, int l){
	for(int i=0; i<9; i++){
		if(sudoku[i][y]==l) return false;
	}
	return true;
}

bool checkSsquare(int x, int y, int l){
	for(int i=x-(x%3); i<x-(x%3)+3; i++){
		for(int j=y-(y%3); j<y-(y%3)+3; j++){
			//cout<<i<<"ics "<<j<<"jcs ";
			if(sudoku[i][j]==l) return false; //first its row then its column 
			
		}
	}
	return true;
}



void solvesudoku(int x, int y, int puste[][3], int npuste){ // coordinates of, the best to fill, element of puste
	//cout<<"tu:"<<npuste<<"\n";
	if(npuste==0) return;
	
	for(int l=0; l<9; l++){
			if(checkvertical(x,y, l) and checkhorizontal(x,y,l) and checkSsquare(x,y,l)){
				cout<<"HERE:"<<l<<" "<<npuste<<"\n";
				sudoku[x][y]=l;
				amendpuste(x,y, puste,npuste);
				seekbestpoint(puste, npuste-1);
				cout<<npuste<<"here";
				
			}
	}
	
}

void amendpuste(int x, int y,int puste[][3], int npuste){
		for(int p=0; p<npuste; p++){
			if(puste[p][0]==x and puste[p][1]==y) {
				swap (puste[p][0], puste[npuste-1][0]);
				swap (puste[p][1], puste[npuste-1][1]);
				swap (puste[p][2], puste[npuste-1][2]);
			}
			else if(puste[p][0]==x or puste[p][1]==y or (puste[p][0]%3==x%3 and puste[p][1]%3==y%3))
				puste[p][2]++;
		}

}

void seekbestpoint(int puste[][3], int npuste){
	if(npuste==0) return;
	int max=0;
	int which=0;
	for(int i=0; i<npuste; i++){
		if(puste[i][2]>max){ 
			max=puste[i][2];
			which=i;
		}
	}
	solvesudoku(puste[which][0], puste[which][1] ,puste, npuste);
}

int main(){	

	int npuste=0;
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			cin>>sudoku[i][j];
			if(sudoku[i][j]==0){
				puste[npuste][0]=j;			//column	(x,
				puste[npuste][1]=i; 		//row  			,y)	
				puste[npuste][2]=0;	
				npuste++;
			}
		}
	}
	
	for(int p=0; p<npuste; p++){
		for(int i=0; i<9; i++){
			if(sudoku[i][puste[p][1]]!=0) puste[p][2]++;
		}
		for(int j=0; j<9; j++){
			if(sudoku[puste[p][0]][j]!=0) puste[p][2]++;
		}
		for(int kr=(puste[p][1]/3*3); kr<(puste[p][1]/3*3)+3; kr++){
			for(int kc=(puste[p][0]/3*3); kc<(puste[p][0]/3*3)+3; kc++){
				if(sudoku[kr][kc]!=0) puste[p][2]++;
			}
		}
	}
	
	cout<<"\n";
	for(int i=0; i<npuste; i++){ 
		for(int j=0; j<2; j++){
			cout<<puste[i][j]<<" ";			//x,y
		}
		cout<<"\n";
	}
	
	
	seekbestpoint(puste, npuste);
	
	
	
	cout<<"\n";
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			cout<<sudoku[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	return 0;
/*
0 0 0 0 6 5 8 3 7
6 1 7 8 3 4 9 5 2
3 8 5 9 7 2 6 4 1
5 3 2 6 8 1 4 7 9
7 4 1 2 5 9 3 8 6
8 6 9 7 0 3 2 1 5
9 2 8 4 1 7 5 6 3
4 7 3 5 9 6 1 2 8
1 5 6 3 2 8 7 9 4


0 9 4 1 6 5 8 3 7
6 1 7 8 3 4 9 5 2
3 8 5 9 7 2 6 4 1
5 3 2 6 8 1 4 7 9
7 4 1 2 5 9 3 8 6
8 6 9 7 4 3 2 1 5
9 2 8 4 1 7 5 6 3
4 7 3 5 9 6 1 2 8
1 5 6 3 2 8 7 9 4

*/
