library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_unsigned.all;


entity traffic_lights is
  port(
    clk_fpga, clr	: in std_logic;
	 sel				: in std_logic_vector(1 downto 0);
	 clk				: out std_logic;
    lights			: out std_logic_vector(5 downto 0) 
  );
end traffic_lights;


architecture ckt of traffic_lights is
	
	component clock_converter is
		port(
			clk_in	: in std_logic;
			clk_out	: out std_logic
		);
	end component;

	component trafficA is 
		port (
			clk, clr : in std_logic;
			lights   : out std_logic_vector(5 downto 0) 
	  );
	end component;
	
	component trafficB is 
	  port (
			clk, clr : in std_logic;
			lights   : out std_logic_vector(5 downto 0) 
	  );
	end component;
	
	component trafficC is 
		port (
			clk, clr : in std_logic;
			lights   : out std_logic_vector(5 downto 0) 
	  );
	end component;
	
	signal clk_1 : std_logic;
	signal leds1, leds2, leds3 : std_logic_vector(5 downto 0);
	signal clk_temporizacao : std_logic_vector(2 downto 0);

begin
	
	CLOK1HZ : clock_converter port map(clk_fpga, clk_1);
	clk <= clk_1;
	
	process(sel) begin
		if(sel = "00") then
			clk_temporizacao(0) <= clk_1;
			clk_temporizacao(1) <= '0';
			clk_temporizacao(2) <= '0';
			lights <= leds1;
		elsif(sel = "01") then
			clk_temporizacao(0) <= '0';
			clk_temporizacao(1) <= clk_1;
			clk_temporizacao(2) <= '0';
			lights <= leds2;
		elsif(sel = "10") then
			clk_temporizacao(0) <= '0';
			clk_temporizacao(1) <= '0';
			clk_temporizacao(2) <= clk_1;
			lights <= leds3;
		end if;
	end process;
	
	TEMP_A : trafficA port map(clk_temporizacao(0), clr, leds1);
	TEMP_B : trafficB port map(clk_temporizacao(1), clr, leds2);
	TEMP_C : trafficC port map(clk_temporizacao(2), clr, leds3);
 
end ckt;