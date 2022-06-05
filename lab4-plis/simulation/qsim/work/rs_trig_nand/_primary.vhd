library verilog;
use verilog.vl_types.all;
entity rs_trig_nand is
    port(
        nR              : in     vl_logic;
        nS              : in     vl_logic;
        Q               : out    vl_logic;
        nQ              : out    vl_logic
    );
end rs_trig_nand;
