//
//  DownloadCubeFile.h
//  CubeEngineFoundationKit
//
//  Created by Ashine on 2018/5/17.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <CubeEngineFoundationKit/CubeFileInfo.h>

@interface DownloadCubeFile : CubeFileInfo


/**
 下载文件cubeFile构造方法
 
 @param identify 唯一标识
 @param url 文件下载路径
 @param localFolder  存储的本地路径
 @return download cubeFile实例
 */
+(instancetype)downloadFileWithIdentify:(NSString *)identify andDownloadUrl:(NSString *)url andLocalFolder:(NSString *)localFolder;

@end
