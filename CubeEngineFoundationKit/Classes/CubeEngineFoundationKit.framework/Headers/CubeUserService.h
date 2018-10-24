//
//  CubeUserService.h
//  CubeEngineFoundationKit
//
//  Created by jianchengpan on 2018/5/8.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <CubeEngineFoundationKit/CubeService.h>
#import <CubeEngineFoundationKit/CubeUser.h>
#import <CubeEngineFoundationKit/CubeDeviceInfo.h>
#import <CubeEngineFoundationKit/CubeError.h>

@protocol CubeUserServiceDelegate<NSObject>

@optional

/**
 用户成功登录回掉
 
 @param user 登录用户
 */
-(void)onLogin:(CubeUser *)user;

/**
 用户成功登出回掉
 
 @param user 登出用户
 */
-(void)onLogout:(CubeUser *)user;

/**
 设备上线
 
 @param deviceInfo 上线设备
 @param onlineDeviceList 当前在线设备列表
 */
-(void)onDeviceOnline:(CubeDeviceInfo *)deviceInfo andOnlineList:(NSArray<CubeDeviceInfo *> *)onlineDeviceList;

/**
 设备下线
 
 @param deviceInfo 下线设备
 @param onlineDeviceList 当前在线设备列表
 */
-(void)onDeviceOffLine:(CubeDeviceInfo *)deviceInfo andOnlineList:(NSArray<CubeDeviceInfo *> *)onlineDeviceList;

/**
 错误回掉
 
 @param error 错误信息
 */
-(void)onUserFailed:(CubeError *)error;

/**
 更新用户信息

 @param user 用户信息 更新失败，返回nil
 @param error 错误信息 如果更新成功，返回为nil
 */
- (void)onUpdateUser:(CubeUser *)user andError:(CubeError *)error;
@end


@protocol CubeUserService <CubeService>

@property (nonatomic, readonly) CubeUser *currentUser;

@property (nonatomic, weak) id<CubeUserServiceDelegate> delegate;

/**
 登录
 
 @param cubeId 用户cube号
 @param cubeToken token
 @param displayName 显示名称
 @return 引擎是否处理成功
 */
-(BOOL)loginWithCubeId:(NSString *)cubeId andCubeToken:(NSString *)cubeToken andDisplayName:(NSString *)displayName;

/**
 登出当前用户
 @note 非强制退出,当前正在通话时会退出失败
 */
-(void)logout;

/**
 是否强制退出当前账户
 
 @note 当强制退出为YES时，用户服务，会主动挂断通话等服务
 @param force 强制退出
 */
-(void)logoutWithForce:(BOOL)force;

/**
 更新用户信息
 
 @param user 待更新的用户信息
 */
-(void)updateUser:(CubeUser *)user;

/**
 查询在线设备列表
 
 @param cubeId 带查询的用户
 @param callBack 查询回掉
 */
-(void)queryOnlineDevicesWithCubeId:(NSString *)cubeId andCallBack:(void(^)(NSArray<CubeDeviceInfo *> *DeviceList))callBack;

/**
 查询指定在线设备详情
 
 @param deviceId 设备ID
 @param callBack 查询回掉
 */
-(void)queryOnlineDeviceWithDeviceId:(NSString *)deviceId andCallBack:(void(^)(CubeDeviceInfo  *DeviceInfo))callBack;

@end
