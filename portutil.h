/**
 * portutil.h
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

#ifndef PORTUTIL_H
#define PORTUTIL_H

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

#endif

