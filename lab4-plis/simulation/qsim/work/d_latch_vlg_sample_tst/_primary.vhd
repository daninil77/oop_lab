library verilog;
use verilog.vl_types.all;
entity d_latch_vlg_sample_tst is
    port(
        d               : in     vl_logic;
        en              : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end d_latch_vlg_sample_tst;
