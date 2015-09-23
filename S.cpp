#include <iostream>
using namespace std;

struct train{
	string peep;
	train * left;
	train * right;
	bool reversed;
};
train* lookup_name(train* heads[20][2], int &n_heads, string &name, bool start){
	for(int i=0; i<n_heads; i++){
		if(heads[i][0]->peep == name){
			if(start)
				return heads[i][0];
			else
				return heads[i][1];
		}
	}
}


void new_train(train* heads[20][2], int& n_heads, string& name, string& peep){
	heads[n_heads][0] = new train;
	train* current = new train;
	heads[n_heads][1] = new train;
	
	//current->peep = name;
	//current->left = NULL;
	//current->right = 
	heads[n_heads][0]->peep = name;
	heads[n_heads][0]->left = NULL;
	heads[n_heads][0]->right = current;
	heads[n_heads][0]->reversed = false;
				
	current->peep = peep;
	current->left = heads[n_heads][0];
	current->right = heads[n_heads][1];
	current->reversed = NULL;
				
	heads[n_heads][1]->peep = name;
	heads[n_heads][1]->left = current;
	heads[n_heads][1]->right = NULL;
	heads[n_heads][1]->reversed = false;
	
	n_heads++;
	

}

/*
1
5
NEW Jeden Przemek
FRONT Jeden Grzegorz
BACK Jeden Andrzej
REVERSE Jeden
PRINT Jeden


*/
void add(train* heads[20][2], int &n_heads, string &name, string &peep, bool start){
	
	train* uno;
	train* dos;
	
	bool reversed;
	
	if(start){		
		uno = lookup_name(heads, n_heads, name, true);	//first
		reversed = uno->reversed;
		if(!reversed) dos = uno->right;								//following
		else {
			dos = uno;
			uno = uno-> left;
		}
	}
	else{
		dos = lookup_name(heads, n_heads, name, false);	//last
		reversed = dos->reversed;
		if(!reversed) uno = dos->left;								//previous
		else {
			uno = dos;
			dos = uno->left;
		}
	}
	
	train* new_peep = new train;
	
	new_peep->peep = peep;
		
	new_peep->left = uno;
	new_peep->right = dos;
	new_peep->reversed = NULL;		
			
	uno->right = new_peep;
	dos->left = new_peep;
}
void print(train* heads[20][2], int &n_heads, string& name){
	
	train* first = lookup_name(heads, n_heads, name, true);
	bool reversed = first->reversed;
	
	cout<<" "<<name<<" :\n";
	
	if(!reversed){
		first = first->right;
		
		cout<<first->peep;
		first = first->right;
		while(first->peep!=name){
			cout<<"<-"<<first->peep;
			first = first->right;
		}cout<<"\n";
	}
	else{
		first = first->left;
		
		cout<<first->peep;
		first = first->left;
		while(first->peep!=name){
			cout<<"<-"<<first->peep;
			first = first->left;
		}cout<<"\n";
	}
}

void reverse(train* heads[20][2], int &n_heads, string& name){
	
	for(int i=0; i<n_heads; i++){
		if(heads[i][0]->peep == name){
			swap(heads[i][0],heads[i][1]);
			if(heads[i][0]->reversed) heads[i][0]->reversed = heads[i][1]->reversed = false;
			else heads[i][0]->reversed = heads[i][1]->reversed = true;
		}
	}
}

void delete_train(train* heads[20][2], int &n_heads, string& name){
	for(int i=0; i<n_heads; i++){
		if(heads[i][0]->peep == name){
			heads[i][0]->name = heads[i][0]->left = heads[i][0]->right = heads[i][0]->reversed = NULL;
			heads[i][1]->name = heads[i][1]->left = heads[i][1]->right = heads[i][1]->reversed = NULL;
			
			delete heads[i][0];
			delete heads[i][1];
			
			swap(heads[i][0], heads[n_heads-1][0]);
			swap(heads[i][1], heads[n_heads-1][1]);
			
			n_heads--;
			return;
		}
	}
}

void union(train* heads[20][2], int& n_heads, string& name1, string& name2){
	train* end1 = lookup_name(heads, n_heads, name1, false);
	train* start2 = lookup_name(heads, n_heads, name2, true);
	train* end2 = lookup_name(heads, n_heads, name2, false);
	
	if(!end1->reversed and !start2->reversed){
		end1 = end1->left;
		start2 = start2->right;
		end2 = end2->left;
		
		end1->right = start2;
		start2->left = end1;
		
		end2->right = end1;
		end1->left = end2;
	}
	else if(end1->reversed and !start2->reversed){
		train* current_uno = start2;
		train* current_dos = current_uno->right;
		train* current_tres = current_dos->right;
		
		current_uno->right = NULL;
		current_uno->left = current_dos ; 		
		
		while(current_tres!=end2){
			current_dos->right = current_uno;
			current_dos->left = current_tres;
			
			current_uno = current_dos;
			current_dos = current_tres;
			current_tres = current_tres->right;
		}
		
		current_tres->left = NULL;
		current_tres->right = current_dos;
		
	}
	else if(!end1->reversed and start2->reversed){
		//TUX)
	}
	else if(end1->reversed and start2->reversed){
		end1 = end1->right;
		start2 = start2->left;
		end2 = end2->right;
		
		end1->left = start2;
		start2->right = end1;
		
		end2->left = end1;
		end1->right = end2;
	}
	delete_train(heads, n_heads, name2);
}



	
	

int main(){
	int n, z, n_heads=0;
	train* heads[20][2];
	train* current;
	string task, name, peep, name1, name2;
	
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>z;
		for(int j=0; j<z; j++ ){
			cin>>task;
			if(task=="NEW"){
				cin>>name>>peep;
				new_train(heads, n_heads, name, peep);
			}
			else if(task=="BACK"){
				cin>>name>>peep;
				add(heads, n_heads, name, peep, false);
			}
			else if(task=="FRONT"){
				cin>>name>>peep;
				add(heads, n_heads, name, peep, true);
			}
			else if(task=="PRINT"){
				cin>>name;
				print(heads, n_heads, name);
			}
			else if(task=="REVERSE"){
				cin>>name;
				reverse(heads, n_heads, name);
			}
			else if(task=="DELFRONT"){
				cin>>name1>>name2;
			//	delfront(heads, n_heads, name1, name2);
			}
			else if(task=="DELBACK"){
				cin>>name1>>name2;
			}
			else if(task=="UNION"){
				cin>>name1>>name2;
			}
		}
	}
	cout<<n_heads;
	
	
	return 0;
}
