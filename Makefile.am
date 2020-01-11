## Process this file with automake to produce Makefile.in

ACLOCAL_AMFLAGS		= -I meta/autotools
AUTOMAKE_OPTIONS	= foreign
EXTRA_DIST		= INSTALL			\
			  meta/slackware/slack-desc.in
dist_doc_DATA		= README COPYING
AM_CFLAGS		= $(MMUX_CFLAGS)
AM_CPPFLAGS		= -I$(srcdir)/src

## --------------------------------------------------------------------

nodist_pkgconfig_DATA	= meta/scripts/mmux-emacs-template.pc


#### documentation

AM_MAKEINFOFLAGS	= --no-split
AM_MAKEINFOHTMLFLAGS	= --split=node -c WORDS_IN_PAGE=0 \
	-c PRE_BODY_CLOSE="<p>This document describes version <tt>$(PACKAGE_VERSION)</tt> of <em>$(PACKAGE_NAME)</em>.</p>"

info_TEXINFOS		= doc/mmux-emacs-template.texi
doc_mmux_emacs_template_TEXINFOS = \
	doc/macros.texi			\
	doc/overview-linking.texi	\
	doc/gpl-3.0.texi		\
	doc/fdl-1.3.texi


#### libraries

mmux_emacs_template_CURRENT		= @mmux_emacs_template_VERSION_INTERFACE_CURRENT@
mmux_emacs_template_REVISION		= @mmux_emacs_template_VERSION_INTERFACE_REVISION@
mmux_emacs_template_AGE			= @mmux_emacs_template_VERSION_INTERFACE_AGE@
mmux_emacs_template_LINKER_VERSION	= -version-info $(mmux_emacs_template_CURRENT):$(mmux_emacs_template_REVISION):$(mmux_emacs_template_AGE)

include_HEADERS		= src/mmux-emacs-template.h

lib_LTLIBRARIES		= libmmux-emacs-template.la
libmmux_emacs_template_la_CPPFLAGS	= $(AM_CPPFLAGS)
libmmux_emacs_template_la_CFLAGS	= $(AM_CFLAGS)
libmmux_emacs_template_la_LDFLAGS	= $(mmux_emacs_template_LINKER_VERSION) $(AM_LDFLAGS)
libmmux_emacs_template_la_SOURCES	= \
	src/mmux-emacs-template.h		\
	src/mmux-emacs-template-internals.h	\
	src/mmux-emacs-template-library.c


#### tests

check_PROGRAMS	= \
	tests/version

#if MMUX_TESTING_ENABLED
TESTS				= $(check_PROGRAMS)
#endif

mmux_emacs_template_tests_cppflags	= $(AM_CPPFLAGS) -I$(srcdir)/tests
mmux_emacs_template_tests_cflags	= $(AM_CFLAGS)
mmux_emacs_template_tests_ldadd		= $(AM_LDFLAGS) libmmux-emacs-template.la

## --------------------------------------------------------------------

tests_version_CPPFLAGS		= $(mmux_emacs_template_tests_cppflags)
tests_version_CFLAGS		= $(mmux_emacs_template_tests_cflags)
tests_version_LDADD		= $(mmux_emacs_template_tests_ldadd)

## --------------------------------------------------------------------

installcheck-local: $(TESTS)
	@for f in $(TESTS); do $(builddir)/$$f; done


#### common rules

include $(top_srcdir)/meta/automake/mmux-makefile-rules

### end of file
