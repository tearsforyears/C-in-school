#include<iostream>
#include<math.h>
#define n 20
using namespace std;
int loop[n]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}; 
void printloop(){
	for(int i=0;i<n;i++)cout<<loop[i]<<",";
	cout<<endl;
}
bool is_prime(int num){
	for(int i=2;i<sqrt(num);i++){
		if(num%i==0)return false;
	}
	return true;
}
bool judge(int cur,int num){
	if(cur==0)return true; // speed up
	//true for current position can fill with number
	for(int i=0;i<cur;i++){
		if(loop[i]==num)return false;
	}
	//judge the front position add this is prime or not
	if(!is_prime(num+loop[cur-1]))return false;
	if(cur+1==n && !is_prime(loop[cur]+loop[0]))return false;
	return true;
}
void dfs(int cur){
	for(int i=0;i<n;i++){
		if(cur<n){
			if(judge(cur,i)){
				loop[cur]=i;
				dfs(cur+1);
				loop[cur]=-1;				
			}
		}else{
			printloop();
			return;
		}
	}
	return;
}
int main(){
	dfs(0);
	return 0;
}
