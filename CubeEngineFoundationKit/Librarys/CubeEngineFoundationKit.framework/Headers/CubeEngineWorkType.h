//
//  CubeEngineWorkType.h
//  CubeEngine
//
//  Created by jianchengpan on 2018/5/21.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#ifndef CubeEngineWorkType_h
#define CubeEngineWorkType_h

typedef NS_ENUM(NSInteger,CubeEngineWorkType) {
	CubeEngineWorkTypeNone = 0,
	CubeEngineWorkTypeRequestAccess  = 1 << 1,
	CubeEngineWorkTypeSendingMessage = 1 << 2,
	CubeEngineWorkTypeSyncingMessage = 1 << 3,
    CubeEngineWorkTypeCalling = 1 << 4,
    CubeEngineWorkTypeMakingConference = 1 << 5,
};

#endif /* CubeEngineWorkType_h */
