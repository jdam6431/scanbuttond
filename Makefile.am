ACLOCAL_AMFLAGS=-Im4

SUBDIRS = contrib interface backends scripts .

pkgsysconfdir = $(sysconfdir)/$(PACKAGE)
 	
AM_CPPFLAGS = $(all_includes) -I$(top_builddir)/include -I.

bin_PROGRAMS = scanbuttond
scanbuttond_SOURCES = scanbuttond.c lib/loader.c include/scanbuttond/backend.h include/scanbuttond/scanbuttond.h include/scanbuttond/common.h
scanbuttond_LDADD = @LIBDL@
