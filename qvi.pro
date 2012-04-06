# -------------------------------------------------
# Project created by QtCreator 2009-05-06T22:18:57
# -------------------------------------------------
TARGET = qvi
TEMPLATE = app
INCLUDEPATH += "qxmlrpc"
SOURCES += main.cpp \
    mainwindow.cpp \
    qimagelabel.cpp \
    mylistview.cpp \
    loadfolderthread.cpp \
    taxonomyterm.cpp \
    pointermodel.cpp \
    PhotoData.cpp \
    connector.cpp \
    qxmlrpc/xmlrpc/variant.cpp \
    qxmlrpc/xmlrpc/serverintrospection.cpp \
    qxmlrpc/xmlrpc/server.cpp \
    qxmlrpc/xmlrpc/response.cpp \
    qxmlrpc/xmlrpc/request.cpp \
    qxmlrpc/xmlrpc/client.cpp \
    logindialog.cpp
HEADERS += mainwindow.h \
    qimagelabel.h \
    mylistview.h \
    loadfolderthread.h \
    taxonomyterm.h \
    pointermodel.h \
    PhotoData.h \
    connector.h \
    qxmlrpc/xmlrpc/variant.h \
    qxmlrpc/xmlrpc/stable.h \
    qxmlrpc/xmlrpc/serverintrospection.h \
    qxmlrpc/xmlrpc/server_private.h \
    qxmlrpc/xmlrpc/server.h \
    qxmlrpc/xmlrpc/response.h \
    qxmlrpc/xmlrpc/request.h \
    qxmlrpc/xmlrpc/qxmlrpc_documentation.h \
    qxmlrpc/xmlrpc/client.h \
    logindialog.h
FORMS += mainwindow.ui \
    logindialog.ui
RESOURCES += resource.qrc
DEFINES += XMLRPC_DEBUG
QT += core gui network xml
