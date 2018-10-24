//
//  CubeConnetctionStater.h
//  CubeEngineFoundationKit
//
//  Created by jianchengpan on 2018/5/10.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#ifndef CubeConnetctionState_h
#define CubeConnetctionState_h

typedef enum{
	CubeConnectionStateNotCall = 0,			//未分配连接
	CubeConnectionStateDisconnceted = 1 << 0,	//断开连接状态
	CubeConnectionStateConnceting = 1 << 1,	//连接中
	CubeConnectionStateConnceted = 1 << 2,		//连接成功
	CubeConnectionStateFailed = 1 << 3,		//连接失败
}CubeConnectionState;

#endif /* CubeConnetctionStater_h */
