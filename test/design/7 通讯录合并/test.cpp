#include<iostream>
#include<stdlib.h>
#include<string>
#include <fstream>
#include <sstream>
#define n 3 //count of tel books
#define cor 100//count of record
#define max_int 0xffffff
using namespace std;
typedef struct TelBook{
	string name;
	string tel;
	string work_place;
};
int len[n]={3,4,5};//������ĳ���	 
TelBook test_data[n][cor];

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
	int max_rol=readFileIntoStringArr("test.txt");
	for(int i=0,k=0;i<n;i++){//i��ͨѶ�� k���ļ����� j�Ǽ�¼ 
		for(int j=0;j<len[i];j++,k++){
			int f_point=0,l_point=0;//�ո�ָ��
			int count=1;
			for(int l=0;l<textline[k].length();l++){//l���ַ���ָ�� 
				if(textline[k][l]==','&&count==1){
					f_point=l;
					count++;
				}
				if(textline[k][l]==','&&count==2)l_point=l;
			}
			test_data[i][j].name=textline[k].substr(0,f_point);
			test_data[i][j].tel=textline[k].substr(f_point+1,l_point-f_point-1);
			test_data[i][j].work_place=textline[k].substr(l_point+1);
		}
	}
	
	return 0;
}      
	

