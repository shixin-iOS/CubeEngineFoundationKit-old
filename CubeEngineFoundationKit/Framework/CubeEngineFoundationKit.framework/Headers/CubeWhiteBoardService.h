//
//  CubeWhiteBoardService.h
//  CubeEngineFoundationKit
//
//  Created by Ashine on 2018/5/28.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#import <CubeEngineFoundationKit/CubeService.h>

@class CubeWhiteBoardConfig;
@class CubeWhiteBoardSlide;
@class CubeWhiteBoard;
@class CubeUser;
@class CubeGroupMember;

@protocol CubeWhiteBoardServiceDelegate <NSObject>

/**
 当创建白板成功时回调

 @param whiteboard 白板实体
 @param from 白板创建者
 */
- (void)onWhiteboardCreated:(CubeWhiteBoard *)whiteboard from:(CubeUser *)from;


/**
 当白板销毁时回调

 @param whiteboard 白板实体
 @param from 白板销毁者（默认为创建者）
 */
- (void)onWhiteboardDestroyed:(CubeWhiteBoard *)whiteboard from:(CubeUser *)from;


/**
 有人申请加入版本时回调，仅群主和管理员（主持人）收到申请回调

 @param whiteboard 白板实体
 @param applier 申请者
 */
//- (void)onWhiteboardApplied:(CubeWhiteBoard *)whiteboard user:(CubeUser *)applier;


/**
 拒绝申请者加入白板回调（仅申请者和拒绝者收到）

 @param whiteboard 白板实体
 @param from  拒绝者
 @param applier 申请者
 */
//- (void)onWhiteboardRejectApplied:(CubeWhiteBoard *)whiteboard from:(CubeUser *)from user:(CubeUser *)applier;


/**
 同意申请者加入时回调

 @param whiteboard 白板实体
 @param from 同意者
 @param applier  申请者
 */
//- (void)onWhiteboardApplyJoined:(CubeWhiteBoard *)whiteboard from:(CubeUser *)from user:(CubeUser *)applier;


/**
 收到邀请回调(仅邀请者自己和被邀请者收到)

 @param whiteboard  白板实体
 @param from 邀请者
 @param invites  被邀请列表
 */
- (void)onWhiteboardInvited:(CubeWhiteBoard *)whiteboard from:(CubeUser *)from user:(NSArray<CubeGroupMember *> *)invites;


/**
 拒绝要邀请回调（仅拒绝者和邀请者收到

 @param whiteboard 白板实体
 @param from  邀请者
 @param rejectMember 拒绝加入者
 */
- (void)onWhiteboardRejectInvited:(CubeWhiteBoard *)whiteboard from:(CubeUser *)from rejectMember:(CubeUser *)rejectMember;

/**
 * 同意邀请加入时回调（仅自己和邀请者收到）
 *
 * @param whiteboard   白板实体
 * @param from         邀请者
 * @param joinedMember 同意加入者
 */
- (void)onWhiteboardAcceptInvited:(CubeWhiteBoard *)whiteboard from:(CubeUser *)from joinedMember:(CubeUser *)joinedMember;

/**
 * 有成员加入时回调
 *
 * @param whiteboard   白板实体
 * @param joinedMember 加入者
 */
- (void)onWhiteboardJoined:(CubeWhiteBoard *)whiteboard joinedMember:(CubeUser *)joinedMember;

/**
 * 有成员退出时回调
 *
 * @param whiteboard   白板实体
 * @param quitedMember 退出者
 */
- (void)onWhiteboardQuited:(CubeWhiteBoard *)whiteboard quitedMember:(CubeUser *)quitedMember;


/**
 * 幻灯片上传进度
 *
 * @param whiteboard 白板
 * @param slide 白板slide
 * @param processed 进度
 * @param total 总进度
 */
- (void)onSlideUploading:(CubeWhiteBoard *)whiteboard slide:(CubeWhiteBoardSlide *)slide processed:(long )processed total:(long )total;


/**
 * 幻灯片上传完成
 *
 * @param whiteboard 白板
 * @param slide slide
 */
- (void)onSlideUploadCompleted:(CubeWhiteBoard *)whiteboard  slide:(CubeWhiteBoardSlide *)slide;


/**
 * 幻灯片上传
 *
 * @param whiteboard 白板
 * @param slide slide
 */

- (void)onSlideUpdated:(CubeWhiteBoard *)whiteboard slide:(CubeWhiteBoardSlide *)slide;

/**
 * 白板错误
 *
 * @param error 错误信息
 */
- (void)onWhiteboardFailed:(CubeWhiteBoard *)whiteboard error:(CubeError *)error;

@end


@protocol CubeWhiteBoardService <CubeService>

@property (nonatomic,weak) id <CubeWhiteBoardServiceDelegate> delegate;

/**
 创建白板

 @param config 白板参数
  @return 指令是否成功
 */
- (BOOL)createWhiteBoardWithConfig:(CubeWhiteBoardConfig *)config ;


/**
 销毁白板

 @param whiteboardId 白板id
 @return 指令是否成功
 */
- (BOOL)destroyWhiteBoard:(NSString *)whiteboardId;



/**
 申请加入白板

 @param whiteboardId 白板id
  @return 指令是否成功
 */
- (BOOL)joinWhiteBoard:(NSString *)whiteboardId;



/**
 退出白板

 @param whiteboardId 白板id
  @return 指令是否成功
 */
