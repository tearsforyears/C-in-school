#include"stdio.h"
#define size 9
void swap(int arr[],int a,int b){
	int temp=arr[a];	
	arr[a]=arr[b];
	arr[b]=temp;
}
void printarr(int arr[]){
	for(int i=0;i<size;i++){
		printf("%d,",arr[i]);
	}
	printf("\n");
}

void arrange(int arr[],int cur){
	if(size==cur+1){
		if((arr[0]*10+arr[1])*arr[2]+(arr[3]*100+arr[4]*10+arr[5])/arr[6]-(10*arr[7]+arr[8])==0){
			if(arr[2]!=1 && arr[6]!=1){
				printarr(arr);	
			}
		} 
	}	
	for(int i=cur;i<size;i++){
		swap(arr,cur,i);
		arrange(arr,cur+1);
		swap(arr,cur,i);
	}
}

int main(){
	//init
	int arr[size];
	for(int i=0;i<size;i++){
		arr[i]=i+1;
	}
	
	//arrange
	arrange(arr,0);
	return 0;
} 
