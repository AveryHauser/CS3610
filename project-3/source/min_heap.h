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
  HeapNode<T> newNode(data, key);
  heap.push_back(newNode);
  heapify_up(heap.size() - 1);
}

template <typename T>
T MinHeap<T>::extract_min() {                          // need to implement this function
  if (heap.empty()) throw runtime_error("Heap is empty");

  T minData = heap[0].data;
  heap[0] = heap.back();
  heap.pop_back();
  if (!heap.empty()) heapify_down(0);

  return minData;
}
template <typename T>
T MinHeap<T>::peek()const{
  return heap[0].data;
}
template <typename T>
int MinHeap<T>::size()const{
  return heap.size();
}
template <typename T>
void MinHeap<T>::heapify_up(int index){
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