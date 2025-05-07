//
// Created by Olcay Taner YILDIZ on 18.05.2023.
//

#include "MinHeap.h"

#include <limits>

void MinHeap::percolateDown(int no) {
    int left, right;
    left = 2 * no + 1;
    right = 2 * no + 2;
    while ((left < count && array[no].getData() > array[left].getData()) ||
           (right < count && array[no].getData() > array[right].getData())){
        if (right >= count || array[left].getData() < array[right].getData()){
            swapNode(no, left);
            no = left;
        } else {
            swapNode(no, right);
            no = right;
        }
        left = 2 * no + 1;
        right = 2 * no + 2;
    }
}

void MinHeap::percolateUp(int no) {
    int parent;
    parent = (no - 1) / 2;
    while (parent >= 0 && array[parent].getData() > array[no].getData()){
        swapNode(parent, no);
        no = parent;
        parent = (no - 1) / 2;
    }
}

void MinHeap::update(int k, int newValue) {
    int oldValue = array[k].getData();
    array[k].setData(newValue);
    if (oldValue < newValue){
        percolateDown(k);
    } else {
        percolateUp(k);
    }
}
bool MinHeap::isLargestLeftMost(){ //Q13P
    int largest = std::numeric_limits<int>::min();
    for(int i=0; i < N; i++)
    {
        if(array[i].getData() > largest)
            largest = array[i].getData();
    };
    int height = 0;
    while ((1 << height) <= N) {
        height++;
    }
    height--;
    int leftmostIndex = (1 << height) - 1;
    return array[leftmostIndex].getData() == largest;
}

MinHeap::MinHeap(int N) : Heap(N) {
}
