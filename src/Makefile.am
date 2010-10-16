bin_PROGRAMS = odin
odin_SOURCES = main.c  odinMainMenu.c  odinNewGame.c  odinSplash.c \
			   odinDocumentation.c odinOptions.c odinMenus.c \
			   odinGameEngine.c odinAIStatic.c odinResizeHandle.c \
			   main.h  odinCommon.h  odinMainMenu.h  odinNewGame.h  odinSplash.h \
			   odinDocumentation.h odinOptions.h odinMenus.h odinGameEngine.h \
			   odinAIStatic.h odinResizeHandle.h


noinst_HEADERS = main.h  odinCommon.h  odinMainMenu.h  odinNewGame.h  odinSplash.h \
				 odinDocumentation.h odinOptions.h odinMenus.h odinGameEngine.h \
				 odinAIStatic.h odinResizeHandle.h

# AM_CFLAGS = 
odin_CFLAGS = -DDATADIR=\"$(datadir)\"  @PACKAGE_CFLAGS@
odin_LDFLAGS = @PACKAGE_LIBS@

