#include<iostream>

using namespace std;

class A{
public:
	void funcA(){
		cout<<(long long)this<<endl;	
	}
};

class B{
public:
	void funcB(){
		cout<<(long long)this<<endl;	
	}
};

class C:public A, public B{
public:
	void funcC(){
		funcA();
		funcB();
		cout<<(long long)this<<endl;	
	}
	
};
	
	


int main(){
	C c;
	c.funcC();
	
	return 0;
	
}