/**********************************************************************************************************************
 *  FILE REQUIRES USER MODIFICATIONS
 *  Template Scope: sections marked with Start and End comments
 *  -------------------------------------------------------------------------------------------------------------------
 *  This file includes template code that must be completed and/or adapted during BSW integration.
 *  The template code is incomplete and only intended for providing a signature and an empty implementation.
 *  It is neither intended nor qualified for use in series production without applying suitable quality measures.
 *  The template code must be completed as described in the instructions given within this file and/or in the.
 *  Technical Reference.
 *  The completed implementation must be tested with diligent care and must comply with all quality requirements which.
 *  are necessary according to the state of the art before its use.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  rbd_NFCVehIf.c
 *           Config:  D:/1.Anushree/Sandbox/PK_FCA_GIT_Latest/rbd/pk/fca/MasterMcu/AIM/BSW/Autosar/PK_FCA.dpa
 *        SW-C Type:  rbd_NFCVehIf
 *  Generation Time:  2023-03-07 14:00:36
 *
 *        Generator:  MICROSAR RTE Generator Version 4.23.0
 *                    RTE Core Version 1.23.0
 *          License:  CBD2100060
 *
 *      Description:  C-Code implementation template for SW-C <rbd_NFCVehIf>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_MSR_Rule5.1, MD_MSR_Rule5.2 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * Dcm_NegativeResponseCodeType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * Dcm_NegativeResponseCodeType
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 * Spaak
 *   uint8 represents integers with a minimum value of 0 and a maximum value of 255.
 *      The order-relation on uint8 is: x < y if y - x is positive.
 *      uint8 has a lexical representation consisting of a finite-length sequence
 *      of decimal digits (#x30-#x39).
 *
 *      For example: 1, 0, 126, +10.
 *
 *********************************************************************************************************************/

#include "Rte_rbd_NFCVehIf.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

//============================================================================
// Local Includes
//============================================================================
#include "string.h"
#include "rbd_NFCVehIf.h"
#include "rbd_RfhmIf.h"
#include "rbdVehIf_Api.h"

#include "rbdSessionMgr_Api_Nfc.h"

#  ifdef RTE_APPLICATION_HEADER_FILE
#undef RTE_APPLICATION_HEADER_FILE
#endif
#include "rbdDeviceMgr_Api.h"
#include "Rte_Type.h"
//============================================================================
// Local Macros
//============================================================================
/** @brief The timespacing between two DESELECT retries if first DESELECT retry is not answered. Unit in seconds */
/*AXIVION Disable MisraC2012Directive-4.1: Cal Param Rte_CData_KE_SPAAK_DeselectTimeout() range is 0 to 10 sec, so it won't overflow */
#define NFC_DESELECT_RETRY_TIMEOUT					(Rte_CData_KE_SPAAK_DeselectTimeout() * 1000U)
/** @brief NFC Card Pairing Routine Timoeut. Unit in seconds */
/*AXIVION Disable MisraC2012Directive-4.1: Cal Param Rte_CData_KE_SPAAK_SCPairingTimeout() range is 0 to 40 sec, so it won't overflow */
#define NFC_CARD_PAIRING_TIMEOUT					(Rte_CData_KE_SPAAK_SCPairingTimeout() * 1000u)
/** @brief NFC Test Card Pairing Routine Timoeut. Unit in seconds */
/*AXIVION Disable MisraC2012Directive-4.1: Cal Param Rte_CData_KE_SPAAK_TestSCPairingTimeout() range is 0 to 40 sec, so it won't overflow */
#define NFC_TEST_CARD_PAIRING_TIMEOUT				(Rte_CData_KE_SPAAK_TestSCPairingTimeout() * 1000u)
/** @brief NFC Test Card Pairing/Test Card Pairing Routine Polling Retry Timoeut. Unit in seconds */
/*AXIVION Disable MisraC2012Directive-4.1: Cal Param Rte_CData_KE_StartPollingTimeout() range is 0 to 20 sec, so it won't overflow */
#define NFC_CARD_PAIRING_POLLING_RETRY_TIMEOUT		(Rte_CData_KE_StartPollingTimeout() * 1000u)
/** @brief Get UID Routine Polling Timeout. Unit in ms */
/*AXIVION Disable MisraC2012Directive-4.1: Cal Param Rte_CData_KE_NfcGetUIDPollingTimer() range is 0 to 5000 msec, so it won't overflow */
#define NFC_GET_UID_POLLING_TIMEOUT					(Rte_CData_KE_NfcGetUIDPollingTimer())
/** @brief Vehicle start Polling response Timer ms */
/*AXIVION Disable MisraC2012Directive-4.1: Cal Param Rte_CData_KE_SPAAK_NfcVehicleStartPollingTimer() range is 0 to 5000 msec, so it won't overflow */
#define NFC_VEH_START_POLLING_TIMEOUT				(Rte_CData_KE_SPAAK_NfcVehicleStartPollingTimer())
//============================================================================
// Local Typedefs
//============================================================================
typedef enum
{
	/** @brief DOOR Status is locked */
    DOOR_STAT_LOCKED_EN 	= 0x00U,
	/** @brief DOOR Status is driver unlocked */
	DOOR_STAT_DRV_UNLOCK_EN = 0x01U,
	/** @brief DOOR Status is all door unlocked */
	DOOR_STAT_ALL_UNLOCK_EN = 0x02U,
	/** @brief DOOR Status signal not available */
	DOOR_STAT_SNA_EN 		= 0x03U,
	/** @brief DOOR Status signal not available */
	DOOR_STAT_INVALID_E		= 0x0Fu,
} NfcVehIf_Door_Stat_EN_TYPE;

typedef enum
{
	/** @brief Reader Default State*/
	NFC_READER_NOT_ACTIVE_STATE_E 						= 0x00u,

	/*!< Tap Entry Flow Reader(FLDHM) states >!*/
	/** @brief NFC Tap Entry Flow Initiated */
	NFC_READER_TAP_ENTRY_FLOW_INIT_STATE_E 				= 0x01u,
	/** @brief NFC Tap Entry Flow Card Auth Success */
	NFC_READER_TAP_ENTRY_CARD_AUTH_SUCCESS_STATE_E 		= 0x02u,
	/** @brief NFC Tap Entry Flow Card Auth Failure */
	NFC_READER_TAP_ENTRY_CARD_AUTH_FAILED_STATE_E 		= 0x03u,
	/** @brief NFC Tap Entry Flow Phone Auth Success */
	NFC_READER_TAP_ENTRY_DEVICE_AUTH_SUCCESS_STATE_E 	= 0x04u,
	/** @brief NFC Tap Entry Flow Phone Auth Failure */
	NFC_READER_TAP_ENTRY_DEVICE_AUTH_FAILED_STATE_E		= 0x05u,
	/** @brief NFC Tap Entry Toggle Response Waiting State */
	NFC_READER_TAP_ENTRY_TOGGLE_RSP_WAIT_STATE_E		= 0x06u,
	/** @brief NFC Tap Entry Auth Success, Device Info Wait state */
	NFC_READER_TAP_ENTRY_DEVICE_INFO_WAIT_STATE_E 		= 0x07u,
	/** @brief NFC Tap Entry Tear down Normal State */
	NFC_READER_TAP_ENTRY_TEAR_DOWN_STATE_E 				= 0x08u,
	/* If New states for Tap Entry are required then add above this comment*/

	/*!< Tap Start Flow Reader(WCPM2) states >!*/
	/** @brief NFC Tap Entry Flow Initiated */
	NFC_READER_TAP_START_FLOW_INIT_STATE_E				= 0x10u,
	/** @brief NFC Tap Start Flow Card Auth Success */
	NFC_READER_TAP_START_CARD_AUTH_SUCCESS_STATE_E		= 0x11u,
	/** @brief NFC Tap Start Flow Card Auth Failure */
	NFC_READER_TAP_START_CARD_AUTH_FAILED_STATE_E		= 0x12u,
	/** @brief NFC Tap Start Flow Phone Auth Success */
	NFC_READER_TAP_START_DEVICE_AUTH_SUCCESS_STATE_E	= 0x13u,
	/** @brief NFC Tap Start Flow Phone Auth Failure */
	NFC_READER_TAP_START_DEVICE_AUTH_FAILED_STATE_E		= 0x14u,
	/** @brief NFC Tap Start Auth Success, Device Info Wait state */
	NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E 		= 0x15u,
	/** @brief NFC Tap START Tear down Normal State */
	NFC_READER_TAP_START_TEAR_DOWN_STATE_E 				= 0x16u,
	/** @brief NFC Tap START Stop Trigger received from Rfhmif */
	NFC_READER_TAP_START_STOP_TRIGGER_STATE_E 			= 0x17u,
	/** @brief NFC Tap START Stop Trigger received from Rfhmif */
	NFC_READER_TAP_START_RFHM_TRIGGER_RX_STATE_E		= 0x18u,
	/* If New states for Tap Start are required then add above this comment*/

	/*!< Owner Pairing Flow Reader(WCPM2) states including FFA >!*/
	/** @brief Owner Pairing Flow Ongoing */
	NFC_READER_OWNER_PAIRING_STATE_E					= 0x20u,
	/** @brief Owner Pairing Tear Down state */
	NFC_READER_OWNER_PAIRING_TEAR_DOWN_STATE_E			= 0x21u,
	/* If New states for Owner Pairing are required then add above this comment*/

	/*!< Card Pant Pairing Flow Reader(WCPM2) states >!*/
	/** @brief Card Plant Pairing Flow Ongoing */
	NFC_READER_CARD_PLANT_PAIR_STATE_E					= 0x30u,
	/** @brief Owner Pairing Tear Down state */
	NFC_READER_CARD_PLANT_PAIR_TEAR_DOWN_STATE_E		= 0x31u,
	/* If New states for Card Pairing are required then add above this comment*/

	/*!< Test Card Pairing Flow Reader(WCPM2) states >!*/
	/** @brief Card Plant Test Flow Ongoing */
	NFC_READER_CARD_PLANT_TEST_STATE_E					= 0x40U,
	/** @brief NFC Test CARD PAIRING Tear Down state */
	NFC_READER_CARD_PLANT_TEST_TEAR_DOWN_STATE_E		= 0x41u,
	/* If New states for Test Card Pairing are required then add above this comment*/

	/*!< Get UID (WCPM2) states >!*/
	/** @brief Get UUID Flow Ongoing */
	NFC_READER_GET_UID_STATE_E							= 0x50u,
	/** @brief NFC Get UID Tear Down state */
	NFC_READER_GET_UID_TEAR_DOWN_STATE_E				= 0x51u,
	/* If New states for Get UID are required then add above this comment*/

	/*!< HeadUnit Triggred Enable Disable(WCPM2) states >!*/
    /** @brief HU triggered Phone enable/disable WCP authentication on going */
	NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_INIT_STATE_E	= 0x60u,
	 /** @brief HU triggered Phone enable/disable WCP authentication finished */
	NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_FINISH_STATE_E	= 0x61u,
	/* If New states for HeadUnit Triggered Enable_Disable are required then add above this comment*/

	/*!< Max State. Add any new states before this enum>!*/
	NFC_READER_MAX_STATE_E,
} NfcVehIf_NfcSession_State_EN_TYPE;

typedef enum
{
	/** @brief NFC Reader DESELECT NORMAL type*/
	NFC_READER_DESELECT_NORMAL_TYPE_E 						= 0x00u,
	/** @brief NFC Reader DESELECT DISABLE type*/
	NFC_READER_DESELECT_DISABLE_TYPE_E 						= 0x01u,
}NfcVehIf_NfcReader_DESELECT_EN_TYPE;

typedef enum
{
	/** @brief Routine status is uninitialized*/
	NFC_ROUTINE_STATUS_UNINITIALIZED_E 			= 0x00u,
	/** @brief Routine status is Success*/
	NFC_ROUTINE_STATUS_SUCCESS_E				= 0x01u,
	/** @brief Routine status is in progress*/
	NFC_ROUTINE_STATUS_IN_PROGRESS_E			= 0x02u,
	/** @brief Routine status is failure*/
	NFC_ROUTINE_STATUS_FAILURE_E       			= 0x03u,
}NfcVehIf_RoutineStatus_EN_TYPE; /*AXIVION Disable MisraC2012-2.3 the enumeration IDs are used in the code */

typedef enum
{
	/** @brief Routine type is Card pairing*/
	NFC_ROUTINE_GROUP_PLANT_PAIRING_E 					= 0x00u,
	/** @brief Routine type is Test Card pairing*/
	NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E 				= 0x01u,
	/** @brief Routine type is get UID*/
	NFC_ROUTINE_GROUP_GET_UID_E 						= 0x02u,

	/** @brief Max State*/
	NFC_ROUTINE_GROUP_MAX_E,
}NfcVehIf_RoutineGroup_EN_TYPE;

typedef enum
{
	/** @brief Routine Init State */
	NFC_DIAG_ROUTINE_INIT_STATE_E,
	/** @brief Routine Request Received State */
	NFC_DIAG_ROUTINE_REQUEST_RX_STATE_E,
	/** @brief Routine State FD9 Bus Active */
	NFC_DIAG_ROUTINE_FD9_ACTIVE_STATE_E,
	/** @brief Routine State -Routine in Running State */
	NFC_DIAG_ROUTINE_RUNNING_STATE_E,
	/** @brief Routine State FD9 Bus Not Active */
	NFC_DIAG_ROUTINE_FD9_DEINIT_STATE_E,
}NfcVehIf_DiagRoutineStates_EN_TYPE;

typedef struct
{
	uint8 cmdId_u8;			 	/*!< Command Id */
	uint8 rxEcu_u8;				/*!< Receiver ECU */
	uint8 txEcu_u8;				/*!< Transmitter ECU */
	uint16 payloadLength_u16;	/*!< Payload Length */
}nfcReaderResponseHeader_t;

typedef struct
{
	uint8 reqRetryCount_u8;			/*!< Deselect Request Retry count in case of failure */
	uint8 uRetryFinish_u8;   		/*!< Max attempts Reached */
	uint8 typeDeselect_u8;			/*!< Deselect Type */
	NfcEcuIds nfcReaderId_en;		/*!< NFC ReaderId */
	uint16 retryTimer_u32;

}nfcReaderDeselectInfo_t;

typedef struct
{
	uint8 nfcCardIdx;									/* 1 byte of cardIndex 			*/
	Rte_DT_rbdCdsTypes_NfcCardDat_st_1 nfcCardUid;		/* 7 bytes of UID 				*/
	sha1HashCetH keyIdentifier;							/* 20 bytes of keyIdentifier    */
	Rte_DT_rbdCdsTypes_KeyInfo_st_5 keyFriendlyName;	/* 30 bytes of key name 		*/
	Rte_DT_rbdCdsTypes_NfcCardDat_st_2 nfcCardSerNum;	/* 15 bytes of Serial Number 	*/
}nfcCard_Did5608_Info_t;

typedef struct
{
	uint8 nfcRoutineStatus;			/*!< 1 byte of cardIndex 			*/
	uint8 nfcRoutineErrorCode;		/*!< 7 bytes of UID 				*/
	uint8 nfcRoutineKeyRef;			/*!< Store the Key Ref if required */
	NfcVehIf_DiagRoutineStates_EN_TYPE DiagRoutine_State_en;	/*!< Routine State */
	/*AXIVION Disable MisraC2012-19.2: The union members nfcRoutineUId and nfcRoutineSerialNumber are not used the same time */
	union
	{
			uint8 nfcRoutineUId[NFC_CARD_UID_LEN];	/*!< Card UID of the Routine in process */
			uint8 nfcRoutineSerialNumber[NFC_SERIAL_LEN];	/*!< Card Serial Number of the Routine in process */
	}nfcCardData_t;
}nfcRoutines_Info_t;

typedef void (*rbd_NFCVehIf_NfcReaderAuthNotification_fp) (Dkm_CccAuthStatus_en Dkm_AuthStatus_en, uint8 DevRef_u8);
//============================================================================
// Local Variables
//============================================================================
/*! \var static nfcTagTableType rbd_NFCVehIf_Table_as Array that maintains a table for current NFC sessions */
static nfcTagTableType rbd_NFCVehIf_Table_as[NFC_NUM_READERS];

/*! \var static uint8 rbd_NFCVehIf_NfcCardSuccessUid_au8 Array that maintains a UID of the Card, retrieved from SELECT response */
static uint8 rbd_NFCVehIf_NfcCardSuccessUid_au8[NFC_CARD_UID_LEN];

/*! \var static nfcRoutines_Info_t rbd_NFCVehIf_RoutineData_S Array maintaining the Routine Status */
static nfcRoutines_Info_t rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_MAX_E];

/*! \var static uint16 rbd_NFCVehIf_NfcCardTimer_u16 NFC Card timer while waiting operation(e.g pairing) to get finished */
static uint16 rbd_NFCVehIf_NfcCardTimer_u16 = 0x00;

/*! \var static uint16 rbd_NFCVehIf_PollingTimeoutTimer_u16 Timer to restartpolling in case of card Pairing and Test Card Pairing routines */
static uint16 rbd_NFCVehIf_PollingTimeoutTimer_u16 = 0x00;

/*! \var static uint8 rbd_NFCVehIf_RoutineRetryPolling_u8 flag to restart polling in case of card Pairing and Test Card Pairing routines */
static uint8 rbd_NFCVehIf_RoutineRetryPolling_u8 = FALSE;

/*! \var static uint16 rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 Timer to count polling response time in case of tap start */
static uint16 rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 = 0x00;

/*! \var static uint16 rbd_NFCVehIf_DTCWCPMTimer_u16 WCPM Communication Failure Timer */
static uint16 rbd_NFCVehIf_DTCWCPMTimer_u16 = 0x00;

/*! \var boolean rbd_NFCVehIf_DTCWCMP2Timer_active_b WCPM communication failure active Timer flag*/
static boolean rbd_NFCVehIf_DTCWCMP2Timer_active_b = FALSE;

/*! \var static uint16 rbd_NFCVehIf_NfcCardTimer_u16 NFC Card timer while waiting operation(e.g pairing) to get finished */
static NFC_READER_DEVICE_1_Sig rbd_NFCVehIf_Request_au8;

/*! \var static rbdCdsTypes_KeyInfo_st keyInfo_S KeyInfo global storage */
static rbdCdsTypes_KeyInfo_st keyInfo_S = { 0 };

/*! \var static uint8 rbd_NFCVehIf_NFC_Count Active NFC count/devices */
static uint8 rbd_NFCVehIf_NFC_Count = 0u;

/*! \var static uint8 rbd_NFCVehIf_CardIndex Card Index */
static uint8 rbd_NFCVehIf_CardIndex = 0;

/*! \var static uint8 keyCardRef_paried_u8 No of devices Paired */
static uint8 keyCardRef_paried_u8 = 0;

/*! \var static nfcCard_Did5608_Info_t rbd_NFCVehIf_Did5608Info Array Containing the DID5608 information */
static nfcCard_Did5608_Info_t rbd_NFCVehIf_Did5608Info[10] = { 0 };

/*! \var static nfcReaderDeselectInfo_t rbd_NFCVehIf_DeselectInfo_S DESELECT Retry Information */
static nfcReaderDeselectInfo_t rbd_NFCVehIf_DeselectInfo_S	= { 0 };

/*! \var static uint16 rbd_NFCVehIf_EventFlag Global Flag holding NFC operaion events */
static uint16 rbd_NFCVehIf_EventFlag = 0x00u;

/* ToDO - Start Intermediate Code until DKM fix for FFA is available */

/*! \var static uint8 DevKeyListCount_u8 Digital Key Device Count */
static uint8 DevKeyListCount_u8 = 0u;

/*! \var static IDT_KeyRef DevKeyRefList_au8 Array containing digital Key Refs */
static IDT_KeyRef DevKeyRefList_au8[32u];

/* ToDO - End Intermediate Code until DKM fix for FFA is available */
//============================================================================
// Extern Functions
//============================================================================

//============================================================================
// Static Functions
//============================================================================
static void rbd_NfcIf_NfcTapThread(void);
static void rbd_NfcIf_NfcReaderCanTPPacketHeaderRead(const uint8 * packetDataIn, nfcReaderResponseHeader_t *  nfcReaderDataHeader_ps);
static void rbd_NfcIf_NfcReaderCanTPPacketHeaderWrite(uint8 * packetDataOut, const nfcReaderResponseHeader_t *  nfcReaderDataHeader_ps);
static void rbd_NFCVehIf_ReadNFCReaderStatusInfo(const uint8 NfcReaderId_u8, uint8 * sessionState_u8, uint8 * readerConnectState_u8, uint8 * deviceRef_u8);
static uint8 rbd_NFCVehIf_UpdateNFCReaderState( const uint8 NfcReaderId_u8, const uint8 newState_u8, const uint8 * newDevRef_pu8);
static uint8 rbd_NFCVehIf_ResetNFCReaderSessionTag(const uint8 NfcReaderId_u8);
static uint8 rbd_NFCVehIf_RegisterNFCReaderSession(const uint8 NfcReaderId_u8);

static void rbd_NFCVehIf_PrepNFCBuffer(uint8 *request_pt, const uint8 comId_u8, const uint8 dest_u8, const uint16 payLen_u16, const uint8* payload_pt);
static Std_ReturnType rbd_NFCVehIf_WritePort(const uint8 dest_u8, const uint8* request_pt, const uint16 length_u16);
static uint8 rbd_NFCVehIf_MapCCCToNFC(const uint16 cccCommandId_u16);
static void rbd_NFCVehIf_NfcStartPolling(const uint8 ecuRx_u8, const uint8* const DigitalKeyFrameworkId);
static void rbd_NFCVehIf_ReceiveNFCResponse(const uint8 *nfcResponse_pt, const uint16 nfcResponseLength_u16);
static void rbd_NFCVehIf_ProcessCCCResponse(const uint8 *nfcResponse_pt);
static void rbd_NFCVehIf_NfcFlow_FLDHM_AuthNotification(Dkm_CccAuthStatus_en Dkm_AuthStatus_en, uint8 DevRef_u8);
static void rbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification(Dkm_CccAuthStatus_en Dkm_AuthStatus_en, uint8 DevRef_u8);
static void rbd_NFCVehIf_UpdateNFCReaderSessionTimeOut( const uint8 NfcReaderId_u8,const uint16 sessionTout_u16);
static void rbd_NFCVehIf_NFCReaderSessionTimeOutManager(void);
static void rbd_NFCVehIf_DESELECT_TimerRetry_Reload(const NfcEcuIds readerId, const NfcVehIf_NfcReader_DESELECT_EN_TYPE deselect_type_en, const uint8 retryCount_u8);
static void rbd_NFCVehIf_Deselect_TxManager_Cyclic(void);
static uint8 rbd_NFCVehIf_IsDeselectRetryTmr_Expired(void);
static void rbd_NFCVehIf_DTC(void);
static void rbd_NFCVehIf_CardPairingRoutine_Cyclic(void);
static void rbd_NFCVehIf_TestCardPairingRoutine_Cyclic(void);
static void rbd_NFCVehIf_GetUIDRoutine_Cyclic(void);
static uint16 rbd_NFCVehIf_ReadEventWord(void);
static void rbd_NFCVehIf_ClearEvent(uint16 eventType_u16);
static void rbd_NFCVehIf_SetEvent(uint16 eventType_u16);
static uint8 rbd_NFCVehIf_IsRoutineInProgress(void);
static void rbd_NfcIf_TapStartTriggerCyclic( void );
static boolean rbd_NfcIf_IsSelectResponseForCard(const uint8* data_pu8, uint16 msgLen_u16, uint8 * uid_u8);
static uint8 rbd_NfcIf_ReadTagAndLength(uint16* detected_tag_u16, uint16* detected_tag_len_u16, const uint8* data_in_pu8, uint16 dataLen_u16);

static const rbd_NFCVehIf_NfcReaderAuthNotification_fp rbd_NFCVehIf_NfcReaderAuthNotification_FuncTable[NFC_NUM_READERS] =
		{
			rbd_NFCVehIf_NfcFlow_FLDHM_AuthNotification,
			NULL, /* rbd_NFCVehIf_NfcFlow_FRDHM_AuthNotification, *//* Enable FRDHM when it it becomes relevant */
			rbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification
		};

