//
//  CubeWhiteBoardMessage.h
//  CubeEngineFoundationKit
//
//  Created by Ashine on 2018/5/22.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <CubeEngineFoundationKit/CubeFileMessage.h>

@interface CubeWhiteBoardMessage : CubeFileMessage

@property (nonatomic, assign) int currentPage;

@property (nonatomic, copy) NSString *firstPath;

@property (nonatomic, copy) NSString *slideName;

@property (nonatomic, strong) NSArray *slideUrls;

@property (nonatomic, strong) NSData *thumbFile;

@property (nonatomic, copy) NSString *thumbImage;

@property (nonatomic, copy) NSString *thumbUrl;

@property (nonatomic, copy) NSString *whiteboardRecords;

@end
