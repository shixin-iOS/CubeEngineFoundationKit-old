//
//  UploadCubeFile.h
//  CubeEngineFoundationKit
//
//  Created by Ashine on 2018/5/17.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import "CubeFileInfo.h"

@interface UploadCubeFile : CubeFileInfo

/**
 上传文件cubeFile构造方法
 
 @param identify 维一标识
 @param filePath 文件本地路径
 @param fileName 文件名
 @return upload cubeFile实例
 */
+(instancetype)uploadFileWithIdentify:(NSString *)identify andFilePath:(NSString *)filePath andFileName:(NSString *)fileName;

@end