/*AXIVION Disable Style MisraC2012-20.1 : Deviation InternalBosch_20_1_A - Auto-generated Da Vinci Files */
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * PhysicalKeyVehicleCertLength: Integer in interval [0...65535]
 * PhysicalVehCertPrivateKeyLength: Integer in interval [0...255]
 * PhysicalVehicleOEMCertLength: Integer in interval [0...65535]
 * Rte_DT_PhysicalKeyVehicleCertificate_0: Integer in interval [0...255]
 * Rte_DT_PhysicalVehCertPrivateKey_0: Integer in interval [0...255]
 * Rte_DT_PhysicalVehicleOEMCertificate_0: Integer in interval [0...255]
 * Spaak: Integer in interval [0...1]
 * uint8: Integer in interval [0...255] (standard type)
 *
 * Enumeration Types:
 * ==================
 * Dcm_NegativeResponseCodeType: Enumeration of integer in interval [0...255] with enumerators
 *   DCM_E_POSITIVERESPONSE (0U)
 *   DCM_E_GENERALREJECT (16U)
 *   DCM_E_SERVICENOTSUPPORTED (17U)
 *   DCM_E_SUBFUNCTIONNOTSUPPORTED (18U)
 *   DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT (19U)
 *   DCM_E_RESPONSETOOLONG (20U)
 *   DCM_E_BUSYREPEATREQUEST (33U)
 *   DCM_E_CONDITIONSNOTCORRECT (34U)
 *   DCM_E_REQUESTSEQUENCEERROR (36U)
 *   DCM_E_NORESPONSEFROMSUBNETCOMPONENT (37U)
 *   DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION (38U)
 *   DCM_E_REQUESTOUTOFRANGE (49U)
 *   DCM_E_SECURITYACCESSDENIED (51U)
 *   DCM_E_AUTHENTICATIONREQUIRED (52U)
 *   DCM_E_INVALIDKEY (53U)
 *   DCM_E_EXCEEDNUMBEROFATTEMPTS (54U)
 *   DCM_E_REQUIREDTIMEDELAYNOTEXPIRED (55U)
 *   DCM_E_CVF_INVALIDTIMEPERIOD (80U)
 *   DCM_E_CVF_INVALIDSIGNATURE (81U)
 *   DCM_E_CVF_INVALIDCHAINOFTRUST (82U)
 *   DCM_E_CVF_INVALIDTYPE (83U)
 *   DCM_E_CVF_INVALIDFORMAT (84U)
 *   DCM_E_CVF_INVALIDCONTENT (85U)
 *   DCM_E_CVF_INVALIDSCOPE (86U)
 *   DCM_E_CVF_INVALIDCERTIFICATEREVOKED (87U)
 *   DCM_E_OWNERSHIPVERIFICATIONFAILED (88U)
 *   DCM_E_CHALLENGECALCULATIONFAILED (89U)
 *   DCM_E_UPLOADDOWNLOADNOTACCEPTED (112U)
 *   DCM_E_TRANSFERDATASUSPENDED (113U)
 *   DCM_E_GENERALPROGRAMMINGFAILURE (114U)
 *   DCM_E_WRONGBLOCKSEQUENCECOUNTER (115U)
 *   DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING (120U)
 *   DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION (126U)
 *   DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION (127U)
 *   DCM_E_RPMTOOHIGH (129U)
 *   DCM_E_RPMTOOLOW (130U)
 *   DCM_E_ENGINEISRUNNING (131U)
 *   DCM_E_ENGINEISNOTRUNNING (132U)
 *   DCM_E_ENGINERUNTIMETOOLOW (133U)
 *   DCM_E_TEMPERATURETOOHIGH (134U)
 *   DCM_E_TEMPERATURETOOLOW (135U)
 *   DCM_E_VEHICLESPEEDTOOHIGH (136U)
 *   DCM_E_VEHICLESPEEDTOOLOW (137U)
 *   DCM_E_THROTTLE_PEDALTOOHIGH (138U)
 *   DCM_E_THROTTLE_PEDALTOOLOW (139U)
 *   DCM_E_TRANSMISSIONRANGENOTINNEUTRAL (140U)
 *   DCM_E_TRANSMISSIONRANGENOTINGEAR (141U)
 *   DCM_E_BRAKESWITCH_NOTCLOSED (143U)
 *   DCM_E_SHIFTERLEVERNOTINPARK (144U)
 *   DCM_E_TORQUECONVERTERCLUTCHLOCKED (145U)
 *   DCM_E_VOLTAGETOOHIGH (146U)
 *   DCM_E_VOLTAGETOOLOW (147U)
 *   DCM_E_VMSCNC_0 (240U)
 *   DCM_E_VMSCNC_1 (241U)
 *   DCM_E_VMSCNC_2 (242U)
 *   DCM_E_VMSCNC_3 (243U)
 *   DCM_E_VMSCNC_4 (244U)
 *   DCM_E_VMSCNC_5 (245U)
 *   DCM_E_VMSCNC_6 (246U)
 *   DCM_E_VMSCNC_7 (247U)
 *   DCM_E_VMSCNC_8 (248U)
 *   DCM_E_VMSCNC_9 (249U)
 *   DCM_E_VMSCNC_A (250U)
 *   DCM_E_VMSCNC_B (251U)
 *   DCM_E_VMSCNC_C (252U)
 *   DCM_E_VMSCNC_D (253U)
 *   DCM_E_VMSCNC_E (254U)
 * Dcm_NegativeResponseCodeType: Enumeration of integer in interval [0...255] with enumerators
 *   DCM_E_POSITIVERESPONSE (0U)
 *   DCM_E_GENERALREJECT (16U)
 *   DCM_E_SERVICENOTSUPPORTED (17U)
 *   DCM_E_SUBFUNCTIONNOTSUPPORTED (18U)
 *   DCM_E_INCORRECTMESSAGELENGTHORINVALIDFORMAT (19U)
 *   DCM_E_RESPONSETOOLONG (20U)
 *   DCM_E_BUSYREPEATREQUEST (33U)
 *   DCM_E_CONDITIONSNOTCORRECT (34U)
 *   DCM_E_REQUESTSEQUENCEERROR (36U)
 *   DCM_E_NORESPONSEFROMSUBNETCOMPONENT (37U)
 *   DCM_E_FAILUREPREVENTSEXECUTIONOFREQUESTEDACTION (38U)
 *   DCM_E_REQUESTOUTOFRANGE (49U)
 *   DCM_E_SECURITYACCESSDENIED (51U)
 *   DCM_E_AUTHENTICATIONREQUIRED (52U)
 *   DCM_E_INVALIDKEY (53U)
 *   DCM_E_EXCEEDNUMBEROFATTEMPTS (54U)
 *   DCM_E_REQUIREDTIMEDELAYNOTEXPIRED (55U)
 *   DCM_E_CVF_INVALIDTIMEPERIOD (80U)
 *   DCM_E_CVF_INVALIDSIGNATURE (81U)
 *   DCM_E_CVF_INVALIDCHAINOFTRUST (82U)
 *   DCM_E_CVF_INVALIDTYPE (83U)
 *   DCM_E_CVF_INVALIDFORMAT (84U)
 *   DCM_E_CVF_INVALIDCONTENT (85U)
 *   DCM_E_CVF_INVALIDSCOPE (86U)
 *   DCM_E_CVF_INVALIDCERTIFICATEREVOKED (87U)
 *   DCM_E_OWNERSHIPVERIFICATIONFAILED (88U)
 *   DCM_E_CHALLENGECALCULATIONFAILED (89U)
 *   DCM_E_UPLOADDOWNLOADNOTACCEPTED (112U)
 *   DCM_E_TRANSFERDATASUSPENDED (113U)
 *   DCM_E_GENERALPROGRAMMINGFAILURE (114U)
 *   DCM_E_WRONGBLOCKSEQUENCECOUNTER (115U)
 *   DCM_E_REQUESTCORRECTLYRECEIVEDRESPONSEPENDING (120U)
 *   DCM_E_SUBFUNCTIONNOTSUPPORTEDINACTIVESESSION (126U)
 *   DCM_E_SERVICENOTSUPPORTEDINACTIVESESSION (127U)
 *   DCM_E_RPMTOOHIGH (129U)
 *   DCM_E_RPMTOOLOW (130U)
 *   DCM_E_ENGINEISRUNNING (131U)
 *   DCM_E_ENGINEISNOTRUNNING (132U)
 *   DCM_E_ENGINERUNTIMETOOLOW (133U)
 *   DCM_E_TEMPERATURETOOHIGH (134U)
 *   DCM_E_TEMPERATURETOOLOW (135U)
 *   DCM_E_VEHICLESPEEDTOOHIGH (136U)
 *   DCM_E_VEHICLESPEEDTOOLOW (137U)
 *   DCM_E_THROTTLE_PEDALTOOHIGH (138U)
 *   DCM_E_THROTTLE_PEDALTOOLOW (139U)
 *   DCM_E_TRANSMISSIONRANGENOTINNEUTRAL (140U)
 *   DCM_E_TRANSMISSIONRANGENOTINGEAR (141U)
 *   DCM_E_BRAKESWITCH_NOTCLOSED (143U)
 *   DCM_E_SHIFTERLEVERNOTINPARK (144U)
 *   DCM_E_TORQUECONVERTERCLUTCHLOCKED (145U)
 *   DCM_E_VOLTAGETOOHIGH (146U)
 *   DCM_E_VOLTAGETOOLOW (147U)
 *   DCM_E_VMSCNC_0 (240U)
 *   DCM_E_VMSCNC_1 (241U)
 *   DCM_E_VMSCNC_2 (242U)
 *   DCM_E_VMSCNC_3 (243U)
 *   DCM_E_VMSCNC_4 (244U)
 *   DCM_E_VMSCNC_5 (245U)
 *   DCM_E_VMSCNC_6 (246U)
 *   DCM_E_VMSCNC_7 (247U)
 *   DCM_E_VMSCNC_8 (248U)
 *   DCM_E_VMSCNC_9 (249U)
 *   DCM_E_VMSCNC_A (250U)
 *   DCM_E_VMSCNC_B (251U)
 *   DCM_E_VMSCNC_C (252U)
 *   DCM_E_VMSCNC_D (253U)
 *   DCM_E_VMSCNC_E (254U)
 *
 * Array Types:
 * ============
 * NFC_READER_FLDHM_RES_Sig: Array with 259 element(s) of type uint8
 * NFC_READER_FRDHM_RES_Sig: Array with 259 element(s) of type uint8
 * NFC_READER_REQ_FLDHM_Sig: Array with 259 element(s) of type uint8
 * NFC_READER_REQ_FRDHM_Sig: Array with 259 element(s) of type uint8
 * NFC_READER_REQ_WCPM2_Sig: Array with 259 element(s) of type uint8
 * NFC_READER_WCPM2_RES_Sig: Array with 259 element(s) of type uint8
 * PhysicalKeyVehicleCertificate: Array with 455 element(s) of type Rte_DT_PhysicalKeyVehicleCertificate_0
 * PhysicalVehCertPrivateKey: Array with 32 element(s) of type Rte_DT_PhysicalVehCertPrivateKey_0
 * PhysicalVehicleOEMCertificate: Array with 442 element(s) of type Rte_DT_PhysicalVehicleOEMCertificate_0
 * uint8_a: Array with 1 element(s) of type uint8
 *
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * APIs which are accessible from all runnable entities of the SW-C
 *
 **********************************************************************************************************************
 * Calibration Parameters:
 * =======================
 *   SW-C local Calibration Parameters:
 *   ----------------------------------
 *   PhysicalKeyVehicleCertLength Rte_CData_Cal_PhysicalKeyVehicleCertLength(void)
 *   PhysicalVehicleOEMCertLength Rte_CData_Cal_PhysicalVehicleOEMCertLength(void)
 *   PhysicalVehCertPrivateKeyLength Rte_CData_Cal_PhysicalVehCertPrivateKeyLength(void)
 *   Rte_DT_PhysicalKeyVehicleCertificate_0 *Rte_CData_Cal_PhysicalKeyVehicleCertificate(void)
 *     Returnvalue: Rte_DT_PhysicalKeyVehicleCertificate_0* is of type PhysicalKeyVehicleCertificate
 *   Rte_DT_PhysicalVehCertPrivateKey_0 *Rte_CData_Cal_PhysicalVehCertPrivateKey(void)
 *     Returnvalue: Rte_DT_PhysicalVehCertPrivateKey_0* is of type PhysicalVehCertPrivateKey
 *   Rte_DT_PhysicalVehicleOEMCertificate_0 *Rte_CData_Cal_PhysicalVehicleOEMCertificate(void)
 *     Returnvalue: Rte_DT_PhysicalVehicleOEMCertificate_0* is of type PhysicalVehicleOEMCertificate
 *
 *********************************************************************************************************************/


#define rbd_NFCVehIf_START_SEC_CODE
#include "rbd_NFCVehIf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */
#include "rbd_ProxiFCA.h"

