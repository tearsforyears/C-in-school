#include"stdio.h"
int main(){
	int min_value1=*(0x100);
	int min_value2=*(0x101);
	for(int i=0x100;i<=0x109;i+=2){
		*(i)<min_value1?min_value1=*(i):;
	}// 存储高位最小值
	for(int i=0x100;i<=0x109;i+=2){
		if(*(i)==min_value){
			*(i+1)<min_value2?min_value2=*(i+1):;
		}
	}// 存储低位最小值
	
}

