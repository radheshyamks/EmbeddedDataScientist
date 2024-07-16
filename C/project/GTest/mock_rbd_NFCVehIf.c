////mock_sourcefilename
//----------------------------------------------------------------------------
// COPYRIGHT RESERVED, 2022 Robert Bosch (Australia) Pty Ltd.
// All rights reserved.  The reproduction, distribution and utilisation of
// this document as well as the communication of its contents to others
// without explicit authorisation is prohibited.  Offenders will be held liable
// for the payment of damages.  All rights reserved in the event of the grant
// of a patent, utility model or design.
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//! \file
//! \brief  Mock function definitions for the rbd_NFCVehIf module.
//!
//----------------------------------------------------------------------------
//============================================================================
// Include Files
//============================================================================
#include "mock_rbd_NFCVehIf.h"

//Include the .c file to get access to static variables and functions
#include "rbd_NFCVehIf.c"

void * gtest_para_memcpy(void* param_1, const void* param_2,size_t param_3)
{
    *(uint8*)param_1 = data1_memcpy[0];
    return 0;
}
//============================================================================
// Mock function definitions
//============================================================================
// Required for FFF
DEFINE_FFF_GLOBALS;
DEFINE_FAKE_VOID_FUNC(rbdSessionMgr_NfcDisconnected,const rbdPk_NfcReaderId_t);
DEFINE_FAKE_VALUE_FUNC(uint8,rbdSessionMgr_GetCardPairingReqResult);
DEFINE_FAKE_VOID_FUNC(rbdSessionMgr_initCardPairingTest,const rbdPk_NfcReaderId_t);
// DEFINE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_CODE),Rte_Receive_rbd_NFCVehIf_NFC_READER_FLDHM_RES_Sig_NFC_READER_FLDHM_DEVICE_Sig,P2VAR(NFC_READER_FLDHM_DEVICE_Sig, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR), P2VAR(uint16, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR));
DEFINE_FAKE_VALUE_FUNC(rbdSessionMgr_Status_et,rbdSessionMgr_ProcessNfcMsg,const rbdPk_NfcReaderId_t, const uint16, const uint8*);
DEFINE_FAKE_VOID_FUNC(rbd_RfhmIf_SendNfcToggleReq,const uint8, const uint8, const rbdPk_KeyRef_t);
DEFINE_FAKE_VALUE_FUNC(rbdSessionMgr_Status_et,rbdSessionMgr_NfcReady,const rbdPk_NfcReaderId_t);
DEFINE_FAKE_VALUE_FUNC(rbdSessionMgr_Status_et,rbdSessionMgr_GetDkAccessProfile,rbdPk_KeyRef_t const, uint8*);
DEFINE_FAKE_VALUE_FUNC(rbdSessionMgr_Status_et,rbdSessionMgr_GetKeyRefByNfcReaderId,const rbdPk_NfcReaderId_t, uint8* const);
DEFINE_FAKE_VOID_FUNC(rbdSessionMgr_NfcConnected,const rbdPk_NfcReaderId_t, const bool, const rbdPk_NfcDevicetype_t);
DEFINE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_CODE),Rte_Write_rbd_NFCVehIf_rbd_NFCVehIf_NFC_PhoneKeyPariring_Result_NFCPhoneKeyPariring_Result,NFC_PhoneKeyPariring_Result);
DEFINE_FAKE_VALUE_FUNC(rbdSessionMgr_Status_et, rbdSessionMgr_ProvisionCert_Async,uint8 const*, uint8* const, uint16_t);

# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
DEFINE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_CODE),Rte_Send_rbd_NFCVehIf_NFC_READER_REQ_FLDHM_Sig_NFC_READER_DEVICE_2_Sig,P2CONST(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_DATA), uint16);
# else
DEFINE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_CODE),Rte_Send_rbd_NFCVehIf_NFC_READER_REQ_FLDHM_Sig_NFC_READER_DEVICE_2_Sig,P2CONST(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_DATA), uint16);
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
DEFINE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_CODE),Rte_Send_rbd_NFCVehIf_NFC_READER_REQ_FRDHM_Sig_NFC_READER_DEVICE_3_Sig,P2CONST(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_DATA), uint16);
# else
DEFINE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_CODE),Rte_Send_rbd_NFCVehIf_NFC_READER_REQ_FRDHM_Sig_NFC_READER_DEVICE_3_Sig,P2CONST(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_DATA), uint16);
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
DEFINE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_CODE),Rte_Send_rbd_NFCVehIf_NFC_READER_REQ_WCPM2_Sig_NFC_READER_DEVICE_1_Sig,P2CONST(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_DATA), uint16);
# else
DEFINE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_CODE),Rte_Send_rbd_NFCVehIf_NFC_READER_REQ_WCPM2_Sig_NFC_READER_DEVICE_1_Sig,P2CONST(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_DATA), uint16);
# endif
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType, rbdSessionMgr_startNFCCardPairing,const rbdPk_NfcReaderId_t, const uint16, const uint8*);
// DEFINE_FAKE_VALUE_FUNC(rbdSessionMgr_Status_et, rbdSessionMgr_ProvisionCert_Async,uint8 const* ,uint8 const* ,uint16_t );


#ifdef RTE_PTR2ARRAYBASETYPE_PASSING
DEFINE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_CODE),Rte_Receive_rbd_NFCVehIf_NFC_READER_FLDHM_RES_Sig_NFC_READER_FLDHM_DEVICE_Sig,P2VAR(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR), P2VAR(uint16, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR));
# else
DEFINE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_CODE),Rte_Receive_rbd_NFCVehIf_NFC_READER_FLDHM_RES_Sig_NFC_READER_FLDHM_DEVICE_Sig,P2VAR(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR), P2VAR(uint16, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR));
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
DEFINE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_CODE),Rte_Receive_rbd_NFCVehIf_NFC_READER_FRDHM_RES_Sig_NFC_READER_FRDHM_DEVICE_Sig,P2VAR(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR), P2VAR(uint16, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR));
# else
DEFINE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_CODE),Rte_Receive_rbd_NFCVehIf_NFC_READER_FRDHM_RES_Sig_NFC_READER_FRDHM_DEVICE_Sig,P2VAR(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR), P2VAR(uint16, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR));
# endif
# ifdef RTE_PTR2ARRAYBASETYPE_PASSING
DEFINE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_CODE),Rte_Receive_rbd_NFCVehIf_NFC_READER_WCPM2_RES_Sig_NFC_READER_WCPM2_DEVICE_Sig,P2VAR(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR), P2VAR(uint16, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR));
# else
DEFINE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_CODE),Rte_Receive_rbd_NFCVehIf_NFC_READER_WCPM2_RES_Sig_NFC_READER_WCPM2_DEVICE_Sig,P2VAR(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR), P2VAR(uint16, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR));
# endif

DEFINE_FAKE_VOID_FUNC(rbd_RfhmIf_SendAuthStatus,boolean,const uint8 * , const uint8 * );

