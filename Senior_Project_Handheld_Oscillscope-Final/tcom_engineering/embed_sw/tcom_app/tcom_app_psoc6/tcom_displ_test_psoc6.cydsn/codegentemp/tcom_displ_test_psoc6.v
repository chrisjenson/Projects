// ======================================================================
// tcom_displ_test_psoc6.v generated from TopDesign.cysch
// 09/16/2020 at 12:55
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
`define CY_BLK_DIR "E:\Applications\PSOC\PSoC Creator\4.3\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\GraphicLCDIntf_v1_80"
`include "E:\Applications\PSOC\PSoC Creator\4.3\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\GraphicLCDIntf_v1_80\GraphicLCDIntf_v1_80.v"
`else
`define CY_BLK_DIR "E:\Applications\PSOC\PSoC Creator\4.3\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\GraphicLCDIntf_v1_80"
`include "E:\Applications\PSOC\PSoC Creator\4.3\PSoC Creator\psoc\content\CyComponentLibrary\CyComponentLibrary.cylib\GraphicLCDIntf_v1_80\GraphicLCDIntf_v1_80.v"
`endif

// TCPWM_Counter_PDL_v1_0(CaptureInput=7, CaptureInputMasked=3, ClockPrescaler=0, Compare0=16384, Compare1=16384, CompareOrCapture=2, CountDirection=0, CountInput=7, CountInputMasked=3, EnableCompareSwap=false, InterruptSource=0, Period=1000, ReloadInput=7, ReloadInputMasked=3, Resolution=16, RunMode=0, StartInput=7, StartInputMasked=3, StopInput=7, StopInputMasked=3, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=TCPWM_Counter_PDL_v1_0, CY_CONFIG_TITLE=DISP_TICK_TIMER, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=DISP_TICK_TIMER, CY_INSTANCE_SHORT_NAME=DISP_TICK_TIMER, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=tcpwm, CY_PDL_DRIVER_REQ_VERSION=1.0.0, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.3, INSTANCE_NAME=DISP_TICK_TIMER, )
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
`define CY_BLK_DIR "E:\Applications\PSOC\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\or_v1_0"
`include "E:\Applications\PSOC\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\or_v1_0\or_v1_0.v"
`else
`define CY_BLK_DIR "E:\Applications\PSOC\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\or_v1_0"
`include "E:\Applications\PSOC\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\or_v1_0\or_v1_0.v"
`endif

// Component: ZeroTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "E:\Applications\PSOC\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal"
`include "E:\Applications\PSOC\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`else
`define CY_BLK_DIR "E:\Applications\PSOC\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal"
`include "E:\Applications\PSOC\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`endif

// Component: cy_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "E:\Applications\PSOC\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0"
`include "E:\Applications\PSOC\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "E:\Applications\PSOC\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0"
`include "E:\Applications\PSOC\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
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

