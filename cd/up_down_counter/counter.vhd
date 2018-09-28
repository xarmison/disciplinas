library IEEE;
use IEEE.std_logic_1164.all;

entity counter is
    port (
        s, en, rst, clk : in std_logic;
        saida_c : out std_logic_vector(2 downto 0)          
    );
end counter;

architecture ckt of counter is

    component mux2x1_3b is 
        port (
            mais_um  : in std_logic_vector(2 downto 0);
            menos_um : in std_logic_vector(2 downto 0);
            s		 	: in std_logic;
            saida    : out std_logic_vector(2 downto 0)
        );
    end component;

    component somador_3b is
        port (
            a, b : in std_logic_vector(2 downto 0);
            sum  : out std_logic_vector(2 downto 0)
        );
    end component;

    component reg3 is
        port (
            inputs   : in std_logic_vector(2 downto 0);
            rst, clk : in std_logic;
            outputs  : out std_logic_vector(2 downto 0)
        );
    end component;
    
        
    signal mux_out, sumIn, sumOut : std_logic_vector(2 downto 0);
    signal num : std_logic_vector(6 downto 0);
	signal regClk : std_logic;

begin
	 
	 regClk <= en and clk;
	 
    REG : reg3 port map(sumOut, rst, regClk, sumIn);
    SEL : mux2x1_3b port map("001", "111", s, mux_out);
    SUM : somador_3b port map(mux_out, sumIn, sumOut);
	 
	 saida_c <= sumIn;

end ckt;