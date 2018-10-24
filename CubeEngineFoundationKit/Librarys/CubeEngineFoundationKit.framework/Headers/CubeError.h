//
//  CubeError.h
//  CubeEngineFoundationKit
//
//  Created by jianchengpan on 2018/5/8.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CubeEngineFoundationKit/CubeJsonObject.h>

@interface CubeError : NSObject<CubeJSONObject>

@property (nonatomic, assign) int errorCode;

@property (nonatomic, copy) NSString *errorInfo;

@property (nonatomic, copy) NSDictionary *userInfo;

+(CubeError *)errorWithCode:(int)errorCode andErrorInfo:(NSString *)errorInfo andUserInfo:(NSDictionary *)userInfo;

@end
