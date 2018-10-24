//
//  CubeNetworkMonitorService.h
//  CubeEngineFoundationKit
//
//  Created by jianchengpan on 2018/8/6.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <CubeEngineFoundationKit/CubeService.h>
#import <CubeEngineFoundationKit/CubeNetworkState.h>

@protocol CubeNetworkMonitorServiceDelegate<NSObject>

@optional
/**
 网络状态改变

 @param newState 新的网络状态
 */
-(void)onNetworkDidChangeTo:(CubeNetworkState)newState;

@end

@protocol CubeNetworkMonitorService <CubeService>

@property (nonatomic, weak) id<CubeNetworkMonitorServiceDelegate> delegate;

@property (nonatomic, readonly) CubeNetworkState currentNetworkState;

@end
