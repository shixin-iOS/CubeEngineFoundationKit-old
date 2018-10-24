//
//  CubeTextMessage.h
//  CubeEngineMessageKit
//
//  Created by jianchengpan on 2018/5/15.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <CubeEngineFoundationKit/CubeMessageEntity.h>

@interface CubeTextMessage : CubeMessageEntity

/**
 消息内容
 */
@property (nonatomic, copy) NSString *content;

-(instancetype)initWithConent:(NSString *)content andSender:(CubeUser *)sender andReceiver:(CubeUser *)receiver;

@end
