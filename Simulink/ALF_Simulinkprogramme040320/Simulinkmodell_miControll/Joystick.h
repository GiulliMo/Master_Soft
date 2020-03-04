#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/joystick.h>
#include <time.h>


#define JOY_DEV "/dev/input/js0"

int joystick_init();

void nonBlocking(int joy_fd);

void joystick_read(int joy_fd, struct js_event js, int sizeEvent, char *button, int *axis);
