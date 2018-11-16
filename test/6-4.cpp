#include <iostream>
#include <string.h>
#define len1 8
#define len2 8
using namespace std;
int printarr(int arr[],int len){
	for(int i=0;i<len;i++)cout<<arr[i]<<",";
	cout<<endl;
}
int max(int a,int b){
	return a>b?a:b;
}
int main(){
	char * str1="xzyzzyx"; 
	char * str2="zxyyzxz";
	//init
	int lis[len1]={0};
	int std[len2]={0};
	
	for(int i=1;i<len2;i++){
		for(int j=1;j<len1;j++){
			if(str1[j-1]==str2[i-1]){
				lis[j]=std[j-1]+1;
			}else{
				lis[j]=max(lis[j-1],std[j]);
			}		
		}
		printarr(lis,len1);
		// copy lis to std and do the next loop
		for(int i=0;i<len1;i++){
			std[i]=lis[i];
		}
	}	
	return 0;
}
