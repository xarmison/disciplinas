library IEEE;
use IEEE.std_logic_1164.all;

entity up_down_counter is
    port (
        s, en, rst, clk : in std_logic
    );
end up_down_counter;

architecture ckt of up_down_counter is

    component counter is
        port (
            s, en, rst, clk : in std_logic;
            saida_c : out std_logic_vector(2 downto 0)          
        );
    end component;

    component display_7seg is
        port (
            bcd : in  std_logic_vector(2 downto 0);
            seg : out std_logic_vector(6 downto 0)
        );
    end component;

    signal counter_out : std_logic_vector(2 downto 0);
    signal segments    : std_logic_vector(6 downto 0);

begin

    COUNT : counter port map(s, en, rst, clk, counter_out);
    DISP  : display_7seg port map(counter_out, segments);

end ckt;



