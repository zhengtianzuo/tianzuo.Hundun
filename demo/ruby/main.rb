require 'fiddle'

lib = Fiddle::dlopen('C:/Users/zhengtianzuo/RubymineProjects/tianzuo.HundunTest/tianzuo.Hundun.dll')
tianzuo_Hundun_check = Fiddle::Function.new(lib['tianzuo_Hundun_check'], [Fiddle::TYPE_VOIDP, Fiddle::TYPE_VOIDP, Fiddle::TYPE_VOIDP], Fiddle::TYPE_INT)

public_key = "-----BEGIN PUBLIC KEY-----
MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA3I4g6QtToZuQopoS7Myf
p1QPSBdC0PWNzG0Ii+oMeEp+aqiiVDU33aIrHgyXcBsDNFyPi3R3USNI9WbyO0cw
LrlYS8YRjP6ckz90lZph2VSXCFWXQm7nOqD4P9GC3QMvV3U9XLyLufRiZs0BcYVF
ENbm+jt3Z8/ikkFaLh0Mw8Y3ksjJN+Kd2DyEgpj5taLXHShHRyLjWAd102M2J4Id
z1hZg3CxyQNN7hQPmsFvZBsOejqAKeSO57/hRgo6IgZHh7iFbIpNyYjj1fxL0T5o
ouJ5yHODq8fWQ9ZHmk3po9QtbQJIYXO/ShfladQiZrz74vg6VFjleVyPp9m9gAUn
lQIDAQAB
-----END PUBLIC KEY-----"

Hundun_error_code_strings_cn = [
  "成功",
  "参数错误",
  "解析错误",
  "许可证文件或路径错误",
  "日期已过",
  "机器码不匹配"]

Hundun_error_code_strings = [
  "success",
  "parameter error",
  "parse error",
  "license filename error",
  "out of date",
  "machine id unmatched"]

license_file = "license.dat"
days = Fiddle::Pointer.malloc(Fiddle::SIZEOF_INT)
error_code = tianzuo_Hundun_check.call(public_key, license_file, days)
if error_code != 0
  print("hundun.check error_code: ", error_code, " error_string:", Hundun_error_code_strings_cn[error_code] ," \n")
  return
end

int_days = days[0, Fiddle::SIZEOF_INT].unpack('I')[0]
print("hundun.check days: ", int_days, "\n")
