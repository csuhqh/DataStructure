#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class HeapSort {
private:
    std::vector<T> heap; //一个数组，一个列表
    // 辅助函数，用于维护堆性质
    void heapifyUp() {
        int currentIndex = heap.size() - 1;
        while (currentIndex > 0) {
            int parentIndex = (currentIndex - 1) / 2;
            if (heap[currentIndex] < heap[parentIndex]) {
                std::swap(heap[currentIndex], heap[parentIndex]);
                currentIndex = parentIndex;
            } else {
                break;
            }
        }
    }
    // 辅助函数，用于维护堆性质
    void heapifyDown() { //删除堆顶元素
        int currentIndex = 0;
        int size = heap.size();
        while (true) {
            int leftChild = 2 * currentIndex + 1;
            int rightChild = 2 * currentIndex + 2;
            int smallest = currentIndex;
            if (leftChild < size && heap[leftChild] < heap[smallest]) {
                smallest = leftChild;
            }
            if (rightChild < size && heap[rightChild] < heap[smallest]) {
                smallest = rightChild;
            }
            if (smallest != currentIndex) {
                std::swap(heap[currentIndex], heap[smallest]);
                currentIndex = smallest;
            } else {
                break;
            }
        }
    }

public:
    // 添加元素到堆中
    void insert(const T& value) {
        heap.push_back(value);
        heapifyUp(); //添加元素，元素上浮
    }

    // 删除堆顶元素
    void remove() {
        if (heap.empty()) {
            std::cout << "Heap is empty." << std::endl;
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown();
    }

    // 堆排序
    void sort() {
        std::vector<T> sorted;
        while (!heap.empty()) {
            sorted.push_back(heap[0]);
            remove();
        }
        std::cout << "Sorted array: ";
        for (const T& value : sorted) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    // 打印当前堆的状态
    void printHeap() const {
        std::cout << "Current heap: ";
        for (const T& value : heap) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    HeapSort<int> heapSort;
    
    heapSort.insert(4);
    heapSort.insert(10);
    heapSort.insert(3);
    heapSort.insert(5);
    heapSort.insert(8);

    std::cout << "Before sorting:" << std::endl;
    heapSort.printHeap();

    heapSort.sort();

    return 0;
}