/**********************************************************************************************************************
 *
 * Runnable Entity Name: rbd_NFCVehIf_Cyclic
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 10ms
 *     and not in Mode(s) <PROGRAMMING_SESSION>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Receive_NFC_READER_FLDHM_RES_Sig_NFC_READER_FLDHM_RES_Sig(uint8 *data, uint16* length)
 *     Argument data: uint8* is of type NFC_READER_FLDHM_RES_Sig
 *   Std_ReturnType Rte_Receive_NFC_READER_FRDHM_RES_Sig_NFC_READER_FRDHM_RES_Sig(uint8 *data, uint16* length)
 *     Argument data: uint8* is of type NFC_READER_FRDHM_RES_Sig
 *   Std_ReturnType Rte_Receive_NFC_READER_WCPM2_RES_Sig_NFC_READER_WCPM2_RES_Sig(uint8 *data, uint16* length)
 *     Argument data: uint8* is of type NFC_READER_WCPM2_RES_Sig
 *   Std_ReturnType Rte_Read_RP_Spaak_Spaak(Spaak *data)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Send_NFC_READER_REQ_FLDHM_Sig_NFC_READER_REQ_FLDHM_Sig(const uint8 *data, uint16 length)
 *     Argument data: uint8* is of type NFC_READER_REQ_FLDHM_Sig
 *   Std_ReturnType Rte_Send_NFC_READER_REQ_FRDHM_Sig_NFC_READER_REQ_FRDHM_Sig(const uint8 *data, uint16 length)
 *     Argument data: uint8* is of type NFC_READER_REQ_FRDHM_Sig
 *   Std_ReturnType Rte_Send_NFC_READER_REQ_WCPM2_Sig_NFC_READER_REQ_WCPM2_Sig(const uint8 *data, uint16 length)
 *     Argument data: uint8* is of type NFC_READER_REQ_WCPM2_Sig
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: rbd_NFCVehIf_Cyclic_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, rbd_NFCVehIf_CODE) rbd_NFCVehIf_Cyclic(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: rbd_NFCVehIf_Cyclic
 *********************************************************************************************************************/

    uint8 DevRef_u8 = 0xffu;
    uint8 wcpmSession_state_u8;
    uint8 wcpmReaderConnection_state_u8;
    uint8 fldhmReaderConnection_state_u8;

    rbd_NfcIf_NfcTapThread();
	rbd_NFCVehIf_Deselect_TxManager_Cyclic();
    rbd_NFCVehIf_NFCReaderSessionTimeOutManager();

	/*AXIVION Disable MisraC2012Directive-4.1 : rbd_NFCVehIf_NfcCardTimer_u16 doesn't create overflow */
	rbd_NFCVehIf_NfcCardTimer_u16 =
					( rbd_NFCVehIf_NfcCardTimer_u16 >= (uint16)NFC_CYCLE_TIME ) ?
						( rbd_NFCVehIf_NfcCardTimer_u16 - NFC_CYCLE_TIME ) : 0u; /*AXIVION Line MisraC2012-21.18: Cycle time make be larger than Card Timer Deviation InternalBosch_FalsePositive_A: Ticket 1198131. Already checking the size to be within range */
	rbd_NFCVehIf_PollingTimeoutTimer_u16 =
						( rbd_NFCVehIf_PollingTimeoutTimer_u16 >= (uint16)NFC_CYCLE_TIME ) ?
							( rbd_NFCVehIf_PollingTimeoutTimer_u16 - NFC_CYCLE_TIME ) : 0u; /*AXIVION Line MisraC2012-21.18: Cycle time make be larger than Card Timer Deviation InternalBosch_FalsePositive_A: Ticket 1198131. Already checking the size to be within range */

	rbd_NFCVehIf_CardPairingRoutine_Cyclic();
    rbd_NFCVehIf_TestCardPairingRoutine_Cyclic();
    rbd_NFCVehIf_GetUIDRoutine_Cyclic();
    rbd_NfcIf_TapStartTriggerCyclic();

    rbd_NFCVehIf_ReadNFCReaderStatusInfo((uint8)WCPM2,&wcpmSession_state_u8,&wcpmReaderConnection_state_u8, &DevRef_u8);
    rbd_NFCVehIf_ReadNFCReaderStatusInfo((uint8)FLDHM,&fldhmReaderConnection_state_u8,&fldhmReaderConnection_state_u8, &DevRef_u8);
    if(TRUE == rbd_NFCVehIf_IsDeselectRetryTmr_Expired())
    {

      Rte_Write_PP_CanRequest_DkmNfc_ComRequest(FALSE);
      /* Stop sending the DESELECT */
      rbd_NFCVehIf_DESELECT_TimerRetry_Reload(WCPM2,NFC_READER_DESELECT_DISABLE_TYPE_E,0u);
      if(READER_IN_SESSION == wcpmReaderConnection_state_u8)
      {
        rbdSessionMgr_NfcDisconnected((uint8)WCPM2);
        (void)rbd_NFCVehIf_ResetNFCReaderSessionTag((uint8)WCPM2);
      }
      else
      {
      }
      if(READER_IN_SESSION == fldhmReaderConnection_state_u8)
      {
        rbdSessionMgr_NfcDisconnected((uint8)WCPM2);
        (void)rbd_NFCVehIf_ResetNFCReaderSessionTag((uint8)WCPM2);
      }
      else
      {
      }
    }

  	//DTC Timer
  if(rbd_NFCVehIf_DTCWCMP2Timer_active_b == TRUE)
  {
    /*AXIVION Disable MisraC2012Directive-4.1 : rbd_NFCVehIf_DTCWCPMTimer_u16 doesn't create overflow */
    rbd_NFCVehIf_DTCWCPMTimer_u16 -= (uint16)NFC_CYCLE_TIME;
    Rte_Write_PP_CanRequest_DkmNfc_ComRequest(TRUE);
    if((uint8)0 >= rbd_NFCVehIf_DTCWCPMTimer_u16)
	{
		rbd_NFCVehIf_DTC();
	}
  }
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: rbd_NFCVehIf_GetNfcUID_Start_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <rbd_NFCVehIf_GetNfcUID_Start>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType rbd_NFCVehIf_GetNfcUID_Start_Start(uint8 *Out_ResData, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_GetNfcUID_Start_E_NOT_OK
 *   RTE_E_GetNfcUID_Start_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: rbd_NFCVehIf_GetNfcUID_Start_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) rbd_NFCVehIf_GetNfcUID_Start_Start(P2VAR(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: rbd_NFCVehIf_GetNfcUID_Start_Start (returns application error)
 *********************************************************************************************************************/

    Std_ReturnType ret = E_NOT_OK;
    static uint8 RoutineTriggered = FALSE;
    if(((uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E == rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcRoutineStatus) ||
       ((uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E == rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E].nfcRoutineStatus))
	{
    	/* Reject if other Routine in progress */
    	*ErrorCode =  DCM_E_GENERALREJECT;
	}
    else
    {
		if (((uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E != rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcRoutineStatus) &&
			(FALSE == RoutineTriggered))
		{
			/* Routine Request from Diag accepted */
			rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].DiagRoutine_State_en = NFC_DIAG_ROUTINE_REQUEST_RX_STATE_E;

			rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcRoutineStatus = (uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E;
			rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcRoutineErrorCode = (uint8)NFC_ROUTINE_NO_ERROR;
			memset(rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcCardData_t.nfcRoutineUId, 0x00, NFC_CARD_UID_LEN);
			rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].DiagRoutine_State_en = NFC_DIAG_ROUTINE_REQUEST_RX_STATE_E;
			RoutineTriggered  = TRUE;
			/* Routine Just got accepted, SO send Pending */
			ret = PENDING;
		}
		else if ((uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E == rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcRoutineStatus)
		{
			/* Routine In Progresss, SO send Pending */
			ret = PENDING;
		}
		else
		{
			/*AXIVION Disable Style MisraC2012-18.1: Pointer arithmetic on Out_ResData creates pointer outside array bounds. Justify operation is valid and not out of bounds */
			Out_ResData[0] = (uint8)rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcRoutineStatus;	/* Byte 0 is Routine status */
			/*AXIVION Disable Style MisraC2012-18.1: Pointer arithmetic on Out_ResData creates pointer outside array bounds. Justify operation is valid and not out of bounds */
			Out_ResData[1] = (uint8)rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcRoutineErrorCode;					/* Byte 1 Get UID Error code */
			RoutineTriggered  = FALSE;

			*ErrorCode = DCM_E_POSITIVERESPONSE;
			/* Routine Finished */
			ret = E_OK;
		}
	}

    return ret;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: rbd_NFCVehIf_Init
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed once after the RTE is started
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: rbd_NFCVehIf_Init_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, rbd_NFCVehIf_CODE) rbd_NFCVehIf_Init(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: rbd_NFCVehIf_Init
 *********************************************************************************************************************/

	uint8 Routine_Counter_u8;
    // Init global nfc tag table
    for (uint8 i_u8 = 0; i_u8 < NFC_NUM_READERS; ++i_u8)
    {
        (void)rbd_NFCVehIf_ResetNFCReaderSessionTag(i_u8);
    }

    /* Init Individual Routine Bytes */
    for(Routine_Counter_u8 = (uint8)NFC_ROUTINE_GROUP_PLANT_PAIRING_E; Routine_Counter_u8 < (uint8)NFC_ROUTINE_GROUP_MAX_E; Routine_Counter_u8 ++)
    {
    	/*AXIVION Disable Style MisraC2012-10.5: Explicit conversion to inappropriate essential type [(uint8_t->NfcVehIf_RoutineGroup_EN_TYPE)Routine_Counter_u8]. Conversion is intended and no risk*/
    	rbd_NFCVehIf_RoutineData_S[(NfcVehIf_RoutineGroup_EN_TYPE)Routine_Counter_u8].DiagRoutine_State_en = NFC_DIAG_ROUTINE_INIT_STATE_E;
    	/*AXIVION Disable Style MisraC2012-10.5: Explicit conversion to inappropriate essential type [(uint8_t->NfcVehIf_RoutineGroup_EN_TYPE)Routine_Counter_u8]. Conversion is intended and no risk*/
    	rbd_NFCVehIf_RoutineData_S[(NfcVehIf_RoutineGroup_EN_TYPE)Routine_Counter_u8].nfcRoutineErrorCode = NFC_ROUTINE_NO_ERROR;
    	/*AXIVION Disable Style MisraC2012-10.5: Explicit conversion to inappropriate essential type [(uint8_t->NfcVehIf_RoutineGroup_EN_TYPE)Routine_Counter_u8]. Conversion is intended and no risk*/
    	rbd_NFCVehIf_RoutineData_S[(NfcVehIf_RoutineGroup_EN_TYPE)Routine_Counter_u8].nfcRoutineStatus = (uint8)NFC_ROUTINE_STATUS_UNINITIALIZED_E;
    	/*AXIVION Disable Style MisraC2012-10.5: Explicit conversion to inappropriate essential type [(uint8_t->NfcVehIf_RoutineGroup_EN_TYPE)Routine_Counter_u8]. Conversion is intended and no risk*/
    	memset(rbd_NFCVehIf_RoutineData_S[(NfcVehIf_RoutineGroup_EN_TYPE)Routine_Counter_u8].nfcCardData_t.nfcRoutineUId, 0x00, NFC_CARD_UID_LEN);
    }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: rbd_NFCVehIf_NFC_Card_Pairing_Start_RequestResults
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RequestResults> of PortPrototype <rbd_NFCVehIf_NFC_Card_Pairing_Start>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType rbd_NFCVehIf_NFC_Card_Pairing_Start_RequestResults(uint8 *Out_ResData, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_NFC_Card_Pairing_Start_E_NOT_OK
 *   RTE_E_NFC_Card_Pairing_Start_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: rbd_NFCVehIf_NFC_Card_Pairing_Start_RequestResults_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) rbd_NFCVehIf_NFC_Card_Pairing_Start_RequestResults(P2VAR(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: rbd_NFCVehIf_NFC_Card_Pairing_Start_RequestResults (returns application error)
 *********************************************************************************************************************/
	Std_ReturnType dkmRet_u8 = RTE_E_OK;
	uint8 ret_u8 = E_NOT_OK;
	static uint8 isKeyInfoReadInProgress = FALSE;
	uint16 errCode = (uint16)0;

	(void)memset( Out_ResData, 0x00, 75u ); /*AXIVION Line MisraC2012-21.18: Size may be too large for pointers passed in. Deviation InternalBosch_FalsePositive_A.  Size is definite length */

	/*AXIVION Disable Style MisraC2012-18.1: Pointer arithmetic on Out_ResData creates pointer outside array bounds. Justify operation is valid and not out of bounds */
    Out_ResData[0] = (uint8)rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcRoutineStatus;	/* Routine status 	0x00= UnInitialized, 0x01= Success, 0x02=Progress, 0x03=Failure  	*/
    /*AXIVION Disable Style MisraC2012-18.1: Pointer arithmetic on Out_ResData creates pointer outside array bounds. Justify operation is valid and not out of bounds */
    Out_ResData[1] = (uint8)rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcRoutineErrorCode;/* Test Pairing Error Code 	Bit0= Fast Transaction Failure Bit1: Timeout Bit2:  Reader Not Ready*/

    if((uint8)NFC_ROUTINE_STATUS_SUCCESS_E == rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcRoutineStatus)
	{
    	/* Routine was successful so go for redaing the data and send it to diag */
    	if(FALSE == isKeyInfoReadInProgress)
    	{
    		dkmRet_u8 = Rte_Call_RP_rbdDeviceMgr_GetKeyInfoCard_Operation((rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcRoutineKeyRef - 0x64u), &keyInfo_S);
    		if(RTE_E_OK == dkmRet_u8 )
    		{
        		isKeyInfoReadInProgress = TRUE;
    		}
    		else
    		{
    			/* Do Nothing */
    		}
    		ret_u8 = RTE_E_NFC_Card_Serial_Number_Read_DCM_E_PENDING;
    	}
    	else
    	{
    		dkmRet_u8 = Rte_Call_RP_rbdDeviceMgr_GetStatus_Operation(&errCode);
    		if(RTE_E_OK == dkmRet_u8)
    		{
    			/* Note Below memcpys are of definite length and don't cause out of bound errors */
    			/*AXIVION Disable Style MisraC2012-21.18: Size argument may be too large for the pointers passed in.sizeof(Rte_DT_rbdCdsTypes_NfcCardDat_st_2) is having definite length */
    			memcpy(&Out_ResData[2],&keyInfo_S.nfcCardDat.nfcCardSerNum[0],sizeof(Rte_DT_rbdCdsTypes_NfcCardDat_st_2)); /* Copy Serial Number */
    			/*AXIVION Disable Style MisraC2012-21.18: Size argument may be too large for the pointers passed in.sizeof(Rte_DT_rbdCdsTypes_NfcCardDat_st_1) is having definite length */
    			memcpy(&Out_ResData[17],&keyInfo_S.nfcCardDat.nfcCardUid[0],sizeof(Rte_DT_rbdCdsTypes_NfcCardDat_st_1)); /* Copy UID */
    			Out_ResData[24] = keyInfo_S.nfcCardDat.nfcCardIdx + 1u;
				/*AXIVION Disable Style MisraC2012-21.18: Size argument may be too large for the pointers passed in.sizeof(sha1HashCetH) is having definite length */
    			memcpy(&Out_ResData[25],&keyInfo_S.keyIdentifier[0],sizeof(sha1HashCetH)); /* Copy Key Identifier */
				/*AXIVION Disable Style MisraC2012-21.18: Size argument may be too large for the pointers passed in.keyInfo_S.keyFriendlyNamLen is having definite length */
    			memcpy(&Out_ResData[45],&keyInfo_S.keyFriendlyName[0],keyInfo_S.keyFriendlyNamLen); /* Copy Friendly Name */

    			isKeyInfoReadInProgress = FALSE;
    			ret_u8 = RTE_E_NFC_Card_Pairing_Start_E_OK;
    			*ErrorCode = DCM_E_POSITIVERESPONSE;
    		}
    		else if(RTE_E_IF_NfcFlow_E_BUSY == dkmRet_u8)
    		{
    			/* If card read operation in progress then send pending*/
    			ret_u8 = RTE_E_NFC_Card_Serial_Number_Read_DCM_E_PENDING;
    		}
    		else
    		{
    			//Failure Condition
    			ret_u8 = RTE_E_NFC_Card_Pairing_Start_E_NOT_OK;
    			*ErrorCode = DCM_E_GENERALREJECT;
    			isKeyInfoReadInProgress = FALSE;
    		}
    	}
	}
	else
	{
		/* Routine Failed */
		isKeyInfoReadInProgress = FALSE;
		*ErrorCode = DCM_E_POSITIVERESPONSE;
		ret_u8 = RTE_E_OK;
	}

    return ret_u8;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: rbd_NFCVehIf_NFC_Card_Pairing_Start_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <rbd_NFCVehIf_NFC_Card_Pairing_Start>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType rbd_NFCVehIf_NFC_Card_Pairing_Start_Start(const uint8 *In_ReqData, uint8 serialNumLen_u8, Dcm_NegativeResponseCodeType *ErrorCode)
 *     Argument In_ReqData: uint8* is of type uint8_a
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_NFC_Card_Pairing_Start_E_NOT_OK
 *   RTE_E_NFC_Card_Pairing_Start_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: rbd_NFCVehIf_NFC_Card_Pairing_Start_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
/*AXIVION Disable Style MisraC2012-8.3  : Deviation InternalBosch_GeneratedCode_A - Declaration is based on AutoSar configuration  */
FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) rbd_NFCVehIf_NFC_Card_Pairing_Start_Start(P2CONST(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_DATA) In_ReqData, uint8 serialNumLen_u8, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: rbd_NFCVehIf_NFC_Card_Pairing_Start_Start (returns application error)
 *********************************************************************************************************************/
    uint8 ret_u8 = E_NOT_OK;
	drmServices_Type dataType;
	(void)Rte_Read_rbd_NFCVehIf_RP_drmServices_drmServices(&dataType);
    if (FALSE == rbd_NFCVehIf_IsRoutineInProgress() && (dataType.SPKPHSCLKEY == TRUE))
    {
    	rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].DiagRoutine_State_en = NFC_DIAG_ROUTINE_REQUEST_RX_STATE_E;
    	/*AXIVION Disable Style MisraC2012-21.18: Size argument may be too large for the pointers passed in. [serialNumLen_u8], serialNumLen_u8 is controlled */
    	memcpy(rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcCardData_t.nfcRoutineSerialNumber, In_ReqData, serialNumLen_u8);
    	ret_u8 = E_OK;
    	*ErrorCode = DCM_E_POSITIVERESPONSE;
    }
    else
    {
    	*ErrorCode =  DCM_E_GENERALREJECT;
    }

    return ret_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) rbd_NFCVehIf_NFC_Card_Serial_Number_Read_ConditionCheckRead(Dcm_OpStatusType OpStatus, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) ErrorCode)
{
	Std_ReturnType ret = RTE_E_NFC_Card_Serial_Number_Read_E_NOT_OK;
	Std_ReturnType result = E_NOT_OK;
	uint16 errCode = (uint16)0;
	Std_ReturnType dkmRet_u8 = RTE_E_OK;
	static uint8 cardKeyList[10];
	static uint8 KeysCountRead = FALSE;
	static uint8 isKeyInfoReadInProgress = FALSE;


	if(KeysCountRead == FALSE)
	{
		/* This allows the redaing of the number of keys from the database only once */
		(void)Rte_Call_RP_rbdDeviceMgr_GetNumberOfKeyEntries_Operation((uint8)DEVICE_TYPE_CARD, cardKeyList, CARD_REF_LENGTH, &keyCardRef_paried_u8);
		KeysCountRead = TRUE;
		rbd_NFCVehIf_CardIndex = 0x00u;
		/*AXIVION Line MisraC2012-21.18: Size may be too large for pointers passed in. Deviation InternalBosch_FalsePositive_A.  Size is definite length */
		memset(&rbd_NFCVehIf_Did5608Info[0], 0x00, sizeof(rbd_NFCVehIf_Did5608Info));
		/* Read the number of paired Card list and initialize the card index to 0 */
	}

	/* If read card operation in progress, don't initiate another one */
	if((0u != keyCardRef_paried_u8) && (rbd_NFCVehIf_CardIndex < keyCardRef_paried_u8)  && (FALSE == isKeyInfoReadInProgress))
	{
		/* If Reading card info operation is not initiated yet, then start the operation */
		dkmRet_u8 = Rte_Call_RP_rbdDeviceMgr_GetKeyInfoCard_Operation(cardKeyList[rbd_NFCVehIf_CardIndex], &keyInfo_S);
		if(RTE_E_OK == dkmRet_u8 )
		{
			isKeyInfoReadInProgress = TRUE;
		}
		else
		{
		}
	}
	else
	{
	}

	/* If read card operation in progress, then check the status of the operation */
	if(TRUE == isKeyInfoReadInProgress)
	{
		result = Rte_Call_RP_rbdDeviceMgr_GetStatus_Operation(&errCode);
		if(RTE_E_NFC_Card_Pairing_Start_E_OK == result)
		{
			/* Card Read info operation successful */
			(void)memcpy(&rbd_NFCVehIf_Did5608Info[rbd_NFCVehIf_CardIndex].nfcCardUid[0],&keyInfo_S.nfcCardDat.nfcCardUid[0],sizeof(Rte_DT_rbdCdsTypes_NfcCardDat_st_1));
			(void)memcpy(&rbd_NFCVehIf_Did5608Info[rbd_NFCVehIf_CardIndex].keyIdentifier[0],&keyInfo_S.keyIdentifier[0],sizeof(sha1HashCetH));
			(void)memcpy(&rbd_NFCVehIf_Did5608Info[rbd_NFCVehIf_CardIndex].keyFriendlyName[0],&keyInfo_S.keyFriendlyName[0],sizeof(Rte_DT_rbdCdsTypes_KeyInfo_st_5));
			(void)memcpy(&rbd_NFCVehIf_Did5608Info[rbd_NFCVehIf_CardIndex].nfcCardSerNum[0],&keyInfo_S.nfcCardDat.nfcCardSerNum[0],sizeof(Rte_DT_rbdCdsTypes_NfcCardDat_st_2));
			/*AXIVION Disable Style MisraC2012-4.1: Cast on result of arithmetic computation may cause overflow. Card Index does not go above 10U */
			rbd_NFCVehIf_Did5608Info[rbd_NFCVehIf_CardIndex].nfcCardIdx = rbd_NFCVehIf_CardIndex + 1u;
			rbd_NFCVehIf_CardIndex ++;
			isKeyInfoReadInProgress = FALSE;
			/* If we already read all the card info then simply return */
			if(rbd_NFCVehIf_CardIndex == keyCardRef_paried_u8)
			{
				ret = RTE_E_NFC_Card_Serial_Number_Read_E_OK;
				*ErrorCode = DCM_E_POSITIVERESPONSE;
				/*AXIVION Disable Style MisraC2012-2.2: Dead (redundant) code: result of assignment is not used. Justify global variable set to 0 */
				rbd_NFCVehIf_CardIndex = 0u;
				KeysCountRead = FALSE;
			}
			else
			{
				/* If all cards are not read then send pending and initiate another read */
				ret = RTE_E_NFC_Card_Serial_Number_Read_DCM_E_PENDING;
			}
		}
		else if(RTE_E_IF_NfcFlow_E_BUSY == result)
		{
			/* If card read operation in progress then send pending*/
			ret = RTE_E_NFC_Card_Serial_Number_Read_DCM_E_PENDING;
		}
		else
		{
			//Failure Condition
			ret = RTE_E_NFC_Card_Serial_Number_Read_E_NOT_OK;
			*ErrorCode = DCM_E_GENERALREJECT;
			isKeyInfoReadInProgress = FALSE;
			KeysCountRead = FALSE;
		}
	}
	else
	{
		if(RTE_E_OK == dkmRet_u8 )
		{
			/* If 0 cards are paired then send OK*/
			ret = RTE_E_NFC_Card_Serial_Number_Read_E_OK;
			*ErrorCode = DCM_E_POSITIVERESPONSE;
			/*AXIVION Disable Style MisraC2012-2.2: Dead (redundant) code: result of assignment is not used. Justify global variable set to 0 */
			rbd_NFCVehIf_CardIndex = 0u;
			isKeyInfoReadInProgress = FALSE;
			KeysCountRead = FALSE;
		}
		else
		{
			ret = RTE_E_NFC_Card_Serial_Number_Read_DCM_E_PENDING;
		}
	}
	(void)OpStatus;
    return ret;

}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: rbd_NFCVehIf_NFC_Card_Serial_Number_Read_Operation
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Operation> of PortPrototype <rbd_NFCVehIf_NFC_Card_Serial_Number_Read>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType rbd_NFCVehIf_NFC_Card_Serial_Number_Read_Operation(uint8 *Data)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_NFC_Card_Serial_Number_Read_E_NOT_OK
 *   RTE_E_NFC_Card_Serial_Number_Read_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: rbd_NFCVehIf_NFC_Card_Serial_Number_Read_Operation_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) rbd_NFCVehIf_NFC_Card_Serial_Number_Read_Operation(P2VAR(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) Data) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: rbd_NFCVehIf_NFC_Card_Serial_Number_Read_Operation (returns application error)
 *********************************************************************************************************************/

	(void)memset( Data, 0x00, 731u ); /*AXIVION Line MisraC2012-21.18: Size may be too large for pointers passed in. Deviation InternalBosch_FalsePositive_A.  Size is definite length */
	Data[0] = keyCardRef_paried_u8; //number of nfc cards paired
	for ( uint8 index_u8 = 0; index_u8 < keyCardRef_paried_u8; ++index_u8 )
	{
		for ( uint8 i_u8 = 0; i_u8 < NFC_SERIAL_LEN; ++i_u8 )
		{
			Data[(uint8)1 + ( (uint8)index_u8 * NFC_PAIRED_CARD_LENGTH ) + (uint8)i_u8] =
				rbd_NFCVehIf_Did5608Info[index_u8].nfcCardSerNum[i_u8];
		}

		for ( uint8 i_u8 = 0; i_u8 < NFC_CARD_UID_LEN; ++i_u8 )
		{
			Data[(uint8)16 + ( (uint8)index_u8 * NFC_PAIRED_CARD_LENGTH ) + (uint8)i_u8] =
				rbd_NFCVehIf_Did5608Info[index_u8].nfcCardUid[i_u8];
		}

		Data[(uint8)23 + ( (uint8)index_u8 * NFC_PAIRED_CARD_LENGTH )] = rbd_NFCVehIf_Did5608Info[index_u8].nfcCardIdx;

		for ( uint8 i_u8 = 0; i_u8 < KEY_IDENTIFIER_LENGTH; ++i_u8 )
		{
			Data[(uint8)24 + ( (uint8)index_u8 * NFC_PAIRED_CARD_LENGTH ) + (uint8)i_u8] =
				rbd_NFCVehIf_Did5608Info[index_u8].keyIdentifier[i_u8];
		}

		for ( uint8 i_u8 = 0; i_u8 < KEY_FRIENDLY_NAME_LENGTH; ++i_u8 )
		{
			Data[(uint8)44 + ( (uint8)index_u8 * NFC_PAIRED_CARD_LENGTH ) + (uint8)i_u8] =
				rbd_NFCVehIf_Did5608Info[index_u8].keyFriendlyName[i_u8];
		}
	}

	return E_OK;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


/**********************************************************************************************************************
 *
 * Runnable Entity Name: rbd_NFCVehIf_NFC_READER_FLDHM_DEVICE_Sig_Callback
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <NFC_READER_FLDHM_RES_Sig> of PortPrototype <NFC_READER_FLDHM_RES_Sig>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Receive_NFC_READER_FLDHM_RES_Sig_NFC_READER_FLDHM_RES_Sig(uint8 *data, uint16* length)
 *     Argument data: uint8* is of type NFC_READER_FLDHM_RES_Sig
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: rbd_NFCVehIf_NFC_READER_FLDHM_DEVICE_Sig_Callback_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, rbd_NFCVehIf_CODE) rbd_NFCVehIf_NFC_READER_FLDHM_DEVICE_Sig_Callback(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: rbd_NFCVehIf_NFC_READER_FLDHM_DEVICE_Sig_Callback
 *********************************************************************************************************************/
	//ToDo: Do we need static,may be stack was not sufficient thats why static
	static uint8 FLDHM_NFCResponse_au8[NFC_MAX_MESSAGE_LEN];
	uint64 utcTimeStamp_u64 = 0x00;
	nfcReaderResponseHeader_t nfcReaderFLDHMHdr;
	uint16 responseLength_u16;
	NfcVehIf_Door_Stat_EN_TYPE door_status_loc_en = DOOR_STAT_SNA_EN;
	boolean data_validity_u8 = FALSE;
	uint8 nfcEntryFailedAttemptCtr_u8 = 0x00;

	Std_ReturnType ret  = RTE_E_OK;
	NfcVehIf_Door_Stat_EN_TYPE doorStatusLastNvm_en = DOOR_STAT_INVALID_E;
	NfcVehIf_Door_Stat_EN_TYPE doorStatusLastCanBus_en = DOOR_STAT_INVALID_E;
	uint8 door_status_fusion_u8 = 0x00u;
	uint8 devRef_u8 = 0xffu;
	uint8 session_state_u8  = (uint8)NFC_READER_NOT_ACTIVE_STATE_E;
	uint8 readerConnection_state_u8 = READER_DISCONNECTED;

    drmServices_Type dataType;
    uint8 keyPlaced_u8 = DEVICE_PHONE_TYPE;
    boolean isCardResponse_bool = FALSE;


    /* Tap Entry transaction code - Look Up table has been created and stored in flash.
     * Look up table arranges the tap entry transaction code based on the door status enumeration
     * If DOOR status is locked it means transaction code is unlocked and vice versa.
     * Refer NfcVehIf_Door_Stat_EN_TYPE and NfcVehIf_NfcFlowTransCode_EN_TYPE for self explantion of below transaction codes
     */
    const uint8 nfcTapEntry_trans_code_lut_u8[(uint8)DOOR_STAT_SNA_EN] =
    {
        RBD_TRANSCODE_UNLOCK_ID,	/* DOOR_STAT_LOCKED_EN(0) position code.*/ //TRANSACTION_CODE_DOOR_UNLOCK_EN,
        RBD_TRANSCODE_LOCK_ID,	   	/* DOOR_STAT_DRV_UNLOCK_EN(1) position code*/ //TRANSACTION_CODE_DOOR_LOCK_EN,
        RBD_TRANSCODE_LOCK_ID,		/* DOOR_STAT_ALL_UNLOCK_EN(2) position code*/ //TRANSACTION_CODE_DOOR_LOCK_EN,
    };

/* verifys OP, Card Pairing & Tap Start are not in session*/
	rbd_NFCVehIf_ReadNFCReaderStatusInfo((uint8)WCPM2,&session_state_u8, &readerConnection_state_u8, &devRef_u8);
	if(READER_DISCONNECTED == readerConnection_state_u8)
	{
	/* ToDo: Don't check SPAAK signal for demo. Discussion with STLA still ongoing */
		if(RTE_E_OK == Rte_Receive_rbd_NFCVehIf_NFC_READER_FLDHM_RES_Sig_NFC_READER_FLDHM_DEVICE_Sig(FLDHM_NFCResponse_au8, &responseLength_u16 )  )
		{
			(void)rbd_NfcIf_NfcReaderCanTPPacketHeaderRead(FLDHM_NFCResponse_au8, &nfcReaderFLDHMHdr);

			/* There are two scenarios to start the NFC start entry.
			* 1. Receive the NFCReader_DetectedUIDs message from FLDHM or
			* 2. Receive the SELECT response from the the FLDHM module.
			* For now only the SELECT response from FLDHM is considered the valid input
			*/
			if ( ((uint8)NFC_SELECT == nfcReaderFLDHMHdr.cmdId_u8 ) && ((uint8)FLDHM == nfcReaderFLDHMHdr.txEcu_u8 ))
			{
		    	/* Determines if object placed on WCPM is a Device or Card*/
		    	isCardResponse_bool = rbd_NfcIf_IsSelectResponseForCard(&FLDHM_NFCResponse_au8[NFC_PAYLOAD_INIT_BYTE],nfcReaderFLDHMHdr.payloadLength_u16, rbd_NFCVehIf_NfcCardSuccessUid_au8);
		    	keyPlaced_u8 = (isCardResponse_bool == TRUE)? DEVICE_CARD_TYPE : DEVICE_PHONE_TYPE;

				/* For NFC TapEntry verify card/phone is Enabled*/
				//once backend is merged will set value to TRUE / FALSE
				(void)Rte_Read_rbd_NFCVehIf_RP_drmServices_drmServices(&dataType);
				if((((dataType.SPKVEHUSG == TRUE) && (keyPlaced_u8 == (uint8)DEVICE_PHONE_TYPE)) || ((dataType.SPKPHSCLKEY == TRUE) && (keyPlaced_u8 == (uint8)DEVICE_CARD_TYPE))) && (proxiPhoneAsAKey_u8 == TRUE))
				{
					Rte_Call_RP_ControlFd9Bus_Cbk_ControlFd9Bus(TRUE);
					nfcEntryFailedAttemptCtr_u8 = *(Rte_Pim_FailedAttemptsCounter_MirrorBlock());
					if(0u == nfcEntryFailedAttemptCtr_u8)
					{
						(void)Rte_Read_RP_AuthenticTimeManagementStatus_UtcTime(&utcTimeStamp_u64);
						Rte_Read_RP_AuthenticTimeManagementStatus_UtcTimeValid(&data_validity_u8);
						/* ToDo -Timer starting is pending */
					}

					/* Read the DOOR status Signal */
					Rte_Read_RP_DoorLockLastElSts_DoorLockLastElSts(&door_status_fusion_u8);
					/*AXIVION Disable MisraC2012Directive-4.1: Assignment of value which does not correspond to an enumerator [(NfcVehIf_Door_Stat_EN_TYPE)&] */
					/*AXIVION Disable MisraC2012-10.5: Explicit conversion to inappropriate essential type [(uint8_t->NfcVehIf_Door_Stat_EN_TYPE)(uint8_t & uint8_t)] */
					/*AXIVION Disable MisraC2012-10.8: Composite expression is cast to different essential type category [(uint8_t->NfcVehIf_Door_Stat_EN_TYPE)(uint8_t & uint8_t)] */
					doorStatusLastNvm_en = (NfcVehIf_Door_Stat_EN_TYPE)((uint8)((door_status_fusion_u8 >> 4u) & 0x0fu));

					/*AXIVION Disable MisraC2012Directive-4.1: Assignment of value which does not correspond to an enumerator [(NfcVehIf_Door_Stat_EN_TYPE)&] */
					/*AXIVION Disable MisraC2012-10.5: Explicit conversion to inappropriate essential type [(uint8_t->NfcVehIf_Door_Stat_EN_TYPE)(uint8_t & uint8_t)] */
					/*AXIVION Disable MisraC2012-10.8: Composite expression is cast to different essential type category [(uint8_t->NfcVehIf_Door_Stat_EN_TYPE)(uint8_t & uint8_t)] */
					doorStatusLastCanBus_en = (NfcVehIf_Door_Stat_EN_TYPE)((uint8)((door_status_fusion_u8 >> 0u) & 0x0fu));
					/* Read the validity of door status signal */

					if(doorStatusLastCanBus_en < DOOR_STAT_SNA_EN)
					{
						/* CAN bus signal is available so use the CAN signal */
						door_status_loc_en = doorStatusLastCanBus_en;
						data_validity_u8 = TRUE;
					}
					else if(doorStatusLastNvm_en < DOOR_STAT_SNA_EN)
					{
						/* CAN bus signal is not available so use the NVM signal */
						door_status_loc_en = doorStatusLastNvm_en;
						data_validity_u8 = TRUE;
					}
					else
					{
						data_validity_u8 = FALSE;
						/* Both CAN and NVM signal are invalid. Most probably device born state or memeory corruption state. Do nothing.*/
					}

					if(TRUE == data_validity_u8)
					{
						rbd_NFCVehIf_ReadNFCReaderStatusInfo((uint8)FLDHM,&session_state_u8,&readerConnection_state_u8, &devRef_u8);
						if(READER_IN_SESSION == readerConnection_state_u8)
						{
							rbdSessionMgr_NfcDisconnected((uint8)FLDHM);
							(void)rbd_NFCVehIf_ResetNFCReaderSessionTag((uint8)FLDHM);
						}
						else
						{
							//misra
						}
						/*AXIVION Disable MisraC2012-10.3: Inappropriate implicit conversion from NfcEcuIds to uint8_t [FLDHM] */
						/*AXIVION Disable MisraC2012-18.1: Access into array might be out of bounds [nfcTapEntry_trans_code_lut_u8]. Array bound condition checked */
						ret = Rte_Call_RP_NfcFlow_Start_Start((uint8)FLDHM, OPERATION_NFC_ENTRY, 0,0,0,(uint8)(nfcTapEntry_trans_code_lut_u8[door_status_loc_en]),NULL,NULL);
						if(TRUE == rbd_NFCVehIf_RegisterNFCReaderSession(nfcReaderFLDHMHdr.txEcu_u8))
						{
							(void)rbd_NFCVehIf_UpdateNFCReaderState((uint8)nfcReaderFLDHMHdr.txEcu_u8, (uint8)NFC_READER_TAP_ENTRY_FLOW_INIT_STATE_E, NULL);
							/* ToDO - Start Intermediate Code until DKM fix for FFA is available */
							DevKeyListCount_u8 = 0x00u;
							(void)Rte_Call_RP_rbdDeviceMgr_GetNumberOfKeyEntries_Operation(DEVICE_TYPE_PHONE, DevKeyRefList_au8, 32u, &DevKeyListCount_u8);
							/* ToDO - End Intermediate Code until DKM fix for FFA is available */
						}
						else
						{
							Rte_Call_RP_ControlFd9Bus_Cbk_ControlFd9Bus(FALSE);
						}
					}
					else
					{
						/* Do nothing else MISRA compliance */
					}
				}
				else
				{
					(void)rbd_NFCVehIf_UpdateNFCReaderState((uint8)FLDHM,(uint8)NFC_READER_TAP_ENTRY_TEAR_DOWN_STATE_E, NULL);
					rbd_NFCVehIf_NfcTeardown((uint8)FLDHM);
				}
			}
			else
			{
				/* If its not a SELECT reponse then no need to initiate the DKM session, just act as a gateway */
			}

			/* Accept the TP messages if they are coming from FLDHM */
			if((RTE_E_OK == ret) && ((uint8)FLDHM == nfcReaderFLDHMHdr.txEcu_u8 ))
			{
				rbd_NFCVehIf_ReceiveNFCResponse( (const uint8*)FLDHM_NFCResponse_au8, responseLength_u16 );
				// clear response buffer
				if ( ( responseLength_u16 <= NFC_MAX_MESSAGE_LEN ) && ( responseLength_u16 != 0U ) )
				{
					(void)memset( FLDHM_NFCResponse_au8, 0, responseLength_u16 );
				}
				else
				{
					/* Do nothing else MISRA compliance */
				}
			}
			else
			{
				/* Reject All TP messages if they are not coming from FLDHM */
			}
		}
		else
		{

		}
		(void)utcTimeStamp_u64;
	}
	else
	{
		rbd_NFCVehIf_NfcTeardown((uint8)FLDHM);
		rbdSessionMgr_NfcDisconnected((uint8)FLDHM);
		(void)rbd_NFCVehIf_ResetNFCReaderSessionTag((uint8)FLDHM);
	}
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: rbd_NFCVehIf_NFC_READER_FRDHM_DEVICE_Sig_Callback
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <NFC_READER_FRDHM_RES_Sig> of PortPrototype <NFC_READER_FRDHM_RES_Sig>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Receive_NFC_READER_FRDHM_RES_Sig_NFC_READER_FRDHM_RES_Sig(uint8 *data, uint16* length)
 *     Argument data: uint8* is of type NFC_READER_FRDHM_RES_Sig
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: rbd_NFCVehIf_NFC_READER_FRDHM_DEVICE_Sig_Callback_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, rbd_NFCVehIf_CODE) rbd_NFCVehIf_NFC_READER_FRDHM_DEVICE_Sig_Callback(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: rbd_NFCVehIf_NFC_READER_FRDHM_DEVICE_Sig_Callback
 *********************************************************************************************************************/
	static uint8 FRDHM_NFCResponse_au8[NFC_MAX_MESSAGE_LEN];
	uint16 responseLength_u16;

	if (RTE_E_OK == Rte_Receive_rbd_NFCVehIf_NFC_READER_FRDHM_RES_Sig_NFC_READER_FRDHM_DEVICE_Sig(FRDHM_NFCResponse_au8, &responseLength_u16))
	{
		rbd_NFCVehIf_ReceiveNFCResponse( (const uint8*)FRDHM_NFCResponse_au8, responseLength_u16 );
		// clear response buffer
		if ( ( responseLength_u16 <= NFC_MAX_MESSAGE_LEN ) && ( responseLength_u16 != 0U ) )
		{
			(void)memset( FRDHM_NFCResponse_au8, 0, responseLength_u16 );
		}
		else
		{
			// do nothing for misra
		}
	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: rbd_NFCVehIf_NFC_READER_WCPM2_DEVICE_Sig_Callback
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <NFC_READER_WCPM2_RES_Sig> of PortPrototype <NFC_READER_WCPM2_RES_Sig>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Receive_NFC_READER_WCPM2_RES_Sig_NFC_READER_WCPM2_RES_Sig(uint8 *data, uint16* length)
 *     Argument data: uint8* is of type NFC_READER_WCPM2_RES_Sig
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: rbd_NFCVehIf_NFC_READER_WCPM2_DEVICE_Sig_Callback_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, rbd_NFCVehIf_CODE) rbd_NFCVehIf_NFC_READER_WCPM2_DEVICE_Sig_Callback(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: rbd_NFCVehIf_NFC_READER_WCPM2_DEVICE_Sig_Callback
 *********************************************************************************************************************/

	/* WCPM responded to SPAAK, DTC passed*/
	rbd_NFCVehIf_DTCWCMP2Timer_active_b = FALSE;
	nfcReaderResponseHeader_t nfcReaderWCPM2MHdr;
	Rte_Call_DTC_0xA16500_NfcDeviceCommunicationFailure_SetEventStatus(DEM_EVENT_STATUS_PREPASSED);


    static uint8 WCPM2_NFCResponse_au8[NFC_MAX_MESSAGE_LEN];
    uint16 responseLength_u16;

    if (RTE_E_OK == Rte_Receive_rbd_NFCVehIf_NFC_READER_WCPM2_RES_Sig_NFC_READER_WCPM2_DEVICE_Sig(WCPM2_NFCResponse_au8, &responseLength_u16))
    {
    	(void)rbd_NfcIf_NfcReaderCanTPPacketHeaderRead(WCPM2_NFCResponse_au8, &nfcReaderWCPM2MHdr);
    	/* Only Accept the TP messages coming from WCPM2 */
    	if((uint8)WCPM2 == nfcReaderWCPM2MHdr.txEcu_u8 )
    	{
			rbd_NFCVehIf_ReceiveNFCResponse((const uint8*)WCPM2_NFCResponse_au8, responseLength_u16);
			// clear response buffer
			if( (responseLength_u16 <= NFC_MAX_MESSAGE_LEN) && (responseLength_u16 != 0U) )
			{
				(void)memset(WCPM2_NFCResponse_au8, 0, responseLength_u16);
			}
			else
			{
				// do nothing for misra
			}
    	}
    	else
    	{
    		/* Reject All TP messages if they are not coming from WCPM2 */
    	}
    }

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: rbd_NFCVehIf_Test_SmartCard_Pairing_Start_RequestResults
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RequestResults> of PortPrototype <rbd_NFCVehIf_Test_SmartCard_Pairing_Start>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType rbd_NFCVehIf_Test_SmartCard_Pairing_Start_RequestResults(uint8 *Out_ResData, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_Test_SmartCard_Pairing_Start_E_NOT_OK
 *   RTE_E_Test_SmartCard_Pairing_Start_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: rbd_NFCVehIf_Test_SmartCard_Pairing_Start_RequestResults_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) rbd_NFCVehIf_Test_SmartCard_Pairing_Start_RequestResults(P2VAR(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: rbd_NFCVehIf_Test_SmartCard_Pairing_Start_RequestResults (returns application error)
 *********************************************************************************************************************/
	/*AXIVION Disable Style MisraC2012-18.1: Pointer arithmetic on Out_ResData creates pointer outside array bounds. Justify operation is valid and not out of bounds */
	Out_ResData[0] = (uint8)rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E].nfcRoutineStatus;	/* Routine status 	0x00= UnInitialized, 0x01= Success, 0x02=Progress, 0x03=Failure  	*/
	/*AXIVION Disable Style MisraC2012-18.1: Pointer arithmetic on Out_ResData creates pointer outside array bounds. Justify operation is valid and not out of bounds */
	Out_ResData[1] = (uint8)rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E].nfcRoutineErrorCode;/* Test Pairing Error Code 	Bit0= Fast Transaction Failure Bit1: Timeout Bit2:  Reader Not Ready*/
	/*AXIVION Disable Style MisraC2012-18.1: Pointer arithmetic on Out_ResData creates pointer outside array bounds. Justify operation is valid and not out of bounds */
	Out_ResData[2] = (uint8)rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E].nfcCardData_t.nfcRoutineUId[0];	/* NFC Card UID byte 0 	*/
	/*AXIVION Disable Style MisraC2012-18.1: Pointer arithmetic on Out_ResData creates pointer outside array bounds. Justify operation is valid and not out of bounds */
	Out_ResData[3] = (uint8)rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E].nfcCardData_t.nfcRoutineUId[1];	/* NFC Card UID byte 1 	*/
	/*AXIVION Disable Style MisraC2012-18.1: Pointer arithmetic on Out_ResData creates pointer outside array bounds. Justify operation is valid and not out of bounds */
	Out_ResData[4] = (uint8)rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E].nfcCardData_t.nfcRoutineUId[2];	/* NFC Card UID byte 2 	*/
	/*AXIVION Disable Style MisraC2012-18.1: Pointer arithmetic on Out_ResData creates pointer outside array bounds. Justify operation is valid and not out of bounds */
	Out_ResData[5] = (uint8)rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E].nfcCardData_t.nfcRoutineUId[3];	/* NFC Card UID byte 3 	*/
	/*AXIVION Disable Style MisraC2012-18.1: Pointer arithmetic on Out_ResData creates pointer outside array bounds. Justify operation is valid and not out of bounds */
	Out_ResData[6] = (uint8)rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E].nfcCardData_t.nfcRoutineUId[4];	/* NFC Card UID byte 4 	*/
	/*AXIVION Disable Style MisraC2012-18.1: Pointer arithmetic on Out_ResData creates pointer outside array bounds. Justify operation is valid and not out of bounds */
	Out_ResData[7] = (uint8)rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E].nfcCardData_t.nfcRoutineUId[5];	/* NFC Card UID byte 5 	*/
	/*AXIVION Disable Style MisraC2012-18.1: Pointer arithmetic on Out_ResData creates pointer outside array bounds. Justify operation is valid and not out of bounds */
	Out_ResData[8] = (uint8)rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E].nfcCardData_t.nfcRoutineUId[6];	/* NFC Card UID byte 6 	*/

	*ErrorCode = DCM_E_POSITIVERESPONSE;
    return RTE_E_OK;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: rbd_NFCVehIf_Test_SmartCard_Pairing_Start_Start
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <Start> of PortPrototype <rbd_NFCVehIf_Test_SmartCard_Pairing_Start>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType rbd_NFCVehIf_Test_SmartCard_Pairing_Start_Start(Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_Test_SmartCard_Pairing_Start_E_NOT_OK
 *   RTE_E_Test_SmartCard_Pairing_Start_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: rbd_NFCVehIf_Test_SmartCard_Pairing_Start_Start_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) rbd_NFCVehIf_Test_SmartCard_Pairing_Start_Start(P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: rbd_NFCVehIf_Test_SmartCard_Pairing_Start_Start (returns application error)
 *********************************************************************************************************************/

    uint8 ret_u8 = E_NOT_OK;

    if (FALSE == rbd_NFCVehIf_IsRoutineInProgress())
    {
    	rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E].DiagRoutine_State_en = NFC_DIAG_ROUTINE_REQUEST_RX_STATE_E;
    	ret_u8 = E_OK;
    	*ErrorCode = DCM_E_POSITIVERESPONSE;
    }
    else
    {
    	*ErrorCode =  DCM_E_GENERALREJECT;
    }

    return ret_u8;

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

 //----------------------------------------------------------------------------
 //! \brief
 //! Initializes Nfc Tag table array to default values
 //!
 //! \param [in] NfcReaderId_u8 ECU ID of the Nfc Reader SPAAK is in communication with
 //!
 //! \return
 //!  None
 //----------------------------------------------------------------------------
