## Makefile.am for korrent

# this has all of the subdirectories that make will recurse into.  if
# there are none, comment this out
SUBDIRS = . pics

# this is the program that gets installed.  it's name is used for all
# of the other Makefile.am variables
bin_PROGRAMS = korrent korrent_client

# set the include path for X, qt and KDE
INCLUDES         = $(all_includes)

# the library search path. 
korrent_LDFLAGS = $(KDE_RPATH) $(all_libraries)

# the libraries to link against.
korrent_LDADD   = $(LIB_KFILE) -lkdeprint

# which sources should be compiled for korrent
korrent_SOURCES =	main.cpp korrent.cpp korrentview.cpp \
					korrentpref.cpp korrentiface.skel

# these are the headers for your project
noinst_HEADERS   = korrent.h korrentview.h korrentpref.h

# client stuff
korrent_client_LDFLAGS = $(KDE_RPATH) $(all_libraries)
korrent_client_LDADD   = $(LIB_KDECORE)
korrent_client_SOURCES = korrent_client.cpp

# let automoc handle all of the meta source files (moc)
METASOURCES = AUTO

messages: rc.cpp
	$(XGETTEXT) *.cpp -o $(podir)/korrent.pot

KDE_ICON = korrent

# this is where the kdelnk file will go 
xdg_apps_data = korrent.desktop

# this is where the XML-GUI resource file goes
rcdir = $(kde_datadir)/korrent
rc_DATA = korrentui.rc
