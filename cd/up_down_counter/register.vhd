library IEEE;
use IEEE.std_logic_1164.all;

entity reg3 is
    port (
        inputs   : in std_logic_vector(2 downto 0);
        rst, clk : in std_logic;
        outputs  : out std_logic_vector(2 downto 0)
    );
end reg3;

architecture ckt of reg3 is

    component ffd is
        port (
          D, C, P, clk : in std_logic;
          Q : out std_logic
        );
    end component;    

begin

    Q0 : ffd port map(inputs(0), not(rst), '0', clk, outputs(0));
    Q1 : ffd port map(inputs(1), not(rst), '0', clk, outputs(1));
    Q2 : ffd port map(inputs(2), not(rst), '0', clk, outputs(2));

end ckt;

