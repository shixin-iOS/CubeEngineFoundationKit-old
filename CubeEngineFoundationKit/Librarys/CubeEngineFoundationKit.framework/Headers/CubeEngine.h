//
//  CubeEngine.h
//  CubeEngineFoundationKit
//
//  Created by jianchengpan on 2018/5/8.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <CubeEngineFoundationKit/CubeUserService.h>
#import <CubeEngineFoundationKit/CubeMessageService.h>
#import <CubeEngineFoundationKit/CubeGroupService.h>
#import <CubeEngineFoundationKit/CubeCallService.h>
#import <CubeEngineFoundationKit/CubeConferenceService.h>
#import <CubeEngineFoundationKit/CubeFileService.h>
#import <CubeEngineFoundationKit/CubeEngineWorkType.h>
#import <CubeEngineFoundationKit/CubeConfig.h>
#import <CubeEngineFoundationKit/CubeMediaService.h>
#import <CubeEngineFoundationKit/CubeWhiteBoardService.h>
#import <CubeEngineFoundationKit/CubeShareDesktopService.h>
#import <CubeEngineFoundationKit/CubeNetworkMonitorService.h>
#import <CubeEngineFoundationKit/CubeSettingService.h>

@interface CubeEngine : NSObject

/**
 引擎单例

 @return 单例
 */
+ (CubeEngine *)sharedSingleton;

/**
 当前生效的配置实例
 */
@property (nonatomic, readonly) CubeConfig *config;

@property (nonatomic, assign) CubeEngineWorkType currentWork;

#pragma mark - manage engine

/**
 启动引擎，引擎完成初始化操作
 
 @param cubeConfig 引擎配置文件
 */
- (BOOL)startWithCubeConfig:(CubeConfig *)cubeConfig;

/** 停止引擎，引擎停止所有工作，并释放内存。
 *
 * 此方法用于停止引擎，将引擎置为关闭状态。
 * 调用该方法后引擎将关闭各项功能，并释放内存。
 *
 * @note 此方法必须在 UI 线程中调用。
 */
- (void)shutdown;

/** 暂停引擎工作。
 *
 * 暂停引擎工作时，引擎会暂停所有正在进行的实时协作操作。
 *
 * @see UIApplicationDelegate#applicationWillResignActive 或者 UIApplicationDelegate#applicationWillEnterForeground 被回调时应当调用该方法。
 */
- (void)sleep;

/** 恢复引擎工作。
 *
 * 恢复引擎时，引擎会恢复到工作状态。
 *
 * @see UIApplicationDelegate#applicationDidBecomeActive 或者 UIApplicationDelegate#applicationDidEnterBackground 被回调时应当调用该方法。
 */
- (void)wakeup;

#pragma mark - config engine

/** 注册 APNS。
 *
 * @param application 应用上下文。
 * @param deviceToken 设备标识。
 */
- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;

#pragma mark - manage current work

/**
 记录开始工作的类型

 @note 引擎当前记录有工作事，会阻止引擎进入休眠
 
 @param workType 工作类型
 */
-(void)workStarted:(CubeEngineWorkType)workType;

/**
 记录结束工作的类型

 @param workType 工作类型
 */
-(void)workEnded:(CubeEngineWorkType)workType;

/**
 要求结束指定的工作类型

 @param workType 工作类型
 */
-(void)stopWork:(CubeEngineWorkType)workType;

#pragma mark - get service

/**
 获取网络检测服务

 @return 网络检测服务
 */
-(id<CubeNetworkMonitorService>)networkMonitorService;

/**
 获取用户服务

 @return 用户服务
 */
-(id<CubeUserService>)userService;

/**
 获取设置服务

 @return 设置服务
 */
-(id<CubeSettingService>)settingService;

/**
 获取消息服务

 @return 消息服务
 */
-(id<CubeMessageService>)messageService;

/**
 获取群组服务

 @return 群组服务
 */
-(id<CubeGroupService>)groupService;

/**
 获取一对一通话服务

 @return 通话服务
 */
-(id<CubeCallService>)callService;

/**
 会议服务

 @return 会议服务
 */
-(id<CubeConferenceService>)conferenceService;

/**
 获取媒体服务

 @return 媒体服务
 */
-(id<CubeMediaService>)mediaService;

/**
 白板服务

 @return 白板服务
 */
-(id<CubeWhiteBoardService>)whiteBoardService;


/**
 文件服务

 @return 文件服务
 */
-(id<CubeFileService>)fileService;

/**
 远程桌面服务

 @return 远程桌面服务
 */
- (id<CubeShareDesktopService>)shareDesktopService;

#pragma mark - tool

/**
 判断是否有访问某种设备的权限，如果没有，则自动申请权限，申请完成后，通过回掉通知
 
 @param mediaType 权限类型
 @param completeHandler 完成回掉
 @return 是否需要申请权限,YES，表示未申请，接下来会自动申请，NO，表示申请
 */

- (BOOL)shouldRequestAccessForMediaType:(NSString *)mediaType andRequestCompleteHandler:(void(^)(BOOL granted))completeHandler;

@end
