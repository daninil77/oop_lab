library verilog;
use verilog.vl_types.all;
entity dff_rse_vlg_sample_tst is
    port(
        clk             : in     vl_logic;
        d               : in     vl_logic;
        en              : in     vl_logic;
        rst             : in     vl_logic;
        set             : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end dff_rse_vlg_sample_tst;
