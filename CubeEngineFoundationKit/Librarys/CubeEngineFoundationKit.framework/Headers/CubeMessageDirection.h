//
//  CubeMessageDirection.h
//  CubeEngine
//
//  Created by jianchengpan on 2018/5/14.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#ifndef CubeMessageDirection_h
#define CubeMessageDirection_h

/** 消息方向。
 *
 */
typedef enum _CubeMessageDirection
{
	/** 消息方向未定义。 */
	CubeMessageDirectionNone,
	/** 收到的消息。 */
	CubeMessageDirectionReceived,
	/** 发出的消息。 */
	CubeMessageDirectionSent
}
CubeMessageDirection;

#endif /* CubeMessageDirection_h */
