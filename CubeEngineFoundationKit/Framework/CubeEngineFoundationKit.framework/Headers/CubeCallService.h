//
//  CubeCallService.h
//  CubeEngineFoundationKit
//
//  Created by Ashine on 2018/5/14.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CubeEngineFoundationKit/CubeService.h>


@class CubeCallSession;
@class CubeUser;


@protocol CubeCallServiceDelegate <NSObject>

/**
 * 收到呼叫（第一个呼叫）
 *
 * @param session 呼叫会话
 * @param from 发起者
 */
-(void)onCall:(CubeCallSession *)session from:(CubeUser *)from;

/**
 * 新的呼叫（在通话中收到新的呼叫）
 *
 * @param session 新的呼叫会话
 * @param from 发起者
 */
- (void)onNewCall:(CubeCallSession *)session from:(CubeUser *)from;

/**
 * 发起呼叫同账号的其他设备
 *
 * @param session 呼叫会话
 * @param from 发起者
 */
- (void)onCallOther:(CubeCallSession *)session from:(CubeUser *)from;

/**
 * 呼叫或者接听过程中
 *
 * @param session 新的呼叫会话
 * @param from 发起者
 */
- (void)onCallProgress:(CubeCallSession *)session from:(CubeUser *)from;

/**
 * 对方响铃（目前私有信令未实现）
 *
 * @param session 新的呼叫会话
 * @param from 发起者
 */

- (void)onCallRinging:(CubeCallSession *)session from:(CubeUser *)from;

/**
 * 呼叫建立
 *
 * @param session 新的呼叫会话
 * @param from 发起者
 */
- (void)onCallConnected:(CubeCallSession *)session from:(CubeUser *)from;

/**
 * 呼叫挂断
 *
 * @param session 挂断的呼叫会话
 * @param from 发起者
 */
- (void)onCallEnded:(CubeCallSession *)session from:(CubeUser *)from;


/**
 * 呼叫在其他设备挂断
 *
 * @param session 挂断的呼叫会话
 * @param from 发起者
 */
- (void)onCallEndedOther:(CubeCallSession *)session from:(CubeUser *)from;

/**
 * 呼叫失败
 *
 * @param session 失败的呼叫会话
 * @param error  失败原因
 *  @param from 发起者
 */
- (void)onCallFailed:(CubeCallSession *)session error:(CubeError *)error from:(CubeUser *)from;
//from:(CubeUser *)from;
@end

@protocol CubeCallService<CubeService>

@property (nonatomic, weak) id<CubeCallServiceDelegate> delegate;

/**
 * 呼叫
 *
 * @param callee 被呼叫者
 * @param enableVideo 是否打开video
 *
 * @return  是否呼叫成功
 */
- (BOOL)makeCallWithCallee:(CubeUser *)callee andEnableVideo:(BOOL )enableVideo;


/**
 * 接听
 *
 * @param callee 对端cubeID
 *
 * @return 是否接听成功
 */
- (BOOL)answerCallWith:(NSString *)callee;


/**
 * 挂断
 *
 * @param callee 对端cube号
 *
 * @return 是否挂断成功
 */
- (BOOL)terminateCall:(NSString *)callee;


@end
