#include <stdio.h>

int main(int argc, char const *argv[])
{
	FILE* fd = fopen(argv[1], "r");
	char buf[1000];
	fread(buf, 1, 1000, fd);

	if (buf[10] - buf[14] > 0) {
		if (buf[12] > buf[25]) {
			if (buf[0] == buf[23]) {
				buf[2000] = 0;
			}
		}
	}
	return 0;
}