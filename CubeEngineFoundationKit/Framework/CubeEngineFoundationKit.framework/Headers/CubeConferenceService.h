//
//  CubeConferenceService.h
//  CubeEngineFoundationKit
//
//  Created by Ashine on 2018/5/17.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <CubeEngineFoundationKit/CubeService.h>

@class CubeConference;
@class CubeConferenceConfig;
@class CubeConferenceMember;

@class CubeError;

@protocol CubeConferenceServiceDelegate <NSObject>

#pragma mark - 会议监听回调
/**
 会议已创建

 @param conference 会议
 @param user 创建人
 */
-(void)onConferenceCreated:(CubeConference *)conference byUser:(CubeUser *)user;

/**
 会议已销毁

 @param conference 会议
 @param user 销毁人
 */
-(void)onConferenceDestroyed:(CubeConference *)conference byUser:(CubeUser *)user;

/**
 收到邀请回调(仅邀请者自己和被邀请者收到)

 @param conference 会议
 @param user 邀请人
 */
-(void)onConferenceInvited:(CubeConference *)conference fromUser:(CubeUser *)user andInvites:(NSArray <CubeUser *>*)invites;

/**
 拒绝要邀请回调（仅拒绝者和邀请者收到）

 @param conference 会议
 @param inviteUser 邀请人
 @param rejectUser 拒绝人
 */
-(void)onConferenceRejectInvited:(CubeConference *)conference fromUser:(CubeUser *)inviteUser byUser:(CubeUser *)rejectUser;

/**
 同意邀请时回调

 @param conference 会议
 @param inviteUser 邀请人
 @param joinedMember 同意加入者
 */
-(void)onConferenceAcceptInvited:(CubeConference *)conference fromUser:(CubeUser *)inviteUser byUser:(CubeUser *)joinedMember;

/**
 用户加入会议

 @param conference 会议
 @param joinedUser 加入用户
 */
-(void)onConferenceJoined:(CubeConference *)conference fromUser:(CubeUser *)joinedUser;

/**
 视频 开启/关闭 回掉

 @param enable 开启/关闭 视频
 @param conference 会议
 */
-(void)onVideoEnabled:(BOOL)enable inConference:(CubeConference *)conference;

/**
 音频 开启/关闭 回掉
 
 @param enable 开启/关闭 音频
 @param conference 会议
 */
-(void)onAudioEnabled:(BOOL)enable inConference:(CubeConference *)conference;

/**
 会议信息更新

 @param conference 会议
 */
-(void)onConferenceUpdated:(CubeConference *)conference;

/**
 退出会议

 @param conference 会议
 @param quitMember 退出人
 */
-(void)onConferenceQuited:(CubeConference *)conference fromUser:(CubeUser *)quitMember;


/**
 会议错误回掉

 @param conference 会议
 @param error 错误信息
 */
- (void)onConferenceFailed:(CubeConference *)conference withError:(CubeError *)error;


/**
 正在链接会议

 @param conference 会议
 */
- (void)onConnecteingConference:(CubeConference *)conference;


/**
 链接会议成功

 @param conference 会议
 */
- (void)onConnectedToConference:(CubeConference *)conference;


#pragma mark - 会议监听扩展(多端登陆处理)

/**
 同账号在其他设备创建会议成功时回调

 @param conference 会议对象
 @param from 会议创建者
 */
- (void)onConferenceCreatedOther:(CubeConference *)conference from:(CubeUser *)from;


/**
 同账号在其他设备销毁会议时回调

 @param conference 会议对象
 @param from 会议创建者
 */
- (void)onConferenceDestroyedOther:(CubeConference *)conference from:(CubeUser *)from;


/**
 同账号在其他设备发起邀请

 @param conference 会议对象
 @param from 邀请者
 @param invites 被邀请列表
 */
- (void)onConferenceInvitedOther:(CubeConference *)conference from:(CubeUser *)from invites:(NSArray *)invites;



