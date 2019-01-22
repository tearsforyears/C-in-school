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
	LinkedList* temp=lis;
	while(temp->next!=NULL){
		cout<<temp->data<<",";
		temp=temp->next;
	}
	cout<<endl;
}
void travel_inv(LinkedList* lis){
	if(lis->next==NULL){
		return;
	}else{
		travel_inv(lis->next);
		cout<<lis->data<<",";
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
LinkedList* delete_from_back_v1(LinkedList* lis,int back){
	return del(lis,len(lis)-back);
}
LinkedList* getLastNode(LinkedList* a){
	LinkedList* node = a;
	while(node->next!=NULL)node=node->next;
	return node;
}
LinkedList* mergeLinkedList(LinkedList* a,LinkedList* b){
	//the core of merge sort 
	LinkedList* point1=a;
	LinkedList* point2=b;
	LinkedList* new_list = init();
	while(point1->next!=NULL && point2->next!=NULL){
		if(point1->data<=point2->data){
			append(new_list,point1->data);
			point1=point1->next;	
		}else{
			append(new_list,point2->data);
			point2=point2->next;
		}
	}
	if(point1->next==NULL){
		append(new_list,point2->data);
	}else{ //point=NULL
		append(new_list,point1->data);
	}
	return new_list;
}
/*
LinkedList* inverse(LinkedList* lis){
	LinkedList* p=lis;
	LinkedList* new_list=init();
	while(p->next!=NULL){
		new_list=insert(new_list,p->data,0);
		p=p->next;
	}
	return new_list;	
}*/
LinkedList* inverse(LinkedList* lis){
	LinkedList *prev=NULL;
	LinkedList *temp=NULL; //only for cache
	LinkedList *head=init();
	head->next=lis;
	while(head){
		temp=head->next; //cache
		head->next=prev;
		prev=head;
		head=temp;
	}	
	return prev->next;
}
int main(){
	LinkedList* lis=init();
	append(lis,1);
	append(lis,2);
	append(lis,4);
	append(lis,8);
	append(lis,6);
	append(lis,9);
	append(lis,11);
	travel(lis);
	lis=inverse(lis);
	travel(lis);
	return 0;
}
