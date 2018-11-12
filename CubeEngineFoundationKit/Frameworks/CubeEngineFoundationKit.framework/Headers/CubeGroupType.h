//
//  CubeGroupType.h
//  CubeEngine
//
//  Created by zhangdi on 2018/5/15.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#ifndef CubeGroupType_h
#define CubeGroupType_h


// groupTypeString
// 普通群组
#define CubeGroupType_Normal_String                    @"normal"
// 多人语音
#define CubeGroupType_Voice_Call_String                @"voice-call"
// 多人视频
#define CubeGroupType_Video_Call_String                @"video-call"
// 音频会议
#define CubeGroupType_Voice_Conference_String          @"voice-conference"
// 视频会议
#define CubeGroupType_Video_Conference_String          @"video-conference"
// 融屏会议
#define CubeGroupType_Mux_Conference_String            @"mux-conference"
// 思科语音会议
#define CubeGroupType_Voice_Cisco_Conference_String    @"voice-cisco-conference"
// 思科视频会议
#define CubeGroupType_Video_Cisco_Conference_String    @"video-cisco-conference"
//屏幕分享会议 （webRTC模式）
#define CubeGroupType_Share_Desktop_Conference_String  @"share-screen"
// 共享桌面
#define CubeGroupType_Share_Desktop_String             @"share-desktop"
// 共享白板
#define CubeGroupType_Share_WB_String                  @"share-wb"
// 直播
#define CubeGroupType_Live_String                      @"live"


typedef enum : NSUInteger {
    CubeGroupType_Normal,                    // 普通群组
    CubeGroupType_Voice_Call,                // 多人语音
    CubeGroupType_Video_Call,                // 多人视频
    CubeGroupType_Voice_Conference,          // 音频会议
    CubeGroupType_Video_Conference,          // 视频会议
    CubeGroupType_Mux_Conference,            // 融屏会议
    CubeGroupType_Voice_Cisco_Conference,    // 思科语音会议
    CubeGroupType_Video_Cisco_Conference,    // 思科视频会议
    CubeGroupType_Share_Desktop_Conference,  //屏幕分享会议 （webRTC模式）
    CubeGroupType_Share_Desktop,             // 共享桌面
    CubeGroupType_Share_WB,                  // 共享白板
    CubeGroupType_Live,                      // 直播
} CubeGroupType;


#endif /* CubeGroupType_h */
