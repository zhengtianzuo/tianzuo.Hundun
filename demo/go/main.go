package main

/*
#include "tianzuo.HundunInterface.h"
*/
import "C"
import (
	"fmt"
	"syscall"
	"unsafe"
)

const (
	Hundun_error_code_success     = 0 //  成功
	Hundun_error_code_parameter   = 1 //  参数错误
	Hundun_error_code_parse       = 2 //  解析错误
	Hundun_error_code_licensefile = 3 //  许可证文件或路径错误
	Hundun_error_code_outofdate   = 4 //  日期已过
	Hundun_error_code_unmatched   = 5 //  机器码不匹配
)

func main() {
	const public_key string = "-----BEGIN PUBLIC KEY-----\n" +
		"MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA3I4g6QtToZuQopoS7Myf\n" +
		"p1QPSBdC0PWNzG0Ii+oMeEp+aqiiVDU33aIrHgyXcBsDNFyPi3R3USNI9WbyO0cw\n" +
		"LrlYS8YRjP6ckz90lZph2VSXCFWXQm7nOqD4P9GC3QMvV3U9XLyLufRiZs0BcYVF\n" +
		"ENbm+jt3Z8/ikkFaLh0Mw8Y3ksjJN+Kd2DyEgpj5taLXHShHRyLjWAd102M2J4Id\n" +
		"z1hZg3CxyQNN7hQPmsFvZBsOejqAKeSO57/hRgo6IgZHh7iFbIpNyYjj1fxL0T5o\n" +
		"ouJ5yHODq8fWQ9ZHmk3po9QtbQJIYXO/ShfladQiZrz74vg6VFjleVyPp9m9gAUn\n" +
		"lQIDAQAB\n" +
		"-----END PUBLIC KEY-----\n"

	Hundun_error_code_strings_cn := [6]string{
		"成功",
		"参数错误",
		"解析错误",
		"许可证文件或路径错误",
		"日期已过",
		"机器码不匹配"}

	//Hundun_error_code_strings := [6]string{
	//	"success",
	//	"parameter error",
	//	"parse error",
	//	"license filename error",
	//	"out of date",
	//	"machine id unmatched"}

	dll := syscall.MustLoadDLL("tianzuo.Hundun.dll")
	tianzuo_Hundun_check := dll.MustFindProc("tianzuo_Hundun_check")
	days := C.int(0)
	pub_key := C.CString(public_key)
	license_file := C.CString("license.dat")
	error_code, _, _ := tianzuo_Hundun_check.Call(uintptr(unsafe.Pointer(pub_key)), uintptr(unsafe.Pointer(license_file)), uintptr(unsafe.Pointer(&days)))
	if error_code != Hundun_error_code_success {
		fmt.Println("hundun.check error_code: ", error_code, " error_string: ", Hundun_error_code_strings_cn[error_code])
		return
	}
	fmt.Println("hundun.check days: ", days)
}
