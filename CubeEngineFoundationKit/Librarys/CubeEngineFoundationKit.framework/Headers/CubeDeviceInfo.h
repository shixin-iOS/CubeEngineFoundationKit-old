//
//  CubeDeviceInfo.h
//  CubeEngineFoundationKit
//
//  Created by jianchengpan on 2018/5/8.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CubeEngineFoundationKit/CubeJsonObject.h>

@interface CubeDeviceInfo : NSObject<CubeJSONObject>

/**
 用户ID
 */
@property (nonatomic, copy) NSString *cubeId;

/**
 设备名
 */
@property (nonatomic, copy) NSString *name;

/**
 当前系统版本
 */
@property (nonatomic, copy) NSString *version;

/**
 系统平台信息
 */
@property (nonatomic, copy) NSString *platform;

/**
 综合信息
 */
@property (nonatomic, copy) NSString *userAgent;

/**
 设备ID
 */
@property (nonatomic, copy) NSString *deviceId;

/**
 推送凭证
 */
@property (nonatomic, copy) NSString *deviceToken;

/**
 获取当前设备信息

 @return 设备信息
 */
+(CubeDeviceInfo *)currentDeviceInfo;

@end
