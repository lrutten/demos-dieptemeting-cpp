#############################################################################
# Makefile for building: dieptemeting
# Generated by qmake (2.01a) (Qt 4.8.2) on: Mon Dec 15 15:58:27 2014
# Project:  dieptemeting.pro
# Template: app
# Command: /usr/bin/qmake -o Makefile dieptemeting.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/lib64/qt/mkspecs/linux-g++-64 -I. -I/usr/lib64/qt/include/QtCore -I/usr/lib64/qt/include/QtGui -I/usr/lib64/qt/include -I. -Ilijn -Ilistsel -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1 -Wl,-rpath,/usr/lib64/qt/lib
LIBS          = $(SUBLIBS)  -L/usr/lib64/qt/lib -lQtGui -L/usr/lib64/qt/lib -L/usr/X11R6/lib64 -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
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

SOURCES       = dieptemeting.cpp \
		driehoek.cpp \
		meting.cpp \
		punt.cpp \
		strook.cpp \
		vaart.cpp 
OBJECTS       = dieptemeting.o \
		driehoek.o \
		meting.o \
		punt.o \
		strook.o \
		vaart.o
DIST          = /usr/lib64/qt/mkspecs/common/unix.conf \
		/usr/lib64/qt/mkspecs/common/linux.conf \
		/usr/lib64/qt/mkspecs/common/gcc-base.conf \
		/usr/lib64/qt/mkspecs/common/gcc-base-unix.conf \
		/usr/lib64/qt/mkspecs/common/g++-base.conf \
		/usr/lib64/qt/mkspecs/common/g++-unix.conf \
		/usr/lib64/qt/mkspecs/qconfig.pri \
		/usr/lib64/qt/mkspecs/modules/qt_phonon.pri \
		/usr/lib64/qt/mkspecs/modules/qt_webkit_version.pri \
		/usr/lib64/qt/mkspecs/features/qt_functions.prf \
		/usr/lib64/qt/mkspecs/features/qt_config.prf \
		/usr/lib64/qt/mkspecs/features/exclusive_builds.prf \
		/usr/lib64/qt/mkspecs/features/default_pre.prf \
		/usr/lib64/qt/mkspecs/features/release.prf \
		/usr/lib64/qt/mkspecs/features/default_post.prf \
		/usr/lib64/qt/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/lib64/qt/mkspecs/features/warn_on.prf \
		/usr/lib64/qt/mkspecs/features/qt.prf \
		/usr/lib64/qt/mkspecs/features/unix/thread.prf \
		/usr/lib64/qt/mkspecs/features/moc.prf \
		/usr/lib64/qt/mkspecs/features/resources.prf \
		/usr/lib64/qt/mkspecs/features/uic.prf \
		/usr/lib64/qt/mkspecs/features/yacc.prf \
		/usr/lib64/qt/mkspecs/features/lex.prf \
		/usr/lib64/qt/mkspecs/features/include_source_dir.prf \
		dieptemeting.pro
QMAKE_TARGET  = dieptemeting
DESTDIR       = 
TARGET        = dieptemeting

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

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: dieptemeting.pro  /usr/lib64/qt/mkspecs/linux-g++-64/qmake.conf /usr/lib64/qt/mkspecs/common/unix.conf \
		/usr/lib64/qt/mkspecs/common/linux.conf \
		/usr/lib64/qt/mkspecs/common/gcc-base.conf \
		/usr/lib64/qt/mkspecs/common/gcc-base-unix.conf \
		/usr/lib64/qt/mkspecs/common/g++-base.conf \
		/usr/lib64/qt/mkspecs/common/g++-unix.conf \
		/usr/lib64/qt/mkspecs/qconfig.pri \
		/usr/lib64/qt/mkspecs/modules/qt_phonon.pri \
		/usr/lib64/qt/mkspecs/modules/qt_webkit_version.pri \
		/usr/lib64/qt/mkspecs/features/qt_functions.prf \
		/usr/lib64/qt/mkspecs/features/qt_config.prf \
		/usr/lib64/qt/mkspecs/features/exclusive_builds.prf \
		/usr/lib64/qt/mkspecs/features/default_pre.prf \
		/usr/lib64/qt/mkspecs/features/release.prf \
		/usr/lib64/qt/mkspecs/features/default_post.prf \
		/usr/lib64/qt/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/lib64/qt/mkspecs/features/warn_on.prf \
		/usr/lib64/qt/mkspecs/features/qt.prf \
		/usr/lib64/qt/mkspecs/features/unix/thread.prf \
		/usr/lib64/qt/mkspecs/features/moc.prf \
		/usr/lib64/qt/mkspecs/features/resources.prf \
		/usr/lib64/qt/mkspecs/features/uic.prf \
		/usr/lib64/qt/mkspecs/features/yacc.prf \
		/usr/lib64/qt/mkspecs/features/lex.prf \
		/usr/lib64/qt/mkspecs/features/include_source_dir.prf \
		/usr/lib64/qt/lib/libQtGui.prl \
		/usr/lib64/qt/lib/libQtCore.prl
	$(QMAKE) -o Makefile dieptemeting.pro
