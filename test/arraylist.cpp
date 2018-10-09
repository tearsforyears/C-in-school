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
//不会用指针 指针都是大神才用的还有->这写法让我不知所措 
//一用指针就各种引用错误比矩阵乘法还恶心 不学了 放弃治疗 
int main(){
	/*define*/
	//没静态方法调用在测试的时候接近崩溃 
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
	//初始化各种测试用参数
	
	 
	printf("---------init----------\n");
	a=init(a,n); //所有修改表结构的都会有返回值 
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
	//终于再把所有指针都抛开后程序完美的执行了 
	return 0;	
}
SqList insert(SqList a,int index,Student s1){
	for(int i=a.length;i>index;i--){ 
	//这里是唯一一个难点 从后向前遍历 否则就等着异常吧 这个恶心和dp中某些是一样的 
		a.elem[i].name=a.elem[i-1].name;
		a.elem[i].num=a.elem[i-1].num;
		a.elem[i].price=a.elem[i-1].price;
	}
	//覆盖index位置
	
	a.elem[index].name=s1.name;
	a.elem[index].num=s1.num;
	a.elem[index].price=s1.price; 
	a.length+=1;
	return a;
} 
SqList del_ByIndex(SqList a,int index){
	for(int i=index+1;i<a.length;i++){//向后覆盖 
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
	int flag=0;//立个flag 
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
			a.elem[i].num="16104321";//不知道api没法生成随机数了 
			a.elem[i].price=59; 
		}//填充假数据 不服可以来改 
		printf("it works by init function\n");
	}
	a.length=len;
	return a;
}
	
