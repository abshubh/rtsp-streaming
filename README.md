# GStreamer RTSP Streaming Server

This project demonstrates how to build a simple **RTSP video streaming server** in C using [GStreamer](https://gstreamer.freedesktop.org/) and the [gst-rtsp-server](https://gstreamer.freedesktop.org/documentation/rtsp/index.html) library.

## 📌 Features
- Streams video over RTSP using GStreamer.
- Default pipeline uses `videotestsrc` (a test video pattern).
- Compatible with VLC, FFplay, or any RTSP client.

---

## 🛠️ Setup

Install required packages (Ubuntu/Debian):

```bash
sudo apt update
sudo apt install build-essential \
    libgstreamer1.0-dev \
    libgstrtspserver-1.0-dev \
    pkg-config
