/******************************************************************************

                  ��Ȩ���� (C), 2001-2012, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : ScApSec.h
  �� �� ��   : ����
  ��������   : 2012��8��27��
  ����޸�   :
  ��������   : SCģ��
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2012��8��27��
    �޸�����   : V7R1C50 ISDB��ȫ�洢��Ŀ����
******************************************************************************/

#ifndef __SCAPSEC_H__
#define __SCAPSEC_H__

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#pragma pack(4)

/*****************************************************************************
  1 ����ͷ�ļ�����
*****************************************************************************/
#include "vos.h"
#include "ScInterface.h"
#include "ScComm.h"

/*****************************************************************************
  2 �궨��
*****************************************************************************/
#define SC_SECURITY_ITEM_NUM                                (16)                /* ��ȫ�洢����� */
#define SC_SECURITY_ITEM_LENGTH_SIZE                        (4)                 /* ��ȫ�洢����ֶδ�С */
#define SC_SECURITY_ITEM_CONTENT_SIZE                       (256)               /* ��ȫ�洢�������ֶδ�С */
#define SC_SECURITY_ITEM_HASH_SIZE                          (32)                /* ��ȫ�洢��HASH�ֶδ�С */
#define SC_SECURITY_ITEM_PADDING_SIZE                       (12)                /* ��ȫ�洢�̶�����ֶδ�С */
#define SC_SECURITY_ITEM_TOTAL_SIZE                         (SC_SECURITY_ITEM_LENGTH_SIZE\
                                                            + SC_SECURITY_ITEM_CONTENT_SIZE\
                                                            + SC_SECURITY_ITEM_HASH_SIZE\
                                                            + SC_SECURITY_ITEM_PADDING_SIZE) /* ��ȫ�洢���ܴ�С */

#define SC_SECURITY_ITEM_PADDING_VALUE                      (0xC)               /* ��ȫ�洢�̶�������� */


#define SC_SEC_AT_KEY_LEN                                   (16)                /* ��ȫAT key�ĳ��� */
#define SC_APSEC_SP_MAX_DATA_LEN                            (266)               /* ��ȫ������ݶ���󳤶� */
#define SC_AES_TEXT_MIN_LEN                                 (16)                /* AES�ӽ����㷨�ı���С�ֽ��� */
#define SC_APSEC_SP_MAJOR_VERSION                           (1)                 /* ��ȫ���������汾 */
#define SC_APSEC_SP_MAJOR_SECSTORE                          (1)                 /* ��ȫ������������Ͱ�ȫ�洢 */
#define SC_APSEC_SP_MAJOR_AT_KEY                            (0xD0)              /* ��ȫ����������ð�ȫAT key */
#define SC_APSEC_SP_MINOR_VERSION                           (1)                 /* ��ȫ���������汾 */
#define SC_APSEC_SP_MINOR_AT_KEY                            (0x90)              /* ��ȫ����������ð�ȫAT key */
#define SC_APSEC_SP_MINOR_READ                              (1)                 /* ��ȫ�����������ȫ������ */
#define SC_APSEC_SP_MINOR_WRITE                             (2)                 /* ��ȫ�������д��ȫ������ */
#define SC_APSEC_SP_FLAG_REQ                                (1)                 /* AP�·�����ȫ����еı�־λ */
#define SC_APSEC_SP_FLAG_CNF                                (2)                 /* Modem�ظ���ȫ����еı�־λ */
#define SC_APSEC_SP_FLAG_AT_KEY                             (0x40)              /* AP���ð�ȫAT key��ȫ����еı�־λ */
#define SC_APSEC_SP_FLAG_ATSEC_REQ_AT_KEY                   (1)                 /* ��ȫ�����־λ����ȫAT key */
#define SC_APSEC_SP_FLAG_ATSEC_SEQID_ERR                    (4)                 /* ��ȫ�����־λ����ȫAT key */
#define SC_APSEC_SP_FLAG_ATSEC_PARA_ERR                     (5)                 /* ��ȫ�����־λ����ȫAT key */
#define SC_APSEC_SP_FLAG_RLT_SUCCESS                        (0)                 /* ��ȫ�����־λ���ش����ɹ� */
#define SC_APSEC_SP_FLAG_RLT_PARAERR                        (5)                 /* ��ȫ�����־λ���ز������� */
#define SC_APSEC_SP_FLAG_RLT_DUALBACK_FAILED                (6)                 /* ��ȫ�����־λ����˫����ʧ�� */
#define SC_APSEC_SP_SEQID_MIN_VALUE                         (0x01)              /* ��ȫ�����SeqID����Сֵ */
#define SC_APSEC_SP_SEQID_MAX_VALUE                         (0xFF)              /* ��ȫ�����SeqID�����ֵ */
#define SC_APSEC_SP_SEQID_AT_KEY                            (0x00)              /* ���ð�ȫAT keyʱ��ȫ�����SeqID��ֵ */
#define SC_APSEC_SP_RANDOM_LEN                              (16)                /* AP�·������������ */

