#include"stdio.h"
void echo(int a){
	printf("%d",a);
}
int len(char * str1){
	int p=0;
	while(str1[p]!=0)p++;
	return p;
}
typedef struct data{
	int num;
	void print(int a){
		printf("%d",a);
		printf("\n%d",num);
	}
}Tools;
int main(){
	Tools t;
	t.num=3;
	//t.print(4);
	return 0;
} 
