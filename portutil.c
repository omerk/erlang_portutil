/**
 * portutil.c
 *
 * This file is part of erlang_portutil <http://github.com/omerk/erlang_portutil>
 *
 * Copyright (C) 2013 Omer Kilic <omerkilic@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#ifdef HAVE_MALLOC_H
#include <malloc.h>
#endif

#include <erl_interface.h>
#include <ei.h>

#include "portutil.h"


int
read_cmd (byte *buf)
{
	int len;

	if ( read_exact(buf, 2) != 2 )
	{
		return -1;
	}	

	len = (buf[0] << 8) | buf[1];

	return read_exact(buf, len);
}

int
read_exact (byte *buf, int len)
{
	int i, got = 0;

	do {
		if ( (i = read(STDIN_FILENO, buf+got, len-got) ) <= 0 )
		{
			return i;
		}

		got += i;
	} while ( got < len );

	return len;
}

int
write_cmd (byte *buf, int len)
{
	byte li;

	li = (len >> 8) & 0xff;
	write_exact(&li, 1);

	li = len & 0xff;
	write_exact(&li, 1);

	return write_exact(buf, len);
}

int
write_cmd_eterm (ETERM *t)
{
	byte buf[1024];

	if ( erl_encode(t, buf)!=0 )
	{
		return write_cmd(buf, erl_term_len(t));
	} else {
		return 0;
	}
}


int
write_exact (byte *buf, int len)
{
	int i, wrote = 0;

	do {
		if ( (i = write(STDOUT_FILENO, buf+wrote, len-wrote) ) <= 0 )
		{
			return i;
		}

		wrote += i;
	} while ( wrote < len );

	return len;
}

