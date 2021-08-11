/*
 * @Author: guanwenjie
 * @Date: 2021-08-11 15:44:29
 * @LastEditTime: 2021-08-11 17:49:46
 * @LastEditors: guanwenjie
 * @Description: server模板
 */

#include "servertemplate.h"
#include "serverdefine.h"
#include "timeutils.h"
#include "processutils.h"

int32_t CServerTemplate::Init()
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
        if (dwSignal & SERVER_SIGNAL_EXIT != 0)
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