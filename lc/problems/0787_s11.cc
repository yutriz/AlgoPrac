#include "../heads.h"
#include <list>
#include <vector>

/* Dijkstra */
int f(int n, vector<vector<int>>& flight, 
      int src, int dsti, int k){
      struct adj_info {
          int dst;        
          int weight;     
      };          
      list<adj_info>* vinfo = new list<adj_info>[n];
      for(int i=0; i<flight.size(); i++){         
          int c1 = flight[i][0];         
          int c2 = flight[i][1];         
          int w  = flight[i][2];         
          vinfo[c1].push_back(adj_info{c2, w});     
      }



}
