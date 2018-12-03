#include<iostream>
#define len 5
using namespace std;
int x[len]={1,2,3,8,1};
int flag[len]={0};
int y=7;
int sum=0;
void f(int s){
	if(sum==y){
		for(int i=0;i<len;i++){
			if(flag[i]==1)cout<<i<<",";
		}
		cout<<endl;
	}
	for(int i=s+1;i<len;i++){
		sum+=x[i];
		flag[i]=1;
		f(i);
		flag[i]=0;
		sum-=x[i]; //»ØËÝ
	}
}
int main(){
	f(-1);
	return 0;
}
