library verilog;
use verilog.vl_types.all;
entity synchronizer_vlg_sample_tst is
    port(
        clk             : in     vl_logic;
        \in\            : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end synchronizer_vlg_sample_tst;
