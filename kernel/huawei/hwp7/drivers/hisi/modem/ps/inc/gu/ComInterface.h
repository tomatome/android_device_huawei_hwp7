/******************************************************************************

                  ��Ȩ���� (C), 2001-2011, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : ComInterface.h
  �� �� ��   : ����
  ��������   : 2011��7��1��
  ����޸�   :
  ��������   : ��NasRrcInterface.h��MmcLmmInterface.h���õ�ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2011��7��1��
    �޸�����   : �����ļ�

******************************************************************************/

/*****************************************************************************
  1 ����ͷ�ļ�����
*****************************************************************************/
#include "vos.h"

#ifndef __COMINTERFACE_H__
#define __COMINTERFACE_H__


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif


#pragma pack(4)

/*****************************************************************************
  2 �궨��
*****************************************************************************/


/*****************************************************************************
  3 ö�ٶ���
*****************************************************************************/
/*****************************************************************************
 ö����    : RRC_NAS_RAT_TYPE_ENUM_UINT32
 �ṹ˵��  : ��ǰ�Ľ��뼼��
 �޸���ʷ      :
 1.��    ��   : 2011��7��1��
   �޸�����   : ����
*****************************************************************************/
enum RRMM_RAT_TYPE_ENUM
{
    RRMM_RAT_TYPE_GSM = 0,                           /* GSM���뼼�� */
    RRMM_RAT_TYPE_WCDMA,                             /* WCDMA���뼼�� */
    RRMM_RAT_TYPE_LTE,                               /* LTE���뼼�� */
    RRMM_RAT_TYPE_BUTT
};
typedef VOS_UINT8 RRMM_RAT_TYPE_ENUM_UINT8;

enum RRMM_RAT_PRIO_ENUM
{
    RRMM_RAT_PRIO_NULL                = 0,               /* �ý��뼼��������    */
    RRMM_RAT_PRIO_LOW                 = 1,               /* ���ȼ��ϵ�   */
    RRMM_RAT_PRIO_MIDDLE              = 2,               /* ���ȼ��м�   */
    RRMM_RAT_PRIO_HIGH                = 3,               /* ���ȼ��ϸ�   */
    RRMM_RAT_PRIO_BUTT
};
typedef VOS_UINT8  RRMM_RAT_PRIO_ENUM_UINT8;


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
/* 7.1 GAS��WAS������Ϣ */
/*******************************************************************************
 �ṹ��    :GSM_BAND_STRU
 Э�����  :
 ASN.1���� :
 �ṹ˵��  : union GSM_BAND_SET_UN��ԱstBitBand����
             bitλ��1��ʾ��Ƶ����Ч
1.��    �� : 2012��3��6��
  �޸����� : �޸�GSM��Ƶ��Ϊ32λ��,�����Ժ���չ            
*******************************************************************************/
typedef struct
{
    VOS_UINT32                          BandGsm450      :1;
    VOS_UINT32                          BandGsm480      :1;
    VOS_UINT32                          BandGsm850      :1;
    VOS_UINT32                          BandGsmP900     :1;
    VOS_UINT32                          BandGsmR900     :1;
    VOS_UINT32                          BandGsmE900     :1;
    VOS_UINT32                          BandGsm1800     :1;
    VOS_UINT32                          BandGsm1900     :1;
    VOS_UINT32                          BandGsm700      :1;
    VOS_UINT32                          BandSpare23     :23;
}GSM_BAND_STRU;
/*******************************************************************************
 �ṹ��    : WCDMA_BAND_STRU
 Э�����  :
 ASN.1���� :
 �ṹ˵��  : union WCDMA_BAND_SET_UN��ԱstBitBand����
             bitλ��1��ʾ��Ƶ����Ч
1.��    �� : 2012��3��6��
  �޸����� : �޸�WCDMA��Ƶ��Ϊ32λ��,֧��W��band19              
*******************************************************************************/
typedef struct
{
    VOS_UINT32                          BandWCDMA_I_2100      :1;
    VOS_UINT32                          BandWCDMA_II_1900     :1;
    VOS_UINT32                          BandWCDMA_III_1800    :1;
    VOS_UINT32                          BandWCDMA_IV_1700     :1;
    VOS_UINT32                          BandWCDMA_V_850       :1;   
    VOS_UINT32                          BandWCDMA_VI_800      :1;
    VOS_UINT32                          BandWCDMA_VII_2600    :1;
    VOS_UINT32                          BandWCDMA_VIII_900    :1;
    VOS_UINT32                          BandWCDMA_IX_J1700    :1;
    VOS_UINT32                          BandSpareBand10       :1;
    VOS_UINT32                          BandWCDMA_XI_1500     :1;
    VOS_UINT32                          BandSpare7            :7;
    VOS_UINT32                          BandWCDMA_XIX_850     :1;
    VOS_UINT32                          BandSpare13           :13;
}WCDMA_BAND_STRU;