DEFINE_FAKE_VALUE_FUNC(FUNC(uint8, COM_CODE),Com_ReceiveSignal,Com_SignalIdType , P2VAR(void, AUTOMATIC, COM_APPL_VAR) );
DEFINE_FAKE_VOID_FUNC(rbd_RfhmIf_ControlFd9Bus,boolean );
DEFINE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, rbdDkmRteWrapper_CODE),Dkm_NfcFlow_Start,VAR(rbdPk_NfcReaderId_t, AUTOMATIC) , VAR(Dkm_OperationType_en, AUTOMATIC) , VAR(Dkm_DataFieldTag_en, AUTOMATIC) , VAR(uint8, AUTOMATIC) , VAR(uint16, AUTOMATIC) , VAR(Dkm_transactioncode_en, AUTOMATIC) , P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) , P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) );
DEFINE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_RBDDKMRTEWRAPPER_APPL_CODE),Dkm_GetKeyInfoDevice_Operation,IDT_KeyRef , P2VAR(rbdCdsTypes_KeyInfo_st, AUTOMATIC, RTE_RBDDKMRTEWRAPPER_APPL_VAR) );
DEFINE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_NVM_APPL_CODE),NvM_WriteBlock,NvM_BlockIdType , dtRef_const_VOID );
DEFINE_FAKE_VOID_FUNC(rbd_RfhmIf_ControlFd1Bus,boolean );
DEFINE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_RBDDKMRTEWRAPPER_APPL_CODE),Dkm_DeviceMgr_GetStatus_Operation,P2VAR(uint16, AUTOMATIC, RTE_RBDDKMRTEWRAPPER_APPL_VAR) );
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType,Dkm_GetNumberOfKeyEntries_Operation,rbdCdsTypes_DeviceType_en , uint8* , uint32 , uint8* );
//DEFINE_FAKE_VALUE_FUNC(Std_ReturnType,Dkm_GetKeyInfoCard_Operation,uint8 , rbdCdsTypes_KeyInfo_st* );
DEFINE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_RBDDKMRTEWRAPPER_APPL_CODE), Dkm_GetKeyInfoCard_Operation, uint8, P2VAR(rbdCdsTypes_KeyInfo_st, AUTOMATIC, RTE_RBDDKMRTEWRAPPER_APPL_VAR));
DEFINE_FAKE_VALUE_FUNC(Std_ReturnType,rbdDeviceMgr_GetStatus,uint16_t* );
DEFINE_FAKE_VOID_FUNC(rbd_VSM_WcpKeyAuthResult_Cbk, uint8, IDT_ConstUint8Ptr);
DEFINE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_CODE), Rte_Read_rbd_NFCVehIf_RP_AuthenticTimeManagementStatus_UtcTime, P2VAR(uint64, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) );
DEFINE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_RBD_BACKENDIF_APPL_CODE), rbd_BackendIf_BackendKeyStatusUpdate_Cbk, IDT_BackendKeyStatusUpdate , P2CONST(uint8, AUTOMATIC, RTE_RBD_BACKENDIF_APPL_DATA) );
DEFINE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_DEMSATELLITE_APP_COREA_SM_P1_APPL_CODE), Dem_SetEventStatus, Dem_EventIdType , Dem_EventStatusType );
DEFINE_FAKE_VALUE_FUNC(FUNC(Std_ReturnType, RTE_CODE),Rte_Read_rbd_NFCVehIf_RP_drmServices_drmServices,P2VAR(drmServices_Type, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) );
//============================================================================
// Static variable getter function definitions
//============================================================================
// <VAR TYPE> *const get_<VAR NAME>(void)
// {
//     return &<VAR NAME>;
// }


