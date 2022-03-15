/*
 * @Author: your name
 * @Date: 2022-03-15 22:01:28
 * @LastEditTime: 2022-03-15 22:19:34
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \undefinedg:\vscode\c++\Design Mode\原型模式\PrototypeMode.h
 */
class Copyable{
public:
    Copyable()=default;
    virtual ~Copyable(){}
    virtual Copyable*Clone()=0;
};
class class1 : public Copyable{
public:
    class1(){}
    class1(const class1&){}
    ~class1(){}
    Copyable* Clone(){
        return  new class1(*this);
    }
};


