//
//  CubeService.h
//  CubeEngineFoundationKit
//
//  Created by jianchengpan on 2018/5/8.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CubeEngineFoundationKit/CubeConnectionState.h>
#import <CubeEngineFoundationKit/CubeServiceState.h>
#import <CubeEngineFoundationKit/CubeEngineWorkType.h>

@protocol CubeService <NSObject>

#pragma mark - state

/**
 工作状态
 */
@property (nonatomic, assign) CubeServiceState state;

/**
 连接状态
 */
@property (nonatomic, assign) CubeConnectionState connectionState;

#pragma mark - manage service

/**
 启动服务
 */
+(void)start;

/**
 停止服务
 */
+(void)shutdown;

@optional

/**
 暂停工作
 */
-(void)sleep;

/**
 恢复工作
 */
-(void)wakeup;

/**
 停止指定工作类型

 @param work 指定工作类型
 */
-(void)shouldStopWork:(CubeEngineWorkType)work;

@end
