#include <stdio.h>
#include <string.h>
#include <unistd.h>    		// write-Funktionen
#include <fcntl.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <linux/can.h>
#include <linux/can/raw.h>


/*int open_port(const char *port);

void CAN_init(int Port);
    
int send_port(struct can_frame *frame);

void read_port(struct can_frame *frame);

int close_port();*/