// SCB_UART_PDL_v2_0(BaudRate=9600, BitsOrder=0, BreakSignalBits=11, BufferMinSize=64, ByteMode=true, ClkFreqDes=115.2, ClkMinusTolerance=5, ClkPlusTolerance=5, ClockFromTerm=false, ComMode=0, CtsPolarity=0, CtsTermEnable=false, DataWidth=8, Direction=2, DropOnFrameErr=false, DropOnParityErr=false, EnableCts=false, EnableInputFilter=false, EnableMultiProc=false, EnableRts=false, EnableRxOutput=false, EnableTxEn=false, EnableTxOutput=false, InterruptMode=1, InterruptTermEnable=false, IntrRxBreakDetected=false, IntrRxFrameErr=false, IntrRxFull=false, IntrRxNotEmpty=false, IntrRxOverflow=false, IntrRxParityErr=false, IntrRxTrigger=false, IntrRxUnderflow=false, IntrTxEmpty=false, IntrTxNotFull=false, IntrTxOverflow=false, IntrTxTrigger=false, IntrTxUartDone=false, IntrTxUartLostArb=false, IntrTxUartNack=false, IntrTxUnderflow=false, IrdaLowPower=false, IrdaPolarity=0, IsCtsPinAllowed=true, IsDmaCapable=true, IsEnableInputFilterVisible=false, IsMultiprocessorModeAvailable=false, IsRtsPinAllowed=false, IsRtsTriggerLevelVisible=false, IsRxIntrSourcesVisible=false, IsRxTriggerLevelVisible=false, IsTxIntrSourcesVisible=false, IsTxTriggerLevelVisible=false, MaxFifoLevel=127, MpRxAcceptAddress=false, MpRxAddress=0, MpRxAddressMask=255, OvsFactor=12, ParityType=0, PreconfigureIO=false, RemoveCtsPin=true, RemoveIntr=false, RemoveRtsPin=true, RemoveRxPin=true, RemoveRxTxPin=true, RemoveTxEnPin=true, RemoveTxPin=true, RtsPolarity=0, RtsTermEnable=false, RtsTriggerLevel=63, RxIntrMask=0, RxTermEnable=false, RxTriggerLevel=63, RxTxTermEnable=false, ShowTerminals=true, SmCardRetryOnNack=false, StopBits=2, SymbolShape=2, TriggerOutputEnable=false, TxEnTermEnable=false, TxIntrMask=0, TxTermEnable=true, TxTriggerLevel=63, UartMode=2, UseIntr=true, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=SCB_UART_PDL_v2_0, CY_CONFIG_TITLE=UART_KITPROG_USB, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=UART_KITPROG_USB, CY_INSTANCE_SHORT_NAME=UART_KITPROG_USB, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=scb, CY_PDL_DRIVER_REQ_VERSION=2.0.0, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.3, INSTANCE_NAME=UART_KITPROG_USB, )
module SCB_UART_PDL_v2_0_2 (
    cts_in,
    tx_out,
    rts_out,
    interrupt,
    clock,
    rx_dma,
    tx_dma,
    rx_in,
    rx_tx_out,
    tx_en_out);
    input       cts_in;
    output      tx_out;
    output      rts_out;
    output      interrupt;
    input       clock;
    output      rx_dma;
    output      tx_dma;
    input       rx_in;
    output      rx_tx_out;
    output      tx_en_out;


          wire  rx_wire;
          wire  tx_wire;
          wire  rts_wire;
          wire  cts_wire;
          wire  intr_wire;
          wire  clock_wire;
          wire  Net_161;
          wire  Net_157;
          wire  Net_156;
          wire [3:0] Net_155;
          wire  Net_154;
          wire  Net_150;
          wire  Net_149;
          wire  Net_148;
          wire  Net_147;
          wire  Net_146;
          wire  Net_145;
          wire  Net_1172;
          wire  Net_23;
          wire  tx_en_wire;
          wire  Net_47;
          wire  Net_22;
          wire  Net_24;
          wire  Net_847;


	cy_clock_v1_0
		#(.id("978aeb8a-3c3e-4274-b088-075e7e532a00/b68e5b9d-7828-482d-a282-930f990e3b3e"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("8680555555.55556"),
		  .is_direct(0),
		  .is_digital(0))
		SCBCLK
		 (.clock_out(Net_847));


	// clock_VM (cy_virtualmux_v1_0)
	assign clock_wire = Net_847;

    ZeroTerminal ZeroTerminal_7 (
        .z(Net_22));


    assign Net_23 = Net_22 | Net_847;

	// rx_VM (cy_virtualmux_v1_0)
	assign rx_wire = rx_in;

	// cts_VM (cy_virtualmux_v1_0)
	assign cts_wire = cts_in;


	cy_mxs40_isr_v1_0
		#(.deepsleep_required(0),
		  .int_type(2'b10))
		SCB_IRQ
		 (.int_signal(intr_wire));


    cy_mxs40_scb_v1_10 SCB (
        .clock(clock_wire),
        .uart_rx(rx_wire),
        .uart_cts(cts_wire),
        .i2c_scl(Net_145),
        .i2c_sda(Net_146),
        .spi_clk_s(1'b0),
        .spi_select_s(1'b0),
        .spi_miso_m(1'b0),
        .spi_mosi_s(1'b0),
        .uart_tx(tx_wire),
        .uart_rts(rts_wire),
        .uart_tx_en(tx_en_wire),
        .spi_clk_m(Net_154),
        .spi_select_m(Net_155[3:0]),
        .spi_mosi_m(Net_156),
        .spi_miso_s(Net_157),
        .interrupt(intr_wire),
        .tr_tx_req(tx_dma),
        .tr_rx_req(rx_dma),
        .tr_i2c_scl_filtered(Net_161));
    defparam SCB.master = 0;
    defparam SCB.mode = 2;
    defparam SCB.requires_io_preconfigure = 0;


    assign tx_out = tx_wire;

    assign rts_out = rts_wire;

    assign interrupt = intr_wire;

    assign rx_tx_out = tx_wire;

    assign tx_en_out = tx_en_wire;


endmodule

// top
module top ;

          wire  Net_68;
          wire  Net_67;
          wire  Net_66;
          wire  Net_65;
          wire  Net_64;
          wire  Net_63;
          wire  Net_62;
          wire  Net_61;
          wire  Net_59;
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
          wire  Net_71;
          wire  Net_70;
          wire  Net_69;
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
        .scl_b(Net_70),
        .sda_b(Net_71),
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


    SCB_UART_PDL_v2_0_2 UART_KITPROG_USB (
        .cts_in(1'b0),
        .tx_out(Net_69),
        .rts_out(Net_61),
        .interrupt(Net_62),
        .clock(1'b0),
        .rx_dma(Net_64),
        .tx_dma(Net_65),
        .rx_in(1'b0),
        .rx_tx_out(Net_67),
        .tx_en_out(Net_68));

	wire [0:0] tmpFB_0__PORT9_PIN1_net;
	wire [0:0] tmpIO_0__PORT9_PIN1_net;
	electrical [0:0] tmpSIOVREF__PORT9_PIN1_net;

	cy_mxs40_gpio_v1_0
		#(.id("570396df-2eb9-4462-a5fc-f70f005f8fa3"),
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
		PORT9_PIN1
		 (.oe({1'b1}),
		  .y({Net_69}),
		  .fb({tmpFB_0__PORT9_PIN1_net[0:0]}),
		  .io({tmpIO_0__PORT9_PIN1_net[0:0]}),
		  .siovref(tmpSIOVREF__PORT9_PIN1_net));


	wire [0:0] tmpFB_0__PORT6_PIN4_net;
	electrical [0:0] tmpSIOVREF__PORT6_PIN4_net;

	cy_mxs40_gpio_v1_0
		#(.id("3bebfee8-790b-4297-b73a-27818bdce71c"),
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
		PORT6_PIN4
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__PORT6_PIN4_net[0:0]}),
		  .io({Net_70}),
		  .siovref(tmpSIOVREF__PORT6_PIN4_net));


	wire [0:0] tmpFB_0__PORT6_PIN5_net;
	electrical [0:0] tmpSIOVREF__PORT6_PIN5_net;

	cy_mxs40_gpio_v1_0
		#(.id("24f8209b-918b-4f9d-b13a-e2304ddcf549"),
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
		PORT6_PIN5
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__PORT6_PIN5_net[0:0]}),
		  .io({Net_71}),
		  .siovref(tmpSIOVREF__PORT6_PIN5_net));




endmodule

