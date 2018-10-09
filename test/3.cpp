#include"stdio.h"
#include"string.h"

int ctoi(char a){
	if(a=='0')return 0;
	if(a=='1')return 1;
	if(a=='2')return 2;
	if(a=='3')return 3;
	if(a=='4')return 4;
	if(a=='5')return 5;
	if(a=='6')return 6;
	if(a=='7')return 7;
	if(a=='8')return 8;
	if(a=='9')return 9;
}
int judge(char *num){
	int t=ctoi(num[0]);
	for(int i=1;i<strlen(num);i++){
		if(t!=10)t=(t*10+ctoi(num[i]))%11;
		else t=(t+ctoi(num[i]))%11;
	}
	if(t==0){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	char* num1="208275335202";
	char* num2="123";
	int res=judge(num2);
	printf("%d",res);
}  
