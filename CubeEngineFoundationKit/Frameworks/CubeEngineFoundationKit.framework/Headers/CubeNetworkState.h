//
//  CubeNetworkState.h
//  CubeEngine
//
//  Created by jianchengpan on 2018/8/6.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#ifndef CubeNetworkState_h
#define CubeNetworkState_h

typedef NS_ENUM(NSUInteger, CubeNetworkState) {
	CubeNetworkStateNotReachable = 0,
	CubeNetworkStateReachableViaWiFi,
	CubeNetworkStateReachableViaWWAN,
	CubeNetworkStateReachablelossy
};

#endif /* CubeNetworkState_h */
