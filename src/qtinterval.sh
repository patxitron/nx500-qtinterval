#!/bin/sh

# Matches the default font size (relative to window size) to be the same as
# when running in the development desktop.
export QT_FONT_DPI=100
./qtinterval -platform xcb
