#include"stdio.h"
#define LEN 8
void swap(int lis[],int a,int b){
	int temp=lis[a];
	lis[a]=lis[b];
	lis[b]=temp;
}
void printarr(int arr[]){
	for(int i=0;i<LEN;i++){
		printf("%d,",arr[i]);
	}
	printf("\n");	
}
void arrange(int cur,int lis []){
	if(cur==LEN-1){
		printarr(lis);
	}
	for(int i=cur;i<LEN;i++){
		swap(lis,cur,i);
		arrange(cur+1,lis);
		swap(lis,cur,i);
	}
}
int main(){
	int lis[LEN]={1,2,3,4,5,6,7,8};
	arrange(0,lis);
	return 0; 
} 
