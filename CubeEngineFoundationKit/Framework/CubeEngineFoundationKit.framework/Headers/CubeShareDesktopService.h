//
//  CubeShareDesktopService.h
//  CubeEngine
//
//  Created by 美少女 on 2018/5/24.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#ifndef CubeShareDesktopService_h
#define CubeShareDesktopService_h
#import <CubeEngineFoundationKit/CubeService.h>
@class CubeShareDesktopConfig;
@class CubeShareDesktop;
@class CubeShareDesktopMember;
@class CubeError;
@class CubeRemoteView;

@protocol CubeShareDesktopServiceDelegate<NSObject>
@optional

/**
 当桌面创建时回调

 @param sd 共享消息实体
 @param fromUser 创建者user实体
 */
- (void)onShareDesktopCreated:(CubeShareDesktop *)sd fromUser:(CubeUser *)fromUser;

/**
 当桌面共享销毁时回调

 @param sd 共享消息实体
 @param fromUser 邀请者user实体
 */
- (void)onShareDesktopDestroyed:(CubeShareDesktop *)sd fromUser:(CubeUser *)fromUser;

/**
 通账号除加入设备之外的其他设备回调

 @param sd 远程桌面实体
 @param joinedMember 加入入者
 */
- (void)onShareDesktopJoined:(CubeShareDesktop *)sd fromJoinMember:(CubeUser *)joinedMember;

/**
 当离开桌面共享时回调

 @param sd 远程桌面实体
 @param fromUser 离开者user实体
 */
- (void)onShareDesktopQuitd:(CubeShareDesktop *)sd fromUser:(CubeUser *)fromUser;


/**
 收到邀请回调(仅邀请者自己和被邀请者回调)

 @param sd 共享桌面对象实例
 @param fromUser 邀请者user实体
 @param invites 被邀请列表
 */
- (void)onShareDesktopInvited:(CubeShareDesktop *)sd fromUser:(CubeUser *)fromUser andInvites:(NSArray <CubeUser *>*)invites;

/**
 同意邀请加入时回调

 @param sd 共享桌面对象实例
 @param fromUser 同意者user实体
 @param joinedMember 加入者user实体
 */
- (void)onShareDesktopInviteJoined:(CubeShareDesktop *)sd fromUser:(CubeUser *)fromUser andJoinedMember:(CubeUser *)joinedMember;

/**
 当拒绝共享桌面时回调

 @param sd 共享桌面对象实例
 @param fromUser 邀请者user实体
 @param rejectMember 拒绝者user实体
 */
- (void)onShareDesktopRejectInvited:(CubeShareDesktop *)sd fromUser:(CubeUser *)fromUser andRejectMember:(CubeUser *)rejectMember;

/**
 共享桌面出错回调

 @param error 错误信息
 */
- (void)onShareDesktopFailed:(CubeError *)error;

//******************************************扩展监听，多终端在线时使用***************************************************/

/**
 同账号在其他设备创建桌面

 @param sd 共享消息实体
 @param fromUser 创建者user实体
 */
- (void)onShareDesktopCreatedOther:(CubeShareDesktop *)sd fromUser:(CubeUser *)fromUser;

/**
 同账号在其他设备销毁桌面

 @param sd  共享消息实体
 @param fromUser  邀请者user实体
 */
- (void)onShareDesktopDestroyedOther:(CubeShareDesktop *)sd fromUser:(CubeUser *)fromUser;

/**
  同账号在其他设备接受申请

 @param sd 共享消息实体
 @param fromUser  同意申请者user实体
 @param appliedMember 申请者user实体
 */
- (void)onShareDesktopAcceptAppliedOther:(CubeShareDesktop *)sd fromUser:(CubeUser *)fromUser andApplied:(CubeUser *)appliedMember;

/**
 同账号在其他设备拒绝申请

 @param sd 共享消息实体
 @param fromUser 拒绝申请者user实体
 @param appliedMember 申请者user实体
 */
- (void)onShareDesktopRejectAppliedOther:(CubeShareDesktop *)sd fromUser:(CubeUser *)fromUser andApplied:(CubeUser *)appliedMember;

/**
 同账号在其他设备申请加入

 @param sd  共享消息实体
 @param fromUser 邀请者user实体
 @param joinedUser 加入者实体
 */
- (void)onShareDesktopApplyJoinedOther:(CubeShareDesktop *)sd fromUser:(CubeUser *)fromUser andJoined:(CubeUser *)joinedUser;