/*****************************************************************************
  3 ö�ٶ���
*****************************************************************************/
/*****************************************************************************
 ö����    : SC_APSEC_ITME_ENUM
 ö��˵��  : ָ����ȫ�����������

  1.��    ��   : 2012��8��27��
    �޸�����   : V7R1C50 ISDB��ȫ�洢��Ŀ����
*****************************************************************************/
enum SC_APSEC_ITME_ENUM
{
    SC_APSEC_ITME_UE_IMEI_I             =   0,              /* IMEI */
    SC_APSEC_ITME_MMB_KL_TEMP           =   1,              /* Temporary license key */
    SC_APSEC_ITME_MMB_KL_REAL           =   2,              /* Usually license key */
    SC_APSEC_ITME_MMB_CASID             =   3,              /* CA system ID */
    SC_APSEC_ITME_MMB_ME_PUBKEY         =   4,              /* Public key */
    SC_APSEC_ITME_MMB_ME_PRIVKEY        =   5,              /* Private key */
    SC_APSEC_ITME_MMB_ME_SIGNATURE      =   6,              /* signature */
    SC_APSEC_ITME_MMB_SEC_SRV_STAT      =   7,              /* secure clock state */
    SC_APSEC_ITME_MMB_SEC_NITZ          =   8,              /* Broadcast clock */
    SC_APSEC_ITME_MMB_SEC_RTC           =   9,              /* RTC */
    SC_APSEC_ITME_MMB_NUM               =  10,              /* ����1 */
    SC_APSEC_ITME_MMB_RESERVED2         =  11,              /* ����2 */
    SC_APSEC_ITME_MMB_RESERVED3         =  12,              /* ����3 */
    SC_APSEC_ITME_MMB_RESERVED4         =  13,              /* ����4 */
    SC_APSEC_ITME_MMB_RESERVED5         =  14,              /* ����5 */
    SC_APSEC_ITME_MMB_RESERVED6         =  15,              /* ����6 */
    SC_APSEC_ITEM_MMB_BUTT,
};
typedef VOS_UINT32 SC_APSEC_ITME_ENUM_UINT32;

/*****************************************************************************
 ö����    : SC_APSEC_FILE_STATE_INIT_ENUM
 ö��˵��  : ��ȫ�洢�ļ���ʼ��״̬

  1.��    ��   : 2012��8��27��
    �޸�����   : V7R1C50 ISDB��ȫ�洢��Ŀ����
*****************************************************************************/
enum SC_APSEC_FILE_STATE_INIT_ENUM
{
    SC_SECURITY_FILE_STATE_INIT         =   0x5A5A5A5A,     /* ��ȫ�洢�ļ���ʼ����� */
    SC_SECURITY_FILE_STATE_IDEL         =   0x5A5A55AA,     /* ��ȫ�洢�ļ���ʼ��δ��� */
    SC_SECURITY_FILE_STATE_BUTT,
};
typedef VOS_UINT32 SC_APSEC_FILE_STATE_INIT_ENUM_UINT32;


