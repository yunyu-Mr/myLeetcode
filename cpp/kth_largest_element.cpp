#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    int heap_size;
    int parent(int i) {return (i-1)/2; }
    int left(int i)  {return 2*i +1; }
    int right(int i) {return 2*i +2; }
    void heapify(vector<int> &A, int i);

public:
    explicit MaxHeap(int size):
        heap_size(size)
        {}
    void build_heap(vector<int> &A);
    int heappop(vector<int> &A);
    int getHeapsize() {return heap_size; }
};

void MaxHeap::heapify(vector<int> & A, int i) {
    int l = left(i);
    int r = right(i);
    int largest = 0;
    if (l < heap_size && A[l] > A[i]){
        largest = l;
    }else {
        largest = i;
    }
    if (r < heap_size && A[r] > A[largest]) {
        largest = r;
    }
    if (largest != i) {
        std::swap(A[i], A[largest]);
        heapify(A, largest);
    }
}

void MaxHeap::build_heap(vector<int> &A) {
    for (int i=(A.size()-1)/2; i>=0; i--) {
        heapify(A, i);
    }
}

int MaxHeap::heappop(vector<int> &A) {
    cout<<"swap : "<<A[0]<<", "<<A[heap_size-1]<<endl;
    std::swap(A[0], A[(heap_size--)-1]);
    heapify(A, 0);
    return A[heap_size];
}

int main() {
    vector<int> A;
    for (int i=0; i<10; i++) {
        A.push_back(i);
    }
    MaxHeap heap(A.size());
    heap.build_heap(A);
    for (int i=0; i<A.size(); i++) {
//        cout<<A[i]<<"  ";
        cout<<"heap size : "<<heap.getHeapsize()<<endl;
        cout<<heap.heappop(A)<<endl;
        for (int j=0; j<A.size(); j++) {
            cout<<A[j]<<"  ";
        }
        cout<<endl<<endl;
    }
}
