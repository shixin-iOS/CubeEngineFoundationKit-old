//
//  CubeFileService.h
//  CubeEngineFoundationKit
//
//  Created by Ashine on 2018/5/17.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <CubeEngineFoundationKit/CubeService.h>
#import <CubeEngineFoundationKit/CubeFileInfo.h>
#import <CubeEngineFoundationKit/DownloadCubeFile.h>
#import <CubeEngineFoundationKit/UploadCubeFile.h>
#import <CubeEngineFoundationKit/CubeError.h>


@protocol CubeFileServiceDelegate<NSObject>


/**
 文件上传成功回调

 @param cubeFile 成功上传的cubefile
 @param data 上传成功服务器返回数据
 */
- (void)onUploadFileComplete:(UploadCubeFile *)cubeFile andCompleteData:(NSDictionary *)data;


/**
 文件上传失败的回调

 @param cubeFile 上传失败的cubefile
 @param error 错误信息
 */
- (void)onUploadFileFailed:(UploadCubeFile *)cubeFile withError:(CubeError *)error;


/**
 文件上传进度回调

 @param cubeFile 上传中的文件
 @param progress 上传进度
 @param total 总进度
 */
- (void)onUploadFile:(UploadCubeFile *)cubeFile withUploadProgress:(long long)progress andTotal:(long long)total;


/**
 文件下载成功回调

 @param cubeFile 下载成功的cubeFile
 */
- (void)onDownloadFileComplete:(DownloadCubeFile *)cubeFile;


/**
 文件下载失败回调

 @param cubeFile 下载失败的cubeFile
 @param error 错误信息
 */
- (void)onDownloadFileFailed:(DownloadCubeFile *)cubeFile withError:(CubeError *)error;;


/**
 文件下载进度回调

 @param cubefile 下载中的文件
 @param progress 下载进度
 @param total 总进度
 */
- (void)onDownloadFile:(DownloadCubeFile *)cubefile withDownloadProgress:(long long)progress andTotal:(long long)total;

@end
// ---------------------------------------------------------------------------------------------------------------


@protocol CubeFileService <CubeService>


/**
  文件服务中 上传下载任务的回调监听
 */
@property (nonatomic,weak) id<CubeFileServiceDelegate> delegate;

#pragma mark - upload Info

///**
// 查询文件上传信息
//
// @param fileId 文件id
// @param uploadInfo 上传信息回调
// @param failure 失败回调
// */
//- (void)getUploadFileProgressWithFileId:(NSString *)fileId
//                             uploadInfo:(void(^)(NSDictionary *uploadInfo))uploadInfo
//                                failure:(void(^)(CubeError *error))failure;

#pragma mark -  upload file mission

/**
 文件上传

 @param cubeFile 待上传文件
 @param progress 上传进度回调
 @param success 成功回调
 @param failure 失败回调
 */
- (void)startUploadFileWithCubeFile:(UploadCubeFile *)cubeFile
                           progress:( void (^)(NSProgress * progress))progress
                            success:( void (^)(NSDictionary *responseData))success
                            failure:( void (^)(CubeError * error))failure;


/**
 取消上传

 @param cubeFile 文件
 @param success 成功回调
 @param failure 失败回调
 */
- (void)cancelUploadFileWithCubeFile:(UploadCubeFile *)cubeFile
                             success:( void (^)(NSDictionary *responseData))success
                             failure:(void (^)(CubeError *error))failure;


/**
 暂停上传

 @param cubeFile 文件
 @param success 成功回调
 @param failure 失败回调
 */
- (void)pauseUploadFileWithCubeFile:(UploadCubeFile *)cubeFile
                            success:( void (^)(NSDictionary *responseData))success
                            failure:(void (^)(CubeError *error))failure;;



/**
 恢复上传

 @param cubeFile 文件
 @param success 成功回调
 @param failure 失败回调
 */
- (void)resumeUploadFileWithCubeFile:(UploadCubeFile *)cubeFile
                            progress:( void (^)(NSProgress * progress))progress
                             success:( void (^)(NSDictionary *responseData))success
                             failure:(void (^)(CubeError *error))failure;;



#pragma mark - download file mission

