QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH+= C:\OpenCV\opencv\release\install\include

LIBS+=C:\OpenCV\opencv\release\bin\libopencv_core455.dll
LIBS+=C:\OpenCV\opencv\release\bin\libopencv_highgui455.dll
LIBS+=C:\OpenCV\opencv\release\bin\libopencv_imgcodecs455.dll
LIBS+=C:\OpenCV\opencv\release\bin\libopencv_imgproc455.dll
LIBS+=C:\OpenCV\opencv\release\bin\libopencv_calib3d455.dll
LIBS+=C:\OpenCV\opencv\release\bin\libopencv_videoio455.dll
LIBS+=C:\OpenCV\opencv\release\bin\libopencv_features2d455.dll
LIBS+=C:\OpenCV\opencv\release\bin\libopencv_flann455.dll

SOURCES += \
        main.cpp


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