/*******************************************************************************
 �ṹ��    : GSM_BAND_SET_UN
 Э�����  :
 ASN.1���� :
 �ṹ˵��  : GSMƵ��union����
1.��    �� : 2012��3��6��
  �޸����� : �޸�GSM��Ƶ��Ϊ32λ��,�����Ժ���չ  
*******************************************************************************/
typedef union
{
    VOS_UINT32                          ulBand;
    
    GSM_BAND_STRU                       stBitBand;
}GSM_BAND_SET_UN;
/*******************************************************************************
 �ṹ��    : WCDMA_BAND_SET_UN
 Э�����  :
 ASN.1���� :
 �ṹ˵��  : WCDMAƵ��union����
1.��    �� : 2012��3��6��
  �޸����� : �޸�WCDMA��Ƶ��Ϊ32λ��,֧��W��band19 
*******************************************************************************/
typedef union
{
    VOS_UINT32                          ulBand;
    
    WCDMA_BAND_STRU                     stBitBand;
}WCDMA_BAND_SET_UN;

/*******************************************************************************
 �ṹ��    : LTE_BAND_STRU
 Э�����  :
 ASN.1���� :
 �ṹ˵��  : LTE��Ƶ�ζ���,aulLteBand[0]������32,aulLteBand[1]������32��Band,
            ���� �û�����Band1,Band3,��aulLteBand[0]=0x05,aulLteBand[1]=0x00
*******************************************************************************/
typedef struct
{
    VOS_UINT32                          aulLteBand[2];
}LTE_BAND_STRU;


/*******************************************************************************
 �ṹ��    : NAS_RRC_WCDMA_BAND_STRU
 �ṹ˵��  : WƵ�ζ���
 �޸���ʷ      :
  1.��    ��   : 2011��7��1��
    �޸�����   : �����ṹ��
  2.��    ��   : 2012��3��6��
    �޸�����   : �޸�WCDMA��Ƶ��Ϊ32λ��,֧��W��band19   
*******************************************************************************/
typedef struct
{
    VOS_UINT32                          ulWcdmaBand;
}NAS_RRC_WCDMA_BAND_STRU;

/*******************************************************************************
 �ṹ��    : NAS_RRC_GSM_BAND_STRU
 �ṹ˵��  : GƵ�ζ���
 �޸���ʷ      :
  1.��    ��   : 2011��7��1��
    �޸�����   : �����ṹ��
  2.��    ��   : 2012��3��6��
    �޸�����   : �޸�GSM��Ƶ��Ϊ32λ��,�����Ժ���չ     
*******************************************************************************/
typedef struct
{
    VOS_UINT32                          ulGsmBand;
}NAS_RRC_GSM_BAND_STRU;



/*******************************************************************************
 �ṹ��    : NAS_RRC_USER_SET_FREQ_BAND_STRU
 �ṹ˵��  : Ƶ�ζ���
 �޸���ʷ      :
  1.��    ��   : 2011��7��1��
    �޸�����   : ����LTE��Ƶ��
  2.��    ��   : 2012��7��17��
    �޸�����   : ����TDS��Ƶ��
  3.��    ��   : 2012��8��14��
    �޸�����   : ɾ��TDS��Ƶ��
*******************************************************************************/
typedef struct
{
    LTE_BAND_STRU                       stLteBand;

    NAS_RRC_WCDMA_BAND_STRU             stWcdmaBand;
    NAS_RRC_GSM_BAND_STRU               stGsmBand;
}NAS_RRC_USER_SET_FREQ_BAND_STRU;


/*****************************************************************************
  8 UNION����
*****************************************************************************/


/*****************************************************************************
  9 OTHERS����
*****************************************************************************/


/*****************************************************************************
  10 ��������
*****************************************************************************/








#if (VOS_OS_VER == VOS_WIN32)
#pragma pack()
#else
#pragma pack(0)
#endif




#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of ComInterface.h */