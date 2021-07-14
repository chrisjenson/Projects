// ======================================================================
// tcom_displ_test_psoc6.v generated from TopDesign.cysch
// 04/30/2021 at 15:09
// This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
// ======================================================================

`define CYDEV_CHIP_FAMILY_PSOC3 1
`define CYDEV_CHIP_FAMILY_PSOC4 2
`define CYDEV_CHIP_FAMILY_PSOC5 3
`define CYDEV_CHIP_FAMILY_PSOC6 4
`define CYDEV_CHIP_FAMILY_FM0P 5
`define CYDEV_CHIP_FAMILY_FM3 6
`define CYDEV_CHIP_FAMILY_FM4 7
`define CYDEV_CHIP_FAMILY_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_3A 1
`define CYDEV_CHIP_REVISION_3A_PRODUCTION 3
`define CYDEV_CHIP_REVISION_3A_ES3 3
`define CYDEV_CHIP_REVISION_3A_ES2 1
`define CYDEV_CHIP_REVISION_3A_ES1 0
`define CYDEV_CHIP_MEMBER_5B 2
`define CYDEV_CHIP_REVISION_5B_PRODUCTION 0
`define CYDEV_CHIP_REVISION_5B_ES0 0
`define CYDEV_CHIP_MEMBER_5A 3
`define CYDEV_CHIP_REVISION_5A_PRODUCTION 1
`define CYDEV_CHIP_REVISION_5A_ES1 1
`define CYDEV_CHIP_REVISION_5A_ES0 0
`define CYDEV_CHIP_MEMBER_4G 4
`define CYDEV_CHIP_REVISION_4G_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4G_ES 17
`define CYDEV_CHIP_REVISION_4G_ES2 33
`define CYDEV_CHIP_MEMBER_4U 5
`define CYDEV_CHIP_REVISION_4U_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4E 6
`define CYDEV_CHIP_REVISION_4E_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD 0
`define CYDEV_CHIP_MEMBER_4X 7
`define CYDEV_CHIP_REVISION_4X_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4O 8
`define CYDEV_CHIP_REVISION_4O_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4R 9
`define CYDEV_CHIP_REVISION_4R_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4T 10
`define CYDEV_CHIP_REVISION_4T_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4N 11
`define CYDEV_CHIP_REVISION_4N_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4S 12
`define CYDEV_CHIP_REVISION_4S_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4W 13
`define CYDEV_CHIP_REVISION_4W_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4AC 14
`define CYDEV_CHIP_REVISION_4AC_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Q 15
`define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Y 16
`define CYDEV_CHIP_REVISION_4Y_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Z 17
`define CYDEV_CHIP_REVISION_4Z_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4D 18
`define CYDEV_CHIP_REVISION_4D_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4J 19
`define CYDEV_CHIP_REVISION_4J_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4K 20
`define CYDEV_CHIP_REVISION_4K_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4V 21
`define CYDEV_CHIP_REVISION_4V_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4H 22
`define CYDEV_CHIP_REVISION_4H_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4AA 23
`define CYDEV_CHIP_REVISION_4AA_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4A 24
`define CYDEV_CHIP_REVISION_4A_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4A_ES0 17
`define CYDEV_CHIP_MEMBER_4F 25
`define CYDEV_CHIP_REVISION_4F_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0
`define CYDEV_CHIP_MEMBER_4P 26
`define CYDEV_CHIP_REVISION_4P_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4M 27
`define CYDEV_CHIP_REVISION_4M_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4AB 28
`define CYDEV_CHIP_REVISION_4AB_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4L 29
`define CYDEV_CHIP_REVISION_4L_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4I 30
`define CYDEV_CHIP_REVISION_4I_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_6A 31
`define CYDEV_CHIP_REVISION_6A_ES 17
`define CYDEV_CHIP_REVISION_6A_PRODUCTION 33
`define CYDEV_CHIP_REVISION_6A_NO_UDB 33
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 32
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 33
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 34
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM3 35
`define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM4 36
`define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0
`define CYDEV_CHIP_FAMILY_USED 4
`define CYDEV_CHIP_MEMBER_USED 31
`define CYDEV_CHIP_REVISION_USED 33
// Component: GraphicLCDIntf_v1_80
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\GraphicLCDIntf_v1_80"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\GraphicLCDIntf_v1_80\GraphicLCDIntf_v1_80.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\GraphicLCDIntf_v1_80"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\GraphicLCDIntf_v1_80\GraphicLCDIntf_v1_80.v"
`endif

// TCPWM_Counter_PDL_v1_0(CaptureInput=7, CaptureInputMasked=3, ClockPrescaler=0, Compare0=16384, Compare1=16384, CompareOrCapture=2, CountDirection=1, CountInput=7, CountInputMasked=3, EnableCompareSwap=false, InterruptSource=1, Period=999, ReloadInput=7, ReloadInputMasked=3, Resolution=16, RunMode=0, StartInput=7, StartInputMasked=3, StopInput=7, StopInputMasked=3, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=TCPWM_Counter_PDL_v1_0, CY_CONFIG_TITLE=DISP_TICK_TIMER, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=DISP_TICK_TIMER, CY_INSTANCE_SHORT_NAME=DISP_TICK_TIMER, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=tcpwm, CY_PDL_DRIVER_REQ_VERSION=1.0.0, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.3, INSTANCE_NAME=DISP_TICK_TIMER, )
module TCPWM_Counter_PDL_v1_0_0 (
    stop,
    reload,
    start,
    count,
    capture,
    interrupt,
    ovrflw,
    undrflw,
    compare,
    clock);
    input       stop;
    input       reload;
    input       start;
    input       count;
    input       capture;
    output      interrupt;
    output      ovrflw;
    output      undrflw;
    output      compare;
    input       clock;


          wire  Net_2;
          wire  Net_1;

    cy_mxs40_tcpwm_v1_0 TCPWM (
        .clock(clock),
        .capture(capture),
        .count(count),
        .reload(reload),
        .stop(stop),
        .start(start),
        .tr_underflow(undrflw),
        .tr_compare_match(compare),
        .tr_overflow(ovrflw),
        .line_compl(Net_1),
        .line(Net_2),
        .interrupt(interrupt));
    defparam TCPWM.exact_width = 0;
    defparam TCPWM.width = 16;



endmodule

// Component: or_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\or_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\or_v1_0\or_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\or_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\or_v1_0\or_v1_0.v"
`endif

