#include <iostream>

#include "graph_algo.hpp"

int main(){
    vector<vector<int>> data={{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};

    weighted_graph wg(4);
    wg.read_adj_list(data);
    wg.bfs(1);
    std::cout<< "done\n";
}
