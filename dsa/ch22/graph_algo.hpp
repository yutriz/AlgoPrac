#include <list>
#include <queue>
#include <vector>
#include <string.h>

#include "misc.hpp"

using namespace std;


/* 
 * directed or undirected
 * current: directed graph without loop
 */
class graph {
  public:
    const int n_vertex;
    void *adj_list;
    
    graph(int n):n_vertex(n){}

    void read_adj_list(vector<vector<int>>);    
    void print_adj_matrix(vector<vector<int>>);
    void bfs(int src);
    

    void topological_sort();

};

struct weighted_list {
    int to_node;
    int weight;
};

class weighted_graph: public graph {
  public:
    weighted_graph(int n):graph(n){};
    void read_adj_list(vector<vector<int>>);    
    void print_adj_matrix(vector<vector<int>>);
    void bfs(int src);
};


void weighted_graph::print_adj_matrix(vector<vector<int>> edges) {
    int **matrix;
    matrix = new int*[n_vertex];
    for(int i=0; i<n_vertex; i++)
        matrix[i] = new int[n_vertex];
    cout << "before read\n";
    for(int i=0; (size_t)i<edges.size(); i++) {
        int src = edges[i][0];
        int dst = edges[i][1];
        matrix[src][dst]=edges[i][2];
    }
    print_c_matrix(matrix, n_vertex, n_vertex);
}

/*
 * [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]]
 */
void graph::read_adj_list(vector<vector<int>> edges){
    adj_list = new list<int>[n_vertex]; 
    for(int i=0; (size_t)i<edges.size(); i++) {
        int src = edges[i][0];
        int dst = edges[i][1];
        list<int>* l = (list<int>*)adj_list;
        l[src].push_back(dst);
    }
}

void weighted_graph::read_adj_list(vector<vector<int>> edges){
    adj_list = new list<weighted_list>[n_vertex]; 
    for(int i=0; (size_t)i<edges.size(); i++) {
        int src = edges[i][0];
        int dst = edges[i][1];
        int w   = edges[i][2];
        list<weighted_list> *lw = (list<weighted_list>*)adj_list;
        lw[src].push_back({dst, w});
    }
}

void graph::bfs(int src) {
    /*
     * 0=WHITE, 1=GRAY, 2=BLACK
     */
    char color[n_vertex];
    int  dstc[n_vertex]; /* distance */
    int  pred[n_vertex]; /* predecessor */
    memset(color, 0, n_vertex*sizeof(char));
    memset(dstc, 0, n_vertex*sizeof(int));
    memset(pred, 0, n_vertex*sizeof(int));

    color[src] = 1;
    dstc[src] = 0;
    pred[src] = 0;

    queue<int> q;
    q.push(src);

    while(!q.empty()) {
        int n_cur = q.front();
        q.pop();
        
        list<int> *li = (list<int>*) adj_list;  
        for(auto iter=li->begin(); iter!=li->end(); iter++) {
            if(color[*iter]==0){
                color[*iter] = 1;
                dstc[*iter] = dstc[n_cur] + 1;
                pred[*iter] = n_cur;
                q.push(*iter);
            }
        }
        color[n_cur] = 2;
    }
}

void weighted_graph::bfs(int src) {
    /*
     * 0=WHITE, 1=GRAY, 2=BLACK
     */
    char color[n_vertex];
    int  dstc[n_vertex]; /* distance */
    int  pred[n_vertex]; /* predecessor */
    memset(color, 0, n_vertex*sizeof(char));
    memset(dstc, 0, n_vertex*sizeof(int));
    memset(pred, 0, n_vertex*sizeof(int));

    color[src] = 1;
    dstc[src] = 0;
    pred[src] = 0;

    queue<int> q;
    q.push(src);

    while(!q.empty()) {
        int n_cur = q.front();
        q.pop();
        
        list<weighted_list> *li = (list<weighted_list>*) adj_list;  
        for(auto iter=li->begin(); iter!=li->end(); iter++) {
            cout << "current to_node " << iter->to_node << endl;
            if(color[iter->to_node]==0){
                color[iter->to_node] = 1;
                dstc[iter->to_node] = dstc[n_cur] + iter->weight;
                pred[iter->to_node] = n_cur;
                q.push(iter->to_node);
            }
        }
        color[n_cur] = 2;
    }
    print_c_array(dstc, n_vertex);
}