/**
 下载文件

 @param cubeFile cubefile(带下载url及identif)
 @param progress 下载进度回调
 @param success 下载成功回调
 @param failure 下载失败回调
 */
- (void)startDownloadFileWithDownloadCubeFile:(DownloadCubeFile *)cubeFile
                                     progress:( void (^)(NSProgress * progress))progress
                                      success:( void (^)(id response))success
                                      failure:( void (^)(CubeError * error))failure;


/**
 暂停文件下载

 @param cubeFile 下载中文件
 */
- (void)pauseDownloadFileWithDownloadCubeFile:(DownloadCubeFile *)cubeFile
                                      success:( void (^)(int64_t receivedBytes))success
                                      failure:( void (^)(CubeError * error))failure;;



/**
 取消文件下载

 @param cubeFile 下载中文件
 */
- (void)cancelDownloadFileWithDownloadCubeFile:(DownloadCubeFile *)cubeFile
                                       success:( void (^)(id response))success
                                       failure:( void (^)(CubeError * error))failure;;



/**
 恢复文件下载

 @param cubeFile 下载中文件
 */
- (void)resumeDownloadFileWithDownloadCubeFile:(DownloadCubeFile *)cubeFile
                                      progress:( void (^)(NSProgress * progress))progress
                                       success:( void (^)(id response))success
                                       failure:( void (^)(CubeError * error))failure;


#pragma mark - file actions

/**
 创建文件目录

 @param dirName 文件目录名
 @param parentId 父文件夹id
 */
- (void)makeDirectoryWithDirectoryName:(NSString *)dirName andParentId:(NSString *)parentId
                               success:( void (^)(id response))success
                               failure:( void (^)(CubeError * error))failure;


/**
 * 批量删除文件或目录（删除目录时同时清除旗下文件）
 *
 * @param fileIds 批量删除的文件id集合
 */
- (void)deleteFileWithFileIds:(NSArray *)fileIds
                     success:( void (^)(id response))success
                     failure:( void (^)(CubeError * error))failure;


/**
 修改名称(文件/文件夹)

 @param fileId 文件id
 @param newName 文件名
 */
- (void)renameFileWithFileId:(NSString *)fileId andNewName:(NSString *)newName
                     success:( void (^)(id response))success
                     failure:( void (^)(CubeError * error))failure;


/**
 移动文件（移动文件或文件夹到别的文件夹下）

 @param fileIds 文件id集合
 @param parentId 父文件夹id
 @param success 成功回调
 @param failure 失败回调
 */
-(void)moveFileWithFileIds:(NSArray *)fileIds
              andParentId:(NSString *)parentId
                  success:(void (^)(id response))success
                  failure:(void (^)(CubeError * error))failure;


/**
 文件拷贝

 @param fileIds 文件id集合
 @param parentId 拷贝后父文件夹id
 */
- (void)copyFileWithFileIds:(NSArray *)fileIds andParentId:(NSString *)parentId
                   success:( void (^)(id response))success
                   failure:( void (^)(CubeError * error))failure;


/**
 获取当前目录下的文件列表信息（含目录）

 @param fileId 当前文件目录id
 @param callBack 查询结果回调
 */
- (void)getfileListWithFileId:(NSString *)fileId
              andListCallBack:(void (^)(NSArray <CubeFileInfo *> *list))callBack
                      success:( void (^)(id response))success
                      failure:( void (^)(CubeError * error))failure;


/**
 通过文件名查询文件查询文件

 @param fileName 文件名
 @param callBack 查询回调
 */
- (void)queryFileInfoByFileName:(NSString *)fileName
                andListCallBack:(void (^)(NSArray <CubeFileInfo *> *list))callBack
                        success:( void (^)(id response))success
                        failure:( void (^)(CubeError * error))failure;


/**
 通过文件Id查询文件查询文件

 @param fileIds 查询到文件id集合
 @param callBack 查询回调
 */
- (void)queryFileInfoByFileIds:(NSArray *)fileIds
              andListCallBack:(void (^)(NSArray <CubeFileInfo *> *list))callBack
                      success:( void (^)(id response))success
                      failure:( void (^)(CubeError * error))failure;



@end
