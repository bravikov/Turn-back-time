/* This program turns back time.
 * Build (for Linux):
 *     gcc -std=c99 -o turn_back_time turn_back_time.c
 * or (for Windows):
 *     i686-w64-mingw32-gcc -std='c99' -static -o turn_back_time.exe turn_back_time.c
 * */

#include <time.h>

int main() {
    const int c = 3;
    struct timespec delay;
    delay.tv_sec = 0;
    delay.tv_nsec = 1e9/c;

    while(1) {
        struct timespec tp;
        clock_gettime(CLOCK_REALTIME, &tp);
        tp.tv_sec--;
        tp.tv_nsec = 0;
        for(int i = 0; i < c; i++) {
            clock_settime(CLOCK_REALTIME, &tp);
            nanosleep(&delay, NULL);
        }
    }
}
