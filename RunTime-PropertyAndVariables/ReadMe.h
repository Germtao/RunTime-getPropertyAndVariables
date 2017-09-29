//
//  ReadMe.h
//  RunTime-PropertyAndVariables
//
//  Created by TAO on 2017/9/28.
//  Copyright © 2017年 Billow. All rights reserved.
//

#ifndef ReadMe_h
#define ReadMe_h

/**
 *  目录:
 *    1. 成员变量和属性到底是什么？
 *    2. 怎么通过 RunTime 获取属性
 *    3. 怎么通过 RunTime 获取成员变量？
 *    4. 成员变量和属性的区别？
 *    5. 实际应用场景是什么？
 */

/**
 *  成员变量
 *    1. 定义: 
 *           Ivar: 实例变量类型, 是一个指向 objc_ivar 结构体的指针 
 *                 typedef struct objc_ivar *Ivar;
 *    2. 相关函数:
 *           class_copyIvarList         // 获取所有成员变量
 *           ivar_getName               // 获取成员变量名
 *           ivar_getTypeEncoding       // 获取成员变量类型编码
 *           class_getInstanceVariable  // 获取指定名称的成员变量
 *           object_getIvar             // 获取某个对象成员变量的值
 *           object_setIvar             // 设置某个对象成员变量的值
 *    3. 说明:
 *           property_getAttributes函数返回objc_property_attribute_t结构体列表,
 *           objc_property_attribute_t结构体包含name和value，常用的属性如下:
 *
 *           属性类型 name 值: T value: 变化
 *           编码类型 name 值: C(copy)&(strong) W(weak)空(assign) 等 value: 无
 *           非/原子性 name 值: 空(atomic) N(Nonatomic) value: 无
 *           变量名称 name 值: V value: 变化
 *
 *           使用 property_getAttributes 获得的描述是 property_copyAttributeList 能获取到的所有的 name 和 
 *           value 的总体描述, 如 T@"NSDictionary",C,N,V_dict1
 */

/**
 *  属性
 *    1. 定义:
 *           objc_property_t: 声明的属性的类型, 是一个指向 objc_property 结构体的指针 
 *                            typedef struct objc_property *objc_property_t;
 *    2. 相关函数:
 *           class_copyPropertyList        // 获取所有属性
 *                                 说明: 使用 class_copyPropertyList 并不会获取无 @property 声明的成员变量
 *           property_getName              // 获取属性名
 *           property_getAttributes        // 获取属性特性描述字符串
 *           property_copyAttributeList    // 获取所有属性特性
 */

/**
 *  应用具体场景
 *
 *    1. Json 数据转 Model模型
 *         原理描述: 用 RunTime 提供的函数遍历 Model 自身所有属性, 如果属性在 JSON 中有对用的值, 则将其赋值。
 *
 */

/**
 *  TODO: 思考
 *
 *       1. 如何识别基本数据类型的属性并处理
 *       2. 空（nil, null）值的处理
 *       3. JSON 中嵌套 JSON (Dict/Array) 的处理
 *   
 *    尝试解决以上问题, 写出属于自己的功能完备的Json转Model库。
 */

// ==============================================
// ================== 快速归档 ====================
/**
 *  原理描述: 
 *         用 RunTime 提供的函数遍历 Model 自身所有属性, 并对属性进行 encode 和 decode 操作。
 *  核心方法:
 *         在 Model 的基类中重写方法:
 */

// ===========================
/**
 *  访问私有变量
 *
 *      OC中没有真正意义上的私有变量和方法, 要让成员变量私有, 要放在m文件中声明, 不对外暴露.
 *      如果我们知道这个成员变量的名称, 可以通过runtime获取成员变量, 再通过 getIvar 来获取它的值.
 *
 *    方法: 
 *        Ivar ivar = class_getInstanceVariable([Model class], "_str1");
 *        +
 NSString * str1 = object_getIvar(model, ivar);
 */





#endif /* ReadMe_h */
