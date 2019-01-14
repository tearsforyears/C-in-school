#include <iostream>
#include <stdlib.h>
#include <cstdio>
#define N 10000
using namespace std;

int key_numb_compare_times = 0; //关键字比较次数
int key_numb_move_times = 0;//关键字移动次数;


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

void insertSort(int *arr){ //插入排序
    key_numb_compare_times = 0;
    key_numb_move_times = 0;
    for(int i=1; i<N; i++){
        if(arr[i]<arr[i-1]){   
            key_numb_compare_times++;
            int temp=arr[i];
            int j=0;
            for(j=i-1; j>=0 && (temp<arr[j]); j--){ //此处j>=0 确保不会下标溢出a的“管辖区域”
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
      int j = 2*i+1; //右边节点
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
            i = j;  //i 为左节点
            j = 2*i+1;//j 为右节点
        }
    }
    arr[i]=temp;
    key_numb_move_times++;
}
 
//堆排序
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
    int n1 = q - p + 1;       //左部分的的元素个数
    int n2 = r - q;           //同上
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
     // 数组L从0~n1-1存放，第n1个存放int型所能表示的最大数，即认为正无穷，这是为了
     //处理合并时，比如当数组L中的n1个元素已经全部按顺序存进数组a中，只剩下数组R的
     //部分元素，这时因为R中剩下的元素全部小于11111111,则执行else语句，直接将剩下的
     //元素拷贝进a中。
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
    cout << "————————————————————————————————————————————"<< endl;
    cout << "__________关键字比较次数_________关键字的移动次数" << endl;
    insertSort(arr);
    cout << "直接插入排序: "<< key_numb_compare_times<<"_________" << key_numb_move_times <<endl;
    random(arr);
    bubbleSort(arr);
    cout << "冒泡排序：    " << key_numb_compare_times<<"_________" << key_numb_move_times <<endl;
    random(arr);
    select_sort(arr);
    cout << "直接选择排序: " << key_numb_compare_times<<"_________" << key_numb_move_times << endl;
    key_numb_compare_times = 0;
    key_numb_move_times = 0;
    random(arr);
    quickSort(arr, 0, N-1);
    cout << "快速排序:    " << key_numb_compare_times<<"_________" << key_numb_move_times << endl;
    random(arr);
    HeapSort(arr,N);
    cout << "堆排序:      " << key_numb_compare_times<<"_________" << key_numb_move_times << endl;
    random(arr);
    MergeSort(arr,0,N-1);
    cout << "归并排序:    " << key_numb_compare_times<<"_________" << key_numb_move_times <<  endl;
}


int main(){
    int numb[N];// 存储随机数的数组；
    cout << "已自动生成一万个随机数" << endl; 
    while(1){
        random(numb);
        cout << "这是一个排序系统" << endl;
        cout << "1.排序比较" << endl;
        cout << "0.退出" << endl;

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
