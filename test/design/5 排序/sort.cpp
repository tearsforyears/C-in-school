#include <iostream>
#include <stdlib.h>
#include <cstdio>
#define N 10000
using namespace std;

int key_numb_compare_times = 0; //�ؼ��ֱȽϴ���
int key_numb_move_times = 0;//�ؼ����ƶ�����;


void print(int*arr){
    for(int i = 0;i < N;i++){
        cout << arr[i] << " " ;
    }
    cout << endl;
}

int* random(int *arr){
    for(int i=0;i<N;i++){
        arr[i] = rand();
    }
    return arr;
}

void insertSort(int *arr){ //��������
    key_numb_compare_times = 0;
    key_numb_move_times = 0;
    for(int i=1; i<N; i++){
        if(arr[i]<arr[i-1]){   
            key_numb_compare_times++;
            int temp=arr[i];
            int j=0;
            for(j=i-1; j>=0 && (temp<arr[j]); j--){ //�˴�j>=0 ȷ�������±����a�ġ���Ͻ����
                arr[j+1]=arr[j];
                key_numb_compare_times++;
                key_numb_move_times++;
            }
            arr[j+1]=temp;
            key_numb_move_times++;
        }
    }
}

int bubbleSort(int *arr){
    key_numb_compare_times = 0;
    key_numb_move_times = 0;
    int temp,j;
    int i = 0;
    for (i = 1; i < N; i++){
        for (j = 1; j <= N -i; j++){
            key_numb_compare_times++;
            if (arr[j]<arr[j+1]){    
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                key_numb_move_times += 3;
            }
        }
    }   
    return 0;
}


void select_sort(int *arr){
    int i = 0, j = 0, k = 0,temp = 0;
    key_numb_compare_times = 0;
    key_numb_move_times = 0;
    for (i=0; i < N-1; i++){
        k = i;
        for (j = i + 1; j < N; j++){
            key_numb_compare_times++;
            if (arr[k] > arr[j]){
                k = j;
            }
        }
 
	    if (k != i){
            temp=arr[k];
            arr[k]=arr[i];
            arr[i]=temp;
            key_numb_move_times +=3;
	    }
    }
}

void quickSort(int *arr, int low, int high){
    if(low >= high){
        return;
    }
    int first=low;
    int last=high;
    int key = arr[first];
    while(first<last){
        while(first<last&&arr[last]>=key){
            key_numb_compare_times++;
            --last;
        }
        key_numb_move_times++;
        arr[first]=arr[last];
        while(first<last&&arr[first]<=key){
            key_numb_compare_times++;
            ++first;
        }
        key_numb_move_times++;
        arr[last]=arr[first];    
	}
    key_numb_move_times++;
    arr[first]=key;
    quickSort(arr,low,first-1);
    quickSort(arr,first+1,high);
}

void MaxHeapFixDown(int *arr, int i,int n){
      int j = 2*i+1; //�ұ߽ڵ�
      int temp = arr[i];
      while(j < n){
        key_numb_compare_times++;
        if(j + 1 < n && arr[j] < arr[j+1])
             ++j;
        key_numb_compare_times++;
        if(temp > arr[j])
            break;
        else{
            key_numb_move_times++;
            arr[i] = arr[j];
            i = j;  //i Ϊ��ڵ�
            j = 2*i+1;//j Ϊ�ҽڵ�
        }
    }
    arr[i]=temp;
    key_numb_move_times++;
}
 
//������
void HeapSort(int *arr,int n){
    key_numb_compare_times = 0;
    key_numb_move_times = 0;    
    for(int i= N/2-1;i>=0;i--){
        MaxHeapFixDown(arr,i,n);
    }
    for(int i=N-1;i>=1;i--){
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        key_numb_move_times += 3;
        MaxHeapFixDown(arr,0,i);
    }
}



void Merge(int *arr,int p, int q, int r){
    int n1 = q - p + 1;       //�󲿷ֵĵ�Ԫ�ظ���
    int n2 = r - q;           //ͬ��
    int i, j, k;
    int *L = new int[n1+1];
    int *R = new int[n2+1];
    for(i = 0; i < n1; i++){
        key_numb_move_times++;
        L[i]=arr[p+i];
    }
    for(j = 0; j < n2; j++){
        key_numb_move_times++;
        R[j] = arr[q+j+1];
    }
    L[n1]=11111111;
    R[n2]=11111111;
     // ����L��0~n1-1��ţ���n1�����int�����ܱ�ʾ�������������Ϊ���������Ϊ��
     //����ϲ�ʱ�����統����L�е�n1��Ԫ���Ѿ�ȫ����˳��������a�У�ֻʣ������R��
     //����Ԫ�أ���ʱ��ΪR��ʣ�µ�Ԫ��ȫ��С��11111111,��ִ��else��䣬ֱ�ӽ�ʣ�µ�
     //Ԫ�ؿ�����a�С�
    for(i = 0, j = 0, k = p;k <= r; k++){
        key_numb_compare_times++;
        if(L[i]<=R[j]){
            key_numb_move_times++;
            arr[k]=L[i++];
        }else{
            key_numb_move_times++;
            arr[k]=R[j++];
        }
    }
 
    delete []L;
    delete []R;
}
 
void MergeSort(int *arr, int l, int r){
    key_numb_compare_times = 0;
    key_numb_move_times = 0;
    if(l<r){
        int m = (l+r)/2;
        MergeSort(arr,l,m);
        MergeSort(arr,m+1,r);
        Merge(arr,l,m,r);
    }
}


void sort_compare(int *arr){
    cout << "����������������������������������������������������������������������������������������"<< endl;
    cout << "__________�ؼ��ֱȽϴ���_________�ؼ��ֵ��ƶ�����" << endl;
    insertSort(arr);
    cout << "ֱ�Ӳ�������: "<< key_numb_compare_times<<"_________" << key_numb_move_times <<endl;
    random(arr);
    bubbleSort(arr);
    cout << "ð������    " << key_numb_compare_times<<"_________" << key_numb_move_times <<endl;
    random(arr);
    select_sort(arr);
    cout << "ֱ��ѡ������: " << key_numb_compare_times<<"_________" << key_numb_move_times << endl;
    key_numb_compare_times = 0;
    key_numb_move_times = 0;
    random(arr);
    quickSort(arr, 0, N-1);
    cout << "��������:    " << key_numb_compare_times<<"_________" << key_numb_move_times << endl;
    random(arr);
    HeapSort(arr,N);
    cout << "������:      " << key_numb_compare_times<<"_________" << key_numb_move_times << endl;
    random(arr);
    MergeSort(arr,0,N-1);
    cout << "�鲢����:    " << key_numb_compare_times<<"_________" << key_numb_move_times <<  endl;
}


int main(){
    int numb[N];// �洢����������飻
    cout << "���Զ�����һ��������" << endl; 
    while(1){
        random(numb);
        cout << "����һ������ϵͳ" << endl;
        cout << "1.����Ƚ�" << endl;
        cout << "0.�˳�" << endl;

        int select = 0;
        cin >> select;
        if(select == 1){
            sort_compare(numb);
        }
        if(select == 0){
            return 0;
        }
    }
    return 0;
}
