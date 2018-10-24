//
//  CubeHistoryMessage.h
//  CubeEngineFoundationKit
//
//  Created by Ashine on 2018/5/22.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <CubeEngineFoundationKit/CubeMessageEntity.h>

@interface CubeHistoryMessage : CubeMessageEntity

/**
 多条消息
 */
@property (nonatomic, strong) NSArray<CubeMessageEntity *> *histories;

/**
 历史消息初始化

 @param histories 历史消息列表
 @param sender 发送者
 @param receiver 接收者
 @return 历史消息
 */
-(instancetype)initWithHistories:(NSArray<CubeMessageEntity *> *)histories andSender:(CubeUser *)sender receiver:(CubeUser *)receiver;

@end
