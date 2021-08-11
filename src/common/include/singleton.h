/*
 * @Author: guanwenjie
 * @Date: 2021-08-11 14:52:45
 * @LastEditTime: 2021-08-11 15:50:38
 * @LastEditors: guanwenjie
 * @Description: 单例模板,C++ 11 以上线程安全
 */

#pragma once

template<class T>
class CSingleton
{
public:
    static T&  GetInstance();

private:
    CSingleton();
    ~CSingleton();
    CSingleton(CSingleton &other);
    void operator=(const CSingleton &);
};

template<class T>
T& CSingleton<T>::GetInstance()
{
    static T oInstance;
    return oInstance;
}