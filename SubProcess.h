//
// Created by lishunan on 16-6-27.
//

#ifndef SUB_PROCESS_SUBPROCESS_H
#define SUB_PROCESS_SUBPROCESS_H

#include <memory>
#include <iostream>
#include <cstring>
#include <set>

#include "SubProcessHandle.h"

class SubProcess{
public:

    SubProcessHandle::ptr create(const char *pathname, char *const argv[],char *const envp[])
    {
        pid_t childPid;
        switch (childPid=fork())
        {
            case -1:
                std::cout<<strerror(errno)<<std::endl;
                return nullptr;
            case 0:

                if(execve(pathname,argv,envp)==-1)
                {
                    std::cout<<strerror(errno)<<std::endl;
                    return nullptr;
                }
                break;
            default:
                break;

        }
        auto h= SubProcessHandle::create(childPid);
        _handles.insert({h});
        return h;
    }

    bool terminate(SubProcessHandle::ptr hdl)
    {
        if(kill(hdl->_pid,SIGTERM)==0)
        {
            return true;
        }
        else
        {
            std::cout<<strerror(errno)<<std::endl;
            return false;
        }
    }

    void get_status(SubProcessHandle::ptr hdl)
    {
        if(kill(hdl->_pid,0)==0)
        {
            std::cout<<"live"<<std::endl;
        }
        else
        {
            if(errno==ESRCH)
                std::cout<<"died"<<std::endl;
        }
    }

    SubProcess()
    {
        if(signal(SIGCHLD,SubProcess::sigchld_handler)==SIG_ERR)
        {
            std::cout<<strerror(errno)<<std::endl;
        }
    }

    ~SubProcess()
    {

    }

private:
    static void sigchld_handler(int signum)
    {
        pid_t pid;
        int   status;
        while ((pid = waitpid(-1, &status, WNOHANG)) >0)
        {
            std::cout<<"pid: "<<pid<<" returns "<<status<<std::endl;
            //unregister_child(pid, status);   // Or whatever you need to do with the PID
        }
    };

    std::set<SubProcessHandle::ptr > _handles;
};



#endif //SUB_PROCESS_SUBPROCESS_H
