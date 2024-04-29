
// *@file tianzuo_HundunInterface.h
// *@brief 天佐.混沌钟 (tianzuo.Hundun)
// *@version 1.0
// *@section LICENSE Copyright © 2003-2103 郑天佐 Corporation
// *@author 郑天佐 (zhengtianzuo)
// *@date 2024-1-1
#pragma once

//!@brief 导出函数定义(define dllexport)
#undef tianzuo_Hundun_lib
#if defined(WIN32)
#define tianzuo_Hundun_atr
#if defined(tianzuo_Hundun_dllexport)
#define tianzuo_Hundun_lib _declspec(dllexport)
#else
#define tianzuo_Hundun_lib
#endif
#else
#define tianzuo_Hundun_atr __attribute__((visibility("default")))
#define tianzuo_Hundun_lib
#endif

//!@enum 错误码
enum Hundun_error_code {
    Hundun_error_code_success,                ///<  成功
    Hundun_error_code_parameter,              ///<  参数错误
    Hundun_error_code_parse,                  ///<  解析错误
    Hundun_error_code_licensefile,            ///<  许可证文件或路径错误
    Hundun_error_code_outofdate,              ///<  日期已过
    Hundun_error_code_unmatched               ///<  机器码不匹配
};

//!@enum 错误码描述
static const char* Hundun_error_code_strings_cn[6] = {
    "成功",
    "参数错误",
    "解析错误",
    "许可证文件或路径错误",
    "日期已过",
    "机器码不匹配"
};

//!@enum 错误码描述
static const char* Hundun_error_code_strings[6] = {
    "success",
    "parameter error",
    "parse error",
    "license filename error",
    "out of date",
    "machine id unmatched"
};

//!@enum 许可证类型
enum Hundun_license_type {
    Hundun_license_type_none,
    Hundun_license_type_datelimit,
    Hundun_license_type_machinelimit,
    Hundun_license_type_machinedatelimit
};

//!@brief 混沌钟模块类 for c++
//!@class tianzuo_HundunInt for c++
class tianzuo_Hundun_lib tianzuo_HundunInt {
 public:
     tianzuo_HundunInt(){}
     ~tianzuo_HundunInt(){}
     
     /*!
     *@name check
     *@brief 验证许可证信息
     *@param[in] public_key_string 公钥字符串
     *@param[in] license_file 许可证文件路径
     *@param[out] days 剩余天数
     *@return int
     *@author 郑天佐
     *@date 2024-1-1
     */
     int check(const char* public_key_string, const char* license_file, int* days);
     
     /*!
     *@name get_machineid
     *@brief 获取注册码
     *@return char* 返回注册码字符串
     *@author 郑天佐
     *@date 2024-1-1
     */
     const char* get_machineid();
};

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
    tianzuo_Hundun_lib int tianzuo_Hundun_check(const char* public_key_string, const char* license_file, int* days);

    /*!
    *@name tianzuo_Hundun_get_machineid
    *@brief 获取注册码
    *@return char* 返回注册码字符串
    *@author 郑天佐
    *@date 2024-1-1
    */
    tianzuo_Hundun_lib const char* tianzuo_Hundun_get_machineid();

#ifdef __cplusplus
}
#endif
