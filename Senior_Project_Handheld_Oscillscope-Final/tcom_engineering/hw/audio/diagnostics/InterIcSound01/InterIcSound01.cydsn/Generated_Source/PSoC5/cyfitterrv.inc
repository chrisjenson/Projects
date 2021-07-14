;
; File Name: cyfitterrv.inc
; 
; PSoC Creator  4.2
;
; Description:
; 
;
;-------------------------------------------------------------------------------
; Copyright (c) 2007-2018 Cypress Semiconductor.  All rights reserved.
; You may use this file only in accordance with the license, terms, conditions, 
; disclaimers, and limitations in the end user license agreement accompanying 
; the software package with which this file was provided.
;-------------------------------------------------------------------------------

    IF :LNOT::DEF:INCLUDED_CYFITTERRV_INC
INCLUDED_CYFITTERRV_INC EQU 1
    GET cydevicerv.inc
    GET cydevicerv_trm.inc

; WS
WS__0__INTTYPE EQU CYREG_PICU3_INTTYPE2
WS__0__MASK EQU 0x04
WS__0__PC EQU CYREG_PRT3_PC2
WS__0__PORT EQU 3
WS__0__SHIFT EQU 2
WS__AG EQU CYREG_PRT3_AG
WS__AMUX EQU CYREG_PRT3_AMUX
WS__BIE EQU CYREG_PRT3_BIE
WS__BIT_MASK EQU CYREG_PRT3_BIT_MASK
WS__BYP EQU CYREG_PRT3_BYP
WS__CTL EQU CYREG_PRT3_CTL
WS__DM0 EQU CYREG_PRT3_DM0
WS__DM1 EQU CYREG_PRT3_DM1
WS__DM2 EQU CYREG_PRT3_DM2
WS__DR EQU CYREG_PRT3_DR
WS__INP_DIS EQU CYREG_PRT3_INP_DIS
WS__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU3_BASE
WS__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
WS__LCD_EN EQU CYREG_PRT3_LCD_EN
WS__MASK EQU 0x04
WS__PORT EQU 3
WS__PRT EQU CYREG_PRT3_PRT
WS__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
WS__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
WS__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
WS__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
WS__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
WS__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
WS__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
WS__PS EQU CYREG_PRT3_PS
WS__SHIFT EQU 2
WS__SLW EQU CYREG_PRT3_SLW

