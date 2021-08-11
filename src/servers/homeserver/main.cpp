/*
 * @Author: guanwenjie
 * @Date: 2021-08-11 15:22:43
 * @LastEditTime: 2021-08-11 15:40:22
 * @LastEditors: guanwenjie
 * @Description: 启动homserver
 */

#include <stdio.h>
#include "homeserver.h"
#include "maintemplate.h"

int32_t main(int32_t argc, char *argv[])
{
    CMainTemplate<CHomeserver> *poHomeserver = new CMainTemplate<CHomeserver>();
    if (poHomeserver == nullptr)
    {
        fprintf(stderr, "ERROR: new homeserver failed.");
        return -1;
    }
    poHomeserver->Run(argc, argv);
    return 0;
}