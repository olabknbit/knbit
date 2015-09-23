#include <iostream>

using namespace std; 

struct heap {
		int value;
		heap * below; 	
};

heap * push(heap * top, int value){
	heap * newtop = new heap;
	newtop->value = value;
	newtop->below=top;
	return newtop;
}

heap * pop(heap * top){
	if(top->below==NULL) return top;
	else
		top=top->below;
	return top;
}

int main(){
	
	heap * top = new heap;
	top->value = NULL;
	top->below = NULL;
	
	int z, element;
	string op="";
	cin>>z;
	for(int i=0; i<z; i++){
		cin>>op;
		if(op=="PUSH"){
			cin>>element;
			top=push(top, element);
		}
		else if(op=="POP"){
			top=pop(top);
			
		}
		else if(op=="TOP"){
			if(!top->value)	cout<<"EMPTY\n";
			else cout<<top->value<<"\n";
		}
		
	}
//	cout<<top->value;
	return 0;
}
