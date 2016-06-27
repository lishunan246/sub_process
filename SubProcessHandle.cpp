//
// Created by lishunan on 16-6-27.
//

#include "SubProcessHandle.h"

SubProcessHandle::ptr SubProcessHandle::create(pid_t pid) {
    return std::make_shared<SubProcessHandle>(pid);
}

SubProcessHandle::SubProcessHandle(pid_t pid):_pid(pid) {}

