/******************************************************************************

��Ȩ���� (C), 2001-2011, ��Ϊ�������޹�˾

******************************************************************************
�� �� ��      : XMLDecode.h
�� �� ��      : ����
��������      : 2010��12��20��
����޸�      :
��������      : ��ͷ�ļ�ΪXML��ز���ͷ�ļ�
�����б�      :
�޸���ʷ      :
1.��    ��    : 2010��12��20��
�޸�����    : �����ļ�

******************************************************************************/

#ifndef _XML_DEOCDE_H_
#define _XML_DEOCDE_H_

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif

#pragma pack(4)

/*****************************************************************************
1 ����ͷ�ļ�����
*****************************************************************************/
#include "comm_adapter.h"

/*****************************************************************************
2 �궨��
*****************************************************************************/
#define  XML_FILE_READ_BUFF_SIZE              (4096)  /* ���ļ���������С         */
#define  XML_NODE_LABEL_BUFF_LENGTH_ORIGINAL  (128)   /* �ڵ��ǩ��������С       */
#define  XML_NODE_VALUE_BUFF_LENGTH_ORIGINAL  (32768) /* �ڵ�ֵ��������С         */
#define  XML_MAX_HARDWARE_LEN                 (32)    /* ����Product Id����󳤶� */

/*****************************************************************************
3 ö�ٶ���
*****************************************************************************/

/*****************************************************************************
ö����    : XML_RESULT_ENUM_UINT32
Э�����  :
ASN.1���� :
ö��˵��  : XML����������״̬����ֵ
*****************************************************************************/
enum XML_RESULT_ENUM
{
    XML_RESULT_SUCCEED                        = 0 , /* �ɹ�                      */
    XML_RESULT_SUCCEED_IGNORE_CHAR                , /* ���Ժ��Ե��ַ�\r\n\t      */
    XML_RESULT_FALIED_PARA_POINTER                , /* ����Ĳ���ָ��            */
    XML_RESULT_FALIED_MALLOC                      , /* �ڴ�����ʧ��              */
    XML_RESULT_FALIED_BAD_SYNTAX                  , /* �����XML�﷨             */
    XML_RESULT_FALIED_BAD_CHAR                    , /* ������ַ�                */
    XML_RESULT_FALIED_READ_FILE                   , /* ��ȡ�ļ�ʧ��              */
    XML_RESULT_FALIED_WRITE_NV                    , /* дNV Value����            */
    XML_RESULT_FALIED_OUT_OF_BUFF_LEN             , /* ��������������            */
    XML_RESULT_FALIED_OUT_OF_MAX_VALUE            , /* ����NV ID�����ֵ         */
    XML_RESULT_FALIED_OUT_OF_0_9                  , /* NV IDֵ����0-9            */
    XML_RESULT_FALIED_OUT_OF_0_F                  , /* NV Valueֵ����0-F         */
    XML_RESULT_FALIED_OUT_OF_2_CHAR               , /* NV Valueֵ����1Byte       */
    XML_RESULT_FALIED_NV_ID_IS_NULL               , /* NV IDֵΪ��               */
    XML_RESULT_FALIED_NV_VALUE_IS_NULL            , /* NV ValueֵΪ��            */
    XML_RESULT_FALIED_PRODUCT_MATCH               , /* <product>������ǩû��ƥ�� */
    XML_RESULT_NOT_NEED_DECODE_XML                , /* XML ����Ҫ���� */
    XML_RESULT_FALIED_FILE_OPERATE                , /* XML �ļ�����ʧ�� */
    XML_RESULT_FALIED_NV_READ                     , /* NV��ʧ�� */
    XML_RESULT_BUTT
};
typedef VOS_UINT32 XML_RESULT_ENUM_UINT32;

