
#include <iostream>
#include <vector>
#include <math.h>


long countZeros(long m, long n, int index, long zeroCount) {
    
 //    om pos(10, index) är större än m, räkna upp till första ettan dyker fram
    long powTenIndex = 1;
    for(int i = 0; i < index; i++) {
        powTenIndex *= 10;
    }
    
    long powTenIndexPlusOne = powTenIndex*10;
    long diff = n - m;
    long start = m;
    if(powTenIndex > m && powTenIndex != 1) {
        long newDiff = diff - powTenIndex;
        start = m + diff - newDiff;
        diff = newDiff;
    }
    
    if(diff < 0) {
        return zeroCount;
    }
    
    int digit = (start / powTenIndex) % 10;
    
    long completeSwitches = diff / powTenIndexPlusOne;
    long totalSwitches = completeSwitches * powTenIndex;
    
    long restAfterCompleteSwitches = diff % powTenIndexPlusOne;
    
    int finalDigit = ((start+restAfterCompleteSwitches) / powTenIndex) % 10;
    
    if(digit == 0 && finalDigit == 0) {
        long toAdd;
        if(restAfterCompleteSwitches <= powTenIndex) {
            toAdd = restAfterCompleteSwitches + 1;
        } else {
            toAdd = powTenIndex - (powTenIndexPlusOne - restAfterCompleteSwitches) + 1;
        }
        totalSwitches += toAdd;
    } else if(digit == 0){
        long filteredVal = start % powTenIndex;
        long toAdd = powTenIndex - filteredVal;
        totalSwitches += toAdd;
    } else if(finalDigit == 0) {
        long finalVal = start+restAfterCompleteSwitches;
        long filteredVal = finalVal % powTenIndex;
        long toAdd = filteredVal + 1;
        totalSwitches += toAdd;
    
    } else if(finalDigit < digit || (finalDigit == digit && restAfterCompleteSwitches >powTenIndex)) {
        totalSwitches += powTenIndex;
    }
    
    return countZeros(m, n,index + 1, zeroCount + totalSwitches);
}

long countZeros(long m, long n) {
    return countZeros(m, n, 0, 0);
}

int main(int argc, const char * argv[])
{
    long m, n;

    while(true){
        scanf("%li %li", &m, &n);
        if(m < 0){
            break;
        }
        long zeros = countZeros(m, n);
        printf("%li\n", zeros);
    }
    return 0;
}

