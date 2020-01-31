#include <cstdio>
#include <iterator>


using namespace std;

void read_from(char s[]) {
	for (size_t i = 0; i < s[i]; i++) {
		printf("%c", s[i]);
	}
	printf("\n");
}

void write_to(char c, int z, char s[]) {
	char ch = c;
	size_t size = sizeof(s) / sizeof(char);
	if (z > size) {
		printf("Buffer overflow\n");
			return;
	}
	for (int i = 0; i < s[i]; i++) {
		if (i == z) {
			s[i] = ch;
		}
	}
}
int main() {
	char lower[] = "abc?e";
	char upper[] = "ABC?E";
	char* upper_ptr = upper;

	lower[3] = 'd';
	upper_ptr[3] = 'D';

	char letter_d = lower[3];
	char letter_D = upper_ptr[3];

	printf("lower: %s\nupper: %s\n", lower, upper);

	read_from(lower);
	write_to('z', 5, lower);
	read_from(lower);
	write_to('z', 4, lower);
	read_from(lower);

	write_to('$', 0, upper);
	read_from(upper);

}