
#include <iostream>
#include <vector>
#include <math.h>


std::vector<long> getLongestSequence(long n) {
    std::vector<long> sequence = {1};
    
    for(int val = 2; val <= n; val *= 2) {
        sequence.push_back(val);
    }
    return sequence;
}

int main(int argc, const char * argv[])
{
    long n;

    scanf ("%li", &n);
    
    std::vector<long> sequence = getLongestSequence(n);
    
    printf("%lu\n", sequence.size());
    
    for(long val: sequence) {
        printf("%li ", val);
    }
    printf("\n");
    
    return 0;
}

