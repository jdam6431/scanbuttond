// libusbi.h: libusb wrapper
// This file is part of scanbuttond.
// Copyleft )c( 2004-2006 by Bernhard Stiftner
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 2 of the
// License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

#ifndef __LIBUSBI_H_INCLUDED
#define __LIBUSBI_H_INCLUDED

#include <usb.h>
#include "scanbuttond/scanbuttond.h"

struct libusbi_device;
typedef struct libusbi_device libusbi_device_t;

struct libusbi_device {
	int vendorID;
	int productID;
	char* location; // bus number + ":" + device number
	struct usb_device* device;
	struct usb_dev_handle* handle; // automatically set by libusbi_open(...)
	int interface;
	int out_endpoint;
	int in_endpoint;
	libusbi_device_t* next;
};

struct libusbi_handle;
typedef struct libusbi_handle libusbi_handle_t;

struct libusbi_handle {
	libusbi_device_t* devices;
	// rescanning info, timestamps???
};

libusbi_handle_t* libusbi_init(void);

// GLOBAL number of changed devices (does not require a handle!)
int libusbi_get_changed_device_count(void);

void libusbi_rescan(libusbi_handle_t* handle);

libusbi_device_t* libusbi_get_devices(libusbi_handle_t* handle);

// returns 0 on success, -EBUSY if the scanner is currently in use,
// or -ENODEV if the scanner does no longer exist
int libusbi_open(libusbi_device_t* device);

int libusbi_close(libusbi_device_t* device);

int libusbi_read(libusbi_device_t* device, void* buffer, int bytecount);

int libusbi_write(libusbi_device_t* device, void* buffer, int bytecount);

// flush bulk read queue
void libusbi_flush(libusbi_device_t* device);

int libusbi_control_msg(libusbi_device_t* device, int requesttype,
					   int request, int value, int index, void* bytes, int size);

void libusbi_exit(libusbi_handle_t* handle);

#endif
