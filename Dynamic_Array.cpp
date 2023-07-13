#include <bits/stdc++.h>
using namespace std;
//if array reaches its full capacity, we dynamically create new array of twice capacity and copy elements that were already there
class DynamicArray{
    int *data;
    int nextIndex;
    int capacity;//total size
    public:
    DynamicArray(){
        data=new int[5];
        nextIndex=0;
        capacity=5;
    };
    void add(int a){//add integer a to the end of array
        if(nextIndex==capacity){
            int* nextData=new int[2*capacity];
            for(int i=0;i<capacity;i++){
                nextData[i]=data[i];
            }
            delete []data;
            data=nextData;//as nextData is a pointer in stack memory and gets deleted after if statement due to scope of variables
            capacity=capacity*2;
        }
        data[nextIndex]=a;
        nextIndex++;
    };
    int get(int i)const{//get integer at index i
        if(i<nextIndex){
            return data[i];
        }else{
            return -1;
        }
    };
    void add(int i,int element){//add element to index i by overwriting the number at index i 
        if(i<nextIndex){
            data[i]=element;
        }else if(i==nextIndex){
            add(element);
        }else{
            return;//cant add to i>nextIndex as garbage values in between
        }
    };
    DynamicArray(DynamicArray const &d){//deep copy constructor
        data=new int[d.capacity];
        for(int i=0;i<d.nextIndex;i++){
            data[i]=d.data[i];
        }
        nextIndex=d.nextIndex;
        capacity=d.capacity;
    };
    void operator=(DynamicArray const &d){//deep copy assignment operator
        data=new int[d.capacity];
        for(int i=0;i<d.nextIndex;i++){
            data[i]=d.data[i];
        }
        nextIndex=d.nextIndex;
        capacity=d.capacity;
    };
    void print()const{
        for(int i=0;i<nextIndex;i++){
            cout<<data[i]<<" ";
        }
    };
};

int main(){
    DynamicArray d1;
    d1.add(1);
    d1.add(5);
    d1.add(8);
    DynamicArray d2(d1);//inbuilt copy constructor or copy assignment operator does shallow copy so data of d2 also points towards the same array as data of d1
    DynamicArray d3;
    d3=d1;//our modified copy assignment operator with deep copy used 
    return 0;
}