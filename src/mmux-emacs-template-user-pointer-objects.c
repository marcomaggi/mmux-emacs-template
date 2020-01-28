/*
  Part of: MMUX Emacs Template
  Contents: usge examples for user-ptr elisp objects
  Date: Jan 14, 2020

  Abstract

	This module implements example functions  accessing and creating the user-ptr
	elisp objects.

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
#include <string.h>
#include <stdlib.h>
#include <errno.h>


/** --------------------------------------------------------------------
 ** Example functions.
 ** ----------------------------------------------------------------- */

typedef struct mmux_template_cplx_t	mmux_template_cplx_t;

struct mmux_template_cplx_t {
  double	X;
  double	Y;
};

static void
cplx_finalizer (void * obj)
{
  free(obj);
}

static emacs_value
Fmmux_emacs_template_cplx_cmake (emacs_env *env, ptrdiff_t nargs MMUX_EMACS_TEMPLATE_UNUSED,
				 emacs_value args[], void * data MMUX_EMACS_TEMPLATE_UNUSED)
{
  double		X = mmux_emacs_get_float(env, args[0]);
  double		Y = mmux_emacs_get_float(env, args[1]);
  mmux_template_cplx_t	* obj;

  errno = 0;
  obj   = malloc(sizeof(mmux_template_cplx_t));
  if (NULL == obj) {
    char const		* errmsg = strerror(errno);
    emacs_value		Serrmsg = mmux_emacs_make_string(env, errmsg, strlen(errmsg));

    /* Signal an error,  then immediately return.  In the "elisp"  Info file: see the
       node "Standard Errors" for a list of  the standard error symbols; see the node
       "Error Symbols"  for methods to define  error symbols.  (Marco Maggi;  Jan 14,
       2020) */
    env->non_local_exit_signal(env, env->intern(env, "mmux-template-no-memory-error"), Serrmsg);
    return env->intern(env, "nil");
  } else {
    obj->X = X;
    obj->Y = Y;
    return mmux_emacs_make_user_ptr(env, cplx_finalizer, obj);
  }
}

static emacs_value
Fmmux_emacs_template_cplx_get_X (emacs_env *env, ptrdiff_t nargs MMUX_EMACS_TEMPLATE_UNUSED,
				 emacs_value args[], void * data MMUX_EMACS_TEMPLATE_UNUSED)
{
  mmux_template_cplx_t	* obj = mmux_emacs_get_user_ptr(env, args[0]);

  return mmux_emacs_make_float(env, obj->X);
}

static emacs_value
Fmmux_emacs_template_cplx_get_Y (emacs_env *env, ptrdiff_t nargs MMUX_EMACS_TEMPLATE_UNUSED,
				 emacs_value args[], void * data MMUX_EMACS_TEMPLATE_UNUSED)
{
  mmux_template_cplx_t	* obj = mmux_emacs_get_user_ptr(env, args[0]);

  return mmux_emacs_make_float(env, obj->Y);
}


/** --------------------------------------------------------------------
 ** Elisp functions table.
 ** ----------------------------------------------------------------- */

#define NUMBER_OF_MODULE_FUNCTIONS	3
static module_function_t const module_functions_table[NUMBER_OF_MODULE_FUNCTIONS] = {
  {
    .name		= "mmux-template-c-cplx-make",
    .implementation	= Fmmux_emacs_template_cplx_cmake,
    .min_arity		= 2,
    .max_arity		= 2,
    .documentation	= "Build and return a new cplx object."
  },
  {
    .name		= "mmux-template-c-cplx-get-X",
    .implementation	= Fmmux_emacs_template_cplx_get_X,
    .min_arity		= 1,
    .max_arity		= 1,
    .documentation	= "Return the X component of a cplx object."
  },
  {
    .name		= "mmux-template-c-cplx-get-Y",
    .implementation	= Fmmux_emacs_template_cplx_get_Y,
    .min_arity		= 1,
    .max_arity		= 1,
    .documentation	= "Return the Y component of a cplx object."
  },
};


/** --------------------------------------------------------------------
 ** Module initialisation.
 ** ----------------------------------------------------------------- */

void
mmux_emacs_template_user_ptr_objects_init (emacs_env * env)
{
  mmux_emacs_template_define_functions_from_table(env, module_functions_table, NUMBER_OF_MODULE_FUNCTIONS);
}

/* end of file */
