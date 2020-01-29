## Process this file with automake to produce Makefile.in

ACLOCAL_AMFLAGS		= -I meta/autotools
AUTOMAKE_OPTIONS	= foreign
EXTRA_DIST		= INSTALL			\
			  meta/slackware/slack-desc.in
dist_doc_DATA		= README COPYING
AM_CFLAGS		= $(MMUX_CFLAGS)
AM_CPPFLAGS		= -I$(srcdir)/src
CLEANFILES		=

## --------------------------------------------------------------------

nodist_pkgconfig_DATA	= meta/scripts/mmux-emacs-template.pc


#### documentation

EXTRA_DIST		+= doc/mmux-emacs-template.style.css
CLEANFILES		+= doc/mmux-emacs-template.css

AM_MAKEINFOFLAGS	= --no-split
AM_MAKEINFOHTMLFLAGS	= --split=node -c WORDS_IN_PAGE=0 --css-ref=mmux-emacs-gmp.css \
	-c PRE_BODY_CLOSE="<p>This document describes version <tt>$(PACKAGE_VERSION)</tt> of <em>$(PACKAGE_NAME)</em>.</p>"

info_TEXINFOS		= doc/mmux-emacs-template.texi
doc_mmux_emacs_template_TEXINFOS = \
	doc/macros.texi			\
	doc/elisp-macros.texi		\
	doc/overview-linking.texi	\
	doc/gpl-3.0.texi		\
	doc/fdl-1.3.texi

## --------------------------------------------------------------------

doc/mmux-emacs-template.html/$(am__dirstamp): doc/$(am__dirstamp)
	@$(MKDIR_P) doc/mmux-emacs-template.html/
	@: > doc/mmux-emacs-template.html/$(am__dirstamp)

doc/mmux-emacs-template.html/mmux-emacs-template.css: doc/mmux-emacs-template.style.css doc/mmux-emacs-template.html/$(am__dirstamp)
	$(INSTALL) -m 0444 "$(top_srcdir)/doc/mmux-emacs-template.style.css" "$(builddir)/doc/mmux-emacs-template.html/mmux-emacs-template.css"

## --------------------------------------------------------------------

html-local: doc/mmux-emacs-template.html/mmux-emacs-template.css

install-html-local:
	$(MKDIR_P) "$(DESTDIR)$(htmldir)/mmux-emacs-template.html/"
	$(INSTALL) -m 0444 $(builddir)/doc/mmux-emacs-template.html/mmux-emacs-template.css "$(DESTDIR)$(htmldir)/mmux-emacs-template.html/"


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
	src/mmux-emacs-template.h			\
	src/mmux-emacs-internals.h			\
	src/mmux-emacs-template-internals.h		\
	src/mmux-emacs-template-library.c		\
	src/mmux-emacs-template-builtin-objects.c	\
	src/mmux-emacs-template-user-pointer-objects.c


#### Emacs code

# This  variable is  reserved to  the  package author.   Users of  the
# package can set ELCFLAGS.
AM_ELCFLAGS	= --quick --directory $(builddir)/src --directory $(PWD)/.libs

dist_lisp_LISP	= src/mmux-emacs-template.el

src/mmux-emacs-template.elc: libmmux-emacs-template.la


#### tests

MMUX_EMACS_TEMPLATE_TESTS_SRC = \
	tests/version.el		\
	tests/builtin-objects-use.el	\
	tests/user-pointer-objects.el

MMUX_EMACS_TEMPLATE_TESTS = \
	tests/version.elc		\
	tests/builtin-objects-use.elc	\
	tests/user-pointer-objects.elc

EXTRA_DIST	+= $(MMUX_EMACS_TEMPLATE_TESTS_SRC)
TESTS		 = $(MMUX_EMACS_TEMPLATE_TESTS)

MMUX_EMACS_CHECK_FLAGS	= --batch --quick --directory $(builddir)/.libs --directory $(builddir)/src $(ELCFLAGS) --load

# We must make sure that this ends with a semicolon!!!
AM_TESTS_ENVIRONMENT	=
TEST_EXTENSIONS		= .elc
ELC_LOG_COMPILER	= $(EMACS)
AM_ELC_LOG_FLAGS	= $(MMUX_EMACS_CHECK_FLAGS)
CLEANFILES		+= $(MMUX_EMACS_TEMPLATE_TESTS)

## --------------------------------------------------------------------

MMUX_EMACS_INSTALLCHECK	= $(EMACS) --batch --quick --directory $(libdir) --directory $(lispdir) --load

installcheck-local:
	@for f in $(MMUX_EMACS_GMP_TESTS_SRC); do $(MMUX_EMACS_INSTALLCHECK) $(srcdir)/$$f; done

## --------------------------------------------------------------------

MMUX_EMACS_TEMPLATE_TEST_SELECTED_TESTS	= $(srcdir)/tests/*$(file)*.el
MMUX_EMACS_TEMPLATE_TEST_RUNTESTS	= $(EMACS) $(MMUX_EMACS_CHECK_FLAGS)

test:
	for f in $(MMUX_EMACS_TEMPLATE_TEST_SELECTED_TESTS) ; do $(MMUX_EMACS_TEMPLATE_TEST_RUNTESTS) $$f; done


#### common rules

include $(top_srcdir)/meta/automake/mmux-makefile-rules

### end of file
