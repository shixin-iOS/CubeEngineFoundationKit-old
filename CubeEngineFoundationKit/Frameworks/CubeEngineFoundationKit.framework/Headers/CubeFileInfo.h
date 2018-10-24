//
//  CubeFileInfo.h
//  CubeEngineFoundationKit
//
//  Created by Ashine on 2018/5/17.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CubeEngineFoundationKit/CubeFileType.h>

@interface CubeFileInfo : NSObject

/**
 文件Id
 */
@property (nonatomic,strong) NSString *fileId;

/**
 文件名称
 */
@property (nonatomic,strong) NSString *name;

/**
 进度
 */
@property (nonatomic,assign) long progress;

/**
 文件大小
 */
@property (nonatomic,assign) long size;

/**
 文件类型
 */
@property (nonatomic,assign) CubeFileType type;

/**
 文件MD5
 */
@property (nonatomic,strong) NSString *md5;

/**
 文件创建时间
 */
@property (nonatomic,assign) long createTime;

/**
 文件父目录id
 */
@property (nonatomic,strong) NSString *parentId;

/**
 文件可操作权限
 */
@property (nonatomic,assign) int permission;

/**
 文件地址
 */
@property (nonatomic,strong) NSString *url;

/**
 文件有效期
 */
@property (nonatomic,assign) long expires;

/**
 文件本地路径
 */
@property (nonatomic,strong) NSString *filePath;

/**
 文件服务中文件的唯一标识
 @note 不同上传任务提供不同的标识 例如会话A中有一个上传文件任务 上传了文件a,会话B中然后创建了一个上传任务a,这是两个不同的identify(虽然是上传同一个文件)
 内部是根据此identify来辨识 该文件上传或下载任务是否正在进行中
 */
@property (nonatomic,strong) NSString  *identify;


@property (nonatomic,strong) NSURLSessionTask *task;



@end
