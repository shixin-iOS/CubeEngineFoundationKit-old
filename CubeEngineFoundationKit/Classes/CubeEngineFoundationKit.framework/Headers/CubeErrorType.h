//
//  CubeErrorType.h
//  CubeEngine
//
//  Created by zhangdi on 2018/5/16.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#ifndef CubeErrorType_h
#define CubeErrorType_h

typedef enum _CubeErrorType
{
    ///////////////////////// Engine  0 ~ 200 ////////////////////////////
    CubeErrorTypeSpeakerFailed = -1,
	CubeErrorTypeConnectError  = 10,			//连接错误
	CubeErrorTypeServiceNotFound = 11,			//未找到指定服务
	CubeErrorTypeServiceNotCall = 12,			//未创建服务连接
	
	///////////////////////// User  1000~1100 ////////////////////////////
	CubeErrorTypeInvalidToken = 1001,			//token失效
	CubeErrorTypeRegisterTimeout = 1002,		//登录超时
	CubeErrorTypeLicenseOutDate = 1003,			//license过期
	CubeErrorTypeUnRegister = 1004,				//用户未注册
	CubeErrorTypeLicenseServerError = 1005,		//license服务器错误
	CubeErrorTypeUpdateError = 1006,			//license更新出错
	CubeErrorTypeUnLogin = 1007,                //用户未登陆
	CubeErrorTypeIsCalling = 1099,				//用户正在通话中
	///////////////////////// Message  1100~1200 ////////////////////////////
	CubeErrorTypeFileMessageExist = 1112,       //文件已经存在
	CubeErrorTypeNoPullMessage = 1113,        	//没有消息
	CubeErrorTypeOutofMaxMessages = 1115, 		//没有回执消息
	CubeErrorTypeNoReceiptMessage = 1116, 		//没有回执消息
	
	CubeErrorTypeCannotFindMessage = 1197,		//找不到指定消息
	CubeErrorTypeSendMessageTimeout = 1198,		//发送消息超时
	CubeErrorTypeSaveMessageFailed = 1199,		//保存消息失败
	
    ///////////////////////// File   1200~1300 ////////////////////////////
    CubeErrorTypeFileSourceExpiredError = 1202,        //资源文件已过期
    CubeErrorTypeFileSourceDoNotExsitAtGivenPath = 1299 , // 在所给的文件本地路径中,文件不存在
    ///////////////////////// Group  1300~1400 ////////////////////////////
    /**
     * 添加管理员失败
     */
    CubeErrorTypeGroupAddMasterFailed = 1300,
    /**
     * 删除管理员失败
     */
    CubeErrorTypeGroupRemoveMasterFailed = 1301,
    /**
     * 群组已销毁
     */
    CubeErrorTypeGroupDestroy = 1302,
    /**
     * 群组不存在
     */
    CubeErrorTypeGroupNotExist = 1303,
    /**
     * 不在群组中
     */
    CubeErrorTypeNotInGroup = 1304,
    ///////////////////////// Call  1400~1500 ////////////////////////////
    
    /**
     * 主叫方不存在
     */
    CubeErrorTypeCallCallerNotFound = 1400,
    
    /**
     * 被叫方不存在
     */
    CubeErrorTypeCallCalleeNotFound = 1401,
    
    /**
     * 被叫方正在跟主叫方回叫
     */
    CubeErrorTypeCallCallerIsCallInreverse = 1402,
    
    /**
     * 被叫方正在通话中
     */
    CubeErrorTypeCallCalleeIsCalling = 1403,
    
    /**
     * 通话记录不存在
     */
    CubeErrorTypeCallRecordNotFound = 1404,
    
    /**
     * 主叫方正在通话中
     */
    CubeErrorTypeCallCallerIsCalling = 1405,
    
    /**
     * 正在其他终端通话中 不能发起通话
     */
    CubeErrorTypeCallIngOnOtherDevice = 1406,

    /**
     * 正在处理其它一对一服务指令
     */
    CubeErrorTypeCallIsBusy = 1498,
    ///////////////////////// Group  1500~1600 ////////////////////////////
    /**
     * 会议已存在
     */
    CubeErrorTypeConferenceExist = 1500,
    /**
     * 会议人数已达上限
     */
    CubeErrorTypeOverMaxNumber = 1501,
    /**
     * 会议被其他端拒绝
     */
    CubeErrorTypeConferenceRejectByOther = 1502,
    /**
     * 您已在其他终端参会
     */
    CubeErrorTypeConferenceJoinFromOther = 1503,
    /**
     * 申请会议失败
     */
    CubeErrorTypeApplyConferenceFailed = 1504,
    /**
     * 取消进入会议
     */
    CubeErrorTypeConferenceJoinCancel = 1505,
    /**
     * 申请进入会议失败
     */
    CubeErrorTypeApplyJoinConferenceFailed = 1506,
    /**
     * 会议操作超时
     */
    CubeErrorTypeConferenceTimeout = 1599,
    /**
     * 正在处理其它会议指令
     */
    CubeErrorTypeConferenceIsBusy = 1598,
    ///////////////////////// ShareDesktop  2000 ~ ////////////////////////////
    /**
     * 远程桌面不存在
     */
    CubeErrorTypeRemoteDeskTopNotExist = 2001,

    
}CubeErrorType;
#endif /* CubeErrorType_h */
