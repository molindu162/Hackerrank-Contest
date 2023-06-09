#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<vector<int> > edges, vector<bool> visited, int start, bool isCyclic)
{
    if (isCyclic == true){
        return;
    }
    visited[start] = true;
    vector<int> neighbours;
    for (int neighbour: neighbours)
    {
        if (visited[neighbour] == false){
            visited[neighbour] = true;
        }
    }
}

void countPaths(int n, vector<vector<int> > edges)
{
    vector<bool> visited(false, n);
    bool isCyclic = false;

}

int main()
{
    return 0;
}