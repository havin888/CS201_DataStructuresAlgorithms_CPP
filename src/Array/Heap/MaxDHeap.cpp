//
// Created by Olcay Taner YILDIZ on 18.05.2023.
//

#include "MaxDHeap.h"

void MaxDHeap::percolateDown(int no) {
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
int MaxDHeap::howManyPairCanBeSwapped() { //Q14P
    int count2 = 0;
    for (int i = 1; i < count; ++i) {
        for (int j = i + 1; j < count; ++j) {
            bool flag1 = true;
            for(int k = 1; k <= d; ++k) {
                if(d*i + k < count && array[d*i + k].getData() > array[j].getData()) {
                    flag1 = false;
                    break;
                };
            }
            if(array[j].getData() > array[(i-1)/d].getData())
                flag1 = false;
            bool flag2 = true;
            for(int k = 1; k <= d; ++k) {
                if(d*j + k < count && array[d*j + k].getData() > array[i].getData()) {
                    flag2 = false;
                    break;
                };
            };
            if(array[i].getData() > array[(j-1)/d].getData())
                flag2 = false;
            if(flag1 && flag2)
                count2++;
        }
    }

    return count2;
}

void MaxDHeap::percolateUp(int no) {
    int parent;
    parent = (no - 1) / d;
    while (parent >= 0 && array[parent].getData() < array[no].getData()){
        swapNode(parent, no);
        no = parent;
        parent = (no - 1) / d;
    }
}

MaxDHeap::MaxDHeap(int N, int d) : DHeap(N, d) {
}
