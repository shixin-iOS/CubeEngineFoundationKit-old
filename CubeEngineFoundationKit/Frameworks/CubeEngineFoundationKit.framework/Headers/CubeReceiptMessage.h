//
//  CubeReceiptMessage.h
//  CubeEngineFoundationKit
//
//  Created by jianchengpan on 2018/6/25.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <CubeEngineFoundationKit/CubeEngineFoundationKit.h>

@interface CubeReceiptMessage : CubeMessageEntity

/**
 回执消息初始化

 @param sender 发送中
 @param receiver 接收者
 @return 回执消息
 */
-(instancetype)initWithSender:(CubeUser *)sender andReceiver:(CubeUser *)receiver;

@end
