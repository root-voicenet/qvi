#############################################################################
# Makefile for building: qvi
# Generated by qmake (2.01a) (Qt 4.7.4) on: ?? ???. 3 23:54:31 2012
# Project:  qvi.pro
# Template: app
# Command: /usr/bin/qmake-qt4 -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug -o Makefile qvi.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib/i386-linux-gnu -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake-qt4
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mainwindow.cpp \
		qimagelabel.cpp \
		mylistview.cpp \
		loadfolderthread.cpp \
		taxonomyterm.cpp \
		pointermodel.cpp moc_mainwindow.cpp \
		moc_qimagelabel.cpp \
		moc_mylistview.cpp \
		moc_loadfolderthread.cpp \
		moc_pointermodel.cpp \
		qrc_resource.cpp
OBJECTS       = main.o \
		mainwindow.o \
		qimagelabel.o \
		mylistview.o \
		loadfolderthread.o \
		taxonomyterm.o \
		pointermodel.o \
		moc_mainwindow.o \
		moc_qimagelabel.o \
		moc_mylistview.o \
		moc_loadfolderthread.o \
		moc_pointermodel.o \
		qrc_resource.o
DIST          = /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		qvi.pro
QMAKE_TARGET  = qvi
DESTDIR       = 
TARGET        = qvi

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_mainwindow.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: qvi.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/g++.conf \
		/usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/i386-linux-gnu/libQtGui.prl \
		/usr/lib/i386-linux-gnu/libQtCore.prl
	$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug -o Makefile qvi.pro
/usr/share/qt4/mkspecs/common/g++.conf:
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/i386-linux-gnu/libQtGui.prl:
/usr/lib/i386-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -spec /usr/share/qt4/mkspecs/linux-g++ CONFIG+=debug -o Makefile qvi.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/qvi1.0.0 || $(MKDIR) .tmp/qvi1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/qvi1.0.0/ && $(COPY_FILE) --parents mainwindow.h qimagelabel.h mylistview.h loadfolderthread.h taxonomyterm.h pointermodel.h .tmp/qvi1.0.0/ && $(COPY_FILE) --parents resource.qrc .tmp/qvi1.0.0/ && $(COPY_FILE) --parents main.cpp mainwindow.cpp qimagelabel.cpp mylistview.cpp loadfolderthread.cpp taxonomyterm.cpp pointermodel.cpp .tmp/qvi1.0.0/ && $(COPY_FILE) --parents mainwindow.ui .tmp/qvi1.0.0/ && (cd `dirname .tmp/qvi1.0.0` && $(TAR) qvi1.0.0.tar qvi1.0.0 && $(COMPRESS) qvi1.0.0.tar) && $(MOVE) `dirname .tmp/qvi1.0.0`/qvi1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/qvi1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mainwindow.cpp moc_qimagelabel.cpp moc_mylistview.cpp moc_loadfolderthread.cpp moc_pointermodel.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_qimagelabel.cpp moc_mylistview.cpp moc_loadfolderthread.cpp moc_pointermodel.cpp
moc_mainwindow.cpp: loadfolderthread.h \
		pointermodel.h \
		mainwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_qimagelabel.cpp: qimagelabel.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) qimagelabel.h -o moc_qimagelabel.cpp

moc_mylistview.cpp: mylistview.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mylistview.h -o moc_mylistview.cpp

moc_loadfolderthread.cpp: loadfolderthread.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) loadfolderthread.h -o moc_loadfolderthread.cpp

moc_pointermodel.cpp: pointermodel.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) pointermodel.h -o moc_pointermodel.cpp

compiler_rcc_make_all: qrc_resource.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_resource.cpp
qrc_resource.cpp: resource.qrc \
		images/Gnome-object-rotate-right.svg \
		images/window-close.png \
		images/document-open.png \
		images/icon.png \
		images/view-fullscreen.svg \
		images/zoom-fit-best.svg \
		images/go-previous.png \
		images/go-next.png \
		images/Gnome-object-rotate-left.svg \
		images/list-add.png \
		images/folder-open.png \
		images/stock_form-listbox.png
	/usr/bin/rcc -name resource resource.qrc -o qrc_resource.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h
ui_mainwindow.h: mainwindow.ui \
		qimagelabel.h \
		mylistview.h
	/usr/bin/uic-qt4 mainwindow.ui -o ui_mainwindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_uic_clean 

####### Compile

main.o: main.cpp mainwindow.h \
		loadfolderthread.h \
		pointermodel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		loadfolderthread.h \
		pointermodel.h \
		ui_mainwindow.h \
		mylistview.h \
		qimagelabel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

qimagelabel.o: qimagelabel.cpp qimagelabel.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qimagelabel.o qimagelabel.cpp

mylistview.o: mylistview.cpp mylistview.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mylistview.o mylistview.cpp

loadfolderthread.o: loadfolderthread.cpp loadfolderthread.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o loadfolderthread.o loadfolderthread.cpp

taxonomyterm.o: taxonomyterm.cpp taxonomyterm.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o taxonomyterm.o taxonomyterm.cpp

pointermodel.o: pointermodel.cpp pointermodel.h \
		taxonomyterm.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o pointermodel.o pointermodel.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_qimagelabel.o: moc_qimagelabel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_qimagelabel.o moc_qimagelabel.cpp

moc_mylistview.o: moc_mylistview.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mylistview.o moc_mylistview.cpp

moc_loadfolderthread.o: moc_loadfolderthread.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_loadfolderthread.o moc_loadfolderthread.cpp

moc_pointermodel.o: moc_pointermodel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_pointermodel.o moc_pointermodel.cpp

qrc_resource.o: qrc_resource.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_resource.o qrc_resource.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

