#include<iostream>
#include<stdlib.h> 
#define n 3 //第几个零件 
#define m 3 //供应商 
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
int cur_price=0;//当前使用价格用于回溯判定界
int cur_weight=0;//当前重量 
int cur_select[n];//当前选择 
int best_weight=10000;//存储最小重量
int flag[n];//决策 
void dfs(int iter){
	for(int i=0;i<m;i++){
		if(iter<n){
			if(cur_price<=d){
				cur_price+=c[iter][i];
				cur_weight+=w[iter][i];
				cur_select[iter]=i;
				dfs(iter+1);
				cur_select[iter]=0;//回溯 
				cur_price-=c[iter][i];//回溯 
				cur_weight-=w[iter][i];//回溯 
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
	dfs(0);//深搜 
	cout<<"best weight:"<<best_weight<<endl;
	cout<<"best select:"; 
	for(int i=0;i<n;i++)
		cout<<flag[i]<<",";
	cout<<endl;
	return 0;
}
