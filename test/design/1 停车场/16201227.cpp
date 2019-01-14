#include<iostream>
#include<stdlib.h>
using namespace std;
#define n 2
typedef struct Stack{
	int data[1000]; //˳��ṹ
	int top;
	int botton;
}Stack;
typedef struct LinkedQueue{
	LinkedQueue* next;
	int data;
}LinkedQueue;
LinkedQueue* init(){
	LinkedQueue* pHead = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	if(NULL==pHead){
		cout<<"error";
        exit(-1);
	}
	pHead->next=NULL;
	return pHead;
}
int len(LinkedQueue* queue){
	LinkedQueue* temp=queue;
	int i=0;
	while((temp=temp->next)!=NULL)i++;
	return i;
}
void in(LinkedQueue* queue,int data){
	if(queue->next==NULL){
		queue->data=data;
		queue->next=init();
	}else{
		in(queue->next,data);
	}
}
LinkedQueue* out(LinkedQueue* queue){
	return queue->next;
}
void travel(LinkedQueue* queue){
	if(queue->next==NULL){
		cout<<endl;
		return;
	}else{
		cout<<queue->data<<",";
		travel(queue->next);
	}
}
LinkedQueue* del_from_queue(LinkedQueue* queue,int data){
	LinkedQueue* head=queue;//head
	LinkedQueue* temp=queue->next;
	if(head->data==data){
		return out(queue);
	}else{//not head
		while(temp!=NULL){
			if(temp->data==data){
				head->next=out(temp);
				return queue;
			}
			temp=temp->next;
			head=head->next;
		}
	}
	return queue;
}
//����Ϊջ��api
Stack initStack(){
	Stack s;
	for(int i=0;i<1000;i++)s.data[i]=-1;
	s.top=0;
	s.botton=0;
	return s;
}
Stack push(Stack s,int data){
	if(s.top<0||s.top-s.botton>=n){
		cout<<"error with the stack"<<endl;
	}else{
		s.data[s.top]=data; 
		s.top=s.top+1;
	}
	return s;
}
/*
Stack pop(Stack s){
	if(s.top-s.botton==0){
		cout<<"error with the stack"<<endl;
	}else{
		s.top=s.top-1;
		s.data[s.top]=-1;	
	}
	return s;
}*/

//����Ϊͣ���� 
void UI(){
	//���ݽṹ 
	Stack times=initStack();//ͣ������ʱ 
	Stack cars=initStack();//ͣ�����ǳ��ƺ� 
	LinkedQueue* wait_queue=init(); 
	int scount=0; 
	int qcount=0; //ͣ�����͵ȴ����г���
	cout<<"���� ���� ����"<<endl; 
	cout<<"�������ָ���ʽ 1.A ���� ʱ��2.D ���� ʱ��3.E 0 0"<<endl; 
	while(true){
		char op;//���� 
		int car_name;
		int time;
		cin>>op>>car_name>>time;
		if(op=='A'){//���� 
			if(scount<n){//��ջ(ͣ����)
				cars=push(cars,car_name);
				times=push(times,time); 
				scount++;
				cout<<"��������ͣ��ͣ����λ��Ϊ"<<scount<<endl; 
			}else{//���ȴ����� 
				in(wait_queue,car_name);
				qcount++;
				cout<<"���������ȴ�λ��Ϊ"<<qcount<<endl;
			}
		}else if(op=='D'){
			if(scount>0){
				for(int i=0;i<scount;i++){
					if(cars.data[i]==car_name){//�ҵ�����ջ���� 
						cout<<"�˳�ͣ��ʱ��Ϊ:"<<time-times.data[i]<<endl;
						//�޸�ջ��ջ��ɾ��һ��Ԫ�� 
						for(int j=i+1;cars.data[j]!=-1;j++){
							//��ǰŲ,����˳��ջ���� 
							cars.data[j-1]=cars.data[j];
							times.data[j-1]=times.data[j];
						}
						cars.top-=1;
						times.top-=1;
						scount--;
						//������ջ
						if(qcount>0){//�����ж�����Ҫ��stack 
							int car_name_=wait_queue->data;
							wait_queue=out(wait_queue);
							qcount--;
							cars=push(cars,car_name_);
							times=push(times,time);
							scount++;
						}
						break;
					}
					if(i+1==scount){//�ҵ�������ջ����,�����ڶ��г���ɾ�� 
						wait_queue=del_from_queue(wait_queue,car_name);
						//del_from_queue ����������ɾ��,û�о�ʲôҲ���� 
					} 
				}
			}else{
				cout<<"ͣ�����յĲ����Ƴ�����"<<endl;
			}
		}else if(op=='E'){
			break;
		}
	}

}

int main(){
	UI();
	return 0;
}
