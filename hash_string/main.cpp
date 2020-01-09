#include <stdio.h>

unsigned int SDBMHash(char *str);
unsigned int RSHash(char *str);
unsigned int JSHash(char *str);
unsigned int PJWHash(char *str);
unsigned int ELFHash(char *str);
unsigned int BKDRHash(char *str);
unsigned int DJBHash(char *str);
unsigned int APHash(char *str);


// Peter K.Pearson
static int T[] =
{
  1, 87, 49, 12, 176, 178, 102, 166, 121, 193, 6, 84, 249, 230, 44, 163,
  14, 197, 213, 181, 161, 85, 218, 80, 64, 239, 24, 226, 236, 142, 38, 200,
  110, 177, 104, 103, 141, 253, 255, 50, 77, 101, 81, 18, 45, 96, 31, 222,
  25, 107, 190, 70, 86, 237, 240, 34, 72, 242, 20, 214, 244, 227, 149, 235,
  97, 234, 57, 22, 60, 250, 82, 175, 208, 5, 127, 199, 111, 62, 135, 248,
  174, 169, 211, 58, 66, 154, 106, 195, 245, 171, 17, 187, 182, 179, 0, 243,
  132, 56, 148, 75, 128, 133, 158, 100, 130, 126, 91, 13, 153, 246, 216, 219,
  119, 68, 223, 78, 83, 88, 201, 99, 122, 11, 92, 32, 136, 114, 52, 10,
  138, 30, 48, 183, 156, 35, 61, 26, 143, 74, 251, 94, 129, 162, 63, 152,
  170, 7, 115, 167, 241, 206, 3, 150, 55, 59, 151, 220, 90, 53, 23, 131,
  125, 173, 15, 238, 79, 95, 89, 16, 105, 137, 225, 224, 217, 160, 37, 123,
  118, 73, 2, 157, 46, 116, 9, 145, 134, 228, 207, 212, 202, 215, 69, 229,
  27, 188, 67, 124, 168, 252, 42, 4, 29, 108, 21, 247, 19, 205, 39, 203,
  233, 40, 186, 147, 198, 192, 155, 33, 164, 191, 98, 204, 165, 180, 117, 76,
  140, 36, 210, 172, 41, 54, 159, 8, 185, 232, 113, 196, 231, 47, 146, 120,
  51, 65, 28, 144, 254, 221, 93, 189, 194, 139, 112, 43, 71, 109, 184, 209,
};

// s是需要进行索引的字符串指针，maxn是字符串可能的最大长度，返回值是相对地址。
int whashstr(char *s, int maxn)
{
	register unsigned char oh, h;
	register unsigned char *p;
	register int i;

	if (!*s)
		return 0;
	p = (unsigned char *)s;
	oh = T[*p]; h = (*(p++) + 1) & 0xff;
	for (i = maxn - 1; *p && --i >= 0; )
	{
		oh = T[oh ^ *p]; h = T[h ^ *(p++)];
	}
	return (oh << 8) + h;
}

char *command[] =
{
"SYST:PRE",
"SYST:ERR?",
"DATA?",
"MEAS?",
"SYST:RNUM:RES",
"FUNC \"VOLT:DC\"",
"VOLT:DC::DIG ",
"VOLT:DC:RANG:UPP ",
"FUNC \"CURR\"",
"CURR:DC:RANG:UPP ",
"FUNC \"RES\"",
"SYST:ZCH ON",
"RES:VSC AUTO",
"RES:RANG:AUTO ON",
"RES:MAN:VSO:OPER ON",
"SYST:ZCH OFF",
"FUNC \"RES\"",
"SYST:ZCH ON",
"RES:VSC AUTO ",
"RES:RANG:AUTO ON",
"RES:MAN:VSO:OPER ON",
"SYST:ZCH OFF",
"RES:RANG:UPP 1E12",
"FUNC \"CHAR\"",
"CHAR:RANG:UPP 1E-9",
"SOUR:VOLT 20",
"SYST:ZCH ON",
"SYST:ZCOR:ACQ",
"SYST:ZCH OFF",
"SYST:ZCOR ON",
"FORM:ELEM?"
};

int main()
{
	char *str = "hello";
	

	printf("SDBMHash = %d \n", SDBMHash(str));
	printf("RSHash = %d \n", RSHash(str));
	printf("JSHash = %d \n", JSHash(str));
	printf("PJWHash = %d \n", PJWHash(str));
	printf("ELFHash = %d \n", ELFHash(str));
	printf("BKDRHash = %d \n", BKDRHash(str));
	printf("DJBHash = %d \n", DJBHash(str));
	printf("APHash = %d \n", APHash(str));
	printf("\n");
	printf("whashstr = %d \n", whashstr(str,6));

	//printf(" %d \n", sizeof(command)/sizeof(int));
	for (int i = 0; i < sizeof(command) / sizeof(int); i++)
	{
		printf("command %d = %d \n", i, whashstr(command[i], 9));
	}
	return 0;
}