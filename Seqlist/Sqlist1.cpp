#include<iostream>

///静态分配的顺序表
typedef int Elemtype; //定义元素类型
#define MaxSize 50
typedef struct{
    Elemtype data[MaxSize];
    int length;
}Sqlist;
void InitList(Sqlist &L){
    L.length=0;
}
//列表插入
bool ListInsert(Sqlist &L,int i,Elemtype e){
    if(i<1||i>=L.length+1){
        return false;
    }
    if(L.length>=MaxSize){
        return false;
    }
    for(int j=L.length;j>=i;j--){
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;
    L.length++;
    return true;
}
//列表删除
bool ListDelete(Sqlist &L,int i,Elemtype &e){
    if(i<1||i>=L.length+1){
        return false;
    }
    e=L.data[i-1];
    for(int j=i;j<L.length;j++){
        L.data[j-1]=L.data[j];
    }
    L.length--;
    return true;
}
int LocateElem(Sqlist L,Elemtype e){
    int i;
    for(i=0;i<L.length;i++){
        if(L.data[i]==e){
            return i+1;
        }
    }
    return 0;
}

//王道算法习题1-4
bool PopMin(Sqlist& L){
    if(L.length==0){
        return false;
    }
    int value=L.data[0];
    int pos=0;
    for(int i=1;i<L.length;i++){
        if(value>L.data[i]){
            value=L.data[i];
            pos=i;
        }
    }
    L.data[pos]=L.data[L.length-1];
    L.length--;
    return true;
}
bool Revesrse(Sqlist L){
    if(L.length==0){
        return false;
    }
    int start=0;
   for(int i=0;i<L.length/2;i++){
        Elemtype e=L.data[i];
        L.data[i]=L.data[L.length-1-i];
        L.data[L.length-1-i]=L.data[i];
   }
   return true;
    
}
void Deletex(Sqlist &L, Elemtype e){
    int k=0,i=0;
    while(i<L.length){
        if(L.data[i]==e){
            k+=1;
        }
        else{
            L.data[i-k]=L.data[i];
        }
        i++;
    }
    L.length-=k;
}
bool DeleteRange(Sqlist &L,Elemtype s,Elemtype t){
    if(L.length==0){
        return false;
    }
    int k=0;
    for(int i=0;i<L.length;i++){
        if(L.data[i]>=t and L.data[i]<=t){
            k+=1;
        }
        else{
            L.data[i-k]=L.data[i];
        }
    }
    L.length-=k;
    return true;

}
