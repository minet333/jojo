#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>

#include <libdill.h>

#define ATTACKERS_COUNT 100
#define TOTAL_DEADLINE (now() + 1000 * 60 * 24 * 3)

void generate_pair(const char **login, const char **password);
coroutine void run_attacker();

int main() {
	int all = bundle();
	assert(all != -1);

	for (size_t i = 0; i < ATTACKERS_COUNT; i++) {
		assert(bundle_go(all, run_attacker()) != -1);
	}

	assert(bundle_wait(all, now() + TOTAL_DEADLINE) != -1);
        return EXIT_SUCCESS;
}

coroutine void run_attacker() {
	
}


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
