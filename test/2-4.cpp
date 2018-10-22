#include"stdio.h"
#define playernum 32
void f(){
	int count=1;
	for(int i=0;i<playernum;i++){
		for(int j=i+1;j<playernum;j++){
			printf("day %d,player%d vs player%d\n",count,i,j);
			count++;
		}
	}
}
int main(){
	f();
	return 0;
}
