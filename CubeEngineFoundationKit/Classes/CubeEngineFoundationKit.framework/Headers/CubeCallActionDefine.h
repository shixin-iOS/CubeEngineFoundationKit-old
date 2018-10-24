//
//  CubeCallActionDefine.h
//  CubeEngineFoundationKit
//
//  Created by Ashine on 2018/7/4.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#ifndef CubeCallActionDefine_h
#define CubeCallActionDefine_h


#pragma mark -- CubeCallServiceAction_CallAction

/**
 * 被挂断
 */
#define CubeCallAction_BYE             @"bye"

/**
 * 主动挂断
 */
#define CubeCallAction_BYE_ACK         @"bye-ack"

/**
 * 被取消
 */
#define CubeCallAction_CANCEL          @"cancel"

/**
 * 主动取消
 */
#define CubeCallAction_CANCEL_ACK      @"cancel-ack"

/**
 * 被其他终端接听
 */
#define CubeCallAction_ANSWER_BY_OTHER @"answer－by-other"

/**
 * 被其他终端取消
 */
#define CubeCallAction_CANCEL_BY_OTHER @"cancel－by-other"

/**
 * 未知挂断
 */
#define CubeCallAction_UNKNOWN         @"unknown"

#endif /* CubeCallActionDefine_h */
