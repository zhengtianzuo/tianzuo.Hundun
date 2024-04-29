#include <iostream>
#include "../../include/tianzuo.HundunInterface.h" // 接口头文件 interface heaher file

#define Get_Machineid 0

int main() {
	std::string public_key = "-----BEGIN PUBLIC KEY-----\n"
		"MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA3I4g6QtToZuQopoS7Myf\n"
		"p1QPSBdC0PWNzG0Ii+oMeEp+aqiiVDU33aIrHgyXcBsDNFyPi3R3USNI9WbyO0cw\n"
		"LrlYS8YRjP6ckz90lZph2VSXCFWXQm7nOqD4P9GC3QMvV3U9XLyLufRiZs0BcYVF\n"
		"ENbm+jt3Z8/ikkFaLh0Mw8Y3ksjJN+Kd2DyEgpj5taLXHShHRyLjWAd102M2J4Id\n"
		"z1hZg3CxyQNN7hQPmsFvZBsOejqAKeSO57/hRgo6IgZHh7iFbIpNyYjj1fxL0T5o\n"
		"ouJ5yHODq8fWQ9ZHmk3po9QtbQJIYXO/ShfladQiZrz74vg6VFjleVyPp9m9gAUn\n"
		"lQIDAQAB\n"
		"-----END PUBLIC KEY-----\n";

	tianzuo_HundunInt hundun;
#if Get_Machineid
	const char* id = hundun.get_machineid();
	if (id == nullptr) {
		std::cerr << "hundun.get_machineid error" << std::endl;
		return -1;
	}
	std::cout << "id: " << id << std::endl;
#else
	int days = 0;
	int error_code = tianzuo_Hundun_check(public_key.c_str(), "license.dat", &days);
	if (error_code != Hundun_error_code_success) {
		std::cout << "hundun.check error_code: " << error_code << " error_string: " << Hundun_error_code_strings_cn[error_code] << std::endl;
		return -1;
	}
	std::cout << "hundun.check days: " << days << std::endl;
#endif
	return 0;
}
