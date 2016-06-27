//
// Created by lishunan on 16-6-27.
//

#ifndef SUB_PROCESS_SUBPROCESSHANDLE_H
#define SUB_PROCESS_SUBPROCESSHANDLE_H

#ifdef __linux__

#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <iostream>


#else

#endif

#include <memory>

class SubProcess;

class SubProcessHandle: public std::enable_shared_from_this<SubProcessHandle> {
public:
    friend class SubProcess;
    using ptr=std::shared_ptr<SubProcessHandle>;

    SubProcessHandle(pid_t pid)
    {
        _pid=pid;
    }
    static ptr create(pid_t pid)
    {
        return std::make_shared<SubProcessHandle>(pid);
    }

private:
    pid_t _pid;

};




#endif //SUB_PROCESS_SUBPROCESSHANDLE_H
