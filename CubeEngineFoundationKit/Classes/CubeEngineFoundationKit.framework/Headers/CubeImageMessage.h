//
//  CubeImageMessage.h
//  CubeEngineMessageKit
//
//  Created by jianchengpan on 2018/5/15.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <CubeEngineFoundationKit/CubeFileMessage.h>

@interface CubeImageMessage : CubeFileMessage

/** 缩略图url*/
@property (nonatomic, strong) NSString *thumbUrl;

/** 缩略文件路径*/
@property (nonatomic, strong) NSString *thumbPath;

/**
 图片高度
 */
@property (nonatomic, assign) int height;

/**
 图片宽度
 */
@property (nonatomic, assign) int width;

/**
 初始化图片消息

 @param fileName 文件名
 @param fileSize 文件大小(byte)
 @param imageSize 图片大小
 @param url 图片url
 @param thumbUrl 缩略图url
 @param md5 文件md5值
 @param sender 发送人
 @param receiver 接受人
 @return 图片消息
 */
-(instancetype)initWithFileName:(NSString *)fileName fileSize:(long long)fileSize imageSize:(CGSize)imageSize url:(NSString *)url thumbUrl:(NSString *)thumbUrl  md5:(NSString *)md5 andSender:(CubeUser *)sender receiver:(CubeUser *)receiver;

@end
