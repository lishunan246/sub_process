//
// Created by lishunan on 16-6-27.
//

#ifndef SUB_PROCESS_SUBPROCESS_H
#define SUB_PROCESS_SUBPROCESS_H


#include <iostream>
#include <cstring>
#include <unordered_map>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include "SubProcessHandle.h"

class SubProcess{
public:
    static SubProcess& Instance()
    {
        static SubProcess instance;
        return instance;
    };
    SubProcess(SubProcess const&) = delete;
    SubProcess(SubProcess&&) = delete;
    SubProcess& operator=(SubProcess const&) = delete;
    SubProcess& operator=(SubProcess &&) = delete;

    SubProcessHandle::ptr create(const char *pathname, const char * argv,const char* a);
    bool terminate(SubProcessHandle::ptr hdl);
    bool is_running(SubProcessHandle::ptr hdl);
    size_t count();
protected:
    SubProcess();
    ~SubProcess(){}

private:
    static void sigchld_handler(int signum);

    std::unordered_map<int,SubProcessHandle::ptr > _handles;
};




#endif //SUB_PROCESS_SUBPROCESS_H
