#include "binrw.h"

int main()
{
	// -------------------------------------
	std::vector<uint8_t> packet;

	// -------------------------------------
	char c = 'h';

#ifdef USE_WCHAR
	wchar_t wc = L'h';
#endif // USE_WCHAR

	int8_t int8 = 55;
	uint8_t uint8 = 55;

	int16_t int16 = 5'555;
	uint16_t uint16 = 5'555;

	int32_t int32 = 5'555'555;
	uint32_t uint32 = 5'555'555;

	int64_t int64 = 5'555'555'555'555;
	uint64_t uint64 = 5'555'555'555'555;

	// -------------------------------------
	std::string string = "hello, binrw!";

#ifdef USE_WCHAR
	std::wstring wstring = L"hello, binrw!";
#endif

	// -------------------------------------
	bin_writer writer(packet);

	// -------------------------------------
	writer.write(c);

#ifdef USE_WCHAR
	writer.write(wc);
#endif	

	writer.write(int8);
	writer.write(uint8);

	writer.write(int16);
	writer.write(uint16);

	writer.write(int32);
	writer.write(uint32);

	writer.write(int64);
	writer.write(uint64);

	writer.write(string);

#ifdef USE_WCHAR
	writer.write(wstring);
#endif

	// -------------------------------------
	c = 0;

#ifdef USE_WCHAR
	wc = 0;
#endif

	int8 = 0;
	uint8 = 0;

	int16 = 0;
	uint16 = 0;

	int32 = 0;
	uint32 = 0;

	int64 = 0;
	uint64 = 0;

	string = "";

#ifdef USE_WCHAR
	wstring = L"";
#endif

	// -------------------------------------
	size_t carriage = 0;
	bin_reader reader(packet, carriage);

	// -------------------------------------
	c = reader.read_char();

#ifdef USE_WCHAR
	wc = reader.read_wchar();
#endif

	int8 = reader.read_int8();
	uint8 = reader.read_uint8();

	int16 = reader.read_int16();
	uint16 = reader.read_uint16();

	int32 = reader.read_int32();
	uint32 = reader.read_int32();

	int64 = reader.read_int64();
	uint64 = reader.read_uint64();

	string = reader.read_string();

#ifdef USE_WCHAR
	wstring = reader.read_wstring();
#endif

	// -------------------------------------
	return 0;
}