enum SC_APSEC_SP_RESULT_ENUM
{
    SC_APSEC_SP_OK                      =   0,              /* ��ȫ���OK */
    SC_APSEC_SP_NO_SATK                 =   1,              /* ��ȫ����ް�ȫAT key */
    SC_APSEC_SP_PADDING_ERR             =   2,              /* ��ȫ���PADDINGλ���� */
    SC_APSEC_SP_SEQID_ERR               =   3,              /* ��ȫ���SeqIDУ��ʧ�� */
    SC_APSEC_SP_PARA_ERR                =   4,              /* ��ȫ����ֶβ������� */
    SC_APSEC_SP_ERROR,                                      /* ��ȫ������������쳣 */
};
typedef VOS_UINT32 SC_APSEC_SP_RESULT_ENUM_UINT32;


/*****************************************************************************
  4 ȫ�ֱ�������
*****************************************************************************/

/*****************************************************************************
  5 ��Ϣͷ����
*****************************************************************************/
/*****************************************************************************
  6 ��Ϣ����
*****************************************************************************/
/*****************************************************************************
  7 STRUCT����
*****************************************************************************/

/*****************************************************************************
 �ṹ��    : SC_APSEC_SECTURE_ITEM_STRU
 ö��˵��  : ��ȫ�洢���ȡд����ṹ

  1.��    ��   : 2012��8��27��
    �޸�����   : V7R1C50 ISDB��ȫ�洢��Ŀ����
*****************************************************************************/
typedef struct
{
    SC_APSEC_ITME_ENUM_UINT32           enItemId;
    VOS_UINT32                          ulItemLen;
    VOS_UINT8                          *pucContent;
}SC_APSEC_SECTURE_ITEM_STRU;

/*****************************************************************************
 �ṹ��    : SC_APSEC_SECTURE_ITEM_STRU
 ö��˵��  : ��ȫ�洢���ȡд����ṹ

  1.��    ��   : 2012��8��27��
    �޸�����   : V7R1C50 ISDB��ȫ�洢��Ŀ����
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           aucEncryptContent[SC_SECURITY_ITEM_TOTAL_SIZE];
}SC_APSEC_ENCRYPT_STRU;

/*****************************************************************************
 �ṹ��    : SC_APSEC_DEFAULT_ITEM_STRU
 ö��˵��  : ��ȫ�洢��Ĭ�Ͻṹ

  1.��    ��   : 2012��8��27��
    �޸�����   : V7R1C50 ISDB��ȫ�洢��Ŀ����
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulItemLen;
    VOS_UINT8                           aucContent[SC_SECURITY_ITEM_CONTENT_SIZE];
    VOS_UINT8                           aucHash[SC_SECURITY_ITEM_HASH_SIZE];
}SC_APSEC_DEFAULT_ITEM_STRU;


typedef struct
{
    VOS_UINT8                           ucSeqID;
    VOS_UINT8                           ucMajorCMD;
    VOS_UINT8                           ucMinorCMD;
    VOS_UINT8                           ucFlag;
} SC_APSEC_SP_HEADER_STRU;


typedef struct
{
    VOS_UINT8                           ucReserved  :4;
    VOS_UINT8                           ucVer       :2;
    VOS_UINT8                           ucType      :2;
} SC_APSEC_SP_MAJOR_CMD_STRU;


typedef struct
{
    VOS_UINT8                           ucSecItem   :4;
    VOS_UINT8                           ucVer       :2;
    VOS_UINT8                           ucType      :2;
} SC_APSEC_SP_MINOR_CMD_STRU;


typedef struct
{
    VOS_UINT8                           ucResult    :3;
    VOS_UINT8                           ucAtSec     :3;
    VOS_UINT8                           ucType      :2;
} SC_APSEC_SP_FLAG_STRU;


typedef struct
{
    SC_APSEC_SP_HEADER_STRU             stHeader;
    VOS_UINT16                          usDataLen;
    VOS_UINT8                           aucData[SC_APSEC_SP_MAX_DATA_LEN];
} SC_APSEC_SECURE_PACKET_STRU;



/*****************************************************************************
  8 UNION����
*****************************************************************************/
/*****************************************************************************
  9 OTHERS����
*****************************************************************************/
/*****************************************************************************
  10 ��������
*****************************************************************************/


/*****************************************************************************
 �� �� ��  : SC_APSEC_GetFileInitState
 ��������  : ��ȡ˫�����ļ���ʼ��״̬
 �������  : ��
 �������  : ��
 �� �� ֵ  : ˫�����ļ���ʼ��״̬
 �޸���ʷ      :
  1.��    ��   : 2012��8��30��
    �޸�����   : V7R1C50 ISDB��ȫ�洢��Ŀ����
*****************************************************************************/
extern VOS_UINT32  SC_APSEC_GetFileInitState(VOS_VOID);

