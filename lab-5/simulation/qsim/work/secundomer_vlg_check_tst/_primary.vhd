library verilog;
use verilog.vl_types.all;
entity secundomer_vlg_check_tst is
    port(
        HEX0            : in     vl_logic_vector(6 downto 0);
        HEX1            : in     vl_logic_vector(6 downto 0);
        HEX2            : in     vl_logic_vector(6 downto 0);
        HEX3            : in     vl_logic_vector(6 downto 0);
        pulse_counter   : in     vl_logic_vector(18 downto 0);
        pulse_counter_10s: in     vl_logic_vector(3 downto 0);
        pulse_counter_100s: in     vl_logic_vector(3 downto 0);
        pulse_counter_ms: in     vl_logic_vector(3 downto 0);
        pulse_counter_s : in     vl_logic_vector(3 downto 0);
        sampler_rx      : in     vl_logic
    );
end secundomer_vlg_check_tst;
