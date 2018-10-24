//
//  CubeCardMessage.h
//  CubeEngineFoundationKit
//
//  Created by jianchengpan on 2018/5/17.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <CubeEngineFoundationKit/CubeMessageEntity.h>
#import <CubeEngineFoundationKit/CubeCardContent.h>

@interface CubeCardMessage : CubeMessageEntity

/**卡片消息标题*/
@property (nonatomic, copy) NSString *title;

/**卡片消息头像*/
@property (nonatomic, copy) NSString *icon;

/**卡片内容*/
@property (nonatomic, copy) NSString *content;

/**卡片对象*/
@property (nonatomic, strong) NSArray<CubeCardContent *> *cardContents;


/**
 卡片消息初始化

 @param title 卡片消息标题
 @param icon 卡片消息头像
 @param content 卡片消息内容
 @param cardContents 卡片内容列表
 @param sender 发送人
 @param receiver 接收人
 @return 卡片消息
 */
-(instancetype)initWithTitle:(NSString *)title icon:(NSString *)icon content:(NSString *)content cardContents:(NSArray<CubeCardContent *> *)cardContents andSender:(CubeUser *)sender receiver:(CubeUser *)receiver;

@end
