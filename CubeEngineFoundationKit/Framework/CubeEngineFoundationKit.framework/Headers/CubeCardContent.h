//
//  CubeCardContent.h
//  CubeEngineFoundationKit
//
//  Created by jianchengpan on 2018/5/17.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CubeEngineFoundationKit/CubeJSONObject.h>

@interface CubeCardContent : NSObject<CubeJSONObject>

/**卡片消息URL*/
@property (nonatomic, copy) NSString *url;

/**卡片消息头像*/
@property (nonatomic, copy) NSString *icon;

/** 卡片名称*/
@property (nonatomic, copy) NSString *name;

/**描述*/
@property (nonatomic, copy) NSString *desc;

/**
 卡片内容初始化

 @param url 卡片消息URL
 @param icon 卡片消息头像
 @param name name
 @param desc 卡片名称
 @return 卡片内容
 */
-(instancetype)initWithUrl:(NSString *)url icon:(NSString *)icon name:(NSString *)name desc:(NSString *)desc;

@end