- (BOOL)quitWhiteBoard:(NSString *)whiteboardId;



/**
 拒绝申请

 @param whiteboardId 白板Id
 @param cubeId 申请者ID
 */
//- (void)rejectApplyWhiteBoard:(NSString *)whiteboardId andCubeId:(NSString *)cubeId;



/**
 同意申请

 @param whiteboardId 白板Id
 @param cubeId 申请者ID
 */
//- (void)acceptApplyWhiteBoard:(NSString *)whiteboardId andCubeId:(NSString *)cubeId;


/**
 邀请白板成员

 @param whiteboardId 白板Id
 @param members 被邀请列表
 @return 指令是否成功
 */
- (BOOL)inviteMembersInWhiteBoard: (NSString *)whiteboardId withMembers:(NSArray *)members;


/**
 拒绝邀请

 @param whiteboardId 白板Id
 @param cubeId 邀请者ID
 @return 指令是否成功
 */
- (BOOL)rejectInviteWhiteBoard:(NSString *)whiteboardId andCubeId:(NSString *)cubeId;


/**
 接受邀请

 @param whiteboardId 白板Id
 @param cubeId 邀请者ID
 @return 指令是否成功
 */
- (BOOL)acceptInviteWhiteBoard:(NSString *)whiteboardId andCubeId:(NSString *)cubeId;


/**
 设置画笔粗细

 @param wide 宽度
 */
- (void)setLineWeight:(int )wide;


/**
 设置画笔颜色

 @param color 颜色
 */
- (void)setLineColor:(NSString *)color;


/**
 选择铅笔
 */
- (void)selectPencil;


/**
选择文本 (暂未开放)
 */
- (void)selectText;


/**
 选择方框
 */
- (void)selectRect;


/**
 选择圆圈
 */
- (void)selectEllipse;



/**
 选择箭头
 */
- (void)selectArrow;


/**
 取消选中模式
 */
- (void)unSelect;


/**
 撤销上一次操作
 */
- (void)undo;


/**
 恢复上一次操作
 */
- (void)redo;


/**
 擦除所有画笔标注
 */
- (void)erase;


/**
 清空白板所有数据
 */
- (void)cleanup;



/**
 缩放白板

 @param ratio 缩放比例
 */
- (void)zoom:(float )ratio;




/**
 获取白板当前缩放比例

 @param callBack 当前缩放比例回调
 */
- (void)getZoomRatio:(void (^)(float ratio))callBack;



/**
 分享云储存文件（office，图片及PDF）

 @param url 分享文件链接
 */
- (void)shareFileWithUrl:(NSString *)url;


/**
 分享本地文件

 @param file 本地文件
 */
- (void)shareFileWithFile:(UploadCubeFile *)file;


/**
 列出所有幻灯片

 @param whiteboardId 白板id
 @param resultCallBack 回调结果
 */
- (void)listFileWithWhiteBoardId:(NSString *)whiteboardId andResult:(void (^)(NSArray <CubeWhiteBoardSlide *> *))resultCallBack;



/**
 下一页（幻灯片模式操作）
 */
- (void)nextPage;


/**
 上一页（幻灯片模式操作）
 */
- (void)prevPage;



/**
 指定页（幻灯片模式操作）

 @param page 指定页
 */
- (void)gotoPage:(int)page;



/**
 获取白板画面（必须先创建白板）

 @return 白板画面
 */
- (UIView *)getView;



/**
 导出白板加密白板数据

 @param callBack 回调
 */
- (void)exportWhiteboard:(void(^)(NSString *whiteBoardData))callBack;


/**
 * 导入白板消息
 *
 * @param wbString 加密白板数据
 * @param callBack 回调
 */
- (void)importWhiteboard:(NSString *)wbString andCallBack:(void (^)( BOOL success))callBack;



/**
 设置背景颜色（#123456）

 @param color 颜色
 */
- (void)setBackgroundColor:(NSString *)color;



/**
 查询cubeId画的白板记录(暂未开通)

 @param cubeId cubeId
 @param isCover 是否覆盖
 @param startTime 开始时间
 */
- (void)queryRecordsWithCubeId:(NSString *)cubeId isCover:(BOOL )isCover startTime:(long )startTime;


/**
 查询白板actions记录

 @param whiteboardId 白板id
 @param since 起始
 @param until 截止
 @param success 成功回调
 @param failure 失败回调
 */
-(void)queryHistoryRecordsWithWhiteBoardId:(NSString *)whiteboardId andSince:(long)since andUntil:(long)until
                                   success:(void(^)(NSDictionary *data))success
                                   failure:(void(^)(CubeError *error))failure;


/**
 根据白板id查询白板信息 可输入id集合

 @param whiteBoardIds 白板id
 @param success 成功回调
 @param failure 失败回调
 */
- (void)queryWhiteBoardWithWhiteBoardId:(NSArray <NSString *> *)whiteBoardIds
                                success:(void(^)(NSDictionary *data))success
                                failure:(void(^)(CubeError *error))failure;

/**
 同步cubeId下的所有白板

 @param offset offset
 @param limit limit
 @param success 成功回调数据
 @param failure 失败回调
 */
- (void)syncWhiteBoardWithOffset:(int )offset andLimit:(int)limit
                         success:(void(^)(NSDictionary *data))success
                         failure:(void(^)(CubeError *error))failure;

//////////// 多白板策略暂不考虑 /////////
@end