/**
 同账号在其他设备拒绝邀请

 @param conference 会议对象
 @param from 邀请者
 @param rejectMember 被邀请列表
 */
- (void)onConferenceRejectInvitedOther:(CubeConference *)conference from:(CubeUser *)from rejectMember:(CubeUser *)rejectMember;


/**
 同账号在其他设备同意邀请

 @param conference 会议对象
 @param from 邀请者
 @param joinedMember 同意加入者
 */
- (void)onConferenceAcceptInvitedOther:(CubeConference *)conference from:(CubeUser *)from joinedMember:(CubeUser *)joinedMember;


/**
 同账号在其他设备加入会议

 @param conference 会议对象
 @param joinedMember 入会者
 */
- (void)onConferenceJoinedOther:(CubeConference *)conference joinedMember:(CubeUser *)joinedMember;


/**
 同账号在其他设备退出会议

 @param conference 会议对象
 @param quitMember 退出者
 */
- (void)onConferenceQuitedOther:(CubeConference *)conference quitMember:(CubeUser *)quitMember;

@end




@protocol CubeConferenceService<CubeService>

@property (nonatomic, weak) id<CubeConferenceServiceDelegate> delegate;

#pragma mark - manage conference

/**
 创建会议

 @param config 会议配置
 @return 指令是否成功
 */
-(BOOL)createConferenceWithConfig:(CubeConferenceConfig *)config;

/**
 销毁会议

 @param conferenceId 会议ID
 @return 指令是否成功
 */
-(BOOL)destroyConference:(NSString *)conferenceId;

/**
 加入会议

 @param conferenceId 会议ID
 @return 指令是否成功
 */
-(BOOL)joinConference:(NSString *)conferenceId;

/**
 退出会议

 @param conferenceId 会议ID
 @return 指令是否成功
 */
-(BOOL)quitConference:(NSString *)conferenceId;



/**
 邀请成员加入会议

 @param members 成员列表
 @param conferenceId 会议ID
 @return 指令是否成功
 */
-(BOOL)inviteMembers:(NSArray<NSString *> *)members intoConference:(NSString *)conferenceId;

/**
 接受会议邀请

 @param cubeId 邀请者ID
 @param conferenceId 会议ID
 @return 指令是否成功
 */
-(BOOL)acceptInviteFrom:(NSString *)cubeId withConferenceId:(NSString *)conferenceId;

/**
 拒绝会议邀请

 @param cubeId 邀请者cubeid
 @param conferenceId 会议ID
 @return 指令是否成功
 */
-(BOOL)rejectInviteFrom:(NSString *)cubeId withConferenceId:(NSString *)conferenceId;



#pragma mark - conference sync
/**
 同步会议

 @param conferenceTypes 筛选会议类型
 @param completion 成功回调
 @param failure 失败回调
 */
-(void)queryConferenceWithConferenceType:(NSArray *)conferenceTypes
                                groupIds:(NSArray *)groupIds
                              completion:(void(^)(NSArray *conferences))completion
                                 failure:(void(^)(CubeError *error))failure;


/**
 @note 如cubeId不传入 则默认使用当前登录账号的cubeId
 根据cubeId同步会议列表

 @param cubeId cubeId
 @param completion 成功回调
 @param failure 失败回调
 */
-(void)queryConferenceWithCubeId:(NSString *)cubeId
                  ConferenceType:(NSArray *)conferenceTypes
                      completion:(void(^)(NSArray *conferences))completion
                         failure:(void(^)(CubeError *error))failure;


#pragma mark - conference get by id
/**
 根据会议id查询会议

 @param conferenceId 会议id
 @param success 成功回调
 @param failure 失败回调
 */
-(void)queryConferenceByConferenceId:(NSString *)conferenceId
                             success:(void(^)(CubeConference *conference))success
                             failure:(void(^)(CubeError *error))failure;



