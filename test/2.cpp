#include"stdio.h"
int gcd(int a,int b){
	if(a%b==0)return b;
	return gcd(b,a%b);
}
int main(){
	int a=4,b=6;
	int res=gcd(a,b);
	printf("%d/%d->%d/%d",a,b,a/res,b/res);
	return 0;
} 
