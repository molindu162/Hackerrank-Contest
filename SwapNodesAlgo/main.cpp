#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void swapTree(int rootIdx, vector<int> &indexes){
    int leftChildIdx = rootIdx * 2;
    int rightChildIdx = leftChildIdx + 1;
    swap(indexes[leftChildIdx], indexes[rightChildIdx]);
}

void swapNodes(vector<int> &indexes, vector<int> queries) {
    int height = log2(indexes.size() + 1);
    for (int h: queries){
        int ratio = height / h;
        int count = 1;
        while (count <= ratio){
            int heightConsider = h * count;
            int startRootIdx = pow(2, heightConsider - 1);

            int endRootIdx = startRootIdx + pow(2, heightConsider - 1) - 1;

            for (int i = startRootIdx; i <= endRootIdx; i++){
                if (indexes[i] != -1){
                    int leftChildIdx = 4;
                    int rightChildIdx = 5;
                    swap(indexes[leftChildIdx], indexes[rightChildIdx]);
                    swapTree(i, indexes);
                }
            }


            count++;
        }
        for (int j: indexes){
            cout << j << " ";
        }
        cout << endl;
    }
}


int main(){
    vector<int> indexes;
    indexes.push_back(0);
    indexes.push_back(1);
    indexes.push_back(2);
    indexes.push_back(3);
    indexes.push_back(4);
    indexes.push_back(-1);
    indexes.push_back(5);
    indexes.push_back(-1);
    indexes.push_back(6);
    indexes.push_back(-1);
    indexes.push_back(7);
    indexes.push_back(8);
    indexes.push_back(-1);
    indexes.push_back(9);
    indexes.push_back(-1);
    indexes.push_back(-1);
    indexes.push_back(10);
    indexes.push_back(11);

    vector<int> queries;
    queries.push_back(2);
    queries.push_back(4);

    swapNodes(indexes, queries);


    return 0;
}