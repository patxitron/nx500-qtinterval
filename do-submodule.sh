#!/bin/sh
THIS_DIR="$(dirname "$(readlink -f "${0}")")"
if [ -d "${THIS_DIR}/${1}" ]; then
    cd "${THIS_DIR}/${1}"
    case "${1}" in
    buildroot-2021.02.5)
        if ! [ -f Makefile ]; then
            git submodule init
            git submodule update
        fi
        cp -f ../buildroot-2021.02.5.config .config
        cp -f ../0001-libxkbcommon-static-and-shared.patch package/libxkbcommon/
        cp -f ../0001-xdo-build-and-install-static-library.patch package/xdotool/
        make oldconfig
        make
        # I can't guess a better method to get the libxdo library installed in the build environment.
        cp -f output/build/xdotool-3.20160805.1/libxdo.a output/host/arm-buildroot-linux-musleabi/sysroot/usr/lib/
        cp -f output/build/xdotool-3.20160805.1/xdo.h output/host/arm-buildroot-linux-musleabi/sysroot/usr/include/
        ;;
    *)
        echo "Unknown submodule"
        ;;
    esac
fi
