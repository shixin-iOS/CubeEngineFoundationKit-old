//
//  CubeMessageType.h
//  CubeEngine
//
//  Created by jianchengpan on 2018/5/14.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#ifndef CubeMessageType_h
#define CubeMessageType_h

/** 一般消息类型描述。
 *
 */
typedef enum _CubeMessageType {
	/** 文本类型的消息。 */
	CubeMessageTypeText,
	/** 文件类型的消息。 */
	CubeMessageTypeFile,
	/** 图片类型的消息。 */
	CubeMessageTypeImage,
	/** 语音剪辑类型的消息。 */
	CubeMessageTypeVoiceClip,
	/** 视频剪辑类型的消息。 */
	CubeMessageTypeVideoClip,
	/** 自定义消息。 */
	CubeMessageTypeCustom,
	/** 卡片消息。 */
	CubeMessageTypeCard,
	/** 历史消息。 */
	CubeMessageTypeHistory,
	/** 普通白板消息。 */
	CubeMessageTypeWhiteboard,
	/** 白板剪辑消息。 */
	CubeMessageTypeWhiteboardClip,
	/** 富文本消息。 */
	CubeMessageTypeRichContent,
	/** 地理位置消息。 */
	CubeMessageTypeLocation,
	/** 回复消息 */
	CubeMessageTypeReply,
	/** 回执消息 */
	CubeMessageTypeReceipt,
	/** 未知类型消息。 */
	CubeMessageTypeUnknown = -1
	
} CubeMessageType;

#endif /* CubeMessageType_h */
