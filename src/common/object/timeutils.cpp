/*
 * @Author: guanwenjie
 * @Date: 2021-08-11 17:04:09
 * @LastEditTime: 2021-08-11 17:35:31
 * @LastEditors: guanwenjie
 * @Description: 时间工具
 */

#include <sys/time.h>
#include "timeutils.h"


void Msleep(unsigned long ulMillisecond)
{
    timeval stTV;
    stTV.tv_sec = ulMillisecond / 1000;
    stTV.tv_usec = (ulMillisecond % 1000) * 1000;
    
    select(0, nullptr, nullptr, nullptr, &stTV);
}