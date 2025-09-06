#include "src/rtsp-server.h"

int main(int argc, char *argv[])
{
    int port = 8554; // Default RTSP port
    const char *mount_point = "/test"; // Default mount point

    if(argc > 1) {
        port = atoi(argv[1]);
    }
    if(argc > 2) {
        mount_point = argv[2];
    }

    gst_rtsp_server_run(port, mount_point);

    return 0;

}