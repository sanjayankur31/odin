bin_PROGRAMS = odin
odin_SOURCES = main.c  odinMainMenu.c  odinNewGame.c  odinSplash.c \
			   odinDocumentation.c odinOptions.c odinMenus.c \
			   main.h  odinCommon.h  odinMainMenu.h  odinNewGame.h  odinSplash.h \
			   odinDocumentation.h odinOptions.h odinMenus.h


noinst_HEADERS = main.h  odinCommon.h  odinMainMenu.h  odinNewGame.h  odinSplash.h \
				 odinDocumentation.h odinOptions.h odinMenus.h

# AM_CFLAGS = 
odin_CFLAGS = -DDATADIR=\"$(datadir)\"  @PACKAGE_CFLAGS@
odin_LDFLAGS = @PACKAGE_LIBS@

