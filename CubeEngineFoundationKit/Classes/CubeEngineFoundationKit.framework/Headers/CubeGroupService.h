//
//  CubeGroupService.h
//  CubeEngine
//
//  Created by zhangdi on 2018/5/15.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#ifndef CubeGroupService_h
#define CubeGroupService_h
#import <CubeEngineFoundationKit/CubeService.h>
@class CubeError;
@class CubeGroup;
@class CubeUser;
@class CubeGroupConfig;
@class CubeGroupPageInfo;
@class CubeGroupQuery;

@protocol CubeGroupServiceDelegate<NSObject>
@optional
/**
 当组操作错误时回调

 @param error 错误信息
 */
- (void)onGroupFailed:(CubeError *)error;

/**
 当创建组成功时回调

 @param group 群组
 @param from 发起人
 */
- (void)onGroupCreated:(CubeGroup *)group fromUser:(CubeUser *)from;

/**
 当组销毁时回调

 @param group  群组
 @param from 发起人
 */
- (void)onGroupDestroyed:(CubeGroup *)group fromUser:(CubeUser *)from;
/**
 当退出群组回调

 @param group 群组
 @param from 发起人
 */
- (void)onGroupQuited:(CubeGroup *)group fromUser:(CubeUser *)from;
/**
  群组数据更新

 @param group 群组
 @param from 发起人
 */
- (void)onGroupUpdated:(CubeGroup *)group fromUser:(CubeUser *)from;

/**
  当组添加成员时回调

 @param group 群组
 @param from 添加者
 @param addMembers 被添加列表
 */
- (void)onMemberAddedWithGroup:(CubeGroup *)group fromUser:(CubeUser *)from withAddMembers:(NSArray <CubeUser *>*)addMembers;

/**
  当组移除成员时回调

 @param group 群组
 @param from 移除者
 @param removedMembers 被移除列表
 */
- (void)onMemberRemovedWithGroup:(CubeGroup *)group fromUser:(CubeUser *)from withRemovedMembers:(NSArray <CubeUser *>*)removedMembers;

/**
 当组添加管理员时回调

 @param group 群组
 @param from 添加者
 @param addedMasters 被添加管理员列表
 */
- (void)onMasterAddedWithGroup:(CubeGroup *)group fromUser:(CubeUser *)from withAddMasters:(NSArray <CubeUser *>*)addedMasters;

/**
 当组移除管理员时回调

 @param group 群组
 @param from 移除者
 @param removedMasters  被移除管理员列表
 */
- (void)onMasterRemovedWithGroup:(CubeGroup *)group fromUser:(CubeUser *)from withRemovedMasters:(NSArray <CubeUser *>*) removedMasters;

/**
 * 有人申请入群时回调，仅群主和管理员（主持人）收到申请回调
 *
 * @param group   群组实体
 * @param applier 申请者
 */
- (void)onGroupApplied:(CubeGroup *)group withApplier:(CubeUser *)applier;

/**
  同意申请加入时回调

 @param group 群组
 @param from 同意者
 @param applier 申请者
 */
- (void)onGroupApplyJoinedWithGroup:(CubeGroup *)group fromUser:(CubeUser *)from withApplier:(CubeUser *)applier;

/**
 拒绝申请请入群回调

 @param group 群组
 @param rejectMember 拒绝加入成员
 */

/**
 拒绝申请请入群回调

 @param group 群组
 @param from 拒绝者
 @param applier 被拒绝成员
 */
- (void)onGroupRejectApplied:(CubeGroup *)group fromUser:(CubeUser *)from withApplier:(CubeUser *)applier;


/**
 * 收到邀请回调(仅邀请者自己和被邀请者收到)
 *
 * @param group   群组实体
 * @param from    邀请者
 * @param invites 被邀请列表
 */
- (void)onGroupInvited:(CubeGroup *)group fromUser:(CubeUser *)from withInvites:(NSArray <CubeUser *> *)invites;

/**
 拒绝要邀请入群回调

 @param group 群组
 @param rejectMember 拒绝成员
 */
- (void)onGroupRejectInvited:(CubeGroup *)group fromUser:(CubeUser *)from withRejectMember:(CubeUser *)rejectMember;

/**
 * 同意邀请加入时回调
 *
 * @param group        群组实体
 * @param from         邀请者
 * @param joinedMember 同意者
 */
- (void)onGroupInviteJoined:(CubeGroup *)group fromUser:(CubeUser *)from withJoinMember:(CubeUser *)joinedMember;

//***********************************扩展监听 多终端在线情况下****************************************/

/**
 同账号在其他设备创建群组

 @param group 群组实体
 @param from  群组创建者
 */
- (void)onGroupCreatedOther:(CubeGroup *)group fromUser:(CubeUser *)from;

/**
 同账号在其他设备销毁群组

 @param group 群组实体
 @param from 群组销毁者
 */
- (void)onGroupDestroyedOther:(CubeGroup *)group fromUser:(CubeUser *)from;

/**
  同账号在其他设备发起邀请

 @param group  群组实体
 @param from 邀请者
 @param invites  被邀请列表
 */
