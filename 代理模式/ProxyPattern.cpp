/*
 * @Author: your name
 * @Date: 2022-03-17 18:57:11
 * @LastEditTime: 2022-03-17 19:30:50
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \Design Mode\代理模式\ProxyPattern.cpp
 */
//静态代理模式

class Subject
{
public:
    Subject() {}
    virtual ~Subject() {}
    virtual void request() = 0;
    virtual void request1() = 0;
};

class Player : public Subject
{
public:
    Player() {}
    void request() override {}
    void request() override {}

private:
};

class Proxy : public Subject
{
public:
    Proxy() {}
    void setPlayer(Player *);
    void request1() override { m_player->request1(); }
    void request() override { m_player->request(); }

private:
    Player *m_player;
};

#include <functional>
//----------------------动态代理----------------------//
struct AbstructProxy
{
    AbstructProxy(std::function<void(void)> f) : m_fun(std::move(f)) {}
    template <typename head>
    void Invoke(head &&value)
    {
        value.before();
        m_fun();
        value.after();
    }
    template <typename head, typename... Params>
    void Invoke(head &&head, Params &&...params)
    {
        head.before();
        Invoke(std::forward<Params>(params));
        head.after();
    }

private:
    std::function<void(void)> m_fun;
};

template <typename... AP>
void Invoke(const std::function<void()> &f)
{
    AbstructProxy msp(f); ///< 构造切面（组合）的代理对象
    msp.Invoke(AP()...);
}
#include <iostream>
struct AA
{
    void before()
    {
        std::cout << "aa before" << std::endl;
    }
    void after()
    {
        std::cout << "aa after" << std::endl;
    }
};

struct BB
{
    void before()
    {
        std::cout << "bb before" << std::endl;
    }
    void after()
    {
        std::cout << "bb after" << std::endl;
    }
};

void m_func(void)
{
}
auto func=std::bind(m_func);
int main(){
    Invoke<AA, BB>(func);
    return 0;
}