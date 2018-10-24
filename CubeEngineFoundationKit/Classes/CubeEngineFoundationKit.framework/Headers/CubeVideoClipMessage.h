//
//  CubeVideoClipMessage.h
//  CubeEngineFoundationKit
//
//  Created by jianchengpan on 2018/5/16.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <CubeEngineFoundationKit/CubeEngineFoundationKit.h>

@interface CubeVideoClipMessage : CubeFileMessage

/**
 剪辑时长，单位秒
 */
@property (nonatomic, assign) long long duration;

/**
 缩略图路径
 */
@property (nonatomic, strong) NSString *thumbPath;

/**
 缩略图url
 */
@property (nonatomic, strong) NSString *thumbUrl;

/**
 缩略图高
 */
@property (nonatomic, assign) int thumbImageHeight;

/**
 缩略图宽
 */
@property (nonatomic, assign) int thumbImageWidth;

/**
 视频消息初始化

 @param fileName 文件名
 @param fileSize 文件大小(byte)
 @param duration 视频时长
 @param thumbImageSize 封面图片大小
 @param url 视频url
 @param thumbUrl 封面url
 @param md5 视频文件md5
 @param sender 发送人
 @param receiver 接受人
 @return 视频消息
 */
-(instancetype)initWithFileName:(NSString *)fileName fileSize:(long long)fileSize duration:(long long )duration thumbImageSize:(CGSize)thumbImageSize url:(NSString *)url thumbUrl:(NSString *)thumbUrl md5:(NSString *)md5 andSender:(CubeUser *)sender receiver:(CubeUser *)receiver;

@end
