#include <iostream>
#include <vector>

#define LIMIT 100

using namespace std;

bool* getPrimes() {
    static bool isPrime[LIMIT];
    fill(isPrime,  isPrime+LIMIT, true);

    for(int i = 0; i < LIMIT; ++i) {
        if(isPrime[i] && i != 0 && i != 1) {
            int j = i*2;
            while(j < LIMIT) {
                isPrime[j] = false;
                j += i;
            }
        }
    }
    return isPrime;
}

int main(){
    bool *isPrime = getPrimes();

    for(int i = 0; i < LIMIT; ++i) {
        if(isPrime[i]) {
            cout<<i<<endl;
        }
    }
    
    return 0;
}
