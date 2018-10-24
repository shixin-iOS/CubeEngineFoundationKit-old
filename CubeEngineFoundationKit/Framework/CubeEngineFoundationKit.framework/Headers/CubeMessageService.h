//
//  CubeMessageService.h
//  CubeEngineFoundationKit
//
//  Created by jianchengpan on 2018/5/14.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <CubeEngineFoundationKit/CubeService.h>

@class CubeMessageEntity;
@class CubeError;

#pragma mark - sync message

@protocol CubeMessageSyncDelegate<NSObject>

@optional

/**
 开始同步消息
 */
-(void)onMessageSyncBegin;

/**
 同步消息
 
 消息字典如下格式
 {
 sessionID1:[message1,message2,message3,...],
 sessionID2:[message1,message2,message3,...],
 sessionID3:[message1,message2,message3,...],
 }
 @param msgDic 消息字典
 */
-(void)onMessagesSyncing:(NSDictionary *)msgDic;

/**
 消息同步结束
 */
-(void)onMessageSyncEnd;

@end


@protocol CubeMessageSynchronizer <NSObject>

@property (nonatomic, weak) id<CubeMessageSyncDelegate> delegate;

/**
 同步当前登录用户的消息
 */
-(void)syncMessages;

/**
 停止当前同步任务
 */
-(void)stopSyncMessages;

@end

#pragma mark - send and recieve message

@protocol CubeMessageServiceDelegate<CubeMessageSyncDelegate>

@optional

#pragma mark - message
/**
 消息发送成功

 @param message 发送成功的消息
 */
-(void)onMessageSent:(CubeMessageEntity *)message;

/**
 收到消息

 @param message 收到的消息
 */
-(void)onMessageReceived:(CubeMessageEntity *)message;

/**
 消息撤回成功

 @param message 撤回的消息
 */
-(void)onMessageRecalled:(CubeMessageEntity *)message;

/**
 消息已取消

 @param message 取消的消息
 */
-(void)onMessageCanceled:(CubeMessageEntity *)message;

/**
 错误回掉

 @param message 出错的消息
 @param error 错误描述
 */
-(void)onMessageFailed:(CubeMessageEntity *)message withError:(CubeError *)error;

@end

@protocol CubeMessageService <CubeService>

/**
 消息同步器
 */
@property (nonatomic, readonly) id<CubeMessageSynchronizer> messageSynchronizer;

@property (nonatomic, weak) id<CubeMessageServiceDelegate> delegate;

/**
 发送消息

 @param message 消息
 @return 引擎是否处理成功
 */
-(BOOL)sendMessage:(CubeMessageEntity *)message;

/**
 重发消息

 @param message 消息
 @return 引擎是否处理成功
 */
-(BOOL)reSendMessage:(CubeMessageEntity *)message;

/**
 发送历史消息

 @param sns 消息sn列表
 @param cubeIds 接收着CubeID列表
 @return 引擎是否处理成功
 */
-(BOOL)sendHistoryMessage:(NSArray<NSString *> *)sns toUsers:(NSArray<NSString *> *)cubeIds;

/**
 撤回消息

 @param SN 消息SN
 @return 引擎是否处理成功
 */
-(BOOL)recallMessage:(long long)SN;

/**
 取消发送消息

 @param SN 消息SN
 @return 引擎是否处理成功
 */
-(BOOL)cancelMessage:(long long)SN;


/**
 删除消息

 @param SN 消息SN
 @return 引擎是否处理成功
 */
-(BOOL)deleteMessage:(long long)SN;

@end
