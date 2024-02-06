#include "../heads.h"
#include <string>
#include <map>
#include <unordered_map>

class SL {
public:
    vector<vector<string>> f(vector<string>& strs){
        
        vector<char> to_be_hash(26, 0);
        unordered_map<string, vector<int>*> umap;

        for(int i=0; i<(int)strs.size(); i++){
            to_be_hash.assign(26, 0);
            for(auto si=strs[i].begin(); si!=strs[i].end(); si++)
                to_be_hash[*si-'a']++;

            const string hash_str(to_be_hash.begin(), to_be_hash.end());
            if(umap.find(hash_str) == umap.end()){
                vector<int> *p = new vector<int>;
                umap.emplace(hash_str, p);
            }
            umap[hash_str]->push_back(i);
        }
        
        vector<vector<string>> result;
        for(auto i=umap.begin(); i!=umap.end(); i++){
            vector<string> rr;
            for(auto si=i->second->begin(); si!=i->second->end(); si++){
                rr.push_back(strs[*si]);
            }
            result.push_back(rr);
        }


        return result;
    }

};

int main() {

}
