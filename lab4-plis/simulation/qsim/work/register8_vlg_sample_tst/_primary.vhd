library verilog;
use verilog.vl_types.all;
entity register8_vlg_sample_tst is
    port(
        clk             : in     vl_logic;
        d               : in     vl_logic_vector(7 downto 0);
        en              : in     vl_logic;
        rst             : in     vl_logic;
        sampler_tx      : out    vl_logic
    );
end register8_vlg_sample_tst;
