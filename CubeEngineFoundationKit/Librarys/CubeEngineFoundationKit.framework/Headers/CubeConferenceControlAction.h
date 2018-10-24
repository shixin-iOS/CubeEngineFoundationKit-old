//
//  CubeConferenceControlAction.h
//  CubeEngineFoundationKit
//
//  Created by Ashine on 2018/6/26.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#ifndef CubeConferenceControlAction_h
#define CubeConferenceControlAction_h

/**
 * 禁听
 */
#define CubeConferenceControl_Action_HEAR         @"deaf"
/**
 * 禁视
 */
#define CubeConferenceControl_Action_VMUTE        @"vmute"
/**
 * 禁言
 */
#define CubeConferenceControl_Action_MUTE         @"mute"
/**
 * 语音入会
 */
#define CubeConferenceControl_Action_VOICE        @"voice"
/**
 * 视频入会
 */
#define CubeConferenceControl_Action_VIDEO        @"video"
/**
 * 踢出会议
 */
#define CubeConferenceControl_Action_KICK         @"kick"
/**
 * 主讲人变更
 */
#define CubeConferenceControl_Action_SPEAKER      @"floor"
/**
 * 主持人变更
 */
#define CubeConferenceControl_Action_PRESENTER    @"presenter"
/**
 * 数据变更(比如邀请列表人数变更时)
 */
#define CubeConferenceControl_Action_UPDATE       @"update"
/**
 * 未知动作
 */
#define CubeConferenceControl_Action_UNKNOWN      @"unknown"

#endif /* CubeConferenceControlAction_h */
