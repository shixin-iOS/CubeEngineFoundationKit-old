//
//  CubeServiceState.h
//  CubeEngineFoundationKit
//
//  Created by jianchengpan on 2018/6/11.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#ifndef CubeServiceState_h
#define CubeServiceState_h

typedef enum {
	CubeServiceStateShutdown,	//关闭
	CubeServiceStateStarted,	//启动
	CubeServiceStateNormal,		//正常
	CubeServiceStatePause,		//暂停
}CubeServiceState;

#endif /* CubeServiceState_h */