; LCD
LCD_LCDPort__0__INTTYPE EQU CYREG_PICU2_INTTYPE0
LCD_LCDPort__0__MASK EQU 0x01
LCD_LCDPort__0__PC EQU CYREG_PRT2_PC0
LCD_LCDPort__0__PORT EQU 2
LCD_LCDPort__0__SHIFT EQU 0
LCD_LCDPort__1__INTTYPE EQU CYREG_PICU2_INTTYPE1
LCD_LCDPort__1__MASK EQU 0x02
LCD_LCDPort__1__PC EQU CYREG_PRT2_PC1
LCD_LCDPort__1__PORT EQU 2
LCD_LCDPort__1__SHIFT EQU 1
LCD_LCDPort__2__INTTYPE EQU CYREG_PICU2_INTTYPE2
LCD_LCDPort__2__MASK EQU 0x04
LCD_LCDPort__2__PC EQU CYREG_PRT2_PC2
LCD_LCDPort__2__PORT EQU 2
LCD_LCDPort__2__SHIFT EQU 2
LCD_LCDPort__3__INTTYPE EQU CYREG_PICU2_INTTYPE3
LCD_LCDPort__3__MASK EQU 0x08
LCD_LCDPort__3__PC EQU CYREG_PRT2_PC3
LCD_LCDPort__3__PORT EQU 2
LCD_LCDPort__3__SHIFT EQU 3
LCD_LCDPort__4__INTTYPE EQU CYREG_PICU2_INTTYPE4
LCD_LCDPort__4__MASK EQU 0x10
LCD_LCDPort__4__PC EQU CYREG_PRT2_PC4
LCD_LCDPort__4__PORT EQU 2
LCD_LCDPort__4__SHIFT EQU 4
LCD_LCDPort__5__INTTYPE EQU CYREG_PICU2_INTTYPE5
LCD_LCDPort__5__MASK EQU 0x20
LCD_LCDPort__5__PC EQU CYREG_PRT2_PC5
LCD_LCDPort__5__PORT EQU 2
LCD_LCDPort__5__SHIFT EQU 5
LCD_LCDPort__6__INTTYPE EQU CYREG_PICU2_INTTYPE6
LCD_LCDPort__6__MASK EQU 0x40
LCD_LCDPort__6__PC EQU CYREG_PRT2_PC6
LCD_LCDPort__6__PORT EQU 2
LCD_LCDPort__6__SHIFT EQU 6
LCD_LCDPort__AG EQU CYREG_PRT2_AG
LCD_LCDPort__AMUX EQU CYREG_PRT2_AMUX
LCD_LCDPort__BIE EQU CYREG_PRT2_BIE
LCD_LCDPort__BIT_MASK EQU CYREG_PRT2_BIT_MASK
LCD_LCDPort__BYP EQU CYREG_PRT2_BYP
LCD_LCDPort__CTL EQU CYREG_PRT2_CTL
LCD_LCDPort__DM0 EQU CYREG_PRT2_DM0
LCD_LCDPort__DM1 EQU CYREG_PRT2_DM1
LCD_LCDPort__DM2 EQU CYREG_PRT2_DM2
LCD_LCDPort__DR EQU CYREG_PRT2_DR
LCD_LCDPort__INP_DIS EQU CYREG_PRT2_INP_DIS
LCD_LCDPort__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
LCD_LCDPort__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
LCD_LCDPort__LCD_EN EQU CYREG_PRT2_LCD_EN
LCD_LCDPort__MASK EQU 0x7F
LCD_LCDPort__PORT EQU 2
LCD_LCDPort__PRT EQU CYREG_PRT2_PRT
LCD_LCDPort__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
LCD_LCDPort__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
LCD_LCDPort__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
LCD_LCDPort__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
LCD_LCDPort__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
LCD_LCDPort__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
LCD_LCDPort__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
LCD_LCDPort__PS EQU CYREG_PRT2_PS
LCD_LCDPort__SHIFT EQU 0
LCD_LCDPort__SLW EQU CYREG_PRT2_SLW

; SCK
SCK__0__INTTYPE EQU CYREG_PICU3_INTTYPE0
SCK__0__MASK EQU 0x01
SCK__0__PC EQU CYREG_PRT3_PC0
SCK__0__PORT EQU 3
SCK__0__SHIFT EQU 0
SCK__AG EQU CYREG_PRT3_AG
SCK__AMUX EQU CYREG_PRT3_AMUX
SCK__BIE EQU CYREG_PRT3_BIE
SCK__BIT_MASK EQU CYREG_PRT3_BIT_MASK
SCK__BYP EQU CYREG_PRT3_BYP
SCK__CTL EQU CYREG_PRT3_CTL
SCK__DM0 EQU CYREG_PRT3_DM0
SCK__DM1 EQU CYREG_PRT3_DM1
SCK__DM2 EQU CYREG_PRT3_DM2
SCK__DR EQU CYREG_PRT3_DR
SCK__INP_DIS EQU CYREG_PRT3_INP_DIS
SCK__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU3_BASE
SCK__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
SCK__LCD_EN EQU CYREG_PRT3_LCD_EN
SCK__MASK EQU 0x01
SCK__PORT EQU 3
SCK__PRT EQU CYREG_PRT3_PRT
SCK__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
SCK__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
SCK__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
SCK__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
SCK__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
SCK__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
SCK__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
SCK__PS EQU CYREG_PRT3_PS
SCK__SHIFT EQU 0
SCK__SLW EQU CYREG_PRT3_SLW

