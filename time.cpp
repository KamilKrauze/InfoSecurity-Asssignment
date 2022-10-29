// CPP program to print current date and time
// using chronos.
#include <chrono>
#include <ctime>
#include <iostream>
  
using namespace std;
  
int main()
{
    time_t timeNow = chrono::system_clock::to_time_t(chrono::system_clock::now());
    struct tm * timeInfo = localtime(&timeNow);
    cout << timeInfo->tm_hour << endl;
}