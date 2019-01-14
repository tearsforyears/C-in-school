#include<iostream>
#include<stdlib.h>
#define n 3 //�ڼ������ 
#define m 3 //��Ӧ�� 
#define MAXINT 100000
using namespace std;
struct NodeType{//���ȶ��нڵ� 
    int *mark;    //��ǰѡ�� 
    int preview;    //��ǰ���򲿼�����+δ������������
    int now;    //��ǰ������Ĳ���
    int nowd;    //��ǰ���򲿼��۸�
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
int future[n];//�����겿��i��ʣ�ಿ��������������(���׶�����ʣ��̰����Сֵ)
int best_weight=MAXINT;    //��¼��С����
int cur_select[n]; 	//��ǰѡ�� 
void bfs(int *future){
    NodeType *h,*temp;//h ��ͷ��� temp����ʱ���� 
    
	//�ֶ���ʼ��ָ�� 
	h=temp=(NodeType *)malloc(sizeof(NodeType));
	temp->mark=new int[n];
	temp->preview=future[0]+w[0][0];
	temp->now=0;			
	temp->nowd=c[0][0]; 
	temp->mark[0]=0;
	temp->next=NULL;
	 

    NodeType *minp,*q;//minp����С��� q����ʱ���� 
    while(h!=NULL){
        int min=best_weight;
        q=h;
        while(q!=NULL){        
            if(q->preview<min){
                min=q->preview;
                minp=q;
				//��������С�Ľڵ� 
            }
            q=q->next;//q++
        }
        for(int i=0;i<m;i++){//������Ӧ�� 
            if(minp->nowd+c[minp->now+1][i]<=d){//���Թ�����һ��� 
                //���ɽڵ� 
				temp=(NodeType *)malloc(sizeof(NodeType));
                temp->mark=new int[n];
                temp->preview=0;
                
				temp->now=minp->now+1;    //��ǰ������Ĳ���Ϊ����minp->now+1
				
                for(int j=0;j<temp->now;j++){
                	temp->preview+=w[j][minp->mark[j]];
				} 
                temp->preview+=w[temp->now][i];   
                temp->preview+=future[temp->now];    //�����֧���޵ĺ�������̰��ֵ 
                temp->nowd=minp->nowd+c[temp->now][i];//�����֧���޵ĺ����۸�
                
                for(int j=0;j<temp->now;j++){
                	temp->mark[j]=minp->mark[j];//������С�ڵ��ѡ�� 
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
                    h->next=temp;//�������
                    h=h->next;
                }
            }    
        }
        
        if(minp==h){//��չ���Ϊͷ��� 
            h=h->next;
            free(minp);
        }
        if(h->preview>=best_weight){//�õ����Ž�����ѭ��
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
    //̰��,���׶���С 
	for(int i=0;i<n-1;i++){
       	future[i]=0;
       	for(int j=i+1;j<n;j++){
			future[i]+=future[j];
	   	}
    }
    future[n-1]=0;
    //�����겿��i��ʣ�ಿ��������������
    bfs(future);
    return 0;
}
