#include "heads.h"
#include <vector>
#include "misc.hpp"

vector<int> plusOne(vector<int>& digits) {
    bool carry_up = 1;
    int i;
    for(i=digits.size()-1; i>=0&&carry_up; i--) {
        if(carry_up && digits[i]==9){
            digits[i] = 0;
            carry_up = 1;
        } else {
            digits[i]++;
            carry_up = 0;
        }
    }
    if(i==-1 && carry_up) 
        digits.insert(digits.begin(), 1);
    return digits;

}

int main() {
    vector<int> d{9,9,9,9,9,9};
    print_vector(plusOne(d));
}


