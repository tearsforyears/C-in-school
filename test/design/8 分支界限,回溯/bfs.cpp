#include<iostream>
#include<stdlib.h>
#define n 3 //第几个零件 
#define m 3 //供应商 
#define MAXINT 100000
using namespace std;
struct NodeType{//优先队列节点 
    int *mark;    //当前选择 
    int preview;    //当前已买部件重量+未来最理想重量
    int now;    //当前考虑买的部件
    int nowd;    //当前已买部件价格
    struct NodeType* next;
};
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
int future[n];//购买完部件i后剩余部件的最理想重量(各阶段往后剩余贪心最小值)
int best_weight=MAXINT;    //记录最小重量
int cur_select[n]; 	//当前选择 
void bfs(int *future){
    NodeType *h,*temp;//h 是头结点 temp是临时变量 
    
	//手动初始化指针 
	h=temp=(NodeType *)malloc(sizeof(NodeType));
	temp->mark=new int[n];
	temp->preview=future[0]+w[0][0];
	temp->now=0;			
	temp->nowd=c[0][0]; 
	temp->mark[0]=0;
	temp->next=NULL;
	 

    NodeType *minp,*q;//minp是最小结点 q是临时变量 
    while(h!=NULL){
        int min=best_weight;
        q=h;
        while(q!=NULL){        
            if(q->preview<min){
                min=q->preview;
                minp=q;
				//找重量最小的节点 
            }
            q=q->next;//q++
        }
        for(int i=0;i<m;i++){//遍历供应商 
            if(minp->nowd+c[minp->now+1][i]<=d){//尝试购买下一零件 
                //生成节点 
				temp=(NodeType *)malloc(sizeof(NodeType));
                temp->mark=new int[n];
                temp->preview=0;
                
				temp->now=minp->now+1;    //当前考虑买的部件为部件minp->now+1
				
                for(int j=0;j<temp->now;j++){
                	temp->preview+=w[j][minp->mark[j]];
				} 
                temp->preview+=w[temp->now][i];   
                temp->preview+=future[temp->now];    //计算分支界限的函数重量贪心值 
                temp->nowd=minp->nowd+c[temp->now][i];//计算分支界限的函数价格
                
                for(int j=0;j<temp->now;j++){
                	temp->mark[j]=minp->mark[j];//复制最小节点的选择 
				} 
                temp->mark[temp->now]=i; 
                temp->next=NULL;
                
                if(temp->now+1==n&&temp->preview<best_weight){
                    best_weight=temp->preview;
                    for(int j=0;j<n;j++){
                    	cur_select[j]=temp->mark[j];
                    }
                    free(temp);            
                }else if(temp->nowd<=d){
                    h->next=temp;//加入队列
                    h=h->next;
                }
            }    
        }
        
        if(minp==h){//拓展结点为头结点 
            h=h->next;
            free(minp);
        }
        if(h->preview>=best_weight){//得到最优解跳出循环
            h=NULL;  
        }
    }
    
    cout<<"best_weight:"<<best_weight<<endl;
    cout<<"best_weight:";
	for(int i=0;i<n;i++)
		cout<<cur_select[i]<<",";
    cout<<endl;
}
int main(){  
    for(int i=0;i<n;i++){
    	int min=MAXINT;
    	for(int j=0;j<m;j++){
    		if(min>w[i][j]){
    			min=w[i][j];	
    		}	
    	}
		future[i]=min;
    }
    //贪心,各阶段最小 
	for(int i=0;i<n-1;i++){
       	future[i]=0;
       	for(int j=i+1;j<n;j++){
			future[i]+=future[j];
	   	}
    }
    future[n-1]=0;
    //求购买完部件i后剩余部件的最理想重量
    bfs(future);
    return 0;
}
