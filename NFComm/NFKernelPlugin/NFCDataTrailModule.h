// -------------------------------------------------------------------------
//    @FileName			:    NFCDataTrailModule.h
//    @Author           :    LvSheng.Huang
//    @Date             :    2013-09-30
//    @Module           :    NFCDataTrailModule
//
// -------------------------------------------------------------------------

#ifndef NFC_DATA_TRAIL_MODULE_H
#define NFC_DATA_TRAIL_MODULE_H

#include "NFComm/NFPluginModule/NFIKernelModule.h"
#include "NFComm/NFPluginModule/NFIPropertyModule.h"
#include "NFComm/NFPluginModule/NFIElementModule.h"
#include "NFComm/NFPluginModule/NFIClassModule.h"
#include "NFComm/NFPluginModule/NFIPropertyConfigModule.h"
#include "NFComm/NFPluginModule/NFIPluginManager.h"
#include "NFComm/NFPluginModule/NFIDataTrailModule.h"
#include "NFComm/NFPluginModule/NFILogModule.h"

class NFCDataTrailModule
    : public NFIDataTrailModule
{
public:
    NFCDataTrailModule(NFIPluginManager* p)
    {
        pPluginManager = p;
    }
    virtual ~NFCDataTrailModule() {};

    virtual bool Init();
    virtual bool Shut();
    virtual bool Execute();
    virtual bool AfterInit();

	virtual void LogObjectData(const NFGUID& self);
    virtual void StartTrail(const NFGUID& self);

protected:
    void PrintStackTrace();

    int TrailObjectData(const NFGUID& self);

    int OnObjectPropertyEvent(const NFGUID& self, const std::string& strPropertyName, const NFData& oldVar, const NFData& newVar);

    int OnObjectRecordEvent(const NFGUID& self, const RECORD_EVENT_DATA& xEventData, const NFData& oldVar, const NFData& newVar);

private:

    NFIKernelModule* m_pKernelModule;
    NFIElementModule* m_pElementModule;
    NFIClassModule* m_pClassModule;
    NFILogModule* m_pLogModule;
};


#endif
