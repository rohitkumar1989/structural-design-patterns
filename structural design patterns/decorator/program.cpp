#include<iostream>

using namespace std;

class I{//interface widget
	public: 
	virtual ~I(){
	}
	virtual void doit()=0;
};

class A:public I{//core functionality class//textfield
	int i;
	public:
	~A(){
		cout<<"\nA destructor.";
	}
	A(int i):i(i){
		cout<<"\nA constructor.\n";
	}
	void doit(){
		cout<<"A => "<<i<<" ";
	}
	
};

class D:public I{//decorator  inherit from interface//scroll decorate
	I* i;
	public:
	D(I* i):i(i){

	}
	void doit(){
		i->doit();
	}
	~D(){
		delete i;
		cout<<"\nD destructor";
	}
};

class X:public D{//embellishment class//option//decoration////border decorator
	
	public:
	X(I* i):D(i){//pass element to decorate to D
	
	    cout<<"\nX constructor\n";
	}
	
	void doit(){
		//cout<<"x1";//embellishment before
		D::doit();
		cout<<"X"; //embellishment after
	}
	
	~X(){
		cout<<"\nX destructor";
	}
};

class Y:public D{//embellishment option2
	
	public:
	Y(I* i):D(i){
	
	    cout<<"\nY constructor\n";
	}
	
	void doit(){
		//cout<<"x1";
		D::doit();
		cout<<"Y";
	}
	
	~Y(){
		cout<<"\nY destructor";
	}
};

class Z:public D{
	
	public:
	Z(I* i):D(i){
	
	    cout<<"\nZ constructor\n";
	}
	
	void doit(){
		//cout<<"x1";
		D::doit();
		cout<<"Z";
	}
	
	~Z(){
		cout<<"\nZ destructor";
	}
};

int main(){
	
	I* anx=new X(new A(5));
	anx->doit();
	delete anx;
	I* anxy=new Y(new X(new A(6)));
	anxy->doit();
	delete anxy;
	I* anxyz=new Z(new Y(new X(new A(7))));
	anxyz->doit();
	delete anxyz;
	
}