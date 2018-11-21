#include"stdio.h"
#include"string.h"
int bf(char * str1,char * str2){
	for(int i=0;i<strlen(str1)-strlen(str2);i++){
		for(int j=0;j<strlen(str2);j++){
			if(str1[i+j]!=str2[j]){
				break;
			}
			if(j==strlen(str2)-1){
				printf("%d\n",i);
				return 1;
			}
		}
	}
	return 0;
}

//实现page53 关于next值的求法
void getnext(char * str,int next[]){
	next[0]=-1;
	for(int j=1;j<strlen(str);j++){
		int k=next[j-1];
		while(str[k]!=str[j-1] && k!=-1){
			k=next[k];
		}
		if(k==-1){
			next[j]=0;
		}else{
			next[j]=k+1;
		}
	}
}
int kmp(char * str1,char *str2){
	int next[strlen(str2)];
	getnext(str2,next);
	int i=0,j=0;
	while(str1[i]!='\0' && str2[j]!='\0'){
		if(str1[i]==str2[j]){
			i++;
			j++;
		}else{
			j=next[j];
			if(j==-1){
				i++;
				j++;
			}
		}
	}
	if(str2[j]=='\0')return i-strlen(str2)+1;
	else return 0;
}
int main(){
	char * str1="ababaababcb";
	char * str2="ababc";	
	int res=kmp(str1,str2); 
	printf("%d",res); 
	//int res=bf(str1,str2);
	return 0;
}