/*****************************************************************************
ö����    : XML_RESULT_ENUM_UINT32
Э�����  :
ASN.1���� :
ö��˵��  : XML������״̬
*****************************************************************************/
enum XML_ANALYSE_STATUS_ENUM
{
    XML_ANASTT_ORIGINAL                       = 0 , /* ��ʼ                 */
    XML_ANASTT_ENTER_LABLE                        , /* �����ǩ             */
    XML_ANASTT_IGNORE                             , /* ���Ի�ע��           */
    XML_ANASTT_NODE_LABLE                         , /* ������ǩ��           */
    XML_ANASTT_SINGLE_ENDS_LABLE                  , /* ������β��ǩ         */
    XML_ANASTT_LABLE_END_MUST_RIGHT               , /* ��ǩ��ʼ����β       */
    XML_ANASTT_PROPERTY_START                     , /* ��ʼ��������         */
    XML_ANASTT_PROPERTY_NAME_START                , /* ��ʼ������������     */
    XML_ANASTT_PROPERTY_NAME_END                  , /* �������ƽ������ȴ�"  */
    XML_ANASTT_PROPERTY_VALUE_START               , /* "�������ȴ�="        */
    XML_ANASTT_PROPERTY_VALUE_END                 , /* ����ֵ�������ȴ�>    */
    XML_ANASTT_BUTT
};
typedef VOS_UINT32 XML_ANALYSE_STATUS_ENUM_UINT32;
typedef VOS_UINT32 (*XML_FUN)(VOS_CHAR cNowChar);

/*****************************************************************************
ö����    : XML_PRODUCT_NODE_STATUS_ENUM_UINT32
Э�����  :
ASN.1���� :
ö��˵��  : ���ڽ���xnv.xml�ļ�ʱ����¼product�ڵ��¸��ӽڵ�ڵ��Ƿ���Ч
*****************************************************************************/
enum XML_PRODUCT_STATUS_ENUM
{
    XML_PRODUCT_NODE_STATUS_INVALID           = 0 , /* Product�ڵ��Ӧ��ID����Ч�� */
    XML_PRODUCT_NODE_STATUS_VALID                 , /* Product�ڵ��Ӧ��ID����Ч�� */
    XML_PRODUCT_NODE_BUTT
};
typedef VOS_UINT32 XML_PRODUCT_STATUS_ENUM_UINT32;

/*****************************************************************************
ö����    : XML_DECODE_STATE_ENUM_UINT32
Э�����  :
ASN.1���� :
ö��˵��  : ���ڽ���xnv.xml�ļ�ʱ����¼��ǰXML�ļ��Ƿ�������
*****************************************************************************/
enum XML_DECODE_STATUS_ENUM
{
    XML_DECODE_STATUS_DECODING                = 0 , /* ��ǰXML�ļ�������   */
    XML_DECODE_STATUS_FINISHED                    , /* ��ǰXML�ļ�������� */
    XML_DECODE_BUTT
};
typedef VOS_UINT32 XML_DECODE_STATE_ENUM_UINT32;

/*****************************************************************************
4 UNION����
*****************************************************************************/

/*****************************************************************************
5 STRUCT����
*****************************************************************************/

/*****************************************************************************
�ṹ��    : XML_PATH_STRU
Э�����  :
ASN.1���� :
�ṹ˵��  : XML·�����ýṹ
*****************************************************************************/
typedef struct
{
    VOS_CHAR    *pcXNVPath;
    VOS_CHAR    *pcCUSTPath;
}XML_PATH_STRU;

/*****************************************************************************
�ṹ��    : XML_NODE_PROPERTY
Э�����  :
ASN.1���� :
�ṹ˵��  : �ڵ����������ĵ�Ԫ
*****************************************************************************/
typedef struct
{
    VOS_UINT32 ulNameLength;                  /* pcPropertyName ����������  */
    VOS_UINT32 ulValueLength;                 /* pcPropertyValue ���������� */
    VOS_CHAR* pcPropertyName;                 /* ��������                   */
    VOS_CHAR* pcPropertyValue;                /* ����ֵ                     */
}XML_NODE_PROPERTY_STRU;


