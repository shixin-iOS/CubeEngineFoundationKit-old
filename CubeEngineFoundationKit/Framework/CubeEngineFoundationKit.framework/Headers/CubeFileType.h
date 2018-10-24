//
//  CubeFileType.h
//  CubeEngineFoundationKit
//
//  Created by Ashine on 2018/5/22.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#ifndef CubeFileType_h
#define CubeFileType_h



typedef enum : NSUInteger {
    /** 文件夹类型。 */
    CubeFileTypeFolder = 1,
    /** PDF类型。 */
    CubeFileTypePDF = 2,
    /** WORD类型。 */
    CubeFileTypeWord = 3,
    /** EXCEL类型。 */
    CubeFileTypeEXCEL = 4,
    /** PPT类型。 */
    CubeFileTypePPT = 5,
    /** 图片类型。 */
    CubeFileTypeImage = 11,
    /** OFFICE类型。 */
    CubeFileTypeOffice = 12,
    /** 视频类型。 */
    CubeFileTypeVideo = 13,
    /** 音频类型。 */
    CubeFileTypeAudio = 14,
    /** 应用类型。 */
    CubeFileTypeApp = 15,
    /** 压缩包类型。 */
    CubeFileTypeZip = 16,
    /** 白板类型。 */
    CubeFileTypeWhiteboard = 20,
    /** 其他常规文件类型。 */
    CubeFileTypeFile = 99,
    /** 未知类型 */
    CubeFileTypeOther = 100

} CubeFileType;


#endif /* CubeFileType_h */
