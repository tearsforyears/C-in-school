#include"stdio.h"
#define LEN 7
void sort(int a[], int left, int right){
	if(right<=left){
		return;
	}
    int i=left;
    int j=right;
    int key=a[left];
    while(i<j)
    {
        while(i<j && key<=a[j]){
            j--;
        } 
        a[i] = a[j];
        while(i<j && key>=a[i]){
            i++;
        }
        a[j]=a[i];
    }
    a[i]=key;// i==j 
    sort(a,left,i-1);
    sort(a,i+1,right);
}
int f(int lis[]){
	sort(lis,0,LEN);
	int res=0xffffff;// inf
	int x1=0xffffff,x2=0xffffff;// nan 
	for(int i=0;i<LEN-1;i++){
		int temp=lis[i+1]-lis[i];
		if(temp<res){
			res=temp;
			x1=lis[i];
			x2=lis[i+1];
		}
	}
	printf("x1=%d,x1=%d,distant=%d",x1,x2,res);
	return 0;	
}
int main(){
	int lis[LEN]={11,2,3,5,-10,9,10}; 
	f(lis);
	return 0;
}
