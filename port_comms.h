typedef unsigned char byte;

int
read_cmd (byte *buf);

int
read_exact (byte *buf, int len);

int
write_cmd (byte *buf, int len);

int
write_cmd_eterm (ETERM *t);

int
write_exact (byte *buf, int len);

