//
//  CubeGroupMember.h
//  CubeEngineGroupKit
//
//  Created by zhangdi on 2018/5/15.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <CubeEngineFoundationKit/CubeUser.h>
#import <CubeEngineFoundationKit/CubeMemberRole.h>

@interface CubeGroupMember : CubeUser <CubeJSONObject>
/**
 群备注名称
 */
@property (nonatomic, strong) NSString *remarkName;

/**
 群成员角色
 */
@property (nonatomic, assign) CubeMemberRole role;

/**
 加入时间
 */
@property (nonatomic, assign) long long joinTime;

/**
 邀请时间
 */
@property (nonatomic, assign) long long inviteTime;


/**
 在什么设备上加入的群组，如果是管理员直接添加则以最近登录的设备ID为准。
 */
@property (nonatomic, strong) NSString *deviceId;

/**
 初始化

 @param cubeId cube号
 @return self
 */
- (instancetype)initGroupMemerWithCubeId:(NSString *)cubeId;

/**
 群成员角色

 @param role 角色
 @return string
 */
+ (NSString *)getCubeMemerRoleString:(CubeMemberRole)role;
@end
