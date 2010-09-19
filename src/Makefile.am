bin_PROGRAMS = odin
odin_SOURCES = main.c  odinMainMenu.c  odinNewGame.c  odinSplash.c \
			   main.h  odinCommon.h  odinMainMenu.h  odinNewGame.h  odinSplash.h

noinst_HEADERS = main.h  odinCommon.h  odinMainMenu.h  odinNewGame.h  odinSplash.h

# AM_CFLAGS = 
odin_CFLAGS = -DDATADIR=\"$(datadir)\"  @PACKAGE_CFLAGS@
odin_LDFLAGS = @PACKAGE_LIBS@

