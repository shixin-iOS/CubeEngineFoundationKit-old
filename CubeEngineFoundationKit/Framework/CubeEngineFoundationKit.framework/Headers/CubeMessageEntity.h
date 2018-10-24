//
//  CubeMessageEntity.h
//  CubeEngineMessageKit
//
//  Created by jianchengpan on 2018/5/14.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CubeEngineFoundationKit/CubeUser.h>
#import <CubeEngineFoundationKit/CubeDeviceInfo.h>

#import <CubeEngineFoundationKit/CubeMessageType.h>
#import <CubeEngineFoundationKit/CubeMessageStatus.h>
#import <CubeEngineFoundationKit/CubeMessageDirection.h>
#import <CubeEngineFoundationKit/CubeMessageAttachmentType.h>

#import <CubeEngineFoundationKit/CubeMessageUtil.h>
#import <CubeEngineFoundationKit/CubeJsonUtil.h>

@interface CubeMessageEntity : NSObject<CubeJSONObject>

/** 消息序列号 */
@property (nonatomic, assign) long long SN;

/** 消息类型 */
@property (nonatomic, assign) CubeMessageType type;

/** 消息状态 */
@property (nonatomic, assign) CubeMessageStatus status;

/** 发件人 */
@property (nonatomic, strong) CubeUser *sender;

/** 发送时间 */
@property (nonatomic, assign) long long sendTime;

/** 接收人 */
@property (nonatomic, strong) CubeUser *receiver;

/** 接收时间 */
@property (nonatomic, assign) long long receiveTime;

/** 是否被其他终端拉取 */
@property (nonatomic, assign) BOOL pulled;

/** 群组号 */
@property (nonatomic, strong) NSString *groupName;

/** 撤回时间 */
@property (nonatomic, assign) long long recallTime;

/** 时间戳 */
@property (nonatomic, assign) long long timestamp;

/**
 默认或者不设置时为 false，当参数为 true 时，消息将仅发送给在线的设备，所有当前离线设备将无法取得该消息 不入库 直接透传
 增加对方正在输入功能（采用自定义消息的透传功能实现，服务器验证traceless属性为true时，不入库，直接透传功能
 */
@property (nonatomic, assign) BOOL traceless;

/**
 消息方向
 */
@property (nonatomic, assign) CubeMessageDirection messageDirection;
/**
 附件类型
 */
@property (nonatomic, assign) CubeMessageAttachmentType attachmentType;

/**消息头*/
@property (nonatomic, strong) NSMutableDictionary *header;

/**
 消息从哪种设备发出
 */
@property (nonatomic, strong) CubeDeviceInfo *deviceInfo;


/**
 消息在此之前被什么设备收取过
 */
@property (nonatomic, strong) NSArray<CubeDeviceInfo *> *pulledDevices;


/**
 是否加密
 */
@property (nonatomic, assign) BOOL secret;


/**
 回执时间
 */
@property (nonatomic, assign) long long receiptTimestamp;


/**
 是否已读
 */
@property (nonatomic, assign) BOOL receipted;

/**
 消息回执设备
 */
@property (nonatomic, strong) NSMutableArray<CubeDeviceInfo *> *receiptedDevices;


/**
 是否是密聊消息
 */
@property (nonatomic, assign) BOOL anonymous;


/**
 是否为有效消息
 */
@property (nonatomic, assign,readonly) BOOL valid;

/**
 同步，
 0. 都同步，1. 仅对方同步 2. 仅自己同步
 */
@property (nonatomic, assign) int sync;

/**
 消息被修改的时间
 */
@property (nonatomic, assign) long long update;

/**
 需要路由者，群消息可以设置此属性，表示只有此列表的人才能收到，不设置没有此属性
 */
@property (nonatomic, strong) NSArray *tos;

-(instancetype)initWithType:(CubeMessageType)type andSender:(CubeUser *)sender andReceiver:(CubeUser *)receiver;

@end
