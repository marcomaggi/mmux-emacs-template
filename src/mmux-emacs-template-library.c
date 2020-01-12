/*
  Part of: MMUX Emacs Template
  Contents: library functions
  Date: Mar  1, 2012

  Abstract

	This module implements library initialisation and version numbers inspection.

  Copyright (C) 2020 Marco Maggi <mrc.mgg@gmail.com>
  Copyright (C) 2017 by Syohei YOSHIDA <https://github.com/syohex>

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

#include <string.h>
#include <stdint.h>
#include "mmux-emacs-template-internals.h"


/** --------------------------------------------------------------------
 ** Version functions.
 ** ----------------------------------------------------------------- */

char const *
met_version_string (void)
{
  return mmux_emacs_template_VERSION_INTERFACE_STRING;
}
int
met_version_interface_current (void)
{
  return mmux_emacs_template_VERSION_INTERFACE_CURRENT;
}
int
met_version_interface_revision (void)
{
  return mmux_emacs_template_VERSION_INTERFACE_REVISION;
}
int
met_version_interface_age (void)
{
  return mmux_emacs_template_VERSION_INTERFACE_AGE;
}

/* ------------------------------------------------------------------ */

static emacs_value
Fmet_version_string (emacs_env *env, ptrdiff_t nargs MET_UNUSED, emacs_value args[]  MET_UNUSED, void *data MET_UNUSED)
{
  char const *	str = met_version_string();

  return env->make_string(env, str, strlen(str));
}
static emacs_value
Fmet_version_interface_current (emacs_env *env, ptrdiff_t nargs MET_UNUSED, emacs_value args[]  MET_UNUSED, void *data MET_UNUSED)
{
  int	N = met_version_interface_current();

  return env->make_integer(env, (intmax_t)N);
}
static emacs_value
Fmet_version_interface_revision (emacs_env *env, ptrdiff_t nargs MET_UNUSED, emacs_value args[]  MET_UNUSED, void *data MET_UNUSED)
{
  int	N = met_version_interface_revision();

  return env->make_integer(env, (intmax_t)N);
}
static emacs_value
Fmet_version_interface_age (emacs_env *env, ptrdiff_t nargs MET_UNUSED, emacs_value args[]  MET_UNUSED, void *data MET_UNUSED)
{
  int	N = met_version_interface_age();

  return env->make_integer(env, (intmax_t)N);
}


/** --------------------------------------------------------------------
 ** Library initialisation.
 ** ----------------------------------------------------------------- */

/* This is required by GNU Emacs' API. */
int  plugin_is_GPL_compatible;

static void
bind_function (emacs_env *env, char const *name, emacs_value Sfun)
{
  emacs_value Qfset = env->intern(env, "fset");
  emacs_value Qsym = env->intern(env, name);
  emacs_value args[] = { Qsym, Sfun };

  env->funcall(env, Qfset, 2, args);
}

static void
provide (emacs_env *env, char const * feature)
{
  emacs_value Qfeat = env->intern(env, feature);
  emacs_value Qprovide = env->intern (env, "provide");
  emacs_value args[] = { Qfeat };

  env->funcall(env, Qprovide, 1, args);
}

int
emacs_module_init (struct emacs_runtime *ert)
{
  emacs_env	*env = ert->get_environment(ert);

#define DEFUN(lsym, csym, amin, amax, doc, data)			\
  bind_function (env, lsym, env->make_function(env, amin, amax, csym, doc, data))

  DEFUN("met-version-string",			Fmet_version_string,		0, 0, "Return the version string", NULL);
  DEFUN("met-version-interface-current",	Fmet_version_interface_current,	0, 0, "Return the interface version current number", NULL);
  DEFUN("met-version-interface-revision",	Fmet_version_interface_revision,0, 0, "Return the interface version revision number", NULL);
  DEFUN("met-version-interface-age",		Fmet_version_interface_age,	0, 0, "Return the interface version age number", NULL);
#undef DEFUN

  provide(env, "libmmux-emacs-template");
  return 0;
}

/* end of file */
