//
// Created by Olcay Taner YILDIZ on 25.04.2023.
//

#include "DHeap.h"

DHeap::DHeap(int N, int d) : Heap(N){
    this->d = d;
}

void DHeap::percolateDown(int no) {
    int child, largestChild;
    int value;
    do{
        largestChild = -1;
        value = array[no].getData();
        for (int i = 1; i <= d && d * no + i < count; i++){
            child = d * no + i;
            if (value < array[child].getData()){
                largestChild = child;
                value = array[child].getData();
            }
        }
        if (largestChild != -1){
            swapNode(no, largestChild);
            no = largestChild;
        } else {
            break;
        }
    } while (true);
}

void DHeap::percolateUp(int no) {
    int parent;
    parent = (no - 1) / d;
    while (parent >= 0 && array[parent].getData() < array[no].getData()){
        swapNode(parent, no);
        no = parent;
        parent = (no - 1) / d;
    }
}
