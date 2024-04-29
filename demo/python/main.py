from ctypes import *
from enum import Enum
import ctypes


tianzuo_HundunLib = cdll.LoadLibrary('./tianzuo.Hundun.dll')


class Hundun_error_code(Enum):
    Hundun_error_code_success       = 0 # 成功
    Hundun_error_code_parameter     = 1 # 参数错误
    Hundun_error_code_parse         = 2 # 解析错误
    Hundun_error_code_licensefile   = 3 # 许可证文件或路径错误
    Hundun_error_code_outofdate     = 4 # 日期已过
    Hundun_error_code_unmatched     = 5 # 机器码不匹配


def tianzuo_Hundun_check(public_key_string, license_file, days):
    tianzuo_HundunLib.tianzuo_Hundun_check.argtypes = [c_char_p, c_char_p, ctypes.POINTER(ctypes.c_int)]
    return tianzuo_HundunLib.tianzuo_Hundun_check(public_key_string, license_file, days)


def main():
    public_key = (b"-----BEGIN PUBLIC KEY-----\n"
                  b"MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA3I4g6QtToZuQopoS7Myf\n"
                  b"p1QPSBdC0PWNzG0Ii+oMeEp+aqiiVDU33aIrHgyXcBsDNFyPi3R3USNI9WbyO0cw\n"
                  b"LrlYS8YRjP6ckz90lZph2VSXCFWXQm7nOqD4P9GC3QMvV3U9XLyLufRiZs0BcYVF\n"
                  b"ENbm+jt3Z8/ikkFaLh0Mw8Y3ksjJN+Kd2DyEgpj5taLXHShHRyLjWAd102M2J4Id\n"
                  b"z1hZg3CxyQNN7hQPmsFvZBsOejqAKeSO57/hRgo6IgZHh7iFbIpNyYjj1fxL0T5o\n"
                  b"ouJ5yHODq8fWQ9ZHmk3po9QtbQJIYXO/ShfladQiZrz74vg6VFjleVyPp9m9gAUn\n"
                  b"lQIDAQAB\n"
                  b"-----END PUBLIC KEY-----\n")

    Hundun_error_code_strings_cn = (
        "成功",
        "参数错误",
        "解析错误",
        "许可证文件或路径错误",
        "日期已过",
        "机器码不匹配")

    Hundun_error_code_strings = (
        "success",
        "parameter error",
        "parse error",
        "license filename error",
        "out of date",
        "machine id unmatched")

    days = ctypes.c_int()
    license_file = b"license.dat"
    error_code = tianzuo_Hundun_check(public_key, license_file, days)
    if error_code != Hundun_error_code.Hundun_error_code_success.value:
        print("hundun.check error_code: {} error_string: {}".format(error_code, Hundun_error_code_strings_cn[error_code]))
        return

    int_days = days.value
    print("hundun.check days: {}".format(int_days))


if __name__ == '__main__':
    main()
