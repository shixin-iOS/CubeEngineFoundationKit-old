//
//  CubeMediaService.h
//  CubeEngineFoundationKit
//
//  Created by jianchengpan on 2018/6/5.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CubeEngineFoundationKit/CubemediaType.h>
#import <AVFoundation/AVFoundation.h>
#import <CubeEngineFoundationKit/CubeCallType.h>

#pragma mark - control Call

@protocol CubeCallControlServiceDelegate<NSObject>


@end

@protocol CubeCallControlService <NSObject>

#pragma mark - check

/**
 是否正在通话

 @return 是否正在通话
 */
-(BOOL)isCalling;

/**
 获取当前所有通话
 
 @param types 通话类型
 @return 所有通话
 */
- (NSArray *)currentCallWithCallType:(CubeCallType )types;

#pragma mark - codec

/**
 获取指定媒体类型的编码器
 
 @param target 通话对端cubeId
 @param mediaType 媒体类型
 @return 编码器
 */
-(NSString *)codecForTarget:(NSString *)target andMediaType:(CubeMediaType)mediaType;

#pragma mark - manage meida

/**
 获取指定媒体类型是否已开启
 
 @param mediaType 媒体类型
 @param target 通话对端cubeID
 @return 是否开启
 */
-(BOOL)enableMediaType:(CubeMediaType)mediaType forTarget:(NSString *)target;

/**
 控制指定媒体类型的开关
 
 @param mediaType 媒体类型
 @param enable 开启|关闭
 @param target 通话对端cubeId
 */
-(void)setMediaType:(CubeMediaType)mediaType enable:(BOOL)enable forTarget:(NSString *)target;

#pragma mark - manage speaker

/**
 扬声器是否可用
 
 @param target 通话对端cubeId
 @return 是否可用
 */
-(BOOL)speakerEnableForTarget:(NSString *)target;

/**
 开启|关闭 扬声器
 
 @param enable 开启|关闭
 @param target 通话对端cubeId
 */
-(void)setSpeakerEnable:(BOOL)enable forTarget:(NSString *)target;

#pragma mark - manage camera

/**
 切换摄像头
 
 @param target 通话对端cubeId
 */
-(void)switchCameraForTarget:(NSString *)target;

/**
 改变摄像头分辨率
 
 @param format 分辨率
 @param fps fps
 @param target 通话对端cubeId
 */
-(void)changeCaptureFormat:(CGSize)format andFPS:(int)fps forTarget:(NSString *)target;

#pragma mark - manager video view

/**
 获取本地视频画面
 
 @param target 对端cubeId
 @return 本地视频画面
 */
-(UIView *)getLocalViewForTarget:(NSString *)target;

/**
 获取远端视频会话
 
 @param target 对端cubeId
 @return 本地视频画面
 */
-(UIView *)getRemoteViewForTarget:(NSString *)target;

@end

#pragma mark - record

@protocol CubeRecordServiceDelegate<NSObject>

#pragma image and video

/**
 录制会话已启动

 @param preview 预览视图
 */
-(void)recordSessionStartedWithPreview:(UIView *)preview;

/**
 录制会话已停止
 */
-(void)recordSessionStopped;

/**
 拍照完成

 @param image 图片信息(使用imagedata和attachments生成)
 @param imageData 图片data
 @param attachments 图片附加信息
 @param error 错误信息(nil表示没有错误)
 */
-(void)capturedImage:(UIImage *)image andData:(NSData *)imageData andttachment:(NSDictionary *)attachments withError:(CubeError *)error;

/**
 开始录制视频

 @param filePath 视频保存位置
 */
-(void)didStartRecordVideoToFile:(NSString *)filePath;

/**
 录制结束

 @param filePath 文件路径
 @param error 错误信息
 */
-(void)didfinishedRecordVideoToFile:(NSString *)filePath withError:(CubeError *)error;

#pragma mark - audio

/**
 开始录制音频

 @param filePath 音频文件路径
 */
-(void)didStartRecordAudioToFile:(NSString *)filePath;

/**
 录制结束

 @param filePath 文件路径
 @param error 错误信息
 */
-(void)didFinishedRecordAudioToFile:(NSString *)filePath withError:(CubeError *)error;

@end

@protocol CubeRecordService<NSObject>

/**
 当前闪光灯模式(如果闪光灯可用，则默认为自动 AVCaptureFlashModeAuto 否则默认为 AVCaptureFlashModeOff)
 */
@property (nonatomic, assign) AVCaptureFlashMode currentFlashModel;

#pragma mark - record video control

/**
 开启录制会话
 */
-(void)startVideoRecordSession;

/**
 切换摄像头
 */
-(void)switchCamera;

/**
 闪光灯当前是否可用

 @return 是否可用
 */
-(BOOL)flashAvailable;

/**
 停止录制会话
 */
-(void)stopVideoRecordSession;

/**
 拍照
 */
-(void)takePhoto;

/**
 开始录制带时间限制的视频

 @param duration 最大时长限制 时间限制(s)
 */
-(void)startRecordVideoWithDuration:(int)duration;

/**
 停止录制视频
 */
-(void)stopRecordVideo;

#pragma mark - record audio

/**
 开始录制音频

 @param duratin 最大时长限制(2)
 */
-(void)startRecordAudioWithDuration:(int)duratin;

/**
 停止音频录制
 */
-(void)stopRecordAudio;

#pragma mark - monitor device orientation

/**
 开始检测屏幕方向变化
 */
-(void)startMonitorDeviceOrientation;

/**
 停止检测屏幕方向变化
 */
-(void)stopMonitorDeviceOrientation;

@end

#pragma mark - play service
@protocol CubeMediaPlayServiceDelegate<NSObject>

-(void)didStartedPlay:(NSString *)file duration:(CMTime)duration viewLayer:(AVPlayerLayer *)layer;

-(void)didCompletedPlay:(NSString *)file withError:(CubeError *)error;

@end

@protocol CubeMediaPlayService<NSObject>

/**
 当前播放文件的路径
 */
@property (nonatomic, copy) NSString *currentPlay;

/**
 播放文件

 @param filePath 文件路径
 @param repeate 播放次数
 */
-(void)play:(NSString *)filePath repeatTimes:(NSInteger)repeate;

/**
 停止当前播放
 */
-(void)stopCurrentPlay;

@end

#pragma mark - media

@protocol CubeMediaService<CubeCallControlService,CubeRecordService,CubeMediaPlayService,CubeService>

@property (nonatomic, weak) id<CubeCallControlServiceDelegate> callControlDelegate;

@property (nonatomic, weak) id<CubeRecordServiceDelegate> recordServiceDelegate;

@property (nonatomic, weak) id<CubeMediaPlayServiceDelegate> mediaPlayServiceDelegate;

@end

