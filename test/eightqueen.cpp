//author = "tearsforyears@github.com"
#include<iostream>
using namespace std;
#define n 8
int arr[n]={-1,-1,-1,-1,-1,-1,-1,-1};
//this array store the position of queen
//eg: arr[0]=4 arr[1]=7 means (4,0) and (7,1) both has a queen
//妈的剪枝时候 y+1 debug一小时 注意边界!注意边界! 
bool judge(int y,int x){
    // false for do not use the (x,y) 
	for(int i=0;i<y;i++){
        if(x==arr[i])return false;
        if((y-i)==(x-arr[i]))return false;
        if((y-i)+(x-arr[i])==0)return false;
    }
    return true;
}
void dfs(int y){
	for(int x=0;x<n;x++){
		if(y<n){
			if(judge(y,x)){//pruning
				arr[y]=x;
				dfs(y+1);
				arr[y]=-1;//back-track			
			}
		}else{
			for(int i=0;i<n;i++)cout<<arr[i]<<",";
			cout<<endl;
			return;
		}
	}
	return;
}
int main(){
	dfs(0);
	return 0;
} 
