library IEEE;
use IEEE.std_logic_1164.all;

entity display_7seg is
    port (
        bcd : in  std_logic_vector(2 downto 0);
        seg : out std_logic_vector(6 downto 0)
    );
end display_7seg;

architecture ckt of display_7seg is
begin
    
    with bcd select 
    seg <=  "0000001" WHEN "000",
            "1001111" WHEN "001",
            "0010010" WHEN "010",
            "0000110" WHEN "011",
            "1001100" WHEN "100",
            "0100100" WHEN "101",
            "0100000" WHEN "110",
            "0001111" WHEN "111";

end ckt;