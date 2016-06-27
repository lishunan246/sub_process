#include <iostream>

#include "SubProcess.h"
using namespace std;

int main() {
    auto& s=SubProcess::Instance();
    auto x= s.create("/bin/ping","/bin/ping","10.10.0.21");
    auto x2= s.create("/bin/ping","/bin/ping","khgf");

    if(x== nullptr)
        cout << "error" << endl;
    else
    {
        cout << "p1!" << endl;
        s.is_running(x);
    }
    if(x2== nullptr)
        cout << "error" << endl;
    else
        cout << "p2!" << endl;

    std::cout<<"current running: "<<s.count()<<std::endl;
    sleep(5);

    if(x)
        s.terminate(x);

    sleep(3);
    if(x)
        s.is_running(x);
    std::cout<<"current running: "<<s.count()<<std::endl;
    sleep(3);
    if(x2)
        s.terminate(x2);
    sleep(1);
    std::cout<<"current running: "<<s.count()<<std::endl;
    return 0;
}