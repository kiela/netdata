// SPDX-License-Identifier: GPL-3.0-or-later

#include "test_exporting_engine.h"

// Use memory allocation functions guarded by CMocka in strdupz
const char *__wrap_strdupz(const char *s)
{
    char *duplicate = malloc(sizeof(char) * (strlen(s) + 1));
    strcpy(duplicate, s);

    return duplicate;
}

time_t __wrap_now_realtime_sec(void)
{
    function_called();
    return mock_type(time_t);
}

void __wrap_uv_thread_set_name_np(uv_thread_t ut, const char* name)
{
    (void)ut;
    (void)name;

    function_called();
}

void __wrap_info_int(const char *file, const char *function, const unsigned long line, const char *fmt, ...)
{
    (void)file;
    (void)function;
    (void)line;

    function_called();

    va_list args;

    va_start(args, fmt);
    vsnprintf(log_line, MAX_LOG_LINE, fmt, args);
    va_end(args);
}

int __wrap_connect_to_one_of(
    const char *destination,
    int default_port,
    struct timeval *timeout,
    size_t *reconnects_counter,
    char *connected_to,
    size_t connected_to_size)
{
    (void)timeout;

    function_called();

    check_expected(destination);
    check_expected_ptr(default_port);
    // TODO: check_expected_ptr(timeout);
    check_expected(reconnects_counter);
    check_expected(connected_to);
    check_expected(connected_to_size);

    return mock_type(int);
}

void __rrdhost_check_rdlock(RRDHOST *host, const char *file, const char *function, const unsigned long line)
{
    (void)host;
    (void)file;
    (void)function;
    (void)line;
}

void __rrdset_check_rdlock(RRDSET *st, const char *file, const char *function, const unsigned long line)
{
    (void)st;
    (void)file;
    (void)function;
    (void)line;
}

void __rrd_check_rdlock(const char *file, const char *function, const unsigned long line)
{
    (void)file;
    (void)function;
    (void)line;
}

RRDSET *rrdset_create_custom(
    RRDHOST *host,
    const char *type,
    const char *id,
    const char *name,
    const char *family,
    const char *context,
    const char *title,
    const char *units,
    const char *plugin,
    const char *module,
    long priority,
    int update_every,
    RRDSET_TYPE chart_type,
    STORAGE_ENGINE_ID storage_engine_id,
    long history_entries)
{
    check_expected_ptr(host);
    check_expected_ptr(type);
    check_expected_ptr(id);
    check_expected_ptr(name);
    check_expected_ptr(family);
    check_expected_ptr(context);
    UNUSED(title);
    check_expected_ptr(units);
    check_expected_ptr(plugin);
    check_expected_ptr(module);
    check_expected(priority);
    check_expected(update_every);
    check_expected(chart_type);
    UNUSED(storage_engine_id);
    UNUSED(history_entries);

    function_called();

    return mock_ptr_type(RRDSET *);
}

void rrdset_next_usec(RRDSET *st, usec_t microseconds)
{
    check_expected_ptr(st);
    UNUSED(microseconds);

    function_called();
}

void rrdset_done(RRDSET *st)
{
    check_expected_ptr(st);

    function_called();
}

RRDDIM *rrddim_add_custom(
    RRDSET *st,
    const char *id,
    const char *name,
    collected_number multiplier,
    collected_number divisor,
    RRD_ALGORITHM algorithm,
    STORAGE_ENGINE_ID storage_engine_id)
{
    check_expected_ptr(st);
    UNUSED(id);
    check_expected_ptr(name);
    check_expected(multiplier);
    check_expected(divisor);
    check_expected(algorithm);
    UNUSED(storage_engine_id);

    function_called();

    return NULL;
}

collected_number rrddim_set_by_pointer(RRDSET *st, RRDDIM *rd, collected_number value)
{
    check_expected_ptr(st);
    UNUSED(rd);
    UNUSED(value);

    function_called();

    return 0;
}

const char *storage_engine_name(STORAGE_ENGINE_ID id)
{
    (void)id;
    return STORAGE_ENGINE_NONE_NAME;
}

void rrdset_update_heterogeneous_flag(RRDSET *st)
{
    (void)st;
}

time_t __mock_rrddim_query_oldest_time(STORAGE_METRIC_HANDLE *db_metric_handle)
{
    (void)db_metric_handle;

    function_called();
    return mock_type(time_t);
}

time_t __mock_rrddim_query_latest_time(STORAGE_METRIC_HANDLE *db_metric_handle)
{
    (void)db_metric_handle;

    function_called();
    return mock_type(time_t);
}

void __mock_rrddim_query_init(STORAGE_METRIC_HANDLE *db_metric_handle, struct rrddim_query_handle *handle, time_t start_time, time_t end_time)
{
    (void)db_metric_handle;
    (void)handle;

    function_called();
    check_expected(start_time);
    check_expected(end_time);
}

int __mock_rrddim_query_is_finished(struct rrddim_query_handle *handle)
{
    (void)handle;

    function_called();
    return mock_type(int);
}

STORAGE_POINT __mock_rrddim_query_next_metric(struct rrddim_query_handle *handle)
{
    (void)handle;

    function_called();

    STORAGE_POINT sp = {};
    return sp;    
}

void __mock_rrddim_query_finalize(struct rrddim_query_handle *handle)
{
    (void)handle;

    function_called();
}

void rrdcalc_update_rrdlabels(RRDSET *st)
{
    (void)st;
}

void rrdpush_sender_send_this_host_variable_now(RRDHOST *host, const RRDVAR_ACQUIRED *rva)
{
    (void)host;
    (void)rva;
}

void db_execute(const char *cmd)
{
    (void)cmd;
}

DICTIONARY *rrdfamily_rrdvars_dict(const RRDFAMILY_ACQUIRED *rfa) {
    (void)rfa;
    return NULL;
}
