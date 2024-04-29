
Imports System.Runtime.InteropServices

Enum Hundun_error_code
    Hundun_error_code_success = 0 '  成功
    Hundun_error_code_parameter = 1 '  参数错误
    Hundun_error_code_parse = 2 '  解析错误
    Hundun_error_code_licensefile = 3 '  许可证文件或路径错误
    Hundun_error_code_outofdate = 4 '  日期已过
    Hundun_error_code_unmatched = 5 '  机器码不匹配
End Enum

Module Program
    <DllImport("tianzuo.Hundun.dll")>
    Public Function tianzuo_Hundun_check(public_key_string As String, license_file As String, ByRef days As Integer) As Integer
    End Function

    ReadOnly Hundun_error_code_strings_cn() As String = {
        "成功",
        "参数错误",
        "解析错误",
        "许可证文件或路径错误",
        "日期已过",
        "机器码不匹配"}

    ReadOnly Hundun_error_code_strings() As String = {
        "success",
        "parameter error",
        "parse error",
        "license filename error",
        "out of date",
        "machine id unmatched"}

    Sub Main(args As String())
        Dim public_key As String = "-----BEGIN PUBLIC KEY-----
MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA3I4g6QtToZuQopoS7Myf
p1QPSBdC0PWNzG0Ii+oMeEp+aqiiVDU33aIrHgyXcBsDNFyPi3R3USNI9WbyO0cw
LrlYS8YRjP6ckz90lZph2VSXCFWXQm7nOqD4P9GC3QMvV3U9XLyLufRiZs0BcYVF
ENbm+jt3Z8/ikkFaLh0Mw8Y3ksjJN+Kd2DyEgpj5taLXHShHRyLjWAd102M2J4Id
z1hZg3CxyQNN7hQPmsFvZBsOejqAKeSO57/hRgo6IgZHh7iFbIpNyYjj1fxL0T5o
ouJ5yHODq8fWQ9ZHmk3po9QtbQJIYXO/ShfladQiZrz74vg6VFjleVyPp9m9gAUn
lQIDAQAB
-----END PUBLIC KEY-----"

        Dim license_file As String = "license.dat"
        Dim days As Integer = 0
        Dim error_code As Integer = tianzuo_Hundun_check(public_key, license_file, days)
        If (error_code <> Hundun_error_code.Hundun_error_code_success) Then
            Console.WriteLine("hundun.check error_code: " + error_code.ToString + " error_string: " + Hundun_error_code_strings_cn(error_code))
            Return
        End If

        Console.WriteLine("hundun.check days:" + days.ToString)
    End Sub
End Module
