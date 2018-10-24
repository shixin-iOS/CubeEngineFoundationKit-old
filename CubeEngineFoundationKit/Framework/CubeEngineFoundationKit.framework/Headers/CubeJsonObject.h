//
//  CubeJsonObject.h
//  CubeEngineFoundationKit
//
//  Created by jianchengpan on 2018/5/10.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol CubeJSONObject

/**
 对象转字典

 @return 字典
 */
-(NSMutableDictionary *)toDictionary;

/**
 字典转对象

 @param dic 字典
 @return 对象
 */
+(id)fromDictionary:(NSDictionary *)dic;

@optional

/**
 映射字段定义
 
 映射字典数据结构如下:
 {
 @"属性名1":@"[自定义的key1]"
 @"属性名2":@"[自定义的key2,自定义的key3,...,自定义的keyN]"
 }
 
 生成字典时，默认使用 属性名 作为key，当定义自定义key后，会使用自定义的key
 生成或更新对象时，将字典里面的 自定义key 的值设置到对应的 属性名 上
 
 当一个属性名对应多个自定义键时，json化时会将多个键当成一直嵌套的字典中的键:例如
 映射 @"属性名":@"[自定义的key1,自定义的key2]" 属性名对应的值会映射到一下value:
		{
		"自定义的key1":{
					  "自定义的key2":"value"
					  }
		}
 
 @return 映射字典
 */
+(NSDictionary *)keysMap;


#pragma mark toDic tools

/**
 忽略属性列表
 
 供工具使用
 
 @return 忽略列表
 */
+(NSArray<NSString *> *)ignoredProperties;

/**
 获取属性值
 
 关联和聚合属性，可以使用此方法返回该属性的字典
 不实现此方法时，工具获取属性值使用 valueForKey:
 
 @param property 属性名
 @return 属性值，返回nil，则暂时忽略此属性
 */
-(id)valueForProperty:(NSString *)property;

#pragma mark fromDic tool

/**
 设置属性值

 @note 不实现此方法则使用 setValue:forKey: 方法
 
 @param value 值
 @param property 属性
 */
-(void)setValue:(id)value forProperty:(NSString *)property;

@end
