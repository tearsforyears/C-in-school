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
//totalλ����һ�� 1-totalΪ��Ч������ 0������ʼֵ��0 
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
	//��ʼ����̬�滮���� 
	printarr(temp);
	for(int i=1;i<coins_num;i++){  //ָʾ�ڼ���	
		for(int j=coins[i];j<total+1;j++){ //ÿһ������Ԫ��ָ�� 
			for(int k=1;0<=j-k*coins[i];k++){ //ʹ�ö��ٸ���Ӳ��
				arr[j]=min(min(temp[j],arr[j]),arr[j-k*coins[i]]+k);
			}
		}
		printarr(arr);
		for(int j=1;j<total+1;j++){
			temp[j]=arr[j];//��̬�滮�Ż� 
		}
	}
	return 0;
} 
int main(){
	dp();
	return 0;
}
