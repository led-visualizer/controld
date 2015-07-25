#pragma once

template<typename T> inline T swapbe(T x) {
	T result = 0;
	auto data = reinterpret_cast<unsigned char *>(&x);
	for(unsigned int i = 0; i < sizeof(T); ++i) {
		result |= data[sizeof(T) - i - 1] << (i * 8);
	}
	return result;
}
