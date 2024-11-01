#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
struct HeapNode {
  HeapNode(const T data, const int key) : data(data), key(key) {}
  bool operator<(const HeapNode<T>& rhs) {return this->key < rhs.key;}
  bool operator<=(const HeapNode<T>& rhs) {return this->key <= rhs.key;}

  T data;
  int key;
};

template <typename T>
class MinHeap {
public:
  MinHeap() {}
  ~MinHeap() {}

  void insert(const T data, const int key);
  T extract_min();
  T peek() const ; // need to implement this function

  int size() const;         // need to implement this function

private:
  vector<HeapNode<T> > heap;

  void heapify_up(int index);
  void heapify_down(int index);
};


template <typename T>
void MinHeap<T>::insert(const T data, const int key) {  // need to implement this function
  //creates a new node and adds it to the back of the heap 
  HeapNode<T> newNode(data, key);
  heap.push_back(newNode);
  //it will use the helper function heapify up to place the node in the correct place
  heapify_up(heap.size() - 1);
}

template <typename T>
T MinHeap<T>::extract_min() {                          // need to implement this function
  //throws a run time error so that we know that the heap was empty and the return type doesnt have to be the same 
  if (heap.empty()) throw runtime_error("Heap is empty");

  //will set the first element to a temp T and return it, then set the back element to the first and pop off the back
  //then it will heapify down on the heap
  T minData = heap[0].data;
  heap[0] = heap.back();
  heap.pop_back();
  if (!heap.empty()) heapify_down(0);

  //will return the data in the first element of heap 
  return minData;
}
template <typename T>
T MinHeap<T>::peek()const{
  //returns the first element in the heap
  return heap[0].data;
}
template <typename T>
int MinHeap<T>::size()const{
  //returns the size of the heap
  return heap.size();
}
template <typename T>
void MinHeap<T>::heapify_up(int index){
  //will heapify up by comparing and swapping the parent and index in the heap
  while (index > 0) {
    int parent = (index - 1) / 2;
    if (heap[index] < heap[parent]) {
      swap(heap[index], heap[parent]);
      index = parent;
    } else {
      break;
    }
  }
}
template <typename T>
void MinHeap<T>::heapify_down(int index){
  //will do the same as heapify up exept sorts in the opisite order as heapify up wiht the smallest and index
  int size = heap.size();
  while (index < size) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;

    if (left < size && heap[left] < heap[smallest]) smallest = left;
    if (right < size && heap[right] < heap[smallest]) smallest = right;

    if (smallest != index) {
      swap(heap[index], heap[smallest]);
      index = smallest;
    } else {
      break;
    }
  }
}