// count prime numbers strictly less tha n.

#include <iostream>
using namespace std;

int sieveOfEratosthenes (int n) {
    if (n < 3)
        return 0;
    
    int count = 0;
    bool prime[n];

    for (int i = 2; i < n; i++) {
        prime[i] = true;
    }

    for (int i = 2; i * i < n; i++) {
        if (prime[i]) {
            for (int j = i * i; j < n; j+= i) {
                prime[j] = false;
            }
        }
    }

    for (int i = 2; i < n; i++) {
        if (prime[i]) {
            count++;
        }
    }
    return count;
}

int countPrimes (int n) {
    if (n < 3)
        return 0; // strictly less (if given in ques)
    return sieveOfEratosthenes(n);
}

int main() {
    cout << countPrimes(10) << endl;
    return 0;
}