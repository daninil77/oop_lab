library verilog;
use verilog.vl_types.all;
entity rs_trig_nand_vlg_check_tst is
    port(
        Q               : in     vl_logic;
        nQ              : in     vl_logic;
        sampler_rx      : in     vl_logic
    );
end rs_trig_nand_vlg_check_tst;
