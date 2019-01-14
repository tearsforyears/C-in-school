#include<iostream>
#include<stdlib.h>
using namespace std;
#define n 2
typedef struct Stack{
	int data[1000]; //顺序结构
	int top;
	int botton;
}Stack;
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
	if(pos>=len(lis))cout<<"error:list index out of range"<<endl;
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
int get_pos(LinkedList* lis,int data){
	LinkedList* top=lis;
	int temp=top->data;
	int count=0;
	while((top=top->next)!=NULL){
		if(temp==data){
			return count;
		}
		temp=top->data;
		count++;
	}
	if(count>=len(lis)){
		return -1;
	}
	return count;
}
//因为以前开发过linkedlist数据结构,所以删除一部分api直接拿过来用了
//以下为队列的api 
void in(LinkedList* lis,int data){
	append(lis,data);
}
LinkedList* out(LinkedList* queue){
	if(len(queue)==0){
		cout<<"length out of index"<<endl;
	}else{
		return del(queue,0);
	}
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
//以下为模拟逻辑
void cmd_line(){
	//A 到达 D 离去 E 结束 
	//数据结构 
	Stack park_time=initStack();
	Stack park_cars=initStack();
	LinkedList* wait_queue=init(); 
	int stack_count=0; //加快判断简化逻辑 、
	int queue_count=0; 
	
	while(true){
		char op;//操作 
		int car_name;
		int time;
		cin>>op>>car_name>>time;
		if(op=='A'){//到来 
			if(stack_count<n){//进栈(停车场)
				park_cars=push(park_cars,car_name);
				park_time=push(park_time,time); 
				cout<<"enter the stack with position"<<stack_count<<endl;
				stack_count++;
			}else{//进等待队列 
				in(wait_queue,car_name);
				cout<<"enter the queue with position"<<queue_count<<endl;
				queue_count++; 
			}
		}else if(op=='D'){
			if(stack_count>0){
				for(int i=0;i<stack_count;i++){ 
					//这里本可以弄个api去查找 
					if(park_cars.data[i]==car_name){//核心决策 
						//找到这么一个元素,在停车场的话要收费
						//还得出栈,顺便还要让等待队列队头入栈
						int cost_time=time-park_time.data[i];
						cout<<"the car cost"<<cost_time<<endl;
						for(int j=i+1;park_cars.data[j]!=-1;j++){
							//往前挪,pop不需要
							park_cars.data[j-1]=park_cars.data[j];
							park_time.data[j-1]=park_time.data[j];
						}
						park_cars.top-=1;
						park_time.top-=1;
						stack_count--;
						//出队入栈
						if(queue_count>0){
							int car_name_=wait_queue->data;
							wait_queue=out(wait_queue);
							park_cars=push(park_cars,car_name_);
							park_time=push(park_time,time);
							stack_count++;
							queue_count--; 
						}
						break;
					}
					if(i+1==stack_count){
						if(get_pos(wait_queue,car_name)!=-1){
							wait_queue=del(wait_queue,get_pos(wait_queue,car_name));
						}
					}
				}
			}else{
				cout<<"empty car"<<endl;
			}
		}else if(op=='E'){
			break;
		}
	}

}

int main(){
	cmd_line();
	return 0;
}
