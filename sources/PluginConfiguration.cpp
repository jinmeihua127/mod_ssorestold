
#include "PluginConfiguration.h"

namespace ssorest {
    PluginConfiguration::PluginConfiguration()
    {
        isEnabled = false;
    }


    bool   PluginConfiguration::getEnable()
    {
        return isEnabled;
    }

    bool   PluginConfiguration::getTraceEnable()
    {
        return traceEnabled;
    }

    string PluginConfiguration::getAccountName()
    {
        return acoName;
    }

    string PluginConfiguration::getGatewayUrl()
    {
        return gatewayUrl;
    }

    string PluginConfiguration::getGatewayToken()
    {
        return gatewayToken;
    }

    string PluginConfiguration::getPluginId()
    {
        return pluginId;
    }

    string PluginConfiguration::getSecretKey()
    {
        return secretKey;
    }

    string PluginConfiguration::getSSOZone()
    {
        return ssoZone;
    }


    void PluginConfiguration::setEnable(const bool& flag)
    {
        isEnabled = flag;
    }
    void PluginConfiguration::setTraceEnable(const bool& flag)
    {
        traceEnabled = flag;
    }
    void PluginConfiguration::setAccountName(const string& value)
    {
        acoName = value;
    }
    void PluginConfiguration::setGatewayUrl(const string& value)
    {
        gatewayUrl = value;
    }
    void PluginConfiguration::setGatewayToken(const string& value)
    {
        gatewayToken = value;
    }
    void PluginConfiguration::setPluginId(const string& value)
    {
        pluginId = value;
    }
    void PluginConfiguration::setSecretKey(const string& value)
    {
        secretKey = value;
    }
    void PluginConfiguration::setSSOZone(const string& value)
    {
        ssoZone = value;
    }
}