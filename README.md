# binrw
binary data reader/writer which may pack/unpack c++ standard simple data

supported data types:
char,
wchar_t (USE_WCHAR macro),
int8_t,
uint8_t,
int16_t,
uint16_t,
int32_t,
uint32_t,
int64_t,
uint64_t,
std::string,
std::wstring (USE_WCHAR macro)

usage:
very simple -> check main.cpp file

warning:
when transferring data via tcp / ip to other devices, you need to know the byte order of the destination operating system or device
