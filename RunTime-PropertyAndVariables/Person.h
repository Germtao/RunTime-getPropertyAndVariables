//
//  Person.h
//  RunTime-PropertyAndVariables
//
//  Created by TAO on 2017/9/28.
//  Copyright © 2017年 Billow. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Person : NSObject
{
    NSString *address;
}
@property (nonatomic, strong) NSString *name;
@property (nonatomic, assign) NSInteger age;

/**
 *  遍历获取 Person 类所有的成员变量 IvarList
 */
- (void)getAllIvarList;

/**
 *  遍历获取 Person 类所有的属性 Property
 */
- (void)getAllProperty;

@end
