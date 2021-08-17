/*
 * @Author: guanwenjie
 * @Date: 2021-08-11 11:44:52
 * @LastEditTime: 2021-08-17 15:13:02
 * @LastEditors: guanwenjie
 * @Description: 主函数模板
 */

#pragma once

#include <stdint.h>
#include <signal.h>
#include <unistd.h>
#include <string>
#include "singleton.h"
#include "serverdefine.h"

static int32_t g_dwSignal = 0;

void HandleSignal(int32_t nSignal)
{
    switch (nSignal)
    {
    case SIG_EXIT:
        g_dwSignal |= SERVER_SIGNAL_EXIT;
        break;
    default:
        break;
    }
}

template<class ConcreteServer>
class CMainTemplate
{
public:
    void Run(int32_t argc, char *argv[]);
};

template<class ConcreteServer>
void CMainTemplate<ConcreteServer>::Run(int32_t argc, char *argv[])
{
    // 启动参数
    int nCh;
    char szOpt[] = "t:n:c:d";
    std::string strServerType = "", strServerName = "", strConfPath = "";
    bool bDeamon = false;
    while ((nCh = getopt(argc, argv, szOpt)) != -1)
    {
        switch (nCh)
        {
        case 't':
            strServerType = optarg;
            break;
        case 'n':
            strServerName = optarg;
            break;
        case 'c':
            strConfPath = optarg;
            break;
        case 'd':
            bDeamon = true;
            break;
        default:
            break;
        }
    }
    if (strServerType == "" || strServerName == "" || strConfPath == "")
    {
        fprintf(stderr, "[ERROR] start server failed, please check startup paramters.\n");
        return;
    }

    // 信号
    signal(SIG_EXIT, HandleSignal);

    // Server启动
    ConcreteServer &rServer = CSingleton<ConcreteServer>::GetInstance();
    rServer.Init(strServerType, strServerName, strConfPath, bDeamon);
    rServer.MainLoop(g_dwSignal);
}