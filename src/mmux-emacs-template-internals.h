/*
  Part of: MMUX Emacs Template
  Contents: private header file
  Date: Jan 11, 2020

  Abstract

	This header file is for internal definitions.  It must be included by all the
	source files in this package.

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

#ifndef MMUX_EMACS_TEMPLATE_INTERNALS_H
#define MMUX_EMACS_TEMPLATE_INTERNALS_H 1


/** --------------------------------------------------------------------
 ** Headers.
 ** ----------------------------------------------------------------- */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include "mmux-emacs-template.h"


/** --------------------------------------------------------------------
 ** Preprocessor macros.
 ** ----------------------------------------------------------------- */



/** --------------------------------------------------------------------
 ** Constants.
 ** ----------------------------------------------------------------- */

/* This is required by GNU Emacs' API. */
met_decl int  plugin_is_GPL_compatible;


/** --------------------------------------------------------------------
 ** Function prototypes.
 ** ----------------------------------------------------------------- */



/** --------------------------------------------------------------------
 ** Done.
 ** ----------------------------------------------------------------- */

#ifdef __cplusplus
} // extern "C"
#endif

#endif /* MMUX_EMACS_TEMPLATE_INTERNALS_H */

/* end of file */
