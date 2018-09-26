library IEEE;
use IEEE.std_logic_1164.all;

entity somador_3b is
    port (
        a, b : in std_logic_vector(2 downto 0);
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

    signal caux : std_logic_vector(2 downto 0);

begin

    SUM0 : somador port map(a(0), b(0), '0',     sum(0), caux(0));
    SUM1 : somador port map(a(1), b(1), caux(0), sum(1), caux(1));
    SUM2 : somador port map(a(2), b(2), caux(1), sum(2), caux(2));

end ckt;