#!/bin/bash

# Directory containing video4linux devices
V4L_DIR="/sys/devices/platform"

# Tracing of V4L2 userland API

# Find all dev_debug files under the video4linux directory
find "$V4L_DIR" -type f -name "dev_debug" | while read -r dev_debug_file; do
    # Enable debug mode by writing 1 to the dev_debug file
    echo 0x3 |  tee "$dev_debug_file" > /dev/null
    echo "Enabled debug mode for $dev_debug_file"
done

# Tracing of the V4L2 core framework
echo 0x3 > /sys/module/videobuf2_common/parameters/debug
echo 0x3 > /sys/module/videobuf2_v4l2/parameters/debug
