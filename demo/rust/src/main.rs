
use std::os::raw::c_char;
use std::ffi::{c_int};
use std::ffi::CString;

#[link(name = "tianzuo.Hundun")]
extern {
    fn tianzuo_Hundun_check(public_key_string: *const c_char, license_file: *const c_char, days: *const c_int) -> c_int;
}

const Hundun_error_code_strings_cn: [&str; 6] = [
    "成功",
    "参数错误",
    "解析错误",
    "许可证文件或路径错误",
    "日期已过",
    "机器码不匹配"];

const Hundun_error_code_strings: [&str; 6] = [
    "success",
    "parameter error",
    "parse error",
    "license filename error",
    "out of date",
    "machine id unmatched"];

fn main() {
    unsafe {
        let public_key = CString::new(String::from("-----BEGIN PUBLIC KEY-----\n\
        MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA3I4g6QtToZuQopoS7Myf\n\
        p1QPSBdC0PWNzG0Ii+oMeEp+aqiiVDU33aIrHgyXcBsDNFyPi3R3USNI9WbyO0cw\n\
        LrlYS8YRjP6ckz90lZph2VSXCFWXQm7nOqD4P9GC3QMvV3U9XLyLufRiZs0BcYVF\n\
        ENbm+jt3Z8/ikkFaLh0Mw8Y3ksjJN+Kd2DyEgpj5taLXHShHRyLjWAd102M2J4Id\n\
        z1hZg3CxyQNN7hQPmsFvZBsOejqAKeSO57/hRgo6IgZHh7iFbIpNyYjj1fxL0T5o\n\
        ouJ5yHODq8fWQ9ZHmk3po9QtbQJIYXO/ShfladQiZrz74vg6VFjleVyPp9m9gAUn\n\
        lQIDAQAB\n\
        -----END PUBLIC KEY-----\n")).expect("Failed to create CString");



        let license_file = CString::new(String::from("license.dat")).expect("Failed to create CString");
        let mut days: c_int = 0;
        let error_code = tianzuo_Hundun_check(public_key.as_ptr(), license_file.as_ptr(), &mut days);
        if 0 != error_code {
            let errorc: usize =  error_code as usize;
            println!("hundun.check error_code: {:?} error_string: {:?}", error_code, Hundun_error_code_strings_cn[errorc]);
        }

        println!("hundun.check days: {:?}", days);
    }
}