/**
 同账号在其他设备退出

 @param sd 共享消息实体
 @param fromUser 离开者user实体
 */
- (void)onShareDesktopQuitedOther:(CubeShareDesktop *)sd fromUser:(CubeUser *)fromUser;

/**
 同账号在其他设备发起邀请

 @param sd 共享消息实体
 @param fromUser 离开者user实体
 */
- (void)onShareDesktopInvitedOther:(CubeShareDesktop *)sd fromUser:(CubeUser *)fromUser;

/**
 同账号在其他设备加入

 @param sd  共享桌面对象实例
 @param fromUser 邀请者user实体
 @param joinedUser 加入者user实体
 */
- (void)onShareDesktopInviteJoinedOther:(CubeShareDesktop *)sd fromUser:(CubeUser *)fromUser andJoined:(CubeUser *)joinedUser;

/**
 同账号在其他设备拒绝邀请

 @param sd 共享桌面对象实例
 @param fromUser 邀请者user实体
 @param rejectedUser  拒绝者user实体
 */
- (void)onShareDesktopRejectInvitedOther:(CubeShareDesktop *)sd fromUser:(CubeUser *)fromUser andRejected:(CubeUser *)rejectedUser;
@end


@protocol CubeShareDesktopService <CubeService>

@property (nonatomic,weak) id<CubeShareDesktopServiceDelegate> delegate;

/**
 创建共享桌面

 @param type 类型
 @param displayName 共享桌面名称，可以是群的displayName，也可是自己的
 @param bindId 绑定群组，可以为空
 */
//- (BOOL)createShareDesktop:(NSString *)type andDisplayName:(NSString *)displayName andBindId:(NSString *)bindId;

//3.0不用该方法
///**
// 加入共享桌面
//
// @param desktopId 共享桌面Id
// */
//- (void)applyJoinShareDesktop:(NSString *)desktopId;

/**
 加入到远程桌面

 @param desktopId 共享桌面Id
 */
- (BOOL)JoinShareDesktop:(NSString *)desktopId;

/**
 拒绝申请

 @param desktopId  共享桌面Id
 @param cubeId 邀请者ID
 */
- (BOOL)rejectApplyShareDesktop:(NSString *)desktopId andCube:(NSString *)cubeId;

/**
 邀请加入桌面

 @param desktopId 共享桌面Id
 @param cubeIds  需要邀请的成员的 Cube 号数组
 */
- (BOOL)inviteShareDesktop:(NSString *)desktopId andCubes:(NSArray <NSString *> *)cubeIds;

/**
 接受邀请

 @param desktopId 共享桌面Id
 @param cubeId 邀请者ID
 */
- (BOOL)acceptInviteShareDesktop:(NSString *)desktopId andCube:(NSString *)cubeId;

/**
 拒绝邀请

 @param desktopId 共享桌面Id
 @param cubeId 邀请者ID
 */
- (BOOL)rejectInviteShareDesktop:(NSString *)desktopId andCube:(NSString *)cubeId;

/**
 退出共享桌面

 @param desktopId 共享桌面ID
 */
- (BOOL)quitShareDesktop:(NSString *)desktopId;

/**
 停止共享

 @param desktopId 共享桌面ID
 */
- (BOOL)destroyShareDesktop:(NSString *)desktopId;

/**
 查询共享桌面

 @param desktopIds 共享桌面IDs
 @param block 回调
 */
- (void)queryShareDesktop:(NSArray <NSString *> *)desktopIds andBlock:(void (^)(NSArray <CubeShareDesktop *> *desktops))block andFail:(void(^)(CubeError *error))failBlock;

/**
 同步自己所在所有共享桌面

 @param block 回调
 */
- (void)syncShareDesktop:(void (^)(NSArray <CubeShareDesktop *> *desktops))block andFail:(void(^)(CubeError *error))failBlock;

/**
 获取远端桌面画面

 @return 远程桌面View
 */
- (CubeRemoteView *)getShareDesktopView;

/**
 * 是否是当前设备发起的指令
 * 例：多终端同时在线时，收到创建共享桌面或者加入共享桌面回调时可以使用

 @param shareDesktop 远程桌面
 @return yes no
 */
- (BOOL)isSelf:(CubeShareDesktop *)shareDesktop;
@end
#endif /* CubeShareDesktopService_h */
