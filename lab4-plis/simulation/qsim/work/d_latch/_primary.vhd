library verilog;
use verilog.vl_types.all;
entity d_latch is
    port(
        d               : in     vl_logic;
        en              : in     vl_logic;
        q               : out    vl_logic
    );
end d_latch;
