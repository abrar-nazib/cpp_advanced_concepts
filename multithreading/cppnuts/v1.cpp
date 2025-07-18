#include<iostream>
#include <ratio>
#include<thread>
#include<chrono>
#include<algorithm>

using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;

ull OddSum = 0;
ull EvenSum = 0;


void findEven(ull start, ull end){
    for (ull i = start; i <= end; ++i){
        if((i&1)==0){
            EvenSum += i;
        }
    }
}

void findOdd(ull start, ull end){
    for (ull i = start; i <= end; ++i){
        if((i&1)==1){
            OddSum += i;
        }
    }
}

int main(){
    ull start = 0, end=190000000;

    auto startTime = high_resolution_clock::now();
    
    std::thread t1(findEven, start, end);
    std::thread t2(findOdd, start, end);
    
    t1.join();
    t2.join();

    // findOdd( start,  end);
    // findEven(start, end);
    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);

    cout << "OddSum: " << OddSum << "\n";
    cout << "EvenSum: " << EvenSum << "\n";
    cout << "Time took: " << duration.count()/1000000 << "\n";
    return 0;

}