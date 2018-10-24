//
//  CubeConfig.h
//  CubeEngineFoundationKit
//
//  Created by jianchengpan on 2018/5/8.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CubeEngineFoundationKit/CubeEngineWorkType.h>

/** 引擎配置参数定义。
 *
 * 配置参数用于对引擎的运行状态及相关指标进行调整。
 * 可调整的参数有视频控制参数、消息控制参数、白板控制参数等。
 */
@interface CubeConfig : NSObject


/** 视频通话时用于控制视频尺寸的描述定义。
 *
 * 视频尺寸描述了魔方引擎使用多大的视频约束进行视频通话。
 * 应用程序根据需要设置己方的视频大小，当通话时将使用该视频大小与对端进行协商。
 */
typedef enum _VideoSize {
	/** 视频分辨率为 128×96 (12,288) 的尺寸设置。 */
	CubeVideoSizeSQCIF = 0,
	/** 视频分辨率为 160×120 (19,200) 的尺寸设置。 */
	CubeVideoSizeQQVGA,
	/** 视频分辨率为 320×240 (76,800) 的尺寸设置。 */
	CubeVideoSizeQVGA,
	/** 视频分辨率为 352×288 (101,376) 的尺寸设置。 */
	CubeVideoSizeCIF,
	/** 视频分辨率为 640×480 (307,200) 的尺寸设置。 */
	CubeVideoSizeVGA,
	/** 视频分辨率为 800×600 (480,000) 的尺寸设置。 */
	CubeVideoSizeSVGA,
	/** 视频分辨率为 960×720 (691,200) 的尺寸设置。 */
	CubeVideoSizeHD,
	/** 视频分辨率为 1024×768 (786,432) 的尺寸设置。 */
	CubeVideoSizeXGA,
	/** 视频分辨率为 1280×1024 (1,310,720) 的尺寸设置。 */
	CubeVideoSizeSXGA,
	/** 视频分辨率为 1600×1200 (1,920,000) 的尺寸设置。 */
	CubeVideoSizeUXGA,
	
	/** 视频分辨率为 400×240 (96,000) 的尺寸设置。 */
	CubeVideoSizeWQVGA = 64,
	/** 视频分辨率为 512×288 (147 456) 的尺寸设置。 */
	CubeVideoSizeWCIF,
	/** 视频分辨率为 800×480 (384,000) 的尺寸设置。 */
	CubeVideoSizeWVGA,
	/** 视频分辨率为 1024×600 (614,400) 的尺寸设置。 */
	CubeVideoSizeWSVGA,
	/** 视频分辨率为 1280×720 (921,600) 的尺寸设置。 */
	CubeVideoSizeWHD,
	/** 视频分辨率为 1280×768 (983,040) 的尺寸设置。 */
	CubeVideoSizeWXGA,
	/** 视频分辨率为 1920×1200 (2,304,000) 的尺寸设置。 */
	CubeVideoSizeWUXGA,
	
	/** 视频分辨率为 768×432 (331,776, a.k.a WVGA 16:9) 的尺寸设置。 */
	CubeVideoSizeW432P,
	/** 视频分辨率为 768×480 (368,640, a.k.a WVGA 16:10) 的尺寸设置。 */
	CubeVideoSizeW480P,
	
	/** 由引擎自动推荐的视频分辨率设置。 */
	CubeVideoSizeSmart
	
} VideoSize;


#pragma mark - engine

/**
 是否为debug Default is NO
 */
@property (nonatomic, assign) BOOL debug;
/**
 应用密钥
 */
@property (nonatomic, copy) NSString *appKey;
/**
 应用ID
 */
@property (nonatomic, copy) NSString *appId;

/**
 授权服务器地址
 */
@property (nonatomic, copy) NSString *licenseServer;

/**
 支持后台工作的工作类型(默认 none)
 */
@property (nonatomic, assign) CubeEngineWorkType enableBackgroundWorkType;

#pragma mark - message

/**
 消息超时时长(s)
 消息从调用引擎发送消息接口开始计时，超过 超时时长 判定为发送失败，默认180s
 */
@property (nonatomic, assign) int messageTimeOut;

/**
 启动时是否同步最近历史消息 Default is YES
 */
@property (nonatomic, assign) BOOL autoSyncMsg;

#pragma mark - video

/** 设置/返回视频尺寸，默认：@see CubeVideoSizeQVGA 。 */
@property (nonatomic, assign) VideoSize videoSize;

/**
 视频最大帧率,默认12
 */
@property (nonatomic, assign) int maxVideoFramerate;

#pragma mark - media
/**
 App数据，聊天，拍照等文件数据存放目录
 */
@property (nonatomic, copy) NSString *resourceDir;
/**
 音频通信格式Opus
 */
@property (nonatomic, copy) NSString *audioCodec;
/**
 视频通信格式VP8/VP9
 */
@property (nonatomic, copy) NSString *videoCodec;


#pragma mark - init

/**
 配置文件
 
 @param appId  应用ID
 @param appKey 应用密钥
 @return 配置
 */
+ (instancetype)configWithAppId:(NSString *)appId AppKey:(NSString *)appKey;

#pragma mark - video property

/** 返回指定的视频尺寸的画面纵横比。
 *
 * 指定的视频尺寸具有不同的画面纵横比，画面纵横比能帮助应用程序合理地展示视频画面。
 * 一般的常见纵横比有4:3、16:9和16:10。
 * 此方法采用的计算公式为：ratio = width / height 。
 *
 * @return 返回浮点数形式的视频纵横比。
 */
- (float)getAspectRatio;

/** 返回视频约束尺寸。
 */
- (CGSize)getConstraintSize;


@end