/usr/lib64/qt/mkspecs/common/unix.conf:
/usr/lib64/qt/mkspecs/common/linux.conf:
/usr/lib64/qt/mkspecs/common/gcc-base.conf:
/usr/lib64/qt/mkspecs/common/gcc-base-unix.conf:
/usr/lib64/qt/mkspecs/common/g++-base.conf:
/usr/lib64/qt/mkspecs/common/g++-unix.conf:
/usr/lib64/qt/mkspecs/qconfig.pri:
/usr/lib64/qt/mkspecs/modules/qt_phonon.pri:
/usr/lib64/qt/mkspecs/modules/qt_webkit_version.pri:
/usr/lib64/qt/mkspecs/features/qt_functions.prf:
/usr/lib64/qt/mkspecs/features/qt_config.prf:
/usr/lib64/qt/mkspecs/features/exclusive_builds.prf:
/usr/lib64/qt/mkspecs/features/default_pre.prf:
/usr/lib64/qt/mkspecs/features/release.prf:
/usr/lib64/qt/mkspecs/features/default_post.prf:
/usr/lib64/qt/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/lib64/qt/mkspecs/features/warn_on.prf:
/usr/lib64/qt/mkspecs/features/qt.prf:
/usr/lib64/qt/mkspecs/features/unix/thread.prf:
/usr/lib64/qt/mkspecs/features/moc.prf:
/usr/lib64/qt/mkspecs/features/resources.prf:
/usr/lib64/qt/mkspecs/features/uic.prf:
/usr/lib64/qt/mkspecs/features/yacc.prf:
/usr/lib64/qt/mkspecs/features/lex.prf:
/usr/lib64/qt/mkspecs/features/include_source_dir.prf:
/usr/lib64/qt/lib/libQtGui.prl:
/usr/lib64/qt/lib/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile dieptemeting.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/dieptemeting1.0.0 || $(MKDIR) .tmp/dieptemeting1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/dieptemeting1.0.0/ && $(COPY_FILE) --parents driehoek.h insprong.h meting.h punt.h strook.h vaart.h .tmp/dieptemeting1.0.0/ && $(COPY_FILE) --parents dieptemeting.cpp driehoek.cpp meting.cpp punt.cpp strook.cpp vaart.cpp .tmp/dieptemeting1.0.0/ && (cd `dirname .tmp/dieptemeting1.0.0` && $(TAR) dieptemeting1.0.0.tar dieptemeting1.0.0 && $(COMPRESS) dieptemeting1.0.0.tar) && $(MOVE) `dirname .tmp/dieptemeting1.0.0`/dieptemeting1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/dieptemeting1.0.0


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

compiler_moc_header_make_all:
compiler_moc_header_clean:
compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: 

####### Compile

dieptemeting.o: dieptemeting.cpp vaart.h \
		meting.h \
		punt.h \
		strook.h \
		driehoek.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dieptemeting.o dieptemeting.cpp

driehoek.o: driehoek.cpp driehoek.h \
		punt.h \
		insprong.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o driehoek.o driehoek.cpp

meting.o: meting.cpp meting.h \
		punt.h \
		insprong.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o meting.o meting.cpp

punt.o: punt.cpp punt.h \
		insprong.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o punt.o punt.cpp

strook.o: strook.cpp strook.h \
		driehoek.h \
		punt.h \
		insprong.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o strook.o strook.cpp

vaart.o: vaart.cpp vaart.h \
		meting.h \
		punt.h \
		strook.h \
		driehoek.h \
		insprong.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o vaart.o vaart.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

