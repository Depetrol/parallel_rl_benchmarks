#ifndef _SERVERREACTOR_H
#define _SERVERREACTOR_H
#include <limits.h>
#include "include/core/platform.h"
#include "include/api/api.h"
#include "include/core/reactor.h"
#include "include/core/reactor_common.h"
#include "include/core/threaded/scheduler.h"
#include "include/core/mixed_radix.h"
#include "include/core/port.h"
#include "include/core/environment.h"
int lf_reactor_c_main(int argc, const char* argv[]);
#include "pythontarget.h"
#include "include/core/reactor.h"
#include <limits.h>
#include "include/core/platform.h"
#include "include/api/api.h"
#include "include/core/reactor.h"
#include "include/core/reactor_common.h"
#include "include/core/threaded/scheduler.h"
#include "include/core/mixed_radix.h"
#include "include/core/port.h"
#include "include/core/environment.h"
int lf_reactor_c_main(int argc, const char* argv[]);
#include "pythontarget.h"
#line 62 "/mnt/c/Users/jacky/Desktop/simple_multi/src/trafficv10.lf"
typedef generic_port_instance_struct _serverreactor_updated_parameters_t;
#line 61 "/mnt/c/Users/jacky/Desktop/simple_multi/src/trafficv10.lf"
typedef generic_port_instance_struct _serverreactor_global_parameters_t;
typedef struct {
    struct self_base_t base;
    char *_lf_name;
    PyObject* _lf_py_reaction_function_0;
    PyObject* _lf_py_reaction_function_1;
    
    #line 63 "/mnt/c/Users/jacky/Desktop/simple_multi/src/trafficv10.lf"
    PyObject* running_reward;
    #line 64 "/mnt/c/Users/jacky/Desktop/simple_multi/src/trafficv10.lf"
    PyObject* actions;
    #line 65 "/mnt/c/Users/jacky/Desktop/simple_multi/src/trafficv10.lf"
    PyObject* round_num;
    #line 66 "/mnt/c/Users/jacky/Desktop/simple_multi/src/trafficv10.lf"
    PyObject* start_time;
    #line 62 "/mnt/c/Users/jacky/Desktop/simple_multi/src/trafficv10.lf"
    // Multiport input array will be malloc'd later.
    #line 62 "/mnt/c/Users/jacky/Desktop/simple_multi/src/trafficv10.lf"
    _serverreactor_updated_parameters_t** _lf_updated_parameters;
    #line 62 "/mnt/c/Users/jacky/Desktop/simple_multi/src/trafficv10.lf"
    int _lf_updated_parameters_width;
    #line 62 "/mnt/c/Users/jacky/Desktop/simple_multi/src/trafficv10.lf"
    // Default input (in case it does not get connected)
    #line 62 "/mnt/c/Users/jacky/Desktop/simple_multi/src/trafficv10.lf"
    _serverreactor_updated_parameters_t _lf_default__updated_parameters;
    #line 62 "/mnt/c/Users/jacky/Desktop/simple_multi/src/trafficv10.lf"
    // Struct to support efficiently reading sparse inputs.
    #line 62 "/mnt/c/Users/jacky/Desktop/simple_multi/src/trafficv10.lf"
    lf_sparse_io_record_t* _lf_updated_parameters__sparse;
    #line 61 "/mnt/c/Users/jacky/Desktop/simple_multi/src/trafficv10.lf"
    _serverreactor_global_parameters_t _lf_global_parameters;
    #line 61 "/mnt/c/Users/jacky/Desktop/simple_multi/src/trafficv10.lf"
    int _lf_global_parameters_width;
    #line 68 "/mnt/c/Users/jacky/Desktop/simple_multi/src/trafficv10.lf"
    reaction_t _lf__reaction_0;
    #line 79 "/mnt/c/Users/jacky/Desktop/simple_multi/src/trafficv10.lf"
    reaction_t _lf__reaction_1;
    trigger_t _lf__startup;
    reaction_t* _lf__startup_reactions[1];
    #line 62 "/mnt/c/Users/jacky/Desktop/simple_multi/src/trafficv10.lf"
    trigger_t _lf__updated_parameters;
    #line 62 "/mnt/c/Users/jacky/Desktop/simple_multi/src/trafficv10.lf"
    reaction_t* _lf__updated_parameters_reactions[1];
    #ifdef FEDERATED
    trigger_t* _lf__updated_parameters_network_port_status;
    
    #endif // FEDERATED
} _serverreactor_self_t;
_serverreactor_self_t* new__serverreactor();
#endif // _SERVERREACTOR_H