// Component: ZeroTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`endif

// Component: cy_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`endif

// SCB_I2C_PDL_v2_0(AcceptAddress=false, AcceptGeneralCall=false, ClkDesFrequency=1550, ClkMinusTolerance=5, ClkPlusTolerance=206.451612903226, ClockFromTerm=false, DataRate=100, DeepSleepCapable=false, EnableManualSclControl=false, EnableRxFifo=true, EnableSclAccess=false, EnableTxFifo=true, EnableWakeup=false, HighPhaseDutyCycle=10, I2cMode=0, IsEnableRxFifoVisible=true, IsMasterEnabled=true, IsSlaveVisible=false, LowPhaseDutyCycle=10, Mode=2, ShowTerminals=true, SlaveAddress=8, SlaveAddressMask=254, SymbolShape=0, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=SCB_I2C_PDL_v2_0, CY_CONFIG_TITLE=I2C_MASTER, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=I2C_MASTER, CY_INSTANCE_SHORT_NAME=I2C_MASTER, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=scb, CY_PDL_DRIVER_REQ_VERSION=2.0.0, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.3, INSTANCE_NAME=I2C_MASTER, )
module SCB_I2C_PDL_v2_0_1 (
    clock,
    scl_b,
    sda_b,
    scl_trig);
    input       clock;
    inout       scl_b;
    inout       sda_b;
    output      scl_trig;


          wire  clock_wire;
          wire  Net_222;
          wire  Net_224;
          wire  Net_223;
          wire  Net_163;
          wire  Net_162;
          wire  Net_1055;
          wire  Net_1061;
          wire [3:0] Net_87;
          wire  Net_1059;
          wire  intr_wire;
          wire  Net_277;
          wire  Net_1053;
          wire  Net_1062;
          wire  Net_278;
          wire  Net_279;
          wire  Net_280;
          wire  Net_281;
          wire  Net_282;
          wire  Net_283;
          wire  Net_847;

    cy_mxs40_scb_v1_10 SCB (
        .clock(clock_wire),
        .uart_rx(Net_283),
        .uart_cts(Net_282),
        .i2c_scl(scl_b),
        .i2c_sda(sda_b),
        .spi_clk_s(Net_281),
        .spi_select_s(Net_280),
        .spi_miso_m(Net_279),
        .spi_mosi_s(Net_278),
        .uart_tx(Net_1062),
        .uart_rts(Net_1053),
        .uart_tx_en(Net_277),
        .spi_clk_m(Net_1059),
        .spi_select_m(Net_87[3:0]),
        .spi_mosi_m(Net_1061),
        .spi_miso_s(Net_1055),
        .interrupt(intr_wire),
        .tr_tx_req(Net_162),
        .tr_rx_req(Net_163),
        .tr_i2c_scl_filtered(scl_trig));
    defparam SCB.master = 1;
    defparam SCB.mode = 0;
    defparam SCB.requires_io_preconfigure = 1;


    assign Net_224 = Net_223 | Net_847;

    ZeroTerminal ZeroTerminal_7 (
        .z(Net_223));

	// clock_VM (cy_virtualmux_v1_0)
	assign clock_wire = Net_847;

    ZeroTerminal ZeroTerminal_6 (
        .z(Net_278));

    ZeroTerminal ZeroTerminal_5 (
        .z(Net_279));

    ZeroTerminal ZeroTerminal_4 (
        .z(Net_280));

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_281));

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_282));

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_283));


	cy_mxs40_isr_v1_0
		#(.deepsleep_required(0),
		  .int_type(2'b10))
		SCB_IRQ
		 (.int_signal(intr_wire));



	cy_clock_v1_0
		#(.id("a6ace5f1-56ad-4e7a-8ea6-227fa37dbd84/b68e5b9d-7828-482d-a282-930f990e3b3e"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("645161290.322581"),
		  .is_direct(0),
		  .is_digital(0))
		SCBCLK
		 (.clock_out(Net_847));




