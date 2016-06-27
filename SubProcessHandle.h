//
// Created by lishunan on 16-6-27.
//

#ifndef SUB_PROCESS_SUBPROCESSHANDLE_H
#define SUB_PROCESS_SUBPROCESSHANDLE_H

#include <unistd.h>
#include <iostream>
#include <memory>

class SubProcess;

class SubProcessHandle: public std::enable_shared_from_this<SubProcessHandle> {
public:
    friend class SubProcess;
    using ptr=std::shared_ptr<SubProcessHandle>;

    SubProcessHandle(SubProcessHandle const&) = delete;
    SubProcessHandle(SubProcessHandle&&) = delete;
    SubProcessHandle& operator=(SubProcessHandle const&) = delete;
    SubProcessHandle& operator=(SubProcessHandle &&) = delete;
    SubProcessHandle(pid_t pid);
    static ptr create(pid_t pid);

private:

    pid_t _pid;
};




#endif //SUB_PROCESS_SUBPROCESSHANDLE_H
