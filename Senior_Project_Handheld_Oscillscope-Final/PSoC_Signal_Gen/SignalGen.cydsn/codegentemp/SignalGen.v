// ======================================================================
// SignalGen.v generated from TopDesign.cysch
// 03/18/2021 at 11:18
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
// Component: cy_analog_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_analog_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_analog_virtualmux_v1_0\cy_analog_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_analog_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_analog_virtualmux_v1_0\cy_analog_virtualmux_v1_0.v"
`endif

// Component: cy_constant_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_constant_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_constant_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.3\PSoC Creator\psoc\content\CyPrimitives\cyprimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
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

// bIncludeDriverToComponent_v1_0(PDL_DRIVER_NAME=ctb, PDL_DRIVER_REQ_VERSION=1.10, PDL_DRIVER_SUBGROUP=, PDL_DRIVER_VARIANT=, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=bIncludeDriverToComponent_v1_0, CY_CONFIG_TITLE=IncludeDriver_1, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=VDAC_1:IncludeDriver_1, CY_INSTANCE_SHORT_NAME=IncludeDriver_1, CY_MAJOR_VERSION=1, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=ctb, CY_PDL_DRIVER_REQ_VERSION=1.10, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.3, INSTANCE_NAME=VDAC_1_IncludeDriver_1, )
module bIncludeDriverToComponent_v1_0_0 ;





endmodule

// VDAC12_PDL_v2_0(DacCodeMode=1, DebugEnable=false, DeepSleep=false, DwrExtAfterCustomized=false, DwrRefExternal=0, GainBandwidth=2, InitialCode=0, InitialVoltage_mV=1650, OpampIDD=2, OpAmpUsage=1, OutputBuffer=2, OutputBufferPower=2, OutputBufferRange=0, RefBufferRange=0, ReferenceCurrentHigh=true, SampleAndHold=false, ShowClk=true, ShowStrobe=false, ShowTrig=false, UpdateMode=1, VrefSource=1, VrefVoltage=1.2, VrefVoltage_mV=3300, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMMENT=, CY_COMPONENT_NAME=VDAC12_PDL_v2_0, CY_CONFIG_TITLE=VDAC_1, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=VDAC_1, CY_INSTANCE_SHORT_NAME=VDAC_1, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=ctdac, CY_PDL_DRIVER_REQ_VERSION=2.0, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.3, INSTANCE_NAME=VDAC_1, )
module VDAC12_PDL_v2_0_1 (
    vref,
    strobe,
    clock,
    vout,
    trigger,
    vref_out);
    inout       vref;
    electrical  vref;
    input       strobe;
    input       clock;
    inout       vout;
    electrical  vout;
    output      trigger;
    inout       vref_out;
    electrical  vref_out;


    electrical  ct_vout_sw;
    electrical  ct_vout_buf;
    electrical  ct_vout;
    electrical  ref_drive;
          wire  Net_58;
          wire  Net_48;
          wire  Net_44;
    electrical  Net_43;
    electrical  Net_42;
          wire  Net_36;
          wire  Net_34;
    electrical  Net_3;
    electrical  Net_14;
    electrical  Net_16;
          wire  Net_1;
    electrical  Net_9;
    electrical  Net_10;

    cy_mxs40_ctdac_v1_0 CTDAC (
        .clock(Net_1),
        .ctdrefdrive(ref_drive),
        .ctdrefsense(Net_3),
        .ctdvout(ct_vout),
        .ctdvoutsw(ct_vout_sw),
        .dsi_ctdac_strobe(strobe),
        .tr_ctdac_empty(trigger));

	// cy_analog_virtualmux_1 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_1_connect(vout, ct_vout_buf);
	defparam cy_analog_virtualmux_1_connect.sig_width = 1;

    cy_mxs40_opamp_v1_0 VOUTBUF (
        .out_1x(Net_16),
        .out_10x(Net_14),
        .vplus(ct_vout),
        .vminus(ct_vout_buf),
        .ctb_dsi_comp(Net_36));
    defparam VOUTBUF.deepsleep_available = 0;
    defparam VOUTBUF.has_resistor = 0;
    defparam VOUTBUF.needs_dsab = 0;

	// cy_analog_virtualmux_3 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_3_connect(ct_vout_buf, Net_14);
	defparam cy_analog_virtualmux_3_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_2 (
        .noconnect(Net_9));

	// cy_analog_virtualmux_2 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_2_connect(Net_10, Net_42);
	defparam cy_analog_virtualmux_2_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_3 (
        .noconnect(Net_42));

    cy_analog_noconnect_v1_0 cy_analog_noconnect_4 (
        .noconnect(Net_3));

    assign Net_44 = 1'h0;

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_1 = clock;

    bIncludeDriverToComponent_v1_0_0 IncludeDriver_1 ();


    cy_connect_v1_0 vref_out__cy_connect_v1_0(vref_out, ref_drive);
    defparam vref_out__cy_connect_v1_0.sig_width = 1;


endmodule

// top
module top ;

          wire  Net_21;
          wire  Net_20;
          wire  Net_26;
    electrical  Net_6;
          wire  Net_5;
          wire  Net_2;
    electrical  Net_1;
    electrical  Net_4;
          wire  Net_3;

    VDAC12_PDL_v2_0_1 VDAC_1 (
        .vref(Net_1),
        .strobe(1'b0),
        .clock(Net_3),
        .vout(Net_4),
        .trigger(Net_5),
        .vref_out(Net_6));


	cy_clock_v1_0
		#(.id("caac4486-9ccb-426a-b02d-9baaaef07f3c"),
		  .source_clock_id("2FB4EC85-8328-4C5A-9ED9-8B63060178EB"),
		  .divisor(0),
		  .period("2000000000"),
		  .is_direct(0),
		  .is_digital(0))
		Clock_1
		 (.clock_out(Net_3));


	wire [0:0] tmpFB_0__Pin_1_net;
	wire [0:0] tmpIO_0__Pin_1_net;
	electrical [0:0] tmpSIOVREF__Pin_1_net;

	cy_mxs40_gpio_v1_0
		#(.id("a61270bc-07ec-447d-ac9e-34cfe85c30e9"),
		  .width(1),
		  .sio_grp_cnt(0),
		  .drive_mode("0"),
		  .ibuf_enabled("0"),
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
		  .pin_mode("A"),
		  .slew_rate("0"),
		  .vtrip("0"),
		  .use_annotation("0"),
		  .hotswap_needed("0"))
		Pin_1
		 (.oe({1'b1}),
		  .y({1'b0}),
		  .fb({tmpFB_0__Pin_1_net[0:0]}),
		  .analog({Net_4}),
		  .io({tmpIO_0__Pin_1_net[0:0]}),
		  .siovref(tmpSIOVREF__Pin_1_net));



	cy_clock_v1_0
		#(.id("33f742fc-c84b-4dcd-a657-533be44d8613"),
		  .source_clock_id("4952BDB5-B02C-44C1-9796-82E591C05DF5"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(0))
		Clock_2
		 (.clock_out(Net_20));


	wire [0:0] tmpFB_0__Pin_2_net;
	wire [0:0] tmpIO_0__Pin_2_net;
	electrical [0:0] tmpSIOVREF__Pin_2_net;

	cy_mxs40_gpio_v1_0
		#(.id("a7030fb2-ca66-4555-92da-d2411c9e4c00"),
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
		Pin_2
		 (.oe({1'b1}),
		  .y({Net_20}),
		  .fb({tmpFB_0__Pin_2_net[0:0]}),
		  .io({tmpIO_0__Pin_2_net[0:0]}),
		  .siovref(tmpSIOVREF__Pin_2_net));




endmodule

