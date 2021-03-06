#include <iostream> 
using namespace std;
#define bag_size 6
#define num 5
int max(int a,int b){
	return a>b?a:b;
}
int printarr(int arr[],int len){
	for(int i=0;i<len;i++)cout<<arr[i]<<",";
	cout<<endl;
}
int main(){
	int weight[]={3,2,1,4,5};
	int value[]={25,20,15,40,50};
	
	//init
	int lis[bag_size+1]={0,0,0,0,0,0,0};
	int std[bag_size+1]={0,0,0,0,0,0,0};
	
	for(int i=0;i<num;i++){
		for(int j=bag_size;j>=0;j--){
			if(j-weight[i]>=0){
				lis[j]=max(std[j],lis[j-weight[i]]+value[i]);
			}
		}
		printarr(lis,bag_size+1); //the result
		// copy lis to std and do the next loop
		for(int i=0;i<bag_size+1;i++){
			std[i]=lis[i];
		}
		//不填充0使得逻辑崩溃,不逆序应该变成无限背包了 
	}	
	return 0;
}