mock_nfcReaderDeselectInfo_t *const get_rbd_NFCVehIf_DeselectInfo_S(void)
{
    return &rbd_NFCVehIf_DeselectInfo_S;
}
nfcTagTableType *const get_rbd_NFCVehIf_Table_as(void)
{
    return &rbd_NFCVehIf_Table_as;
}
// boolean *const get_rbd_NFCVehIf_NfcCardTimerIsActive_b(void)
// {
//     return &rbd_NFCVehIf_NfcCardTimerIsActive_b;
// }Code removed
// nfcCardPairDataType *const get_rbd_NFCVehIf_CardData_st(void)
// {
//     return &rbd_NFCVehIf_CardData_st;
// }Code removed
uint16 *const get_rbd_NFCVehIf_NfcCardTimer_u16(void)
{
    return &rbd_NFCVehIf_NfcCardTimer_u16;
}
// uint8 *const get_rbd_NFCVehIf_NfcCardDefaultUid_au8(void)
// {
//     return &rbd_NFCVehIf_NfcCardDefaultUid_au8;
// }Code removed
// nfcCardUidDataType *const get_rbd_NFCVehIf_CardUid_st(void)
// {
//     return &rbd_NFCVehIf_CardUid_st;
// }
// nfcCardPairReqType *const get_rbd_NFCVehIf_CardPairReq_st(void)
// {
//     return &rbd_NFCVehIf_CardPairReq_st;
// }Code removed
NFC_READER_DEVICE_1_Sig *const get_rbd_NFCVehIf_Request_au8(void)
{
    return &rbd_NFCVehIf_Request_au8;
}
uint8 *const get_rbd_NFCVehIf_NfcCardSuccessUid_au8(void)
{
    return &rbd_NFCVehIf_NfcCardSuccessUid_au8;
}
rbdCdsTypes_KeyInfo_st *const get_keyInfo_S(void)
{
    return &keyInfo_S;
}
// boolean *const get_rbd_NFCVehIf_getUID_active_b(void)
// {
//     return &rbd_NFCVehIf_getUID_active_b;
// }Code removed
uint8 *const get_keyCardRef_paried_u8(void)
{
    return &keyCardRef_paried_u8;
}
nfcCard_Did5608_Info *const get_rbd_NFCVehIf_Did5608Info(void)
{
    return &rbd_NFCVehIf_Did5608Info;
}
uint8 *const get_rbd_NFCVehIf_CardIndex(void)
{
    return &rbd_NFCVehIf_CardIndex;
}
uint16 *const get_rbd_NFCVehIf_DTCWCPMTimer_u16(void)
{
    return &rbd_NFCVehIf_DTCWCPMTimer_u16;
}
boolean *const get_rbd_NFCVehIf_DTCWCMP2Timer_active_b(void)
{
    return &rbd_NFCVehIf_DTCWCMP2Timer_active_b;
}
uint16 *const get_rbd_NFCVehIf_PollingTimeoutTimer_u16(void)
{
    return &rbd_NFCVehIf_PollingTimeoutTimer_u16;
}
uint16 *const get_rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16(void)
{
    return &rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16;
}
mock_nfcRoutines_Info_t *const get_rbd_NFCVehIf_RoutineData_S(void)
{
    return &rbd_NFCVehIf_RoutineData_S;
}
uint16 *const get_rbd_NFCVehIf_EventFlag(void)
{
    return &rbd_NFCVehIf_EventFlag;
}
uint8 *const get_rbd_NFCVehIf_NFC_Count(void)
{
    return &rbd_NFCVehIf_NFC_Count;
}
// nfcRoutines_Info_t *const get_rbd_NFCVehIf_RoutineData_S(void)
// {
//     return &rbd_NFCVehIf_RoutineData_S;
// }
//============================================================================
// Static function wrapper definitions
//============================================================================
// <RETURN TYPE> call_<FUNCTION NAME>(<ARG0>, ...)
// {
//     return <FUNCTION NAME>(<ARG0>, ...);
// }
void call_rbd_NFCVehIf_Cyclic(void)
{
    rbd_NFCVehIf_Cyclic();
}
FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) call_rbd_NFCVehIf_GetNfcUID_Start_Start(P2VAR(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) ErrorCode)
{
    return rbd_NFCVehIf_GetNfcUID_Start_Start(Out_ResData,ErrorCode);
}
FUNC(void, rbd_NFCVehIf_CODE) call_rbd_NFCVehIf_Init(void)
{
    rbd_NFCVehIf_Init();
}
FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) call_rbd_NFCVehIf_NFC_Card_Pairing_Start_RequestResults(P2VAR(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) ErrorCode)
{
    return rbd_NFCVehIf_NFC_Card_Pairing_Start_RequestResults(Out_ResData,ErrorCode);
}
FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) call_rbd_NFCVehIf_NFC_Card_Pairing_Start_Start(P2CONST(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_DATA) In_ReqData, uint8 serialNumLen_u8, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) ErrorCode)
{
    return rbd_NFCVehIf_NFC_Card_Pairing_Start_Start(In_ReqData,serialNumLen_u8,ErrorCode);
}
FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) call_rbd_NFCVehIf_NFC_Card_Serial_Number_Read_Operation(P2VAR(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) Data)
{
    return rbd_NFCVehIf_NFC_Card_Serial_Number_Read_Operation(Data);
}
FUNC(void, rbd_NFCVehIf_CODE) call_rbd_NFCVehIf_NFC_READER_FLDHM_DEVICE_Sig_Callback(void)
{
    rbd_NFCVehIf_NFC_READER_FLDHM_DEVICE_Sig_Callback();
}
FUNC(void, rbd_NFCVehIf_CODE) call_rbd_NFCVehIf_NFC_READER_FRDHM_DEVICE_Sig_Callback(void)
{
    rbd_NFCVehIf_NFC_READER_FRDHM_DEVICE_Sig_Callback();
}
FUNC(void, rbd_NFCVehIf_CODE) call_rbd_NFCVehIf_NFC_READER_WCPM2_DEVICE_Sig_Callback(void)
{
    rbd_NFCVehIf_NFC_READER_WCPM2_DEVICE_Sig_Callback();
}
FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) call_rbd_NFCVehIf_Test_SmartCard_Pairing_Start_RequestResults(P2VAR(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) ErrorCode)
{
    return rbd_NFCVehIf_Test_SmartCard_Pairing_Start_RequestResults(Out_ResData,ErrorCode);
}
FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) call_rbd_NFCVehIf_Test_SmartCard_Pairing_Start_Start(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) ErrorCode)
{
    return rbd_NFCVehIf_Test_SmartCard_Pairing_Start_Start(ErrorCode);
}
void call_rbd_NFCVehIf_PrepNFCBuffer(uint8 *request_pt, const uint8 comId_u8, const uint8 dest_u8, const uint16 payLen_u16, const uint8* payload_pt)
{
    rbd_NFCVehIf_PrepNFCBuffer(&request_pt, comId_u8, dest_u8, payLen_u16,&payload_pt);
}
Std_ReturnType call_rbd_NFCVehIf_WritePort(const uint8 dest_u8, const uint8 *request_pt, const uint16 length_u16)
{
    return rbd_NFCVehIf_WritePort(dest_u8,request_pt,length_u16);
}
uint8 call_rbd_NFCVehIf_MapCCCToNFC(const uint16 cccCommandId_u16)
{
    return rbd_NFCVehIf_MapCCCToNFC(cccCommandId_u16);
}
void call_rbd_NFCVehIf_SetOwnerPairingMode(boolean const Enable)
{
    rbd_NFCVehIf_SetOwnerPairingMode(Enable);
}
void call_rbd_NFCVehIf_NfcTeardown(const rbdPk_NfcReaderId_t nfcReaderId)
{
    rbd_NFCVehIf_NfcTeardown(nfcReaderId);
}
boolean call_rbd_NFCVehIf_SendNfcMsg(const rbdPk_NfcReaderId_t nfcReaderId, const uint16 Length, const uint8* const Data)
{
    return rbd_NFCVehIf_SendNfcMsg(nfcReaderId,Length, &Data);
}
void call_rbd_NFCVehIf_ReceiveNFCResponse(const uint8 *nfcResponse_pt, const uint16 nfcResponseLength_u16)
{
    rbd_NFCVehIf_ReceiveNFCResponse(nfcResponse_pt,nfcResponseLength_u16);
}
void call_rbd_NFCVehIf_ProcessCCCResponse(const uint8 *nfcResponse_pt)
{
    rbd_NFCVehIf_ProcessCCCResponse(nfcResponse_pt);
}
void call_rbd_NFCVehIf_DkmStartPolling(const rbdPk_NfcReaderId_t nfcReaderId, const uint8* const DigitalKeyFrameworkId)
{
    rbd_NFCVehIf_DkmStartPolling(nfcReaderId,DigitalKeyFrameworkId);
}
 Std_ReturnType call_rbd_NFCVehIf_NfcFlow_NotifyAuthStatus(rbdPk_NfcReaderId_t ReaderId, Dkm_CccAuthStatus_en* CccAuthStatus, uint8 * DeviceRef)
 {
    return rbd_NFCVehIf_NfcFlow_NotifyAuthStatus(ReaderId , CccAuthStatus , DeviceRef);
 }
 void call_rbd_NFCVehIf_NfcFlow_FLDHM_AuthNotification(Dkm_CccAuthStatus_en Dkm_AuthStatus_en, uint8 DevRef_u8)
 {
    rbd_NFCVehIf_NfcFlow_FLDHM_AuthNotification( Dkm_AuthStatus_en,  DevRef_u8);
 }
