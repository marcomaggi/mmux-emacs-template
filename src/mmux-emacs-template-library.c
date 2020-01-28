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

#include <string.h>
#include <stdint.h>
#include "mmux-emacs-template-internals.h"


/** --------------------------------------------------------------------
 ** Global variables.
 ** ----------------------------------------------------------------- */

/* This is required by GNU Emacs' API. */
int  plugin_is_GPL_compatible;


/** --------------------------------------------------------------------
 ** Version functions.
 ** ----------------------------------------------------------------- */

char const *
mmux_emacs_template_version_string (void)
{
  return mmux_emacs_template_VERSION_INTERFACE_STRING;
}
int
mmux_emacs_template_version_interface_current (void)
{
  return mmux_emacs_template_VERSION_INTERFACE_CURRENT;
}
int
mmux_emacs_template_version_interface_revision (void)
{
  return mmux_emacs_template_VERSION_INTERFACE_REVISION;
}
int
mmux_emacs_template_version_interface_age (void)
{
  return mmux_emacs_template_VERSION_INTERFACE_AGE;
}

/* ------------------------------------------------------------------ */

static emacs_value
Fmmux_emacs_template_version_string (emacs_env *env,
			       ptrdiff_t nargs MMUX_EMACS_TEMPLATE_UNUSED, emacs_value args[] MMUX_EMACS_TEMPLATE_UNUSED,
			       void *data MMUX_EMACS_TEMPLATE_UNUSED)
{
  char const *	str = mmux_emacs_template_version_string();

  return mmux_emacs_make_string(env, str, strlen(str));
}
static emacs_value
Fmmux_emacs_template_version_interface_current (emacs_env *env,
					  ptrdiff_t nargs MMUX_EMACS_TEMPLATE_UNUSED, emacs_value args[] MMUX_EMACS_TEMPLATE_UNUSED,
					  void *data MMUX_EMACS_TEMPLATE_UNUSED)
{
  int	N = mmux_emacs_template_version_interface_current();

  return mmux_emacs_make_int(env, (intmax_t)N);
}
static emacs_value
Fmmux_emacs_template_version_interface_revision (emacs_env *env,
					   ptrdiff_t nargs MMUX_EMACS_TEMPLATE_UNUSED, emacs_value args[] MMUX_EMACS_TEMPLATE_UNUSED,
					   void *data MMUX_EMACS_TEMPLATE_UNUSED)
{
  int	N = mmux_emacs_template_version_interface_revision();

  return mmux_emacs_make_int(env, (intmax_t)N);
}
static emacs_value
Fmmux_emacs_template_version_interface_age (emacs_env *env,
				      ptrdiff_t nargs MMUX_EMACS_TEMPLATE_UNUSED, emacs_value args[] MMUX_EMACS_TEMPLATE_UNUSED,
				      void *data MMUX_EMACS_TEMPLATE_UNUSED)
{
  int	N = mmux_emacs_template_version_interface_age();

  return mmux_emacs_make_int(env, (intmax_t)N);
}


/** --------------------------------------------------------------------
 ** Table of elisp functions.
 ** ----------------------------------------------------------------- */

#define NUMBER_OF_MODULE_FUNCTIONS	4
static module_function_t const module_functions_table[NUMBER_OF_MODULE_FUNCTIONS] = {
  {
    .name		= "mmux-template-version-string",
    .implementation	= Fmmux_emacs_template_version_string,
    .min_arity		= 0,
    .max_arity		= 0,
    .documentation	= "Return the version string."
  },
  {
    .name		= "mmux-template-version-interface-current",
    .implementation	= Fmmux_emacs_template_version_interface_current,
    .min_arity		= 0,
    .max_arity		= 0,
    .documentation	= "Return the interface version current number."
  },
  {
    .name		= "mmux-template-version-interface-revision",
    .implementation	= Fmmux_emacs_template_version_interface_revision,
    .min_arity		= 0,
    .max_arity		= 0,
    .documentation	= "Return the interface version revision number."
  },
  {
    .name		= "mmux-template-version-interface-age",
    .implementation	= Fmmux_emacs_template_version_interface_age,
    .min_arity		= 0,
    .max_arity		= 0,
    .documentation	= "Return the interface version age number."
  }
};


/** --------------------------------------------------------------------
 ** Module initialisation.
 ** ----------------------------------------------------------------- */

void
mmux_emacs_template_define_functions_from_table (emacs_env * env, module_function_t const * module_functions, int number_of_module_functions)
{
  emacs_value	Qdefalias = env->intern(env, "defalias");

  for (int i=0; i<number_of_module_functions; ++i) {
    emacs_value	args[2]	= {
      env->intern(env, module_functions[i].name),
      env->make_function(env,
			 module_functions[i].min_arity,
			 module_functions[i].max_arity,
			 module_functions[i].implementation,
			 module_functions[i].documentation,
			 NULL)
    };
    if (0) {
      fprintf(stderr, "%s: defining function for C %s\n", __func__, module_functions[i].name);
    }
    env->funcall(env, Qdefalias, 2, args);
  }
}

int
emacs_module_init (struct emacs_runtime *ert)
{
  if (ert->size < (ptrdiff_t)sizeof(*ert)) {
    return 1;
  } else {
    emacs_env	*env = ert->get_environment(ert);

    if (env->size < (ptrdiff_t)sizeof(*env)) {
      return 2;
    } else {
      mmux_emacs_template_define_functions_from_table(env, module_functions_table, NUMBER_OF_MODULE_FUNCTIONS);
      mmux_emacs_template_builtin_objects_init(env);
      mmux_emacs_template_user_ptr_objects_init(env);
      return 0;
    }
  }
}

/* end of file */
