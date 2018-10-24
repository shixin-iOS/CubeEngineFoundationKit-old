//
//  CubeGroupConfig.h
//  CubeEngineFoundationKit
//
//  Created by 美少女 on 2018/5/24.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CubeEngineFoundationKit/CubeGroupType.h>
#import <CubeEngineFoundationKit/CubeJsonObject.h>
@interface CubeGroupConfig : NSObject <CubeJSONObject>
/**
 群组管理员
 */
@property (nonatomic, strong) NSArray<NSString *> *masters;

/**
 群组成员
 */
@property (nonatomic, strong) NSArray<NSString *> *members;

/**
 邀请账号
 */
@property (nonatomic, strong) NSArray<NSString *> *invites;

/**
 绑定群组
 */
@property (nonatomic, strong) NSString * bindGroupId;

/**
 群组有效期
 */
@property (nonatomic, assign) long long expired;

/**
 群组名称
 */
@property (nonatomic, strong) NSString *displayName;

/**
 群组类型：会议，桌面共享，白板，直播
 @note  CubeGroupType define
 */
@property (nonatomic, assign) NSString *type;

/**
 群组最大人数
 */
@property (nonatomic, assign) long long maxNumber;

/**
 是否开放入群
 */
@property (nonatomic, assign) BOOL isOpen;

/**
 构造方法

 @param type 群组类型
 @param displayName 群组名称
 @return self
 */
- (instancetype)initWithGroupType:(NSString *)type withDisplayName:(NSString *)displayName;
@end
