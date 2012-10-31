#include <cstdlib>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;


int main(int argc, const char *argv[])
{
    cout << "Test emplace_back and variadic for pair" << endl;
    vector<pair<string, int>> aVec {{"initializer1", 0}, {"initializer2", 1}};
    aVec.emplace_back("This is a string", 10);
    aVec.emplace_back("Another string", 11);
    for (auto v : aVec){
        cout << "First:" << v.first << ", second:" << v.second << endl;
    }

    cout << "---------------------\nTest variadic for tuple" << endl;
    vector<tuple<string, int, double>> bVec;
    bVec.emplace_back("index1", 1, 1.0);
    bVec.emplace_back("index2", 11, 1.1);
    for (auto v : aVec){
        cout << "First:" << v.first << ", second:" << v.second << endl;
    }

    cout << "---------------------\nTest variadic for nullptr" << endl;
    pair<int*, double> p{0, 1.1f}; //SFINAE
    pair<int*, double> p1{nullptr, 1.1f}; //this is better

    return 0;
}
