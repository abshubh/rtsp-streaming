CC = gcc
CFLAGS = -Wall -g `pkg-config --cflags gstreamer-1.0 gstreamer-rtsp-server-1.0`
LIBS = `pkg-config --libs gstreamer-1.0 gstreamer-rtsp-server-1.0`

SRC = src/rtsp-server.c main.c
OBJ = $(SRC:.c=.o)
TARGET = gst-rtsp-server

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)
