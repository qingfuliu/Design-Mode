/*
 * @Author: your name
 * @Date: 2022-03-17 18:11:19
 * @LastEditTime: 2022-03-17 18:37:28
 * @LastEditors: Please set LastEditors
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \Design Mode\建造者模式\builderSchemas.cpp
 */
//内部类的实现方式
#include <string>
class Product
{
public:
    Product(const std::string &param1);
    Product() {}
    class Builder
    {
    public:
        Product* Build()
        {
            return new Product(*this);
        }
        Builder &setParam1(const std::string &param1)
        {
            this->param1 = param1;
            return *this;
        }
        Builder &setParam2(const std::string &param2)
        {
            this->param2 = param1;
            return *this;
        }
        Builder &setParam3(const std::string &param2)
        {
            this->param1 = param2;
            return *this;
        }
        std::string getParam1() const;
        std::string getParam2() const;
        std::string getParam3() const;

    private:
        std::string param1;
        std::string param2;
        std::string param3;
    };

public:
    void setParam1();
    void setParam2();
    void setParam3();
    std::string getParam1();
    std::string getParam2();
    std::string getParam3();

private:
    Product(const Builder &builder)
    {
        this->param1 = builder.getParam1();
        this->param2 = builder.getParam2();
        this->param3 = builder.getParam3();
    }
    //只有参数一是必要的，其他都是可选的
    std::string param1;
    std::string param2;
    std::string param3;
};
//继承实现方式 有一个抽象的构造类
class Builder
{
public:
    Builder() { m_product = new Product; }
    virtual ~Builder() {}
    void setParam1(const std::string &param1);
    void setParam2(const std::string &param2);
    void setParam3(const std::string &param3);
    Product *getProduct() { return m_product; }

private:
    Product *m_product;
};
class ConcreteBuilder
{
public:
    ConcreteBuilder() {}
    //需要提供具体的实现
    void setParam1(const std::string &param1);
    void setParam2(const std::string &param2);
    void setParam3(const std::string &param3);

private:
};
class Diretcor
{
public:
    Diretcor()
    {
    }
    void setBuilder(Builder *);
    void createProduct()
    {
        m_builder->setParam1("...");
        m_builder->setParam2("...");
        m_builder->setParam3("...");
    }

private:
    Builder *m_builder;
};
//使用方法
Product *product = Product::Builder()
                       .setParam1("asdf")
                       .setParam2("sadasd")
                       .setParam3("asfas")
                       .Build();
