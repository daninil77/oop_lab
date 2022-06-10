library verilog;
use verilog.vl_types.all;
entity secundomer is
    port(
        KEY             : in     vl_logic_vector(1 downto 0);
        CLOCK_50        : in     vl_logic;
        pulse_counter   : out    vl_logic_vector(18 downto 0);
        pulse_counter_ms: out    vl_logic_vector(3 downto 0);
        pulse_counter_s : out    vl_logic_vector(3 downto 0);
        pulse_counter_10s: out    vl_logic_vector(3 downto 0);
        pulse_counter_100s: out    vl_logic_vector(3 downto 0);
        HEX0            : out    vl_logic_vector(6 downto 0);
        HEX1            : out    vl_logic_vector(6 downto 0);
        HEX2            : out    vl_logic_vector(6 downto 0);
        HEX3            : out    vl_logic_vector(6 downto 0)
    );
end secundomer;
