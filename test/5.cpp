#include"stdio.h"

int main(){
	int a=5;
	int n=111;
	int m=10;
	for(int i=0;i<n;i++){
		a=a*a%m;
	}
	printf("%d\n",a);
	return 0;
}
