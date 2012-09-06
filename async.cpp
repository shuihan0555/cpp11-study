#include <cstdlib>
#include <iostream>
#include <future>
#include <thread>

using namespace std;

void write_message(const std::string& msg){
    std::cout << msg;
}

void testAsync(){
    auto f = std::async(std::launch::async, write_message, "hello world from std::async! Launch policy is: async\n");
    write_message("hello world from main thread!\n");
    getchar();
    f.wait();
}

void testDeferred(){
    auto f = std::async(std::launch::deferred, write_message, "hello world from std::async!, Launch policy is: deferred\n");
    write_message("hello world from main thread!\n");
    getchar();
    f.wait();
}

int main(int argc, const char *argv[])
{
    cout << "Test async method!" << endl;
    testAsync();

    cout << "Test deferred method!" << endl;
    testDeferred();
    return 0;
}
