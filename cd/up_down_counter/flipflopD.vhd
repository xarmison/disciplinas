library IEEE;
use IEEE.std_logic_1164.all;

entity ffd is
  port (
    D, C, P, clk : in std_logic;
    Q : out std_logic
  );
end ffd;

architecture ckt of ffd is

  signal estado : std_logic;

begin

  process(D, clk, C)
  begin
	 if(C = '1') then estado <= '0';
	 elsif(clk = '1' and clk'event) then
		if(D = '0') then estado <= '0';
		else estado <= '1';
		end if;
	 end if;
  end process;
  
  Q <= estado;

end ckt;