static uint8 rbd_NFCVehIf_ResetNFCReaderSessionTag( const uint8 NfcReaderId_u8 )
{
	uint8 ret = FALSE;
	if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) )
	{
		rbd_NFCVehIf_Table_as[NfcReaderId_u8].connectionStatus_u8 = READER_DISCONNECTED;
		rbd_NFCVehIf_Table_as[NfcReaderId_u8].Key_Card_Ref_b = RBDPK_KEYREF_INVALID;
		rbd_NFCVehIf_Table_as[NfcReaderId_u8].activeState_u8 = (uint8)NFC_READER_NOT_ACTIVE_STATE_E;
		rbd_NFCVehIf_Table_as[NfcReaderId_u8].session_timeout_u16 = NFC_SESSION_TIMEOUT;
		ret = TRUE;
	}
	else
	{
	}

	return ret;
}

//----------------------------------------------------------------------------
//! \brief      rbd_NFCVehIf_RegisterNFCReaderSession
//!             Register a new NFC session in rbd_NFCVehIf_Table_as
//! \return		TRUE in case of SUCCESS
//!             FALSE otherwise
//!  None
//----------------------------------------------------------------------------
static uint8 rbd_NFCVehIf_RegisterNFCReaderSession( const uint8 NfcReaderId_u8 )
{
	uint8 ret = FALSE;
	if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) )
	{
		if ( READER_DISCONNECTED == rbd_NFCVehIf_Table_as[NfcReaderId_u8].connectionStatus_u8 )
		{
			rbd_NFCVehIf_Table_as[NfcReaderId_u8].connectionStatus_u8 = READER_IN_SESSION;
			rbd_NFCVehIf_Table_as[NfcReaderId_u8].Key_Card_Ref_b = RBDPK_KEYREF_INVALID;
			rbd_NFCVehIf_Table_as[NfcReaderId_u8].session_timeout_u16 = NFC_SESSION_TIMEOUT;
			/* NfcReaderId_u8[NfcReaderId_u8].activeState_u8 = (uint8)NFC_READER_NOT_ACTIVE_STATE_E; */
			/* rbd_NFCVehIf_Table_as[NfcReaderId_u8].session_timeout_u16 = initSessionTout_u16; */
			ret = TRUE;
		}
		else
		{

		}
	}
	else
	{
	}

	return ret;
}

//----------------------------------------------------------------------------
//! \brief      rbd_NFCVehIf_UpdateNFCReaderState
//!             Set the new state for the said reader
//!
//! \param [in] NfcReaderId_u8: Reader ID
//! \param [out] newState_u8: The new state to be set
//! \param [in] newDevRef_pu8: Optionally update the DevRef if passed as non NULL.
//! \return		TRUE in case of SUCCESS
//!             FALSE otherwise
//!  None
//----------------------------------------------------------------------------
static uint8 rbd_NFCVehIf_UpdateNFCReaderState( const uint8 NfcReaderId_u8, const uint8 newState_u8, const uint8 * newDevRef_pu8)
{
	uint8 ret = FALSE;
	/*AXIVION Disable MisraC2012-2.2 : Redundant code, parameter comparison to NULL is always true[NfcReaderId_u8] */
	/*AXIVION Disable MisraC2012-14.3 : Redundant code, parameter comparison to NULL is always true. Deviation comparisons are valid here.Else branch is not dead */
	if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) )
	{
		rbd_NFCVehIf_Table_as[NfcReaderId_u8].activeState_u8 = newState_u8;
		if(NULL != newDevRef_pu8)
		{
			rbd_NFCVehIf_Table_as[NfcReaderId_u8].Key_Card_Ref_b = *newDevRef_pu8;
		}
		ret = TRUE;
	}
	else
	{
	}
	return ret;
}

//----------------------------------------------------------------------------
//! \brief      rbd_NFCVehIf_ReadNFCReaderStatusInfo
//!             Read the info of the NFC Reader Session
//!
//! \param [in] NfcReaderId_u8: NFC Reader ID
//! \param [out] sessionState_u8: NFC Reader Session state
//! \param [out] readerConnectState_u8: NFC Reader Connection state
//! \param [out] deviceRef_u8: device Ref
//! \return		None
//!  None
//----------------------------------------------------------------------------
static void rbd_NFCVehIf_ReadNFCReaderStatusInfo( const uint8 NfcReaderId_u8,
	uint8 *sessionState_u8, uint8 *readerConnectState_u8, uint8 *deviceRef_u8 )
{
	/*AXIVION Disable MisraC2012-2.2 : Redundant code, parameter comparison to NULL is always true[sessionState_u8] - Deviation ptr(sessionState_u8, readerConnectState_u8) could be NULL */
	/*AXIVION Disable MisraC2012-14.3 : Redundant code, parameter comparison to NULL is always true. Deviation comparisons are valid here.Else branch is not dead */
	if ( ( NfcReaderId_u8 < NFC_NUM_READERS ) && ( NULL != sessionState_u8 )
		&& ( NULL != readerConnectState_u8 ) )
	{
		*sessionState_u8 = rbd_NFCVehIf_Table_as[NfcReaderId_u8].activeState_u8;
		*readerConnectState_u8 = rbd_NFCVehIf_Table_as[NfcReaderId_u8].connectionStatus_u8;
		*deviceRef_u8 = rbd_NFCVehIf_Table_as[NfcReaderId_u8].Key_Card_Ref_b;
	}
	else
	{
	}
}

//----------------------------------------------------------------------------
//! \brief      rbd_NFCVehIf_UpdateNFCReaderSessionTimeOut
//!             Update the timeout value during NFC session/flow
//!
//! \param [in] NfcReaderId_u8: NFC Reader ID
//! \param [out] sessionTout_u16: NFC session Timeout
//! \param [out] readerConnectState_u8: NFC Reader Connection state
//!  None
//----------------------------------------------------------------------------
static void rbd_NFCVehIf_UpdateNFCReaderSessionTimeOut( const uint8 NfcReaderId_u8,
	const uint16 sessionTout_u16)
{
	if ( ( NfcReaderId_u8 < NFC_NUM_READERS )  && (READER_IN_SESSION == rbd_NFCVehIf_Table_as[NfcReaderId_u8].connectionStatus_u8))
	{
		rbd_NFCVehIf_Table_as[NfcReaderId_u8].session_timeout_u16 = sessionTout_u16;
	}
	else
	{
	}
}

//----------------------------------------------------------------------------
//! \brief      rbd_NFCVehIf_NFCReaderSessionTimeOutManager
//!             Periodically check the NFC session for timeout and if timeout
//!             occurs then fress up the session, so it can accomdate new session
//!             later on.
//!
//! \param [in] NfcReaderId_u8: NFC Reader ID
//! \param [out] sessionTout_u16: NFC session Timeout
//! \param [out] readerConnectState_u8: NFC Reader Connection state
//!  None
//----------------------------------------------------------------------------
static void rbd_NFCVehIf_NFCReaderSessionTimeOutManager(void)
{
	uint8 NfcReaderId_u8 = 0x00u;

	for ( NfcReaderId_u8 = 0u; NfcReaderId_u8 < NFC_NUM_READERS; NfcReaderId_u8++ )
	{
		if ( READER_IN_SESSION == rbd_NFCVehIf_Table_as[NfcReaderId_u8].connectionStatus_u8 )
		{
			rbd_NFCVehIf_Table_as[NfcReaderId_u8].session_timeout_u16 =
				( rbd_NFCVehIf_Table_as[NfcReaderId_u8].session_timeout_u16 != 0u ) ?
					( rbd_NFCVehIf_Table_as[NfcReaderId_u8].session_timeout_u16 - (uint16)1u ) : (uint16)0u;

			if(0u == rbd_NFCVehIf_Table_as[NfcReaderId_u8].session_timeout_u16)
			{
				rbd_NFCVehIf_NfcTeardown(NfcReaderId_u8);
                (void)rbd_NFCVehIf_ResetNFCReaderSessionTag(NfcReaderId_u8);
                rbdSessionMgr_NfcDisconnected(NfcReaderId_u8);
			}
			else
			{
				/* Do Nothing */
			}
		}
		else
		{
			/* Do Nothing */
		}
	}

}
//----------------------------------------------------------------------------
//! \brief
//! Function that aligns data in NFC reader format
//!
//! \param [in] request_pt Pointer to start of nfc request buffer
//! \param [in] comId_u8 NFC command id
//! \param [in] dest_u8 Represents ECU ID of the target NFC Reader for this request
//! \param [in] payLen_u16 length of payload
//! \param [in] payload_pt pointer to payload data
//!
//! \return
//!  None
//----------------------------------------------------------------------------
static void rbd_NFCVehIf_PrepNFCBuffer(uint8 *request_pt, const uint8 comId_u8, const uint8 dest_u8, const uint16 payLen_u16, const uint8* payload_pt)
{
	nfcReaderResponseHeader_t nfcReaderMsgHdr;
	/* Fill in the header details */
	nfcReaderMsgHdr.cmdId_u8 = (uint8)comId_u8;
	nfcReaderMsgHdr.rxEcu_u8 = (uint8)dest_u8;
	nfcReaderMsgHdr.txEcu_u8 = (uint8)SPAAK;
	nfcReaderMsgHdr.payloadLength_u16 = (uint16)payLen_u16;
	/* Prepare the header */
	rbd_NfcIf_NfcReaderCanTPPacketHeaderWrite(request_pt,&nfcReaderMsgHdr);

    // Transfer payload:
    if(payLen_u16 <= ((uint16)MAX_LENGTH_CAPDU - (uint16)NFC_PAYLOAD_INIT_BYTE - (uint16)1U))
    {
        (void)memcpy(&request_pt[NFC_PAYLOAD_INIT_BYTE], payload_pt, payLen_u16); /*AXIVION Line MisraC2012-21.18: Size may be too large for pointers passed in and size might be zero. Deviation InternalBosch_FalsePositive_A: Ticket 1198131. Already checking the size to be within range */
    }
    else
    {
        // do nothing for misra
    }
}

//----------------------------------------------------------------------------
//! \brief
//! Function that chooses the correct Rte port to write buffer to based on ecu id
//!
//! \param [in] dest_u8 Represents ECU ID of the target NFC Reader for this communication
//! \param [in] request_pt Points to request buffer
//! \param [in] length_u16 length of buffer
//! \param [out] ret return of Rte write
//!
//! \return
//!  Status of Rte write
//----------------------------------------------------------------------------
static Std_ReturnType rbd_NFCVehIf_WritePort(const uint8 dest_u8, const uint8 *request_pt, const uint16 length_u16)
{
    Std_ReturnType ret = E_NOT_OK;
	uint8 devRef_u8 = 0xffu;
	uint8 session_state_u8  = (uint8)NFC_READER_NOT_ACTIVE_STATE_E;
	uint8 readerConnection_state_u8 = READER_DISCONNECTED;

	rbd_NFCVehIf_ReadNFCReaderStatusInfo((uint8)dest_u8,&session_state_u8,&readerConnection_state_u8, &devRef_u8);
	if((uint8)NFC_READER_GET_UID_STATE_E != session_state_u8)
	{
		rbd_NFCVehIf_UpdateNFCReaderSessionTimeOut(dest_u8, NFC_SESSION_TIMEOUT);
	}
	else
	{
	}
    if (dest_u8 == (uint8)FLDHM)
    {
        ret = Rte_Send_NFC_READER_REQ_FLDHM_Sig_NFC_READER_DEVICE_2_Sig(request_pt, length_u16);
    }
    else if (dest_u8 == (uint8)FRDHM)
    {
        ret = Rte_Send_NFC_READER_REQ_FRDHM_Sig_NFC_READER_DEVICE_3_Sig(request_pt, length_u16);
    }
    else if (dest_u8 == (uint8)WCPM2)
    {
      /*start timer to determine if WCPM responds*/
      if(rbd_NFCVehIf_DTCWCMP2Timer_active_b == FALSE)
      {
        rbd_NFCVehIf_DTCWCPMTimer_u16 = Rte_CData_cp_NFC_Device_Request_Timer() * 1000u;
      }
      rbd_NFCVehIf_DTCWCMP2Timer_active_b = TRUE;
      ret = Rte_Send_NFC_READER_REQ_WCPM2_Sig_NFC_READER_DEVICE_1_Sig(request_pt, length_u16);

    }
    else
    {
        // error handling
    }
    (void)readerConnection_state_u8;
    (void)devRef_u8;
    return ret;
}

//----------------------------------------------------------------------------
//! \brief
//! Mapping function to convert CCC ID to NFC ID
//!
//! \param [in] cccCommandId_u16 CCC Command ID
//! \param [out] tempNFCComID_u8 NFC Command ID
//!
//! \return
//!  NFC Command ID
//----------------------------------------------------------------------------
static uint8 rbd_NFCVehIf_MapCCCToNFC(const uint16 cccCommandId_u16)
{
    uint8 tempNFCComID_u8 = (uint8)NFC_DEFAULT;
    boolean command_found_b = FALSE;
    /* Mapping table for CCC / NFC Command IDs: Pushed to flash */
    const uint16 commandIdMapTable[CCC_COMMAND_COUNT][2u] =
    {
    	 /* CCC Command             Stellantis Cmd ID on CAN TP */
		 {CCC_SELECT, 				NFC_SELECT				},
		 {CCC_SPAKE2PLUSREQUEST,	NFC_SPAKE2PLUSREQUEST	},
		 {CCC_SPAKE2PLUSVERIFY, 	NFC_SPAKE2PLUSVERIFY	},
		 {CCC_WRITEDATA, 			NFC_WRITEDATA			},
		 {CCC_GETDATA, 				NFC_GETDATA				},
		 {CCC_GETRESPONSE, 			NFC_GETRESPONSE			},
		 {CCC_CONTROLFLOW, 			NFC_CONTROLFLOW			},
		 {CCC_AUTH0, 				NFC_AUTH0				},
		 {CCC_AUTH1, 				NFC_AUTH1				},
		 {CCC_PRESENCE0, 			NFC_PRESENCE0			},
		 {CCC_PRESENCE1, 			NFC_PRESENCE1			},
		 {CCC_READBUFFER, 			NFC_READBUFFER			},
		 {CCC_EXCHANGE, 			NFC_EXCHANGE			},
		 {CCC_STS0, 				NFC_STS0				},
		 {CCC_STS1, 				NFC_STS1				},
		 {CCC_CREATEENDPOINT, 		NFC_CREATEENDPOINT		},
		 {CCC_TERMINATEENDPOINT, 	NFC_TERMINATEENDPOINT	},
		 {CCC_DELETEENDPOINT, 		NFC_DELETEENDPOINT		},
		 {CCC_VIEW, 				NFC_VIEW				},
		 {CCC_WRITEBUFFER, 			NFC_WRITEBUFFER			},
    };

	/*AXIVION Disable MisraC2012-14.2 :  Loop condition shall not use objects modified in the loop body (other than loop control flags) [command_found_b]. Deviation - Condition evaluated */
    for (uint8 i_u8 = 0u; ((i_u8 < CCC_COMMAND_COUNT) && (FALSE == command_found_b)); ++i_u8)
    {
        if(cccCommandId_u16 == commandIdMapTable[i_u8][CCC_ID_COL])
        {
            tempNFCComID_u8 = (uint8)commandIdMapTable[i_u8][NFC_ID_COL];
            command_found_b = TRUE;
        }
    }

    return tempNFCComID_u8;
}

//----------------------------------------------------------------------------
//! \brief
//! Cfg function called by DKM to notify the launch of an owner pairing session
//!
//! \param [in] Enable boolean representing whether entering owner pairing
//!
//! \return
//!  None
//----------------------------------------------------------------------------
void rbd_NFCVehIf_SetOwnerPairingMode(boolean const Enable)
{
    if (Enable == TRUE)
    {
        (void)rbd_NFCVehIf_UpdateNFCReaderState((uint8)WCPM2, (uint8)NFC_READER_OWNER_PAIRING_STATE_E, NULL);
        rbdSessionMgr_NfcConnected((uint8)WCPM2, TRUE, DEVICE_PHONE_TYPE);
    }
}


//----------------------------------------------------------------------------
//! \brief
//! Function sets the DTC based on if the reader responded to SPAAK in a given amount of time withing a max amount of tries
//!
//! \param [in] nfcReaderId_u8 ID of reader that did not respond to SPAAK
//!
//! \return
//!  None
//----------------------------------------------------------------------------
static void rbd_NFCVehIf_DTC(void)
{
	//clear dtc if recieve response
	uint8 wcpm2_auth_failure_counter_u8 = 0x00U;
	uint8 max_auth_failure_counter_u8 = Rte_CData_cp_NFC_Device_Request_Counter();

	/* Add 1 to WCPM counter indicating WCPM did not respond to Spaak Req*/
	wcpm2_auth_failure_counter_u8 = *(Rte_Pim_rbd_NFCVehIf_WCMP_FailedAttempts_Counter_MirrorBlock());
	wcpm2_auth_failure_counter_u8 ++;
	if(max_auth_failure_counter_u8 <= wcpm2_auth_failure_counter_u8)
	{
		/* WCPM did not response max amount of times resulting in DTC error*/
		Rte_Call_DTC_0xA16500_NfcDeviceCommunicationFailure_SetEventStatus(DEM_EVENT_STATUS_PREFAILED);
		wcpm2_auth_failure_counter_u8 = 0x00U;
	}

  /* Update NVM counter block */
	*(Rte_Pim_rbd_NFCVehIf_WCMP_FailedAttempts_Counter_MirrorBlock()) = wcpm2_auth_failure_counter_u8;
	Rte_Call_rbd_NFCVehIf_WCMP_FailedAttempts_Counter_WriteBlock(Rte_Pim_rbd_NFCVehIf_WCMP_FailedAttempts_Counter_MirrorBlock());

  Rte_Write_PP_CanRequest_DkmNfc_ComRequest(FALSE);
	rbd_NFCVehIf_DTCWCMP2Timer_active_b = FALSE;
}

