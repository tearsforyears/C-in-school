#include"stdio.h"
#define N 3
int arr[1<<N][N]={0};
void f(int n){
	if(n==1){
        arr[0][0] = 0;
        arr[1][0] = 1;
        return;
    }
	int len=1<<n;
	for(int i=0;i<len/2;i++){
		arr[i][n-1]=0;
		arr[len-1-i][n-1]=1;	
	}
	f(n-1);//只有前半部分进行了01填充要对其进行反转 
    for(int i=len/2;i<len;i++){
    	for(int j=0; j<n-1; j++){
    		arr[i][j]=arr[len-i-1][j]; //对剩下的所有行进行对称反转 
    	}
	}
	//其实有更简单的填充规律 01|10 0011|1100 00001111| 完全可以得到矩阵的推算表达式 
}
int main(){
	f(N);
	for(int i=0;i<1<<N;i++){
		for(int j=0;j<N;j++){
			printf("%d,",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
