#include<iostream>
#include<vector>
using namespace std;

class component{
	public:
	virtual void traverse()=0;
	
};

class primitive:public component{
	
	int val;
	public: 
    primitive(int i):val(i){
	}
	
	void traverse(){
		cout<<val;
	}
	
	
};

class composite:public component{
	//int val;
	vector<component*> comp;
	public:
//	composite(/*int i*/)/*:val(i)*/{
		
//	}
	
	void traverse(){
	//	cout<<val;
		for(int i =0;i<comp.size();i++){
			comp[i]->traverse();
		}
		
	}
	
	void add(component* c){
		comp.push_back(c);
	}
	
};

int main(){
	composite container[4];
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++){
			container[i].add(new primitive(i*3+j));
		}
	}
	for(int i=1;i<4;i++){
			container[0].add(&container[i]);
	}
	
	for(int i=0;i<4;i++){
			container[i].traverse();
			cout<<endl;
	}
	
	
}

