/*
  Part of: MMUX Emacs Template
  Contents: public header file
  Date: Jan 11, 2020

  Abstract

	This is the public  header file of the library, defining  the public API.  It
	must be included in all the code that uses the library.

  Copyright (C) 2020 Marco Maggi <mrc.mgg@gmail.com>

  This program is free  software: you can redistribute it and/or  modify it under the
  terms  of  the  GNU General  Public  License  as  published  by the  Free  Software
  Foundation, either version 3 of the License, or (at your option) any later version.

  This program  is distributed in the  hope that it  will be useful, but  WITHOUT ANY
  WARRANTY; without  even the implied  warranty of  MERCHANTABILITY or FITNESS  FOR A
  PARTICULAR PURPOSE.  See the GNU General Public License for more details.

  You should have received  a copy of the GNU General Public  License along with this
  program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MMUX_EMACS_TEMPLATE_H
#define MMUX_EMACS_TEMPLATE_H 1


/** --------------------------------------------------------------------
 ** Preliminary definitions.
 ** ----------------------------------------------------------------- */

#ifdef __cplusplus
extern "C" {
#endif

/* The macro CCT_UNUSED indicates that a  function, function argument or variable may
   potentially be unused. Usage examples:

   static int unused_function (char arg) CCT_UNUSED;
   int foo (char unused_argument CCT_UNUSED);
   int unused_variable CCT_UNUSED;
*/
#ifdef __GNUC__
#  define CCT_UNUSED		__attribute__((__unused__))
#else
#  define CCT_UNUSED		/* empty */
#endif

#ifndef __GNUC__
#  define __attribute__(...)	/* empty */
#endif

/* I found  the following chunk on  the Net.  (Marco Maggi;  Sun Feb 26,
   2012) */
#if defined _WIN32 || defined __CYGWIN__
#  ifdef BUILDING_DLL
#    ifdef __GNUC__
#      define cct_decl		__attribute__((__dllexport__)) extern
#    else
#      define cct_decl		__declspec(dllexport) extern
#    endif
#  else
#    ifdef __GNUC__
#      define cct_decl		__attribute__((__dllimport__)) extern
#    else
#      define cct_decl		__declspec(dllimport) extern
#    endif
#  endif
#  define cct_private_decl	extern
#else
#  if __GNUC__ >= 4
#    define cct_decl		__attribute__((__visibility__("default"))) extern
#    define cct_private_decl	__attribute__((__visibility__("hidden")))  extern
#  else
#    define cct_decl		extern
#    define cct_private_decl	extern
#  endif
#endif


/** --------------------------------------------------------------------
 ** Headers.
 ** ----------------------------------------------------------------- */

/* Enable everything GNU. */
#define _GNU_SOURCE		1

/* Enable latest POSIX features. */
#define _POSIX_C_SOURCE		200809L

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h> /* for offsetof() */
#include <setjmp.h>
#include <errno.h>
#include <unistd.h>


/** --------------------------------------------------------------------
 ** Constants and preprocessor macros.
 ** ----------------------------------------------------------------- */

#define CCT_PC(POINTER_TYPE, POINTER_NAME, EXPRESSION)	\
  POINTER_TYPE * POINTER_NAME = (POINTER_TYPE *) (EXPRESSION)


/** --------------------------------------------------------------------
 ** Version functions.
 ** ----------------------------------------------------------------- */

cct_decl char const *	cct_version_string		(void);
cct_decl int		cct_version_interface_current	(void);
cct_decl int		cct_version_interface_revision	(void);
cct_decl int		cct_version_interface_age	(void);


/** --------------------------------------------------------------------
 ** Library initialisation.
 ** ----------------------------------------------------------------- */

cct_decl void cct_library_init (void)
  __attribute__((__constructor__));


/** --------------------------------------------------------------------
 ** Done.
 ** ----------------------------------------------------------------- */

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* MMUX_EMACS_TEMPLATE_H */

/* end of file */
