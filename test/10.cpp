#include"stdio.h"
#include"math.h"
#define LEN 10 
void echo(double a){
	printf("%.7f\n",a);
}
int len(char * str1){
	int p=0;
	while(str1[p]!=0)p++;
	return p;
}
typedef struct data{
	double lis[LEN];
	void print(){
		for(int i=0;i<LEN;i++)
			printf("%.7f,",lis[i]);
		printf("\n");
	}
	int length(){
		return LEN; 
	}
	double max(){
		double res=-0xffffff;
		for(int i=0;i<LEN;i++)
			res>lis[i]?:res=lis[i];
		return res;
	}
	double min(){
		double res=0xffffff;
		for(int i=0;i<LEN;i++)
			res<lis[i]?:res=lis[i];
		return res;
	}
	double sum(){
		double res=0;
		for(int i=0;i<LEN;i++)res+=lis[i];
		return res;
	}
	double mean(){
		return sum()/LEN; 
	}
	double std(){
		double m=mean();
		double sstd=0.0;
		for(int i=0;i<LEN;i++)
			sstd+=(lis[i]-m)*(lis[i]-m);
		return sqrt(sstd);
	}
}Array;
int main(){
	Array arr;
	arr={{-1.0,2.0,-3.0,5.0,7.0,9.0,7.0,11.0,12.0,-10.0}};
	arr.print();
	echo(arr.std());
	return 0;
} 
