#include<iostream>
#include<stdlib.h>
#include<string>
#include <fstream>
#include <sstream>
#define n 3 //count of tel books
#define cor 100//count of record
#define rols 200//�ļ����� 
#define max_int 0xffffff
using namespace std;
typedef struct TelBook{
	string name;
	string tel;
	string work_place;
};
int len[n]={3,4,5};//������ĳ���	 
TelBook test_data[n][cor];//�绰��¼ 
string textline[rols]; //װ�ļ������� 
typedef struct BiTree{
	BiTree* left;
	BiTree* right;
	int data;//store length
	TelBook* tel;//�绰�� 
}BiTree;
BiTree* init(int rootdata){
	//��ʼ�������� 
	BiTree* root=(BiTree*)malloc(sizeof(BiTree));
	if(root==NULL){
		cout<<"error:init error for an binary tree"<<endl;
		exit(-1);
	}
	root->data=rootdata;
	root->left=NULL;
	root->right=NULL;
	root->tel=new TelBook[cor];
	return root;
}
void printarr(BiTree* arr[]){
	for(int i=0;i<n;i++){
		if(arr[i]->data!=max_int){
			cout<<arr[i]->data<<",";
		}else{
			cout<<"inf"<<",";
		}	
	}
	cout<<endl;
}
void quickSort(BiTree* a[], int low, int high){
	//����Ǩ�������� tel��data 
    if(low >= high){
        return;
    }
    int first=low;
    int last=high;
    int key=a[first]->data;
    TelBook* key_tel=a[first]->tel;
    while(first<last){
        while(first<last&&a[last]->data>=key){
            --last;
        }
        a[first]->data=a[last]->data;
        a[first]->tel=a[last]->tel;
        while(first<last&&a[first]->data<=key){
            ++first;
        }
        a[last]->data=a[first]->data;
		a[last]->tel=a[first]->tel;    
	}
    a[first]->data=key;
    a[first]->tel=key_tel;
    //�ݹ� 
    quickSort(a,low,first-1);
    quickSort(a,first+1,high);
}
void merge(BiTree* nodes[]){
	quickSort(nodes,0,n-1);//���� 
	int len=nodes[0]->data+nodes[1]->data;
	cout<<"����Ϊ"<<nodes[0]->data<<"��,�ͳ���Ϊ"<<nodes[1]->data<<"�ϲ���"<<endl;
	BiTree* node=init(len);//�½ڵ� 
	node->left=nodes[0];
	node->right=nodes[1];
	//�ϲ������绰��
	cout<<"�绰��1:"; 
	for(int k=0;k<nodes[0]->data;k++){
		cout<<nodes[0]->tel[k].name<<",";
	}
	cout<<endl;
	cout<<"�绰��2:";
	for(int k=0;k<nodes[1]->data;k++){
		cout<<nodes[1]->tel[k].name<<",";
	}
	cout<<endl;
	int i=0,j=0;//ָʾ�����绰���ĳ��� 
	while(i<nodes[0]->data && j<nodes[1]->data){//ָ���ƶ��Ϸ� 
		if(nodes[0]->tel[i].name[0]<nodes[1]->tel[j].name[0]){//��ӵ�һ����ڶ�������
			node->tel[i+j].name=nodes[0]->tel[i].name;
			i++;
		}else{
			node->tel[i+j].name=nodes[1]->tel[j].name;
			j++;
		}
	}
	if(i==nodes[0]->data){//�����һ���绰�����˾�ͷ 
		for(;j<nodes[1]->data;j++){//���ϵڶ����绰�� 
			node->tel[i+j].name=nodes[1]->tel[j].name;
		}
	}else{
		for(;i<nodes[0]->data;i++){//ͬ�� 
			node->tel[i+j].name=nodes[0]->tel[i].name;
		}
	}
	cout<<"�ϲ��绰��"<<endl;
	for(int k=0;k<len;k++){
		cout<<node->tel[k].name<<",";
	}
	cout<<endl;
	//���·����б� 
	nodes[0]=node;
	nodes[1]=init(max_int); //���ֵ,������ʵ�ֻ����
}
void mid_travel(BiTree* tree){
	if(tree!=NULL){
		mid_travel(tree->left);
		cout<<tree->data<<",";
		mid_travel(tree->right);
	}
}
BiTree* huffman(BiTree* nodes[]){
	for(int i=0;i<n-1;i++){
		merge(nodes);	
	}
	quickSort(nodes,0,n-1);
	return nodes[0];
}
int readFileIntoStringArr(char * filename){
	int i=0,ii=0;//i�ļ����� ii��ʱ���� 
	ifstream fin(filename);
	for(;!fin.eof();){//�ļ�����û��ĩβ 
	    getline(fin,textline[i],'\n');
	    i++;
	}
	return i;
}
int main(){
	readFileIntoStringArr("test.txt");
	for(int i=0,k=0;i<n;i++){//i��ͨѶ�� k���ļ����� j�Ǽ�¼ 
		for(int j=0;j<len[i];j++,k++){
			int f_point=0,l_point=0;//�ո�ָ��
			int count=1;
			for(int l=0;l<textline[k].length();l++){//l���ַ���ָ�� 
				if(textline[k][l]==','&&count==1){
					f_point=l;
					count++;
				}
				if(textline[k][l]==','&&count==2)l_point=l;//�ҷָ���λ�� 
			}
			//�ָ��ַ��� 
			test_data[i][j].name=textline[k].substr(0,f_point);
			test_data[i][j].tel=textline[k].substr(f_point+1,l_point-f_point-1);
			test_data[i][j].work_place=textline[k].substr(l_point+1);
		}
	}
	//�����������ڵ� 
	BiTree* nodes[n];
	//init datas
	for(int i=0;i<n;i++){
		nodes[i]=init(len[i]);
		nodes[i]->tel=test_data[i];
	}
	printarr(nodes);
	BiTree* h_tree=huffman(nodes);
	//mid_travel(h_tree);
	return 0;
}      
	

