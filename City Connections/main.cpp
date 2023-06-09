#include <iostream>
#include <vector>

using namespace std;

bool isCyclicUtil(vector<vector<int> > edges, vector<bool> visited, int curr){
    if (visited[curr] == true){
        return true;
    }

    visited[curr] = true;
    bool FLAG = false;
    for (int i = 0; i < edges[curr].size(); i++){
        FLAG = isCyclicUtil(edges, visited, edges[curr][i]);
        if (FLAG == true){
            return true;
        }
    }

    return false;
}

bool isCyclic(int V, vector<vector<int> > edges){
    vector<bool> visited(V, false);
    bool FLAG = false;
    for (int i = 0; i < V; i++){
        visited[i] = true;
        for (int j = 0; j < edges[i].size(); j++){
            FLAG = isCyclicUtil(edges, visited, edges[i][j]);
            if (FLAG == true){
                return true;
            }
        }
        visited[i] = false;
    }
    return false;
}

void DFS(vector<vector<int> > edges, vector<bool> &visited, int start, int end, int &paths)
{
    if (isCyclic(5, edges) == true){
        paths = INT_MAX;
        return;
    }

    if (start == end)
        paths += 1;

    if (start != end){
        visited[start] = true;
    }

    vector<int> neighbours = edges[start];
    for (int neighbour: neighbours)
    {
        if (visited[neighbour] == false) {
            DFS(edges, visited, neighbour, end, paths);
        }
      else{
          if (isCyclic(5, edges)){
              paths = INT_MAX;
              return;
          }
      }

    }
}

int countPaths(int n, vector<vector<int> > edges)
{
    vector<bool> visited(5, false);
    bool isCyclic = false;
    int paths = 0;
    DFS(edges, visited, 0, 4, paths);
    return paths;

}

int main()
{
    vector<int> a;
    a.push_back(2);
    a.push_back(3);


    vector<int> b;
    b.push_back(0);

    vector<int> c;
    c.push_back(4);

    vector<int> d;
    d.push_back(1);
    d.push_back(4);

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