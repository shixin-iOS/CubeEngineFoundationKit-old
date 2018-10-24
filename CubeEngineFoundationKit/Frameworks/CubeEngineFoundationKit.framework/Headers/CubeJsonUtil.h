//
//  CubeJsonUtil.h
//  CubeEngineFoundationKit
//
//  Created by jianchengpan on 2018/5/9.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CubeEngineFoundationKit/CubeJsonObject.h>

@interface CubeJsonUtil : NSObject

/**
 将对象翻译成字典

 @param obj 待处理的对象
 @return 字典
 */
+(NSMutableDictionary *)translateObjectToDictionay:(id)obj;

/**
 将字典转成对象

 @param cls 对象具体类
 @param dic 字典
 @return 对象
 */
+(id)generateObjectOfClass:(Class)cls fromDictionary:(NSDictionary *)dic;

/**
 使用字典更新值

 @param obj 待更新对象
 @param dic 字典
 */
+(void)updateObject:(id)obj withDictionary:(NSDictionary *)dic;


@end
