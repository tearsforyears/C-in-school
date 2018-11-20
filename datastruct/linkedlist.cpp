#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct LinkedList{
	LinkedList* next;
	int data;
}LinkedList;
LinkedList* init(){
	LinkedList* pHead = (LinkedList*)malloc(sizeof(LinkedList));
	if(NULL==pHead){
		cout<<"error";
        exit(-1);
	}
	pHead->next=NULL;
	return pHead;
}
void append(LinkedList* lis,int data){
	if(lis->next==NULL){
		lis->data=data;
		lis->next=init();
		//cout<<lis->data<<",";
	}else{
		append(lis->next,data);
	}
}
void travel(LinkedList* lis){
	if(lis->next==NULL){
		cout<<endl;
		return;
	}else{
		cout<<lis->data<<",";
		travel(lis->next);
	}
}
int len(LinkedList* lis){
	LinkedList* temp=lis;
	int i=0;
	while((temp=temp->next)!=NULL)i++;
	//cout<<i<<endl;
	return i;
}
LinkedList* insert(LinkedList* lis,int data,int pos){
	if(pos==0){
		LinkedList *node=init();
		node->data=data;
		node->next=lis;
		return node;
	}else if(pos>len(lis)){
		cout<<"error:list index out of range"<<endl;
		return NULL;
	}else{
		LinkedList* top=lis;
		for(int i=0;i<pos-1;i++){
			top=top->next;
		}
		LinkedList* node=init();
		node->data=data;
		node->next=top->next;
		top->next=node;
		return lis;
	}
}
LinkedList* del(LinkedList* lis,int pos){
	if(pos>len(lis))cout<<"error:list index out of range"<<endl;
	else if(pos==0){
		return lis->next;
	}else{
		LinkedList* top=lis;
		for(int i=0;i<pos-1;i++){
			top=top->next;
		}
		top->next=top->next->next;
		return lis;
	}
}
int main(){
	LinkedList* lis=init();
	append(lis,3);
	append(lis,5);
	append(lis,7);
	append(lis,9);
	lis=insert(lis,1,0);
	lis=del(lis,0);
	travel(lis);
	
	return 0;
}
