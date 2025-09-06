#include <gst/gst.h>
#include <gst/rtsp-server/rtsp-server.h>
#include "rtsp-server.h"

void gst_rtsp_server_run(int port, const char *mount_point)
{
    GMainLoop *loop;
    GstRTSPServer *server;
    GstRTSPMountPoints *mounts;
    GstRTSPMediaFactory *factory;

    gchar *pipeline_desc;

    gst_init(NULL, NULL);

    loop = g_main_loop_new(NULL, FALSE);

    server = gst_rtsp_server_new();
    g_object_set(server, "service", g_strdup_printf("%d", port), NULL);

    mounts = gst_rtsp_server_get_mount_points(server);
    factory = gst_rtsp_media_factory_new();

    // Example pipeline : test source -> H.264 encoded -> RTP payload
    pipeline_desc = g_strdup_printf(
        "( videotestsrc ! x264enc ! rtph264pay name=pay0 pt=96 )"
    );

    gst_rtsp_media_factory_set_launch(factory, pipeline_desc);
    gst_rtsp_media_factory_set_shared(factory, TRUE);

    gst_rtsp_mount_points_add_factory(mounts, mount_point, factory);
    g_object_unref(mounts);

    gst_rtsp_server_attach(server, NULL);

    g_print("RTSP server is running at rtsp://localhost:%d%s\n", port, mount_point);
    g_main_loop_run(loop);

  
}