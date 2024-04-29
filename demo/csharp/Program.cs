

using System.Runtime.InteropServices;

class Program {
    [DllImport("tianzuo.Hundun.dll")]
    public static extern int tianzuo_Hundun_check(string public_key_string, string license_file, ref int days);

    public enum Hundun_error_code
    {
        Hundun_error_code_success,                ///<  成功
        Hundun_error_code_parameter,              ///<  参数错误
        Hundun_error_code_parse,                  ///<  解析错误
        Hundun_error_code_licensefile,            ///<  许可证文件或路径错误
        Hundun_error_code_outofdate,              ///<  日期已过
        Hundun_error_code_unmatched               ///<  机器码不匹配
    }

    public string[] Hundun_error_code_strings_cn = {
        "成功",
        "参数错误",
        "解析错误",
        "许可证文件或路径错误",
        "日期已过",
        "机器码不匹配"
    };

    public string[] Hundun_error_code_strings = {
        "success",
        "parameter error",
        "parse error",
        "license filename error",
        "out of date",
        "machine id unmatched"
    };

    static void Main(string[] args) {
        string public_key = "-----BEGIN PUBLIC KEY-----\n" +
            "MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA3I4g6QtToZuQopoS7Myf\n" +
            "p1QPSBdC0PWNzG0Ii+oMeEp+aqiiVDU33aIrHgyXcBsDNFyPi3R3USNI9WbyO0cw\n" +
            "LrlYS8YRjP6ckz90lZph2VSXCFWXQm7nOqD4P9GC3QMvV3U9XLyLufRiZs0BcYVF\n" +
            "ENbm+jt3Z8/ikkFaLh0Mw8Y3ksjJN+Kd2DyEgpj5taLXHShHRyLjWAd102M2J4Id\n" +
            "z1hZg3CxyQNN7hQPmsFvZBsOejqAKeSO57/hRgo6IgZHh7iFbIpNyYjj1fxL0T5o\n" +
            "ouJ5yHODq8fWQ9ZHmk3po9QtbQJIYXO/ShfladQiZrz74vg6VFjleVyPp9m9gAUn\n" +
            "lQIDAQAB\n" +
            "-----END PUBLIC KEY-----\n";

        int days = 0;
        int error_code = tianzuo_Hundun_check(public_key, "license.dat", ref days);
        if (error_code != (int)Hundun_error_code.Hundun_error_code_success)
        {
            Program myProgram = new Program();
            Console.WriteLine("hundun.check error_code: " + error_code + " error_string: " + myProgram.Hundun_error_code_strings_cn[error_code]);
            return;
        }
        Console.WriteLine("hundun.check days: " + days);

    }

}