; SDI
SDI__0__INTTYPE EQU CYREG_PICU3_INTTYPE1
SDI__0__MASK EQU 0x02
SDI__0__PC EQU CYREG_PRT3_PC1
SDI__0__PORT EQU 3
SDI__0__SHIFT EQU 1
SDI__AG EQU CYREG_PRT3_AG
SDI__AMUX EQU CYREG_PRT3_AMUX
SDI__BIE EQU CYREG_PRT3_BIE
SDI__BIT_MASK EQU CYREG_PRT3_BIT_MASK
SDI__BYP EQU CYREG_PRT3_BYP
SDI__CTL EQU CYREG_PRT3_CTL
SDI__DM0 EQU CYREG_PRT3_DM0
SDI__DM1 EQU CYREG_PRT3_DM1
SDI__DM2 EQU CYREG_PRT3_DM2
SDI__DR EQU CYREG_PRT3_DR
SDI__INP_DIS EQU CYREG_PRT3_INP_DIS
SDI__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU3_BASE
SDI__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
SDI__LCD_EN EQU CYREG_PRT3_LCD_EN
SDI__MASK EQU 0x02
SDI__PORT EQU 3
SDI__PRT EQU CYREG_PRT3_PRT
SDI__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
SDI__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
SDI__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
SDI__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
SDI__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
SDI__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
SDI__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
SDI__PS EQU CYREG_PRT3_PS
SDI__SHIFT EQU 1
SDI__SLW EQU CYREG_PRT3_SLW

