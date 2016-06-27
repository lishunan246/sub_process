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
        s.get_status(x);
    }
    if(x2== nullptr)
        cout << "error" << endl;
    else
        cout << "p2!" << endl;


    sleep(5);

    if(x)
        s.terminate(x);

    sleep(3);
    if(x)
        s.get_status(x);
    sleep(3);
    if(x2)
        s.terminate(x2);
    sleep(1);
    return 0;
}