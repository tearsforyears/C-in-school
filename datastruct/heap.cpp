#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
#define MAX_HEAP_LENGTH 100
#define INVAILD_ELEMENT -0xffffff 
#define arr_len 6
int heap[MAX_HEAP_LENGTH];
int maxarg(int a,int b){
	return heap[a]>heap[b]?a:b;
}
void print(int arr[]){
	for(int i=0;i<MAX_HEAP_LENGTH;i++){
		if(arr[i]!=INVAILD_ELEMENT)cout<<arr[i]<<",";
	}
	cout<<endl;
}
void init(int arr[]){
	for(int i=0;i<MAX_HEAP_LENGTH;i++){
		arr[i]=INVAILD_ELEMENT;
	}
}
int len(int arr[]){
	int i=0;
	while(arr[i]!=INVAILD_ELEMENT)i++;
	return i;
}
void swap(int arr[],int a,int b){
	int temp=arr[a];
	arr[a]=arr[b];
	arr[b]=temp;
}
/*
	index for heap
	parent(i) = floor((i - 1)/2)
	left(i)   = 2i + 1
	right(i)  = 2i + 2
*/
void shiftup(int index){//big root heap
	//index=len(heap)
	//the largest element should up
	int cur_index=index;
	int shifted_element=heap[cur_index];
	//cout<<cur_index<<","<<shifted_element<<endl;
	while(heap[(cur_index-1)/2]<shifted_element && cur_index!=0){//need to shiftup
		heap[cur_index]=heap[(cur_index-1)/2];//parent node should down
		cur_index=(cur_index-1)/2;
	}
	heap[cur_index]=shifted_element;
}
void shiftdown(int index){
	//index=0
	int cur_index=index;
	int shifted_element=heap[cur_index];
	//the element is so small so it should be shiftdown
	//select bigger one to up
	while(cur_index<len(heap) && heap[maxarg(2*cur_index+1,2*cur_index+2)]>shifted_element){
		//need to shiftdown
		heap[cur_index]=heap[maxarg(2*cur_index+1,2*cur_index+2)];
		cur_index=maxarg(2*cur_index+1,2*cur_index+2);
	}
	heap[cur_index]=shifted_element;
}
int del(){
	int data=heap[0];
	heap[0]=heap[len(heap)-1];
	heap[len(heap)-1]=INVAILD_ELEMENT;
	shiftdown(0);
	return data;	
}
void add(int data){
	heap[len(heap)]=data;
	shiftup(len(heap)-1);
}
void buildHeap(int arr[]){
	for(int i=0;i<arr_len;i++)add(arr[i]);
}
void buildheap(int arr[]){
	for(int i=arr_len/2;i>=0;i--)shiftdown(i);
}
int main(){
	init(heap);
	int arr[arr_len]={10,7,2,5,1,16};
	buildHeap(arr);
	add(18);
	print(heap);
	delete []arr;
	del();
	return 0;
}
