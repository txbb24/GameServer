/*
 * @Author: guanwenjie
 * @Date: 2021-08-11 15:26:15
 * @LastEditTime: 2021-08-17 15:13:32
 * @LastEditors: guanwenjie
 * @Description: Server进程模板
 */

#pragma once

#include <stdint.h>
#include <string>

enum E_SERVER_STATUS
{
    E_SERVER_STATUS_INIT = 0,
    E_SERVER_STATUS_RUN,
    E_SERVER_STATUS_RELOAD,
    E_SERVER_STATUS_EXIT
};

class CServerTemplate
{
public:
    CServerTemplate() {}
    ~CServerTemplate() {}

    int32_t Init(const std::string &strServerType, const std::string &strServerName, const std::string &strConfPath, bool bDeamon);
    int32_t MainLoop(int32_t &dwSignal);

    virtual void OnExitBegin() {}
    virtual bool CheckExitFinish() { return true; }

private:
    E_SERVER_STATUS m_eStatus;
};