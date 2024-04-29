
// *@file tianzuo_HundunInterface.h
// *@brief 天佐.混沌钟 (tianzuo.Hundun)
// *@version 1.0
// *@section LICENSE Copyright © 2003-2103 郑天佐 Corporation
// *@author 郑天佐 (zhengtianzuo)
// *@date 2024-1-1
#pragma once

//!@brief 混沌钟接口 for python java csharp javascript php visualbasic go rust ruby
//!@class tianzuo_HundunInterface for python java csharp javascript php visualbasic go rust ruby
#ifdef __cplusplus
extern "C"
{
#endif

    /*!
    *@name tianzuo_Hundun_check
    *@brief 验证许可证信息
    *@param[in] public_key_string 公钥字符串
    *@param[in] license_file 许可证文件路径
    *@param[out] days 剩余天数
    *@return int
    *@author 郑天佐
    *@date 2024-1-1
    */
    int tianzuo_Hundun_check(const char* public_key_string, const char* license_file, int* days);

    /*!
    *@name tianzuo_Hundun_get_machineid
    *@brief 获取注册码
    *@return char* 返回注册码字符串
    *@author 郑天佐
    *@date 2024-1-1
    */
    const char* tianzuo_Hundun_get_machineid();

#ifdef __cplusplus
}
#endif
