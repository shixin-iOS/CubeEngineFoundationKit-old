//
//  CubeGroup.h
//  CubeEngineGroupKit
//
//  Created by zhangdi on 2018/5/15.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <CubeEngineFoundationKit/CubeJsonObject.h>
#import <CubeEngineFoundationKit/CubeGroupType.h>
#import <CubeEngineFoundationKit/CubeGroupMember.h>

@interface CubeGroup : NSObject <CubeJSONObject>

/**
 群组类型：会议，桌面共享，白板，直播
 */
@property (nonatomic, strong) NSString *type;
/**
 群组ID
 */
@property (nonatomic, strong) NSString *groupId;

/**
 群组名称
 */
@property (nonatomic, strong) NSString *displayName;

/**
 群组头像
 */
@property (nonatomic, strong) NSString *avatar;

/**
 群主创建者
 */
@property (nonatomic, strong) NSString *founder;

/**
 群主拥有者
 */
@property (nonatomic, strong) NSString *owner;

/**
 群组创建时间
 */
@property (nonatomic, assign) long long created;

/**
 群组有效期
 */
@property (nonatomic, assign) long long expired;

/**
 群组最大人数
 */
@property (nonatomic, assign) long long maxNumber;

/**
 群组管理员
 */
@property (nonatomic, strong) NSArray<CubeGroupMember *> *masters;

/**
 群组成员
 */
@property (nonatomic, strong) NSArray<CubeGroupMember *> *members;

/**
 邀请账号
 */
@property (nonatomic, strong) NSArray<CubeGroupMember *> *invites;

/**
 来宾账号
 */
@property (nonatomic, strong) NSArray<CubeGroupMember *> *guests;

/**
 是否开放入群
 */
@property (nonatomic, assign) BOOL isOpen;

/**
 绑定群组
 */
@property (nonatomic, strong) NSString * bindGroupId;

/**
 构造方法

 @param type 群组类型
 @param displayName 群组名称
 @return self
 */
- (instancetype)initWithGroupType:(NSString *)type withDisplayName:(NSString *)displayName;

@end
