#include "misc.hpp"

using namespace std;

void insert_sort(vector<int>& arr) {
    int key;
    for(int j=1; (unsigned int)j<arr.size(); j++){
        key = arr[j];
        int i = j-1;
        while(i>=0 && arr[i]>key){
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;
    }
}

void insert_sort_reverse(vector<int>& arr) {
    int key;
    for(int j=1; (unsigned int)j<arr.size(); j++){
        key = arr[j];
        int i = j-1;
        while(i>=0 && arr[i]<key){
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;
    }
}


int main() {
    vector<int> origin = random_array(15);
    print_array(origin);
    insert_sort_reverse(origin);
    print_array(origin);


}



