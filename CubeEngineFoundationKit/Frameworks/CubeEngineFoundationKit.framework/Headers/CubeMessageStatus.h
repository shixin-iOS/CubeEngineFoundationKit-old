//
//  CubeMessageStatus.h
//  CubeEngine
//
//  Created by jianchengpan on 2018/5/14.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#ifndef CubeMessageStatus_h
#define CubeMessageStatus_h

/** 消息状态描述。
 */
typedef enum _CubeMessageStatus {
	/** 创建成功待发送。 */
	CubeMessageStatusCreated = 0,
	/** 发送过程中。 */
	CubeMessageStatusSending = 1,
	/** 接收过程中。 */
	CubeMessageStatusReceiving = 2,
	/** 消息处理成功。 */
	CubeMessageStatusSucceed = 3,
	/**消息暂停*/
	CubeMessageStatusPaused = 4,
	/** 消息处理失败。 */
	CubeMessageStatusFailed = -1
	
} CubeMessageStatus;

#endif /* CubeMessageStatus_h */
