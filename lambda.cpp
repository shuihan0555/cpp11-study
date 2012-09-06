#include <iostream>
#include <cstdlib>

using namespace std;

#define DUMP(hint) cout << hint << " a = " << a << ", b = " << b << ", c = " << c << endl;

void lambda_capture_test(){
    int a = 1, b = 2, c = 3;
    DUMP("default by copy before called:");
    [=](){
        //compile error for modifying read only parameters
        //a += 1;
        //b *= 2;
        //c -= 3;
    }();
    DUMP("default by copy after called:");

    DUMP("default by ref before called:");
    [&](){
        a += 1;
        b *= 2;
        c -= 3;
    }();
    DUMP("default by ref after called:");
    
    a = b = c = 2;
    DUMP("default copy, ref a&b  before called:");
    [=, &a, &b](){
        a += 2;
        b *= 3;
        //Readonly c can't be modified
        //c -= 1;
    }();
    DUMP("default copy, ref a&b  after called:");
    
    [&a, &b](){
        a += 2;
        b *= 3;
        //explicit binding - no access to other variables
        //c -= 1;
    }();
}

int main(int argc, const char *argv[])
{
    lambda_capture_test();    
    return 0;
}
