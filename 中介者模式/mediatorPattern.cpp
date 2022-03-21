/*
 * @Autor: qing fu liu
 * @Email: 1805003304@qq.com
 * @Github: https://github.com/qingfuliu
 * @Date: 2022-03-21 21:49:21
 * @LastEditors: qingfu liu
 * @LastEditTime: 2022-03-21 21:54:57
 * @FilePath: \Design Mode\中介者模式\mediatorPattern.cpp
 * @Description: 
 */
class Collage1{
public:
    Collage1():m_mediaor(nullptr){

    }
    void setMediaor(AbstractMediaor*);
    ///调用自己的方法，不需要和终结者进行交互
    void doSelfFunction();
    ///依赖于其他类，需要通过终结者进行
    void doSelfFunction2();

private:
    AbstractMediaor*m_mediaor;
};
///同事角色2
class Collage2{
public:
    Collage2(){}
private:
    AbstractMediaor*m_mediaor;
};
class AbstractMediaor{
public:
    AbstractMediaor(){}
    virtual ~AbstractMediaor(){}
        
private:

};
//中介者
class Mediaor{
public:
    Mediaor(){}
     ~Mediaor(){}
    void doSOmething1();//业务代码一
    void doSOmething2();//业务代码二
    void set1(Collage1*);
    void set2(Collage2*);
private:
    Collage1    *Collage1_;
    Collage2    *Collage2_;
};