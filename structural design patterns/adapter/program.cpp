#include<iostream>

using namespace std;

class target{
	public:
	virtual void draw()=0;
};


class legacy_rectangle{
	int x1,y1,x2,y2;
	public:
	legacy_rectangle(int x,int y,int w,int h):x1(x),y1(y),x2(w),y2(h){
		
	}
	
	void old_draw(){
		cout<<"old legacy"<<x1<<" "<<y1<<" "<<x2<<" "<<y2;
		
	}
};

class new_rectangle:public target,private legacy_rectangle{
	
	public:
	new_rectangle(int x1,int y1,int w,int h):legacy_rectangle(x1,y1,w+x1,h+y1){
		
	}
	
	void draw(){
		old_draw();
	}
	
};


int main(){
	
	target* t=new new_rectangle(10,15,4,3);
	t->draw();	
	
}
