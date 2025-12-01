#include<iostream>
using namespace std;
class maxheap{
    int* arr;
    int size;
    int total_size;
    public:
    maxheap(int n){
        arr=new int[n];
        size=0;
        total_size=n;
        }

        void heapifyup(int index){
            int parent=(index-1)/2;
            while(index>0&&arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                index=parent;
                parent=(index-1)/2;
            }
        }


          void heapifydown(int index){
            int largest=index;
            int left=2*index+1;
            int right=2*index+2;
          if(left<size&&arr[left]>arr[largest]){
          
            largest=left;
          }
           if(right<size&&arr[right]>arr[largest]){
          
            largest=right;
          }
          if(largest!=index){
            swap(arr[index],arr[largest]);
            heapifydown(largest);
          }
        }
        void insert(int value){
            if(size==total_size){
                cout<<"overflow";
                return;

            }
           
            arr[size]=value;
            heapifyup(size);
         size++;
        }
        int getmax(){
            if(size==0){
             
                return -1;
            }
            return arr[0];
        }
           int extractmax(){
            if(size==0){
                cout<<"empty heap";
                return -1;
            }
            int maxval=arr[0];
            arr[0]=arr[size-1];
            size--;
            heapifydown(0);
            return maxval;
        }
         void print() {
        for(int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};
int main(){
maxheap pq(5);

    pq.insert(10);
    pq.insert(4);
    pq.insert(15);
    pq.insert(20);
    pq.insert(1);

    cout << "Priority Queue (Heap): ";
    pq.print();

    cout << "Max element = " << pq.getmax() << endl;

    cout << "Extracted max = " << pq.extractmax() << endl;

    pq.print();

    cout << "Extracted max = " << pq.extractmax() << endl;

    pq.print();

}