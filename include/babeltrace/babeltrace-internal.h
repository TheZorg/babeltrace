#ifndef _BABELTRACE_INTERNAL_H
#define _BABELTRACE_INTERNAL_H

#include <stdio.h>
#include <glib.h>

extern int babeltrace_verbose, babeltrace_debug;

#define printf_verbose(fmt, args...)				\
	do {							\
		if (babeltrace_verbose)				\
			printf("[verbose] " fmt, ## args);	\
	} while (0)

#define printf_debug(fmt, args...)				\
	do {							\
		if (babeltrace_debug)				\
			printf("[debug] " fmt, ## args);	\
	} while (0)

#define likely(x)	__builtin_expect(!!(x), 1)
#define unlikely(x)	__builtin_expect(!!(x), 0)

struct trace_descriptor;
struct trace_collection {
	GPtrArray *array;
};

int convert_trace(struct trace_descriptor *td_write,
		  struct trace_collection *trace_collection_read);

extern int opt_all_field_names,
	opt_scope_field_names,
	opt_header_field_names,
	opt_context_field_names,
	opt_payload_field_names,
	opt_trace_name,
	opt_trace_domain,
	opt_trace_procname,
	opt_trace_vpid,
	opt_loglevel;

#endif