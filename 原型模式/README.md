<!--
 * @Author: your name
 * @Date: 2022-03-15 22:07:58
 * @LastEditTime: 2022-03-15 22:15:45
 * @LastEditors: your name
 * @Description: 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * @FilePath: \undefinedg:\vscode\c++\Design Mode\原型模式\README.md
-->
# Design-Mode-PrototypeMode.h
原型模式的优点：
1.原型模式是二进制流的拷贝，因此要比new一个对象的性能要好很多
2.逃避构造函数的约束，直接在内存中拷贝，拷贝构造函数是不会执行的

原型模式的使用场景:
1.类的初始化需要非常多的资源
2.new一个对象需要非常繁琐的数据准备或访问权限
3.一个对象可以给其他对象访问，其他对象又要修改他

经常和工厂模式一起混用，我觉得c++里面拷贝构造函数就可以实现一个原型模式，需要注意的问题是深拷贝和浅拷贝的问题