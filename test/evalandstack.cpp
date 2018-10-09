#include"stdio.h"
typedef  struct{
	int elem[1000];
	//#set stack space                                                                  
	//in this case we use top and base as the pointer
	int top;
	int base; 
}Stack;
//forgive me that i really do not use c language
//and ofcourse i do not use pointer
Stack init(Stack s){
	s.top=0;
	s.base=0;//this do not change 
	return s;
}
Stack push(Stack s,int ele){
	s.elem[s.top]=ele;
	s.top+=1;
	return s;
}
Stack pop(Stack s){
	s.elem[s.top]=0xffffff;//#我忘了预定义怎么写 
	s.top-=1;
	return s;
}
int getTop(Stack s){
	int temp=s.elem[s.top-1];
	return temp;
}
void showElements(Stack s){
	for(int i=0;i<s.top;i++){
		printf("%d\n",s.elem[i]);
	}
}
void showElementsAsChar(Stack s){
	for(int i=0;i<s.top;i++){
		printf("%c\n",s.elem[i]);
	}
}
int toInt(char c){
	if(c=='1')return 1;
	if(c=='2')return 2;
	if(c=='3')return 3;
	if(c=='4')return 4;
	if(c=='5')return 5;
	if(c=='6')return 6;
	if(c=='7')return 7;
	if(c=='8')return 8;
	if(c=='9')return 9;
	if(c=='0')return 0;
	else return -1;
	//printf("input with a ilegal number mother fucker\n");
}
int len(char * str){
	int i=0;
	while(1){
		if(str[i]=='\0'){//呵呵 
			return i;	
		}
		i+=1;
	}
} 
int stackEmpty(Stack s){
	if(s.base==s.top){
		return 1;
	}else{
		return 0; //没有boolean 只能这么先代替了 
	}
}
char * subString(char* str,int from,int to){//模拟切片 
	char s_temp[to-from];
	for(int i=from;i<to;i++){
		//+号不能拼接字符串我也就忍了 你不能拼接字符还那么多事情搞啥 
		if(str[i]=='\0')break;
		s_temp[i-from]=str[i];
	}
	return s_temp; 
}
int pow(int a,int b){
	if(b==0)return 1;
	if(b==1)return a;
	else return a*pow(a,b-1);
}
char * toString(int num){
	int pow(int a,int b);
	char str[8];
	int j=0;
	for(int i=8;i>=0;i--){
		int temp=num/pow(10,i);
		//printf("%d\n",temp%10);//个位数
		int n=temp%10;
		if(n==0){
			if(j>0){
				str[j++]='0';
			}
		}
		if(n==1)str[j++]='1';
		if(n==2)str[j++]='2';
		if(n==3)str[j++]='3';
		if(n==4)str[j++]='4';
		if(n==5)str[j++]='5';
		if(n==6)str[j++]='6';
		if(n==7)str[j++]='7';
		if(n==8)str[j++]='8';
		if(n==9)str[j++]='9';
	}
	printf(str);
	return str; 
}
char getRelation(char a,char b){
	char list[7][7]={
	{'>','>','<','<','<','>','>'},
	{'>','>','<','<','<','>','>'},
	{'>','>','>','>','<','>','>'},
	{'>','>','>','>','<','>','>'},
	{'<','<','<','<','<','=',' '},
	{'>','>','>','>',' ','>','>'},
	{'<','<','<','<','<',' ','='},
	};
	char * std="+-*/()#"; 
	int a_index;
	int b_index;
	for(int i=0;i<len(std);i++){
		if(std[i]==a)a_index=i;
		if(std[i]==b)b_index=i;
	}
	//printf("index=%d,%d\n",a_index,b_index);
	char step_op=list[a_index][b_index];//this char gives the relation
	//printf("op_step=%c\n",step_op);
	return step_op;
}
int evalSimpleVersion(char *str,Stack s,Stack op){
	int i=0;
	while(i<len(str)){
		//printf("%c\n",str[i]);
		if(toInt(str[i])==-1){
			if(i==0){
				op=push(op,str[i]);//add # to stack op
			}else{//add or not
			while(i<len(str)||getTop(op)!='#'){
				char op_top=getTop(op);
				char next_char=str[i];
				//printf("op_top=%c,next_char=%c\n",op_top,next_char); 
				char step_op=getRelation(op_top,next_char);
				if(step_op=='>'){
					op=pop(op);
					int a=getTop(s);
					s=pop(s);
					int b=getTop(s);
					s=pop(s);
					if(op_top=='+')s=push(s,b+a);
					if(op_top=='-')s=push(s,b-a);
					if(op_top=='*')s=push(s,b*a);
					if(op_top=='/')s=push(s,b/a);
				}
				if(step_op=='<'){
					op=push(op,str[i]);
					break;//移进 
				}
				if(step_op=='='){
					if(op_top=='('&&next_char==')'){
						op=pop(op);
						break;
					}
					//归约 
				}
			}//while inside
		}
		}else{
			s=push(s,toInt(str[i]));
		}
		i+=1;
		if(i>=len(str)-1){
			break;
		}
	}//while
	while(getTop(op)!='#'){
		char op_top=getTop(op);
		char next_char=str[i];
		//printf("op_top=%c,next_char=%c\n",op_top,next_char); 
		char step_op=getRelation(op_top,next_char);
		if(step_op=='>'){
			op=pop(op);
			int a=getTop(s);
			s=pop(s);
			int b=getTop(s);
			s=pop(s);
			if(op_top=='+')s=push(s,b+a);
			if(op_top=='-')s=push(s,b-a);
			if(op_top=='*')s=push(s,b*a);
			if(op_top=='/')s=push(s,b/a);
		}
		if(step_op=='<'){
			op=push(op,str[i]);
			break;//移进 
		}
	}
	return getTop(s);
} 
int main(){
	char * str="#((3-7)+1)*(2-1)*(4-9/3+2)#";
	printf(str);
	printf("\n");
	Stack s;
	Stack op; 
	s=init(s);
	op=init(op);
	//input into stack 
	int res=evalSimpleVersion(str,s,op);
	printf("%d",res);
	return 0;
}
