//
//  CubeSetting.h
//  CubeEngineFoundationKit
//
//  Created by jianchengpan on 2018/9/17.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CubeEngineFoundationKit/CubeJsonObject.h>

/**
 通知设置
 */
@interface CubeNotifyConfig : NSObject<CubeJSONObject>

/**
 是否提醒
 */
@property (nonatomic, assign) BOOL isAlerts;

/**
 isDetails
 */
@property (nonatomic, assign) BOOL isDetails;

/**
 是否开启声音
 */
@property (nonatomic, assign) BOOL isSound;

/**
 是否开启震动
 */
@property (nonatomic, assign) BOOL isVibrate;

/**
 最近更新时间
 */
@property (nonatomic, assign) long long updateTime;

@end



/**
 免打扰设置
 */
@interface CubeDisturbConfig : NSObject<CubeJSONObject>

/**
 是否开启面打扰
 */
@property (nonatomic, assign) BOOL isNotDisturb;

/**
 开始时间
 */
@property (nonatomic, copy) NSString * startTime;

/**
 结束时间
 */
@property (nonatomic, copy) NSString * endTime;

/**
 最近更新时间
 */
@property (nonatomic, assign) long long updateTime;

@end


/**
 设置
 */
@interface CubeSetting : NSObject<CubeJSONObject>

/**
 置顶列表
 */
@property (nonatomic, strong) NSMutableDictionary<NSString *,NSNumber *> *topList;

/**
 静音列表
 */
@property (nonatomic, strong) NSMutableDictionary<NSString *,NSNumber *> *muteList;

/**
 通知设置
 */
@property (nonatomic, strong) CubeNotifyConfig *notify;

/**
 免打扰设置
 */
@property (nonatomic, strong) CubeDisturbConfig *disturb;

/**
 deviceToken
 */
@property (nonatomic, copy) NSString *deviceToken;

/**
 最近更新时间
 */
@property (nonatomic, assign) long long updateTime;

@end
