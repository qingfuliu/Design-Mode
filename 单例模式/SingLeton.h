/*
 * @Author: your name
 * @Date: 2022-03-15 22:21:39
 * @LastEditTime: 2022-03-15 22:31:22
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \Design Mode\单例模式\SingLeton.h
 */
#include<mutex>
//懒汉模式
class SingLeton{
public:
    SingLeton(const SingLeton&)=delete;
    SingLeton&operator=(const SingLeton&)=delete;
    SingLeton(SingLeton&&)=delete;
    SingLeton&operator=(SingLeton&&)=delete;
    SingLeton&getInstance(){
        // 用c++11的特性
        static SingLeton singleton;
        return singleton;
        //双层判空
        if(instance==nullptr){
            std::lock_guard<std::mutex>Lock(m_mutex);
            if(instance==nullptr){
                instance=new SingLeton;
            }
        }
        return *instance;
    }
private:
    SingLeton(){}///在此实例化自己
    static SingLeton*instance;
    static std::mutex m_mutex;
};