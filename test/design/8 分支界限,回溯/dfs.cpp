#include<iostream>
#include<stdlib.h> 
#define n 3 //�ڼ������ 
#define m 3 //��Ӧ�� 
using namespace std;
int w[n][m]={
{1,2,3,},
{3,2,1,},
{2,3,4,},
};
int c[n][m]={
{1,2,3,},
{5,4,2,},
{2,1,2,},
};
int d=7;
int cur_price=0;//��ǰʹ�ü۸����ڻ����ж���
int cur_weight=0;//��ǰ���� 
int cur_select[n];//��ǰѡ�� 
int best_weight=10000;//�洢��С����
int flag[n];//���� 
void dfs(int iter){
	for(int i=0;i<m;i++){
		if(iter<n){
			if(cur_price<=d){
				cur_price+=c[iter][i];
				cur_weight+=w[iter][i];
				cur_select[iter]=i;
				dfs(iter+1);
				cur_select[iter]=0;//���� 
				cur_price-=c[iter][i];//���� 
				cur_weight-=w[iter][i];//���� 
			}
		}else{//iter==n means it done
			if(best_weight<cur_weight){
				//pass 
			}else{
				best_weight=cur_weight;
				for(int i=0;i<n;i++)flag[i]=cur_select[i]; 
			}
		}
	}
}
int main(){
	dfs(0);//���� 
	cout<<"best weight:"<<best_weight<<endl;
	cout<<"best select:"; 
	for(int i=0;i<n;i++)
		cout<<flag[i]<<",";
	cout<<endl;
	return 0;
}
