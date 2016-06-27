//
// Created by lishunan on 16-6-27.
//

#include "SubProcess.h"

SubProcessHandle::ptr SubProcess::create(const char *pathname, const char * argv,const char* a)
{
    pid_t childPid;
    switch (childPid=fork())
    {
        case -1:
            std::cout<<"fork: "<<strerror(errno)<<std::endl;
            return nullptr;
        case 0:
            if(execl(pathname,argv,a)==-1)
            {
                std::cout<<"exec error: "<<strerror(errno)<<std::endl;
                exit(-1);
            }
            break;
        default:
            break;

    }

    auto h= SubProcessHandle::create(childPid);
    if(h)
    {
        _handles.insert({childPid,h});
    }
    return h;
}

bool SubProcess::terminate(SubProcessHandle::ptr hdl)
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

bool SubProcess::is_running(SubProcessHandle::ptr hdl) {
    std::cout<<"pid "<<hdl->_pid;
    if(kill(hdl->_pid,0)==0)
    {
        std::cout<<" live"<<std::endl;
        return true;
    }
    else
    {
        if(errno==ESRCH)
            std::cout<<" died"<<std::endl;
        else
            std::cout<<" status ???"<<std::endl;

        return false;
    }
}

SubProcess::SubProcess() {
    if(signal(SIGCHLD,SubProcess::sigchld_handler)==SIG_ERR)
    {
        std::cout<<"init: "<< strerror(errno)<<std::endl;
    }
}

void SubProcess::sigchld_handler(int) {
    pid_t pid;
    int   status;
    while ((pid = waitpid(-1, &status, WNOHANG)) >0)
    {
        std::cout<<"pid: "<<pid<<" returns "<<status<<std::endl;
        SubProcess::Instance()._handles.erase(pid);
    }
}

size_t SubProcess::count() {
    return _handles.size();
}





