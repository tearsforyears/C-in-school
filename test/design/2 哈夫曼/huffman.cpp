#include<iostream>
#include<stdlib.h>
#include<string>
#include <fstream>
#include <sstream>
#define n 26 //编码26个字母 
#define max_int 0xffffff
using namespace std;

int count[n]; //记录具体的值 
int flag[n]; //记录节点是否被访问过
typedef struct BiTree{ 
	BiTree* left;
	BiTree* right;
	int data;
	char ch; 
}BiTree;
BiTree* nodes[n];
BiTree* init(int rootdata){
	BiTree* root=(BiTree*)malloc(sizeof(BiTree));
	if(root==NULL){
		cout<<"error"<<endl;
		exit(-1);
	}
	root->data=rootdata;
	root->ch='\0';
	root->left=NULL;
	root->right=NULL;
	return root;
}
void statistics(string str){
	for(int i=0;i<str.length();i++){
		if(str[i]-'a'<n){
			count[str[i]-'a']+=1;	
		}
	}
}
int get_min_pos(BiTree* nodes[]){
	int temp=max_int;
	int pos;
	for(int i=0;i<n;i++){
		if(flag[i]!=-1){//可以访问
			if(temp>count[i]){
				temp=count[i];
				pos=i; //记录位置 
			}
		}
	}
	return pos; 
}
int merge(BiTree* nodes[]){
	int index1=get_min_pos(nodes);
	flag[index1]=-1;
	int index2=get_min_pos(nodes);
	//找出要合并的两个节点,合并 
	BiTree* node=init(nodes[index1]->data+nodes[index2]->data);
	node->left=nodes[index1];
	node->right=nodes[index2];
	count[index2]=nodes[index1]->data+nodes[index2]->data;
	//忘记更新count的值了,惨痛的教训,用面向对象设计应该不会犯这种低级错误 
	nodes[index2]=node;
	return index2;
}
BiTree* huffman(BiTree* nodes[]){
	int index=max_int;
	for(int i=0;i<n-1;i++){
		index=merge(nodes);
	}
	return nodes[index];
}
void printarr(BiTree* arr[]){
	for(int i=0;i<n;i++){
		cout<<arr[i]->data<<",";	
	}
	cout<<endl;
}
void mid_travel(BiTree* tree){
	if(tree!=NULL){
		mid_travel(tree->left);
		cout<<"("<<tree->data<<","<<tree->ch<<"),";
		mid_travel(tree->right);
	}
}
//编码解码部分数据机构
string test_str="abcdeacadbeadabca";
string encoding_map[n];//编码表 
string l="0";//常量 
string r="1";//常量
string record="";
void generate_encoding_map(BiTree* tree){
	//本质上是中序遍历
	if(tree!=NULL){
		record+=l; 
		generate_encoding_map(tree->left);
		record=record.substr(0,record.length()-1); //回溯 
		if(tree->ch>='a'&&tree->ch<='z'){
			encoding_map[tree->ch-'a']=record;//存储编码表 
			cout<<tree->ch<<":"<<record<<endl;//打印编码表 
		}
		record+=r;
		generate_encoding_map(tree->right);
		record=record.substr(0,record.length()-1); //回溯 
	}
}
string encoder(string str){
	string temp="";
	for(int i=0;i<str.length();i++){
		temp+=encoding_map[str[i]-'a'];
	}
	cout<<temp<<endl; 
	return temp;
}
void decoder(string str,BiTree* huffman){
	BiTree* temp_point=huffman;
	for(int i=0;i<=str.length();i++){ 
		if(str[i]==l[0]){//向左 
			if(temp_point->left==NULL){//左边没有东西,到达尽头 
				cout<<temp_point->ch;
				temp_point=huffman;//回溯
				i--; //回溯 
			}else{
				temp_point=temp_point->left;
			}
		}else{
			if(temp_point->right==NULL){
				cout<<temp_point->ch;
				temp_point=huffman;//回溯 
				i--;//回溯 
			}else{
				temp_point=temp_point->right;
			}
		}
	}

}
string readFileIntoString(char * filename){
	ifstream ifile(filename);
	//将文件读入到ostringstream对象buf中
	ostringstream buf;
	char ch;
	while(buf&&ifile.get(ch)){//ifile>>ch
		if(ch>='a'&&ch<='z'){
			buf.put(ch);//buf<<put
		} 
	}
	return buf.str();
}
int main(){
	string file_str=readFileIntoString("test.txt");
	//read file as string into a string type variable
	statistics(file_str);//统计频度 
	for(int i=0;i<n;i++){
		nodes[i]=init(count[i]);
		nodes[i]->ch='a'+i;
	}
	printarr(nodes);
	BiTree* h_tree=huffman(nodes);//生成huffman树 
	generate_encoding_map(h_tree);//生成编码表
	string encode_str=encoder(file_str);//编码 
	decoder(encode_str,h_tree);//解码 
	return 0;
}      
	

