library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_unsigned.all;

entity speed_radar is 
	port(
		clk_fpga : in std_logic;
		a, b : in std_logic;
		leds : out std_logic_vector(1 downto 0)
	);
end speed_radar;


architecture ckt of speed_radar is 

	component clock_converter is
		port(
			clk_in	: in std_logic;
			clk_out	: out std_logic
		);
	end component;
	
	component ffjk is 
		port( 
			J,K: in  std_logic;
			Reset: in std_logic;
			Clock_enable: in std_logic;
			Clock: in std_logic;
			Output: out std_logic
		);
	end component;
	
	signal count : std_logic_vector(5 downto 0);
	
	signal clk_1 : std_logic;
	signal activation : std_logic;
begin 
	
	CLOK1HZ : clock_converter port map(clk_fpga, clk_1);
	
	KEEPCOUNTER : ffjk port map('1', '1', '0', '1', (a or b), activation);
	
	process(clk_1)
	begin 
		if clk_1 = '1' and clk_1'event then
			if activation = '1' then
				count <= count + 1;
			else 
				if count > "100100" then
					leds <= "10";
				else 
					leds <= "01";
				end if;
				count <= "000000";
			end if;
		end if;
	end process;

end ckt;