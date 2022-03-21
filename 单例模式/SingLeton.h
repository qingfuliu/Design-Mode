/*
 * @Author: your name
 * @Date: 2022-03-15 22:21:39
 * @LastEditTime: 2022-03-18 18:12:49
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \Design Mode\单例模式\SingLeton.h
 */
#include <mutex>
//懒汉模式
class SingLeton
{
public:
    SingLeton(const SingLeton &) = delete;
    SingLeton &operator=(const SingLeton &) = delete;
    SingLeton(SingLeton &&) = delete;
    SingLeton &operator=(SingLeton &&) = delete;
    SingLeton &getInstance()
    {
        // 用c++11的特性
        static SingLeton singleton;
        return singleton;
        //双层判空  可以预防高并发模式下线程对锁争抢，减少上下文切换
        if (instance == nullptr)
        {
            // std::lock_guard<std::mutex> Lock(m_mutex);
            if (instance == nullptr)
            {
                instance = new SingLeton;
            }
        }
        return *instance;
    }

private:
    SingLeton() {} ///在此实例化自己
    static SingLeton *instance;
    // static std::mutex m_mutex;
};

class SingLeton2
{
public:
    SingLeton2(const SingLeton2 &) = delete;
    SingLeton2 &operator=(const SingLeton2 &) = delete;
    SingLeton2(SingLeton2 &&) = delete;
    SingLeton2 &operator=(SingLeton2 &&) = delete;
    static SingLeton2& getInstance(){
        return  m_Instance;
    }
private:
    SingLeton2(){}
    ~SingLeton2(){}
public:
    static SingLeton2 m_Instance;
};


//模板单例模式 陈硕muduo网络库
template<class T>
class SingLetonT{
public:
    SingLetonT(const SingLetonT&)=delete;
    SingLetonT(const SingLetonT&&)=delete;
    SingLetonT& operator=(const SingLetonT&)=delete;
    SingLetonT& operator=(SingLetonT&&)=delete;
    static T& getInstance(){
        static T instance;
        return intance;

        // if(m_instance==nullptr){
        //     std::lock_guard<std::mutex>Lock(m_mutex);
        //     if(m_instance==nullptr){
        //         m_instance.reset(new T);
        //     }
        // }
        // return *m_instance;
    }
private:
    // static std::unique_ptr<T>m_instance;
    // static std::mutex m_mutex;
};
// template<class T>
// std::unique_ptr<T> SingLetonT<T>::m_instance;
// template<class T>
// std::mutex SingLetonT<T>::m_mutex;
class Example{
public:
    void aaa9();
};

// SingLetonT<Example>::getInstance();