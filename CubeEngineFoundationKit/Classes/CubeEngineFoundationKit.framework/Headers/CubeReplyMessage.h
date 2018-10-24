//
//  CubeReplyMessage.h
//  CubeEngineFoundationKit
//
//  Created by jianchengpan on 2018/5/18.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <CubeEngineFoundationKit/CubeMessageEntity.h>

@interface CubeReplyMessage : CubeMessageEntity

@property (nonatomic, strong) CubeMessageEntity *source;

@property (nonatomic, strong) CubeMessageEntity *reply;


/**
 回复消息初始化

 @param source 待回复的消息
 @param reply 回复的消息
 @param sender 消息发送者
 @param receiver 消息接收者
 @return 回复消息
 */
-(instancetype)initWithSource:(CubeMessageEntity *)source reply:(CubeMessageEntity *)reply andSender:(CubeUser *)sender receiver:(CubeUser *)receiver;

@end
