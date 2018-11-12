//
//  CubeGroupUtil.h
//  CubeEngineFoundationKit
//
//  Created by 美少女 on 2018/5/25.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CubeGroupType.h"

@interface CubeGroupUtil : NSObject
/**
 获取群组类型对应字符串

 @param type 群组类型
 @return string
 */
+ (NSString *)toGroupTypeString:(CubeGroupType )type;


/**
 获取群组类型

 @param typeString 群组类型字符串
 @return 群组类型
 */
+ (CubeGroupType )fromGroupTypeString:(NSString *)typeString;

@end
