//
//  Person.m
//  RunTime-PropertyAndVariables
//
//  Created by TAO on 2017/9/28.
//  Copyright © 2017年 Billow. All rights reserved.
//

#import "Person.h"
#import <objc/objc-runtime.h>

@implementation Person

/**
 *  遍历获取 Person 类所有的成员变量 IvarList
 */
- (void)getAllIvarList {
    unsigned int methodCount = 0;
    Ivar *ivars = class_copyIvarList([Person class], &methodCount);
    
    for (unsigned int i = 0; i < methodCount; i++) {
        Ivar ivar = ivars[i];
        const char *name = ivar_getName(ivar);
        const char *type = ivar_getTypeEncoding(ivar);
        
        NSLog(@"Person 拥有的成员变量类型为: %s, 名字为: %s", type, name);
    }
    
    free(ivars);
}

- (void)getAllProperty {
    unsigned int propertyCount = 0;
    objc_property_t *propertyList = class_copyPropertyList([Person class], &propertyCount);
    
    for (unsigned int i = 0; i < propertyCount; i++) {
        objc_property_t thisProperty = propertyList[i];
        const char *propertyName = property_getName(thisProperty);
        
        NSLog(@"Person 拥有的属性为: %s", propertyName);
    }
}

@end
