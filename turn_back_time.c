/* This program turns back time.
 * Build (Linux):
 *     gcc -o turn_back_time turn_back_time.c
 * or (Windows):
 *     i686-w64-mingw32-gcc -o turn_back_time.exe turn_back_time.c
 * */

#include <time.h>

int main() {    
    struct timespec delay;
    delay.tv_sec = 0;
    delay.tv_nsec = 0.9e9;

    while(1) {
        struct timespec tp;
        clock_gettime(CLOCK_REALTIME, &tp);
        nanosleep(&delay, NULL);
        tp.tv_sec--;
        clock_settime(CLOCK_REALTIME, &tp);
    }
}
