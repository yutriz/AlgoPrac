#include "heads.h"
#include <vector>
#include <set>

/*
 * easiest
 *  set.insert(i)
 *  set.find(j)
 */


/*
 * dont use this 
 */
int getCommon(vector<int>& nums1, vector<int>& nums2) {

    if (nums1[nums1.size()-1] < nums2[0] ||
        nums2[nums2.size()-1] < nums1[0])
        return -1;

    if (nums1[0]==nums2[0])
        return nums1[0];
       
    vector<int> *n0_less;
    vector<int> *n0_greater;

    if(nums1[0]<nums2[0]){
        n0_greater = &nums2;
        n0_less    = &nums1;
    } else {
        n0_greater = &nums1;
        n0_less    = &nums2;
    }
    
    int ptr1 = 0;
    int ptr2 = n0_less->size();

    while(ptr1 < ptr2) {
        int mptr = (ptr1 + ptr2)/2;
        printf("in loop: mptr: %d\n", mptr);
        if ((*n0_less)[mptr] == (*n0_greater)[0])
            return (*n0_greater)[0];

        if ((*n0_less)[mptr] > (*n0_greater)[0]) {
            ptr2 = mptr - 1;
        } else {
            ptr1 = mptr + 1;
        }
        printf("p1: %d, p2: %d\n", ptr1, ptr2); 
    }
    
    set<int> setn1;
    set<int> setn2;
    setn1.insert(-1);
    setn2.insert(-1);
    ptr2 = 0;
    while(ptr1<(int)(n0_less->size()) || ptr2<(int)(n0_greater->size())) {
        cout << "cooco" <<endl;
        int n1 = (*n0_less)[ptr1];
        int n2 = (*n0_greater)[ptr2];
        
        if(n1==n2)
            return n1;

        if(setn2.find(n1)!=setn2.end())
            return n1;

        if(setn1.find(n2)!=setn1.end())
            return n2;
        setn2.insert(n2);
        setn1.insert(n1);

        ptr1++;
        ptr2++;
    }

    return -1;

}    
