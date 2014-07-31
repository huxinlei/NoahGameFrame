// -------------------------------------------------------------------------
//    @FileName         :    NFIProperty.h
//    @Author           :    LvSheng.Huang
//    @Date             :    2012-03-01
//    @Module           :    NFIProperty
//
// -------------------------------------------------------------------------

#ifndef _NFI_PROPERTY_H_
#define _NFI_PROPERTY_H_

#include "NFDefine.h"
#include "NFIValueList.h"

class NFIProperty
{
public:
    virtual ~NFIProperty() {}

    virtual void SetValue(const NFIValueList::TData& TData) = 0;
    virtual void SetValue(const NFIProperty* pProperty) = 0;
    virtual bool SetInt(int value) = 0;
    virtual bool SetFloat(float value) = 0;
    virtual bool SetDouble(double value) = 0;
    virtual bool SetString(const std::string& value) = 0;
    virtual bool SetObject(const NFIDENTID& value) = 0;
    virtual bool SetPointer(void* value) = 0;

    virtual const TDATA_TYPE GetType() const = 0;
    virtual const bool GeUsed() const = 0;
    virtual const std::string& GetKey() const = 0;
    virtual const bool GetSave() const = 0;
    virtual const bool GetPublic() const = 0;
    virtual const bool GetPrivate() const = 0;
    virtual const int GetIndex() const = 0;
    virtual const std::string& GetRelationValue() const = 0;

    virtual void SetSave(bool bSave) = 0;
    virtual void SetPublic(bool bPublic) = 0;
    virtual void SetPrivate(bool bPrivate) = 0;
    virtual void SetScriptFunction(const std::string& strScriptFunction) = 0;

    virtual int GetInt() const = 0;
    virtual float GetFloat() const = 0;
    virtual double GetDouble() const = 0;
    virtual const std::string& GetString() const = 0;
    virtual NFIDENTID GetObject() const = 0;
    virtual void* GetPointer() const = 0;

    virtual bool Changed() const = 0;

    virtual void RegisterCallback(const PROPERTY_EVENT_FUNCTOR_PTR& cb, const NFIValueList& argVar) = 0;

protected:

    virtual NFIValueList::TData GetValue() const = 0;

};

#endif