/*****************************************************************************
 �� �� ��  : SC_APSEC_SetFileInitState
 ��������  : ����˫�����ļ���ʼ��״̬
 �������  : ulState:˫�����ļ���ʼ��״̬
 �������  : ��
 �� �� ֵ  : ��
 �޸���ʷ      :
  1.��    ��   : 2012��8��30��
    �޸�����   : V7R1C50 ISDB��ȫ�洢��Ŀ����
*****************************************************************************/
extern VOS_VOID  SC_APSEC_SetFileInitState(SC_APSEC_FILE_STATE_INIT_ENUM_UINT32 ulState);

/*****************************************************************************
 �� �� ��  : SC_APSEC_EncryptItem
 ��������  : ��ȫ�洢����½ӿ�
 �������  : pucSrc: δ��������
             ulItemLen: item�ĳ���
 �������  : pucDest:���ܺ�����
 �� �� ֵ  : VOS_UINT32
 �޸���ʷ      :
  1.��    ��   : 2012��8��27��
    �޸�����   : V7R1C50 ISDB��ȫ�洢��Ŀ����
*****************************************************************************/
extern VOS_UINT32  SC_APSEC_EncryptItem(
    VOS_UINT32                          ulItemLen,
    const VOS_CHAR                     *pucSrc,
    VOS_CHAR                           *pucDest);

/*****************************************************************************
 �� �� ��  : SC_APSEC_UpdateSecItem
 ��������  : ��ȫ�洢����½ӿ�
 �������  : pstSecItem: ��Ҫ���µİ�ȫ�洢������
             enSecItemId:��ȫ�洢��ID
 �������  : ��
 �� �� ֵ  : VOS_UINT32
 �޸���ʷ      :
  1.��    ��   : 2012��8��27��
    �޸�����   : V7R1C50 ISDB��ȫ�洢��Ŀ����
*****************************************************************************/
extern VOS_UINT32  SC_APSEC_UpdateSecItem(
    SC_APSEC_ITME_ENUM_UINT32           enSecItemId,
    SC_APSEC_DEFAULT_ITEM_STRU         *pstSecItem);

/*****************************************************************************
 �� �� ��  : SC_APSEC_ReadEncryptFile
 ��������  : ���ݼ����ļ���ȡ���ڴ���
 �������  : pucFile:�ļ�·��
 �������  : ppstEncryptFile:�ļ��������ڴ��б���ĵ�ַ
 �� �� ֵ  : �����ļ����ڴ��еĵ�ַ
 �޸���ʷ      :
  1.��    ��   : 2012��8��31��
    �޸�����   : V7R1C50 ISDB��ȫ�洢��Ŀ����
*****************************************************************************/
extern SC_APSEC_ENCRYPT_STRU*  SC_APSEC_ReadEncryptFile(VOS_CHAR *pucFile);

/*****************************************************************************
 �� �� ��  : SC_APSEC_ReadEncryptItem
 ��������  : ˫�����ļ����ܴ洢���ȡ�����HASH���鲢����
 �������  : enSecItemId:��ȫ�洢��ID
             pstFileContent:��ȫ�洢�ļ�ԭʼ����

 �������  : pstSecItem:���ܺ�İ�ȫ�洢��
 �� �� ֵ  : ˫�����ļ���ʼ��״̬
 �޸���ʷ      :
  1.��    ��   : 2012��8��30��
    �޸�����   : V7R1C50 ISDB��ȫ�洢��Ŀ����
*****************************************************************************/
extern VOS_UINT32  SC_APSEC_ReadEncryptItem(
    SC_APSEC_ITME_ENUM_UINT32           enSecItemId,
    SC_APSEC_ENCRYPT_STRU              *pstFileContent,
    SC_APSEC_DEFAULT_ITEM_STRU         *pstSecItem);


