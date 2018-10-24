//
//  CubeFilePermission.h
//  CubeEngineFoundationKit
//
//  Created by Ashine on 2018/5/22.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#ifndef CubeFilePermission_h
#define CubeFilePermission_h

typedef enum : NSUInteger {
    /** 可读文件内容。 */
    CubeFilePermRead = 1<<0,
    /** 可创建新文件。 */
    CubeFilePermNewFile = 1<<1,
    /** 可创建新目录。 */
    CubeFilePermNewFolder = 1<<2,
    /** 可移动文件或目录。 */
    CubeFilePermMove = 1<<3,
    /** 可重命名文件或目录。 */
    CubeFilePermRename = 1<<4,
    /** 可删除文件或目录。 */
    CubeFilePermDelete = 1<<5,
    /** 可下载文件数据。 */
    CubeFilePermDownload = 1<<6,
    /** 可分享文件。 */
    CubeFilePermShare = 1<<7
} CubeFilePermission;


#endif /* CubeFilePermission_h */
