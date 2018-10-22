#include"stdio.h"
int max(int l,int r,int lis[]){
	if(r-l==1){
		return lis[l]>lis[r]?lis[l]:lis[r];
	}else if(r==l){
		return lis[l];
	}else{
		return max(l,(l+r)/2,lis)>max((l+r)/2+1,r,lis)?max(l,(l+r)/2,lis):max((l+r)/2+1,r,lis);
	}
} 
int main(){
	int lis[]={1,3,5,6,9,4,5,2,3,1};
	int res=max(0,9,lis);
	printf("%d",res);
	return 0; 
}


