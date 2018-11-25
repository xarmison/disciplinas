library IEEE;
use IEEE.std_logic_1164.all;

entity clock_converter is 
	port(
			clk_in	: in std_logic;
			clk_out	: out std_logic
	);
end clock_converter;

architecture ckt of clock_converter is

	signal cont : integer range 1 to 50;

begin 
	process(clk_in)
	begin
		if(clk_in = '1' and clk_in'event) then 
			if(cont = 50) then
				clk_out <= '1';
				cont <= 1;
			else 
				clk_out <= '0';
				cont <= cont + 1;
			end if; 
		end if;
	end process;
end ckt;