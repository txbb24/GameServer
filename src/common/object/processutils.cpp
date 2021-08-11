/*
 * @Author: guanwenjie
 * @Date: 2021-08-11 17:38:48
 * @LastEditTime: 2021-08-11 17:48:49
 * @LastEditors: guanwenjie
 * @Description: 进程工具
 */

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
#include "processutils.h"

int32_t StartDeamon()
{
    if (fork() != 0)
    {
        // TODO stderr
        exit(1);
    }

    if (setsid() < 0)
    {
        // TODO stderr
        return -1;
    }

    if (fork() != 0)
    {
        // TODO stderr
        exit(1);
    }

    umask(0);
    signal(SIGINT, SIG_IGN);
    signal(SIGHUP, SIG_IGN);
    signal(SIGQUIT, SIG_IGN);
    signal(SIGPIPE, SIG_IGN);
    signal(SIGTTOU, SIG_IGN);
    signal(SIGTTIN, SIG_IGN);
    signal(SIGUSR1, SIG_IGN);
    signal(SIGUSR2, SIG_IGN);
    signal(SIGALRM, SIG_IGN);

    fclose(stdin);
    fclose(stdout);
    fclose(stderr);

    return 0;
}