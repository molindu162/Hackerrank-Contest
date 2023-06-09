#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<vector<int> > edges, vector<bool> &visited, int start, int end, bool &isCyclic, int &paths)
{
    if (isCyclic == true){
        paths = INT_MAX;
        return;
    }

    if (start == end)
        paths += 1;

    visited[start] = true;
    vector<int> neighbours = edges[start];
    for (int neighbour: neighbours)
    {
        if (visited[neighbour] == false){
            visited[neighbour] = true;
            DFS(edges, visited, neighbour, end, isCyclic, paths);
        }
        else{
            isCyclic = true;
            paths = INT_MAX;
            return;
        }
    }
}

int countPaths(int n, vector<vector<int> > edges)
{
    vector<bool> visited(false, n);
    bool isCyclic = false;
    int paths = 0;
    DFS(edges, visited, 0, 4, isCyclic, paths);
    return paths;
}

int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(2);

    vector<int> b;
    a.push_back(3);

    vector<int> c;
    a.push_back(4);

    vector<int> d;
    a.push_back(4);

    vector<int> e;

    vector<vector<int> > edges;
    edges.push_back(a);
    edges.push_back(b);
    edges.push_back(c);
    edges.push_back(d);
    edges.push_back(e);

    int noOfPaths = countPaths(5, edges);
    cout << noOfPaths;

    return 0;
}