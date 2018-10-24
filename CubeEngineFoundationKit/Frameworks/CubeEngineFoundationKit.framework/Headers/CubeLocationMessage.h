//
//  CubeLocationMessage.h
//  CubeEngineFoundationKit
//
//  Created by Ashine on 2018/5/22.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <CubeEngineFoundationKit/CubeEngineFoundationKit.h>

@interface CubeLocationMessage : CubeMessageEntity
/**
 纬度
 */
@property (nonatomic, assign) double lat;

/**
 经度
 */
@property (nonatomic, assign) double lng;

/**
 地址信息
 */
@property (nonatomic, copy) NSString *address;

/**
 初始化位置信息

 @param lat 纬度
 @param lng 经度
 @param address 地址信息
 @param sender 发送者
 @param receiver 接收者
 @return 位置消息
 */
-(instancetype)initWithLat:(double)lat lng:(double)lng address:(NSString *)address andSender:(CubeUser *)sender receiver:(CubeUser *)receiver;

@end
