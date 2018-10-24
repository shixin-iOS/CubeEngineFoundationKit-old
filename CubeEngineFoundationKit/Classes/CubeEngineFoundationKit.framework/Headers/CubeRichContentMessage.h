//
//  CubeRichContentMessage.h
//  CubeEngineFoundationKit
//
//  Created by Ashine on 2018/5/22.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <CubeEngineFoundationKit/CubeEngineFoundationKit.h>

@interface CubeRichContentMessage : CubeMessageEntity
/**
 多条消息
 */
@property (nonatomic, strong) NSArray <CubeMessageEntity *> *richcontents;

/**
 富文本消息初始化

 @param richContents 富文本消息列表
 @param sender 发送者
 @param receiver 接收者
 @return 富文本消息
 */
-(instancetype)initWithRichContents:(NSArray<CubeMessageEntity *> *)richContents andSender:(CubeUser *)sender receiver:(CubeUser *)receiver;

@end
