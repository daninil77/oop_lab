library verilog;
use verilog.vl_types.all;
entity rs_trig_nand_vlg_sample_tst is
    port(
        nR              : in     vl_logic;
        nS              : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end rs_trig_nand_vlg_sample_tst;
