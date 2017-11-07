#include<iostream>

using namespace std;

class person{
public:	string name;
	public:
	person(string p):name(p){}
	
};

class real{
	
	public:
	void draw(){
		cout<<"draw real\n";
	}
	void draw1(){
		cout<<"draw1 real\n";
	}
};


class virtualproxy{
	real* rptr;
	public:
	virtualproxy():rptr(NULL){}
	~virtualproxy(){
		delete rptr;
	}
	
	real* operator ->(){
			return rptr;
	}
	
	void draw(person *p){
		if(p->name=="babbu"){	
			if(rptr==NULL){	
			    
				rptr=new real;
				rptr->draw();
			}
		}else{
			cout<<"access to real not provided\n";
		}	
	}
	void draw1(){
		cout<<"draw1 proxy\n";
	}
	
	
	
	
};

int main(){
	
	virtualproxy vp;
	person vp1("rohit"),vp2("babbu");
	vp.draw(&vp1);//autentication proxy and virtuall proxy
	vp->draw1();//-> and . give different result
	vp.draw1();
	vp.draw(&vp2);//autentication proxy and virtuall proxy

    
    
}