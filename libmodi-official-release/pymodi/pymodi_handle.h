/*
 * Python object wrapper of libmodi_handle_t
 *
 * Copyright (C) 2012-2021, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#if !defined( _PYMODI_HANDLE_H )
#define _PYMODI_HANDLE_H

#include <common.h>
#include <types.h>

#include "pymodi_libbfio.h"
#include "pymodi_libmodi.h"
#include "pymodi_python.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct pymodi_handle pymodi_handle_t;

struct pymodi_handle
{
	/* Python object initialization
	 */
	PyObject_HEAD

	/* The libmodi handle
	 */
	libmodi_handle_t *handle;

	/* The libbfio file IO handle
	 */
	libbfio_handle_t *file_io_handle;

	/* The file IO pool
	 */
	libbfio_pool_t *file_io_pool;
};

extern PyMethodDef pymodi_handle_object_methods[];
extern PyTypeObject pymodi_handle_type_object;

int pymodi_handle_init(
     pymodi_handle_t *pymodi_handle );

void pymodi_handle_free(
      pymodi_handle_t *pymodi_handle );

PyObject *pymodi_handle_signal_abort(
           pymodi_handle_t *pymodi_handle,
           PyObject *arguments );

PyObject *pymodi_handle_open(
           pymodi_handle_t *pymodi_handle,
           PyObject *arguments,
           PyObject *keywords );

PyObject *pymodi_handle_open_file_object(
           pymodi_handle_t *pymodi_handle,
           PyObject *arguments,
           PyObject *keywords );

PyObject *pymodi_handle_open_band_data_files(
           pymodi_handle_t *pymodi_handle,
           PyObject *arguments );

PyObject *pymodi_handle_open_band_data_files_as_file_objects(
           pymodi_handle_t *pymodi_handle,
           PyObject *arguments,
           PyObject *keywords );

PyObject *pymodi_handle_close(
           pymodi_handle_t *pymodi_handle,
           PyObject *arguments );

PyObject *pymodi_handle_read_buffer(
           pymodi_handle_t *pymodi_handle,
           PyObject *arguments,
           PyObject *keywords );

PyObject *pymodi_handle_read_buffer_at_offset(
           pymodi_handle_t *pymodi_handle,
           PyObject *arguments,
           PyObject *keywords );

PyObject *pymodi_handle_seek_offset(
           pymodi_handle_t *pymodi_handle,
           PyObject *arguments,
           PyObject *keywords );

PyObject *pymodi_handle_get_offset(
           pymodi_handle_t *pymodi_handle,
           PyObject *arguments );

PyObject *pymodi_handle_get_media_size(
           pymodi_handle_t *pymodi_handle,
           PyObject *arguments );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _PYMODI_HANDLE_H ) */
