#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>

#define LIMIT 1000

using namespace std;

bool* getPrimes() {
    static bool isPrime[LIMIT];
    fill(isPrime,  isPrime+LIMIT, true);

    for(int i = 0; i < sqrt(LIMIT); ++i) {
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
    cout<<"[*] Calculating primes"<<endl;

    string filename("primes.txt");
    fstream file;
    // erases content in previous file
    file.open(filename, ofstream::out | ofstream::trunc);
    file.close();

    // Opens file for writing
    file.open(filename, std::ios_base::app | std::ios_base::in);

    cout<<"[*] Writing primes to file"<<endl;

    for(int i = 0; i < LIMIT; ++i) {
        if(isPrime[i]) {
            file<<i<<endl;
        }
    }
    file.close();
    cout<<"[*] Done!"<<endl;

    return 0;
}
