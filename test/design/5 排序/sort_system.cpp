#include<iostream>
#include<stdlib.h>
#include<string.h>
#define n 10000
using namespace std;
int compare=0; //�ؼ��ֱȽϴ���
int move=0;//�ؼ����ƶ�����;
void printarr(int a[]){
	for(int i=0;i<n;i++){
		cout<<a[i]<<",";
	}
	cout<<endl;
}
int* generate_random_arr(){
	int arr[n];
	for(int i=0;i<n;i++){
		arr[i]=rand();
	}
	return arr;
} 
void insertSort(int arr[]){ 
    for(int i=1;i<n;i++){
    	compare=0;
        move=0;
        compare++;
		if(arr[i]<arr[i-1]){
            int temp=arr[i];
            int j;
            for(j=i-1;j>=0&&(temp<arr[j]);j--){
            	arr[j+1]=arr[j];
            	compare++;
            	move++;
			}
            arr[j+1]=temp;//���� 
            move++;
        }
    }
}
void bubbleSort(int arr[]){
	compare=0;
    move=0;
    int temp;
    for(int i=0;i!=n;++i){
        for(int j=0;j!=n;++j){
        	compare++;
            if(arr[i]<arr[j]){
            	//����,����ð�� 
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                move+=3;
            }
        }
    }
}
void selectSort(int a[]){
	compare=0;
    move=0;
    int k;
    for(int i=0;i<n;i++){
        k=i;
        for(int j=i+1;j<n;j++){
        	compare++;
            if(a[j]<a[k])k=j;
        }
        int temp=a[i];
        a[i]=a[k];
        a[k]=temp;
        move+=3;
    }
}
void swap(int v[], int i, int j){
    int temp;
    temp=v[j];
    v[j]=v[i];
    v[i]=temp;
}
void quickSort(int v[], int first, int last){
    int i,storeindex;
    if(first>=last){
    	return;
    }
    swap(v,last,(first+last)/2); //move partition elem
    move+=3;
    storeindex=first;
    for(i=first;i<=last-1;i++){
    	compare++;
		if(v[i]<=v[last]){
            swap(v,storeindex,i);
            storeindex += 1;
            move+=3;
        }
	}   
    swap(v,last,storeindex);
    move+=3;
	quickSort(v,first,storeindex-1);
    quickSort(v,storeindex+1,last);
}
void MaxHeapFixDown(int a[],int i,int k){//��������� 
    int j=2*i+1;
    int temp=a[i];
    while(j<k){
    	compare++; 
        if(j+1<k&&a[j]<a[j+1]){
        	++j;
		}
        compare++;
		if(temp>a[j]){
			break;
		}else{
			move++;
            a[i]=a[j];
            i=j;
            j=2*i+1;
        }
    }
    move++;
    a[i]=temp;
}
void heapSort(int a[]){
	compare=0;
	move=0;
    for(int i= n/2-1;i>=0;i--)
        MaxHeapFixDown(a,i,n);
    for(int i=n-1;i>=1;i--){
        swap(a,i,0);
        move+=3;
        MaxHeapFixDown(a,0,i);
    }
}
void mergeAdd(int arr[], int left, int mid, int right, int *temp){//�ϲ� 
	int i=left;
	int j=mid+1;
	int k=left;//��ʱ�±�
	while(i<=mid&&j<=right){
		compare++;
		if(arr[i]<arr[j]){
			move++;
			temp[k++]=arr[i++];
		}else{
			move++;
			temp[k++]=arr[j++];
		}
	}
	while(i<=mid){
		move++;
		temp[k++]=arr[i++];
	}
	while(j<=right){
		move++;
		temp[k++]=arr[j++];
	}
	//��temp�е����ݿ���arr������
	//���й鲢��ʱ�򣬴����������arr[left,right),��Ӧ�Ļ��
	//�ⲿ������������tmp[left,right)������
	memcpy(arr+left,temp+left,sizeof(int)*(right-left+1));
}
void mergeSort(int arr[],int left,int right,int *temp){
	compare=0;
	move=0;
	int mid = 0;
	if(left<right){
		mid=left+(right-left)/2;
		mergeSort(arr,left,mid,temp);
		mergeSort(arr,mid+1,right,temp);
		mergeAdd(arr,left,mid,right,temp);
	}	
}
void UI(){
	int *a=generate_random_arr();
	int arr[n];
	while(true){
		int num;
		cout<<"�����밴1,�����밴2"<<endl;
		cin>>num;
		if(num==1){
			for(int i=0;i<n;i++){
				arr[i]=a[i];
			}
			int *temp=(int*)malloc(sizeof(int)*n);
			mergeSort(arr,0,n,temp);
			cout<<"�鲢����->compare times:"<<compare<<",move times:"<<move<<endl;
			for(int i=0;i<n;i++){
				arr[i]=a[i];
			}
			heapSort(arr);
			cout<<"������->compare times:"<<compare<<",move times:"<<move<<endl;
			for(int i=0;i<n;i++){
				arr[i]=a[i];
			}
			compare=0;
			move=0;
			quickSort(arr,0,n);//��Ϊ�õݹ�д�˵��ֶ���ʼ�� 
			cout<<"��������->compare times:"<<compare<<",move times:"<<move<<endl;
			for(int i=0;i<n;i++){
				arr[i]=a[i];
			}
			selectSort(arr);
			cout<<"ѡ������->compare times:"<<compare<<",move times:"<<move<<endl;
			for(int i=0;i<n;i++){
				arr[i]=a[i];
			}
			bubbleSort(arr);
			cout<<"ð������->compare times:"<<compare<<",move times:"<<move<<endl;
			for(int i=0;i<n;i++){
				arr[i]=a[i];
			}
			insertSort(arr);
			cout<<"��������->compare times:"<<compare<<",move times:"<<move<<endl;
			break;
		}else if(num==2){
			break;
		}
	}  
}
int main(){
	UI();
	return 0;
}
