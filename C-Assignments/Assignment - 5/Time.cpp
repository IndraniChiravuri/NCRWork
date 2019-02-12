#include <cstdio>
#include <cstdlib>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

int main() {
    struct Time t1;
    printf("Enter Time(hr:mi:se): ");
    scanf("%d:%d:%d", &t1.hours, &t1.minutes, &t1.seconds);
    printf("Time: %d:%d:%d\n", t1.hours, t1.minutes, t1.seconds);
	return 0;
}