; I2S_1
I2S_1_bI2S_BitCounter__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B1_UDB04_05_ACTL
I2S_1_bI2S_BitCounter__16BIT_CONTROL_CONTROL_REG EQU CYREG_B1_UDB04_05_CTL
I2S_1_bI2S_BitCounter__16BIT_CONTROL_COUNT_REG EQU CYREG_B1_UDB04_05_CTL
I2S_1_bI2S_BitCounter__16BIT_COUNT_CONTROL_REG EQU CYREG_B1_UDB04_05_CTL
I2S_1_bI2S_BitCounter__16BIT_COUNT_COUNT_REG EQU CYREG_B1_UDB04_05_CTL
I2S_1_bI2S_BitCounter__16BIT_MASK_MASK_REG EQU CYREG_B1_UDB04_05_MSK
I2S_1_bI2S_BitCounter__16BIT_MASK_PERIOD_REG EQU CYREG_B1_UDB04_05_MSK
I2S_1_bI2S_BitCounter__16BIT_PERIOD_MASK_REG EQU CYREG_B1_UDB04_05_MSK
I2S_1_bI2S_BitCounter__16BIT_PERIOD_PERIOD_REG EQU CYREG_B1_UDB04_05_MSK
I2S_1_bI2S_BitCounter__CONTROL_AUX_CTL_REG EQU CYREG_B1_UDB04_ACTL
I2S_1_bI2S_BitCounter__CONTROL_REG EQU CYREG_B1_UDB04_CTL
I2S_1_bI2S_BitCounter__CONTROL_ST_REG EQU CYREG_B1_UDB04_ST_CTL
I2S_1_bI2S_BitCounter__COUNT_REG EQU CYREG_B1_UDB04_CTL
I2S_1_bI2S_BitCounter__COUNT_ST_REG EQU CYREG_B1_UDB04_ST_CTL
I2S_1_bI2S_BitCounter__MASK_CTL_AUX_CTL_REG EQU CYREG_B1_UDB04_MSK_ACTL
I2S_1_bI2S_BitCounter__PER_CTL_AUX_CTL_REG EQU CYREG_B1_UDB04_MSK_ACTL
I2S_1_bI2S_BitCounter__PERIOD_REG EQU CYREG_B1_UDB04_MSK
I2S_1_bI2S_BitCounter_ST__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B1_UDB04_05_ACTL
I2S_1_bI2S_BitCounter_ST__16BIT_STATUS_REG EQU CYREG_B1_UDB04_05_ST
I2S_1_bI2S_BitCounter_ST__MASK_REG EQU CYREG_B1_UDB04_MSK
I2S_1_bI2S_BitCounter_ST__MASK_ST_AUX_CTL_REG EQU CYREG_B1_UDB04_MSK_ACTL
I2S_1_bI2S_BitCounter_ST__PER_ST_AUX_CTL_REG EQU CYREG_B1_UDB04_MSK_ACTL
I2S_1_bI2S_BitCounter_ST__STATUS_AUX_CTL_REG EQU CYREG_B1_UDB04_ACTL
I2S_1_bI2S_BitCounter_ST__STATUS_CNT_REG EQU CYREG_B1_UDB04_ST_CTL
I2S_1_bI2S_BitCounter_ST__STATUS_CONTROL_REG EQU CYREG_B1_UDB04_ST_CTL
I2S_1_bI2S_BitCounter_ST__STATUS_REG EQU CYREG_B1_UDB04_ST
I2S_1_bI2S_CtlReg__1__MASK EQU 0x02
I2S_1_bI2S_CtlReg__1__POS EQU 1
I2S_1_bI2S_CtlReg__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B1_UDB05_06_ACTL
I2S_1_bI2S_CtlReg__16BIT_CONTROL_CONTROL_REG EQU CYREG_B1_UDB05_06_CTL
I2S_1_bI2S_CtlReg__16BIT_CONTROL_COUNT_REG EQU CYREG_B1_UDB05_06_CTL
I2S_1_bI2S_CtlReg__16BIT_COUNT_CONTROL_REG EQU CYREG_B1_UDB05_06_CTL
I2S_1_bI2S_CtlReg__16BIT_COUNT_COUNT_REG EQU CYREG_B1_UDB05_06_CTL
I2S_1_bI2S_CtlReg__16BIT_MASK_MASK_REG EQU CYREG_B1_UDB05_06_MSK
I2S_1_bI2S_CtlReg__16BIT_MASK_PERIOD_REG EQU CYREG_B1_UDB05_06_MSK
I2S_1_bI2S_CtlReg__16BIT_PERIOD_MASK_REG EQU CYREG_B1_UDB05_06_MSK
I2S_1_bI2S_CtlReg__16BIT_PERIOD_PERIOD_REG EQU CYREG_B1_UDB05_06_MSK
I2S_1_bI2S_CtlReg__2__MASK EQU 0x04
I2S_1_bI2S_CtlReg__2__POS EQU 2
I2S_1_bI2S_CtlReg__CONTROL_AUX_CTL_REG EQU CYREG_B1_UDB05_ACTL
I2S_1_bI2S_CtlReg__CONTROL_REG EQU CYREG_B1_UDB05_CTL
I2S_1_bI2S_CtlReg__CONTROL_ST_REG EQU CYREG_B1_UDB05_ST_CTL
I2S_1_bI2S_CtlReg__COUNT_REG EQU CYREG_B1_UDB05_CTL
I2S_1_bI2S_CtlReg__COUNT_ST_REG EQU CYREG_B1_UDB05_ST_CTL
I2S_1_bI2S_CtlReg__MASK EQU 0x06
I2S_1_bI2S_CtlReg__MASK_CTL_AUX_CTL_REG EQU CYREG_B1_UDB05_MSK_ACTL
I2S_1_bI2S_CtlReg__PER_CTL_AUX_CTL_REG EQU CYREG_B1_UDB05_MSK_ACTL
I2S_1_bI2S_CtlReg__PERIOD_REG EQU CYREG_B1_UDB05_MSK
I2S_1_bI2S_Rx_CH_0__dpRx_u0__16BIT_A0_REG EQU CYREG_B1_UDB05_06_A0
I2S_1_bI2S_Rx_CH_0__dpRx_u0__16BIT_A1_REG EQU CYREG_B1_UDB05_06_A1
I2S_1_bI2S_Rx_CH_0__dpRx_u0__16BIT_D0_REG EQU CYREG_B1_UDB05_06_D0
I2S_1_bI2S_Rx_CH_0__dpRx_u0__16BIT_D1_REG EQU CYREG_B1_UDB05_06_D1
I2S_1_bI2S_Rx_CH_0__dpRx_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B1_UDB05_06_ACTL
I2S_1_bI2S_Rx_CH_0__dpRx_u0__16BIT_F0_REG EQU CYREG_B1_UDB05_06_F0
I2S_1_bI2S_Rx_CH_0__dpRx_u0__16BIT_F1_REG EQU CYREG_B1_UDB05_06_F1
I2S_1_bI2S_Rx_CH_0__dpRx_u0__A0_A1_REG EQU CYREG_B1_UDB05_A0_A1
I2S_1_bI2S_Rx_CH_0__dpRx_u0__A0_REG EQU CYREG_B1_UDB05_A0
I2S_1_bI2S_Rx_CH_0__dpRx_u0__A1_REG EQU CYREG_B1_UDB05_A1
I2S_1_bI2S_Rx_CH_0__dpRx_u0__D0_D1_REG EQU CYREG_B1_UDB05_D0_D1
I2S_1_bI2S_Rx_CH_0__dpRx_u0__D0_REG EQU CYREG_B1_UDB05_D0
I2S_1_bI2S_Rx_CH_0__dpRx_u0__D1_REG EQU CYREG_B1_UDB05_D1
I2S_1_bI2S_Rx_CH_0__dpRx_u0__DP_AUX_CTL_REG EQU CYREG_B1_UDB05_ACTL
I2S_1_bI2S_Rx_CH_0__dpRx_u0__F0_F1_REG EQU CYREG_B1_UDB05_F0_F1
I2S_1_bI2S_Rx_CH_0__dpRx_u0__F0_REG EQU CYREG_B1_UDB05_F0
I2S_1_bI2S_Rx_CH_0__dpRx_u0__F1_REG EQU CYREG_B1_UDB05_F1
I2S_1_bI2S_Rx_CH_0__dpRx_u0__MSK_DP_AUX_CTL_REG EQU CYREG_B1_UDB05_MSK_ACTL
I2S_1_bI2S_Rx_CH_0__dpRx_u0__PER_DP_AUX_CTL_REG EQU CYREG_B1_UDB05_MSK_ACTL
I2S_1_bI2S_Rx_STS_0__Sts__0__MASK EQU 0x01
I2S_1_bI2S_Rx_STS_0__Sts__0__POS EQU 0
I2S_1_bI2S_Rx_STS_0__Sts__1__MASK EQU 0x02
I2S_1_bI2S_Rx_STS_0__Sts__1__POS EQU 1
I2S_1_bI2S_Rx_STS_0__Sts__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B1_UDB05_06_ACTL
I2S_1_bI2S_Rx_STS_0__Sts__16BIT_STATUS_REG EQU CYREG_B1_UDB05_06_ST
I2S_1_bI2S_Rx_STS_0__Sts__MASK EQU 0x03
I2S_1_bI2S_Rx_STS_0__Sts__MASK_REG EQU CYREG_B1_UDB05_MSK
I2S_1_bI2S_Rx_STS_0__Sts__MASK_ST_AUX_CTL_REG EQU CYREG_B1_UDB05_MSK_ACTL
I2S_1_bI2S_Rx_STS_0__Sts__PER_ST_AUX_CTL_REG EQU CYREG_B1_UDB05_MSK_ACTL
I2S_1_bI2S_Rx_STS_0__Sts__STATUS_AUX_CTL_REG EQU CYREG_B1_UDB05_ACTL
I2S_1_bI2S_Rx_STS_0__Sts__STATUS_CNT_REG EQU CYREG_B1_UDB05_ST_CTL
I2S_1_bI2S_Rx_STS_0__Sts__STATUS_CONTROL_REG EQU CYREG_B1_UDB05_ST_CTL
I2S_1_bI2S_Rx_STS_0__Sts__STATUS_REG EQU CYREG_B1_UDB05_ST

