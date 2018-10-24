//
//  CubeUser.h
//  CubeEngineFoundationKit
//
//  Created by jianchengpan on 2018/5/8.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CubeEngineFoundationKit/CubeJsonObject.h>
#import <CubeEngineFoundationKit/CubeJsonUtil.h>

@interface CubeUser : NSObject<CubeJSONObject>

/**
 用户的cubeID
 */
@property (nonatomic, copy) NSString *cubeId;

/**
 用户昵称
 */
@property (nonatomic, copy) NSString *displayName;

/**
 用户头像
 */
@property (nonatomic, copy) NSString *avatar;

/**
 cubeToken
 */
@property (nonatomic, copy) NSString *cubeToken;

+(CubeUser *)userWithCubeId:(NSString *)cubeId andDiaplayName:(NSString *)displayName andAvatar:(NSString *)avatar;

@end
