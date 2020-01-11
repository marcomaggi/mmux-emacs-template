/*
  Part of: MMUX Emacs Template
  Contents: library functions
  Date: Mar  1, 2012

  Abstract

	This module implements library initialisation and version numbers inspection.

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


/** --------------------------------------------------------------------
 ** Headers.
 ** ----------------------------------------------------------------- */

#include "mmux-emacs-template-internals.h"


/** --------------------------------------------------------------------
 ** Version functions.
 ** ----------------------------------------------------------------- */

char const *
cct_version_string (void)
{
  return mmux_emacs_template_VERSION_INTERFACE_STRING;
}
int
cct_version_interface_current (void)
{
  return mmux_emacs_template_VERSION_INTERFACE_CURRENT;
}
int
cct_version_interface_revision (void)
{
  return mmux_emacs_template_VERSION_INTERFACE_REVISION;
}
int
cct_version_interface_age (void)
{
  return mmux_emacs_template_VERSION_INTERFACE_AGE;
}


/** --------------------------------------------------------------------
 ** Library initialisation.
 ** ----------------------------------------------------------------- */

void
cct_library_init (void)
{
}

/* end of file */