; Pin_1
Pin_1__0__INTTYPE EQU CYREG_PICU3_INTTYPE3
Pin_1__0__MASK EQU 0x08
Pin_1__0__PC EQU CYREG_PRT3_PC3
Pin_1__0__PORT EQU 3
Pin_1__0__SHIFT EQU 3
Pin_1__AG EQU CYREG_PRT3_AG
Pin_1__AMUX EQU CYREG_PRT3_AMUX
Pin_1__BIE EQU CYREG_PRT3_BIE
Pin_1__BIT_MASK EQU CYREG_PRT3_BIT_MASK
Pin_1__BYP EQU CYREG_PRT3_BYP
Pin_1__CTL EQU CYREG_PRT3_CTL
Pin_1__DM0 EQU CYREG_PRT3_DM0
Pin_1__DM1 EQU CYREG_PRT3_DM1
Pin_1__DM2 EQU CYREG_PRT3_DM2
Pin_1__DR EQU CYREG_PRT3_DR
Pin_1__INP_DIS EQU CYREG_PRT3_INP_DIS
Pin_1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU3_BASE
Pin_1__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
Pin_1__LCD_EN EQU CYREG_PRT3_LCD_EN
Pin_1__MASK EQU 0x08
Pin_1__PORT EQU 3
Pin_1__PRT EQU CYREG_PRT3_PRT
Pin_1__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
Pin_1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
Pin_1__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
Pin_1__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
Pin_1__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
Pin_1__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
Pin_1__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
Pin_1__PS EQU CYREG_PRT3_PS
Pin_1__SHIFT EQU 3
Pin_1__SLW EQU CYREG_PRT3_SLW

