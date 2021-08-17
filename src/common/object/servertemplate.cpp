/*
 * @Author: guanwenjie
 * @Date: 2021-08-11 15:44:29
 * @LastEditTime: 2021-08-17 15:13:51
 * @LastEditors: guanwenjie
 * @Description: server模板
 */

#include "servertemplate.h"
#include "serverdefine.h"
#include "timeutils.h"
#include "processutils.h"

int32_t CServerTemplate::Init(const std::string &strServerType, const std::string &strServerName, const std::string &strConfPath, bool bDeamon)
{
    if (StartDeamon() != 0)
    {
        // TODO log
        return -1;
    }
    return 0;
}

int32_t CServerTemplate::MainLoop(int32_t &dwSignal)
{
    while(true)
    {
        if ((dwSignal & SERVER_SIGNAL_EXIT) != 0)
        {
            if (m_eStatus < E_SERVER_STATUS_EXIT)
            {
                m_eStatus = E_SERVER_STATUS_EXIT;
                OnExitBegin();
                dwSignal &= ~SERVER_SIGNAL_EXIT;
            }
        }

        if (m_eStatus == E_SERVER_STATUS_EXIT && CheckExitFinish() == true)
        {
            break;
        }
        Msleep(1);
    }
    return 0;
}