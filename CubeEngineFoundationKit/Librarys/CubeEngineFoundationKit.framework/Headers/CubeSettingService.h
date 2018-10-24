//
//  CubeSettingService.h
//  CubeEngineFoundationKit
//
//  Created by jianchengpan on 2018/9/17.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <CubeEngineFoundationKit/CubeService.h>
#import <CubeEngineFoundationKit/CubeSetting.h>
@class CubeError;
/**
 设置服务代理
 */
@protocol CubeSettingServiceDelegate <NSObject>

/**
 通知设置已更新

 @param config 新的通知设置
 */
-(void)onNotifyConfigUpdated:(CubeNotifyConfig *)config;

/**
 免打扰设置已更新

 @param config 新的免打扰设置
 */
-(void)onDisturbConfigUpdated:(CubeDisturbConfig *)config;

/**
 添加新的置顶会话

 @param topSessions 新的置顶列表
 @param sessionId 新置顶的会话ID
 */
-(void)onTopSessionAdded:(NSDictionary<NSString *,NSNumber *> *)topSessions addedSession:(NSString *)sessionId;

/**
 移除置顶会话

 @param topSessions  新的置顶会话
 @param sessionId 移除的置顶会话ID
 */
-(void)onTopSessionRemoved:(NSDictionary<NSString *,NSNumber *> *)topSessions removedSession:(NSString *)sessionId;

/**
 添加新的静音会话

 @param muteSessions 新的静音列表
 @param sessionId 新增的静音会话ID
 */
-(void)onMuteSessionAdded:(NSDictionary<NSString *,NSNumber *> *)muteSessions addedSession:(NSString *)sessionId;

/**
 移除静音会话

 @param muteSessions 新的静音列表
 @param sessionId 移除的静音会话ID
 */
-(void)onMuteSessionRemoved:(NSDictionary<NSString *,NSNumber *> *)muteSessions removedSession:(NSString *)sessionId;

/**
设置错误

 @param error 错误
 */
- (void)onSettingFailed:(CubeError *)error;
@end


/**
 设置服务
 */
@protocol CubeSettingService <CubeService>

/**
 设置代理
 */
@property (nonatomic, weak) id<CubeSettingServiceDelegate> delegate;

/**
 获取当前用户的设置
 */
@property (nonatomic, readonly) CubeSetting *setting;

/**
  更新通知设置

 @param config  通知设置
 @return 处理结果
 */
-(BOOL)updateNotifyConfig:(CubeNotifyConfig *)config;

/**
 更新免打扰设置

 @param config 免打扰设置
 @return 令处理结果
 */
-(BOOL)updateDisturbConfig:(CubeDisturbConfig *)config;

/**
 更新deviceToken

 @param deviceToken deviceToken
 @return 指令处理结果
 */
-(BOOL)updateDeviceToken:(NSString *)deviceToken;

/**
  添加置顶会话

 @param sessionId CubeId 或者 GroupId
 @return 指令处理结果
 */
-(BOOL)addTopSession:(NSString *)sessionId;

/**
 移除置顶会话

 @param sessionId CubeId 或者 GroupId
 @return 处理结果
 */
-(BOOL)removeTopSession:(NSString *)sessionId;

/**
 添加静音会话

 @param sessionId CubeId 或者 GroupId
 @return 处理结果
 */
-(BOOL)addMuteSession:(NSString *)sessionId;

/**
  移除静音会话

 @param sessionId CubeId 或者 GroupId
 @return 处理结果
 */
-(BOOL)removeMuteSession:(NSString *)sessionId;

@end
