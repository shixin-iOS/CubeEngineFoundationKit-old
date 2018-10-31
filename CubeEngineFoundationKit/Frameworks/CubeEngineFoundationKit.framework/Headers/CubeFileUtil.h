//
//  CubeFileUtil.h
//  CubeEngineFoundationKit
//
//  Created by jiancheng pan on 2018/10/31.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 engine(CubeEngine) 内部计算文件路径工具
 
 @discussion 文件的根目录由CubeConfig->fileRootPath指定
 @discussion 基本每个方法都有可选参数addtionalPath,指定可选的addtionalPath后，会在根目录下的addtionalPath文件夹中查找文件或者将文件保存到该文件夹下
 */
@interface CubeFileUtil : NSObject

#pragma mark - identifier

/**
 获取文件标识
 
 @discussion 文件标识以数据内容md5加密得出
 
 @param data 计算的文件
 @return 文件标识
 */
-(NSString *)fileIdentifierFor:(NSData *)data;

#pragma mark - get filePath

/**
 获取文件标识指向的路径

 @discussion 文件路径指向的文件不一定存在
 
 @param identifier 文件标识
 @param addtionalPath 文件根目录下的具体路径，不指定则获取文件根目录下的文件路径
 @return 文件路径
 */
-(NSString *)filePathForIdentifier:(NSString *)identifier withAddtionalPath:(nullable NSString *)addtionalPath;

/**
 获取已下载文件的路径

 @discussion 当文件未下载或着下载文件已经被删除时，返回文件路径为空
 
 @param url 已下载文件的url
 @param addtionalPath 文件根目录下的具体路径，不指定则搜索根目录下的url指向的文件
 @return 文件路径
 */
-(nullable NSString *)filePathForUrl:(NSString *)url withAddtionalPath:(nullable NSString *)addtionalPath;

/**
 获取url临时文件的的存放路径

 @param url url
 @param addtionalPath 文件根目录下的具体路径，不指定则将临时文件保存到文件根路径
 @return url的临时文件存放路径
 */
-(NSString *)tempFilePathForUrl:(NSString *)url withAddtionalPath:(nullable NSString *)addtionalPath;

#pragma mark - save file

/**
 保存文件

 @param data 待保存的文件数据
 @return 文件路径
 */
-(NSString *)saveFile:(NSData *)data withAddtionalPath:(nullable NSString *)addtionalPath;

/**
 创建url到文件的连接

 @discussion 文件标识所指向的文件不存在时，创建连接失败
 
 @param identifier 文件标识
 @param url 待处理的url
 @param addtionalPath 文件根目录下的具体路径，不指定则搜索文件根路径下的指定文件并创建连接
 @return 是否创建成功
 */
-(BOOL)createlinkTo:(NSString *)identifier for:(NSString *)url withAddtionalPath:(nullable NSString *)addtionalPath;

/**
 外部完成对临时文件的处理,让engine处理临时文件
 
 @discussion engine对临时文件的处理包括3点:
             1.根据文件内容,将文件转移到最终的存放目录(fileIdentifierFor:,filePathForIdentifier:)
             2.创建url到文件的连接(createlinkTo:for:)
             3.移除临时文件
 @param url 待处理的url
 @param addtionalPath 文件根目录下的具体路径，不指定则将临时文件保存到文件根路径
 @return 文件的最终存放路径
 */
-(NSString *)completeTempFileFor:(NSString *)url withAddtionalPath:(nullable NSString *)addtionalPath;

@end
