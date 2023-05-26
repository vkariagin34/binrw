#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>

class bin_reader
{
private:
	std::vector<uint8_t> &src;
	size_t &carriage;	

public:
	inline bin_reader(std::vector<uint8_t> &src, size_t &carriage)
		: src(src)
		, carriage(carriage)
	{}

	inline ~bin_reader()
	{}

public:
	inline char read_char()
	{
		return src[carriage++];
	}

#ifdef USE_WCHAR
	inline wchar_t read_wchar()
	{
		return
	#ifdef _WIN32		
			(src[carriage++]) |
			(src[carriage++] << 8);			
	#elif __linux__
			(src[carriage++]) |
			(src[carriage++] << 8) |
			(src[carriage++] << 16) |
			(src[carriage++] << 24);
	#else
	#error "unsupported platform!"
	#endif
	}
#endif

	inline float read_float()
	{
		int32_t result = read_int32();
		return *reinterpret_cast<float *>(&result);
	}

public:
	inline int8_t read_int8()
	{
		return src[carriage++];
	}

	inline uint8_t read_uint8()
	{
		return src[carriage++];
	}

	inline int16_t read_int16()
	{
		return
			(src[carriage++]) |
			(src[carriage++] << 8);
	}

	inline uint16_t read_uint16()
	{
		return
			(src[carriage++]) |
			(src[carriage++] << 8);
	}

	inline int32_t read_int32()
	{
		return
			(src[carriage++]) |
			(src[carriage++] << 8) |
			(src[carriage++] << 16) |
			(src[carriage++] << 24);
	}

	inline uint32_t read_uint32()
	{
		return
			(src[carriage++]) |
			(src[carriage++] << 8) |
			(src[carriage++] << 16) |
			(src[carriage++] << 24);
	}

	inline int64_t read_int64()
	{
		return
			(static_cast<int64_t>(src[carriage++])) |
			(static_cast<int64_t>(src[carriage++]) << 8) |
			(static_cast<int64_t>(src[carriage++]) << 16) |
			(static_cast<int64_t>(src[carriage++]) << 24) |
			(static_cast<int64_t>(src[carriage++]) << 32) |
			(static_cast<int64_t>(src[carriage++]) << 40) |
			(static_cast<int64_t>(src[carriage++]) << 48) |
			(static_cast<int64_t>(src[carriage++]) << 54);
	}

	inline uint64_t read_uint64()
	{
		return
			(static_cast<uint64_t>(src[carriage++])) |
			(static_cast<uint64_t>(src[carriage++]) << 8) |
			(static_cast<uint64_t>(src[carriage++]) << 16) |
			(static_cast<uint64_t>(src[carriage++]) << 24) |
			(static_cast<uint64_t>(src[carriage++]) << 32) |
			(static_cast<uint64_t>(src[carriage++]) << 40) |
			(static_cast<uint64_t>(src[carriage++]) << 48) |
			(static_cast<uint64_t>(src[carriage++]) << 54);
	}

	inline std::string read_string()
	{
		std::string result;
		uint32_t length = read_uint32();
		while (length--)
		{
			result.push_back(read_char());
		}
		return result;
	}

#ifdef USE_WCHAR
	inline std::wstring read_wstring()
	{
		std::wstring result;
		uint32_t length = read_uint32();
		while (length--)
		{
			result.push_back(read_wchar());
		}
		return result;
	}
#endif
};
