#include<iostream>
#include<stdlib.h>
using namespace std;
#define n 8
int chessboard[n]={-1};
//chessboard[y]=x (x,y) chessboard Ϊ����
int RAND(int min, int max){
	return (rand()+1)  * (max - min) / (0x7FFF) + min; 
}
bool judge(int y,int x){
	for(int i=0;i<y;i++){
        if(x==chessboard[i])return false; 
        if((y-i)==(x-chessboard[i]))return false;  // ��б�� 
        if((y-i)==-(x-chessboard[i]))return false; // ��б�� 
    }
    return true; 
}
void huisu(int y){
	if(y<n){
		for(int x=0;x<n;x++){
			if(judge(y,x)){
				chessboard[y]=x; //ȡֵ 
				huisu(y+1);
				chessboard[y]=-1;//����			
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
		int x=RAND(0,n); //���ȡһ��x���г��� 
		if(judge(y,x)){
			chessboard[y]=x; //ȡֵ 
			suiji(y+1);
			chessboard[y]=-1;//����			
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
	//���ݷ� 
	//huisu(0);
	
	//��˹ά��˹�㷨 
	while(true)suiji(0);
	 
	return 0;
} 
