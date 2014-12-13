#!/bin/bash

PACKAGE=com.luckky.demo.coolphysics2d
PROJ_NAME=CoolPhysics2DDemo

echo Uninstalling $PACKAGE...
adb uninstall $PACKAGE
echo Reinstalling $PACKAGE...
adb install bin/$PROJ_NAME-debug.apk