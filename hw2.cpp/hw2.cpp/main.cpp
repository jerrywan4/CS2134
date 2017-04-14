//
//  main.cpp
//  hw2.cpp
//
//  Created by Jerry Wan on 2/28/17.
//  Copyright © 2017 Jerry Wan. All rights reserved.
//

#include <iostream>
#include <ctime>

using namespace std;

class Timer {
    double start;
public:
    void timer(){start = clock();}
    double elapsed(){return(clock() - start) / CLOCKS_PER_SEC;}
    void reset(){start = clock();}
    
};

bool is_prime1(int n){
    if (n == 2){
        return true;
    }
    for (int m = 2; m < n-1; m++){
        is_prime1(m);
        if (n % m == 0){
            return false;
        }
    }
    return true;
}

int count_primes1(int n){
    int count = 0;
    for (int m = 2; m < n; m++){
        if (is_prime1(m))
            count += 1;
    }
    return count;
}

bool is_prime2(int n) {
    if (n == 2) { return true; }
    for (int m = 2; m < n-1; m++) { // O(n)
        if (n % m == 0) { return false; }
    }
    return true;
}

int count_primes2(int n) {
    int count = 0;
    for (int m = 2; m < n; m++){
        if (is_prime2(m))
            count += 1;
    }
    return count;
}

bool is_prime3(int n){
    if (n == 2) { return true; }
    for (int m = 2; m*m <= n; m++) { // O(sqrt(n))
        if (n % m == 0) { return false; }
    }
    return true;
}

int count_primes3(int n){
    int count = 0;
    for (int m = 2; m < n; m++){
        if (is_prime3(m))
            count += 1;
    }
    return count;
}

int main() {
    int method = -1;
    int n;
    int count;
    Timer c;
    double time;
    
    while (method != 0) {
        cout << "Which method (1,2,3 or 0=exit): ";
        cin >> method;
        
        if (method == 1) {
            cout << "Enter the value of n: ";
            cin >> n;
            
            c. reset();
            c.timer();
            count = count_primes1(n);
            time = c.elapsed();
            
            cout << "There are " << count << " prime numbers between 2 and " << n << endl;
            cout << "Time to compute: approx. " << time << endl;
            method = -1;
        }
        else if (method == 2) {
            cout << "Enter the value of n: ";
            cin >> n;
            
            c. reset();
            c.timer();
            count = count_primes2(n);
            time = c.elapsed();
            
            cout << "There are " << count << " prime numbers between 2 and " << n << endl;
            cout << "Time to compute: approx. " << time << endl;
            method = -1;
        }
        else if (method == 3) {
            cout << "Enter the value of n: ";
            cin >> n;
            
            c. reset();
            c.timer();
            count = count_primes3(n);
            time = c.elapsed();
            
            cout << "There are " << count << " prime numbers between 2 and " << n << endl;
            cout << "Time to compute: approx. " << time << endl;
            method = -1;
        }
        else if (method == 0) {
            cout << "Thank you." << endl;
            break;
        }
    }
}

/*
 Written assignment
 =======================
 
 1)
            m1 time(s)  |   m2 time(s)  |   m3 time(s)
 n
 100        0.365385        8e-06           3e-06
 1000                       .000396         3.8e-05
 2000                       .00141          8.9e-05
 5000                       .007731         .000284
 10000                      .023875         .000701
 20000                      .083076         .001826
 50000                      .457506         .005897
 100000                     1.84838         .011828
 
 2)
 
 Time complexity of:
 is_prime2: O(n)
 is_prime3: O(sqrt(n))
 
 3)
 
 log(n^5)                     == O(log(n))
 300n^2 + 20n + n^4           == O(n^4)
 n * log(n+12)                == O(nlog(n))
 100n + 4n^2 + 12log(n)       == O(n^2)
 log(n) + n/100               == O(log(n))
 sqrt(6n) * (log(n) + 10)     == O(sqrt(n)log(n))
 n + (n-1) + (n-2) + ... + 1  == O(n)
 
 4)
 
 a) O(n^2)
 
 b) O(n*sqrt(n))
 
 c) O(log n)

*/