//----------------------------------------------------------------------------
//! \brief
//! API function that constructs and transmits a Deselect command to the NFC Reader of whose ID is passed as input
//! Then this function resets the state parameters accordingly
//!
//! \param [in] nfcReaderId_u8 ID of reader we are deselecting from
//!
//! \return
//!  None
//----------------------------------------------------------------------------
void rbd_NFCVehIf_NfcTeardown(const rbdPk_NfcReaderId_t nfcReaderId)
{
	uint8 devRef_u8 = 0xffu;
	uint8 session_state_u8  = (uint8)NFC_READER_NOT_ACTIVE_STATE_E;
	uint8 readerConnection_state_u8 = READER_DISCONNECTED;
    NfcVehIf_NfcReader_DESELECT_EN_TYPE typeDeselect_en = NFC_READER_DESELECT_NORMAL_TYPE_E;
    uint8 retryDeselectAttempts_u8 = 0u;

	rbd_NFCVehIf_ReadNFCReaderStatusInfo((uint8)nfcReaderId,&session_state_u8, &readerConnection_state_u8, &devRef_u8);
	switch((NfcEcuIds)nfcReaderId)
	{
		case WCPM2:
				rbd_NFCVehIf_NFC_Count -= (rbd_NFCVehIf_NFC_Count > 0U) ? 1U : 0U;
				(void)Rte_Write_PP_Nfc_Count_Devices(rbd_NFCVehIf_NFC_Count);
				if(((uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_CARD_PLANT_PAIR_TEAR_DOWN_STATE_E == session_state_u8) ||
					((uint8)NFC_READER_CARD_PLANT_TEST_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_CARD_PLANT_TEST_TEAR_DOWN_STATE_E == session_state_u8))
				{
					retryDeselectAttempts_u8 = 2u;
					/* In case of pairing and Get UID apply two retries */
				}
				else if(((uint8)NFC_READER_TAP_START_TEAR_DOWN_STATE_E == session_state_u8) ||
					    ((uint8)NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E == session_state_u8))
				{
					/* The DKM flow for Tap start is bit different and we should not send any DESLECT until CMAC2 is sent out */
					retryDeselectAttempts_u8 = 0u;
				}
				else
				{
					retryDeselectAttempts_u8 = 1u;
				}

				if(((uint8)NFC_READER_TAP_START_STOP_TRIGGER_STATE_E == session_state_u8) ||
					((uint8)NFC_READER_TAP_START_FLOW_INIT_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_GET_UID_STATE_E == session_state_u8) ||
				   ((uint8)NFC_READER_GET_UID_TEAR_DOWN_STATE_E == session_state_u8))
				{
					typeDeselect_en = NFC_READER_DESELECT_DISABLE_TYPE_E;
				}
				else
				{
					typeDeselect_en = NFC_READER_DESELECT_NORMAL_TYPE_E;
				}

			break;

		case FLDHM:
			/* Wait for toggle operation to finish before resetting */
			if((uint8)NFC_READER_TAP_ENTRY_TEAR_DOWN_STATE_E == session_state_u8)
			{
				retryDeselectAttempts_u8 = 1u;
				typeDeselect_en = NFC_READER_DESELECT_NORMAL_TYPE_E;
				(void)rbd_NFCVehIf_ResetNFCReaderSessionTag((uint8)FLDHM);
			}
			break;

		case FRDHM:
			retryDeselectAttempts_u8 = 0u;
			typeDeselect_en = NFC_READER_DESELECT_NORMAL_TYPE_E;
			break;

		default:
			retryDeselectAttempts_u8 = 0u;
			typeDeselect_en = NFC_READER_DESELECT_NORMAL_TYPE_E;
			break;

	}

	rbd_NFCVehIf_DESELECT_TimerRetry_Reload((NfcEcuIds)nfcReaderId,typeDeselect_en,retryDeselectAttempts_u8);
}

//----------------------------------------------------------------------------
//! \brief rbd_NFCVehIf_DESELECT_TimerRetry_Reload
//! Reloads the Deselect Timer infor for the DESELECT Request to be sent out
//!
//! \param [in] nfcReaderId encodes ecu id of nfc reader
//! \param [in] deselect_type_en DESELECT Request type to be sent out
//! \param [in] retryCount_u8 Number of retries to be done
//!
//! \return void/none
//!  None
//----------------------------------------------------------------------------
static void rbd_NFCVehIf_DESELECT_TimerRetry_Reload(const NfcEcuIds readerId, const NfcVehIf_NfcReader_DESELECT_EN_TYPE deselect_type_en, const uint8 retryCount_u8)
{
	rbd_NFCVehIf_DeselectInfo_S.nfcReaderId_en = readerId;
	rbd_NFCVehIf_DeselectInfo_S.reqRetryCount_u8 = retryCount_u8;
	rbd_NFCVehIf_DeselectInfo_S.typeDeselect_u8 = (uint8)deselect_type_en;
	rbd_NFCVehIf_DeselectInfo_S.retryTimer_u32 = 0x00u;
	rbd_NFCVehIf_DeselectInfo_S.uRetryFinish_u8 = FALSE;
}

//----------------------------------------------------------------------------
//! \brief rbd_NFCVehIf_Deselect_TxManager_Cyclic
//! Handles the transmission of Deselect Request to the NFC reader
//!
//! \param [in] void
//! \param [in] void
//!
//! \return TRUE if it finished the last retry FALSE otherwise
//!  None
//----------------------------------------------------------------------------
static void rbd_NFCVehIf_Deselect_TxManager_Cyclic(void)
{
	if((0x00U == rbd_NFCVehIf_DeselectInfo_S.retryTimer_u32) &&
		(rbd_NFCVehIf_DeselectInfo_S.reqRetryCount_u8 > 0x00u))
	{
		rbd_NFCVehIf_DeselectInfo_S.retryTimer_u32 = NFC_DESELECT_RETRY_TIMEOUT;
		rbd_NFCVehIf_DeselectInfo_S.reqRetryCount_u8 --;

		rbd_NFCVehIf_PrepNFCBuffer(rbd_NFCVehIf_Request_au8, (uint8)NFC_DESELECT, (uint8)rbd_NFCVehIf_DeselectInfo_S.nfcReaderId_en, NFC_TEARDOWN_PAYLOAD_LEN, &rbd_NFCVehIf_DeselectInfo_S.typeDeselect_u8);
		(void)rbd_NFCVehIf_WritePort((uint8)rbd_NFCVehIf_DeselectInfo_S.nfcReaderId_en, rbd_NFCVehIf_Request_au8, NFC_TEARDOWN_LEN);
		/* clear request buffer */
		(void)memset(rbd_NFCVehIf_Request_au8, 0x00u, NFC_TEARDOWN_LEN);
	}
	else
	{
		if(rbd_NFCVehIf_DeselectInfo_S.retryTimer_u32 > 0x00u)
		{
			rbd_NFCVehIf_DeselectInfo_S.retryTimer_u32 =
  	  				( rbd_NFCVehIf_DeselectInfo_S.retryTimer_u32 >= (uint16)NFC_CYCLE_TIME ) ?
  	  					( rbd_NFCVehIf_DeselectInfo_S.retryTimer_u32 - NFC_CYCLE_TIME ) : 0x00u; /*AXIVION Line MisraC2012-21.18: Cycle time make be larger than Card Timer Deviation InternalBosch_FalsePositive_A: Ticket 1198131. Already checking the size to be within range */
			rbd_NFCVehIf_DeselectInfo_S.uRetryFinish_u8 = ((rbd_NFCVehIf_DeselectInfo_S.retryTimer_u32 == 0x00u) && (rbd_NFCVehIf_DeselectInfo_S.reqRetryCount_u8 ==  0x00u))?TRUE:FALSE;
		}
		else
		{
		}
	}
}

//----------------------------------------------------------------------------
//! \brief rbd_NFCVehIf_IsDeselectRetryTmr_Expired
//! Give sthe status of DESELECT Timer
//!
//! \param [in] void
//! \param [in] void
//!
//! \return TRUE if DESELCT timer has just expired FALSE otherwise
//!  None
//----------------------------------------------------------------------------
static uint8 rbd_NFCVehIf_IsDeselectRetryTmr_Expired(void)
{
	return rbd_NFCVehIf_DeselectInfo_S.uRetryFinish_u8;
}

//----------------------------------------------------------------------------
//! \brief rbd_NFCVehIf_IsDeselectRetry_InProgress
//! Give sthe status of DESELECT Timer
//!
//! \param [in] void
//! \param [in] void
//!
//! \return TRUE if DESELCT Retries Ongoing
//!  None
//----------------------------------------------------------------------------
static uint8 rbd_NFCVehIf_IsDeselectRetry_InProgress(void)
{
	return (((rbd_NFCVehIf_DeselectInfo_S.retryTimer_u32 != 0x00u) || (rbd_NFCVehIf_DeselectInfo_S.reqRetryCount_u8 >  0x00u))?TRUE:FALSE);
}

//----------------------------------------------------------------------------
//! \brief
//! Function that constructs and transmits a StartPolling command to the passed target ECU (Nfc Reader)
//!
//! \param [in] ecuRx_u8 Represents ECU ID of the target NFC Reader for this communication
//! \param [in] DigitalKeyFrameworkId Points to aid buffer, either Framework OR Applet
//!
//! \return
//!  None
//----------------------------------------------------------------------------
static void rbd_NFCVehIf_NfcStartPolling(const uint8 ecuRx_u8, const uint8* const DigitalKeyFrameworkId)
{
    rbd_NFCVehIf_PrepNFCBuffer(rbd_NFCVehIf_Request_au8, (uint8)NFC_STARTPOLLING, (uint8)ecuRx_u8, AID_LENGTH, DigitalKeyFrameworkId);

    (void)rbd_NFCVehIf_WritePort(ecuRx_u8, rbd_NFCVehIf_Request_au8, (uint16)(NFC_PAYLOAD_INIT_BYTE+AID_LENGTH));

    // clear request buffer
    (void)memset(rbd_NFCVehIf_Request_au8, 0, NFC_PAYLOAD_INIT_BYTE+AID_LENGTH);
}

//----------------------------------------------------------------------------
//! \brief
//! DKM Cfg Function that passes correct aid to the local start polling function
//!
//! \param [in] nfcReaderId encodes ecu id of nfc reader
//! \param [in] DigitalKeyFrameworkId encodes framework aid OR applet aid to send to nfc reader
//!
//! \return
//!  None
//----------------------------------------------------------------------------
void rbd_NFCVehIf_DkmStartPolling(const rbdPk_NfcReaderId_t nfcReaderId, const uint8* const DigitalKeyFrameworkId)
{
    rbd_NFCVehIf_NfcStartPolling((uint8)nfcReaderId, DigitalKeyFrameworkId);
	(void)rbd_NFCVehIf_RegisterNFCReaderSession((uint8)nfcReaderId);
}

//----------------------------------------------------------------------------
//! \brief
//! Function for DKM to call when sending a CCC/STS request to the Nfc tag at the reader
//!
//! \param [in] Data The pointer to the request array
//! \param [in] Length The length of the request array, starting from the passed pointer
//! \param [in] nfcReaderId The ECU ID with the device in communication
//! \param [out] retFinal boolean result of Rte CAN message transmission
//!
//! \return
//!  retFinal
//----------------------------------------------------------------------------
/*AXIVION Disable MisraC2012-18.1 : Deviation InternalBosch_18_1_A - Out of Bounds Memory Access Through Data - Temp Until Bauhaus is Fixed */
boolean rbd_NFCVehIf_SendNfcMsg(const rbdPk_NfcReaderId_t nfcReaderId, const uint16 Length, const uint8* const Data)
{
    boolean retFinal_b = FALSE;
    static uint16 cccComId_u16;
    static uint8 nfcComId_u8;
    uint16 requestLength_u16 = 0;
    uint16 payLength_u16 = 0;

    // check there are at least 3 bytes in the buffer
    if ((Length > CCC_ID_LENGTH) && (Length < MAX_LENGTH_CAPDU))
    {
        payLength_u16 = Length - CCC_ID_LENGTH;
        requestLength_u16 = Length + CCC_ID_LENGTH;

        // Extract CCC Command ID encoded in first 2 bytes:
        cccComId_u16 = (((uint16)Data[CCC_CLA_BYTE]) << 8) | ((uint16)Data[CCC_INS_BYTE]);

        // Map CCC to NFC Command ID:
        nfcComId_u8 = rbd_NFCVehIf_MapCCCToNFC(cccComId_u16);

        // load request buffer
        rbd_NFCVehIf_PrepNFCBuffer(rbd_NFCVehIf_Request_au8, nfcComId_u8, nfcReaderId, payLength_u16, &Data[CCC_ID_LENGTH]);


        // Send to appropriate Reader:
        if(RTE_E_OK == rbd_NFCVehIf_WritePort(nfcReaderId, rbd_NFCVehIf_Request_au8, requestLength_u16))
        {
            retFinal_b = TRUE;
        }
        else
        {
            retFinal_b = FALSE;
        }

        // clear request buffer
        if (requestLength_u16 <= MAX_LENGTH_CAPDU)
        {
        	(void)memset(rbd_NFCVehIf_Request_au8, 0, requestLength_u16);
        }
        else
        {
            // do nothing for misra
        }
    }
    else
    {
        // error handling
    }

    return retFinal_b;
}

//----------------------------------------------------------------------------
//! \brief
//! Function that checks NFC response for Status, FailureMode, or UIDS, else calls rbd_NFCVehIf_ProcessCCCResponse()
//!
//! \param [in] nfcResponse_pt The pointer to the response array read from COM port
//! \param [in] nfcResponseLength_u16 The length of the message in read buffer
//!
//! \return
//!  None
//----------------------------------------------------------------------------
static void rbd_NFCVehIf_ReceiveNFCResponse( const uint8 *nfcResponse_pt,
	const uint16 nfcResponseLength_u16 )
{
	uint8 devRef_u8 = 0xffu;
	uint8 session_state_u8 = (uint8)NFC_READER_NOT_ACTIVE_STATE_E;
	uint8 readerConnection_state_u8 = READER_DISCONNECTED;
	nfcReaderResponseHeader_t nfcReaderHdr;
	uint8 performDeInit = TRUE;

	if ( nfcResponseLength_u16 >= (uint16)NFC_PAYLOAD_INIT_BYTE )
	{
		(void)rbd_NfcIf_NfcReaderCanTPPacketHeaderRead( nfcResponse_pt, &nfcReaderHdr );

		// check for NFC control commands before sending for ccc processing
		if ( nfcReaderHdr.cmdId_u8 == (uint8)NFC_STATUS )
		{
			rbd_NFCVehIf_ReadNFCReaderStatusInfo( (uint8)nfcReaderHdr.txEcu_u8, &session_state_u8,
				&readerConnection_state_u8, &devRef_u8 );
			switch ( nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE] )
			{
				case READY:
				{
					/* Stop sending the DESELECT */
					rbd_NFCVehIf_DESELECT_TimerRetry_Reload( (NfcEcuIds)nfcReaderHdr.txEcu_u8,
						NFC_READER_DESELECT_DISABLE_TYPE_E, 0u );
					// send no toggle request to fldhm
					if ( (uint8)nfcReaderHdr.txEcu_u8 == (uint8)FLDHM )
					{
						rbdSessionMgr_NfcDisconnected( (uint8)nfcReaderHdr.txEcu_u8 );
						rbd_RfhmIf_SendNfcToggleReq( NO_TOGGLE, 0, RBDPK_KEYREF_INVALID );
					}

					// if this ready is following a final AuthStatus cbk for WCPM, then teardown session
					if ( ( (uint8)NFC_READER_TAP_START_STOP_TRIGGER_STATE_E == session_state_u8 ) ||
						( (uint8)NFC_READER_OWNER_PAIRING_TEAR_DOWN_STATE_E == session_state_u8 ) ||
						( (uint8)NFC_READER_CARD_PLANT_PAIR_TEAR_DOWN_STATE_E == session_state_u8 )
						||
						( (uint8)NFC_READER_CARD_PLANT_TEST_TEAR_DOWN_STATE_E == session_state_u8 )
						||
						( (uint8)NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_FINISH_STATE_E
							== session_state_u8 ) )
					{
						(void)rbd_NFCVehIf_ResetNFCReaderSessionTag( (uint8)nfcReaderHdr.txEcu_u8 );
						rbdSessionMgr_NfcDisconnected( (uint8)nfcReaderHdr.txEcu_u8 );
					}
					else
					{
						// notify DKM that Nfc reader is ready
						(void)rbdSessionMgr_NfcReady( (uint8)nfcReaderHdr.txEcu_u8 );
					}
					performDeInit = FALSE;
				}
				break;

				case DEVICEREMOVED:
				{
					// send no toggle request to fldhm
					if ( (uint8)nfcReaderHdr.txEcu_u8 == (uint8)FLDHM )
					{
						rbd_RfhmIf_SendNfcToggleReq( NO_TOGGLE, 0, (uint8)RBDPK_KEYREF_INVALID );
					}
					else if ( (uint8)nfcReaderHdr.txEcu_u8 == (uint8)WCPM2 )
					{
						if ( ( session_state_u8 == (uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E ) ||
							( session_state_u8 == (uint8)NFC_READER_CARD_PLANT_TEST_STATE_E ) ||
							( session_state_u8 == (uint8)NFC_READER_TAP_START_FLOW_INIT_STATE_E ) ||
							( session_state_u8 == (uint8)NFC_READER_GET_UID_STATE_E ) )
						{
							rbd_NFCVehIf_SetEvent( NFC_WCPM_DEVICEMOVED_EVENT );
						}
						else
						{
							Rte_Write_PP_CanRequest_DkmNfc_ComRequest( FALSE );
						}
					}
					else
					{
						Rte_Write_PP_CanRequest_DkmNfc_ComRequest( FALSE );
					}
				}
				break;

				case NOTREADY:
				{
					if ( (uint8)nfcReaderHdr.txEcu_u8 == (uint8)WCPM2 )
					{
						if ( ( session_state_u8 == (uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E ) ||
							( session_state_u8 == (uint8)NFC_READER_TAP_START_FLOW_INIT_STATE_E ) ||
							( session_state_u8 == (uint8)NFC_READER_CARD_PLANT_TEST_STATE_E ) )
						{
							rbd_NFCVehIf_SetEvent( NFC_WCPM_NOT_READY_EVENT );
						}
						else
						{
							Rte_Write_PP_CanRequest_DkmNfc_ComRequest( FALSE );
						}
					}
				}
				break;

				case MULTNFCDEVPRESENT:
				{
					if ( (uint8)nfcReaderHdr.txEcu_u8 == (uint8)WCPM2 )
					{
						if (( session_state_u8 == (uint8)NFC_READER_GET_UID_STATE_E ) ||
							( session_state_u8 == (uint8)NFC_READER_TAP_START_FLOW_INIT_STATE_E ))
						{
							rbd_NFCVehIf_SetEvent( NFC_WCPM_MULTIDEVICE_PRESENT_EVENT );
						}
						else
						{
						}
					}
				}
				break;

				default:
				{
					if ( (uint8)nfcReaderHdr.txEcu_u8 == (uint8)WCPM2 )
					{
						if (( session_state_u8 == (uint8)NFC_READER_GET_UID_STATE_E )||
							( session_state_u8 == (uint8)NFC_READER_TAP_START_FLOW_INIT_STATE_E ))

						{
							rbd_NFCVehIf_SetEvent( NFC_WCPM_READER_INVALID_MSG_EVENT );
						}
						else
						{
						}
					}
				}
				break;
			}
			if ( TRUE == performDeInit )
			{
				// Disconnect from sessionMgr and reset tag
				if ( FALSE == rbd_NFCVehIf_IsDeselectRetry_InProgress() )
				{
					rbd_NFCVehIf_NfcTeardown( (uint8)nfcReaderHdr.txEcu_u8 );
				}

				rbdSessionMgr_NfcDisconnected( (uint8)nfcReaderHdr.txEcu_u8 );
				(void)rbd_NFCVehIf_ResetNFCReaderSessionTag( (uint8)nfcReaderHdr.txEcu_u8 );
			}
		}
		else if ( nfcReaderHdr.cmdId_u8 == NFC_FAILUREMODE )
		{
			// nothing defined yet
		}
		else if ( nfcReaderHdr.cmdId_u8 == NFC_DETECTEDUIDS )
		{
			// no multi device support yet from SPAAK, TBD
		}
		else
		{
			// must be a CCC/STSmessage
			rbd_NFCVehIf_ProcessCCCResponse( nfcResponse_pt );
		}
	}
	else
	{
		// error handling tbd
	}
}

//----------------------------------------------------------------------------
//! \brief
//! Function that parses NFC Response into CCC compliant response format, and shares response with DKM
//! If the response isn't CCC (i.e. Status), then this function would not have been called
//!
//! \param [in] nfcResponse_pt The pointer to the response array read from COM port
//!
//! \return
//!  None
//----------------------------------------------------------------------------
static void rbd_NFCVehIf_ProcessCCCResponse(const uint8 *nfcResponse_pt)
{
	uint8 devRef_u8 = 0xffu;
    uint8 session_state_u8 = (uint8)NFC_READER_NOT_ACTIVE_STATE_E;
    uint8 readerConnection_state_u8 = READER_DISCONNECTED;
    nfcReaderResponseHeader_t nfcReaderHdr;
    drmServices_Type dataType;
    uint8 keyPlaced_u8 = DEVICE_PHONE_TYPE;
    boolean isCardResponse_bool = FALSE;

    (void)rbd_NfcIf_NfcReaderCanTPPacketHeaderRead(nfcResponse_pt, &nfcReaderHdr);
    rbd_NFCVehIf_ReadNFCReaderStatusInfo((uint8)nfcReaderHdr.txEcu_u8,&session_state_u8, &readerConnection_state_u8, &devRef_u8);

    /* If a Select Response is received  */
    if (((uint8)NFC_SELECT == nfcReaderHdr.cmdId_u8) && (nfcReaderHdr.txEcu_u8 == (uint8)WCPM2))
    {
    	rbd_NFCVehIf_RoutineRetryPolling_u8 = FALSE;
    	/* Determines if object placed on WCPM is a Device or Card*/
    	isCardResponse_bool = rbd_NfcIf_IsSelectResponseForCard(&nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE],nfcReaderHdr.payloadLength_u16, rbd_NFCVehIf_NfcCardSuccessUid_au8);
    	keyPlaced_u8 = (isCardResponse_bool == TRUE)? DEVICE_CARD_TYPE : DEVICE_PHONE_TYPE;

        /* For NFC TapStart verify card/phone is Enabled*/
        if(((uint8)NFC_READER_TAP_START_FLOW_INIT_STATE_E == session_state_u8) && (proxiPhoneAsAKey_u8== TRUE))
        {
			 //once backend is merged will set value to TRUE / FALSE
            (void)Rte_Read_rbd_NFCVehIf_RP_drmServices_drmServices(&dataType);
            if(((dataType.SPKVEHUSG == FALSE) && (keyPlaced_u8 == (uint8)DEVICE_PHONE_TYPE)) || ((dataType.SPKPHSCLKEY == FALSE) && (keyPlaced_u8 == (uint8)DEVICE_CARD_TYPE)))
            {
              rbdSessionMgr_NfcDisconnected( (uint8)WCPM2 );
            	(void)rbd_NFCVehIf_UpdateNFCReaderState((uint8)WCPM2,(uint8)NFC_READER_TAP_START_STOP_TRIGGER_STATE_E, NULL);
              rbd_NFCVehIf_NfcTeardown((uint8)WCPM2);
              Rte_Call_RP_SendAuthStatus_Cbk_SendAuthStatus(FALSE, NULL, NULL);
            }
            else
            {
              //misra
            }
        }

        /* Adds one to the count of devices used in Tap Start Response */
        if(rbd_NFCVehIf_Table_as[WCPM2].activeState_u8 == (uint8)NFC_READER_TAP_START_FLOW_INIT_STATE_E)
        {
            rbd_NFCVehIf_NFC_Count ++;
            /* Maximum supported NFC devices at the WCPM2 is 0x01 at the moment. */
            (void)Rte_Write_PP_Nfc_Count_Devices(rbd_NFCVehIf_NFC_Count);
        }
        else{
          //misra
        }

    }

    /* Don't send the SELECT reponse to DKM in case of Get UID state. Currently it seems to be creating problem as complete flow doesn't get completed in this case */
    if(session_state_u8 != (uint8)NFC_READER_GET_UID_STATE_E)
    {
		if (RBDSESSIONMGR_E_OK != rbdSessionMgr_ProcessNfcMsg(nfcReaderHdr.txEcu_u8, nfcReaderHdr.payloadLength_u16, &nfcResponse_pt[NFC_PAYLOAD_INIT_BYTE]))
		{
			// consider error handling
		}
    }
    else
    {
    	rbd_NFCVehIf_SetEvent(NFC_WCPM_READER_GETUID_RSP_EVENT);
    	memcpy(rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcCardData_t.nfcRoutineUId,rbd_NFCVehIf_NfcCardSuccessUid_au8,NFC_CARD_UID_LEN);
    }
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: rbd_NFCVehIf_ToggleOperationFinished
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <ToggleOperationFinished> of PortPrototype <PP_ToggleOperationFinished_Cbk>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void rbd_NFCVehIf_ToggleOperationFinished(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: rbd_NFCVehIf_ToggleOperationFinished_doc
 *********************************************************************************************************************/
//! \brief      rbd_NfcVehIf_ToggleOperationFinished
//!             This function is a notification from RFHM informing NFCVehIf that
//!             toggle operation is finished.
//!
//! \param [in] None
//! \return		None
//!  None
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, rbd_NFCVehIf_CODE) rbd_NFCVehIf_ToggleOperationFinished(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: rbd_NFCVehIf_ToggleOperationFinished
 *********************************************************************************************************************/
	uint8 devRef_u8 = 0xffu;
	uint8 session_state_u8  = (uint8)NFC_READER_NOT_ACTIVE_STATE_E;
	uint8 readerConnection_state_u8 = READER_DISCONNECTED;

	rbd_NFCVehIf_ReadNFCReaderStatusInfo((uint8)FLDHM,&session_state_u8,&readerConnection_state_u8, &devRef_u8);
	/* Only allow it to enter when it is waiting for Toggle rsp */
	if(session_state_u8 == (uint8)NFC_READER_TAP_ENTRY_TOGGLE_RSP_WAIT_STATE_E)
	{
		(void)rbd_NFCVehIf_UpdateNFCReaderState((uint8)FLDHM,(uint8)NFC_READER_TAP_ENTRY_TEAR_DOWN_STATE_E, NULL);
		rbd_NFCVehIf_NfcTeardown(FLDHM);
	}
	else
	{
	}

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: rbd_NFCVehIf_SendStartTrigger
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SendStartTrigger> of PortPrototype <PP_SendStartTrigger_Cbk>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void rbd_NFCVehIf_SendStartTrigger(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: rbd_NFCVehIf_SendStartTrigger_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, rbd_NFCVehIf_CODE) rbd_NFCVehIf_SendStartTrigger(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: rbd_NFCVehIf_SendStartTrigger
 *********************************************************************************************************************/
	uint8 devRef_u8 = 0xffu;
	uint8 session_state_u8 = (uint8)NFC_READER_NOT_ACTIVE_STATE_E;
	uint8 readerConnection_state_u8 = READER_DISCONNECTED;

	/*verifies tap entry is not in progress*/
	rbd_NFCVehIf_ReadNFCReaderStatusInfo( (uint8)FLDHM, &session_state_u8, &readerConnection_state_u8, &devRef_u8 );
	if(readerConnection_state_u8 == READER_DISCONNECTED)
	{
		rbd_NFCVehIf_ReadNFCReaderStatusInfo( (uint8)WCPM2, &session_state_u8, &readerConnection_state_u8, &devRef_u8 );

		if ( READER_IN_SESSION == readerConnection_state_u8 )
		{
			rbdSessionMgr_NfcDisconnected( (uint8)WCPM2 );
			(void)rbd_NFCVehIf_ResetNFCReaderSessionTag( (uint8)WCPM2 );
		}
		else
		{
			//misra
		}

		//NFC Vehif Implementation
		(void)rbd_NFCVehIf_RegisterNFCReaderSession( (uint8)WCPM2 );
		(void)rbd_NFCVehIf_UpdateNFCReaderState( (uint8)WCPM2,(uint8)NFC_READER_TAP_START_RFHM_TRIGGER_RX_STATE_E, NULL );
		/* ToDO - Start Intermediate Code until DKM fix for FFA is available */
		DevKeyListCount_u8 = 0x00u;
		(void)Rte_Call_RP_rbdDeviceMgr_GetNumberOfKeyEntries_Operation(DEVICE_TYPE_PHONE, DevKeyRefList_au8, 32u, &DevKeyListCount_u8);
		/* ToDO - End Intermediate Code until DKM fix for FFA is available */
	}
	else
	{
		(void)rbd_NFCVehIf_ResetNFCReaderSessionTag((uint8)WCPM2);
	}


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: rbd_NFCVehIf_WcpKeyAuthReq_Cbk
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <WcpKeyAuthReq> of PortPrototype <PP_WcpKeyAuthReq>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void rbd_NFCVehIf_WcpKeyAuthReq_Cbk(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: rbd_NFCVehIf_WcpKeyAuthReq_Cbk_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) rbd_NFCVehIf_WcpKeyAuthReq_Cbk(void)
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: rbd_NFCVehIf_WcpKeyAuthReq_Cbk
 *********************************************************************************************************************/

	Std_ReturnType ret_val = RTE_E_INVALID;
	uint8 devRef_u8 = 0xffu;
	uint8 session_state_u8 = (uint8)NFC_READER_NOT_ACTIVE_STATE_E;
	uint8 readerConnection_state_u8 = READER_DISCONNECTED;

	rbd_NFCVehIf_ReadNFCReaderStatusInfo( (uint8)WCPM2, &session_state_u8, &readerConnection_state_u8, &devRef_u8 );
	if ( READER_IN_SESSION == readerConnection_state_u8 )
	{
		rbdSessionMgr_NfcDisconnected( (uint8)WCPM2 );
		(void)rbd_NFCVehIf_ResetNFCReaderSessionTag( (uint8)WCPM2 );
	}
	else
	{
		;//do nothing
	}
	//NFC Vehif Implementation
	(void)rbd_NFCVehIf_RegisterNFCReaderSession( (uint8)WCPM2 );

	(void)rbd_NFCVehIf_UpdateNFCReaderState( (uint8)WCPM2,(uint8)NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_INIT_STATE_E, NULL );
	//todo: request DKM to create a new NFCFlow, same as OPERATION_NFC_START to start WCP polling.For now, just use the OPERATION_NFC_START
	ret_val = Rte_Call_RP_NfcFlow_Start_Start( (uint8)WCPM2, OPERATION_NFC_START, 0, 0, 0, RBD_TRANSCODE_ENGINE_START_FIRST_CONTACT, NULL, NULL );
	return ret_val;
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: rbd_NFCVehIf_SendStopTrigger
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <SendStopTrigger> of PortPrototype <PP_SendStopTrigger_Cbk>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   void rbd_NFCVehIf_SendStopTrigger(void)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: rbd_NFCVehIf_SendStopTrigger_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, rbd_NFCVehIf_CODE) rbd_NFCVehIf_SendStopTrigger(void) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: rbd_NFCVehIf_SendStopTrigger
 *********************************************************************************************************************/
	uint8 wcpmDevRef_u8 = 0xffu;
	uint8 wcpmSession_state_u8 = NFC_READER_NOT_ACTIVE_STATE_E;
	uint8 wcpmReaderConnection_state_u8 = READER_DISCONNECTED;

	rbd_NFCVehIf_ReadNFCReaderStatusInfo( (uint8)WCPM2, &wcpmSession_state_u8, &wcpmReaderConnection_state_u8, &wcpmDevRef_u8 );
	(void)rbd_NFCVehIf_UpdateNFCReaderState( (uint8)WCPM2,(uint8)NFC_READER_TAP_START_STOP_TRIGGER_STATE_E, NULL );
	if(READER_IN_SESSION == wcpmReaderConnection_state_u8)
	{
		rbd_NFCVehIf_NfcTeardown(WCPM2);
	}

	(void)rbd_NFCVehIf_ResetNFCReaderSessionTag( (uint8)WCPM2 );
	rbdSessionMgr_NfcDisconnected( (uint8)WCPM2 );

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}
//----------------------------------------------------------------------------
//! \brief      rbd_NfcIf_NfcReaderCanTPPacketHeaderRead
//!             This function extracts the CAN TP header info from Input
//!              data stream and populates it in nfcReaderResponseHeader_t
//!
//! \param [in] packetDataIn - Input CAN TP Packet
//! \param [out] nfcReaderDataHeader_ps - Packet header info
//! \return		None
//!  None
//----------------------------------------------------------------------------
static void rbd_NfcIf_NfcReaderCanTPPacketHeaderRead(const uint8 * packetDataIn, nfcReaderResponseHeader_t *  nfcReaderDataHeader_ps)
{
	if((NULL != packetDataIn) && (NULL != nfcReaderDataHeader_ps))
	{
		nfcReaderDataHeader_ps->cmdId_u8 = (uint8)packetDataIn[NFC_COM_ID_BYTE];
		nfcReaderDataHeader_ps->rxEcu_u8 = ((uint8)(packetDataIn[NFC_ECU_ID_BYTE] >> 3u) & 0x07u);
		nfcReaderDataHeader_ps->txEcu_u8 = ((uint8)(packetDataIn[NFC_ECU_ID_BYTE] >> 0u) & 0x07u);
		/* Read the length bytes in Big Endian format */
		nfcReaderDataHeader_ps->payloadLength_u16 = (uint16_t)(packetDataIn[NFC_PAY_LEN_LS_BYTE]);
		nfcReaderDataHeader_ps->payloadLength_u16 = (nfcReaderDataHeader_ps->payloadLength_u16 << 8u);
		nfcReaderDataHeader_ps->payloadLength_u16 |= (uint16_t)(packetDataIn[NFC_PAY_LEN_MS_BYTE]);
	}
	else
	{

	}
}

//----------------------------------------------------------------------------
//! \brief      rbd_NfcIf_NfcReaderCanTPPacketHeaderWrite
//!             This function writes the CAN TP header based on the
//!             nfcReaderResponseHeader_t information
//!
//! \param [out] packetDataOut - Output CAN TP byte stream with header
//! \param [in] nfcReaderDataHeader_ps - Packet header info
//! \return		None
//!  None
//----------------------------------------------------------------------------
static void rbd_NfcIf_NfcReaderCanTPPacketHeaderWrite(uint8 * packetDataOut, const nfcReaderResponseHeader_t *  nfcReaderDataHeader_ps)
{
	/*AXIVION Disable MisraC2012-2.2 : Redundant code, parameter comparison to NULL is always true[CccAuthStatus] - Deviation ptr(packetDataOut, nfcReaderDataHeader_ps) could be NULL */
	/*AXIVION Disable MisraC2012-14.3 : Redundant code, parameter comparison to NULL is always true. Deviation comparisons are valid here.Else branch is not dead */
	if((NULL != packetDataOut) && (NULL != nfcReaderDataHeader_ps))
	{
		packetDataOut[NFC_COM_ID_BYTE] = (uint8)(nfcReaderDataHeader_ps->cmdId_u8);
		packetDataOut[NFC_ECU_ID_BYTE] = (uint8)(((nfcReaderDataHeader_ps->rxEcu_u8 & 0x07u) << 3) | (nfcReaderDataHeader_ps->txEcu_u8 & 0x07u));
		/* Write the length bytes in Big Endian format */
		packetDataOut[NFC_PAY_LEN_LS_BYTE] = (uint8)((nfcReaderDataHeader_ps->payloadLength_u16>>8U) & 0xffU);
		packetDataOut[NFC_PAY_LEN_MS_BYTE] = (uint8)((nfcReaderDataHeader_ps->payloadLength_u16>>0U) & 0xffU);
	}
	else
	{

	}
}

//----------------------------------------------------------------------------
//! \brief      Dkm_NfcFlow_NotifyAuthStatus
//!             This is the callback generated by DKM in response to NFC
//!             authentoication flow.
//!
//! \param [in] nfcReaderId_u8: NFC Reader id either FLDHM/FRDHM or WCPM2
//! \param [in] authStatus_pu8: authentication status of the operation
//! \param [in] devRef_pu8: devRef(device Ref or Card ref)
//! \return
//!  None
//----------------------------------------------------------------------------
/*AXIVION Disable MisraC2012-8.13 : Parameter can be declared as pointer/reference to const- Deviation prototype is declared in DKM */
Std_ReturnType rbd_NFCVehIf_NfcFlow_NotifyAuthStatus(rbdPk_NfcReaderId_t ReaderId, Dkm_CccAuthStatus_en* CccAuthStatus, uint8 * DeviceRef)
{
	uint8 authStatus_u8;
	uint8 devRef_u8;

	/*AXIVION Disable MisraC2012-2.2 : Redundant code, parameter comparison to NULL is always true[CccAuthStatus] - Deviation ptr(DeviceRef, CccAuthStatus) could be NULL */
	/*AXIVION Disable MisraC2012-14.3 : Redundant code, parameter comparison to NULL is always true. Deviation comparisons are valid here. Else branch is not dead */
	if((NULL != DeviceRef) && (NULL !=CccAuthStatus))
	{
		authStatus_u8 = *CccAuthStatus;
		devRef_u8 = *DeviceRef;

		if(ReaderId <= NFC_NUM_READERS)
		{
			if(NULL != rbd_NFCVehIf_NfcReaderAuthNotification_FuncTable[ReaderId])
			{
				/* Call the appropriate function based on WCPM, FLDHM or FRDHM */
				(void)(*rbd_NFCVehIf_NfcReaderAuthNotification_FuncTable[ReaderId])(authStatus_u8, devRef_u8);
				/* Info : Split the function for individual reader to fix MISRA warnings and reduce HIS v(G) code complexity level which was above 20 for combined function */
			}
			else
			{
				/* do nothing for misra */
			}
		}
		else
		{
			/* do nothing for misra */
		}
	}
	else
	{
		/* do nothing for misra */
	}

	return RTE_E_OK;
}

//----------------------------------------------------------------------------
//! \brief      rbd_NFCVehIf_NfcFlow_FLDHM_AuthNotification
//!             Function to handle authentcation flow at FLDHM
//!
//! \param [in] Dkm_AuthStatus_en: authentication status of the operation
//! \param [in] DevRef_u8: devRef(device Ref or Card ref)
//! \return
//!  None
//----------------------------------------------------------------------------
static void rbd_NFCVehIf_NfcFlow_FLDHM_AuthNotification(Dkm_CccAuthStatus_en Dkm_AuthStatus_en, uint8 DevRef_u8)
{
	uint8 auth_fail_counter_u8 = 0x00u;
	Std_ReturnType dkmRet_u8;
	uint8 fldhmDevRef_u8 = 0xffu;
	uint8 fldhmSession_state_u8 = NFC_READER_NOT_ACTIVE_STATE_E;
	uint8 fldhmReaderConnection_state_u8 = READER_IN_SESSION;

	rbd_NFCVehIf_ReadNFCReaderStatusInfo((uint8)FLDHM,&fldhmSession_state_u8,&fldhmReaderConnection_state_u8, &fldhmDevRef_u8);
	if(fldhmSession_state_u8 == (uint8)NFC_READER_TAP_ENTRY_FLOW_INIT_STATE_E)
	{
		auth_fail_counter_u8 = *(Rte_Pim_FailedAttemptsCounter_MirrorBlock());
		/* In case of phone the DevRef_u8 range is between 0-31 */
		if((DevRef_u8 <= 32u) && (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATED))
		{
			/* Its a phone */
			auth_fail_counter_u8 = 0u;
			dkmRet_u8 = Rte_Call_RP_rbdDeviceMgr_GetKeyInfoDevice_Operation(DevRef_u8, &keyInfo_S);
			if(RTE_E_OK == dkmRet_u8 )
			{
				(void)rbd_NFCVehIf_UpdateNFCReaderState((uint8)FLDHM, (uint8)NFC_READER_TAP_ENTRY_DEVICE_INFO_WAIT_STATE_E, &DevRef_u8);
			}
			else
			{
				(void)rbd_NFCVehIf_UpdateNFCReaderState((uint8)FLDHM, (uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_SUCCESS_STATE_E, &DevRef_u8);
			}
		}
		/* In case of card the DevRef_u8 range is between  100 to 109 */
		else if(((DevRef_u8 >=100u) && (DevRef_u8 <= 109u)) && (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATED))
		{
			auth_fail_counter_u8 = 0u;
			/* Its a Card */
			(void)rbd_NFCVehIf_UpdateNFCReaderState((uint8)FLDHM, (uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_SUCCESS_STATE_E, &DevRef_u8);
		}
		else if(RBD_CCC_DEV_AUTHENTICATION_FAILED == Dkm_AuthStatus_en)
		{
			/* Authentication failed so increment the failure counter */
			auth_fail_counter_u8 += (auth_fail_counter_u8 != 0xFFU) ? 1U : 0U;
			(void)rbd_NFCVehIf_UpdateNFCReaderState((uint8)FLDHM, (uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_FAILED_STATE_E, &DevRef_u8);
			/* Todo Add NFC_READER_DESELECT_DISABLE_TYPE_Eafter 7 attempst */
		}
		else
		{
			//misra
		}
		/* Update the failure counter in NVM if necessary(initiate write only if its changed) */
		if (*(Rte_Pim_FailedAttemptsCounter_MirrorBlock()) != auth_fail_counter_u8)
		{
			*(Rte_Pim_FailedAttemptsCounter_MirrorBlock()) = auth_fail_counter_u8;
			Rte_Call_FailedAttemptsTimer_WriteBlock(
				Rte_Pim_FailedAttemptsCounter_MirrorBlock());
		}
		else
		{

		}
	}
	else
	{

	}

}

//----------------------------------------------------------------------------
//! \brief      rbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification
//!             Function to handle authentcation flow at WCPM2
//!
//! \param [in] Dkm_AuthStatus_en: authentication status of the operation
//! \param [in] DevRef_u8: devRef(device Ref or Card ref)
//! \return
//!  None
//----------------------------------------------------------------------------
static void rbd_NFCVehIf_NfcFlow_WCPM2_AuthNotification(Dkm_CccAuthStatus_en Dkm_AuthStatus_en, uint8 DevRef_u8)
{
	uint8 wcpmDevRef_u8 = 0xffu;
	Std_ReturnType dkmRet_u8;
    uint8 wcpmSession_state_u8 = NFC_READER_NOT_ACTIVE_STATE_E;
    uint8 wcpmReaderConnection_state_u8 = READER_IN_SESSION;

	rbd_NFCVehIf_ReadNFCReaderStatusInfo((uint8)WCPM2,&wcpmSession_state_u8,&wcpmReaderConnection_state_u8, &wcpmDevRef_u8);
	// Handle post-authorization action based on active use case
	if (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATED)
	{
		if (wcpmSession_state_u8 == (uint8)NFC_READER_OWNER_PAIRING_STATE_E)
		{
			(void)rbd_NFCVehIf_UpdateNFCReaderState((uint8)WCPM2, (uint8)NFC_READER_OWNER_PAIRING_TEAR_DOWN_STATE_E, &DevRef_u8);
			(void)Rte_Write_rbd_NFCVehIf_rbd_NFCVehIf_NFC_PhoneKeyPariring_Result_NFCPhoneKeyPariring_Result((uint8)Dkm_AuthStatus_en);
			// share ack to HU, not included in MVP with simulation tool
		}
		else if (wcpmSession_state_u8 == (uint8)NFC_READER_TAP_START_FLOW_INIT_STATE_E)
		{

			/* Card keyRefs reported by DKM are between 100 to 109 */
			if((DevRef_u8 >=100u) && (DevRef_u8 <= 109u))
			{
				(void)rbd_NFCVehIf_UpdateNFCReaderState((uint8)WCPM2, (uint8)NFC_READER_TAP_START_CARD_AUTH_SUCCESS_STATE_E, &DevRef_u8);
			}
			else if(DevRef_u8 < 32u)
			{
				/* Device keyRefs repprted by DKM are between 0 to 31 */
				dkmRet_u8 = Rte_Call_RP_rbdDeviceMgr_GetKeyInfoDevice_Operation(DevRef_u8, &keyInfo_S);
				if(RTE_E_OK == dkmRet_u8 )
				{
					(void)rbd_NFCVehIf_UpdateNFCReaderState((uint8)WCPM2, (uint8)NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E, &DevRef_u8);
				}
				else
				{
					(void)rbd_NFCVehIf_UpdateNFCReaderState((uint8)WCPM2, (uint8)NFC_READER_TAP_START_DEVICE_AUTH_SUCCESS_STATE_E, &DevRef_u8);
				}
			}
			else
			{
				/* Error Handling as being seen with current SCP03 version */
				(void)rbd_NFCVehIf_UpdateNFCReaderState((uint8)WCPM2, (uint8)NFC_READER_TAP_START_DEVICE_AUTH_FAILED_STATE_E, &DevRef_u8);
			}

		}
		else if (wcpmSession_state_u8 == (uint8)NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_INIT_STATE_E)
		{
			//send VSM tag WCP authentication result
			rbd_VSM_WcpKeyAuthResult_Cbk(TRUE, &DevRef_u8);
			//set state to WCP_AUTH_FINISH to clean up NFC reader session
			(void)rbd_NFCVehIf_UpdateNFCReaderState((uint8)WCPM2, (uint8)NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_FINISH_STATE_E, &DevRef_u8);
		}
		else if (wcpmSession_state_u8 == (uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E)
		{
			(void)rbd_NFCVehIf_UpdateNFCReaderState((uint8)WCPM2, (uint8)NFC_READER_CARD_PLANT_PAIR_TEAR_DOWN_STATE_E, &DevRef_u8);
			// in future, we will call dkm api here for uid, but now we pull from whats secondarily stored in vehIf
			rbd_NFCVehIf_SetEvent(NFC_PAIR_AUTHENTICATION_EVENT);
			memcpy(rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcCardData_t.nfcRoutineUId,rbd_NFCVehIf_NfcCardSuccessUid_au8,NFC_CARD_UID_LEN);
			rbd_NFCVehIf_NfcTeardown((uint8)WCPM2);
			/* Deactivate the FD9 bus */
		}
		else if(wcpmSession_state_u8 == (uint8)NFC_READER_CARD_PLANT_TEST_STATE_E)// test card pair use case
		{
			// in future, we will call dkm api here for uid, but now we pull from whats secondarily stored in vehIf
			(void)rbd_NFCVehIf_UpdateNFCReaderState((uint8)WCPM2, (uint8)NFC_READER_CARD_PLANT_TEST_TEAR_DOWN_STATE_E, &DevRef_u8);
			rbd_NFCVehIf_SetEvent(NFC_TEST_PAIR_AUTHENTICATION_EVENT);
			memcpy(rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E].nfcCardData_t.nfcRoutineUId,rbd_NFCVehIf_NfcCardSuccessUid_au8,NFC_CARD_UID_LEN);
			rbd_NFCVehIf_NfcTeardown((uint8)WCPM2);
			/* Deactivate the FD9 bus */
		}
		else
		{

		}
	}
	else if (Dkm_AuthStatus_en == RBD_CCC_DEV_AUTHENTICATION_FAILED)
	{
		if (wcpmSession_state_u8 == (uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E)
		{
			(void)rbd_NFCVehIf_UpdateNFCReaderState((uint8)WCPM2, (uint8)NFC_READER_CARD_PLANT_PAIR_TEAR_DOWN_STATE_E, &DevRef_u8);
			rbd_NFCVehIf_SetEvent(NFC_PAIR_AUTHENTICATION_EVENT);
			rbd_NFCVehIf_NfcTeardown((uint8)WCPM2);
			/* Deactivate the FD9 bus */
		}
		else if (wcpmSession_state_u8 == (uint8)NFC_READER_CARD_PLANT_TEST_STATE_E)
		{
			(void)rbd_NFCVehIf_UpdateNFCReaderState((uint8)WCPM2, (uint8)NFC_READER_CARD_PLANT_TEST_TEAR_DOWN_STATE_E, &DevRef_u8);
			rbd_NFCVehIf_SetEvent(NFC_TEST_PAIR_AUTHENTICATION_EVENT);
			rbd_NFCVehIf_NfcTeardown((uint8)WCPM2);
		}
		else if(wcpmSession_state_u8 == (uint8)NFC_READER_TAP_START_FLOW_INIT_STATE_E)
		{
			(void)rbd_NFCVehIf_UpdateNFCReaderState((uint8)WCPM2, (uint8)NFC_READER_TAP_START_DEVICE_AUTH_FAILED_STATE_E, &DevRef_u8);
		}
		else if (wcpmSession_state_u8 == (uint8)NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_INIT_STATE_E)
		{
			//send VSM tag WCP authentication result
			rbd_VSM_WcpKeyAuthResult_Cbk(FALSE, &DevRef_u8);
			//set state to WCP_AUTH_FINISH to clean up NFC reader session
			(void)rbd_NFCVehIf_UpdateNFCReaderState((uint8)WCPM2, (uint8)NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_FINISH_STATE_E, &DevRef_u8);
		}
		else if (wcpmSession_state_u8 == (uint8)NFC_READER_OWNER_PAIRING_STATE_E)
		{
			(void)rbd_NFCVehIf_UpdateNFCReaderState((uint8)WCPM2, (uint8)NFC_READER_OWNER_PAIRING_TEAR_DOWN_STATE_E, &DevRef_u8);
			rbd_NFCVehIf_NfcTeardown((uint8)WCPM2);
		}
		else
		{
			// do nothing for misra
		}
	}
	else
	{
		// do nothing for misra
	}
}

//----------------------------------------------------------------------------
//! \brief      rbd_NfcIf_TapStartTriggerCyclic
//!             Responsible for the handling of retriggering tap start within
//!             the vehicle start timeout
//!
//! \param [in] void
//! \return
//!  None
//----------------------------------------------------------------------------
static void rbd_NfcIf_TapStartTriggerCyclic( void )
{
	uint8 devRef_u8 = 0xffu;
	uint8 session_state_u8 = (uint8)NFC_READER_NOT_ACTIVE_STATE_E;
	uint8 readerConnection_state_u8 = READER_DISCONNECTED;
	uint16 nfc_ReaderEvtMsg_u16 = 0x00u;
	Std_ReturnType ret_val = RTE_E_INVALID;

	rbd_NFCVehIf_ReadNFCReaderStatusInfo( (uint8)WCPM2, &session_state_u8,
		&readerConnection_state_u8, &devRef_u8 );

	if ( ((uint8)NFC_READER_TAP_START_RFHM_TRIGGER_RX_STATE_E) == session_state_u8 )
	{
		rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 = NFC_VEH_START_POLLING_TIMEOUT;
		rbd_NFCVehIf_ClearEvent( NFC_EVENT_ALL_EVENT_MASK );
		/* This is the first pass/try of the NFC start flow upon receiving Trigger from rfhmif*/
		(void)rbd_NFCVehIf_UpdateNFCReaderState( (uint8)WCPM2,
			(uint8)NFC_READER_TAP_START_FLOW_INIT_STATE_E, NULL );
		ret_val = Rte_Call_RP_NfcFlow_Start_Start( (uint8)WCPM2, OPERATION_NFC_START, 0, 0, 0,
			RBD_TRANSCODE_ENGINE_START_FIRST_CONTACT, NULL, NULL );
	}
	else
	{
		/* Here the retries for the tap start would be attempted */
		rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 =
			( rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 >= (uint16)NFC_CYCLE_TIME ) ?
				( rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 - NFC_CYCLE_TIME ) : 0u; /*AXIVION Line MisraC2012-21.18: Cycle time make be larger than Card Timer Deviation InternalBosch_FalsePositive_A: Ticket 1198131. Already checking the size to be within range */

		if ( rbd_NFCVehIf_TapStartPollingTimeoutTimer_u16 > 0x00u )
		{
			nfc_ReaderEvtMsg_u16 = rbd_NFCVehIf_ReadEventWord();
			if ( ( NFC_WCPM_NOT_READY_EVENT == ( nfc_ReaderEvtMsg_u16 & NFC_WCPM_NOT_READY_EVENT ) ) ||
				( NFC_WCPM_DEVICEMOVED_EVENT == ( nfc_ReaderEvtMsg_u16 & NFC_WCPM_DEVICEMOVED_EVENT ) ) ||
				( NFC_WCPM_READER_TIMEOUT_EVENT == ( nfc_ReaderEvtMsg_u16 & NFC_WCPM_READER_TIMEOUT_EVENT ) ) ||
				( NFC_WCPM_READER_INVALID_MSG_EVENT == ( nfc_ReaderEvtMsg_u16 & NFC_WCPM_READER_INVALID_MSG_EVENT ) ) ||
				( NFC_WCPM_MULTIDEVICE_PRESENT_EVENT == ( nfc_ReaderEvtMsg_u16 & NFC_WCPM_MULTIDEVICE_PRESENT_EVENT ) ) )
			{
				(void)rbd_NFCVehIf_RegisterNFCReaderSession( (uint8)WCPM2 );
				(void)rbd_NFCVehIf_UpdateNFCReaderState( (uint8)WCPM2,
					(uint8)NFC_READER_TAP_START_FLOW_INIT_STATE_E, NULL );
				ret_val = Rte_Call_RP_NfcFlow_Start_Start( (uint8)WCPM2, OPERATION_NFC_START, 0, 0,
					0, RBD_TRANSCODE_ENGINE_START_FIRST_CONTACT, NULL, NULL );
				rbd_NFCVehIf_ClearEvent( NFC_EVENT_ALL_EVENT_MASK );
			}
			else
			{
				/* If here means we are waiting for some response from WCPM */
			}
		}
		else
		{
			/* If WCPM still in tap start session */
			if ( ( READER_IN_SESSION == readerConnection_state_u8 )
				&& ( ((uint8)NFC_READER_TAP_START_FLOW_INIT_STATE_E) == session_state_u8 ) )
			{
				rbd_NFCVehIf_ClearEvent( NFC_EVENT_ALL_EVENT_MASK );
				rbd_NFCVehIf_NfcTeardown( WCPM2 );
				rbdSessionMgr_NfcDisconnected( (uint8)WCPM2 );
				(void)rbd_NFCVehIf_ResetNFCReaderSessionTag( (uint8)WCPM2 );
			}
		}
	}

	(void)ret_val;
}

//----------------------------------------------------------------------------
//! \brief      rbd_NfcIf_NfcTapThread
//!             The handler gets called cyclically. It performs the necessary
//!             things required for the tap entry flow
//!
//! \param [in] void
//! \return
//!  None
//----------------------------------------------------------------------------
static void rbd_NfcIf_NfcTapThread(void)
{
	uint16 devMgr_OpStatus_u16 = (uint16)RBDPK_CCC_DEV_AUTHENTICATION_FAILED;
	uint8 ret = 0x00;
	uint8 profile_id_u8 = 0x0f;
	uint8 devRef_u8 = 0xffu;
	uint8 session_state_u8  = (uint8)NFC_READER_NOT_ACTIVE_STATE_E;
	uint8 readerConnection_state_u8 = READER_DISCONNECTED;
	Std_ReturnType dkmRet_u8;
	uint8 RefreshedDevKeyListCount_u8 = 0x00;

	rbd_NFCVehIf_ReadNFCReaderStatusInfo((uint8)FLDHM,&session_state_u8,&readerConnection_state_u8, &devRef_u8);
	/* 1. Check for NFC Card Tap Entry Authentication status */
	if(((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8))
	{
		Rte_Call_RP_ControlFd1Bus_Cbk_ControlFd1Bus(TRUE);
		/* Card entitlement is always full access */
		rbd_RfhmIf_SendNfcToggleReq(TOGGLE,(uint8)RBD_DK_ACCESS_PROFILE_FULL_ACCESS,devRef_u8);
		(void)rbd_NFCVehIf_UpdateNFCReaderState((uint8)FLDHM, (uint8)NFC_READER_TAP_ENTRY_TOGGLE_RSP_WAIT_STATE_E, &devRef_u8);
	}
	/* 2. Check for NFC Device Tap Entry Authentication status */
	else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8))
	{
		dkmRet_u8 = Rte_Call_RP_rbdDeviceMgr_GetKeyInfoDevice_Operation(devRef_u8, &keyInfo_S);
		if(RTE_E_OK == dkmRet_u8 )
		{
			(void)rbd_NFCVehIf_UpdateNFCReaderState((uint8)FLDHM, (uint8)NFC_READER_TAP_ENTRY_DEVICE_INFO_WAIT_STATE_E, &devRef_u8);
		}
		else
		{
		}
	}
	else if(((uint8)NFC_READER_TAP_ENTRY_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8))
	{
		/* Check the status of the operation */
		Rte_Call_RP_ControlFd1Bus_Cbk_ControlFd1Bus(TRUE);
		ret = Rte_Call_RP_rbdDeviceMgr_GetStatus_Operation(&devMgr_OpStatus_u16);
		if(RTE_E_OK == ret)
		{
			if(TRUE == keyInfo_S.isFriendDev)
			{
				/* Its a friend Device so extract the profile ID */
				profile_id_u8 = keyInfo_S.friendDevDat.standardProfiles;
				/* ToDO - Start Intermediate Code until DKM fix for FFA is available */
				RefreshedDevKeyListCount_u8 = 0x00u;
				(void)Rte_Call_RP_rbdDeviceMgr_GetNumberOfKeyEntries_Operation(DEVICE_TYPE_PHONE, DevKeyRefList_au8, 32u, &RefreshedDevKeyListCount_u8);
				if(RefreshedDevKeyListCount_u8 > DevKeyListCount_u8)
				{
					(void)Rte_Call_RP_BackendKeyStatusUpdate_BackendKeyStatusUpdate(NFC_FriendFirstApproach, keyInfo_S.keyIdentifier);
				}
				/* ToDO - End Intermediate Code until DKM fix for FFA is available */
			}
			else
			{
				/* Owner device always has full access */
				profile_id_u8 = (uint8)RBD_DK_ACCESS_PROFILE_FULL_ACCESS;
			}
			/* Send the toggle request to RFHM */
			rbd_RfhmIf_SendNfcToggleReq(TOGGLE,(uint8)profile_id_u8,devRef_u8);
			(void)rbd_NFCVehIf_UpdateNFCReaderState((uint8)FLDHM, (uint8)NFC_READER_TAP_ENTRY_TOGGLE_RSP_WAIT_STATE_E, &devRef_u8);
		}
		else if(RTE_E_INVALID == ret)
		{
			/*Some error hanlding -  Its highly unlikely to enter here especially when DKM said Auth OK, but just in case of some issue */
			(void)rbd_NFCVehIf_ResetNFCReaderSessionTag((uint8)FLDHM);
		}
		else
		{	/* Do Nothing MISRA compliant else */
		}
	}
	else if(((uint8)NFC_READER_TAP_ENTRY_TOGGLE_RSP_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8))
	{

	}
	else if((((uint8)NFC_READER_TAP_ENTRY_CARD_AUTH_FAILED_STATE_E == session_state_u8) || ((uint8)NFC_READER_TAP_ENTRY_DEVICE_AUTH_FAILED_STATE_E == session_state_u8))
		&& (READER_IN_SESSION == readerConnection_state_u8))
	{
		/* Send also the deselect as rbd_NFCVehIf_NfcTeardown is not called by DKM in case of failed auth */
		rbd_NFCVehIf_NfcTeardown((uint8)FLDHM);
		(void)rbd_NFCVehIf_UpdateNFCReaderState((uint8)FLDHM,(uint8)NFC_READER_TAP_ENTRY_TEAR_DOWN_STATE_E, NULL);
		rbdSessionMgr_NfcDisconnected((uint8)FLDHM);
		(void)rbd_NFCVehIf_ResetNFCReaderSessionTag((uint8)FLDHM);
		Rte_Write_PP_CanRequest_DkmNfc_ComRequest(FALSE);
	}
	else
	{	/* Do Nothing MISRA compliant else */
	}

	rbd_NFCVehIf_ReadNFCReaderStatusInfo((uint8)WCPM2,&session_state_u8,&readerConnection_state_u8, &devRef_u8);

	if(((uint8)NFC_READER_TAP_START_CARD_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8))
	{
		/* Card entitlement is always full access */
		profile_id_u8 = (uint8)RBD_DK_ACCESS_PROFILE_FULL_ACCESS;
		Rte_Call_RP_SendAuthStatus_Cbk_SendAuthStatus(TRUE, &profile_id_u8, &devRef_u8);
		(void)rbd_NFCVehIf_UpdateNFCReaderState((uint8)WCPM2,(uint8)NFC_READER_TAP_START_TEAR_DOWN_STATE_E, NULL);
		//rbd_NFCVehIf_ResetNFCReaderSessionTag((uint8)WCPM2);
	}
	else if(((uint8)NFC_READER_TAP_START_DEVICE_AUTH_SUCCESS_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8))
	{
		dkmRet_u8 = Rte_Call_RP_rbdDeviceMgr_GetKeyInfoDevice_Operation(devRef_u8, &keyInfo_S);
		if(RTE_E_OK == dkmRet_u8 )
		{
			(void)rbd_NFCVehIf_UpdateNFCReaderState((uint8)WCPM2, (uint8)NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E, &devRef_u8);
		}
		else
		{
		}
	}
	else if(((uint8)NFC_READER_TAP_START_DEVICE_INFO_WAIT_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8))
	{
		/* Check the status of the operation */
		ret = Rte_Call_RP_rbdDeviceMgr_GetStatus_Operation(&devMgr_OpStatus_u16);
		if(RTE_E_OK == ret)
		{
			if(TRUE == keyInfo_S.isFriendDev)
			{
				/* Its a friend Device so extract the profile ID */
				profile_id_u8 = keyInfo_S.friendDevDat.standardProfiles;
				/* ToDO - Start Intermediate Code until DKM fix for FFA is available */
				RefreshedDevKeyListCount_u8 = 0x00u;
				(void)Rte_Call_RP_rbdDeviceMgr_GetNumberOfKeyEntries_Operation(DEVICE_TYPE_PHONE, DevKeyRefList_au8, 32u, &RefreshedDevKeyListCount_u8);
				if(RefreshedDevKeyListCount_u8 > DevKeyListCount_u8)
				{
					(void)Rte_Call_RP_BackendKeyStatusUpdate_BackendKeyStatusUpdate (NFC_FriendFirstApproach, keyInfo_S.keyIdentifier);
				}
				/* ToDO - End Intermediate Code until DKM fix for FFA is available */

			}
			else
			{
				/* Owner device always has full access */
				profile_id_u8 = (uint8)RBD_DK_ACCESS_PROFILE_FULL_ACCESS;
			}
			/* Send the toggle request to RFHM */
			Rte_Call_RP_SendAuthStatus_Cbk_SendAuthStatus(TRUE, &profile_id_u8, &devRef_u8);
			(void)rbd_NFCVehIf_UpdateNFCReaderState((uint8)WCPM2,(uint8)NFC_READER_TAP_START_TEAR_DOWN_STATE_E, NULL);
			//rbd_NFCVehIf_ResetNFCReaderSessionTag((uint8)WCPM2);
		}
		else if(RTE_E_INVALID == ret)
		{
			/*Some error hanlding -  Its highly unlikely to enter here especially when DKM said Auth OK, but just in case of some issue */
			Rte_Call_RP_SendAuthStatus_Cbk_SendAuthStatus(FALSE, NULL, NULL);
			(void)rbd_NFCVehIf_UpdateNFCReaderState((uint8)WCPM2,(uint8)NFC_READER_TAP_START_TEAR_DOWN_STATE_E, NULL);
		}
		else
		{	/* Do Nothing MISRA compliant else */
		}
	}
	else if((((uint8)NFC_READER_TAP_START_CARD_AUTH_FAILED_STATE_E == session_state_u8) || ((uint8)NFC_READER_TAP_START_DEVICE_AUTH_FAILED_STATE_E == session_state_u8))
		&& (READER_IN_SESSION == readerConnection_state_u8))
	{
		Rte_Call_RP_SendAuthStatus_Cbk_SendAuthStatus(FALSE, NULL, NULL);
		(void)rbd_NFCVehIf_UpdateNFCReaderState((uint8)WCPM2,(uint8)NFC_READER_TAP_START_TEAR_DOWN_STATE_E, NULL);
	}
	else if (((uint8)NFC_READER_PHONE_ENABLE_DISABLE_WCP_AUTH_FINISH_STATE_E == session_state_u8) && (READER_IN_SESSION == readerConnection_state_u8))
	{
		rbd_NFCVehIf_NfcTeardown((uint8)WCPM2);
		(void)rbd_NFCVehIf_ResetNFCReaderSessionTag( (uint8)WCPM2 );
		(void)rbdSessionMgr_NfcDisconnected((uint8)WCPM2);
	}
	else
	{	/* Do Nothing MISRA compliant else */
	}
}

/**********************************************************************************************************************
 *
 * Runnable Entity Name: rbd_NFCVehIf_GetNfcUID_Start_RequestResults
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered by server invocation for OperationPrototype <RequestResults> of PortPrototype <rbd_NFCVehIf_GetNfcUID_Start>
 *
 **********************************************************************************************************************
 *
 * Runnable prototype:
 * ===================
 *   Std_ReturnType rbd_NFCVehIf_GetNfcUID_Start_RequestResults(uint8 *Out_ResData, Dcm_NegativeResponseCodeType *ErrorCode)
 *
 **********************************************************************************************************************
 *
 * Available Application Errors:
 * =============================
 *   RTE_E_GetNfcUID_Start_E_NOT_OK
 *   RTE_E_GetNfcUID_Start_E_OK
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: rbd_NFCVehIf_GetNfcUID_Start_RequestResults_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(Std_ReturnType, rbd_NFCVehIf_CODE) rbd_NFCVehIf_GetNfcUID_Start_RequestResults(P2VAR(uint8, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) Out_ResData, P2VAR(Dcm_NegativeResponseCodeType, AUTOMATIC, RTE_RBD_NFCVEHIF_APPL_VAR) ErrorCode) /* PRQA S 0624, 3206 */ /* MD_Rte_0624, MD_Rte_3206 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: rbd_NFCVehIf_GetNfcUID_Start_RequestResults (returns application error)
 *********************************************************************************************************************/

	/*AXIVION Disable Style MisraC2012-18.1: Pointer arithmetic on Out_ResData creates pointer outside array bounds. Justify operation is valid and not out of bounds */
	Out_ResData[0] = (uint8)rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcRoutineStatus;	/* Routine status 	0x00= UnInitialized, 0x01= Success, 0x02=Progress, 0x03=Failure  	*/
	/*AXIVION Disable Style MisraC2012-18.1: Pointer arithmetic on Out_ResData creates pointer outside array bounds. Justify operation is valid and not out of bounds */
	Out_ResData[1] = (uint8)rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcRoutineErrorCode;/* Get UID Error Code 	Bit0= Multiple cards detected Bit1: Timeout*/
	/*AXIVION Disable Style MisraC2012-18.1: Pointer arithmetic on Out_ResData creates pointer outside array bounds. Justify operation is valid and not out of bounds */
	Out_ResData[2] = (uint8)rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcCardData_t.nfcRoutineUId[0];	/* NFC Card UID byte 0 	*/
	/*AXIVION Disable Style MisraC2012-18.1: Pointer arithmetic on Out_ResData creates pointer outside array bounds. Justify operation is valid and not out of bounds */
	Out_ResData[3] = (uint8)rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcCardData_t.nfcRoutineUId[1];	/* NFC Card UID byte 1 	*/
	/*AXIVION Disable Style MisraC2012-18.1: Pointer arithmetic on Out_ResData creates pointer outside array bounds. Justify operation is valid and not out of bounds */
	Out_ResData[4] = (uint8)rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcCardData_t.nfcRoutineUId[2];	/* NFC Card UID byte 2 	*/
	/*AXIVION Disable Style MisraC2012-18.1: Pointer arithmetic on Out_ResData creates pointer outside array bounds. Justify operation is valid and not out of bounds */
	Out_ResData[5] = (uint8)rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcCardData_t.nfcRoutineUId[3];	/* NFC Card UID byte 3 	*/
	/*AXIVION Disable Style MisraC2012-18.1: Pointer arithmetic on Out_ResData creates pointer outside array bounds. Justify operation is valid and not out of bounds */
	Out_ResData[6] = (uint8)rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcCardData_t.nfcRoutineUId[4];	/* NFC Card UID byte 4 	*/
	/*AXIVION Disable Style MisraC2012-18.1: Pointer arithmetic on Out_ResData creates pointer outside array bounds. Justify operation is valid and not out of bounds */
	Out_ResData[7] = (uint8)rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcCardData_t.nfcRoutineUId[5];	/* NFC Card UID byte 5 	*/
	/*AXIVION Disable Style MisraC2012-18.1: Pointer arithmetic on Out_ResData creates pointer outside array bounds. Justify operation is valid and not out of bounds */
	Out_ResData[8] = (uint8)rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcCardData_t.nfcRoutineUId[6];	/* NFC Card UID byte 6 	*/

	*ErrorCode = DCM_E_POSITIVERESPONSE;
    return RTE_E_OK;
}

//----------------------------------------------------------------------------
//! \brief      rbd_NfcIf_ReadTagAndLength
//!             This function parses the tags from the data
//!
//! \param [out] detected_tag_u16: The detected tag from the data stream
//! \param [out] detected_tag_len_u16: The detected tag length
//! \param [in] data_in_pu8: Input data stream
//! \param [in] dataLen_u16: Input data length
//! \return
//!  None
//----------------------------------------------------------------------------
static uint8 rbd_NfcIf_ReadTagAndLength(uint16* detected_tag_u16, uint16* detected_tag_len_u16, const uint8* data_in_pu8, uint16 dataLen_u16)
{
    uint8 position_u8 = 0U;
    boolean tag_found_bool = TRUE;
    uint8 lengthBytes = 0U;
    if ((detected_tag_u16 == NULL) || (detected_tag_len_u16 == NULL) || (data_in_pu8 == NULL) || (dataLen_u16 < 2U))
    {
        tag_found_bool = FALSE;
    }
    if (TRUE == tag_found_bool)
    {
        // See BER-TLV description: bit 8 and bit 7 indicate the tag class, bit 6 whether the object is primitive or
        // constructed and bit 1..5 the actual tag. If bits 1..5 are all 1 (0x1f), another tag byte follows.
        // For our use, we consider all bits to be part of the actual tag (as opposed to the "tag number").
        // This seems to match the approach in the CCC spec.
        if ((data_in_pu8[position_u8] & 0x1fU) == 0x1fU)
        {
            // The tag has at least two bytes.
            if (((uint16)(position_u8 + 2U)) >= dataLen_u16)
            {
                tag_found_bool = FALSE;
            }
            else
            {
                // If MSB is set, we have at least three bytes. We do not support more than two bytes.
                // We do not support three bytes.
                if ((data_in_pu8[position_u8] & 0x80U) != 0U)
                {
                    tag_found_bool = FALSE;
                }
                else
                {
                    *detected_tag_u16 = (uint16)((((uint16)data_in_pu8[position_u8]) << 8U) | ((uint16)data_in_pu8[position_u8 + 1U]));
                    position_u8 += 2U;
                }
            }

        }
        else
        {
            *detected_tag_u16 = data_in_pu8[position_u8];
            position_u8++;
        }
    }
    if (TRUE == tag_found_bool)
    {
        // See BER-TLV description:
        // - if bit 8 is 0, the byte contains the length.
        // - if bit 8 is 1, the other bytes encode the number of bytes that follow. the following bytes encode the
        //   length (big endian).
        // We support at most 2 length bytes.
        if ((data_in_pu8[position_u8] & 0x80U) == 0U)
        {
            *detected_tag_len_u16 = data_in_pu8[position_u8];
            position_u8++;
        }
        else
        {
            lengthBytes = data_in_pu8[position_u8] & 0x7fU;
            if (((uint16)position_u8 + (uint16)lengthBytes) >= dataLen_u16)
            {
                tag_found_bool = FALSE;
            }
            else
            {
                if (lengthBytes == 1U)
                {
                    // long form used to encode exactly one byte.
                    // -> This is required for len > 127 (because bit 0x80 indicates long form is used)
                    *detected_tag_len_u16 = data_in_pu8[position_u8 + 1U];
                    position_u8 += 1U;
                }
                else if (lengthBytes == 2U)
                {
					*detected_tag_len_u16 = (uint16)((((uint16)data_in_pu8[0U]) << 8U) | ((uint16)data_in_pu8[1U]));
                    position_u8 += 2U;
                }
                else
                {
                    // - 127: value not allowed
                    // - 0: indefinite form, we do not support this.
                    // - > 2: not supported by us.
                    tag_found_bool = FALSE;
                }
            }
        }
    }
    if (FALSE == tag_found_bool)
    {
        position_u8 = 0U;
        if (detected_tag_u16 != NULL)
        {
            *detected_tag_u16 = 0U;
        }
        if (detected_tag_len_u16 != NULL)
        {
            *detected_tag_len_u16 = 0U;
        }
    }
    return position_u8;
}

//----------------------------------------------------------------------------
//! \brief      rbd_NfcIf_IsSelectResponseForCard
//!             This function parses the SELECT response and returns TRUE if
//!             its from card otherwise FALSE(phone)
//!
//! \param [out] uid_u8: UID of the card would get placed in here. If application
//!                      doesn't want UID, they can pass parameter as NULL.
//! \param [in] data_pu8: Input data stream
//! \param [in] msgLen_u16: Input data length
//! \return
//!  None
//----------------------------------------------------------------------------
static boolean rbd_NfcIf_IsSelectResponseForCard(const uint8* data_pu8, uint16 msgLen_u16, uint8 * uid_u8)
{
	boolean parsing_ok_bool = TRUE;
	uint16 data_loc_u16 = 0U;
	uint16 currentToplevelTag_u16 = 0U;
    uint16 currentToplevelTagLength_u16 = 0U;
    uint16 subTag_u16 = 0U;
    uint16 subTagLength_u16 = 0U;
	uint16 bytesProcessed_u16 = 0U;
	boolean card_response_bool = FALSE;
	const uint8 CardTag_Hdr_len_u8 = 2u; /* Tag header length can vary however for card specific tags, length is always 2, 1 byte for type and 1 byte for len */

	while ((TRUE == parsing_ok_bool) && (data_loc_u16 < msgLen_u16))
	{
		bytesProcessed_u16 = rbd_NfcIf_ReadTagAndLength(&currentToplevelTag_u16, &currentToplevelTagLength_u16, &data_pu8[data_loc_u16], msgLen_u16 - data_loc_u16);
		if (bytesProcessed_u16 == 0U)
		{
			parsing_ok_bool = FALSE;
		}
		else
        {
            data_loc_u16 += bytesProcessed_u16;
            if ((data_loc_u16 + currentToplevelTagLength_u16) > msgLen_u16)
            {
                parsing_ok_bool = FALSE;
            }
        }
		if (TRUE == parsing_ok_bool)
		{
			switch(currentToplevelTag_u16)
			{
				case NFC_DK_APPLET_VER_TAG: /* supported Digital Key applet protocol versions  */
				case NFC_SPAKE2_VER_TAG: /* supported SPAKE2+ protocol versions (ver.high | ver.low) */
				case NFC_PAIRING_MODE_TAG: /* Pairing Mode Info */
				data_loc_u16 +=currentToplevelTagLength_u16;

				break;

				case NFC_CARD_PARENT_TAG: /* Parent tag fro Cards*/
					card_response_bool = TRUE;
					while ((TRUE == parsing_ok_bool) && (data_loc_u16 < msgLen_u16))
					{
						bytesProcessed_u16 = rbd_NfcIf_ReadTagAndLength(&subTag_u16, &subTagLength_u16, &data_pu8[data_loc_u16], msgLen_u16 - data_loc_u16);
						if((NFC_CARD_UID_TAG == subTag_u16) && ( (uint16)NFC_CARD_UID_LEN == subTagLength_u16))
						{
							if(NULL != uid_u8)
							{
								memcpy(uid_u8, &data_pu8[data_loc_u16 + CardTag_Hdr_len_u8], 7);
							}
						}
						else
						{

						}
						data_loc_u16 +=subTagLength_u16 + CardTag_Hdr_len_u8;
					}
				break;

				default:
					data_loc_u16 +=currentToplevelTagLength_u16;
				break;
			}
		}
	}

	return card_response_bool;
}

//----------------------------------------------------------------------------
//! \brief      rbd_NFCVehIf_SetEvent
//!             This function sets the events for a particular case so that
//!             application can process it later
//!
//! \param [in] eventType_u8: type of the event to be set
//! \return
//!  None
//----------------------------------------------------------------------------
/*AXIVION Disable Style MisraC2012-8.7 :Function has been intentionally kept non-static. In future it could be called by rbd_Rfhm_PSStart_TapsStart.c if needed */
static void rbd_NFCVehIf_SetEvent(uint16 eventType_u16)
{
	rbd_NFCVehIf_EventFlag |= eventType_u16;
}

//----------------------------------------------------------------------------
//! \brief      rbd_NFCVehIf_ClearEvent
//!             This function clears the events
//!
//! \param [in] eventType_u8: type of the event to be cleared
//! \return
//!  None
//----------------------------------------------------------------------------
static void rbd_NFCVehIf_ClearEvent(uint16 eventType_u16)
{
	rbd_NFCVehIf_EventFlag &= ~(eventType_u16);
}

//----------------------------------------------------------------------------
//! \brief      rbd_NFCVehIf_ReadEventWord
//!             This function clears the events
//!
//! \param [in] eventType_u8: type of the event to be cleared
//! \return
//!  None
//----------------------------------------------------------------------------
static uint16 rbd_NFCVehIf_ReadEventWord(void)
{
    return rbd_NFCVehIf_EventFlag;
}

//----------------------------------------------------------------------------
//! \brief      rbd_NFCVehIf_IsRoutineInProgress
//!             This function returns TRUE if any NFC routine viz. pairing
//!             test pairing or GetUID is in progress
//!
//! \param [in] eventType_u8: type of the event to be cleared
//! \return
//!  None
//----------------------------------------------------------------------------
static uint8 rbd_NFCVehIf_IsRoutineInProgress(void)
{
	uint8 ret = FALSE;
	if ( ( rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcRoutineStatus
		== (uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E )
		||
		( rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E].nfcRoutineStatus
			== (uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E )
		||
		( rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcRoutineStatus
			== (uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E ) )
	{
		ret = TRUE;
	}
	else
	{
		ret = FALSE;
	}

	return ret;
}
//----------------------------------------------------------------------------
//! \brief      rbd_NFCVehIf_CardPairingRoutine_Cyclic
//!             Perform Card Pairing operation and have Card Pairing
//!             results available which can then be read by diagnostics
//!
//! \param [in] void
//! \return
//!  None
//----------------------------------------------------------------------------
static void rbd_NFCVehIf_CardPairingRoutine_Cyclic( void )
{
	uint8 checkDkmReturn_u8;
	uint16 nfc_RoutineEvent_u16 = 0x00u;
	uint8 performDeInit = TRUE;
	uint8 sendTearDown = FALSE;
	uint8 cardKeyList[10];
	uint8 wcpmDevRef_u8 = 0xffu;
	uint8 wcpmSession_state_u8 = 0x00u;
	uint8 wcpmReaderConnection_state_u8 = 0x00u;

	switch ( rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].DiagRoutine_State_en )
	{

		case NFC_DIAG_ROUTINE_INIT_STATE_E:
		{
			; /* Default State. FD9 goes to sleep within 8 seconds if its here..provided no other trigger(rke/peps) is active */
		}
		break;

		case NFC_DIAG_ROUTINE_REQUEST_RX_STATE_E:
		{
			(void)Rte_Call_RP_rbdDeviceMgr_GetNumberOfKeyEntries_Operation( (uint8)DEVICE_TYPE_CARD,
				cardKeyList, CARD_REF_LENGTH, &keyCardRef_paried_u8 );
			if ( keyCardRef_paried_u8 >= CARD_REF_LENGTH )
			{
				rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcRoutineStatus =
					(uint8)NFC_ROUTINE_STATUS_UNINITIALIZED_E;
				rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcRoutineErrorCode =
					(uint8)NFC_ROUTINE_NO_ERROR;
				memset(
					rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcCardData_t
						.nfcRoutineUId, 0x00u, NFC_CARD_UID_LEN );
				rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].DiagRoutine_State_en =
					NFC_DIAG_ROUTINE_FD9_DEINIT_STATE_E;
			}
			else
			{
				Rte_Write_PP_CanRequest_DkmNfc_ComRequest( TRUE );
				rbd_NFCVehIf_NfcCardTimer_u16 = NFC_CARD_PAIRING_TIMEOUT;
				/* Load the timer here as well, just in case DKM call rbdSessionMgr_startNFCCardPairing itself fails as happening now */
				rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].DiagRoutine_State_en =
					NFC_DIAG_ROUTINE_FD9_ACTIVE_STATE_E;
				rbd_NFCVehIf_RoutineRetryPolling_u8 = TRUE;
			}
		}
		break;

		case NFC_DIAG_ROUTINE_FD9_ACTIVE_STATE_E:
		{
			checkDkmReturn_u8 = rbdSessionMgr_startNFCCardPairing( (uint8)WCPM2,
				(uint16)NFC_SERIAL_LEN,
				rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcCardData_t
					.nfcRoutineSerialNumber );
			/* The above counter is decremented just in case DKM is not responding with Busy always - Issue 279733 */
			if ( checkDkmReturn_u8 == RBD_SESSIONMGR_E_OK )
			{
				rbdSessionMgr_NfcConnected( (uint8)WCPM2, TRUE, DEVICE_CARD_TYPE ); // need to use DKM's macro value FOR ALL
				rbd_NFCVehIf_NfcCardTimer_u16 = NFC_CARD_PAIRING_TIMEOUT;
				rbd_NFCVehIf_PollingTimeoutTimer_u16 = NFC_CARD_PAIRING_POLLING_RETRY_TIMEOUT;
				(void)rbd_NFCVehIf_UpdateNFCReaderState( (uint8)WCPM2,
					(uint8)NFC_READER_CARD_PLANT_PAIR_STATE_E, NULL );

				rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcRoutineStatus =
					(uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E;
				rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcRoutineErrorCode =
					(uint8)NFC_ROUTINE_NO_ERROR;
				memset(
					rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcCardData_t
						.nfcRoutineUId, 0x00u, NFC_CARD_UID_LEN );
				rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].DiagRoutine_State_en =
					NFC_DIAG_ROUTINE_RUNNING_STATE_E;
				//Clear Event to start with
			}
			else if ( ( checkDkmReturn_u8 == RBD_SESSIONMGR_E_NOT_OK )
				|| ( 0u == rbd_NFCVehIf_NfcCardTimer_u16 ) )
			{
				/* Deactivate the FD9 bus */
				Rte_Write_PP_CanRequest_DkmNfc_ComRequest( FALSE );
				(void)rbd_NFCVehIf_ResetNFCReaderSessionTag( (uint8)WCPM2 );

				rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcRoutineStatus =
					(uint8)NFC_ROUTINE_STATUS_FAILURE_E;
				rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcRoutineErrorCode =
					(uint8) ( NFC_PAIR_ERR_BIT_TIMEOUT_ERR | NFC_PAIR_ERR_BIT_PAIR_FAILURE );
				memset(
					rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcCardData_t
						.nfcRoutineUId, 0x00u, NFC_CARD_UID_LEN );
				rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].DiagRoutine_State_en =
					NFC_DIAG_ROUTINE_FD9_DEINIT_STATE_E;
			}
			else
			{
				/// Do nothing for misra
			}
		}
		break;

		case NFC_DIAG_ROUTINE_RUNNING_STATE_E:
		{
			nfc_RoutineEvent_u16 = rbd_NFCVehIf_ReadEventWord();
			if ( 0x00u != nfc_RoutineEvent_u16 )
			{
				if ( NFC_PAIR_AUTHENTICATION_EVENT
					== ( nfc_RoutineEvent_u16 & NFC_PAIR_AUTHENTICATION_EVENT ) )
				{
					checkDkmReturn_u8 = rbdSessionMgr_GetCardPairingReqResult();
					if ( NFC_CARD_PAIRING_SUCCESS == checkDkmReturn_u8 )
					{
						/* Pairing Success Scenario */
						rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E]
							.nfcRoutineErrorCode = (uint8)NFC_ROUTINE_NO_ERROR;
						rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E]
							.nfcRoutineStatus = (uint8)NFC_ROUTINE_STATUS_SUCCESS_E;
						rbd_NFCVehIf_ReadNFCReaderStatusInfo( (uint8)WCPM2, &wcpmSession_state_u8,
							&wcpmReaderConnection_state_u8, &wcpmDevRef_u8 );
						rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E]
							.nfcRoutineKeyRef = wcpmDevRef_u8;
					}
					else if ( ( NFC_CARD_PRECONDITION_NOT_MET == checkDkmReturn_u8 )
						|| ( NFC_CARD_CERTIFICATE_ERROR == checkDkmReturn_u8 ) )
					{
						/* Pairing Failure Scenario because of certs or preconditions Scenario */
						rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E]
							.nfcRoutineErrorCode = (uint8) ( NFC_PAIR_ERR_BIT_CERT_PROV_ERR
							| NFC_PAIR_ERR_BIT_PAIR_FAILURE );
						rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E]
							.nfcRoutineStatus = (uint8)NFC_ROUTINE_STATUS_FAILURE_E;
						sendTearDown = TRUE;
					}
					else if ( NFC_CARD_DEVICETYPE_ERROR == checkDkmReturn_u8 )
					{
						/* Pairing Failure Scenario because of Fast transation/auth error sequence */
						rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E]
							.nfcRoutineErrorCode = (uint8) ( NFC_PAIR_ERR_BIT_AUTH_ERR
							| NFC_PAIR_ERR_BIT_PAIR_FAILURE );
						rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E]
							.nfcRoutineStatus = (uint8)NFC_ROUTINE_STATUS_FAILURE_E;
						sendTearDown = TRUE;
					}
					else
					{
						/* Everything OK waiting. Should never come here */
						performDeInit = FALSE;
					}
				}
				else if ( ( NFC_WCPM_NOT_READY_EVENT
					== ( nfc_RoutineEvent_u16 & NFC_WCPM_NOT_READY_EVENT ) )
					||
					( NFC_WCPM_DEVICEMOVED_EVENT
						== ( nfc_RoutineEvent_u16 & NFC_WCPM_DEVICEMOVED_EVENT ) )
					||
					( NFC_WCPM_READER_INVALID_MSG_EVENT
						== ( nfc_RoutineEvent_u16 & NFC_WCPM_DEVICEMOVED_EVENT ) ) )
				{
					/* Pairing Failure Scenario because WCPM is not ready */
					rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E]
						.nfcRoutineErrorCode = (uint8) ( NFC_PAIR_ERR_BIT_READER_NOT_READY
						| NFC_PAIR_ERR_BIT_PAIR_FAILURE );
					rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcRoutineStatus =
						(uint8)NFC_ROUTINE_STATUS_FAILURE_E;
					sendTearDown = TRUE;
				}
				else
				{
					performDeInit = FALSE;
				}
				rbd_NFCVehIf_ClearEvent(NFC_EVENT_ALL_EVENT_MASK);
			}
			else if ( (0u == rbd_NFCVehIf_NfcCardTimer_u16) && (FALSE == rbd_NFCVehIf_RoutineRetryPolling_u8) )
			{
				/* Pairing Failure Scenario because WCPM is not responsing - Timeout */
				rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcRoutineErrorCode =
					(uint8) ( NFC_PAIR_ERR_BIT_TIMEOUT_ERR | NFC_PAIR_ERR_BIT_PAIR_FAILURE );
				rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].nfcRoutineStatus =
					(uint8)NFC_ROUTINE_STATUS_FAILURE_E;
				sendTearDown = TRUE;
			}
			else if( (0u == rbd_NFCVehIf_PollingTimeoutTimer_u16) && (TRUE == rbd_NFCVehIf_RoutineRetryPolling_u8) )
			{
				/* Disable the further Retries */
				rbd_NFCVehIf_RoutineRetryPolling_u8 = FALSE;
				sendTearDown = FALSE;
				performDeInit = FALSE;
				rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E]
					.DiagRoutine_State_en = NFC_DIAG_ROUTINE_FD9_ACTIVE_STATE_E;
				rbdSessionMgr_NfcDisconnected( (uint8)WCPM2 );
				rbd_NFCVehIf_NfcCardTimer_u16 = NFC_CARD_PAIRING_TIMEOUT;
				/* Go for polling Retry */
			}
			else
			{
				performDeInit = FALSE;
			}

			if ( TRUE == sendTearDown )
			{
				rbd_NFCVehIf_NfcTeardown( (uint8)WCPM2 );
			}
			else
			{
			}

			if ( TRUE == performDeInit )
			{
				rbd_NFCVehIf_NfcCardTimer_u16 = 0x00u;
				rbd_NFCVehIf_PollingTimeoutTimer_u16 = 0x00u;
				Rte_Write_PP_CanRequest_DkmNfc_ComRequest( FALSE );
				rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].DiagRoutine_State_en =
					NFC_DIAG_ROUTINE_FD9_DEINIT_STATE_E;
				rbdSessionMgr_NfcDisconnected( (uint8)WCPM2 );
				(void)rbd_NFCVehIf_ResetNFCReaderSessionTag( (uint8)WCPM2 );
			}
			else
			{
			}
		}
		break;

		case NFC_DIAG_ROUTINE_FD9_DEINIT_STATE_E:
		{
			rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_PLANT_PAIRING_E].DiagRoutine_State_en =
				NFC_DIAG_ROUTINE_INIT_STATE_E;
			/* Go back to default state Doing Nothing. So that FD9 will go to sleep */
		}
		break;

		default:
		{
			; //do nothing
		}
		break;
	}
}

