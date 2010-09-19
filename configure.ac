dnl Written on Sun 19 Sep 2010
dnl Copyright 2010 Ankur Sinha , GPLv3
dnl Configure script for odin

AC_INIT([odin],[0.0.1],[sanjay.ankur@gmail.com])
AM_INIT_AUTOMAKE([-W -Wall -Werror dist-bzip2 dist-zip check-news])    

ODIN_MAJOR_VERSION=0
ODIN_MINOR_VERSION=0
ODIN_MICRO_VERSION=1

ODIN_VERSION=$ODIN_MAJOR_VERSION.$ODIN_MINOR_VERSION.$ODIN_MICRO_VERSION

VERSION=$ODIN_VERSION
PACKAGE=odin

AC_CONFIG_SRCDIR([src/main.c])    

AM_MAINTAINER_MODE    
AC_PROG_CC
AC_PROG_INSTALL
AM_PROG_CC_C_O

PKG_CHECK_MODULES(PACKAGE, ncurses)
AC_SUBST(PACKAGE_CFLAGS)    
AC_SUBST(PACKAGE_LIBS)    

AC_CONFIG_FILES([Makefile src/Makefile])    
AC_OUTPUT
    
    