endmodule

// SCB_SPI_PDL_v2_0(BitsOrder=1, BufferMinSize=64, ByteMode=false, ClkDesFrequency=40000, ClkMinusTolerance=100, ClkPlusTolerance=5, ClockFromTerm=false, DataRate=10000, DeassertSelectLine=false, DeepSleepCapable=false, EnableFreeRunSclk=false, EnableInputFilter=false, EnableInterruptTerm=true, EnableLateMisoSample=false, EnableRxOutput=false, EnableSpimMisoTerm=true, EnableSpimMosiTerm=true, EnableSpimSclkTerm=true, EnableSpimSs0Term=true, EnableSpimSs1Term=false, EnableSpimSs2Term=false, EnableSpimSs3Term=false, EnableSpisMisoTerm=false, EnableSpisMosiTerm=false, EnableSpisSclkTerm=false, EnableSpisSsTerm=false, EnableTriggerOutput=false, EnableTxOutput=false, EnableWakeup=false, InterruptMode=2, IntrMasterSlaveMask=0, IntrMasterSpiDone=false, IntrRxFull=false, IntrRxMask=0, IntrRxNotEmpty=false, IntrRxOverflow=false, IntrRxTrigger=false, IntrRxUnderflow=false, IntrSlaveBusError=false, IntrTxEmpty=false, IntrTxMask=0, IntrTxNotFull=false, IntrTxOverflow=false, IntrTxTrigger=false, IntrTxUnderflow=false, IsDmaCapable=true, IsEnableWakeupVisible=false, IsMasterEnabled=true, IsRxTriggerLevelVisible=false, IsTxTriggerLevelVisible=false, MasterMode=true, MaxFifoLevel=63, MinOvsFactor=4, Mode=1, OvsFactor=4, RemoveIntr=true, RemoveMasterMiso=true, RemoveMasterMosi=true, RemoveMasterSclk=true, RemoveMasterSs0Pin=true, RemoveMasterSs1Pin=true, RemoveMasterSs2Pin=true, RemoveMasterSs3Pin=true, RemoveMiso=false, RemoveMosi=false, RemoveSclk=false, RemoveSlaveMiso=true, RemoveSlaveMosi=true, RemoveSlaveSclk=true, RemoveSlaveSS=true, RxDataWidth=16, RxTriggerLevel=63, SclkMode=3, SelectLinesNumber=1, ShowTerminals=true, SpiMode=1, Ss0Polarity=0, Ss1Polarity=0, Ss2Polarity=0, Ss3Polarity=0, SubMode=0, SymbolShape=3, TxDataWidth=16, TxTriggerLevel=63, UseIntr=false, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=SCB_SPI_PDL_v2_0, CY_CONFIG_TITLE=SPIM, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=SPIM, CY_INSTANCE_SHORT_NAME=SPIM, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=scb, CY_PDL_DRIVER_REQ_VERSION=2.0.0, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.3, INSTANCE_NAME=SPIM, )
module SCB_SPI_PDL_v2_0_2 (
    interrupt,
    clock,
    rx_dma,
    tx_dma,
    s_mosi,
    s_sclk,
    s_ss,
    m_miso,
    m_mosi,
    m_sclk,
    m_ss0,
    m_ss1,
    m_ss2,
    m_ss3,
    s_miso);
    output      interrupt;
    input       clock;
    output      rx_dma;
    output      tx_dma;
    input       s_mosi;
    input       s_sclk;
    input       s_ss;
    input       m_miso;
    output      m_mosi;
    output      m_sclk;
    output      m_ss0;
    output      m_ss1;
    output      m_ss2;
    output      m_ss3;
    output      s_miso;


          wire  mosi_s_wire;
          wire  clock_wire;
          wire  intr_wire;
          wire  mosi_m_wire;
          wire  sclk_m_wire;
          wire  miso_m_wire;
          wire  miso_s_wire;
          wire [3:0] select_m_wire;
          wire  sclk_s_wire;
          wire  select_s_wire;
          wire  Net_498;
          wire  Net_490;
          wire  Net_489;
          wire  Net_488;
          wire  Net_483;
          wire  Net_482;
          wire  Net_481;
          wire  Net_480;
          wire  Net_29;
          wire  Net_28;
          wire  Net_228;
          wire  Net_227;
          wire  Net_218;
          wire  Net_216;
          wire  Net_138;
          wire  Net_847;


	cy_clock_v1_0
		#(.id("84d45b05-d23b-4fcd-98cb-414e3a04b3eb/b68e5b9d-7828-482d-a282-930f990e3b3e"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("25000000"),
		  .is_direct(0),
		  .is_digital(0))
		SCBCLK
		 (.clock_out(Net_847));


	// clock_VM (cy_virtualmux_v1_0)
	assign clock_wire = Net_847;

    ZeroTerminal ZeroTerminal_7 (
        .z(Net_28));


    assign Net_29 = Net_28 | Net_847;

    cy_mxs40_scb_v1_10 SCB (
        .clock(clock_wire),
        .uart_rx(1'b0),
        .uart_cts(1'b0),
        .i2c_scl(Net_482),
        .i2c_sda(Net_483),
        .spi_clk_s(sclk_s_wire),
        .spi_select_s(select_s_wire),
        .spi_miso_m(miso_m_wire),
        .spi_mosi_s(mosi_s_wire),
        .uart_tx(Net_488),
        .uart_rts(Net_489),
        .uart_tx_en(Net_490),
        .spi_clk_m(sclk_m_wire),
        .spi_select_m(select_m_wire[3:0]),
        .spi_mosi_m(mosi_m_wire),
        .spi_miso_s(miso_s_wire),
        .interrupt(intr_wire),
        .tr_tx_req(tx_dma),
        .tr_rx_req(rx_dma),
        .tr_i2c_scl_filtered(Net_498));
    defparam SCB.master = 1;
    defparam SCB.mode = 1;
    defparam SCB.requires_io_preconfigure = 0;

	// select_s_VM (cy_virtualmux_v1_0)
	assign select_s_wire = s_ss;

	// sclk_s_VM (cy_virtualmux_v1_0)
	assign sclk_s_wire = s_sclk;

	// mosi_s_VM (cy_virtualmux_v1_0)
	assign mosi_s_wire = s_mosi;

	// miso_m_VM (cy_virtualmux_v1_0)
	assign miso_m_wire = m_miso;


    assign interrupt = intr_wire;

    assign m_mosi = mosi_m_wire;

    assign m_sclk = sclk_m_wire;

    assign m_ss0 = select_m_wire[0];

    assign m_ss1 = select_m_wire[1];

    assign m_ss2 = select_m_wire[2];

    assign m_ss3 = select_m_wire[3];

    assign s_miso = miso_s_wire;


endmodule

// top
module top ;

          wire  Net_100;
          wire  Net_99;
          wire  Net_98;
          wire  Net_97;
          wire  Net_96;
          wire  Net_95;
          wire  Net_94;
          wire  Net_93;
          wire  Net_92;
          wire  Net_91;
          wire  Net_90;
          wire  Net_89;
          wire  Net_88;
          wire  Net_145;
          wire  Net_85;
          wire  Net_58;
          wire  Net_47;
          wire  Net_44;
          wire  Net_42;
          wire  Net_41;
          wire  Net_40;
          wire  Net_38;
          wire  Net_37;
          wire  Net_36;
          wire  Net_35;
          wire  Net_34;
          wire  Net_33;
          wire [7:0] Net_3;
          wire  Net_2;
          wire [7:0] Net_1;
          wire  Net_80;
          wire  Net_79;
          wire  Net_54;
          wire  Net_43;
          wire  Net_131;
          wire  Net_130;
          wire  Net_129;
          wire  Net_132;
          wire  Net_127;
          wire [7:0] Net_133;
          wire [7:0] Net_86;

    GraphicLCDIntf_v1_80 LCD_INTERFACE (
        .di_lsb(Net_133[7:0]),
        .di_msb(8'b0),
        .clock(Net_2),
        .do_lsb(Net_86[7:0]),
        .do_msb(Net_3[7:0]),
        .oe(Net_127),
        .d_c(Net_132),
        .ncs(Net_129),
        .nwr(Net_130),
        .nrd(Net_131));
    defparam LCD_INTERFACE.BitWidth = 8;
    defparam LCD_INTERFACE.ReadHiPulse = 5;
    defparam LCD_INTERFACE.ReadLoPulse = 18;

	wire [7:0] tmpIO_7__d_net;
	electrical [0:0] tmpSIOVREF__d_net;

	cy_mxs40_gpio_v1_0
		#(.id("a61270bc-07ec-447d-ac9e-34cfe85c30e9"),
		  .width(8),
		  .sio_grp_cnt(0),
		  .drive_mode("6,6,6,6,6,6,6,6"),
		  .ibuf_enabled("1,1,1,1,1,1,1,1"),
		  .init_dr_st("1,1,1,1,1,1,1,1"),
		  .input_sync("0,0,0,0,0,0,0,0"),
		  .intr_mode("0,0,0,0,0,0,0,0"),
		  .io_voltage(",,,,,,,"),
		  .output_conn("1,1,1,1,1,1,1,1"),
		  .oe_conn("1,1,1,1,1,1,1,1"),
		  .output_sync("0,0,0,0,0,0,0,0"),
		  .oe_sync("0,0,0,0,0,0,0,0"),
		  .drive_strength("0,0,0,0,0,0,0,0"),
		  .max_frequency("100,100,100,100,100,100,100,100"),
		  .i2c_mode("0,0,0,0,0,0,0,0"),
		  .output_current_cap("8,8,8,8,8,8,8,8"),
		  .pin_aliases(",,,,,,,"),
		  .pin_mode("IO,IO,IO,IO,IO,IO,IO,IO"),
		  .slew_rate("0,0,0,0,0,0,0,0"),
		  .vtrip("0,0,0,0,0,0,0,0"),
		  .use_annotation("0,0,0,0,0,0,0,0"),
		  .hotswap_needed("0,0,0,0,0,0,0,0"))
		d
		 (.oe({Net_127, Net_127, Net_127, Net_127, Net_127, Net_127, Net_127, Net_127}),
		  .y({Net_86[7:0]}),
		  .fb({Net_133[7:0]}),
		  .io({tmpIO_7__d_net[7:0]}),
		  .siovref(tmpSIOVREF__d_net));


	wire [0:0] tmpFB_0__d_c_net;
	wire [0:0] tmpIO_0__d_c_net;
	electrical [0:0] tmpSIOVREF__d_c_net;

	cy_mxs40_gpio_v1_0
		#(.id("5f722662-09eb-484c-8282-7daba1a78235"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("6"),
		  .ibuf_enabled("0"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("1"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		d_c
		 (.oe({1'b1}),
		  .y({Net_132}),
		  .fb({tmpFB_0__d_c_net[0:0]}),
		  .io({tmpIO_0__d_c_net[0:0]}),
		  .siovref(tmpSIOVREF__d_c_net));



	cy_clock_v1_0
		#(.id("bb212b48-3568-49e1-9d8b-2b947d970fae"),
		  .source_clock_id("2FB4EC85-8328-4C5A-9ED9-8B63060178EB"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(0))
		CLOCK_3
		 (.clock_out(Net_2));


	wire [0:0] tmpFB_0__ncs_net;
	wire [0:0] tmpIO_0__ncs_net;
	electrical [0:0] tmpSIOVREF__ncs_net;

	cy_mxs40_gpio_v1_0
		#(.id("f752c72a-0226-4ca8-ab2f-39272ef36684"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("6"),
		  .ibuf_enabled("0"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("1"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		ncs
		 (.oe({1'b1}),
		  .y({Net_129}),
		  .fb({tmpFB_0__ncs_net[0:0]}),
		  .io({tmpIO_0__ncs_net[0:0]}),
		  .siovref(tmpSIOVREF__ncs_net));


	wire [0:0] tmpFB_0__nwr_net;
	wire [0:0] tmpIO_0__nwr_net;
	electrical [0:0] tmpSIOVREF__nwr_net;

	cy_mxs40_gpio_v1_0
		#(.id("0f29494a-c63e-4158-a298-0050fca8ff03"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("6"),
		  .ibuf_enabled("0"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("1"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		nwr
		 (.oe({1'b1}),
		  .y({Net_130}),
		  .fb({tmpFB_0__nwr_net[0:0]}),
		  .io({tmpIO_0__nwr_net[0:0]}),
		  .siovref(tmpSIOVREF__nwr_net));


	wire [0:0] tmpFB_0__nrd_net;
	wire [0:0] tmpIO_0__nrd_net;
	electrical [0:0] tmpSIOVREF__nrd_net;

	cy_mxs40_gpio_v1_0
		#(.id("0654abd4-8013-44c2-931a-887ce094a48a"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("6"),
		  .ibuf_enabled("0"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("1"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		nrd
		 (.oe({1'b1}),
		  .y({Net_131}),
		  .fb({tmpFB_0__nrd_net[0:0]}),
		  .io({tmpIO_0__nrd_net[0:0]}),
		  .siovref(tmpSIOVREF__nrd_net));


	wire [0:0] tmpFB_0__PORT6_PIN2_net;
	wire [0:0] tmpIO_0__PORT6_PIN2_net;
	electrical [0:0] tmpSIOVREF__PORT6_PIN2_net;

	cy_mxs40_gpio_v1_0
		#(.id("c9b124f9-4cf0-4d22-8113-96929508aa62"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("6"),
		  .ibuf_enabled("0"),
		  .init_dr_st("0"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		PORT6_PIN2
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__PORT6_PIN2_net[0:0]}),
		  .io({tmpIO_0__PORT6_PIN2_net[0:0]}),
		  .siovref(tmpSIOVREF__PORT6_PIN2_net));


    TCPWM_Counter_PDL_v1_0_0 DISP_TICK_TIMER (
        .stop(1'b0),
        .reload(1'b0),
        .start(1'b0),
        .count(1'b1),
        .capture(1'b0),
        .interrupt(Net_54),
        .ovrflw(Net_40),
        .undrflw(Net_41),
        .compare(Net_42),
        .clock(Net_43));

    SCB_I2C_PDL_v2_0_1 I2C_MASTER (
        .clock(1'b0),
        .scl_b(Net_79),
        .sda_b(Net_80),
        .scl_trig(Net_47));


	cy_clock_v1_0
		#(.id("a2855aba-c831-4349-b81c-292cb29f4479"),
		  .source_clock_id("2FB4EC85-8328-4C5A-9ED9-8B63060178EB"),
		  .divisor(0),
		  .period("1000000000"),
		  .is_direct(0),
		  .is_digital(0))
		CLOCK_2
		 (.clock_out(Net_43));



	cy_mxs40_isr_v1_0
		#(.deepsleep_required(0),
		  .int_type(2'b10))
		DISP_TICK_ISR
		 (.int_signal(Net_54));


	wire [0:0] tmpFB_0__PORT9_PIN1_net;
	electrical [0:0] tmpSIOVREF__PORT9_PIN1_net;

	cy_mxs40_gpio_v1_0
		#(.id("570396df-2eb9-4462-a5fc-f70f005f8fa3"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("2"),
		  .ibuf_enabled("1"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("B"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		PORT9_PIN1
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__PORT9_PIN1_net[0:0]}),
		  .io({Net_80}),
		  .siovref(tmpSIOVREF__PORT9_PIN1_net));


	wire [0:0] tmpFB_0__PORT9_PIN0_net;
	electrical [0:0] tmpSIOVREF__PORT9_PIN0_net;

	cy_mxs40_gpio_v1_0
		#(.id("4cca878b-77b5-471d-8aeb-ad6925202455"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("2"),
		  .ibuf_enabled("1"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("B"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		PORT9_PIN0
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__PORT9_PIN0_net[0:0]}),
		  .io({Net_79}),
		  .siovref(tmpSIOVREF__PORT9_PIN0_net));


    SCB_SPI_PDL_v2_0_2 SPIM (
        .interrupt(Net_85),
        .clock(1'b0),
        .rx_dma(Net_88),
        .tx_dma(Net_89),
        .s_mosi(1'b0),
        .s_sclk(1'b0),
        .s_ss(1'b0),
        .m_miso(Net_93),
        .m_mosi(Net_94),
        .m_sclk(Net_95),
        .m_ss0(Net_96),
        .m_ss1(Net_97),
        .m_ss2(Net_98),
        .m_ss3(Net_99),
        .s_miso(Net_100));

	wire [0:0] tmpFB_0__SPI_MOSI_net;
	wire [0:0] tmpIO_0__SPI_MOSI_net;
	electrical [0:0] tmpSIOVREF__SPI_MOSI_net;

	cy_mxs40_gpio_v1_0
		#(.id("16190a5f-8d93-4c48-9172-c4d1dae3c0f1"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("6"),
		  .ibuf_enabled("0"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("1"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		SPI_MOSI
		 (.oe({1'b1}),
		  .y({Net_94}),
		  .fb({tmpFB_0__SPI_MOSI_net[0:0]}),
		  .io({tmpIO_0__SPI_MOSI_net[0:0]}),
		  .siovref(tmpSIOVREF__SPI_MOSI_net));


	wire [0:0] tmpFB_0__SPI_CLK_net;
	wire [0:0] tmpIO_0__SPI_CLK_net;
	electrical [0:0] tmpSIOVREF__SPI_CLK_net;

	cy_mxs40_gpio_v1_0
		#(.id("2e5db35c-9902-4642-bb12-ce29fe6b5ef9"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("6"),
		  .ibuf_enabled("0"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("1"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		SPI_CLK
		 (.oe({1'b1}),
		  .y({Net_95}),
		  .fb({tmpFB_0__SPI_CLK_net[0:0]}),
		  .io({tmpIO_0__SPI_CLK_net[0:0]}),
		  .siovref(tmpSIOVREF__SPI_CLK_net));


	wire [0:0] tmpFB_0__SPI_Sel_net;
	wire [0:0] tmpIO_0__SPI_Sel_net;
	electrical [0:0] tmpSIOVREF__SPI_Sel_net;

	cy_mxs40_gpio_v1_0
		#(.id("ab058973-8609-4279-ab29-1256c31b0dd3"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("6"),
		  .ibuf_enabled("0"),
		  .init_dr_st("1"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("1"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		SPI_Sel
		 (.oe({1'b1}),
		  .y({Net_96}),
		  .fb({tmpFB_0__SPI_Sel_net[0:0]}),
		  .io({tmpIO_0__SPI_Sel_net[0:0]}),
		  .siovref(tmpSIOVREF__SPI_Sel_net));


	wire [0:0] tmpIO_0__SPI_MISO_net;
	electrical [0:0] tmpSIOVREF__SPI_MISO_net;

	cy_mxs40_gpio_v1_0
		#(.id("546dcbdd-bda1-470b-9a98-28fbf3e704d3"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("0"),
		  .ibuf_enabled("1"),
		  .init_dr_st("0"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		SPI_MISO
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({Net_93}),
		  .io({tmpIO_0__SPI_MISO_net[0:0]}),
		  .siovref(tmpSIOVREF__SPI_MISO_net));


	wire [0:0] tmpFB_0__SEL_PIN_net;
	wire [0:0] tmpIO_0__SEL_PIN_net;
	electrical [0:0] tmpSIOVREF__SEL_PIN_net;

	cy_mxs40_gpio_v1_0
		#(.id("9dccffa9-0f96-4336-8d9b-23c06d4df85c"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("6"),
		  .ibuf_enabled("0"),
		  .init_dr_st("0"),
		  .input_sync("0"),
		  .intr_mode("0"),
		  .io_voltage(""),
		  .output_conn("0"),
		  .oe_conn("0"),
		  .output_sync("0"),
		  .oe_sync("0"),
		  .drive_strength("0"),
		  .max_frequency("100"),
		  .i2c_mode("0"),
		  .output_current_cap("8"),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		SEL_PIN
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__SEL_PIN_net[0:0]}),
		  .io({tmpIO_0__SEL_PIN_net[0:0]}),
		  .siovref(tmpSIOVREF__SEL_PIN_net));




endmodule

