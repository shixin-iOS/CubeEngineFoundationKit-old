//
//  CubeCallType.h
//  CubeEngineFoundationKit
//
//  Created by Ashine on 2018/6/27.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#ifndef CubeCallType_h
#define CubeCallType_h


typedef enum : NSUInteger {
    CubeCallTypeCall = 1 << 0,        //一对一通话
    CubeCallTypeConfernce = 1 << 1,        //会议
} CubeCallType;

#endif /* CubeCallType_h */
