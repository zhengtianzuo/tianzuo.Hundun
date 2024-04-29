package cn.camelsoft;

import com.sun.jna.Library;
import com.sun.jna.Native;

enum Hundun_error_code {
    Hundun_error_code_success       (0),            ///<  成功
    Hundun_error_code_parameter     (1),            ///<  参数错误
    Hundun_error_code_parse         (2),            ///<  解析错误
    Hundun_error_code_licensefile   (3),            ///<  许可证文件或路径错误
    Hundun_error_code_outofdate     (4),            ///<  日期已过
    Hundun_error_code_unmatched     (5);            ///<  机器码不匹配

    private int value;

    Hundun_error_code(int value) {
        this.value = value;
    }

    public int getValue() {
        return value;
    }
}

public class Main {
    public interface tianzuo_HundunLib extends Library {
        tianzuo_HundunLib instance = (tianzuo_HundunLib) Native.load("./tianzuo.Hundun.dll", tianzuo_HundunLib.class);
        int tianzuo_Hundun_check(String public_key_string, String license_file, int[] days);
    }

    public static void main(String[] args) {
        System.setProperty("jna.encoding","UTF-8");

        String public_key = "-----BEGIN PUBLIC KEY-----\n" +
        "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA3I4g6QtToZuQopoS7Myf\n" +
        "p1QPSBdC0PWNzG0Ii+oMeEp+aqiiVDU33aIrHgyXcBsDNFyPi3R3USNI9WbyO0cw\n" +
        "LrlYS8YRjP6ckz90lZph2VSXCFWXQm7nOqD4P9GC3QMvV3U9XLyLufRiZs0BcYVF\n" +
        "ENbm+jt3Z8/ikkFaLh0Mw8Y3ksjJN+Kd2DyEgpj5taLXHShHRyLjWAd102M2J4Id\n" +
        "z1hZg3CxyQNN7hQPmsFvZBsOejqAKeSO57/hRgo6IgZHh7iFbIpNyYjj1fxL0T5o\n" +
        "ouJ5yHODq8fWQ9ZHmk3po9QtbQJIYXO/ShfladQiZrz74vg6VFjleVyPp9m9gAUn\n" +
        "lQIDAQAB\n" +
        "-----END PUBLIC KEY-----\n";

        String[] Hundun_error_code_strings_cn = {"成功",
                "参数错误",
                "解析错误",
                "许可证文件或路径错误",
                "日期已过",
                "机器码不匹配"};

        String[] Hundun_error_code_strings = {
                "success",
                "parameter error",
                "parse error",
                "license filename error",
                "out of date",
                "machine id unmatched"
        };

        int[] days = {0};
        int error_code = tianzuo_HundunLib.instance.tianzuo_Hundun_check(public_key, "license.dat", days);
        if (error_code != Hundun_error_code.Hundun_error_code_success.getValue()) {
            System.out.printf("hundun.check error_code: %d error_string: %s\n", error_code, Hundun_error_code_strings_cn[error_code]);
            return;
        }
        System.out.printf("hundun.check days: : %d\n", days[0]);
    }
}
