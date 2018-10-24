//
//  CubeFileMessage.h
//  CubeEngineMessageKit
//
//  Created by jianchengpan on 2018/5/15.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <CubeEngineFoundationKit/CubeMessageEntity.h>

@interface CubeFileMessage : CubeMessageEntity

/** 文件名*/
@property (nonatomic, strong) NSString *fileName;

/** 文件(上传或下载)进度*/
@property (nonatomic, assign) long long progress;

/** 文件大小*/
@property (nonatomic, assign) long long fileSize;

/** 文件url*/
@property (nonatomic, strong) NSString *url;

/** 本地路径*/
@property (nonatomic, strong) NSString *filePath;

/** 文件MD5*/
@property (nonatomic, strong) NSString *md5;

/**
 文件服务器key
 */
@property (nonatomic, strong) NSString *key;


/**
 modified
 */
@property (nonatomic, strong) NSString *modified;


/**
 文件消息初始化方法

 @param fileName 文件名
 @param fileSize 文件大小(byte)
 @param url 文件url
 @param md5 文件md5值
 @param sender 发送人
 @param receiver 接收人
 @return 文件消息实体
 */
-(instancetype)initWithFileName:(NSString *)fileName fileSize:(long long )fileSize url:(NSString *)url md5:(NSString *)md5 andSender:(CubeUser *)sender receiver:(CubeUser *)receiver;

@end
