//
// Created by Olcay Taner YILDIZ on 6.05.2023.
//

#include "DisjointSet.h"

#include <algorithm>

DisjointSet::DisjointSet(int *elements, int count) {
    sets = new Set[count];
    for (int i = 0; i < count; i++){
        sets[i] = Set(elements[i], i);
    }
    this->count = count;
}

DisjointSet::~DisjointSet() {
    delete[] sets;
}

int DisjointSet::findSetRecursive(int index) {
    int parent = sets[index].getParent();
    if (parent != index){
        return findSetRecursive(parent);
    }
    return parent;
}

int DisjointSet::findSetIterative(int index) {
    int parent = sets[index].getParent();
    while (parent != index){
        index = parent;
        parent = sets[index].getParent();
    }
    return parent;
}

void DisjointSet::unionOfSets(int index1, int index2) {
    int x = findSetIterative(index1);
    int y = findSetIterative(index2);
    if (sets[x].getDepth() < sets[y].getDepth()){
        sets[x].setParent(y);
    } else {
        sets[y].setParent(x);
        if (sets[x].getDepth() == sets[y].getDepth()){
            sets[x].incrementDepth();
        }
    }

}

DisjointSet::DisjointSet(int count) {
    sets = new Set[count];
    for (int i = 0; i < count; i++){
        sets[i] = Set(i, i);
    }
    this->count = count;
}
int* DisjointSet::grandChildren(int index) {//Q3
    int count2 = 0;
    for (int i = 0; i < count; ++i) {
        if (sets[i].getParent() == index) {
            for (int j = 0; j < count; ++j) {
                if (sets[j].getParent() == i) {
                    count2++;
                }
            }
        }
    }
    int* result = new int[count2];
    count2 = 0;
    for (int i = 0; i < count; ++i) {
        if (sets[i].getParent() == index) {
            for (int j = 0; j < count; ++j) {
                if (sets[j].getParent() == i) {
                    result[count2++] = j;
                }
            }
        }
    }
    return result;
}
int* DisjointSet::getSetWithIndex(int index) { //Q7P
    int size = 0;
    for(int i=0; i<count;i++) {
        if(findSetIterative(index) == findSetIterative(i)) {
            size++;
        }
    }
    int* result = new int[size];
    size = 0;
    for (int i=0;i<count;i++) {
        if(findSetIterative(index)==findSetIterative(i)) {
            result[size] = i;
            size++;
        }
    }
    return result;
}
/* int* DisjointSet::ascendants(int index) { //Q11 (cannot complete the question because there's no getter for data)
    int temp = index;
    int count2 = 0;
    while(true) {
        count2++;
        int parent = sets[temp].getParent();
        sets[parent].getParent();
        sets[parent].
        if(parent == temp){ break;}
        temp = parent;
    }
    int* ascendantArray = new int[count2];
    temp = index;
    for(int i=0;i<count2;i++) {
        ascendantArray[i] =
    }
} /*




