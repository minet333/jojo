#include <stdio.h>
#include <stdlib.h>

void generate_pair(const char **login, const char **password) {
	static const char *logins[] = {
		"abcdef",
		"bcdefg",
		"cdefgh",
		"defghi",
		"efghij",
		"fghijk",
		"ghijkl",
		"hijklm",
		"ijklmn",
		"jklmno", //  #10
		"klmnop",
		"lmnopq",
		"mnopqr",
		"nopqrs",
		"opqrst",
		"pqrstu",
		"qrstuv",
		"rstuvw",
		"stuvwx",
		"tuvwxy", // #20
		"uvwxyz",
		"123456",
		"234567",
		"345678",
		"456789",
		"567890",
		"jabsnf",
		"fhgbds",
		"eucosd",
		"docnel", // #30
		"reghoe",
		"cnslfi",
		"wufcyc",
		"wjkfdh",
		"3ifhbv",
		"ociden",
		"oeifhr",
		"wivund",
		"wicufd",
		"olxmdh", // #40
		"cnbdkd",
		"vcuenh",
		"cnskfd",
		"cieuyr",
		"cuendd",
		"fdiebf",
		"ciewyh",
		"zbxlss",
		"qycndd",
		"pqoxmd", // #50
		"xndkdf",
		"eocnen",
		"cnbsal",
		"iocuen",
		"soxmei",
		"cxuenb",
		"xijmwd",
		"xieyfn",
		"qpxcdn",
		"qpdicm", // #60
		"xbnfhd",
		"egtjej",
		"jvcbdn",
		"cuenxx",
		"apslcn",
		"xnedhf",
		"xuwens",
		"xiwmdn",
		"wucndd",
		"nvbxms"  // #70
	};

	*login = logins[rand() % sizeof(logins) / sizeof(logins[0])];
	*password = "njwofghunwrjdsh397345";
}

int main() {
	return EXIT_SUCCESS;
}
