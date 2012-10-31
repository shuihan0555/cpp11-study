#include <cstdlib>
#include <iostream>
#include <chrono>
#include <future>
#include <thread>

using namespace std;
using namespace std::chrono;

void test_stability(){
    cout << "System clock is steady:" << boolalpha << system_clock::is_steady << endl;
    cout << "High resolution clock is steady:" << boolalpha << high_resolution_clock::is_steady << endl;
}

void test_prof(){
    auto sum = 0.0;
    auto start = high_resolution_clock::now();
    auto future = async([&](){
            for (double i = 1; i < 100000; i++) {
                sum += 1.0/(i*i);
            }
        });
    auto schedule = high_resolution_clock::now();
    future.get();
    auto end = high_resolution_clock::now();

    cout << "Calculated sum is:" << sum << endl;
    cout << "Schedule time is " << chrono::duration<double, milli>(schedule - start).count() 
         << " ms, and total time is " << chrono::duration<double, milli>(end - start).count() 
         << " ms" << endl;
}

int main(int argc, const char *argv[]){
    test_stability(); 
    test_prof();
    return 0;
}
