//
//  CubeCustomMessage.h
//  CubeEngineFoundationKit
//
//  Created by jianchengpan on 2018/5/16.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <CubeEngineFoundationKit/CubeEngineFoundationKit.h>

@interface CubeCustomMessage : CubeMessageEntity

/**消息体*/
@property (nonatomic, copy) NSString *body;

/**
 消息过期时间 单位秒
 */
@property (nonatomic, assign) int expires;

/**
 自定义消息初始化

 @param header 消息头
 @param expires 消息过期时间(s)
 @param sender 发送人
 @param receiver 接收人
 @return 自定义消息
 */
-(instancetype)initWithHeader:(NSDictionary *)header expires:(int)expires andSender:(CubeUser *)sender receiver:(CubeUser *)receiver;

@end
