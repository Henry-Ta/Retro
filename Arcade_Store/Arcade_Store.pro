TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        about.cpp \
        main.cpp \
        menu.cpp \
        state.cpp \
        state_manager.cpp \
        user_profile.cpp

HEADERS += \
    about.h \
    menu.h \
    state.h \
    state_manager.h \
    user_profile.h