/*****************************************************************************
 �� �� ��  : SC_APSEC_InitDualBackFile
 ��������  : ˫�����ļ����ܺ�����ݳ�ʼ�����ڴ���
 �������  : ��
 �������  : ��
 �� �� ֵ  : ˫�����ļ���ʼ��״̬
 �޸���ʷ      :
  1.��    ��   : 2012��8��30��
    �޸�����   : V7R1C50 ISDB��ȫ�洢��Ŀ����
*****************************************************************************/
extern VOS_UINT32  SC_APSEC_InitDualBackFile(VOS_VOID);

/*****************************************************************************
 �� �� ��  : SC_APSEC_GetFileSyncFlg
 ��������  : ˫�����ļ���ͬ����ǻ�ȡ����
 �������  : enSecItemId:��ȫ�洢��
             pstEncryptFileA:ָ������ļ�A�а�ȫ�洢���ָ��
             pstEncryptFileC:ָ������ļ�C�а�ȫ�洢���ָ��
 �������  : pstSecItemA:�����ļ�A���ܺ�õ��İ�ȫ�洢��
             pstSecItemC:�����ļ�C���ܺ�õ��İ�ȫ�洢��
             pulFileSyncFlgA:�ļ�A��Ҫ��ͬ���ı��
             pulFileSyncFlgC:�ļ�C��Ҫ��ͬ���ı��
 �� �� ֵ  : ˫�����ļ���ʼ��״̬
 �޸���ʷ      :
  1.��    ��   : 2012��9��3��
    �޸�����   : V7R1C50 ISDB��ȫ�洢��Ŀ����
*****************************************************************************/
extern VOS_VOID    SC_APSEC_GetFileSyncFlg(
    SC_APSEC_ITME_ENUM_UINT32           enSecItemId,
    SC_APSEC_ENCRYPT_STRU              *pstEncryptFileA,
    SC_APSEC_ENCRYPT_STRU              *pstEncryptFileC,
    SC_APSEC_DEFAULT_ITEM_STRU         *pstSecItemA,
    SC_APSEC_DEFAULT_ITEM_STRU         *pstSecItemC,
    VOS_UINT32                         *pulFileSyncFlgA,
    VOS_UINT32                         *pulFileSyncFlgC);

/*****************************************************************************
 �� �� ��  : SC_APSEC_ResyncFile
 ��������  : ˫�����ļ���ͬ����������
 �������  : ulSyncFileFlg:˫�����ļ���ͬ�����
 �������  : ��
 �� �� ֵ  : ˫�����ļ���ʼ��״̬
 �޸���ʷ      :
  1.��    ��   : 2012��9��3��
    �޸�����   : V7R1C50 ISDB��ȫ�洢��Ŀ����
*****************************************************************************/
extern VOS_UINT32 SC_APSEC_ResyncFile(VOS_UINT32 ulSyncFileFlg);

/*****************************************************************************
 �� �� ��  : SC_APSEC_ReadSecItem
 ��������  : ��ȫ�洢����ȡ
 �������  : ��
 �������  : ��
 �� �� ֵ  : ˫�����ļ���ʼ��״̬
 �޸���ʷ      :
  1.��    ��   : 2012��8��30��
    �޸�����   : V7R1C50 ISDB��ȫ�洢��Ŀ����
*****************************************************************************/
extern VOS_UINT32  SC_APSEC_ReadSecItem(
    SC_APSEC_ITME_ENUM_UINT32           enSecItemId,
    SC_APSEC_DEFAULT_ITEM_STRU         *pstSecItem);

/*****************************************************************************
 �� �� ��  : SC_APSEC_FreshDualBackFile
 ��������  : ��ȫ�洢˫�����ļ�ˢ��
 �������  : ��
 �������  : ��
 �� �� ֵ  : ˫�����ļ���ʼ��״̬
 �޸���ʷ      :
  1.��    ��   : 2012��8��31��
    �޸�����   : V7R1C50 ISDB��ȫ�洢��Ŀ����
*****************************************************************************/
extern VOS_UINT32  SC_APSEC_FreshDualBackFile(VOS_VOID);

/*****************************************************************************
 �� �� ��  : SC_APSEC_IncrementSeqID
 ��������  : ����ȫ�ֱ����е�SeqID����1
 �������  : VOS_VOID
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��9��2��
    �޸�����   : �����ɺ���

*****************************************************************************/
extern VOS_VOID SC_APSEC_IncrementSeqID( VOS_VOID );

