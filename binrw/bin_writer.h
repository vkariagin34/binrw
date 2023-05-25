#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>

class bin_writer
{
private:
	std::vector<uint8_t> &dst;

public:
	inline bin_writer(std::vector<uint8_t> &dst)
		: dst(dst)
	{}

	inline ~bin_writer()
	{}

public:
	inline void write(const char &value)
	{
		dst.push_back(value & 0xFF);
	}

#ifdef USE_WCHAR
	inline void write(const wchar_t &value)
	{
	#ifdef _WIN32
		dst.push_back(value & 0xFF);
		dst.push_back((value >> 8) & 0xFF);
	#elif __linux__
		dst.push_back(value & 0xFF);
		dst.push_back((value >> 8) & 0xFF);
		dst.push_back((value >> 16) & 0xFF);
		dst.push_back((value >> 24) & 0xFF);
	#else
	#error "unsupported platform!"
	#endif
	}
#endif

public:
	inline void write(const int8_t &value)
	{
		dst.push_back(value & 0xFF);
	}

	inline void write(const uint8_t &value)
	{
		dst.push_back(value & 0xFF);
	}

	inline void write(const int16_t &value)
	{
		dst.push_back(value & 0xFF);
		dst.push_back((value >> 8) & 0xFF);				
	}

	inline void write(const uint16_t &value)
	{
		dst.push_back(value & 0xFF);
		dst.push_back((value >> 8) & 0xFF);				
	}

	inline void write(const int32_t &value)
	{
		dst.push_back(value & 0xFF);
		dst.push_back((value >> 8) & 0xFF);
		dst.push_back((value >> 16) & 0xFF);
		dst.push_back((value >> 24) & 0xFF);		
	}

	inline void write(const uint32_t &value)
	{
		dst.push_back(value & 0xFF);
		dst.push_back((value >> 8) & 0xFF);
		dst.push_back((value >> 16) & 0xFF);
		dst.push_back((value >> 24) & 0xFF);
	}
	
	inline void write(const int64_t &value)
	{
		dst.push_back(value & 0xFF);
		dst.push_back((value >> 8) & 0xFF);
		dst.push_back((value >> 16) & 0xFF);
		dst.push_back((value >> 24) & 0xFF);
		dst.push_back((value >> 32) & 0xFF);
		dst.push_back((value >> 40) & 0xFF);
		dst.push_back((value >> 48) & 0xFF);
		dst.push_back((value >> 56) & 0xFF);
	}

	inline void write(const uint64_t &value)
	{
		dst.push_back(value & 0xFF);
		dst.push_back((value >> 8) & 0xFF);
		dst.push_back((value >> 16) & 0xFF);
		dst.push_back((value >> 24) & 0xFF);
		dst.push_back((value >> 32) & 0xFF);
		dst.push_back((value >> 40) & 0xFF);
		dst.push_back((value >> 48) & 0xFF);
		dst.push_back((value >> 56) & 0xFF);
	}

	inline void write(const std::string &value)
	{
		const uint32_t length = static_cast<const uint32_t>(value.length());
		write(length);
		for (auto &item : value)
		{
			write(item);
		}
	}

#ifdef USE_WCHAR
	inline void write(const std::wstring &value)
	{
		const uint32_t length = static_cast<const uint32_t>(value.length());
		write(length);
		for (auto &item : value)
		{
			write(item);
		}
	}
#endif
};
