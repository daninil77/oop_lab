library verilog;
use verilog.vl_types.all;
entity counter8_vlg_check_tst is
    port(
        counter         : in     vl_logic_vector(7 downto 0);
        sampler_rx      : in     vl_logic
    );
end counter8_vlg_check_tst;
