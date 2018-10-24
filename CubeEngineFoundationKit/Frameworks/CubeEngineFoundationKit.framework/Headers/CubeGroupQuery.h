//
//  CubeGroupQuery.h
//  CubeEngineFoundationKit
//
//  Created by 美少女 on 2018/5/24.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CubeEngineFoundationKit/CubeGroupPageInfo.h>
#import <CubeEngineFoundationKit/CubeGroup.h>
@interface CubeGroupQuery : NSObject

/**
分页信息
 */
@property (nonatomic, strong)  CubeGroupPageInfo         * page;

/**
 群组集合
 */
@property (nonatomic, strong) NSArray <CubeGroup *>  *    groups;

@end
