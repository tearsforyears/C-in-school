#include<iostream>
#include<stdlib.h>
using namespace std;
#define n 2
typedef struct Stack{
	int data[1000]; //顺序结构
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
//以下为栈的api
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

//以下为停车场 
void UI(){
	//数据结构 
	Stack times=initStack();//停车场计时 
	Stack cars=initStack();//停车场记车牌号 
	LinkedQueue* wait_queue=init(); 
	int scount=0; 
	int qcount=0; //停车场和等待队列长度
	cout<<"车来 车走 结束"<<endl; 
	cout<<"输入操作指令格式 1.A 车牌 时间2.D 车牌 时间3.E 0 0"<<endl; 
	while(true){
		char op;//操作 
		int car_name;
		int time;
		cin>>op>>car_name>>time;
		if(op=='A'){//到来 
			if(scount<n){//进栈(停车场)
				cars=push(cars,car_name);
				times=push(times,time); 
				scount++;
				cout<<"上述车辆停入停车场位置为"<<scount<<endl; 
			}else{//进等待队列 
				in(wait_queue,car_name);
				qcount++;
				cout<<"上述车辆等待位置为"<<qcount<<endl;
			}
		}else if(op=='D'){
			if(scount>0){
				for(int i=0;i<scount;i++){
					if(cars.data[i]==car_name){//找到车在栈里面 
						cout<<"此车停的时间为:"<<time-times.data[i]<<endl;
						//修改栈从栈中删除一个元素 
						for(int j=i+1;cars.data[j]!=-1;j++){
							//往前挪,利用顺序栈特性 
							cars.data[j-1]=cars.data[j];
							times.data[j-1]=times.data[j];
						}
						cars.top-=1;
						times.top-=1;
						scount--;
						//出队入栈
						if(qcount>0){//队列有东西才要进stack 
							int car_name_=wait_queue->data;
							wait_queue=out(wait_queue);
							qcount--;
							cars=push(cars,car_name_);
							times=push(times,time);
							scount++;
						}
						break;
					}
					if(i+1==scount){//找到车不在栈里面,可能在队列尝试删除 
						wait_queue=del_from_queue(wait_queue,car_name);
						//del_from_queue 有这辆车就删除,没有就什么也不做 
					} 
				}
			}else{
				cout<<"停车场空的不能移除车辆"<<endl;
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
