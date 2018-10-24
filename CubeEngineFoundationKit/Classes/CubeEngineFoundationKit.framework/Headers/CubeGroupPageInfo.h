//
//  CubeGroupPageInfo.h
//  CubeEngineFoundationKit
//
//  Created by 美少女 on 2018/5/24.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>
/**
 * 分页信息(分页公共工具)
 */
@interface CubeGroupPageInfo : NSObject

/**
  开始时间
 */
@property (nonatomic, assign) long long since;

/**
  //结束时间
 */
@property (nonatomic, assign) long long until;

/**
 开始页码
 */
@property (nonatomic, assign) long long offset;

/**
 每页条数
 */
@property (nonatomic, assign) long long count;

/**
 总共条数
 */
@property (nonatomic, assign) long long total;
@end