/*****************************************************************************
�ṹ��    : XML_NODE_STRU
Э�����  :
ASN.1���� :
�ṹ˵��  : XML���Ľڵ�
*****************************************************************************/
typedef struct
{
    VOS_UINT32 ulLabelLength;                 /* pcNodeLabel ����������    */
    VOS_UINT32 ulLabelEndLength;              /* pcNodeLabelEnd ���������� */
    VOS_UINT32 ulValueLength;                 /* pcNodeValue ����������    */
    VOS_CHAR*  pcNodeLabel;                   /* �ڵ��ǩ                  */
    VOS_CHAR*  pcNodeLabelEnd;                /* ��β������ǩ              */
    VOS_CHAR*  pcNodeValue;                   /* �ڵ�ֵ                    */
    XML_NODE_PROPERTY_STRU stProperty;        /* ����                      */
}XML_NODE_STRU;

/*****************************************************************************
�ṹ��    : XML_PRODUCT_STRU
Э�����  :
ASN.1���� :
�ṹ˵��  : ���ڼ�¼PRODUCT�ڵ���Ϣ
*****************************************************************************/
typedef struct
{
    /* ��¼product�ڵ��¸��ӽڵ�ڵ��Ƿ���Ч    */
    XML_PRODUCT_STATUS_ENUM_UINT32 enValidNode;
    /* �ж�XML�����Ƿ����                      */
    XML_DECODE_STATE_ENUM_UINT32   enXMLDecodeState;
    /* ��Ч��Product�ڵ㼰����product�ڵ�ĸ��� */
    VOS_UINT32                     ulNodeLevel;
    /* ��¼��ǰ�����product id                 */
    VOS_CHAR                       acProductId[XML_MAX_HARDWARE_LEN];
}XML_PRODUCT_STRU;

/*****************************************************************************
�ṹ��    : XML_ERROR_INFO_STRU
Э�����  :
ASN.1���� :
�ṹ˵��  : ���ڼ�¼XML������Ϣ
*****************************************************************************/
typedef struct
{
    VOS_UINT32 ulXMLLine;      /* XML��Ӧ���к�      */
    VOS_UINT32 ulStatus;       /* XML��Ӧ�Ľ���״̬  */
    VOS_UINT32 ulCodeLine;     /* ���������Ӧ���к� */
    VOS_UINT16 usNvId;         /* NV ID��ֵ          */
    VOS_UINT16 usReserve;      /* NV ID��ֵ          */
    VOS_UINT32 ulResult;       /* ���صĽ��         */
} XML_ERROR_INFO_STRU;

/*****************************************************************************
6 ��Ϣͷ����
*****************************************************************************/


/*****************************************************************************
7 ��Ϣ����
*****************************************************************************/


/*****************************************************************************
8 ȫ�ֱ�������
*****************************************************************************/


/*****************************************************************************
9 OTHERS����
*****************************************************************************/


/*****************************************************************************
10 ��������
*****************************************************************************/
extern XML_RESULT_ENUM_UINT32 XML_WriteNVItem(VOS_VOID);

extern XML_RESULT_ENUM_UINT32 XML_StringToNvId(VOS_CHAR  *pcBuff,
                                        VOS_UINT16 *pusRetVal);

extern XML_RESULT_ENUM_UINT32 XML_StringToNvValue(VOS_UINT8  *pucBuff,
                                             VOS_UINT8  *pucRetBuff,
                                             VOS_UINT32 *pulRetBuffLen);

extern VOS_VOID XML_WriteErrorLog(VOS_UINT32 ulErrLine, VOS_UINT16 ulNvId,
                            VOS_UINT32 ulResult);

extern XML_RESULT_ENUM_UINT32 XML_ProcInit(VOS_VOID);

extern XML_RESULT_ENUM_UINT32 XML_DecodeXMLFile(FILE* pfFile);

extern VOS_VOID XML_FreeMem(VOS_VOID);

extern VOS_VOID XML_InitGlobal(VOS_VOID);

extern VOS_VOID XML_DecodeMain(VOS_VOID);

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

#endif /* _XML_H_ */