//----------------------------------------------------------------------------
//! \brief      rbd_NFCVehIf_TestCardPairingRoutine_Cyclic
//!             Perform Test Card Pairing operation and have Test Card Pairing
//!             results available which can then be read by diagnostics
//!
//! \param [in] void
//! \return
//!  None
//----------------------------------------------------------------------------
static void rbd_NFCVehIf_TestCardPairingRoutine_Cyclic( void )
{
	uint8 checkDkmReturn_u8;
	uint8 wcpmDevRef_u8 = 0xffu;
	uint8 wcpmSession_state_u8 = 0x00u;
	uint8 wcpmReaderConnection_state_u8 = 0x00u;
	uint16 nfc_RoutineEvent_u16 = 0x00u;
	uint8 performDeInit = TRUE;
	uint8 sendTearDown = FALSE;

	rbd_NFCVehIf_ReadNFCReaderStatusInfo( (uint8)WCPM2, &wcpmSession_state_u8,
		&wcpmReaderConnection_state_u8, &wcpmDevRef_u8 );

	switch ( rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E].DiagRoutine_State_en )
	{

		case NFC_DIAG_ROUTINE_INIT_STATE_E:
		{
			; /* Default State. FD9 goes to sleep within 8 seconds if its here..provided no other trigger(rke/peps) is active */
		}
		break;

		case NFC_DIAG_ROUTINE_REQUEST_RX_STATE_E:
		{
			Rte_Write_PP_CanRequest_DkmNfc_ComRequest( TRUE );
			/* Load the timer here as well, just in case DKM call rbdSessionMgr_startNFCCardPairing itself fails as happening now */
			rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E].DiagRoutine_State_en =
				NFC_DIAG_ROUTINE_FD9_ACTIVE_STATE_E;
			rbd_NFCVehIf_RoutineRetryPolling_u8 = TRUE;
		}
		break;

		case NFC_DIAG_ROUTINE_FD9_ACTIVE_STATE_E:
		{
			/* Start the Test Card Pairing Procedure */
			rbdSessionMgr_initCardPairingTest( (uint8)WCPM2 );
			(void)rbd_NFCVehIf_UpdateNFCReaderState( (uint8)WCPM2,
				(uint8)NFC_READER_CARD_PLANT_TEST_STATE_E, NULL );
			rbd_NFCVehIf_NfcCardTimer_u16 = NFC_TEST_CARD_PAIRING_TIMEOUT;
			rbd_NFCVehIf_PollingTimeoutTimer_u16 = NFC_CARD_PAIRING_POLLING_RETRY_TIMEOUT;
			rbd_NFCVehIf_UpdateNFCReaderSessionTimeOut( (uint8)WCPM2,
				rbd_NFCVehIf_NfcCardTimer_u16 );

			rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E].nfcRoutineStatus =
				(uint8)NFC_ROUTINE_STATUS_IN_PROGRESS_E;
			rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E].nfcRoutineErrorCode =
				(uint8)NFC_ROUTINE_NO_ERROR;
			memset(
				rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E].nfcCardData_t
					.nfcRoutineUId, 0x00u, NFC_CARD_UID_LEN );
			rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E].DiagRoutine_State_en =
				NFC_DIAG_ROUTINE_RUNNING_STATE_E;
		}
		break;

		case NFC_DIAG_ROUTINE_RUNNING_STATE_E:
		{
			nfc_RoutineEvent_u16 = rbd_NFCVehIf_ReadEventWord();
			if ( 0x00u != nfc_RoutineEvent_u16 )
			{
				if ( NFC_TEST_PAIR_AUTHENTICATION_EVENT
					== ( nfc_RoutineEvent_u16 & NFC_TEST_PAIR_AUTHENTICATION_EVENT ) )
				{
					checkDkmReturn_u8 = rbdSessionMgr_GetCardPairingReqResult();
					if ( NFC_CARD_PAIRING_SUCCESS == checkDkmReturn_u8 )
					{
						/* Pairing Success Scenario */
						rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E]
							.nfcRoutineErrorCode = (uint8)NFC_ROUTINE_NO_ERROR;
						rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E]
							.nfcRoutineStatus = (uint8)NFC_ROUTINE_STATUS_SUCCESS_E;
						sendTearDown = FALSE;
					}
					else if ( NFC_CARD_DEVICETYPE_ERROR == checkDkmReturn_u8 )
					{
						/* Pairing Failure Scenario because of Fast transation/auth error sequence */
						rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E]
							.nfcRoutineErrorCode =
							(uint8) ( NFC_TESTPAIR_ERR_BIT_FAST_TRANS_ERROR );
						rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E]
							.nfcRoutineStatus = (uint8)NFC_ROUTINE_STATUS_FAILURE_E;
						sendTearDown = TRUE;
					}
					else
					{
						/* Everything OK waiting. Should never come here */
						performDeInit = FALSE;
					}
				}
				else if ( ( NFC_WCPM_NOT_READY_EVENT
					== ( nfc_RoutineEvent_u16 & NFC_WCPM_NOT_READY_EVENT ) )
					||
					( NFC_WCPM_DEVICEMOVED_EVENT
						== ( nfc_RoutineEvent_u16 & NFC_WCPM_DEVICEMOVED_EVENT ) )
					||
					( NFC_WCPM_READER_INVALID_MSG_EVENT
						== ( nfc_RoutineEvent_u16 & NFC_WCPM_DEVICEMOVED_EVENT ) ) )
				{
					/* Pairing Failure Scenario because WCPM is not ready */
					rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E]
						.nfcRoutineErrorCode = (uint8) ( NFC_TESTPAIR_ERR_BIT_READER_NOT_READY );
					rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E]
						.nfcRoutineStatus = (uint8)NFC_ROUTINE_STATUS_FAILURE_E;
					sendTearDown = TRUE;
				}
				else
				{
					performDeInit = FALSE;
				}
				rbd_NFCVehIf_ClearEvent(NFC_EVENT_ALL_EVENT_MASK);
			}
			else if ( (0u == rbd_NFCVehIf_NfcCardTimer_u16) && (FALSE == rbd_NFCVehIf_RoutineRetryPolling_u8) )
			{
				/* Pairing Failure Scenario because WCPM is not responsing - Timeout */
				rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E]
					.nfcRoutineErrorCode = (uint8) ( NFC_TESTPAIR_ERR_BIT_TIMEOUT_ERR );
				rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E].nfcRoutineStatus =
					(uint8)NFC_ROUTINE_STATUS_FAILURE_E;
				sendTearDown = TRUE;
			}
			else if( (0u == rbd_NFCVehIf_PollingTimeoutTimer_u16) && (TRUE == rbd_NFCVehIf_RoutineRetryPolling_u8) )
			{
				rbd_NFCVehIf_RoutineRetryPolling_u8 = FALSE;
				sendTearDown = FALSE;
				performDeInit = FALSE;
				rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E]
					.DiagRoutine_State_en = NFC_DIAG_ROUTINE_FD9_ACTIVE_STATE_E;
				rbdSessionMgr_NfcDisconnected( (uint8)WCPM2 );
				/* Go for polling Retry */
			}
			else
			{
				performDeInit = FALSE;
			}

			if ( TRUE == sendTearDown )
			{
				rbd_NFCVehIf_NfcTeardown( (uint8)WCPM2 );
			}
			else
			{
			}

			if ( TRUE == performDeInit )
			{
				rbd_NFCVehIf_NfcCardTimer_u16 = 0x00u;
				rbd_NFCVehIf_PollingTimeoutTimer_u16 = 0x00u;
				Rte_Write_PP_CanRequest_DkmNfc_ComRequest( FALSE );
				rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E]
					.DiagRoutine_State_en = NFC_DIAG_ROUTINE_FD9_DEINIT_STATE_E;
				rbdSessionMgr_NfcDisconnected( (uint8)WCPM2 );
				(void)rbd_NFCVehIf_ResetNFCReaderSessionTag( (uint8)WCPM2 );
			}
			else
			{
			}
		}
		break;

		case NFC_DIAG_ROUTINE_FD9_DEINIT_STATE_E:
		{
			rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_TEST_CARD_PAIRING_E].DiagRoutine_State_en =
				NFC_DIAG_ROUTINE_INIT_STATE_E;
			/* Go back to default state Doing Nothing. So that FD9 will go to sleep */
		}
		break;

		default:
		{
			; //do nothing
		}
		break;
	}
}

