library verilog;
use verilog.vl_types.all;
entity register8 is
    port(
        d               : in     vl_logic_vector(7 downto 0);
        clk             : in     vl_logic;
        rst             : in     vl_logic;
        en              : in     vl_logic;
        q               : out    vl_logic_vector(7 downto 0)
    );
end register8;
