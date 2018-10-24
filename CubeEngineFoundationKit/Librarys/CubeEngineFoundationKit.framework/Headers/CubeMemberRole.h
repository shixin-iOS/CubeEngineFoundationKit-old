//
//  CubeMemberRole.h
//  CubeEngine
//
//  Created by zhangdi on 2018/5/15.
//  Copyright © 2018年 CubeTeam. All rights reserved.
//

#ifndef CubeMemberRole_h
#define CubeMemberRole_h

typedef enum _CubeMemberRole
{
    /**
     * 群主
     */
    CubeMemberRoleOwner,
    /**
     * 管理员
     */
    CubeMemerRoleMaster,
    /**
     * 群成员
     */
    CubeMemberRoleMember,
    /**
     * 来宾
     */
    CubeMemberRoleGuest,
}CubeMemberRole;

#endif /* CubeMemberRole_h */