; clock
clock__CFG0 EQU CYREG_CLKDIST_DCFG0_CFG0
clock__CFG1 EQU CYREG_CLKDIST_DCFG0_CFG1
clock__CFG2 EQU CYREG_CLKDIST_DCFG0_CFG2
clock__CFG2_SRC_SEL_MASK EQU 0x07
clock__INDEX EQU 0x00
clock__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
clock__PM_ACT_MSK EQU 0x01
clock__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
clock__PM_STBY_MSK EQU 0x01

; VDAC8_1
VDAC8_1_viDAC8__CR0 EQU CYREG_DAC3_CR0
VDAC8_1_viDAC8__CR1 EQU CYREG_DAC3_CR1
VDAC8_1_viDAC8__D EQU CYREG_DAC3_D
VDAC8_1_viDAC8__PM_ACT_CFG EQU CYREG_PM_ACT_CFG8
VDAC8_1_viDAC8__PM_ACT_MSK EQU 0x08
VDAC8_1_viDAC8__PM_STBY_CFG EQU CYREG_PM_STBY_CFG8
VDAC8_1_viDAC8__PM_STBY_MSK EQU 0x08
VDAC8_1_viDAC8__STROBE EQU CYREG_DAC3_STROBE
VDAC8_1_viDAC8__SW0 EQU CYREG_DAC3_SW0
VDAC8_1_viDAC8__SW2 EQU CYREG_DAC3_SW2
VDAC8_1_viDAC8__SW3 EQU CYREG_DAC3_SW3
VDAC8_1_viDAC8__SW4 EQU CYREG_DAC3_SW4
VDAC8_1_viDAC8__TR EQU CYREG_DAC3_TR
VDAC8_1_viDAC8__TRIM__M1 EQU CYREG_FLSHID_CUST_TABLES_DAC3_M1
VDAC8_1_viDAC8__TRIM__M2 EQU CYREG_FLSHID_CUST_TABLES_DAC3_M2
VDAC8_1_viDAC8__TRIM__M3 EQU CYREG_FLSHID_CUST_TABLES_DAC3_M3
VDAC8_1_viDAC8__TRIM__M4 EQU CYREG_FLSHID_CUST_TABLES_DAC3_M4
VDAC8_1_viDAC8__TRIM__M5 EQU CYREG_FLSHID_CUST_TABLES_DAC3_M5
VDAC8_1_viDAC8__TRIM__M6 EQU CYREG_FLSHID_CUST_TABLES_DAC3_M6
VDAC8_1_viDAC8__TRIM__M7 EQU CYREG_FLSHID_CUST_TABLES_DAC3_M7
VDAC8_1_viDAC8__TRIM__M8 EQU CYREG_FLSHID_CUST_TABLES_DAC3_M8
VDAC8_1_viDAC8__TST EQU CYREG_DAC3_TST

