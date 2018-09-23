library IEEE;
use IEEE.std_logic_1164.all;

entity somador_3b is
    port (
        a, b : in std_logic_vector(2 downto 0);
        cin  : in '0';
        sum  : out std_logic_vector(2 downto 0)
    );
end somador_3b;

architecture ckt of somador_3b is 

    component somador is
        port (
            a, b, cin : in  std_logic;
            sum, cout : out std_logic
        );
    end component;

    signal caux : std_logic;

begin

    SUM0 : somador port map(a(0), b(0), cin,  sum(0), caux);
    SUM1 : somador port map(a(1), b(1), caux, sum(1), caux);
    SUM2 : somador port map(a(2), b(2), caux, sum(2), caux);

end ckt;