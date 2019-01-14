#include<iostream>
#include<stdlib.h>
using namespace std;
#define total 10
#define coins_num 4
#define max_int 100000
int coins[coins_num] = {1,7,4,3};
int arr[total+1]={0};
int temp[total+1]={0};
int min(int a,int b){return a>b?b:a;}
//total位移了一下 1-total为有效索引号 0索引初始值是0 
void printarr(int arr[]){
	for(int j=1;j<total+1;j++){
		cout<<arr[j]<<",";
	}
	cout<<endl;
}
int dp(){
	for(int j=1;j<total+1;j++){
		if(j%coins[0]==0){
			temp[j]=j/coins[0];
			arr[j]=j/coins[0];
		}else{
			temp[j]=max_int;
			arr[j]=max_int;
		}
	}
	//初始化动态规划数组 
	printarr(temp);
	for(int i=1;i<coins_num;i++){  //指示第几行	
		for(int j=coins[i];j<total+1;j++){ //每一行行内元素指针 
			for(int k=1;0<=j-k*coins[i];k++){ //使用多少个该硬笔
				arr[j]=min(min(temp[j],arr[j]),arr[j-k*coins[i]]+k);
			}
		}
		printarr(arr);
		for(int j=1;j<total+1;j++){
			temp[j]=arr[j];//动态规划优化 
		}
	}
	return 0;
} 
int main(){
	dp();
	return 0;
}
