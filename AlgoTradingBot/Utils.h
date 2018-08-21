#pragma once

#ifndef UTILS
#define UTILS

#include <vector>
#include <cstdint>

class Utils {
public:
	static inline bool is_base64(std::uint8_t c);
	static std::vector<std::uint8_t> base64_decode(std::string const&);
	static std::string formatDoubleString(std::string const&);
};
#endif // ! UTILS
