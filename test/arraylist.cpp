#include"stdio.h"
#include"string.h"
typedef struct {
    char* num; //String  
    char* name; 
    int price;     
}Student;
typedef  struct{
	Student elem[100];    
	int length;                                                                  
}SqList;
//������ָ�� ָ�붼�Ǵ�����õĻ���->��д�����Ҳ�֪���� 
//һ��ָ��͸������ô���Ⱦ���˷������� ��ѧ�� �������� 
int main(){
	/*define*/
	//û��̬���������ڲ��Ե�ʱ��ӽ����� 
	SqList init(SqList a,int len);
	void show_all(SqList a);
	void show_Index(SqList a,int index);
	int count(SqList a);
	void show_IndexByName(SqList a,char* name);
	SqList append(SqList a,Student s1);
	SqList del_ByIndex(SqList a,int index);
	SqList insert(SqList a,int index,Student s1);	
	
	/*process*/	
	SqList a;
	int n=5;
	Student s1;
	s1.name="tomcat and java web";
	s1.num="sin(1.17)";
	s1.price=581;
	//��ʼ�����ֲ����ò���
	
	 
	printf("---------init----------\n");
	a=init(a,n); //�����޸ı�ṹ�Ķ����з���ֵ 
	show_all(a);
	printf("---------1----------\n");
	show_Index(a,1);
	printf("----------2---------\n");
	show_IndexByName(a,"aa");
	printf("-------------------\n");
	show_IndexByName(a,"aaada");
	printf("-----------3--------\n");	
	a=append(a,s1);
	show_all(a);
	printf("----------4---------\n");	
	a=del_ByIndex(a,1);
	show_all(a);
	printf("----------5---------\n");	
	a=insert(a,2,s1);
	show_all(a);
	printf("all of the function can work\n");
	//�����ٰ�����ָ�붼�׿������������ִ���� 
	return 0;	
}
SqList insert(SqList a,int index,Student s1){
	for(int i=a.length;i>index;i--){ 
	//������Ψһһ���ѵ� �Ӻ���ǰ���� ����͵����쳣�� ������ĺ�dp��ĳЩ��һ���� 
		a.elem[i].name=a.elem[i-1].name;
		a.elem[i].num=a.elem[i-1].num;
		a.elem[i].price=a.elem[i-1].price;
	}
	//����indexλ��
	
	a.elem[index].name=s1.name;
	a.elem[index].num=s1.num;
	a.elem[index].price=s1.price; 
	a.length+=1;
	return a;
} 
SqList del_ByIndex(SqList a,int index){
	for(int i=index+1;i<a.length;i++){//��󸲸� 
		a.elem[i-1].name=a.elem[i].name; 
		a.elem[i-1].num=a.elem[i].num;
		a.elem[i-1].price=a.elem[i].price;
	}
	a.length-=1;
	return a;
}
SqList append(SqList a,Student s1){
	a.elem[a.length].name=s1.name; 
	a.elem[a.length].num=s1.num;
	a.elem[a.length].price=s1.price;
	a.length+=1;
	return a; 
}
void show_IndexByName(SqList a,char* name){
	int flag=0;//����flag 
	for(int i=0;i<a.length;i++){
		if(strcmp(name,a.elem[i].name)==0){
			printf("name: %s ",a.elem[i].name); 
			printf("num: %s ",a.elem[i].num);
			printf("price: %d ",a.elem[i].price);
			printf("\n");
			flag=1;
		}
	}
	if(flag==0){
		printf("the people who with the name ");
		printf(name);
		printf(" is not exist\n");
	}
}
void show_Index(SqList a,int index){
	printf("index: %d ",index);
	printf("name: %s ",a.elem[index].name); 
	printf("num: %s ",a.elem[index].num);
	printf("price: %d \n",a.elem[index].price);
}
void show_all(SqList a){
	for(int i=0;i<a.length;i++){
		printf("index: %d",i);
		printf("name: %s ",a.elem[i].name); 
		printf("num: %s ",a.elem[i].num);
		printf("price: %d\n ",a.elem[i].price);
	}
}
int count(SqList a){
	printf("%d\n",a.length);
	return a.length;
}
SqList init(SqList a,int len){
	if(len>=100){
		printf("length is to long\n");
	}else{
		for(int i=0;i<len;i++){
			a.elem[i].name="aaada";
			a.elem[i].num="16104321";//��֪��apiû������������� 
			a.elem[i].price=59; 
		}//�������� ������������ 
		printf("it works by init function\n");
	}
	a.length=len;
	return a;
}
	
