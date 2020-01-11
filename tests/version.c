/*
  Part of: MMUX Emacs Template
  Contents: test for version functions
  Date: Jan 11, 2020

  Abstract

	Test file for version functions.

  Copyright (C) 2020 Marco Maggi <mrc.mgg@gmail.com>

  See the COPYING file.
*/

#include <mmux-emacs-template.h>
#include <stdio.h>
#include <stdlib.h>

int
main (int argc CCT_UNUSED, char const * const argv[] CCT_UNUSED)
{
  cct_library_init();

  printf("version number string: %s\n", cct_version_string());
  printf("libtool version number: %d:%d:%d\n",
	 cct_version_interface_current(),
	 cct_version_interface_revision(),
	 cct_version_interface_age());
  exit(EXIT_SUCCESS);
}

/* end of file */