//----------------------------------------------------------------------------
//! \brief      rbd_NFCVehIf_GetUIDRoutine_Cyclic
//!             Perform Get UID operation and have GetUID routine Results ready
//!             The routine results are then read by diagnostics
//!
//! \param [in] void
//! \return
//!  None
//----------------------------------------------------------------------------
static void rbd_NFCVehIf_GetUIDRoutine_Cyclic( void )
{
	uint8 wcpmDevRef_u8 = 0xffu;
	uint8 wcpmSession_state_u8 = 0x00u;
	uint8 wcpmReaderConnection_state_u8 = 0x00u;
	uint16 nfc_RoutineEvent_u16 = 0x00u;
	uint8 performDeInit = TRUE;
	uint8 sendTearDown = FALSE;
	const uint8 AidIdentifier[AID_LENGTH] = { 0xA0, 0x00, 0x00, 0x08, 0x09, 0x43, 0x43, 0x43, 0x44,
		0x4B, 0x41, 0x76, 0x31 };

	static uint8 Fd9_ActivationTriggered_GetUID_Ctr = 0u;

	rbd_NFCVehIf_ReadNFCReaderStatusInfo( (uint8)WCPM2, &wcpmSession_state_u8,
		&wcpmReaderConnection_state_u8, &wcpmDevRef_u8 );

	switch ( rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].DiagRoutine_State_en )
	{

		case NFC_DIAG_ROUTINE_INIT_STATE_E:
		{
			Fd9_ActivationTriggered_GetUID_Ctr = 0u; /* Default State. FD9 goes to sleep within 8 seconds if its here..provided no other trigger(rke/peps) is active */
		}
		break;

		case NFC_DIAG_ROUTINE_REQUEST_RX_STATE_E:
		{
			Rte_Write_PP_CanRequest_DkmNfc_ComRequest( TRUE );

			/*AXIVION Disable MisraC2012Directive-4.1 : Fd9_ActivationTriggered_GetUID_Ctr doesn't create overflow */
			Fd9_ActivationTriggered_GetUID_Ctr +=
				( Fd9_ActivationTriggered_GetUID_Ctr < NFC_FD9_WAKEUP_CYCLE_CNT ) ? 1u : 0u;/*AXIVION Disable FaultDetection-IntegerOverflow error - Condition evaluated- controlled behavior overflow not possible */
			if ( Fd9_ActivationTriggered_GetUID_Ctr >= NFC_FD9_WAKEUP_CYCLE_CNT )
			{
				Fd9_ActivationTriggered_GetUID_Ctr = 0x00u;
				rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].DiagRoutine_State_en =
					NFC_DIAG_ROUTINE_FD9_ACTIVE_STATE_E;
			}
			else
			{
			}
		}
		break;

		case NFC_DIAG_ROUTINE_FD9_ACTIVE_STATE_E:
		{
			/* Start the GET UID Routine */
			rbd_NFCVehIf_NfcStartPolling( (uint8)WCPM2, &AidIdentifier[0] );
			(void)rbd_NFCVehIf_RegisterNFCReaderSession( (uint8)WCPM2 );
			(void)rbd_NFCVehIf_UpdateNFCReaderState( (uint8)WCPM2,
				(uint8)NFC_READER_GET_UID_STATE_E, NULL );
			rbd_NFCVehIf_NfcCardTimer_u16 = NFC_GET_UID_POLLING_TIMEOUT;
			rbd_NFCVehIf_UpdateNFCReaderSessionTimeOut( (uint8)WCPM2,
				rbd_NFCVehIf_NfcCardTimer_u16 );
			rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].DiagRoutine_State_en =
				NFC_DIAG_ROUTINE_RUNNING_STATE_E;
		}
		break;

		case NFC_DIAG_ROUTINE_RUNNING_STATE_E:
		{
			nfc_RoutineEvent_u16 = rbd_NFCVehIf_ReadEventWord();
			if ( 0x00u != nfc_RoutineEvent_u16 )
			{
				if ( NFC_WCPM_READER_GETUID_RSP_EVENT
					== ( nfc_RoutineEvent_u16 & NFC_WCPM_READER_GETUID_RSP_EVENT ) )
				{
					/* Pairing Success Scenario */
					rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcRoutineErrorCode =
						(uint8)NFC_ROUTINE_NO_ERROR;
					rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcRoutineStatus =
						(uint8)NFC_ROUTINE_STATUS_SUCCESS_E;
					sendTearDown = TRUE;
				}
				else if ( NFC_WCPM_MULTIDEVICE_PRESENT_EVENT
					== ( nfc_RoutineEvent_u16 & NFC_WCPM_MULTIDEVICE_PRESENT_EVENT ) )
				{
					/* Pairing Success Scenario */
					rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcRoutineErrorCode =
						(uint8)NFC_GETUID_ERR_BIT_MULTIPLE_CARDS;
					rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcRoutineStatus =
						(uint8)NFC_ROUTINE_STATUS_FAILURE_E;
					sendTearDown = TRUE;
				}
				else if ( ( NFC_WCPM_DEVICEMOVED_EVENT
					== ( nfc_RoutineEvent_u16 & NFC_WCPM_DEVICEMOVED_EVENT ) )
					||
					( NFC_WCPM_READER_INVALID_MSG_EVENT
						== ( nfc_RoutineEvent_u16 & NFC_WCPM_DEVICEMOVED_EVENT ) ) )
				{
					/* Pairing Failure Scenario because WCPM is not responsing - Timeout */
					rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcRoutineErrorCode =
						(uint8) ( NFC_GETUID_ERR_BIT_TIMEOUT_ERR );
					rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcRoutineStatus =
						(uint8)NFC_ROUTINE_STATUS_FAILURE_E;
					sendTearDown = TRUE;
				}
				else
				{
					performDeInit = FALSE;
				}

				rbd_NFCVehIf_ClearEvent(NFC_EVENT_ALL_EVENT_MASK);
			}
			else if ( 0u == rbd_NFCVehIf_NfcCardTimer_u16 )
			{
				/* Pairing Failure Scenario because WCPM is not responsing - Timeout */
				rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcRoutineErrorCode =
					(uint8) ( NFC_GETUID_ERR_BIT_TIMEOUT_ERR );
				rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].nfcRoutineStatus =
					(uint8)NFC_ROUTINE_STATUS_FAILURE_E;
				sendTearDown = TRUE;
			}
			else
			{
				performDeInit = FALSE;
			}

			if ( TRUE == sendTearDown )
			{
				rbd_NFCVehIf_NfcTeardown( (uint8)WCPM2 );
			}
			else
			{
			}

			if ( TRUE == performDeInit )
			{
				rbd_NFCVehIf_NfcCardTimer_u16 = 0x00u;
				Rte_Write_PP_CanRequest_DkmNfc_ComRequest( FALSE );
				rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].DiagRoutine_State_en =
					NFC_DIAG_ROUTINE_FD9_DEINIT_STATE_E;
				(void)rbd_NFCVehIf_ResetNFCReaderSessionTag( (uint8)WCPM2 );
			}
			else
			{
			}
		}
		break;

		case NFC_DIAG_ROUTINE_FD9_DEINIT_STATE_E:
		{
			rbd_NFCVehIf_RoutineData_S[NFC_ROUTINE_GROUP_GET_UID_E].DiagRoutine_State_en =
				NFC_DIAG_ROUTINE_INIT_STATE_E;
			/* Go back to default state Doing Nothing. So that FD9 will go to sleep */
		}
		break;

		default:
		{
			; //do nothing
		}
		break;
	}
}
#define rbd_NFCVehIf_STOP_SEC_CODE
#include "rbd_NFCVehIf_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_MemMap */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/



/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2012 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0624:  MISRA rule: Rule8.3
     Reason:     This MISRA violation is a consequence from the RTE requirements [SWS_Rte_01007] [SWS_Rte_01150].
                 The typedefs are never used in the same context.
     Risk:       No functional risk. Only a cast to uint8* is performed.
     Prevention: Not required.

   MD_Rte_3206:  MISRA rule: Rule2.7
     Reason:     The parameter are not used by the code in all possible code variants.
     Risk:       No functional risk.
     Prevention: Not required.

     */
