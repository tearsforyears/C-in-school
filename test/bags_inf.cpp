#include<iostream>
#define bag_size 10
#define num 4
using namespace std;
int max(int a,int b){
	return a>b?a:b;
}
int printarr(int arr[],int len){
	for(int i=0;i<len;i++)cout<<arr[i]<<",";
	cout<<endl;
}
int main(){
	int weight[]={2,3,4,7};
	int value[]={1,3,5,9};
	
	//init
	int lis[bag_size+1]={0};
	int std[bag_size+1]={0};
	
	for(int i=0;i<num;i++){
		for(int j=weight[i];j<bag_size+1;j++){
			lis[j]=max(std[j],lis[j-weight[i]]+value[i]);
		}
		printarr(lis,bag_size+1); //the result
		// copy lis to std and do the next loop
		for(int i=0;i<bag_size+1;i++){
			std[i]=lis[i];
		}
	}	
	return 0;
}
