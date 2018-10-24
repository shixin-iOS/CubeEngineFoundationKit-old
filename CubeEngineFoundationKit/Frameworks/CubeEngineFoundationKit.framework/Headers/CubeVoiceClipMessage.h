//
//  CubeVoiceClipMessage.h
//  CubeEngineMessageKit
//
//  Created by jianchengpan on 2018/5/16.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <CubeEngineFoundationKit/CubeFileMessage.h>

@interface CubeVoiceClipMessage : CubeFileMessage

/**
 时长，单位秒
 */
@property (nonatomic, assign) long long duration;

/**
 语音消息初始化方法

 @param fileName 文件名
 @param fileSize 文件大小(byte)
 @param duration 语音时长(s)
 @param url 文件url
 @param md5 文件md5
 @param sender 发送人
 @param receiver 接受人
 @return 语音消息
 */
-(instancetype)initWithFileName:(NSString *)fileName fileSize:(long long)fileSize duration:(long long)duration url:(NSString *)url md5:(NSString *)md5 andSender:(CubeUser *)sender receiver:(CubeUser *)receiver;

@end
