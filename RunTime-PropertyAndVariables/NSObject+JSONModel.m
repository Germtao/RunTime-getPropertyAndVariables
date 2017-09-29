//
//  NSObject+JSONModel.m
//  RunTime-PropertyAndVariables
//
//  Created by TAO on 2017/9/28.
//  Copyright © 2017年 Billow. All rights reserved.
//

#import "NSObject+JSONModel.h"
#import <objc/objc-runtime.h>

@implementation NSObject (JSONModel)

- (instancetype)initWithDict:(NSDictionary *)dict {
    
    if (self = [self init]) {
        //  1. 获取类的属性及属性对应的类型
        NSMutableArray *keys = [NSMutableArray array];
        NSMutableArray *attributes = [NSMutableArray array];
        
        /**
         *  🌰例子:
         *        name = value3 attribute = T@"NSString",C,N,V_value3
         *        name = value4 attribute = T^i,N,V_value4
         */
        
        unsigned int outCount;
        objc_property_t *propertyList = class_copyPropertyList([self class], &outCount);
        
        for (unsigned int i = 0; i < outCount; i++) {
            objc_property_t property = propertyList[i];
            
            // 1. 通过 property_getName 函数获取属性名
            NSString *propertyName = [NSString stringWithCString:property_getName(property)
                                                        encoding:NSUTF8StringEncoding];
            [keys addObject:propertyName];
            
            // 2. 通过 property_getAttributes 函数可以获取属性名和 encode 编码
            NSString *propertyAttribute = [NSString stringWithCString:property_getAttributes(property)
                                                             encoding:NSUTF8StringEncoding];
            [attributes addObject:propertyAttribute];
        }
        
        //  立即释放 propertyList 指向的内存
        free(propertyList);
        
        //  2. 根据类型给属性赋值
        for (NSString *key in keys) {
            if ([dict valueForKey:key] == nil) continue;
            
            [self setValue:[dict valueForKey:key] forKey:key];
        }
    }
    
    return self;
}

@end