; Miscellaneous
BCLK__BUS_CLK__HZ EQU 24000000
BCLK__BUS_CLK__KHZ EQU 24000
BCLK__BUS_CLK__MHZ EQU 24
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PSOC4A EQU 18
CYDEV_CHIP_DIE_PSOC5LP EQU 2
CYDEV_CHIP_DIE_PSOC5TM EQU 3
CYDEV_CHIP_DIE_TMA4 EQU 4
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_FM0P EQU 5
CYDEV_CHIP_FAMILY_FM3 EQU 6
CYDEV_CHIP_FAMILY_FM4 EQU 7
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_PSOC6 EQU 4
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC5
CYDEV_CHIP_JTAG_ID EQU 0x2E123069
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 18
CYDEV_CHIP_MEMBER_4D EQU 13
CYDEV_CHIP_MEMBER_4E EQU 6
CYDEV_CHIP_MEMBER_4F EQU 19
CYDEV_CHIP_MEMBER_4G EQU 4
CYDEV_CHIP_MEMBER_4H EQU 17
CYDEV_CHIP_MEMBER_4I EQU 23
CYDEV_CHIP_MEMBER_4J EQU 14
CYDEV_CHIP_MEMBER_4K EQU 15
CYDEV_CHIP_MEMBER_4L EQU 22
CYDEV_CHIP_MEMBER_4M EQU 21
CYDEV_CHIP_MEMBER_4N EQU 10
CYDEV_CHIP_MEMBER_4O EQU 7
CYDEV_CHIP_MEMBER_4P EQU 20
CYDEV_CHIP_MEMBER_4Q EQU 12
CYDEV_CHIP_MEMBER_4R EQU 8
CYDEV_CHIP_MEMBER_4S EQU 11
CYDEV_CHIP_MEMBER_4T EQU 9
CYDEV_CHIP_MEMBER_4U EQU 5
CYDEV_CHIP_MEMBER_4V EQU 16
CYDEV_CHIP_MEMBER_5A EQU 3
CYDEV_CHIP_MEMBER_5B EQU 2
CYDEV_CHIP_MEMBER_6A EQU 24
CYDEV_CHIP_MEMBER_FM3 EQU 28
CYDEV_CHIP_MEMBER_FM4 EQU 29
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 EQU 25
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 EQU 26
CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 EQU 27
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_5B
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5TM_ES1 EQU 1
CYDEV_CHIP_REV_PSOC5TM_PRODUCTION EQU 1
CYDEV_CHIP_REV_TMA4_ES EQU 17
CYDEV_CHIP_REV_TMA4_ES2 EQU 33
CYDEV_CHIP_REV_TMA4_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD EQU 0
CYDEV_CHIP_REVISION_4E_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256K EQU 0
CYDEV_CHIP_REVISION_4G_ES EQU 17
CYDEV_CHIP_REVISION_4G_ES2 EQU 33
CYDEV_CHIP_REVISION_4G_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4H_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4I_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4J_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4K_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4L_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4M_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4N_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4O_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4P_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4Q_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4R_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4S_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4T_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4U_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4V_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_6A_ES EQU 17
CYDEV_CHIP_REVISION_6A_NO_UDB EQU 33
CYDEV_CHIP_REVISION_6A_PRODUCTION EQU 33
CYDEV_CHIP_REVISION_FM3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_FM4_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_5B_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_FASTBOOT_ENABLED EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_AllowButWarn
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIGURATION_COMPRESSED EQU 0
CYDEV_CONFIGURATION_DMA EQU 1
CYDEV_CONFIGURATION_ECC EQU 1
CYDEV_CONFIGURATION_IMOENABLED EQU CYDEV_CONFIG_FASTBOOT_ENABLED
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_DMA
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_ENABLE_MASK EQU 0x20
CYDEV_DEBUG_ENABLE_REGISTER EQU CYREG_MLOGIC_DEBUG
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_JTAG_4 EQU 1
CYDEV_DEBUGGING_DPS_JTAG_5 EQU 0
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS_SWD_SWV EQU 6
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD_SWV
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DEBUGGING_XRES EQU 0
CYDEV_DMA_CHANNELS_AVAILABLE EQU 24
CYDEV_ECC_ENABLE EQU 0
CYDEV_HEAP_SIZE EQU 0x80
CYDEV_INSTRUCT_CACHE_ENABLED EQU 0
CYDEV_INTR_RISING EQU 0x00000000
CYDEV_IS_EXPORTING_CODE EQU 0
CYDEV_IS_IMPORTING_CODE EQU 0
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LAUNCHER EQU 5
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER EQU 4
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_PROTECTION_ENABLE EQU 0
CYDEV_STACK_SIZE EQU 0x0800
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 0
CYDEV_VDDA_MV EQU 5000
CYDEV_VDDD_MV EQU 5000
CYDEV_VDDIO0_MV EQU 5000
CYDEV_VDDIO1_MV EQU 5000
CYDEV_VDDIO2_MV EQU 5000
CYDEV_VDDIO3_MV EQU 5000
CYDEV_VIO0_MV EQU 5000
CYDEV_VIO1_MV EQU 5000
CYDEV_VIO2_MV EQU 5000
CYDEV_VIO3_MV EQU 5000
CYIPBLOCK_ARM_CM3_VERSION EQU 0
CYIPBLOCK_P3_ANAIF_VERSION EQU 0
CYIPBLOCK_P3_CAN_VERSION EQU 0
CYIPBLOCK_P3_CAPSENSE_VERSION EQU 0
CYIPBLOCK_P3_COMP_VERSION EQU 0
CYIPBLOCK_P3_DECIMATOR_VERSION EQU 0
CYIPBLOCK_P3_DFB_VERSION EQU 0
CYIPBLOCK_P3_DMA_VERSION EQU 0
CYIPBLOCK_P3_DRQ_VERSION EQU 0
CYIPBLOCK_P3_DSM_VERSION EQU 0
CYIPBLOCK_P3_EMIF_VERSION EQU 0
CYIPBLOCK_P3_I2C_VERSION EQU 0
CYIPBLOCK_P3_LCD_VERSION EQU 0
CYIPBLOCK_P3_LPF_VERSION EQU 0
CYIPBLOCK_P3_OPAMP_VERSION EQU 0
CYIPBLOCK_P3_PM_VERSION EQU 0
CYIPBLOCK_P3_SCCT_VERSION EQU 0
CYIPBLOCK_P3_TIMER_VERSION EQU 0
CYIPBLOCK_P3_USB_VERSION EQU 0
CYIPBLOCK_P3_VIDAC_VERSION EQU 0
CYIPBLOCK_P3_VREF_VERSION EQU 0
CYIPBLOCK_S8_GPIO_VERSION EQU 0
CYIPBLOCK_S8_IRQ_VERSION EQU 0
CYIPBLOCK_S8_SAR_VERSION EQU 0
CYIPBLOCK_S8_SIO_VERSION EQU 0
CYIPBLOCK_S8_UDB_VERSION EQU 0
DMA_CHANNELS_USED__MASK0 EQU 0x00000000
CYDEV_BOOTLOADER_ENABLE EQU 0
    ENDIF
    END