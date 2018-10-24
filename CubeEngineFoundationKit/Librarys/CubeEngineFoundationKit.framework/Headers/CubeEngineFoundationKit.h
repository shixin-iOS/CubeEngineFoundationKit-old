//
//  CubeEngineFoundationKit.h
//  CubeEngineFoundationKit
//
//  Created by jianchengpan on 2018/5/8.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for CubeEngineFoundationKit.
FOUNDATION_EXPORT double CubeEngineFoundationKitVersionNumber;

//! Project version string for CubeEngineFoundationKit.
FOUNDATION_EXPORT const unsigned char CubeEngineFoundationKitVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <CubeEngineFoundationKit/PublicHeader.h>

#import <Genie/Genie.h>

// Engine
#import <CubeEngineFoundationKit/CubeConfig.h>
#import <CubeEngineFoundationKit/CubeEngineWorkType.h>
#import <CubeEngineFoundationKit/CubeEngine.h>

// Service
#import <CubeEngineFoundationKit/CubeService.h>
#import <CubeEngineFoundationKit/CubeUserService.h>
#import <CubeEngineFoundationKit/CubeMessageService.h>
#import <CubeEngineFoundationKit/CubeCallService.h>
#import <CubeEngineFoundationKit/CubeGroupService.h>
#import <CubeEngineFoundationKit/CubeConferenceService.h>
#import <CubeEngineFoundationKit/CubeFileService.h>
#import <CubeEngineFoundationKit/CubeShareDesktopService.h>
#import <CubeEngineFoundationKit/CubeWhiteboardService.h>
#import <CubeEngineFoundationKit/CubeMediaService.h>
#import <CubeEngineFoundationKit/CubeShareDesktopService.h>
#import <CubeEngineFoundationKit/CubeNetworkMonitorService.h>
#import <CubeEngineFoundationKit/CubeSettingService.h>

// UserService
#import <CubeEngineFoundationKit/CubeUser.h>
#import <CubeEngineFoundationKit/CubeDeviceInfo.h>


//MessageService
#import <CubeEngineFoundationKit/CubeMessageEntity.h>
#import <CubeEngineFoundationKit/CubeTextMessage.h>
#import <CubeEngineFoundationKit/CubeFileMessage.h>
#import <CubeEngineFoundationKit/CubeImageMessage.h>
#import <CubeEngineFoundationKit/CubeVoiceClipMessage.h>
#import <CubeEngineFoundationKit/CubeVideoClipMessage.h>
#import <CubeEngineFoundationKit/CubeCustomMessage.h>
#import <CubeEngineFoundationKit/CubeCardContent.h>
#import <CubeEngineFoundationKit/CubeCardMessage.h>
#import <CubeEngineFoundationKit/CubeReplyMessage.h>
#import <CubeEngineFoundationKit/CubeHistoryMessage.h>
#import <CubeEngineFoundationKit/CubeWhiteBoardMessage.h>
#import <CubeEngineFoundationKit/CubeWhiteBoardClipMessage.h>
#import <CubeEngineFoundationKit/CubeRichContentMessage.h>
#import <CubeEngineFoundationKit/CubeLocationMessage.h>
#import <CubeEngineFoundationKit/CubeReceiptMessage.h>

//GroupService
#import <CubeEngineFoundationKit/CubeGroup.h>
#import <CubeEngineFoundationKit/CubeGroupMember.h>
#import <CubeEngineFoundationKit/CubeGroupConfig.h>
#import <CubeEngineFoundationKit/CubeGroupPageInfo.h>
#import <CubeEngineFoundationKit/CubeGroupQuery.h>

//FileService
#import <CubeEngineFoundationKit/CubeFileInfo.h>
#import <CubeEngineFoundationKit/DownloadCubeFile.h>
#import <CubeEngineFoundationKit/UploadCubeFile.h>

//netWorkMonitor service
#import <CubeEngineFoundationKit/CubeNetworkState.h>

//SettingService
#import <CubeEngineFoundationKit/CubeSetting.h>

//ShareDesktopService

// Public

// ------ Util ------
#import <CubeEngineFoundationKit/CubeMessageUtil.h>
#import <CubeEngineFoundationKit/CubeGroupUtil.h>
#import <CubeEngineFoundationKit/CubeJsonUtil.h>

//------ protocls
#import <CubeEngineFoundationKit/CubeJsonObject.h>

//------ model ------
#import <CubeEngineFoundationKit/CubeError.h>

// ------ Enum ------
//state
#import <CubeEngineFoundationKit/CubeConnectionState.h>
#import <CubeEngineFoundationKit/CubeServiceState.h>
//error
#import <CubeEngineFoundationKit/CubeErrorType.h>

//media
#import <CubeEngineFoundationKit/CubemediaType.h>
#import <CubeEngineFoundationKit/CubeCallType.h>

//message
#import <CubeEngineFoundationKit/CubeMessageType.h>
#import <CubeEngineFoundationKit/CubeMessageStatus.h>
#import <CubeEngineFoundationKit/CubeMessageDirection.h>
#import <CubeEngineFoundationKit/CubeMessageAttachmentType.h>
//group
#import <CubeEngineFoundationKit/CubeGroupType.h>
#import <CubeEngineFoundationKit/CubeMemberRole.h>
// file
#import <CubeEngineFoundationKit/CubeFileType.h>
#import <CubeEngineFoundationKit/CubeFilePermission.h>
// conference
#import <CubeEngineFoundationKit/CubeConferenceControlAction.h>
// call
#import <CubeEngineFoundationKit/CubeCallActionDefine.h>
