#include "heads.h"
#include <bitset>
#include <iomanip>
#include <cmath>


int mySqrt(int x) {
  
    float num = (float) x;
    float half = num/2;
    float y = num;
    int i = *(int*) &y;
    i = 0x1fbd1df5 + (i>>1);
    y = * (float*) &i;
    y = y/2 + half/y;
    y = y/2 + half/y;
    
    i = (int)y;
    if(i*i>x)
        i--;

    return i;
}

float Q_rsqrt( float number )  
{  
   long i;  
   float x2, y;  
   const float threehalfs = 1.5F;  
 
   x2 = number * 0.5F;  
   y  = number;  
   i  = * ( long * ) &y;                       // evil floating point bit level hacking  
   i  = 0x5f3759df - ( i >> 1 );               // what the fuck?  
   y  = * ( float * ) &i;  
   y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration  
// y = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed  
 
   return y;  
}

int main(){
    float f = 114514.8964;
    int x=2147395599;
    cout << mySqrt(x) << endl;

    cout << fixed << setprecision(12) << pow(x, 0.5) << endl;
}
