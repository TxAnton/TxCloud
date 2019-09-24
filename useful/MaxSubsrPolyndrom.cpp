#include <iostream>
#include <string>

using namespace std;

int rec(string str,int reclvl=0){
	
	int len =str.length(); 
	bool flag=true;
	for(int i =0;i<len/2;i++){
		if(str[i]!=str[len-1-i]){
			flag=false;
			break;
		}
	}
	if(flag){
		for(int j =0;j<reclvl;j++)cout<<' ';
		if(str.length()!=1)cout<<str<<endl;
		return len;
	}
	else{
		int l1 = rec(str.substr(0,len-1),reclvl+1);
		int l2 = rec(str.substr(1,len-1),reclvl+1);
		
		return l1>=l2?l1:l2;
	}
		   
}



int main(){
	string str;
	
	getline(cin,str);
	//int len = str.length();
	//cout<<str.substr(0,len-1)<<endl<<str.substr(1,len-1);
	cout<<rec(str)<<endl;
	
	return 0;	
}


	