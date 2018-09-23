library IEEE;
use IEEE.std_logic_1164.all;

entity counter is
    port (
        s, en, rst, clk : in std_logic;
        saida : out std_logic_vector(2 downto 0)          
    );
end counter;

architecture ckt of counter is

    component mux is 
        port (
            mais_um  : in std_logic_vector(2 downto 0);
            menos_um : in std_logic_vector(2 downto 0);
            s		 : in std_logic;
            saida    : out std_logic_vector(2 downto 0)
        );
    end component;

    component somador_3b is
        port (
            a, b : in std_logic_vector(2 downto 0);
            cin  : in '0';
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
        
    signal mux_out, sumIn : std_logic_vector(2 downto 0);
    signal regIn <= "000";

begin
    
    REG : reg3 port map(regIn, rst, clk, sumIn);
    S   : mux port map("001", "111", s, mux_out);
    SUM : somador_3b port map(mux_out, sumIn, saida);
    
    regIn <=saida;

end ckt;