void call_rbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification(Dkm_CccAuthStatus_en Dkm_AuthStatus_en, uint8 DevRef_u8)
{
    rbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification( Dkm_AuthStatus_en,  DevRef_u8);
}
FUNC(void, rbd_NFCVehIf_CODE) call_rbd_NFCVehIf_SendStopTrigger(void)
{
    rbd_NFCVehIf_SendStopTrigger();
}
FUNC(void, rbd_NFCVehIf_CODE) call_rbd_NFCVehIf_SendStartTrigger(void)
{
    rbd_NFCVehIf_SendStartTrigger();
}
void call_rbd_NfcIf_NfcTapThread(void)
{
    rbd_NfcIf_NfcTapThread();
}
uint8 call_rbd_NFCVehIf_ResetNFCReaderSessionTag( const uint8 NfcReaderId_u8 )
{
    return rbd_NFCVehIf_ResetNFCReaderSessionTag(NfcReaderId_u8 );
}
uint8 call_rbd_NFCVehIf_RegisterNFCReaderSession( const uint8 NfcReaderId_u8 )
{
    return rbd_NFCVehIf_RegisterNFCReaderSession( NfcReaderId_u8 );
}
uint8 call_rbd_NFCVehIf_UpdateNFCReaderState( const uint8 NfcReaderId_u8, const uint8 newState_u8, const uint8 * newDevRef_pu8)
{
   return rbd_NFCVehIf_UpdateNFCReaderState(  NfcReaderId_u8, newState_u8, newDevRef_pu8);
}
void call_rbd_NFCVehIf_ReadNFCReaderStatusInfo( const uint8 NfcReaderId_u8,uint8 *sessionState_u8, uint8 *readerConnectState_u8, uint8 *deviceRef_u8 )
{
     rbd_NFCVehIf_ReadNFCReaderStatusInfo(  NfcReaderId_u8,sessionState_u8, readerConnectState_u8, deviceRef_u8 );
}
FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) call_rbd_NFCVehIf_GetNfcUID_Start_RequestResults(P2VAR(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) ErrorCode)
{
   return rbd_NFCVehIf_GetNfcUID_Start_RequestResults( Out_ResData,  ErrorCode);
}
FUNC(void, rbd_NFCVehIf_CODE) call_rbd_NFCVehIf_ToggleOperationFinished(void)
{
    rbd_NFCVehIf_ToggleOperationFinished();
}

FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) call_rbd_NFCVehIf_NFC_Card_Serial_Number_Read_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) ErrorCode)
{
    return rbd_NFCVehIf_NFC_Card_Serial_Number_Read_ConditionCheckRead(OpStatus, ErrorCode);
}
void call_rbd_NFCVehIf_UpdateNFCReaderSessionTimeOut( const uint8 NfcReaderId_u8, const uint16 sessionTout_u16)
{
    rbd_NFCVehIf_UpdateNFCReaderSessionTimeOut( NfcReaderId_u8, sessionTout_u16);
}

void call_rbd_NFCVehIf_NFCReaderSessionTimeOutManager(void)
{
    rbd_NFCVehIf_NFCReaderSessionTimeOutManager();
}
FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) call_rbd_NFCVehIf_WcpKeyAuthReq_Cbk(void)
{
    return rbd_NFCVehIf_WcpKeyAuthReq_Cbk();
}
void call_rbd_NfcIf_NfcReaderCanTPPacketHeaderRead(const uint8 * packetDataIn, mock_nfcReaderResponseHeader_t * nfcReaderDataHeader_ps)
{
    rbd_NfcIf_NfcReaderCanTPPacketHeaderRead(packetDataIn, nfcReaderDataHeader_ps);
}
void call_rbd_NfcIf_NfcReaderCanTPPacketHeaderWrite(uint8 * packetDataOut, const mock_nfcReaderResponseHeader_t *  nfcReaderDataHeader_ps)
{
    rbd_NfcIf_NfcReaderCanTPPacketHeaderWrite(packetDataOut, nfcReaderDataHeader_ps);
}
// void call_rbd_NFCVehIf_checkDkmCardPairingRequest( void )
// {
//     rbd_NFCVehIf_checkDkmCardPairingRequest();
// } Code removed
void call_rbd_NFCVehIf_DTC(void)
{
    rbd_NFCVehIf_DTC();
}
uint8 call_rbd_NFCVehIf_IsRoutineInProgress(void)
{
    return rbd_NFCVehIf_IsRoutineInProgress();
}
void call_rbd_NfcIf_TapStartTriggerCyclic(void)
{
    rbd_NfcIf_TapStartTriggerCyclic();
}
void call_rbd_NFCVehIf_CardPairingRoutine_Cyclic(void)
{
    rbd_NFCVehIf_CardPairingRoutine_Cyclic();
}