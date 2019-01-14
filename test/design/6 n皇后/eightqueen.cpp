#include<iostream>
#include<stdlib.h>
using namespace std;
#define n 8
int chessboard[n]={-1};
//chessboard[y]=x (x,y) chessboard 为棋盘
int RAND(int min, int max){
	return (rand()+1)  * (max - min) / (0x7FFF) + min; 
}
bool judge(int y,int x){
	for(int i=0;i<y;i++){
        if(x==chessboard[i])return false; 
        if((y-i)==(x-chessboard[i]))return false;  // 正斜率 
        if((y-i)==-(x-chessboard[i]))return false; // 负斜率 
    }
    return true; 
}
void huisu(int y){
	if(y<n){
		for(int x=0;x<n;x++){
			if(judge(y,x)){
				chessboard[y]=x; //取值 
				huisu(y+1);
				chessboard[y]=-1;//回溯			
			}
		}
	}else{
		for(int i=0;i<n;i++){
			cout<<chessboard[i]<<",";
		}
		cout<<endl;
		return;
	}
}
void suiji(int y){
	if(y<n){
		int x=RAND(0,n); //随机取一个x进行尝试 
		if(judge(y,x)){
			chessboard[y]=x; //取值 
			suiji(y+1);
			chessboard[y]=-1;//回溯			
		}
	}else{
		for(int i=0;i<n;i++){
			cout<<chessboard[i]<<",";
		}
		cout<<endl;
		return;
	}
}
int main(){
	//回溯法 
	//huisu(0);
	
	//拉斯维加斯算法 
	while(true)suiji(0);
	 
	return 0;
} 
