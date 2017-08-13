#include <string>
using namespace std;
namespace ssorest {
    class PluginConfiguration
    {
    public:
        PluginConfiguration();
        
        bool   getEnable();
        bool   getTraceEnable();
        string getAccountName();
        string getGatewayUrl();
        string getGatewayToken();
        string getPluginId();
        string getSecretKey();
        string getSSOZone();

        void setEnable(const bool& flag);
        void setTraceEnable(const bool& flag);
        void setAccountName(const string& value);
        void setGatewayUrl(const string& value);
        void setGatewayToken(const string& value);
        void setPluginId(const string& value);
        void setSecretKey(const string& value);
        void setSSOZone(const string& value);
        
    private:
        bool   isEnabled;
        bool   traceEnabled;
        string acoName;
        string gatewayUrl;
        string gatewayToken;
        string pluginId;
        string secretKey;
        string ssoZone;
    };
}