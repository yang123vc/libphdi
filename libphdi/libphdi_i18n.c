/*
 * Internationalization (i18n) functions
 *
 * Copyright (C) 2015-2016, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <types.h>

#if defined( HAVE_LIBINTL_H )
#include <libintl.h>
#endif

#include "libphdi_i18n.h"
#include "libphdi_libcerror.h"

static int libphdi_i18n_initialized = 0;

/* Initializes library internationalization functions
 */
int libphdi_i18n_initialize(
     libcerror_error_t **error )
{
	static char *function = "libphdi_i18n_initialize";

	if( libphdi_i18n_initialized == 0 )
	{
#if defined( HAVE_BINDTEXTDOMAIN )
		if( bindtextdomain(
		     "libphdi",
		     LOCALEDIR ) == NULL )
		{
			libcerror_error_set(
			 error,
			 LIBCERROR_ERROR_DOMAIN_RUNTIME,
			 LIBCERROR_RUNTIME_ERROR_SET_FAILED,
			 "%s: unable to bind text domain.",
			 function );

			return( -1 );
		}
#endif
		libphdi_i18n_initialized = 1;
	}
	return( 1 );
}

