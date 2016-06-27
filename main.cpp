#include <iostream>

#include "SubProcess.h"
using namespace std;

int main() {
    char path[]=  "/bin/ping";
    char *arg[]={"baidu.com"};
    char* env[]= {NULL};

    char path2[]=  "/bin/ping";
    char *arg2[]={"baidu.com"};
    char* env2[]= {NULL};

    SubProcess s;
    auto x= s.create(path,arg,env);
    auto x2= s.create(path2,arg2,env2);
    s.get_status(x);
    if(x== nullptr)
        cout << "error" << endl;
    else
        cout << "Hello, 1!" << endl;
    if(x2== nullptr)
        cout << "error" << endl;
    else
        cout << "Hello, 2!" << endl;
    sleep(5);
    s.terminate(x);

    sleep(1);
    s.terminate(x2);
    sleep(1);
    s.get_status(x);
    return 0;
}