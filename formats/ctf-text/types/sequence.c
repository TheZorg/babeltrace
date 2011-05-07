/*
 * Common Trace Format
 *
 * Sequence format access functions.
 *
 * Copyright 2010 - Mathieu Desnoyers <mathieu.desnoyers@efficios.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 */

#include <babeltrace/ctf-text/types.h>
#include <stdio.h>

int ctf_text_sequence_write(struct stream_pos *ppos, struct definition *definition)
{
	struct ctf_text_stream_pos *pos = ctf_text_pos(ppos);
	int ret;

	if (!pos->dummy) {
		print_pos_tabs(pos);
		fprintf(pos->fp, "[\n");
		pos->depth++;
	}
	ret = sequence_rw(ppos, definition);
	if (!pos->dummy) {
		pos->depth--;
		print_pos_tabs(pos);
		fprintf(pos->fp, "]\n");
	}
	return ret;
}