- (void)onGroupInvitedOther:(CubeGroup *)group fromUser:(CubeUser *)from withInvites:(NSArray <CubeUser *> *)invites;

/**
 同账号在其他设备拒绝邀请

 @param group 群组实体
 @param from 邀请者
 @param rejectMember 拒绝者
 */
- (void)onGroupRejectInvitedOther:(CubeGroup *)group fromUser:(CubeUser *)from withRejectMember:(CubeUser *)rejectMember;

/**
 同账号在其他设备加入群组

 @param group 群组实体
 @param from  邀请者
 @param joinedMember  同意者
 */
- (void)onGroupInviteJoinedOther:(CubeGroup *)group fromUser:(CubeUser *)from withJoinMember:(CubeUser *)joinedMember;
/**
 * 同账号在其他设备退出群组
 *
 * @param group 群组实体
 * @param from  群组销毁者
 */
- (void)onGroupQuitedOther:(CubeGroup *)group fromUser:(CubeUser *)from;
@end

@protocol CubeGroupService <CubeService>

/**
 群组服务代理
 */
@property (nonatomic, weak) id<CubeGroupServiceDelegate> delegate;

/**
 创建群组
 
 @param config 群组信息
 */
- (BOOL)createGroupWithGroup:(CubeGroupConfig *)config;

/**
 退出群组

 @param groupId 群组ID
 */
- (BOOL)quitGroupWithGroupId:(NSString *)groupId;
/**
 删除群组
 
 @param groupId 群组ID
 */
- (BOOL)destroyGroupWithGroupId:(NSString *)groupId;

/**
 添加组成员
 
 @param groupId 群组Id
 @param members 群成员
 */
- (BOOL)addMembersWithGroupId:(NSString *)groupId withMembers:(NSArray <NSString *>*)members;

/**
 删除组成员
 
 @param groupId 群组Id
 @param members 群成员
 */
- (BOOL)removeMembersWithGroupId:(NSString *)groupId withMembers:(NSArray <NSString *> *)members;

/**
 邀请组成员
 
 @param groupId 群组Id
 @param members 群成员
 */
- (BOOL)inviteMembersWithGroupId:(NSString *)groupId withMembers:(NSArray <NSString *>*)members;

/**
  拒绝邀请

 @param groupId 群组Id
 @param cubeId 邀请者Id
 */
- (BOOL)rejectInviteWithGroupId:(NSString *)groupId withCubeId:(NSString *)cubeId;

/**
 接受邀请

 @param groupId 群组Id
 @param cubeId 邀请者Id
 */
- (BOOL)acceptInviteWithGroupId:(NSString *)groupId withCubeId:(NSString *)cubeId;

/**
 * 添加管理员
 *
 * @param groupId 群组Id
 * @param masters 管理员列表
 */
- (BOOL)addMastersWithGroupId:(NSString *)groupId withMasters:(NSArray <NSString *>*)masters;
/**
 * 删除管理员
 *
 * @param groupId 群组Id
 * @param masters 管理员列表
 */
- (BOOL)removeMastersWithGroupId:(NSString *)groupId withMasters:(NSArray <NSString *>*)masters;

/**
 * 申请加入群组
 *
 * @param groupId 群组Id
 */
- (BOOL)applyJoinGroupWithGroupId:(NSString *)groupId;

/**
 拒绝申请

 @param groupId 群组Id
 @param cubeId cubeID
 */
- (BOOL)rejectApplyWithGroupId:(NSString *)groupId withCubeId:(NSString *)cubeId;

/**
 同意申请

 @param groupId 群组Id
 @param cubeId cubeId
 */
- (BOOL)acceptApplyWithGroupId:(NSString *)groupId withCubeId:(NSString *)cubeId;

/**
 * 修改群组
 * （暂时不做）
 * @param group 群组
 */
- (BOOL)updateGroupWithGroup:(CubeGroup *) group;

/**
 * 是否为群组
 *
 * @param strJson json
 * @return YES /NO
 */
- (BOOL)isGroupWithJson:(NSString *)strJson;

/**
 * 是否为群组
 *
 * @param group 群组
 * @return YES/NO
 */
- (BOOL)isGroupWithGroup:(CubeGroup *)group;

/**
 * 解析群组
 *
 * @return 群组
 */
- (CubeGroup *)parseJsonStr:(NSString *)strJson;

/**
查询单个组详情

 @param groupIds 群组Id
 @param block 回调
 */
- (void)queryGroupDetails:(NSArray *)groupIds andBlock:(void (^)(NSArray <CubeGroup *> *groups))block;

/**

 @param offset 分页
 @param count 每页条数
 @param block 回调
 */
- (void)queryGroups:(int)offset andCount:(int)count andBlock:(void (^)(CubeGroupQuery *groupQuery))block;

/**
 * 是否是当前设备发起的指令
 * 例：多终端同时在线时，收到创建群组回调时可以使用
 @return 群组
 */
- (BOOL)isSelf:(CubeGroup *)group;
@end
#endif /* CubeGroupService_h */
