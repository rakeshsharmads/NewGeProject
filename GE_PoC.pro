QT += charts qml quick

SOURCES += \
    main.cpp \
    Backend_ChartsData.cpp

RESOURCES += \
    resources.qrc

DISTFILES += \
    qml/qmlaxes/* \
    qml/qmlaxes/styling.xml \
    qml/qmlaxes/Numerics.qml \
    qml/qmlaxes/Rect.qml \
    qml/qmlaxes/RectGroup.qml

target.path = $$[QT_INSTALL_EXAMPLES]/
INSTALLS += target

HEADERS += \
    Backend_NumericsData.h \
    Backend_ChartsData.h \
    data.h
