library IEEE;
use IEEE.std_logic_1164.all;

entity traffic is 
	port(
		clk_fpga, clr, a, b : in std_logic;
		sel : in std_logic_vector(1 downto 0);
		leds : out std_logic_vector(1 downto 0);
		lights : out std_logic_vector(5 downto 0) 
	);
end traffic;

architecture ckt of traffic is 
	
	component traffic_lights is
	  port(
		 clk_fpga, clr	: in std_logic;
		 sel				: in std_logic_vector(1 downto 0);
		 lights			: out std_logic_vector(5 downto 0) 
	  );
	end component;
	
	component speed_radar is 
		port(
			clk_fpga : in std_logic;
			a, b : in std_logic;
			leds : out std_logic_vector(1 downto 0)
		);
	end component;
	
	signal temp_leds : std_logic_vector(1 downto 0);
	signal temp_lights : std_logic_vector(5 downto 0);
	
begin 

	SEMAFORO : traffic_lights port map(clk_fpga, clr, sel, temp_lights);
	RADAR	 	: speed_radar port map(clk_fpga, a, b, temp_leds);
	
	lights <= temp_lights;
	leds <= temp_leds;

end ckt;