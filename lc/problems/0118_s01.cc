#include "../heads.h"
#include <vector>

/* row
 *  1       1
 *  2      1 1         edges must be 1 
 *  3     1 2 1        2=(n-1)*1
 *  4    1 3 3 1       3=(n-2)*1+1
 *  5   1 4 6 4 1      4=(n-3)*1+1 6=3*2
 *
 */

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> triangle;
    triangle.push_back({1});
    if (numRows == 1)
        return triangle;
    triangle.push_back({1,1});
    
    for(int i=3; i<=numRows; i++) {
        vector<int> row(i);
        row[0]=1;
        for(int j=1; j<i/2; j++) {
            row[j] = triangle[i-2][j-1] + triangle[i-2][j];
        }
        /* j4 r3=r */
        for(int j=i; j>i/2; j--) {
            row[j-1] = row[i-j];
        }
        if(i%2){
            row[i/2] = triangle[i-2][i/2-1] + triangle[i-2][i/2];
        }
        triangle.push_back(row);
    }

    return triangle;
}

int main() {
    vector<vector<int>> p = generate(5);
    for(auto i:p){
        for(auto j:i)
            cout << j << " ";
        cout << endl;
    }


}
