#include <list>
#include <vector>
#include <iostream>
using namespace std;

class graph {
  public:
    int n_vertex;
    void *adj_list;
    
    graph(int n) { n_vertex=n; } 
    virtual void read_adj_list(vector<vector<int>>);    
    void topological_sort();

};

struct weighted_list {
    int to_node;
    int weight;
};

class weighted_graph: graph {
  public:
    weighted_graph(int n):graph(n){};
    void read_adj_list(vector<vector<int>>);    
};

/*
 * [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]]
 */
void graph::read_adj_list(vector<vector<int>> edges){
    adj_list = new list<int>[n_vertex]; 
    for(int i=0; (size_t)i<edges.size(); i++) {
        int src = edges[i][0];
        int dst = edges[i][1];
        ((list<int>*)adj_list)[src].push_back(dst);
    }
}

void weighted_graph::read_adj_list(vector<vector<int>> edges){
    adj_list = new list<weighted_list>[n_vertex]; 
    for(int i=0; (size_t)i<edges.size(); i++) {
        int src = edges[i][0];
        int dst = edges[i][1];
        int w   = edges[i][2];
        ((list<weighted_list>*)adj_list)[src].push_back({dst, w});
    }
}

int main(){
    vector<vector<int>> data={{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};

    weighted_graph wg(3);
    wg.read_adj_list(data);
    std::cout<< "done\n";
}