#pragma mark - extend api

/**
 根据传入会议判断是否是当前设备发起的指令

 @param conference conference对象
 @return 是否是当前设备发起
 */
- (BOOL)isSelf:(CubeConference *)conference;

#pragma mark - control conference

/**
 打开或关闭音频

 @param enable 开启或关闭
 @param conferenceId 会议ID
 @return 设置是否成功
 */
- (BOOL)setAudioEnable:(BOOL)enable WithConferenceId:(NSString *)conferenceId;

/**
 打开或关闭视频

 @param enable 开启或关闭
 @param conferenceId 会议ID
 @return 设置是否成功
 */
- (BOOL)setVideoEnable:(BOOL)enable WithConferenceId:(NSString *)conferenceId;

/**
 添加主讲人

 @param cubeId 主讲人ID
 @param conferenceId 会议ID
 @return 指令是否成功
 */
-(BOOL)addPresenter:(NSString *)cubeId inConference:(NSString *)conferenceId;

/**
 删除主讲人
 
 @param cubeId 主讲人ID
 @param conferenceId 会议ID
 @return 指令是否成功
 */
-(BOOL)removePresenter:(NSString *)cubeId inConference:(NSString *)conferenceId;

/**
 切换主讲人
 
 @param cubeId 主讲人ID
 @param conferenceId 会议ID
 @return 指令是否成功
 */
-(BOOL)changeSpeaker:(NSString *)cubeId inConference:(NSString *)conferenceId;

/**
 禁听用户

 @param deaf 是否禁听
 @param cubeId 用户ID
 @param conferenceId 会议ID
 @return 指令是否成功
 */
-(BOOL)setMemberDeaf:(BOOL)deaf withCubeId:(NSString *)cubeId inConference:(NSString *)conferenceId;

/**
 禁言用户

 @param mute 是否禁言
 @param cubeId 用户ID
 @param conferenceId 会议ID
 @return 指令是否成功
 */
-(BOOL)setMemberMute:(BOOL)mute withCubeId:(NSString *)cubeId inConference:(NSString *)conferenceId;

/**
 禁视用户
 
 @param watch 是否禁视
 @param cubeId 用户ID
 @param conferenceId 会议ID
 @return 指令是否成功
 */
-(BOOL)setMemberWatch:(BOOL)watch withCubeId:(NSString *)cubeId inConference:(NSString *)conferenceId;

/**
踢出用户
 
 @param cubeId 用户ID
 @param conferenceId 会议ID
 @return 指令是否成功
 */
-(BOOL)kickMember:(NSString *)cubeId inConference:(NSString *)conferenceId;

///**
// * 是否为会议
// *
// * @param strJson JSON
// *
// * @return  是否为会议
// */
//- (BOOL)isConference:(NSString *)strJson;
//
//
///**
// * 解析会议
// *
// * @param strJson JSON
// *
// * @return 会议对象
// */
//-(CubeConference *)parse:(NSString *)strJson;


/**
 * 获取会议成员静态帧
 *
 * @param conferenceId 会议id
 * @param cubeId cubeid
 * @param quality quality
 */
- (NSString *)getCapturedCameraImagesWithConferenceId:(NSString *)conferenceId andCubeId:(NSString *)cubeId andQuality:(BOOL )quality;


/**
 * 是否是当前设备发起的指令
 * 例：多终端同时在线时，收到创建会议或者加入会议回调时可以使用

 @param conference 会议
 @return YES NO
 */
//- (BOOL)isSelf:(CubeConference *)conference;
///**
// * 获取本地视频通话画面。(使用mediaService实现)
// *
// * @return 本地视频画面
// */
//- (UIView *)getLocalView;
//
//
///**
// * 获取远端视频通话画面。(使用mediaService实现)
// *
// * @return 远程视频画面
// */
//- (UIView *)getRemoteView;

@end
