<?php

// 检查是否加载了 FFI 扩展
if (extension_loaded('ffi')) {
    echo("已启用 FFI 扩展\n");
} else {
    die("未启动 FFI 扩展\n");
}

enum Hundun_error_code
{
    const Hundun_error_code_success = 0;        //  成功
    const Hundun_error_code_parameter = 1;      //  参数错误
    const Hundun_error_code_parse = 2;          //  解析错误
    const Hundun_error_code_licensefile = 3;    //  许可证文件或路径错误
    const Hundun_error_code_outofdate = 4;      //  日期已过
    const Hundun_error_code_unmatched = 5;      //  机器码不匹配
}

$ffi = FFI::cdef("
    int tianzuo_Hundun_check(const char* public_key_string, const char* license_file, int* days);
", "tianzuo.Hundun.dll");

$public_key = "-----BEGIN PUBLIC KEY-----
MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA3I4g6QtToZuQopoS7Myf
p1QPSBdC0PWNzG0Ii+oMeEp+aqiiVDU33aIrHgyXcBsDNFyPi3R3USNI9WbyO0cw
LrlYS8YRjP6ckz90lZph2VSXCFWXQm7nOqD4P9GC3QMvV3U9XLyLufRiZs0BcYVF
ENbm+jt3Z8/ikkFaLh0Mw8Y3ksjJN+Kd2DyEgpj5taLXHShHRyLjWAd102M2J4Id
z1hZg3CxyQNN7hQPmsFvZBsOejqAKeSO57/hRgo6IgZHh7iFbIpNyYjj1fxL0T5o
ouJ5yHODq8fWQ9ZHmk3po9QtbQJIYXO/ShfladQiZrz74vg6VFjleVyPp9m9gAUn
lQIDAQAB
-----END PUBLIC KEY-----\n";

define('Hundun_error_code_strings_cn', [
    "成功",
    "参数错误",
    "解析错误",
    "许可证文件或路径错误",
    "日期已过",
    "机器码不匹配"]);

define('Hundun_error_code_strings', [
    "success",
    "parameter error",
    "parse error",
    "license filename error",
    "out of date",
    "machine id unmatched"
]);

$days = FFI::new("int");
$error_code = $ffi->tianzuo_Hundun_check($public_key, "license.dat", FFI::addr($days));
if ($error_code != Hundun_error_code::Hundun_error_code_success) {
    echo "hundun.check error_code: " . $error_code . " error_string: " . Hundun_error_code_strings_cn[$error_code] . "\n";
    return;
}
echo "hundun.check days: " . $days->cdata . "\n";





?>