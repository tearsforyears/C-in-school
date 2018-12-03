#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

typedef struct BiTree{
	BiTree* left;
	BiTree* right;
	int data;
}BiTree;

BiTree* init(int rootdata){
	BiTree* root=(BiTree*)malloc(sizeof(BiTree));
	if(root==NULL){
		cout<<"error:init error for an binary tree"<<endl;
		exit(-1);
	}
	root->data=rootdata;
	root->left=NULL;
	root->right=NULL;
	return root;
}
BiTree* add_bin_sort(BiTree* tree,int data){ //¶þ²æÅÅÐòÊ÷ 
	if(tree!=NULL){
		if(data>=tree->data){
			tree->right=add_bin_sort(tree->right,data);	
		}else{
			tree->left=add_bin_sort(tree->left,data);	
		}
		return tree;			
	}else{
		return init(data);
	}
}
void mid_travel(BiTree* tree){
	if(tree!=NULL){
		mid_travel(tree->left);
		cout<<tree->data<<",";
		mid_travel(tree->right);
	}
}
void front_travel(BiTree* tree){
	if(tree!=NULL){
		cout<<tree->data<<",";
		mid_travel(tree->left);
		mid_travel(tree->right);
	}
}
void back_travel(BiTree* tree){
	if(tree!=NULL){
		mid_travel(tree->left);
		mid_travel(tree->right);
		cout<<tree->data<<",";
	}
}
int getHeight(BiTree* tree){
	if(tree==NULL)return 0;
	int left_h=getHeight(tree->left)+1;
	int right_h=getHeight(tree->right)+1;
	return max(left_h,right_h);
}
int getNodesNum(BiTree* tree){
	if(tree==NULL)return 0;
	return getNodesNum(tree->left)+getNodesNum(tree->right)+1;
}
int get_levaes(BiTree* tree){
	if(tree!=NULL){
		if(tree->left==NULL && tree->right==NULL)return 1;
		return get_levaes(tree->left)+get_levaes(tree->right);
	}
} 
int main(){
	BiTree* tree=init(2);
	tree=add_bin_sort(tree,3);
	tree=add_bin_sort(tree,5);
	tree=add_bin_sort(tree,7);
	tree=add_bin_sort(tree,2);
	tree=add_bin_sort(tree,1);
	mid_travel(tree);
	cout<<endl<<get_levaes(tree);
	return 0;
}
