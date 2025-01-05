#include<iostream>

///静态分配的顺序表
typedef int Elemtype; //定义元素类型
#define MaxSize 50
typedef struct{
    Elemtype data[MaxSize];
    int length;
}Sqlist;
using namespace std;
//王道习题5-8
//删除重复项目
bool DeleteSame(Sqlist &L){
    if(L.length==0){
        return false;
    }     
    int i,j;
    for(i=0,j=1;j<L.length;j++){
        if(L.data[i]!=L.data[j]){
            L.data[++i]=L.data[j];
        }

    }
    L.length=i+1;
    return true;                                                                            
    
}
//6 合并有序数组
bool Merge_List(Sqlist A,Sqlist B,Sqlist &C){
    if(A.length+B.length>MaxSize){
        return false;
    }
    int i,j,k=0;
    while(i<A.length and j<B.length){
        if(A.data[i]<=B.data[j]){
            C.data[k++]=A.data[i++];
        }else{
            C.data[k++]=B.data[j++];
        }
    }
    while(i<A.length){
        C.data[k++]=A.data[i++];
    }while(i<B.length){
        C.data[k++]=B.data[k++];
    }
    C.length=k;
    return true;
}
//7线性表调换位置
void Reverse(int t[],int start,int end){
    int j=(end-start);
    for(int i=0;i<j/2;i++){
        int temp=t[i];
        t[i]=t[j-i];
        t[j-i]=temp;
    }
}
void ChangeRange(int t[],int n,int m){
    Reverse(t,0,m+m-1);
    Reverse(t,0,n);
    Reverse(t,n,m+n-1);

}
//8有序数组查找元素要求最快而且和后继交换
void LocateElem(int t[],int x,int arraySize){
    int left=0,right=arraySize,mid;
    while(left<=right){
        mid=(left+right)/2;
        if(t[mid]==x){
            break;
        }
        if(t[mid]>x){
            right=arraySize-1;
        }else{
            left=mid+1;
        }

    }
    if(t[mid]==x and  mid!=arraySize-1){
        int temp=t[mid];
        t[mid]=t[mid+1];
        t[mid+1]=temp;

    }
    if(right>left){
        for(int i=arraySize-1;i>right;i--){
            t[i+1]=t[i];
        }
        t[i+1]=x;
    }
}
void PrintList(const Sqlist &L) {
    if (L.length == 0) {
        cout << "顺序表为空！" << endl;
        return;
    }
    cout << "顺序表内容：" << endl;
    for (int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}
void InitList(Sqlist &L) {
    L.length = 0;
}
// 主函数
int main() {
    Sqlist L;
    InitList(L);

    // 给顺序表赋初值（假设元素已经排序）
    L.data[0] = 1;
    L.data[1] = 1;
    L.data[2] = 2;
    L.data[3] = 3;
    L.data[4] = 3;
    L.data[5] = 4;
    L.length = 6; // 设置顺序表长度

   
    PrintList(L);

    // 删除重复元素
    DeleteSame(L);


    PrintList(L);

    return 0;
}