#include<iostream>
#include<stdlib.h>
#include<string>
#include <fstream>
#include <sstream>
#define n 26 //����26����ĸ 
#define max_int 0xffffff
using namespace std;

int count[n]; //��¼�����ֵ 
int flag[n]; //��¼�ڵ��Ƿ񱻷��ʹ�
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
		if(flag[i]!=-1){//���Է���
			if(temp>count[i]){
				temp=count[i];
				pos=i; //��¼λ�� 
			}
		}
	}
	return pos; 
}
int merge(BiTree* nodes[]){
	int index1=get_min_pos(nodes);
	flag[index1]=-1;
	int index2=get_min_pos(nodes);
	//�ҳ�Ҫ�ϲ��������ڵ�,�ϲ� 
	BiTree* node=init(nodes[index1]->data+nodes[index2]->data);
	node->left=nodes[index1];
	node->right=nodes[index2];
	count[index2]=nodes[index1]->data+nodes[index2]->data;
	//���Ǹ���count��ֵ��,��ʹ�Ľ�ѵ,������������Ӧ�ò��᷸���ֵͼ����� 
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
//������벿�����ݻ���
string test_str="abcdeacadbeadabca";
string encoding_map[n];//����� 
string l="0";//���� 
string r="1";//����
string record="";
void generate_encoding_map(BiTree* tree){
	//���������������
	if(tree!=NULL){
		record+=l; 
		generate_encoding_map(tree->left);
		record=record.substr(0,record.length()-1); //���� 
		if(tree->ch>='a'&&tree->ch<='z'){
			encoding_map[tree->ch-'a']=record;//�洢����� 
			cout<<tree->ch<<":"<<record<<endl;//��ӡ����� 
		}
		record+=r;
		generate_encoding_map(tree->right);
		record=record.substr(0,record.length()-1); //���� 
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
		if(str[i]==l[0]){//���� 
			if(temp_point->left==NULL){//���û�ж���,���ﾡͷ 
				cout<<temp_point->ch;
				temp_point=huffman;//����
				i--; //���� 
			}else{
				temp_point=temp_point->left;
			}
		}else{
			if(temp_point->right==NULL){
				cout<<temp_point->ch;
				temp_point=huffman;//���� 
				i--;//���� 
			}else{
				temp_point=temp_point->right;
			}
		}
	}

}
string readFileIntoString(char * filename){
	ifstream ifile(filename);
	//���ļ����뵽ostringstream����buf��
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
	statistics(file_str);//ͳ��Ƶ�� 
	for(int i=0;i<n;i++){
		nodes[i]=init(count[i]);
		nodes[i]->ch='a'+i;
	}
	printarr(nodes);
	BiTree* h_tree=huffman(nodes);//����huffman�� 
	generate_encoding_map(h_tree);//���ɱ����
	string encode_str=encoder(file_str);//���� 
	decoder(encode_str,h_tree);//���� 
	return 0;
}      
	