/*****************************************************************************
 �� �� ��  : SC_APSEC_RegressSeqID
 ��������  : ��ԭ����ȫ�ֱ����е�SeqID
 �������  : VOS_VOID
 �������  : ��
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��9��2��
    �޸�����   : �����ɺ���

*****************************************************************************/
extern VOS_VOID SC_APSEC_RegressSeqID( VOS_VOID );


extern VOS_UINT32 SC_APSEC_GenerateSecATkey(
    VOS_UINT32                         *pulSPLen,
    VOS_UINT8                          *pucSecPacket );

/*****************************************************************************
 �� �� ��  : SC_APSEC_DecryptSecPacket
 ��������  : ʹ��AES-ECB�㷨���ܰ�ȫ���
 �������  : VOS_UINT8     *pucCipherSP     -- ��ȫ�������
             VOS_UINT32     ulCipherSPLen   -- ��ȫ������ĳ���
 �������  : SC_APSEC_SECURE_PACKET_STRU   *pstSecPacket    -- ���ܺ�İ�ȫ���
 �� �� ֵ  : SC_APSEC_DECRYPT_RESULT_ENUM_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��9��2��
    �޸�����   : �����ɺ���

*****************************************************************************/
SC_APSEC_SP_RESULT_ENUM_UINT32 SC_APSEC_DecryptSecPacket(
    VOS_UINT8                          *pucCipherSP,
    VOS_UINT32                          ulCipherSPLen,
    SC_APSEC_SECURE_PACKET_STRU        *pstSecPacket );

/*****************************************************************************
 �� �� ��  : SC_APSEC_CheckSecPacket
 ��������  : ��鰲ȫ���У��λ
 �������  : pstSecPacket   -- ��У��İ�ȫ���
 �������  : ��
 �� �� ֵ  : SC_APSEC_SP_RESULT_ENUM_UINT32
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��9��2��
    �޸�����   : �����ɺ���

*****************************************************************************/
SC_APSEC_SP_RESULT_ENUM_UINT32 SC_APSEC_CheckSecPacket(
    SC_APSEC_SECURE_PACKET_STRU        *pstSecPacket );


extern VOS_UINT32 SC_APSEC_EncryptSecPacket(
    SC_APSEC_SECURE_PACKET_STRU        *pstSecPacket,
    VOS_UINT8                          *pucCipherSP,
    VOS_UINT32                         *pulCipherSPLen);


extern VOS_UINT32 SC_APSEC_CreateSecPacket(
    SC_APSEC_SP_RESULT_ENUM_UINT32      enResult,
    SC_APSEC_SECURE_PACKET_STRU        *pstSecPacket,
    VOS_UINT8                          *pucSecPacket,
    VOS_UINT32                         *pulSPLen );

/*****************************************************************************
 �� �� ��  : SC_APSEC_DealSecureStorage
 ��������  : ������ȫ�洢����
 �������  : SC_APSEC_SECURE_PACKET_STRU  *pstSecPacket -- �������İ�ȫ���
 �������  : SC_APSEC_SECURE_PACKET_STRU  *pstSecPacket -- ������ɵİ�ȫ���
 �� �� ֵ  : VOS_VOID
 ���ú���  :
 ��������  :

 �޸���ʷ      :
  1.��    ��   : 2012��9��2��
    �޸�����   : �����ɺ���

*****************************************************************************/
extern VOS_VOID SC_APSEC_DealSecureStorage(
    SC_APSEC_SECURE_PACKET_STRU        *pstSecPacket );


extern VOS_UINT32 SC_APSEC_GetDefaultSecItem(
    SC_APSEC_ITME_ENUM_UINT32           enSecItemId,
    SC_APSEC_DEFAULT_ITEM_STRU         *pstSecItem);


extern SC_APSEC_SECTURE_ITEM_STRU* SC_APSEC_GetSecItemDefaultTbl(VOS_VOID);

#if ((VOS_OS_VER == VOS_WIN32) || (VOS_OS_VER == VOS_NUCLEUS))
#pragma pack()
#else
#pragma pack(0)
#endif


#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif
