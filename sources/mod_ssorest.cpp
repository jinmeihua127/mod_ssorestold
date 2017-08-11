#include <httpd.h>
#include <http_request.h>
#include <http_log.h>
#include <http_core.h>
#include "PluginConfiguration.h"
using namespace ssorest;

static const char* setEnable(cmd_parms* command, void* /*config*/, const char* argument);
static const char* setTraceEnable(cmd_parms* command, void* /*config*/, const char* argument);
static const char* setAccountName(cmd_parms* command, void* /*config*/, const char* argument);
static const char* setGatewayUrl(cmd_parms* command, void* /*config*/, const char* argument);
static const char* setPluginId(cmd_parms* command, void* /*config*/, const char* argument);
static const char* setSecretKey(cmd_parms* command, void* /*config*/, const char* argument);
static const char* setSSOZone(cmd_parms* command, void* /*config*/, const char* argument);
static void registerHooks(apr_pool_t* );

static PluginConfiguration configuration;

static const command_rec moduleDirectives[] =
{
    AP_INIT_TAKE1
    (
        "SSORestEnabled",            
        reinterpret_cast<cmd_func>(setEnable), 
        NULL, 
        OR_ALL, 
        "Enable or disable mod_ssorest"
    ),

    AP_INIT_TAKE1
    (
        "SSORestTrace",
        reinterpret_cast<cmd_func>(setTraceEnable), 
        NULL, 
        OR_ALL, 
        "Enable or disable libcurl debug"
    ),

    AP_INIT_TAKE1
    (
        "SSORestACOName",        
        reinterpret_cast<cmd_func>(setAccountName), 
        NULL, 
        OR_ALL, 
        ""
    ),
          
    AP_INIT_TAKE1
    (
        "SSORestGatewayUrl",
        reinterpret_cast<cmd_func>(setGatewayUrl), 
        NULL, 
        OR_ALL, 
        "Gateway Location"
    ),

    AP_INIT_TAKE1
    (
        "SSORestPluginId",
        reinterpret_cast<cmd_func>(setPluginId), 
        NULL, 
        OR_ALL, 
        ""
    ),

    AP_INIT_TAKE1
    (
        "SSORestSecretKey",
        reinterpret_cast<cmd_func>(setSecretKey), 
        NULL, 
        OR_ALL,
        ""
    ),

    AP_INIT_TAKE1
    (
        "SSORestSSOZone",
        reinterpret_cast<cmd_func>(setSSOZone), 
        NULL, 
        OR_ALL, 
        ""
    ),
    
    { NULL }
};

extern "C" {
    AP_DECLARE_MODULE(ssorest) = {
        STANDARD20_MODULE_STUFF,
        NULL,                   /* Per-directory configuration handler */
        NULL,                   /* Merge handler for per-directory configurations */
        NULL,                   /* Per-server configuration handler */
        NULL,                   /* Merge handler for per-server configurations */
        NULL, 
        registerHooks 
    };
}


static const char* setEnable(cmd_parms* command, void* /*config*/, const char* argument)
{
    if (::strcasecmp(argument, "on") == 0)
        configuration.setEnable(true);
    else
        configuration.setEnable(false);
    return NULL;
}
static const char* setTraceEnable(cmd_parms* command, void* /*config*/, const char* argument)
{
    if (::strcasecmp(argument, "on") == 0)
        configuration.setTraceEnable(true);
    else
        configuration.setTraceEnable(false);
    return NULL;
}
static const char* setAccountName(cmd_parms* command, void* /*config*/, const char* argument)
{
    configuration.setAccountName(argument);
    return NULL;
}
static const char* setGatewayUrl(cmd_parms* command, void* /*config*/, const char* argument)
{
    configuration.setGatewayUrl(argument);
    return NULL;
}
static const char* setPluginId(cmd_parms* command, void* /*config*/, const char* argument)
{
    configuration.setPluginId(argument);
    return NULL;
}
static const char* setSecretKey(cmd_parms* command, void* /*config*/, const char* argument)
{
    configuration.setSecretKey(argument);
    return NULL;
}
static const char* setSSOZone(cmd_parms* command, void* /*config*/, const char* argument)
{
    configuration.setSSOZone(argument);
    return NULL;
}


static int processRequest(request_rec* r) {
    ap_log_rerror(APLOG_MARK, APLOG_WARNING, 0, r, APLOGNO(10000)
            "Evalute the Request");
    ap_log_rerror(APLOG_MARK, APLOG_WARNING, 0, r, APLOGNO(10000)
            "TestCode:%s:", configuration.getSecretKey().c_str());
    return OK;
}

static void registerHooks(apr_pool_t* ) {
    ::ap_hook_check_access(processRequest, NULL, NULL, APR_HOOK_MIDDLE,
                      AP_AUTH_INTERNAL_PER_URI);
}