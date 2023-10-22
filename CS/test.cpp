#include <cstdio>
#include <cmath>

// int divide_power2(int x, int k) { 
// 	int is_neg = x & (1<<31); 
// 	(is_neg && (x = x + (1 << k) - 1)); 
// 	return x >> k; 
// }

// int divide_power2(int x, int k){
//     int f = (x >> 31);
//     return -(f & (-x >> k)) + (~f & (x >> k));
// }

float fpwr2(int x){
    unsigned exp, frac;
    unsigned u;

    if(x < 1-127-23){
        exp = 0;
        frac = 0;
    }
    else if(x < 1-127){
        exp = 0;
        frac = 1 << (unsigned)(x - (1 - 127 - 23));
    }
    else if(x < 127){
        exp = x + 127;
        frac = 0;
    }
    else{
        exp = 0xff;
        frac = 0;
    }
    u = exp << 23 | frac;
    return u;
}

int main(){
    
    return 0;
}