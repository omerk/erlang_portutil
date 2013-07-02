#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <malloc.h>

#include <erl_interface.h>
#include <ei.h>

#include "port_comms.h"


int
read_cmd (byte *buf)
{
	int len;

	if ( read_exact(buf, 2) != 2 ){
		return -1;
	}

	len = (buf[0] << 8) | buf[1];
	return read_exact(buf, len);
}


int
write_cmd(byte *buf, int len)
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

   if (erl_encode(t, buf)!=0)
   {
     return write_cmd(buf, erl_term_len(t));
   } else
   {
      return 0;
   }
}

int
read_exact (byte *buf, int len)
{
	int i, got = 0;

	do {
		if ( (i = read(STDIN_FILENO, buf+got, len-got) ) <= 0 ){ //STDIN_FILENO
                                                                         //=
                                                                         //0
			return i;
		}
		got += i;
	} while ( got < len );

	return len;
}

int
write_exact (byte *buf, int len)
{
	int i, wrote = 0;

	do {
		if ( (i = write(STDOUT_FILENO, buf+wrote, len-wrote) ) <= 0 ){ //STDOUT_FILENO = 1
			return i;
		}
		wrote += i;
	} while ( wrote < len );

	return len;
}

