/******************************************************************************

                  ��Ȩ���� (C), 2001-2011, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : test_sd_drv.h
  �� �� ��   : ����
  ��������   : 2012��10��15��
  ����޸�   :
  ��������   : test_sddrv.h ��ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2012��11��02��
    �޸�����   : �����ļ�

******************************************************************************/

/*****************************************************************************
  1 ����ͷ�ļ�����
*****************************************************************************/



#ifndef __TEST_SD_DRV_H__
#define __TEST_SD_DRV_H__

extern int g_bufferSize;

#define SD_MULTI_BUFFER_SIZE  g_bufferSize

#define ERROR (-1)


#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif



/*****************************************************************************
  2 �궨��
*****************************************************************************/


/*****************************************************************************
  3 ö�ٶ���
*****************************************************************************/


/*****************************************************************************
  4 ��Ϣͷ����
*****************************************************************************/


/*****************************************************************************
  5 ��Ϣ����
*****************************************************************************/


/*****************************************************************************
  6 STRUCT����
*****************************************************************************/


/*****************************************************************************
  7 UNION����
*****************************************************************************/


/*****************************************************************************
  8 OTHERS����
*****************************************************************************/


/*****************************************************************************
  9 ȫ�ֱ�������
*****************************************************************************/


/*****************************************************************************
  10 ��������
*****************************************************************************/
int test_sd_write_single(void);
int test_sd_write_multi(int blkcount);
int test_sd_write_all(void);
int test_sd_read_single(void);
int test_sd_read_multi(int blockcount);
int test_sd_read_all(void);


#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of test_sd_drv.h */
