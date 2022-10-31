#ifndef SECCCAN_H
#define SECCCAN_H


#include <map>
#include <functional>
#include <time.h>
#include "NewProtocol.h"

#include <map>

class EVSEModelCan
{
private:

    String chargePointModel;
    int connectorNum;
    String chargePointSerialNumber;
    String chargePointVendor;
    String firmwareVersion;  

    String Cablestatus;
    String CPstatus;
    String lockstutus;

    float L1Voltage; float L1Current; float L1Power;
    float L2Voltage; float L2Current; float L2Power;
    float L3Voltage; float L3Current; float L3Power;

    String idtag;
    int UsingconnecterID;
    String ErrorCode = "NoError";
    
    std::map<uint32_t,String> CanPacketSave;

    Payload_AuthorizeReq  AuthorizeReq;
    Payload_BootNtf BootNtf;
    Payload_HeartbeatReq HeartbeatReq;
    Payload_MeterValueNtf MeterValueNtf;
    Payload_StopChargingNtf StopChargingNtf;
    Payload_ErrorNtf ErrorNtf;
    Payload_ChangeAvailabilityRes ChangeAvailabilityRes;
    Payload_RemoteStartRes RemoteStartRes;
    Payload_RemoteStopRes RemoteStopRes;
    Payload_ResetRes ResetRes;
    Payload_UnlockConnectorRes UnlockConnectorRes;
 
    //template<typename T>
    void CanProtocol_AuthorizeReq(Payload_AuthorizeReq& payload );  
    void CanProtocol_BootNtf(Payload_BootNtf& payload);
    void CanProtocol_HeartbeatReq(Payload_HeartbeatReq& payload);
    void CanProtocol_MeterValueNtf(Payload_MeterValueNtf& payload);
public:
    //EVSEModel(SECC_SPIClass *pCommIF);
    EVSEModelCan();
    ~EVSEModelCan();
    
    void loop();

    void Command_Boot();  
    void Command_Heartbeat();
    void Command_MeterValue();
    void Command_Authorize();
    void Command_StopCharing();
    void Command_Error();

    String getchargePointModel();
    int getconnectorNum();
    String getchargePointSerialNumber();
    String getchargePointVendor();
    String getfirmwareVersion();  

    String getCablestatus();
    String getCPstatus();
    String getlockstutus();

    int getL1Voltage(); int getL1current(); int getL1Power();
    int getL2Voltage(); int getL2current(); int getL2Power();
    int getL3Voltage(); int getL3current(); int getL3Power();

    String getidtag();
    int getUsingconnecterID();
    String getErrorCode();
};


#endif