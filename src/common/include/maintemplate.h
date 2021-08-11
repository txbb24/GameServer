/*
 * @Author: guanwenjie
 * @Date: 2021-08-11 11:44:52
 * @LastEditTime: 2021-08-11 17:13:39
 * @LastEditors: guanwenjie
 * @Description: 主函数模板
 */

#pragma once

#include <stdint.h>
#include <signal.h>
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
void CMainTemplate<ConcreteServer>::Run(int32_t arc, char *argv[])
{
    // 启动参数

    // 信号
    signal(SIG_EXIT, HandleSignal);

    // Server启动
    ConcreteServer &rServer = CSingleton<ConcreteServer>::GetInstance();
    rServer.Init();
    rServer.MainLoop(g_dwSignal);
}