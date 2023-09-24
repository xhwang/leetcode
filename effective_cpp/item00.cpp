
// C++ `declaration` is different from `definition`
//
// 1. declaration 只是表明某物(object, class, template class)的名字或类型
//
// 2. definition（定义）为编译器提供在 declaration（声明）时被省略的细节。
// 对于一个 object（对象），definition（定义）是编译器为 object（对象）留出内存的地方。
// 对于一个 function（函数）或一个 function template（函数模板），definition（定义）提供代码本体。
// 对于一个 class（类）或一个 class template（类模板），definition（定义）列出了 class（类）或者 template（模板）的 members（成员）

// 3. initialization 初始化是设定 object 第一个值的过程。
// user-defined type object, 初始化通过 default constructor 完成
// default constructor 可以不需要任何参数，或者参数都有默认值。
